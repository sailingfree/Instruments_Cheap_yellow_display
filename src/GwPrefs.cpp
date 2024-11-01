// Preferences and settings for the n2kgw
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
#include <GwPrefs.h>
#include <Preferences.h>

#include <vector>

// Holds the list of configurable registers in the preference object
static std::vector<String> Reg;

static Preferences shellPref;
static const char *prefname = "settings";
static bool doneInit = false;

void GwPrefsInit() {
    if (!doneInit) {
        Reg.clear();
        Reg.push_back(WIFIMODE);
        Reg.push_back(SSID1);
        Reg.push_back(SSID2);
        Reg.push_back(SSPW1);
        Reg.push_back(SSPW2);
        Reg.push_back(GWHOST);
        Reg.push_back(GWPASS);
        Reg.push_back(GWSCREEN);
        doneInit = true;
    }
}

void GwPrint(Stream &s) {
    //   GwPrefsInit();
    s.printf("Preferences\n");
    for (String str : Reg) {
        String val = GwGetVal(str.c_str());
        s.printf("%s\t\t%s\n", str.c_str(), val.c_str());
    }
}

// Check to see if the register is in the list
bool isGwKey(String key) {
    //    GwPrefsInit();
    bool isreg = false;
    for (String str : Reg) {
        if (key == str) {
            isreg = true;
        }
    }
    return isreg;
}

// List the allowable registers
void GwListRegs(Stream &s) {
    //    GwPrefsInit();
    for (String str : Reg) {
        s.printf("\t%s\n", str.c_str());
    }
}

String GwGetVal(const char *key, String defval) {
    // GwPrefsInit();
    shellPref.begin(prefname, false);
    String val = shellPref.getString(key);
    shellPref.end();
    // Serial.printf("GWGETVAL %s '%s'\n", key, val.c_str());
    if (val == "") {
        val = defval;
    }
    return val;
}

String GwSetVal(const char *key, String newval) {
    // GwPrefsInit();
    String curval;
    shellPref.begin(prefname, false);
    shellPref.putString(key, newval);
    curval = shellPref.getString(key);
    shellPref.end();
    return curval;
}