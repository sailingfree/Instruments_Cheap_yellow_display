// Logging functions for the gateway

#include <Arduino.h>
#include <sdcard.h>

void setup_logging(void);
void append_log(const char * msg);
void read_log(Stream & s);
String & getLogname();