/*
  configure the library and U-Blox for serial port use as well as
  switching the module from the default 9600 baud to 38400.

  sets the navigation type to sea and sets the lock speed

  This uses the sparkfun arduino library local copy.

  I don't use this library for the nav info though as I dont get reliable results.

  After the setup function has been called the calling program can restart the
  software serial object without write (TX pin).
*/



#include <Arduino.h>
#include <SparkFun_Ublox_Arduino_Library_Series_6_7.h>
#include <SoftwareSerial.h>
#include <cyd_pins.h>
#include <ublox_6m_config.h>

static const int RXPin = SERIAL_RX,
                TXPin = CYD_SCL_PIN;   // Shared with the i2c so only use one at a time

void config_ublox(uint16_t GPSBaud)
{
  // The aprkfun ublox object
  SFE_UBLOX_GPS myGPS;

  // The serial connection to the GPS device
  SoftwareSerial mySerial(RXPin, TXPin);

   //Assume that the U-Blox GNSS is running at 9600 baud (the default)
  //Loop until we're in sync and then ensure it's at the requested speed baud.
  do {
    Serial.printf("GNSS: trying %d baud\n", GPSBaud);
    mySerial.begin(GPSBaud);
    if (myGPS.begin(mySerial) == true) break;

    delay(100);
    Serial.println("GNSS: trying 9600 baud");
    mySerial.begin(9600);
    if (myGPS.begin(mySerial) == true) {
        Serial.println("GNSS: connected at 9600 baud, switching to 38400");
        myGPS.setSerialRate(GPSBaud);
        delay(100);
    } else {
        //myGPS.factoryReset();
        delay(2000); //Wait a bit before trying again to limit the Serial output
    }
  } while(1);
  Serial.printf("GNSS serial connected at %d baud\n", GPSBaud);
 
  myGPS.setUART1Output(COM_TYPE_NMEA); //Set the UART port to output NMEA only

  // set the dynamic mode to SEA and also sets the static lock threshold in cm/s
  myGPS.setDynamicModel(DYN_MODEL_SEA, 1100U, 15);

  mySerial.end();
}