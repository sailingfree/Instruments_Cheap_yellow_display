// Wrap the admin functions here

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
#include <GwOTA.h>
#include <GwPrefs.h>
#include <GwShell.h>
#include <GwTelnet.h>
#include <MyWiFi.h>

// Global objects and variables
String host_name;
String Model = "Naiad Display 1";
String macAddress;  // Make the mac address gloabal

// Setup the shell and other admin
void adminSetup(void) {
    uint8_t chipid[6];
    uint32_t id = 0;
    uint32_t i;

    // get the MAC address
    esp_err_t fuse_error = esp_efuse_mac_get_default(chipid);
    if (fuse_error) {
        Serial.printf("efuse error: %d\n", fuse_error);
    }

    for (i = 0; i < 6; i++) {
        if (i != 0) {
            macAddress += ":";
        }
        id += (chipid[i] << (7 * i));
        macAddress += String(chipid[i], HEX);
    }

    // Initialise the preferences
    GwPrefsInit();

    // Generate the hostname by appending the last two octets of the mac address to make it unique
    String hname = GwGetVal(GWHOST, "n2kdisplay");
    host_name = hname + String(chipid[4], HEX) + String(chipid[5], HEX);

    // Init the shell
    initGwShell();
    setShellSource(&Serial);
}

void adminWork() {
    if (WiFi.status() == WL_CONNECTED) {
        // handle any telnet sessions
        handleTelnet();
        handleOTA();
    }

    // run any local shell commands
    handleShell();
}
