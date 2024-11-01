// Logging for te gateway

#include <Arduino.h>
#include <GwLogger.h>

// Logfile name for the current operations
static String logname;

// How many old versions to keep
static const uint16_t maxlogs = 10;

// The logfile base name
String logbase = "logfile";

// The suffix. .txt works when reading on windows PCs
String logsuffix = ".txt";

// Rotae the logs, losing the oldest and renaming the remaing files
// so the oldest has the highest number
void rotateLogs() {
  String f1, f2;

  // remove the oldest file
  f1 = logbase + maxlogs + logsuffix;
  if(sd.exists(f1)) {
    sd.remove(f1);
  }

// rename the old logs moving them to their next highest number
  for(uint16_t i = maxlogs; i > 1; i--) {
    f1 = logbase + i + logsuffix;
    f2 = logbase + (i-1) + logsuffix;
    if(sd.exists(f2)) {
      sd.rename(f2, f1);
      Serial.printf("Renaming %s to %s\n", f2.c_str() , f1.c_str());
    }
  }
  // rename the old log with 1st sequence
  sd.rename(logbase + logsuffix, logbase + 1 + logsuffix);
}

void setup_logging(void) {
    rotateLogs();
    logname = logbase + logsuffix;

    if(!hasSdCard()) {
      return;
    }

// create a file and write one line to the file
  if (!file.open(logname.c_str(), O_WRONLY | O_CREAT | O_TRUNC)) {
    errorPrint("Creating logfile");
    return;
  }
  file.println(logname);
  file.close();
}

void append_log(const char * msg) {
     if(!hasSdCard()) {
      return;
    }

    if (!file.open(logname.c_str(), O_WRONLY | O_CREAT | O_APPEND)) {
        errorPrint("Updating logfile");
        return;
    }

  file.println(msg);
  file.close();
  file.sync();
}

void read_log(String &log, Stream & s) {
    if(!hasSdCard()) {
      return;
    }
    
    if (!file.open(log.c_str(), O_RDWR)) {
        errorPrint("Updating logfile");
        return;
    }

    String str;
    do {
        str = file.readString();
        s.print(str);
    } while(str.length());
    file.close();
}

String & getLogname() {
  return logname;
}