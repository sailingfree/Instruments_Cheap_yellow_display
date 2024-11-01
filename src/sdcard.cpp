#include <Arduino.h>
#include <SdFat.h>
#include <SPI.h>
#include "sdios.h"
#include <time.h>
#include <ESP32time.h>

// ----------------------------
// SD Reader pins
// ----------------------------

#define SCK 18
#define MISO 19
#define SMOSI 23
#define SS 5
#define SDCARD_SS_PIN SS
/*
  Set DISABLE_CS_PIN to disable a second SPI device.
  For example, with the Ethernet shield, set DISABLE_CS_PIN
  to 10 to disable the Ethernet controller.
*/
const int8_t DISABLE_CS_PIN = -1;

/*
  Change the value of SD_CS_PIN if you are using SPI
  and your hardware does not use the default value, SS.
  Common values are:
  Arduino Ethernet shield: pin 4
  Sparkfun SD shield: pin 8
  Adafruit SD shields and modules: pin 10
*/
// SDCARD_SS_PIN is defined for the built-in SD on some boards.
#ifndef SDCARD_SS_PIN
const uint8_t SD_CS_PIN = SS;
#else   // SDCARD_SS_PIN
const uint8_t SD_CS_PIN = SDCARD_SS_PIN;
#endif  // SDCARD_SS_PIN

// Select the best SD card configuration.
#define SD_CONFIG SdSpiConfig(SD_CS_PIN, SHARED_SPI, SD_SCK_MHZ(32))

SdFs sd;
FsFile file;

static bool hasSD = false;

bool hasSdCard() {
  return hasSD;
}

//------------------------------------------------------------------------------

cid_t cid;
csd_t csd;
scr_t scr;
uint8_t cmd6Data[64];
uint32_t eraseSize;
uint32_t ocr;


const char * getCardType() {
  if(!hasSD) {
    return "No SD card found";
  } else {

  switch (sd.card()->type()) {
    case SD_CARD_TYPE_SD1:
      return "SD1";
      break;

    case SD_CARD_TYPE_SD2:
      return "SD2";
      break;

    case SD_CARD_TYPE_SDHC:
      if (csd.capacity() < 70000000) {
        return "SDHC";
      } else {
        return "SDXC";
      }
      break;

    default:
      return "Unknown";
  }
  }
}

// Card capacity in MB
uint32_t getCapacity() {
  uint32_t s = csd.capacity();
  return s * 0.000512;
}

//------------------------------------------------------------------------------
void printCardType() {
  Serial.printf("SD Card type %s\n", getCardType());
}


//------------------------------------------------------------------------------
void printConfig(SdSpiConfig config) {
  if (DISABLE_CS_PIN < 0) {
    Serial.printf(
        "\nAssuming the SD is the only SPI device.\n"
        "Edit DISABLE_CS_PIN to disable an SPI device.\n");
  } else {
    Serial.printf("\nDisabling SPI device on pin %d", DISABLE_CS_PIN);
      pinMode(DISABLE_CS_PIN, OUTPUT);
    digitalWrite(DISABLE_CS_PIN, HIGH);
  }
}
//------------------------------------------------------------------------------
void printConfig(SdioConfig config) {
  (void)config;
  Serial.printf("Assuming an SDIO interface.\n");
}

//------------------------------------------------------------------------------
static ArduinoOutStream cout(Serial);

//------------------------------------------------------------------------------
void errorPrint(const char * msg = "") {
  cout << msg << " ";
  if (sd.sdErrorCode()) {
    cout << "SD errorCode: " << hex << showbase;
    printSdErrorSymbol(&Serial, sd.sdErrorCode());
    cout << " = " << int(sd.sdErrorCode()) << endl;
    cout << "SD errorData = " << int(sd.sdErrorData()) << dec << endl;
  }
}

// Call back for file timestamps.  Only called for file create and sync().
void dateTime(uint16_t* date, uint16_t* t, uint8_t* ms10) {
  ESP32Time rtc;
  
  // Return date using FS_DATE macro to format fields.
  *date = FS_DATE(rtc.getYear(), rtc.getMonth(), rtc.getDay());

  // Return time using FS_TIME macro to format fields in 24 hour format
  *t = FS_TIME(rtc.getHour(true), rtc.getMinute(), rtc.getSecond());

  // Return low time bits in units of 10 ms.
  *ms10 = 0;
  //Serial.printf("0x%x 0x%x 0x%x\n", *date, *t, *ms10);
}

