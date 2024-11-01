// Defines for teh sdfat implementation
#ifndef __SDCARD_H
#define __SDCARD_H

#include <SdFat.h>

extern SdFs sd;
extern FsFile file;

void sdcard_setup(void);
void sdcard_test();
void dir(const char * dirname, uint8_t levels, Stream & stream);
esp_err_t formatSD();
void errorPrint(const char * msg = "");
bool hasSdCard();
const char * getCardType();
uint32_t getCapacity();

#endif // __SDCARD_H