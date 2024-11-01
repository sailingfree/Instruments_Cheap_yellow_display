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
#include <TFT_eSPI.h>
#include <lvgl.h>
//#include <rotary_encoder.h>
#include <tftscreen.h>
#include <NMEA2000.h>
#include <N2kMessages.h>

// A library for interfacing with the touch screen
//
// Can be installed from the library manager (Search for "XPT2046")
// https://github.com/PaulStoffregen/XPT2046_Touchscreen
#include <XPT2046_Touchscreen.h>

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

SPIClass mySpi = SPIClass(HSPI);
XPT2046_Touchscreen ts(XPT2046_CS, XPT2046_IRQ);

TFT_eSPI tft = TFT_eSPI(); /* TFT instance */
static lv_disp_buf_t disp_buf;
static lv_color_t buf[TFT_WIDTH * 10];

#if USE_LV_LOG != 0
/* Serial debugging */
void my_print(lv_log_level_t level, const char *file, uint32_t line, const char *dsc) {
    Serial.printf("%s@%d->%s\r\n", file, line, dsc);
    Serial.flush();
}
#endif

// Forward declarations
static lv_obj_t *createEngineScreen(int screen);
static lv_obj_t *createNavScreen(int screen);
static lv_obj_t *createGNSSScreen(int screen);
static lv_obj_t *createEnvScreen(int screen);
static lv_obj_t *createInfoScreen(int screen);

/* Display flushing */
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p) {
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);

    tft.startWrite();
    tft.setAddrWindow(area->x1, area->y1, w, h);
    tft.pushColors(&color_p->full, w * h, true);
    tft.endWrite();

    lv_disp_flush_ready(disp);
}

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
static Indicator *ind[SCR_MAX][6];
static lv_obj_t *screen[SCR_MAX];
static lv_obj_t *gauges[SCR_MAX];
static lv_obj_t *vals[SCR_MAX];
static lv_obj_t *infos[SCR_MAX];

// define text areas
static lv_obj_t *textAreas[SCR_MAX];

// GNSS Signal strength
static lv_chart_series_t *GNSSChartSeries;
static lv_obj_t *GNSSChart;

// GNSSS sky view
static lv_obj_t *skyView;

// Static local cache of satellite data
#define MAXSATS 9

struct SatData {
    lv_obj_t *dot;
};

static SatData satData[MAXSATS];

// Print some text to the boot info screen textarea
void displayText(const char *str) {
    if (textAreas[SCR_BOOT]) {
        lv_textarea_add_text(textAreas[SCR_BOOT], str);
        lv_textarea_cursor_down(textAreas[SCR_BOOT]);
        metersWork();
    }
}

// Helper
#define MAX_TOUCH_X (4096 / TFT_HEIGHT)
#define MAX_TOUCH_Y (4096 / TFT_WIDTH)

void printTouchToSerial(TS_Point p) {
    Serial.print("Pressure = ");
    Serial.print(p.z);
    Serial.print(", x = ");
    Serial.print(p.x / MAX_TOUCH_X);
    Serial.print(", y = ");
    Serial.print(p.y / MAX_TOUCH_Y);
    Serial.println();
}

/*
 * Read the touch panel
 */

bool read_touch(lv_indev_drv_t *indev, lv_indev_data_t *data) {
    if (ts.tirqTouched() && ts.touched()) {
        TS_Point p = ts.getPoint();
        //    printTouchToSerial(p);
        data->point.x = p.x / MAX_TOUCH_X;
        data->point.y = p.y / MAX_TOUCH_Y;
        data->state = LV_INDEV_STATE_PR or LV_INDEV_STATE_REL;
    }
    return false;
}

static int iiscrnum = 0;  // Screen number selected

// Handle the touch event.
static void my_event_cb(lv_obj_t *obj, lv_event_t event) {
    //   Serial.printf("EV %d\n", event);
    if (event == LV_EVENT_RELEASED) {
        // Key up swap screens.
        iiscrnum = (iiscrnum + 1) % SCR_MAX;
        if (iiscrnum == SCR_BOOT) {
            // Ignore the boot messages screen during normal operation
            iiscrnum++;
        }
        lv_scr_load(screen[iiscrnum]);
        StringStream s;
        getSysInfo(s);
        lv_textarea_set_text(textAreas[SCR_SYSINFO], s.data.c_str());
        s.clear();
        getN2kMsgs(s);
        lv_textarea_set_text(textAreas[SCR_MSGS], s.data.c_str());
        s.clear();
        getNetInfo(s);
        lv_textarea_set_text(textAreas[SCR_NETWORK], s.data.c_str());

        String val(iiscrnum);
        GwSetVal(GWSCREEN, val);
    }
}

