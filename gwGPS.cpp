// GPS code using a ublox module

#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>
#include <GwPrefs.h>
#include <StringStream.h>

SET_LOOP_TASK_STACK_SIZE(16 * 1024);

// Some ublox UBX code from here https://forum.arduino.cc/t/ubx-protocol-help-configuring-a-neo-6m-arduino-gps-module-fletcher-checksum/226600/10
/*
   This sample code demonstrates the normal use of a TinyGPSPlus (TinyGPSPlus) object.
   It requires the use of SoftwareSerial, and assumes that you have a
   9600-baud serial GPS device connected to the GPIOS defined below.
*/
static const int RXPin = SERIAL_RX,
                TXPin = CYD_SCL_PIN;   // Shared with the i2c so only use one at a time

static const uint32_t GPSBaud = 38400;

// The TinyGPSPlus object used for local GNSS data
TinyGPSPlus gps;

// Custom messages PUBX
TinyGPSCustom pubxTime(gps, "PUBX", 2);

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);

// The string stream object for building text
StringStream output;

// This custom version of delay() ensures that the gps object
// is being "fed".
static void smartDelay(unsigned long ms) {
    unsigned long start = millis();
    do {
        while (ss.available())
            gps.encode(ss.read());
    } while (millis() - start < ms);
}

static void printFloat(float val, bool valid, int len, int prec, bool addToOutput = false, bool doprint = true) {
    StringStream local;

    if (!valid) {
        while (len-- > 1)
            local.print('*');
        local.print(' ');
    }
    else {
        local.print(val, prec);
        int vi = abs((int)val);
        int flen = prec + (val < 0.0 ? 2 : 1);  // . and -
        flen += vi >= 1000 ? 4 : vi >= 100 ? 3
            : vi >= 10 ? 2
            : 1;
        for (int i = flen; i < len; ++i)
            local.print(' ');
    }
    if (doprint) {
        Serial.print(local.data);
    }
    if (addToOutput) {
        output.data += local.data;
    }

    smartDelay(0);
}

static void printInt(unsigned long val, bool valid, int len, bool addToOutput = false, bool doprint = true) {
    StringStream local;

    char sz[32] = "*****************";
    if (valid)
        sprintf(sz, "%ld", val);
    sz[len] = 0;
    for (int i = strlen(sz); i < len; ++i)
        sz[i] = ' ';
    if (len > 0)
        sz[len - 1] = ' ';
    local.print(sz);
    if (doprint) {
        Serial.print(local.data);
    }
    if (addToOutput) {
        output.data += local.data;
    }
    smartDelay(0);
}

static void printDateTime(TinyGPSDate& d, TinyGPSTime& t, bool addToOutput = false, bool doprint = true) {
    StringStream local;

    if (!d.isValid()) {
        local.print(F("********** "));
    }
    else {
        char sz[32];
        sprintf(sz, "%02d/%02d/%02d ", d.month(), d.day(), d.year());
        local.print(sz);
    }

    if (!t.isValid()) {
        local.print(F("******** "));
    }
    else {
        char sz[32];
        sprintf(sz, "%02d:%02d:%02d ", t.hour(), t.minute(), t.second());
        local.print(sz);
    }

    if (doprint) {
        Serial.print(local.data);
    }
    if (addToOutput) {
        output.data += local.data;
    }
    printInt(d.age(), d.isValid(), 5, false, doprint);
    smartDelay(0);
}

static void printStr(const char* str, int len, bool addToOutput = false, bool doprint = true) {
    StringStream local;

    int slen = strlen(str);
    for (int i = 0; i < len; ++i)
        local.print(i < slen ? str[i] : ' ');

    if (doprint) {
        Serial.print(local.data);
    }
    if (addToOutput) {
        output.data += local.data;
    }
    smartDelay(0);
}


void initGPS() {

    Serial.println(F("FullExample.ino"));
    Serial.println(F("An extensive example of many interesting TinyGPSPlus features"));
    Serial.print(F("Testing TinyGPSPlus library v. "));
    Serial.println(TinyGPSPlus::libraryVersion());
    Serial.println(F("by Mikal Hart"));
    Serial.println();
    Serial.println(F("Sats HDOP  Latitude   Longitude   Fix  Date       Time     Date Alt    Course Speed Card  Distance Course Card  Chars Sentences Checksum"));
    Serial.println(F("           (deg)      (deg)       Age                      Age  (m)    --- from GPS ----  ---- to London  ----  RX    RX        Fail"));
    Serial.println(F("----------------------------------------------------------------------------------------------------------------------------------------"));

    config_ublox(GPSBaud);
    
    ss.begin(GPSBaud);
}

void handleGPS() {
    bool print_gps = false;

    static const double LONDON_LAT = 51.508131, LONDON_LON = -0.128002;

    static double   lastLat = 0.0, lastLong = 0.0;
    static uint32_t lastTime = 0;
    static long     distance = 0;

    String Lat, Long, Time, Speed, Course, Dist, MaxSp, AvgSp, Hdop, Sats;
    double gpsLng;
    double gpsLat;

    // Serial.println(F("Sats HDOP  Latitude   Longitude   Fix  Date       Time     Date Alt    Course Speed Card  Distance Course Card  Chars Sentences Checksum"));
    gpsLng = gps.location.lng();
    gpsLat = gps.location.lat();

    if(lastLat == 0.0) {
        lastLat = gpsLat;
    }
    if(lastLong == 0.0) {
        lastLong = gpsLng;
    }

    printInt(gps.satellites.value(), gps.satellites.isValid(), 5, true, print_gps);
    Sats = output.data;
    output.clear();

    printFloat(gps.hdop.hdop(), gps.hdop.isValid(), 6, 1, true, print_gps);
    Hdop = output.data;
    output.clear();

    printFloat(gpsLat, gps.location.isValid(), 11, 6, true, print_gps);
    Lat = output.data;
    output.clear();

    printFloat(gpsLng, gps.location.isValid(), 12, 6, true, print_gps);
    Long = output.data;
    output.clear();

    printInt(gps.location.age(), gps.location.isValid(), 5, false, print_gps);
    printDateTime(gps.date, gps.time, true, print_gps);
    Time = output.data;
    output.clear();

    printFloat(gps.altitude.meters(), gps.altitude.isValid(), 7, 2, false, print_gps);
    printFloat(gps.course.deg(), gps.course.isValid(), 7, 2, true, print_gps);
    Course = output.data;
    output.clear();

    printFloat(gps.speed.kmph(), gps.speed.isValid(), 6, 2, true, print_gps);
    Speed = output.data;
    output.clear();

    // Convert to nautical miles and to string
    Dist = String((float)MtoNM(distance));

    printInt(gps.charsProcessed(), true, 6, false, print_gps);
    printInt(gps.sentencesWithFix(), true, 10, false, print_gps);
    printInt(gps.failedChecksum(), true, 9, false, print_gps);
    if (print_gps) {
        Serial.print("\r");
    }

    smartDelay(1000);

    String space(" ");
    display_write(DISPDateTime, Time);
    display_write(DISPPosition, Lat + space + Long);
    display_write(DISPHDOP, String("HDOP ") + Hdop);
    display_write(DISPSats, String("Satellites ") + Sats);
    display_write(DISPSpeed, String("Speed ") + Speed + String(" Kts"));
    display_write(DISPCourse, String("Course ") + Course + String(" "));
    display_write(DISPDistance, String("Distance ") + Dist + String(" NM"));

    gpsLng = gps.location.lng();
    gpsLat = gps.location.lat();
    int32_t gpsCourse = gps.course.value();  // Course in degress clockwise from north
}
