// Functions fore drawing on the TFT screen using lvgl

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


#include <GwPrefs.h>
#include <StringStream.h>
#include <SysInfo.h>
//#include <TFT_eSPI.h>
//#include <lvgl.h>
//#include <rotary_encoder.h>
#include <tftscreen.h>
#include <NMEA2000.h>
#include <N2kMessages.h>

// A library for interfacing with the touch screen
//
// Can be installed from the library manager (Search for "XPT2046")
// https://github.com/PaulStoffregen/XPT2046_Touchscreen
//#include <XPT2046_Touchscreen.h>

// ----------------------------
// Touch Screen pins
// ----------------------------

// The CYD touch uses some non default
// SPI pins

#define XPT2046_IRQ 36
#define XPT2046_MOSI 32
#define XPT2046_MISO 39
#define XPT2046_CLK 25
#define XPT2046_CS 33

// ----------------------------

//SPIClass mySpi = SPIClass(HSPI);
//XPT2046_Touchscreen ts(XPT2046_CS, XPT2046_IRQ);

//TFT_eSPI tft = TFT_eSPI(); /* TFT instance */
//static lv_disp_buf_t disp_buf;
//static lv_color_t buf[TFT_WIDTH * 10];

#if USE_LV_LOG != 0
/* Serial debugging */
void my_print(lv_log_level_t level, const char *file, uint32_t line, const char *dsc) {
    Serial.printf("%s@%d->%s\r\n", file, line, dsc);
    Serial.flush();
}
#endif

// Forward declarations
//static lv_obj_t *createEngineScreen(int screen);
//static lv_obj_t *createNavScreen(int screen);
//static lv_obj_t *createGNSSScreen(int screen);
//static lv_obj_t *createEnvScreen(int screen);
//static lv_obj_t *createInfoScreen(int screen);

/* Display flushing */
//void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p) {
//    uint32_t w = (area->x2 - area->x1 + 1);
//    uint32_t h = (area->y2 - area->y1 + 1);

//    tft.startWrite();
//    tft.setAddrWindow(area->x1, area->y1, w, h);
//    tft.pushColors(&color_p->full, w * h, true);
//    tft.endWrite();

//    lv_disp_flush_ready(disp);
//}

#if 0
/*
 * Read the input rotary encoder
 * Read the value and the button state
 */
bool read_encoder(lv_indev_drv_t *indev, lv_indev_data_t *data) {
    static int32_t last_val = 0;

    int32_t rval = rotaryEncoder.readEncoder();
    data->enc_diff = rval - last_val;
    last_val = rval;
    data->state = rotaryEncoder.isEncoderButtonDown() ? LV_INDEV_STATE_PR : LV_INDEV_STATE_REL; /* Dummy - no press */

    if (data->enc_diff > 0) {
        data->key = LV_KEY_UP;
    } else if (data->enc_diff < 0) {
        data->key = LV_KEY_DOWN;
    }
    return false;  // Never any more data epected from this device
}

#endif

// Static data items for the screens and their data items
//static Indicator *ind[SCR_MAX][6];
//static lv_obj_t *screen[SCR_MAX];
//static lv_obj_t *gauges[SCR_MAX];
//static lv_obj_t *vals[SCR_MAX];
//static lv_obj_t *infos[SCR_MAX];

// define text areas
//static lv_obj_t *textAreas[SCR_MAX];

// GNSS Signal strength
//static lv_chart_series_t *GNSSChartSeries;
//static lv_obj_t *GNSSChart;

// GNSSS sky view
//static lv_obj_t *skyView;

// Static local cache of satellite data
#define MAXSATS 9

//struct SatData {
//    lv_obj_t *dot;
//};

//static SatData satData[MAXSATS];

// Print some text to the boot info screen textarea
void displayText(const char *str) {
}

// Helper
#define MAX_TOUCH_X (4096 / TFT_HEIGHT)
#define MAX_TOUCH_Y (4096 / TFT_WIDTH)

//void printTouchToSerial(TS_Point p) {
//    Serial.print("Pressure = ");
//    Serial.print(p.z);
//    Serial.print(", x = ");
//    Serial.print(p.x / MAX_TOUCH_X);
//    Serial.print(", y = ");
//    Serial.print(p.y / MAX_TOUCH_Y);
//    Serial.println();
//}

/*
 * Read the touch panel
 */

//bool read_touch(lv_indev_drv_t *indev, lv_indev_data_t *data) {
//    if (ts.tirqTouched() && ts.touched()) {
//        TS_Point p = ts.getPoint();
//        //    printTouchToSerial(p);
//        data->point.x = p.x / MAX_TOUCH_X;
//        data->point.y = p.y / MAX_TOUCH_Y;
//        data->state = LV_INDEV_STATE_PR or LV_INDEV_STATE_REL;
//    }
//    return false;
//}

static int iiscrnum = 0;  // Screen number selected

// Handle the touch event.
//static void my_event_cb(lv_obj_t *obj, lv_event_t event) {
    //   Serial.printf("EV %d\n", event);
//    if (event == LV_EVENT_RELEASED) {
//        // Key up swap screens.
//        iiscrnum = (iiscrnum + 1) % SCR_MAX;
//        if (iiscrnum == SCR_BOOT) {
 //           // Ignore the boot messages screen during normal operation
//            iiscrnum++;
//        }
//        lv_scr_load(screen[iiscrnum]);
//        StringStream s;
//        getSysInfo(s);
///        lv_textarea_set_text(textAreas[SCR_SYSINFO], s.data.c_str());
//        s.clear();
//        getN2kMsgs(s);
//        lv_textarea_set_text(textAreas[SCR_MSGS], s.data.c_str());
//        s.clear();
//        getNetInfo(s);
//        lv_textarea_set_text(textAreas[SCR_NETWORK], s.data.c_str());

// /       String val(iiscrnum);
//        GwSetVal(GWSCREEN, val);
//    }
//}


void metersSetup() {
}


// Update the meters. Called regularly from the main loop/task
void metersWork(void) {
}

// Set the value of a meter using a double
void setMeter(int scr, int idx, double value, const char *units) {
}

void setGauge(int scr, double value) {
}

// Set the value of a meter using a string
void setMeter(int scr, int idx, String &string) {
}

// set using a char *
void setMeter(int scr, int idx, char * str) {
}

void setVlabel(int scr, String &str) {
}

void setilabel(int scr, String &str) {
}

// Load the first screen
void loadScreen() {
}

// set a value in the GNSSChart
void setGNSSSignal(uint32_t idx, uint32_t val) {
}

// set one of the indicators in the sjky view
void setGNSSSky(uint32_t idx, double azimuth, double declination) {
}

// Initialise the sky view for the nunber of satellites. Removes any old ones not needed
void initGNSSSky(uint32_t svs) {
}

// Init the signal display to the number of SVs
void initGNSSSignal(uint32_t svs) {
}