// Constructor. Binds to the parent object.
Indicator::Indicator(lv_obj_t *parent, const char *name, uint32_t x, uint32_t y) {
    container = lv_cont_create(parent, NULL);
    lv_obj_set_style_local_border_width(container, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, 2);
    lv_obj_set_style_local_border_color(container, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_cont_set_layout(container, LV_LAYOUT_CENTER);
    lv_cont_set_fit(container, LV_FIT_NONE);
    lv_obj_set_size(container, TFT_HEIGHT / 2, TFT_WIDTH / 3);
    lv_obj_set_style_local_margin_left(container, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_margin_right(container, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, 0);

    label = lv_label_create(container, NULL);
    lv_obj_set_style_local_text_font(label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_montserrat_18);
    lv_label_set_text(label, name);

    text = lv_label_create(container, NULL);
    lv_obj_set_style_local_text_font(text, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_montserrat_32);
    lv_label_set_text(text, "---");
    text->event_cb = my_event_cb;

    lv_obj_set_pos(container, x, y);
}

void Indicator::setValue(const char *value) {
    lv_label_set_text(text, value);
}

void touch_init() {
    // Start the SPI for the touch screen and init the TS library
    mySpi.begin(XPT2046_CLK, XPT2046_MISO, XPT2046_MOSI, XPT2046_CS);
    bool s = ts.begin(mySpi);
    Serial.printf("Touch begin => %d\n", s);
    ts.setRotation(1);
}

void metersSetup() {
//    rotary_setup();
    lv_init();
#if USE_LV_LOG != 0
    lv_log_register_print_cb(my_print); /* register print function for debugging */
#endif
    touch_init();

    //   tft.begin(); /* TFT init */
    tft.init();

    // Clear the screen
    // tft.fillRect(0, 0, TFT_WIDTH, TFT_HEIGHT, 0);
    tft.setRotation(1); /* Landscape orientation */

    lv_disp_buf_init(&disp_buf, buf, NULL, TFT_WIDTH * 10);

    /*Initialize the display*/
    lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = TFT_HEIGHT;
    disp_drv.ver_res = TFT_WIDTH;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.buffer = &disp_buf;
    lv_disp_drv_register(&disp_drv);

    // At startup create a text area to display startup progress.
    screen[SCR_BOOT] = createInfoScreen(SCR_BOOT);
    displayText("Initialising screens...");

    /*Initialize the rotary encoder input device drivers */
//    lv_indev_drv_t indev_drv;
//    lv_indev_drv_init(&indev_drv);
//    indev_drv.type = LV_INDEV_TYPE_ENCODER;
//    indev_drv.read_cb = read_encoder;
//    lv_indev_t *rotary = lv_indev_drv_register(&indev_drv);

    // Create the group for the rotary
    lv_group_t *g = lv_group_create();

    // And for the touch
    lv_indev_drv_t touch_dev;
    lv_indev_drv_init(&touch_dev);
    touch_dev.type = LV_INDEV_TYPE_POINTER;
    touch_dev.read_cb = read_touch;
    lv_indev_t *touch = lv_indev_drv_register(&touch_dev);

    lv_group_t *t = lv_group_create();

    // Create the screens. These get loaded later
    screen[SCR_ENGINE] = createEngineScreen(SCR_ENGINE);
    screen[SCR_NAV] = createNavScreen(SCR_NAV);
    screen[SCR_GNSS] = createGNSSScreen(SCR_GNSS);
    screen[SCR_ENV] = createEnvScreen(SCR_ENV);
    screen[SCR_NETWORK] = createInfoScreen(SCR_NETWORK);
    screen[SCR_SYSINFO] = createInfoScreen(SCR_SYSINFO);
    screen[SCR_MSGS] = createInfoScreen(SCR_MSGS);
    screen[SCR_BOOT] = createInfoScreen(SCR_BOOT);

    // Load the boot screen
    lv_scr_load(screen[SCR_BOOT]);
}

static void setCommonStyles(lv_obj_t *obj) {
    lv_obj_set_auto_realign(obj, true);                   /*Auto realign when the size changes*/
    lv_obj_align_origo(obj, NULL, LV_ALIGN_CENTER, 0, 0); /*This parametrs will be used when re-aligned*/
    lv_cont_set_fit(obj, LV_FIT_PARENT);
    lv_cont_set_layout(obj, LV_LAYOUT_OFF);
    lv_obj_set_style_local_pad_left(obj, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_pad_right(obj, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_pad_top(obj, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_pad_bottom(obj, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_pad_inner(obj, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_margin_left(obj, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_margin_right(obj, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, 0);
}

// create a container for a gauge or other display object
// setting styles etc
static lv_obj_t *createContainer(lv_obj_t *cont) {
    lv_obj_t *container = lv_cont_create(cont, NULL);
    lv_obj_set_style_local_border_width(container, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, 2);
    lv_obj_set_style_local_border_color(container, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_cont_set_layout(container, LV_LAYOUT_COLUMN_MID);
    lv_cont_set_fit(container, LV_FIT_NONE);
    lv_obj_set_size(container, TFT_HEIGHT / 2, (TFT_WIDTH / 6 * 5));
    lv_obj_set_style_local_margin_left(container, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_margin_right(container, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, 0);
    lv_obj_set_pos(container, TFT_HEIGHT / 2, 0);
    lv_obj_set_style_local_pad_inner(container, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, 2);
    return container;
}

static lv_obj_t *createEngineScreen(int scr) {
    lv_obj_t *gauge;
    lv_obj_t *vlabel, *ilabel;
    lv_obj_t *screen = lv_obj_create(NULL, NULL);
    lv_obj_t *cont = lv_cont_create(screen, NULL);
    setCommonStyles(cont);

    // Create the indicator panels
    ind[scr][0] = new Indicator(cont, "House Voltage", 0, 0);
    ind[scr][1] = new Indicator(cont, "House Current", 0, TFT_WIDTH / 3);
    ind[scr][2] = new Indicator(cont, "Engine Voltage", 0, 2 * TFT_WIDTH / 3);

    // Create a container for a gauge
    // lv_cont_set_layout(cont, LV_LAYOUT_COLUMN_RIGHT);
    lv_obj_t *container = createContainer(cont);

    // Gauge for the RPM
    uint8_t major = 8;     // Major ticks - 500RPM each
    uint8_t minor = (36);  // max is 3500 RPM
    gauge = lv_gauge_create(container, NULL);
    lv_obj_set_size(gauge, TFT_HEIGHT / 2, TFT_HEIGHT / 2);
    lv_obj_set_style_local_pad_inner(gauge, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, 10);
    lv_obj_set_style_local_pad_left(gauge, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, 2);
    lv_obj_set_style_local_pad_right(gauge, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, 2);
    lv_obj_set_style_local_pad_top(gauge, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, 2);
    lv_obj_set_style_local_pad_bottom(gauge, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, 2);

    lv_gauge_set_value(gauge, 0, 0);
    lv_gauge_set_range(gauge, 0, 35);
    lv_gauge_set_scale(gauge, 270, minor, major);
    lv_gauge_set_critical_value(gauge, 30);
    lv_obj_set_style_local_text_font(gauge, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT,
                                     &lv_font_montserrat_16);
    lv_obj_align(gauge, container, LV_ALIGN_IN_TOP_MID, 0, 0);
    gauges[scr] = gauge;

    // And the Value label
    vlabel = lv_label_create(container, NULL);
    lv_label_set_text(vlabel, "0000");
    lv_obj_align(vlabel, container, LV_ALIGN_IN_BOTTOM_MID, 0, 0);
    lv_obj_set_style_local_text_font(vlabel, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT,
                                     &lv_font_montserrat_24);

    vals[scr] = vlabel;
    // Info at the bottom
    ilabel = lv_label_create(cont, NULL);
    lv_label_set_text(ilabel, "000.000.000.000");
    lv_obj_align(ilabel, cont, LV_ALIGN_IN_BOTTOM_RIGHT, 0, 0);
    lv_obj_set_style_local_text_font(ilabel, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT,
                                     &lv_font_montserrat_12);
    infos[scr] = ilabel;

    // Event callback
    lv_obj_set_event_cb(gauge, my_event_cb);                  /*Assign an event callback*/
    lv_obj_set_event_cb(ind[scr][0]->container, my_event_cb); /*Assign an event callback*/
    lv_obj_set_event_cb(ind[scr][1]->container, my_event_cb); /*Assign an event callback*/
    lv_obj_set_event_cb(ind[scr][2]->container, my_event_cb); /*Assign an event callback*/

    return screen;
}

static lv_obj_t *createNavScreen(int scr) {
    lv_obj_t *gauge;
    lv_obj_t *vlabel, *ilabel;
    lv_obj_t *screen = lv_obj_create(NULL, NULL);
    lv_obj_t *cont = lv_cont_create(screen, NULL);
    setCommonStyles(cont);

    ind[scr][0] = new Indicator(cont, "SOG", 0, 0);
    ind[scr][1] = new Indicator(cont, "Depth", 0, TFT_WIDTH / 3);
    ind[scr][2] = new Indicator(cont, "HDG", 0, 2 * TFT_WIDTH / 3);

    // Create a container and a gauge
    lv_obj_t *container = createContainer(cont);

    // Gauge for the Wind
    uint8_t label_cnt = 5;  // Major ticks N S E W
    uint8_t sub_div = 8;
    uint8_t line_cnt = line_cnt = (sub_div + 1) * (label_cnt - 1) + 1;  // Max

    
    static lv_style_t style;
    lv_style_init(&style);
    gauge = lv_gauge_create(container, NULL);
    lv_obj_set_size(gauge, TFT_HEIGHT / 2, TFT_HEIGHT / 2);
    lv_obj_set_style_local_pad_inner(gauge, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, 10);
    lv_obj_set_style_local_pad_left(gauge, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, 2);
    lv_obj_set_style_local_pad_right(gauge, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, 2);
    lv_obj_set_style_local_pad_top(gauge, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, 2);
    lv_obj_set_style_local_pad_bottom(gauge, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, 2);

    lv_gauge_set_value(gauge, 0, 0);
    lv_gauge_set_range(gauge, 1, 360);
    lv_gauge_set_scale(gauge, 359, line_cnt, label_cnt); 
    lv_gauge_set_angle_offset(gauge, 181); 
    lv_gauge_set_critical_value(gauge, 0);
    lv_style_set_scale_end_color(&style, LV_STATE_DEFAULT, LV_COLOR_BLUE);
    lv_style_set_line_color(&style, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_obj_set_style_local_text_font(gauge, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT,
                                     &lv_font_montserrat_16);
    lv_obj_add_style(gauge, LV_GAUGE_PART_MAIN, &style);
    lv_obj_align(gauge, container, LV_ALIGN_IN_TOP_MID, 0, 0);
    gauges[scr] = gauge;

    // And the Value label
    vlabel = lv_label_create(container, NULL);
    lv_label_set_text(vlabel, "000");
    lv_obj_align(vlabel, container, LV_ALIGN_IN_BOTTOM_MID, 0, 0);
    lv_obj_set_style_local_text_font(vlabel, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT,
                                     &lv_font_montserrat_24);
    vals[scr] = vlabel;

    // Info at the bottom
    ilabel = lv_label_create(cont, NULL);
    lv_label_set_text(ilabel, "000.000.000.000");
    lv_obj_align(ilabel, cont, LV_ALIGN_IN_BOTTOM_RIGHT, 0, 0);
    lv_obj_set_style_local_text_font(ilabel, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT,
                                     &lv_font_montserrat_12);
    infos[scr] = ilabel;

    // Event callback
    lv_obj_set_event_cb(gauge, my_event_cb);                  /*Assign an event callback*/
    lv_obj_set_event_cb(ind[scr][0]->container, my_event_cb); /*Assign an event callback*/
    lv_obj_set_event_cb(ind[scr][1]->container, my_event_cb); /*Assign an event callback*/
    lv_obj_set_event_cb(ind[scr][2]->container, my_event_cb); /*Assign an event callback*/

    return screen;
}

// Screen for the GNSS status and info
static lv_obj_t *createGNSSScreen(int scr) {
    lv_obj_t *vlabel, *ilabel;
    lv_obj_t *screen = lv_obj_create(NULL, NULL);
    lv_obj_t *cont = lv_cont_create(screen, NULL);
    setCommonStyles(cont);

    ind[scr][0] = new Indicator(cont, "SATS", 0, 0);
    ind[scr][1] = new Indicator(cont, "HDOP", 0, TFT_WIDTH / 3);
    ind[scr][2] = new Indicator(cont, "UTC", 0, 2 * TFT_WIDTH / 3);

    // Create a sky view. An image forms the background rings
    LV_IMG_DECLARE(sky);
    skyView = lv_img_create(cont, NULL);
    lv_img_set_src(skyView, &sky);
    lv_obj_align(skyView, NULL, LV_ALIGN_IN_TOP_RIGHT, 0, 0);
    lv_obj_set_style_local_margin_top(skyView, LV_IMG_PART_MAIN, LV_STATE_DEFAULT, 0);

    // Chart for the signal strength
    GNSSChart = lv_chart_create(cont, NULL);
    lv_obj_set_size(GNSSChart, TFT_HEIGHT / 2, TFT_WIDTH / 3);
    lv_obj_align(GNSSChart, NULL, LV_ALIGN_IN_BOTTOM_RIGHT, 0, 0);
    lv_chart_set_type(GNSSChart, LV_CHART_TYPE_COLUMN);
    lv_chart_set_range(GNSSChart, MIN_SNR, MAX_SNR);  // Typical min and max SNR

    // I want the bars to fill their columns but the default leaves a big gap
    // This value fits the number of bars and was found by trial and error.
    lv_obj_set_style_local_pad_inner(GNSSChart, LV_CHART_PART_SERIES, LV_STATE_DEFAULT, -5);
    GNSSChartSeries = lv_chart_add_series(GNSSChart, LV_COLOR_GREEN);

    // Zero all the values at the start
    for (int i = 0; i < MAXSATS; i++) {
        GNSSChartSeries->points[i] = 0;
    }

    // Event callback
    lv_obj_set_event_cb(ind[scr][0]->container, my_event_cb); /*Assign an event callback*/
    lv_obj_set_event_cb(ind[scr][1]->container, my_event_cb); /*Assign an event callback*/
    lv_obj_set_event_cb(ind[scr][2]->container, my_event_cb); /*Assign an event callback*/

#if GNSSTEST
    // Test data
    for (int i = 0; i < 9; i++) {
        setGNSSSignal(i, random(40, 50));
    }

    // Creates a spiral from the top clockwise to the centre
    uint32_t points = 64;
    for (int i = 0; i < points; i++) {
        setGNSSSky(i, i * 360 / points, i * 90 / points);
    }
#endif
    return screen;
}

// Screen for the environmental status and info
static lv_obj_t *createEnvScreen(int scr) {
    lv_obj_t *screen = lv_obj_create(NULL, NULL);
    lv_obj_t *cont = lv_cont_create(screen, NULL);
    setCommonStyles(cont);

    ind[scr][0] = new Indicator(cont, "Air Temp", 0, 0);
    ind[scr][1] = new Indicator(cont, "Humidity", 0, TFT_WIDTH / 3);
    ind[scr][2] = new Indicator(cont, "Pressure", 0, 2 * TFT_WIDTH / 3);
    ind[scr][3] = new Indicator(cont, "Sea Temp", TFT_HEIGHT / 2, 0);
    ind[scr][4] = new Indicator(cont, "Wind Speed", TFT_HEIGHT / 2, TFT_WIDTH / 3);
    ind[scr][5] = new Indicator(cont, "Apparent Wind", TFT_HEIGHT / 2, 2 * TFT_WIDTH / 3);

    // Event callback
    lv_obj_set_event_cb(ind[scr][0]->container, my_event_cb); /*Assign an event callback*/
    lv_obj_set_event_cb(ind[scr][1]->container, my_event_cb); /*Assign an event callback*/
    lv_obj_set_event_cb(ind[scr][2]->container, my_event_cb); /*Assign an event callback*/
    lv_obj_set_event_cb(ind[scr][3]->container, my_event_cb); /*Assign an event callback*/
    lv_obj_set_event_cb(ind[scr][4]->container, my_event_cb); /*Assign an event callback*/
    lv_obj_set_event_cb(ind[scr][5]->container, my_event_cb); /*Assign an event callback*/

    return screen;
}

// Screens for system info
static lv_obj_t *createInfoScreen(int scr) {
    char buf[128];
    LV_FONT_DECLARE(arial8);
    lv_obj_t *screen = lv_obj_create(NULL, NULL);
    // Create a text area to display startup progress.
    textAreas[scr] = lv_textarea_create(screen, NULL);
    lv_obj_set_size(textAreas[scr], 200, TFT_WIDTH);
    lv_obj_align(textAreas[scr], NULL, LV_ALIGN_CENTER, 0, 0);
    lv_textarea_set_text(textAreas[scr], "");
    lv_obj_set_style_local_text_font(textAreas[scr], LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &arial8);

    // Set callback for touch etc
    lv_obj_set_event_cb(textAreas[scr], my_event_cb);

    return screen;
}

// Update the meters. Called regularly from the main loop/task
void metersWork(void) {
    lv_task_handler(); /* let the GUI do its work */
}

// Set the value of a meter using a double
void setMeter(int scr, int idx, double value, const char *units) {
    //    Serial.printf("SET %d %d %f\n", scr, idx, value);
    if (scr >= 0 && scr < SCR_MAX && ind[scr][idx]) {
        String v(value, 2);
        v += units;
        ind[scr][idx]->setValue(v.c_str());
    }
}

void setGauge(int scr, double value) {
    if (scr >= 0 && scr < SCR_MAX && gauges[scr]) {
        lv_gauge_set_value(gauges[scr], 0, value);
    }
}

// Set the value of a meter using a string
void setMeter(int scr, int idx, String &string) {
    if (scr >= 0 && scr < SCR_MAX && ind[scr][idx]) {
        ind[scr][idx]->setValue(string.c_str());
    }
}

// set using a char *
void setMeter(int scr, int idx, char * str) {
    if (scr >= 0 && scr < SCR_MAX && ind[scr][idx]) {
        ind[scr][idx]->setValue(str);
    }
}

void setVlabel(int scr, String &str) {
    if (scr >= 0 && scr < SCR_MAX && vals[scr]) {
        lv_label_set_text(vals[scr], str.c_str());
    }
}

void setilabel(int scr, String &str) {
    if (scr >= 0 && scr < SCR_MAX && infos[scr]) {
        lv_label_set_text(infos[scr], str.c_str());
    }
}

// Load the first screen
void loadScreen() {
    // Get the last screen number if set and use that
    String scrnum = GwGetVal(GWSCREEN);
    if (scrnum != "---") {
        iiscrnum = scrnum.toInt() % SCR_MAX;
    }
    lv_scr_load(screen[iiscrnum]);
}

// set a value in the GNSSChart
void setGNSSSignal(uint32_t idx, uint32_t val) {
    if (idx < 0 || idx > MAXSATS)
        return;  // Ignore bad index

    GNSSChartSeries->points[idx] = val;
    lv_chart_refresh(GNSSChart);
}

// set one of the indicators in the sjky view
void setGNSSSky(uint32_t idx, double azimuth, double declination) {
    if (idx < 0 || idx > MAXSATS)
        return;  // Ignore bad index
    if (azimuth < 0 || azimuth > 360 || declination < 0 || declination > 90) {
        return;  // Ignore inplausible values
    }

    // Green dot for the sky view
    if (!satData[idx].dot) {
        // First time for this index so create the image object
        LV_IMG_DECLARE(green_dot);
        satData[idx].dot = lv_img_create(skyView, NULL);
        lv_img_set_src(satData[idx].dot, &green_dot);
    }
    uint32_t dotw, doth;
    dotw = lv_obj_get_width(satData[idx].dot);
    doth = lv_obj_get_height(satData[idx].dot);
    uint32_t skyw, skyh;
    skyw = lv_obj_get_width(skyView);
    skyh = lv_obj_get_height(skyView);
    double rad = skyw / 2 - dotw;
    rad *= cos(DegToRad(declination));
    int32_t x = sin(DegToRad(azimuth)) * rad;
    int32_t y = cos(DegToRad(azimuth)) * rad;
    int32_t xorig = skyw / 2 - dotw / 2;
    int32_t yorig = skyh / 2 - doth / 2;
    //    Serial.printf("IDX %d AZ %f DEC %f RAD %f X %d Y %d\n", idx, azimuth, declination, rad, x, y);
    lv_obj_set_pos(satData[idx].dot, xorig + x, yorig - y);
}

// Initialise the sky view for the nunber of satellites. Removes any old ones not needed
void initGNSSSky(uint32_t svs) {
    for (int i = svs; i < MAXSATS; i++) {
        if (satData[i].dot) {
            lv_obj_del(satData[i].dot);
            satData[i].dot = NULL;
        }
    }
}

// Init the signal display to the number of SVs
void initGNSSSignal(uint32_t svs) {
    for (int i = svs; i < MAXSATS; i++) {
        if (GNSSChartSeries->points[i]) {
            GNSSChartSeries->points[i] = 0;
            lv_chart_refresh(GNSSChart);
        }
    }
}