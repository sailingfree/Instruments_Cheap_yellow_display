// Handle the N2K PGNS and update the displays

/*
Copyright (c) 2024 Peter Martin www.naiadhome.com

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the
Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <Arduino.h>
// NMEA headers
#include <N2kMessages.h>
#include <N2kMsg.h>
#include <NMEA2000.h>
#include <handlePGN.h>
#include <StringStream.h>
#include <GwLogger.h>
#include <ArduinoJson.h>

// Display handlers
#include <tftscreen.h>

// Time handling library
#include <ESP32Time.h>

#include <time.h>

static  ESP32Time rtc;

// Update the time displayed on the screen.
// Uses the internal system time which will have been updated
// if the GPS has provided a clock.
// Only update if the seconds have changed
void updateTime() {
    static time_t last = 0;
    struct tm tm;
    char buf[10];
    time_t now = time(NULL);
    gmtime_r(&now, &tm);

    if(now > last) {
        last = now;
        snprintf(buf, 9, "%02d:%02d:%02d", tm.tm_hour, tm.tm_min, tm.tm_sec);
        setMeter(SCR_GNSS, TIME, buf);
    }
}

// Function to return a String objcet formatted to a fixed number of decimal places
String dpf(double val, int dp = 2) {
    String result(val, 2);
    return result;
}

void handlePGN(tN2kMsg& msg) {
    // get the current system time and format with YYY-MM-DD HH:MM:SS
    // this is the primary key for each log entry.
    time_t now = time(NULL);
    char buf[25];
    struct tm tm;
    gmtime_r(&now, &tm);
        snprintf(buf, sizeof(buf), "%d-%d-%d %d:%d:%d",
        tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
        tm.tm_hour, tm.tm_min, tm.tm_sec);

   // Base object for logging
    JsonDocument doc;
    doc["PGN"] = msg.PGN;
    doc["ms"] = millis();

    // Add a record for the data found
    JsonObject record = doc[buf].to<JsonObject>();

    // Flag to indicate we actually wrote some data.
    bool hadData = true;   // We negate this in the default case below

     switch (msg.PGN) {
        case 127508: {
            // Battery Status
            unsigned char instance = 0xff;
            double voltage = 0.0;
            double current = 0.0;
            double temp = 273.0;
            unsigned char SID = 0xff;
            bool s = ParseN2kPGN127508(msg, instance, voltage, current, temp, SID);

            if (s && voltage != N2kDoubleNA && current != N2kDoubleNA) {
                switch (instance) {
                    case 0:
                        setMeter(SCR_ENGINE, HOUSEV, voltage, "V");
                        setMeter(SCR_ENGINE, HOUSEI, current, "A");
                        record["instance"]  = instance;
                        record["housev"] = voltage;
                        record["housei"] = current;
                        break;
                    case 1:
                        setMeter(SCR_ENGINE, ENGINEV, voltage, "V");
                        record["instance"]  = instance;
                        record["enginev"] = voltage;
                        ;
                        break;
                }
            }
        } break;

        case 127513:
            // Not interested
            break;

        case 127488: {
            // Engine Rapid
            unsigned char instance;
            double speed;
            double boost;
            int8_t trim;
            bool s = ParseN2kPGN127488(msg, instance, speed, boost, trim);
            if(s && speed != N2kDoubleNA) {
                setGauge(SCR_ENGINE, speed / 100);
                String es(speed, 0);
                es += "rpm";
                setVlabel(SCR_ENGINE, es);
                record["rpm"] = (int)speed / 100;
            }
        } break;

        case 130306: {
            // Wind
            double windSpeed;
            double windAngle;
            unsigned char instance;
            tN2kWindReference ref;
            bool s = ParseN2kPGN130306(msg, instance, windSpeed, windAngle, ref);
            String ws(msToKnots(windSpeed));
            ws += "kts";
            setVlabel(SCR_NAV, ws);
            if(s && windAngle != N2kDoubleNA) {
                setGauge(SCR_NAV, (int)RadToDeg(windAngle) + 180);
                setMeter(SCR_ENV, WINDANGLE, RadToDeg(windAngle), "°");
                record["angle"] = (int)RadToDeg(windAngle) + 180;
            }
            if(s && windSpeed != N2kDoubleNA) {
                setMeter(SCR_ENV, WINDSP, msToKnots(windSpeed), "kts");
                record["wind"] = dpf(msToKnots(windSpeed), 1);
            }
        } break;

        case 129026: {
            // COG/SOG
            unsigned char instance;
            tN2kHeadingReference ref;
            double hdg;
            double sog;
            bool s = ParseN2kPGN129026(msg, instance, ref, hdg, sog);
            if(s && sog != N2kDoubleNA) {
                setMeter(SCR_NAV, SOG, msToKnots(sog), "kts");
                record["sog"] = dpf(msToKnots(sog), 1);
            }
            if(s && hdg != N2kDoubleNA) {
                setMeter(SCR_NAV, HDG, RadToDeg(hdg), "°");
                record["cog"] = (int)RadToDeg(hdg);
            }

 

        } break;

        case 128267: {
            // depth;
            unsigned char instance;
            double depth;
            double offset;
            double range;
            bool s = ParseN2kPGN128267(msg, instance, depth, offset, range);
            if(s && depth != N2kDoubleNA) {
                setMeter(SCR_NAV, DEPTH, depth, "m");
                record["depth"] = dpf(depth,1);
            }
        } break;

        case 129029: {
            // GNSS
            unsigned char instance;
            uint16_t DaysSince1970;
            double SecondsSinceMidnight;
            double Latitude;
            double Longitude;
            double Altitude;
            tN2kGNSStype GNSStype;
            tN2kGNSSmethod GNSSmethod;
            unsigned char nSatellites;
            double Hdop;
            double PDOP;
            double GeoidalSeparation;
            unsigned char nReferenceStations;
            tN2kGNSStype ReferenceStationType;
            uint16_t ReferenceSationID;
            double AgeOfCorrection;

            bool s = ParseN2kPGN129029(msg, instance, DaysSince1970, SecondsSinceMidnight, Latitude,
                                       Longitude, Altitude, GNSStype, GNSSmethod, nSatellites, Hdop, PDOP, GeoidalSeparation,
                                       nReferenceStations, ReferenceStationType, ReferenceSationID, AgeOfCorrection);

            // Convert seconds since midnight to HH:MM:SS
            // Check we have valid values! 
            if (s && DaysSince1970 !=  N2kUInt16NA && SecondsSinceMidnight != N2kDoubleNA) {
                uint16_t seconds, minutes, hours;
                uint32_t t = SecondsSinceMidnight;
                seconds = t % 60;
                t = (t - seconds) / 60;
                minutes = t % 60;
                hours = (t - minutes) / 60;
                char buf[10];
                snprintf(buf, 9, "%02d:%02d:%02d", hours, minutes, seconds);

                setMeter(SCR_GNSS, HDOP, Hdop, "");

                record["lat"] = Latitude;
                record["lon"] = Longitude;
                record["time"] = buf;
                record["days"] = DaysSince1970;
                record["seconds"] = SecondsSinceMidnight;

#define SECONDS_IN_DAY (60 * 60 * 24)

                time_t now = (DaysSince1970 * SECONDS_IN_DAY) + SecondsSinceMidnight;
                // now = 365 * 10 * SECONDS_IN_DAY;
                // now += 26 * SECONDS_IN_DAY;
                struct tm tm;
                gmtime_r(&now, &tm);
                /*
                Serial.printf("XX %d %d %f %ld %d-%d-%d %d:%d:%d\n",
                              DaysSince1970,
                              SecondsSinceMidnight,
                              now,
                              tm.tm_hour, tm.tm_min, tm.tm_sec,
                              tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
                */
                // Update the system time
                rtc.setTime(tm.tm_sec, tm.tm_min, tm.tm_hour, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
            }
        } break;

        case 126992: {
            // date and time
            // Ignore this as we use the values in PGN129029
        }  break;

        case 129540: {
            // GNSS satellites in view

            unsigned char instance;
            tN2kRangeResidualMode Mode;
            uint8_t NumberOfSVs;

            // First get the number of satellites in view
            bool s = ParseN2kPGN129540(msg, instance, Mode, NumberOfSVs);

            initGNSSSky(NumberOfSVs);
            initGNSSSignal(NumberOfSVs);
            // Now for each satellite index get the details
            for (int i = 0; i < NumberOfSVs; i++) {
                tSatelliteInfo SatelliteInfo;

                s = ParseN2kPGN129540(msg, i, SatelliteInfo);
/*                Console->printf("RET %d Sat %d PRN %d AZ %f EL %f SNR %f\n", s, i, SatelliteInfo.PRN,
                                RadToDeg(SatelliteInfo.Azimuth), RadToDeg(SatelliteInfo.Elevation),
                                SatelliteInfo.SNR);
*/                                
                setGNSSSignal(i, SatelliteInfo.SNR);
                setGNSSSky(i, RadToDeg(SatelliteInfo.Azimuth), RadToDeg(SatelliteInfo.Elevation));
                
            }

            setMeter(SCR_GNSS, SATS, (double)NumberOfSVs, "");

        } break;

        case 130310: {
            // Outside Environmental
            unsigned char instance;
            double WaterTemperature;
            double OutsideAmbientAirTemperature;
            double AtmosphericPressure;

            bool s = ParseN2kPGN130310(msg, instance, WaterTemperature, OutsideAmbientAirTemperature, AtmosphericPressure);

            if(s && WaterTemperature > 273.0) {
                setMeter(SCR_ENV, SEATEMP, KelvinToC(WaterTemperature), "°C");
                record["seatemp"] = dpf(KelvinToC(WaterTemperature),1);
            }
        } break;

        case 130312: {
            // Temperature
            unsigned char instance;
            unsigned char TempInstance;
            tN2kTempSource TempSource;
            double ActualTemperature;
            double SetTemperature;

            bool s = ParseN2kPGN130312(msg, instance, TempInstance, TempSource, ActualTemperature, SetTemperature);

            if(s && ActualTemperature != 0.01) {
                setMeter(SCR_ENV, AIRTEMP, KelvinToC(ActualTemperature), "°C");
                record["airtemp"] = dpf(KelvinToC(ActualTemperature),1);
            }
        } break;

        case 130313: {
            // Humidity
            unsigned char instance;
            unsigned char HumidityInstance;
            tN2kHumiditySource HumiditySource;
            double ActualHumidity;

            bool s = ParseN2kPGN130313(msg, instance, HumidityInstance, HumiditySource, ActualHumidity);

            if(s && ActualHumidity != N2kDoubleNA) {
                setMeter(SCR_ENV, HUM, ActualHumidity, "%");
            }
        } break;

        case 130314: {
            // Pressure
            unsigned char instance;
            unsigned char PressureInstance;
            tN2kPressureSource PressureSource;
            double Pressure;

            bool s = ParseN2kPGN130314(msg, instance, PressureInstance, PressureSource, Pressure);

            if(s && Pressure != 0.01) {
                setMeter(SCR_ENV, PRESSURE, Pressure / 100, "");
                record["pressure"]  = (int)Pressure / 100;
            }
        } break;

        default:
            // Catch any messages we don't expect
            // and indicate no data
            hadData = false;
            break;
    }

    // If we had some data then log it
    size_t size = record.size();
    if(hadData && size > 0) {
        String buffer;
        serializeJson(doc, buffer);
        append_log(buffer.c_str());
        String now = rtc.getTime("%A, %B %d %Y %H:%M:%S");
    }
}