//-----------------------------------------------------------------------------
void sdcard_setup() {
  Serial.printf("SdFat version: %s ", SD_FAT_VERSION_STR);
  printConfig(SD_CONFIG);
  
  // Initialize at the highest speed supported by the board that is
  // not over 50 MHz. Try a lower speed if SPI errors occur.
  if (!sd.begin(SD_CONFIG)) {
  Serial.print(
        "\nSD initialization failed.\n"
        "Do not reformat the card!\n"
        "Is the card correctly inserted?\n"
        "Is there a wiring/soldering problem?\n");
    if (isSpi(SD_CONFIG)) {
      Serial.print(
          "Is SD_CS_PIN set to the correct value?\n"
          "Does another SPI device need to be disabled?\n");
    }
    errorPrint();
    return;
  }
  hasSD = true;

  printConfig(SD_CONFIG);
  printCardType();

   // Set callback
  FsDateTime::setCallback(dateTime);
  sd.ls(LS_R);
}

//------------------------------------------------------------------------------
uint32_t cardSectorCount = 0;
uint8_t sectorBuffer[512];
//------------------------------------------------------------------------------
// SdCardFactory constructs and initializes the appropriate card.
SdCardFactory cardFactory;
// Pointer to generic SD card.
SdCard* m_card = nullptr;


//------------------------------------------------------------------------------
void clearSerialInput() {
  uint32_t m = micros();
  do {
    if (Serial.read() >= 0) {
      m = micros();
    }
  } while (micros() - m < 10000);
}


//------------------------------------------------------------------------------
// flash erase all data
uint32_t const ERASE_SIZE = 262144L;
void eraseCard() {
  cout << endl << "Erasing\n";
  uint32_t firstBlock = 0;
  uint32_t lastBlock;
  uint16_t n = 0;

  do {
    lastBlock = firstBlock + ERASE_SIZE - 1;
    if (lastBlock >= cardSectorCount) {
      lastBlock = cardSectorCount - 1;
    }
    if (!m_card->erase(firstBlock, lastBlock)) {
      errorPrint("erase failed");
    }
    cout << '.';
    if ((n++) % 64 == 63) {
      cout << endl;
    }
    firstBlock += ERASE_SIZE;
  } while (firstBlock < cardSectorCount);
  cout << endl;

  if (!m_card->readSector(0, sectorBuffer)) {
    errorPrint("readBlock");
  }
  cout << hex << showbase << setfill('0') << internal;
  cout << "All data set to " << setw(4) << int(sectorBuffer[0]) << endl;
  cout << dec << noshowbase << setfill(' ') << right;
  cout << "Erase done\n";
}
//------------------------------------------------------------------------------
void formatCard() {
  ExFatFormatter exFatFormatter;
  FatFormatter fatFormatter;

  // Format exFAT if larger than 32GB.
  bool rtn = cardSectorCount > 67108864
                 ? exFatFormatter.format(m_card, sectorBuffer, &Serial)
                 : fatFormatter.format(m_card, sectorBuffer, &Serial);

  if (!rtn) {
    errorPrint();
  }
  cout << "Done." << endl;
}

void dir(const char * dirname, uint8_t levels, Stream & stream) {
  if(!hasSD){
    return;
  }
  sd.ls(&stream, "/", LS_R | LS_A | LS_DATE | LS_SIZE);
  stream.printf("\n");
}

esp_err_t formatSD() {

  if(!hasSD) {
    cout << "No SD card.. exiting..." << endl;
    return -1;
  }
    // Select and initialize proper card driver.
  m_card = cardFactory.newCard(SD_CONFIG);
  if (!m_card || m_card->errorCode()) {
    errorPrint("card init failed.");
    return 0;
  }

  cardSectorCount = m_card->sectorCount();
  if (!cardSectorCount) {
    errorPrint("Get sector count failed.");
    return 0;
  }

  cout << "\nCard size: " << cardSectorCount * 5.12e-7;
  cout << " GB (GB = 1E9 bytes\n";

  cout << "Card will be formated ";
  if (cardSectorCount > 67108864) {
    cout << "exFAT\n";
  } else if (cardSectorCount > 4194304) {
    cout << "FAT32\n";
  } else {
    cout << "FAT16\n";
  }
  eraseCard();
  formatCard();
  return 0;
}