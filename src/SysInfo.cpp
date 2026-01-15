// System and net info
/*
Copyright (c) 2022 Peter Martin www.naiadhome.com

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
#include <Esp.h>
#include <GwPrefs.h>
#include <NMEA0183Messages.h>
#include <SysInfo.h>
#include <esp_wifi.h>
#include <lv_version.h>
#include <esp_idf_version.h>

#include "uptime_formatter.h"
#include <Version.h>
#include <systemInfo.h>

void getNetInfo(Stream &s) {
    s.println("=========== NETWORK ==========");
    s.printf("HOST NAME: %s\n", host_name.c_str());
    s.printf("MAC: %s\n", macAddress.c_str());
    s.printf("WifiMode %s\n", WifiMode.c_str());
    s.printf("WifiIP %s\n", WifiIP.c_str());
    s.printf("WifiSSID %s\n", WifiSSID.c_str());
    s.println("=========== END ==========");
}

void getTaskInfo(Stream &s) {
    UBaseType_t ntasks = uxTaskGetNumberOfTasks();
    s.println("=========== TASKS ==========");
    s.printf("There are %d tasks\n", ntasks);
//    task_monitor();
    s.println("=========== SYSTEM ==========");
}


void getSysInfo(Stream &s) {
    EspClass esp;

    uint32_t sketchFree = esp.getFreeSketchSpace();
    uint32_t flashSize = esp.getFlashChipSize();
    uint32_t flashUsedPc = (flashSize - sketchFree) * 100 / flashSize;
    String uptime = uptime_formatter::getUptime();

    s.println("=========== SYSTEM ==========");
    systemInfo(s);
    s.printf("Flash used %d%%\n", flashUsedPc);
    s.println("=========== BUILD ==========");
    s.printf("Build version %s\n", VERSION);
    s.printf("Build date: %s\n", BUILD_TIMESTAMP);
    s.printf("LVGL Version %d.%d.%d\n", LVGL_VERSION_MAJOR, LVGL_VERSION_MINOR, LVGL_VERSION_PATCH);
    s.printf("ESPIDF %s\n", esp_get_idf_version());
    s.println("=========== SETTINGS ==========");
    GwPrint(s);
    s.println("=========== END ==========");
}

// Get the N2k messages and their counts and send to the configured output stream.
extern std::map<int, int> N2kMsgMap;
void getN2kMsgs(Stream &s) {
    std::map<int, int>::iterator it = N2kMsgMap.begin();

    s.println("======== N2K Messages ====");
    s.printf("PGN\tCount\tFunction\n");

    while (it != N2kMsgMap.end()) {
        const char *name = "unknown";
        switch (it->first) {
            case 127488:
                name = "Engine Rapid";
                break;
            case 127508:
                name = "Battery Status";
                break;
            case 127513:
                name = "Battery Configuration";
                break;
            case 60928:
                name = "IsoAddress";
                break;
            case 126992:
                name = "System Time";
                break;
            case 126996:
                name = "Product Information";
                break;
            case 127250:
                name = "Magnetic Heading";
                break;
            case 127489:
                name = "Engine Dynamic";
                break;
            case 130306:
                name = "Wind Data";
                break;
            case 128267:
                name = "Depth Data";
                break;
            case 129026:
                name = "COG/SOG";
                break;
            case 130310:
                name = "Outside environment";
                break;
            case 130311:
                name = "Environmental Parameters";
                break;
            case 130312:
                name = "Temperature";
                break;
            case 130313:
                name = "Humidity";
                break;
            case 130314:
                name = "Pressure";
                break;
            case 129029:
                name = "GNSS";
                break;
            case 129539:
                name = "GNSS DOP";
                break;
            case 129540:
                name = "GNSS Sats in view";
                break;
        }
        s.printf("%d\t%d\t%s\n", it->first, it->second, name);
        it++;
    }
    s.println("=========== END ==========");
}