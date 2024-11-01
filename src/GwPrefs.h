// preferences
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
#pragma once

#include <Arduino.h>

void GwPrefsInit();
String GwSetVal(const char *key, String val);
String GwGetVal(const char *key, String defval = "---");
void GwListRegs(Stream &s);
bool isGwKey(String k);
void GwPrint(Stream &s);

// WiFi mode. Can be AP CL OFF
#define WIFIMODE "wifi"

// the keys we support
// SSID for the two optional wifi networks to try
#define SSID1 "ssid1"
#define SSID2 "ssid2"
#define SSPW1 "sspw1"
#define SSPW2 "sspw2"

// The AP name and password when operating in AP mode
#define GWSSID "gwssid"
#define GWPASS "gwpass"

// Diameter of the engine pulley
#define ENGINEDIA "enginedia"

// Diameter fo the alternator pulley
#define ALTDIA "altdia"

// Number of alternator poles
#define ALTPOLES "poles"

// Pressure calibration in mbar
#define PRESSCAL "presscal"

// Compass offset value in degrees
#define COMPASSOFF "compassoff"

// Hostname advertised by the network
#define GWHOST "gwhost"

// The last selected screen number
#define GWSCREEN "screen"
