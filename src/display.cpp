// Display information on the screen

#include <display.h>
#include <cyd_pins.h>
#include <lvgl.h>
#include <esp32_smartdisplay.h>
#include <myFonts.h>
#include <StringStream.h>
#include <N2kMessages.h>
#include <NMEA0183Messages.h>
#include <N2kMsg.h>
#include <map>
#include <Meter.h>
#include <SysInfo.h>
#include <sensors.h>

static const uint32_t border = 1, padding = 0;

static void buttonHandler(lv_event_t* e);

// Pointers to the screens and their components.
// Will all be NULL at initialisation
lv_obj_t* screens[SCR_MAX];
static Indicator* ind[SCR_MAX][12];
static InfoBar* bars[SCR_MAX];
static Meter* meters[SCR_MAX];
// define the text areas
static lv_obj_t* textAreas[SCR_MAX];

// Constructor. Binds to the parent object.
Indicator::Indicator(lv_obj_t* parent, const char* name, uint32_t x, uint32_t y) {
    container = lv_obj_create(parent);
    lv_obj_set_pos(container, x, y);
    lv_obj_set_width(container, IND_WIDTH - (2 * padding));
    lv_obj_set_height(container, IND_HEIGHT - (2 * padding));

    lv_style_init(&style);
    lv_style_set_border_width(&style, border);
    lv_obj_add_style(container, &style, 0);

    lv_obj_set_layout(container, LV_LAYOUT_FLEX);
    lv_obj_set_flex_flow(container, LV_FLEX_FLOW_COLUMN);
    lv_obj_clear_flag(container, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_pad_gap(container, 0, 0);

    label = lv_label_create(container);
    lv_label_set_text(label, name);
    lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, 0);

    lv_style_init(&text_style);
    lv_style_set_text_font(&text_style, &RobotoCondensedVariableFont_wght16);
    lv_obj_add_style(label, &text_style, 0);

    text = lv_label_create(container);
    lv_style_init(&value_style);
    lv_style_set_text_font(&value_style, &RobotoCondensedVariableFont_wght32);
    lv_obj_add_style(text, &value_style, 0);
    lv_obj_set_style_text_align(text, LV_TEXT_ALIGN_CENTER, 0);

    lv_label_set_text(text, "---");
}

// Change the text size
void Indicator::setFont(const lv_font_t* value) {
    lv_style_set_text_font(&value_style, value);
}

// set the value using a double and precision.
void Indicator::setValue(double value, const char* units, uint32_t prec) {
    String v(value, prec);
    v += units;
    setValue(v.c_str());
}

void Indicator::setValue(const char* value) {
    lv_label_set_text(text, value);
}

// Constructor. Binds to the parent object.
// Info bar has the screen title and the time
InfoBar::InfoBar(lv_obj_t* parent, uint32_t y) {
    static lv_style_t style;
    static lv_style_t value_style;

    container = lv_obj_create(parent);
    lv_obj_set_pos(container, 0, y);
    lv_obj_set_width(container, (BAR_WIDTH)-(2 * padding));
    lv_obj_set_height(container, (BAR_HEIGHT)-2 * padding);
    lv_obj_clear_flag(container, LV_OBJ_FLAG_SCROLLABLE);

    lv_style_init(&style);
    lv_style_set_border_width(&style, border);

    lv_style_set_radius(&style, 3);

    lv_style_set_bg_opa(&style, LV_OPA_100);
    lv_style_set_bg_color(&style, lv_palette_main(LV_PALETTE_BLUE));

    lv_obj_add_style(container, &style, 0);

    //    lv_obj_set_layout(container, LV_LAYOUT_FLEX);
    //    lv_obj_set_flex_flow(container, LV_FLEX_FLOW_ROW);

    // Title text
    text = lv_label_create(container);
    lv_style_init(&value_style);
    lv_style_set_bg_opa(&value_style, LV_OPA_100);
    lv_style_set_bg_color(&value_style, lv_palette_main(LV_PALETTE_BLUE));
    lv_style_set_text_color(&value_style, lv_color_white());
    lv_style_set_pad_all(&value_style, 10);
    lv_style_set_text_font(&value_style, &RobotoCondensedVariableFont_wght24);
    lv_obj_add_style(text, &value_style, 0);
    lv_obj_set_align(text, LV_ALIGN_LEFT_MID);

    curTime = lv_label_create(container);
    lv_obj_add_style(curTime, &value_style, 0);
    lv_label_set_text(curTime, "00:00:00");
    lv_obj_set_align(curTime, LV_ALIGN_RIGHT_MID);
}

MenuBar::MenuBar(lv_obj_t* parent, uint32_t y) {
    // Constructor. Binds to the parent object.
    static lv_style_t style;

    container = lv_obj_create(parent);
    lv_obj_set_pos(container, 0, y);
    lv_obj_set_width(container, (BAR_WIDTH)-2 * padding);
    lv_obj_set_height(container, BAR_MENU_HEIGHT);
    lv_obj_clear_flag(container, LV_OBJ_FLAG_SCROLLABLE);

    lv_style_init(&style);
    lv_style_set_border_width(&style, border);
    lv_style_set_pad_all(&style, 0);
    lv_obj_add_style(container, &style, 0);

    lv_obj_set_layout(container, LV_LAYOUT_FLEX);
    lv_obj_set_flex_flow(container, LV_FLEX_FLOW_ROW);
}


static void buttonHandler(lv_event_t* e) {
    void* target = lv_event_get_user_data(e);
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
    Screens s = reinterpret_cast<Screens&>(target);
#pragma GCC diagnostic pop
    lv_event_code_t code = lv_event_get_code(e);

    if (code == LV_EVENT_PRESSED) {
        if (s >= 0 && s < SCR_MAX && screens[s]) {
            refreshSysinfo();
            lv_scr_load(screens[s]);
        }
    }
}

// Add a button to a menu bar. The callbackl will change the screen to the target
void MenuBar::addButton(const char* label, Screens target) {
    lv_obj_t* b = lv_button_create(container);
    lv_obj_t* l = lv_label_create(b);
    lv_obj_set_height(b, BAR_MENU_HEIGHT);
    lv_label_set_text(l, label);
    lv_obj_set_flex_grow(b, 1);
    /*Init the style for the default state*/
    static lv_style_t style;
    lv_style_init(&style);

    lv_style_set_radius(&style, 3);

    lv_style_set_bg_opa(&style, LV_OPA_100);
    lv_style_set_bg_color(&style, lv_palette_main(LV_PALETTE_BLUE));
    //    lv_style_set_bg_grad_color(&style, lv_palette_darken(LV_PALETTE_BLUE, 2));
    //   lv_style_set_bg_grad_dir(&style, LV_GRAD_);

    lv_style_set_border_opa(&style, LV_OPA_40);
    lv_style_set_border_width(&style, 2);
    lv_style_set_border_color(&style, lv_palette_main(LV_PALETTE_GREY));

    //    lv_style_set_shadow_width(&style, 8);
    //    lv_style_set_shadow_color(&style, lv_palette_main(LV_PALETTE_GREY));
    //    lv_style_set_shadow_offset_y(&style, 8);

    lv_style_set_outline_opa(&style, LV_OPA_COVER);
    lv_style_set_outline_color(&style, lv_palette_main(LV_PALETTE_BLUE));

    lv_style_set_text_color(&style, lv_color_white());
    lv_style_set_text_font(&style, &RobotoCondensedVariableFont_wght32);
    //    lv_style_set_pad_all(&style, 10);
    //    lv_obj_remove_style_all(b);
    lv_obj_add_style(b, &style, 0);
    lv_event_code_t code = LV_EVENT_PRESSED;
    //,             /**< The object has been pressed*/
    // LV_EVENT_PRESSING,            /**< The object is being pressed (called continuously while pressing)*/
    // LV_EVENT_PRESS_LOST,          /**< The object is still being pressed but slid cursor/finger off of the object */
    // LV_EVENT_SHORT_CLICKED,       /**< The object was pressed for a short period of time, then released it. Not called if scrolled.*/
    // LV_EVENT_LONG_PRESSED,        /**< Object has been pressed for at least `long_press_time`.  Not called if scrolled.*/
    // LV_EVENT_LONG_PRESSED_REPEAT, /**< Called after `long_press_time` in every `long_press_repeat_time` ms.  Not called if scrolled.*/
    // LV_EVENT_CLICKED,             /**< Called on release if not scrolled (regardless to long press)*/
    // LV_EVENT_RELEASED,
    lv_obj_add_event_cb(b, buttonHandler, code, (void*)target);
}

// Add a button to a menu bar. The callback will change the screen to the target
// returns a pointer to the label object
lv_obj_t* MenuBar::addActionButton(const char* label, void (*ptr)(lv_event_t* e)) {
    lv_obj_t* b = lv_button_create(container);
    lv_obj_t* l = lv_label_create(b);
    lv_label_set_text(l, label);
    lv_obj_set_flex_grow(b, 1);
    /*Init the style for the default state*/
    static lv_style_t style;
    lv_style_init(&style);

    lv_style_set_radius(&style, 3);

    lv_style_set_bg_opa(&style, LV_OPA_100);
    lv_style_set_bg_color(&style, lv_palette_main(LV_PALETTE_BLUE));
    lv_style_set_bg_grad_color(&style, lv_palette_darken(LV_PALETTE_BLUE, 2));
    lv_style_set_bg_grad_dir(&style, LV_GRAD_DIR_VER);

    lv_style_set_border_opa(&style, LV_OPA_40);
    lv_style_set_border_width(&style, 2);
    lv_style_set_border_color(&style, lv_palette_main(LV_PALETTE_GREY));

    lv_style_set_shadow_width(&style, 8);
    lv_style_set_shadow_color(&style, lv_palette_main(LV_PALETTE_GREY));
    lv_style_set_shadow_offset_y(&style, 8);

    lv_style_set_outline_opa(&style, LV_OPA_COVER);
    lv_style_set_outline_color(&style, lv_palette_main(LV_PALETTE_BLUE));

    lv_style_set_text_color(&style, lv_color_white());
    lv_style_set_pad_all(&style, 10);
    //    lv_obj_remove_style_all(b);
    lv_obj_add_style(b, &style, 0);
    lv_obj_add_event_cb(b, ptr, LV_EVENT_CLICKED, NULL);

    return l;
}

void InfoBar::setValue(const char* value) {
    lv_label_set_text(text, value);
}

void InfoBar::setTime(const char* t) {
    lv_label_set_text(curTime, t);
}

static void setupCommonstyles(lv_obj_t* obj) {
    lv_obj_set_style_pad_gap(obj, padding, 0);

    lv_obj_set_height(obj, BODY_HEIGHT);
    lv_obj_set_width(obj, TFT_WIDTH);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
}

static void setupHeader(Screens scr, lv_obj_t* screen, const char* title) {
    // Info bar at the tope
    InfoBar* bar = new InfoBar(screen, BAR_ROW_TOP);
    bars[scr] = bar;
    bar->setValue(title);
}

static void setupMenu(lv_obj_t* screen) {
    MenuBar* menuBar = new MenuBar(screen, BAR_ROW_BOTTOM);
    menuBar->addButton("Eng", SCR_ENGINE);
    menuBar->addButton("Nav", SCR_NAV);
    menuBar->addButton("Time", SCR_THERMOMETER);
    menuBar->addButton("Env", SCR_ENV);
    menuBar->addButton("Info", SCR_SYSINFO);
}

lv_obj_t* createNavScreen() {
    lv_obj_t* screen = lv_obj_create(NULL);

    setupCommonstyles(screen);
    setupHeader(SCR_NAV, screen, "Nav");

    ind[SCR_NAV][NAV_SOG] = new Indicator(screen, "SOG", COL1, ROW1);
    ind[SCR_NAV][NAV_COG] = new Indicator(screen, "COG", COL1, ROW2);
    ind[SCR_NAV][DEPTH] = new Indicator(screen, "Depth", COL1, ROW3);

    LV_IMG_DECLARE(wind);
    uint32_t w = MIN(TFT_WIDTH / 2, BODY_HEIGHT);
    uint32_t h = w;
    meters[SCR_NAV] = new Meter(screen, &wind, w, h, 0.0, 359, 360, 0.0);
    meters[SCR_NAV]->setPos(TFT_WIDTH / 2, BAR_HEIGHT);
    meters[SCR_NAV]->setVal(45);

    setupMenu(screen);
    return screen;

}

lv_obj_t* createEngineScreen() {
    lv_obj_t* screen = lv_obj_create(NULL);

    setupCommonstyles(screen);
    setupHeader(SCR_ENGINE, screen, "Engine");

    ind[SCR_ENGINE][HOUSEV] = new Indicator(screen, "HouseV", COL1, ROW1);
    ind[SCR_ENGINE][HOUSEI] = new Indicator(screen, "HouseI", COL1, ROW2);
    ind[SCR_ENGINE][ENGINEV] = new Indicator(screen, "EngineV", COL1, ROW3);

    LV_IMG_DECLARE(rpm);
    uint32_t w = MIN(TFT_WIDTH / 2, BODY_HEIGHT);
    uint32_t h = w;
    meters[SCR_ENGINE] =
        new Meter(screen, &rpm, w, h, 0.0, 30.0, 270.0, -135.0);
    meters[SCR_ENGINE]->setPos(TFT_WIDTH / 2, BAR_HEIGHT);
    meters[SCR_ENGINE]->setVal(0);

    setupMenu(screen);
    return screen;

}

lv_obj_t* createEnvScreen() {
    lv_obj_t* screen = lv_obj_create(NULL);

    setupCommonstyles(screen);
    setupHeader(SCR_ENV, screen, "Environment");

    ind[SCR_ENV][AIRTEMP] = new Indicator(screen, "Air Temp", COL1, ROW1);
    ind[SCR_ENV][HUM] = new Indicator(screen, "Humidity", COL1, ROW2);
    ind[SCR_ENV][PRESSURE] = new Indicator(screen, "Pressure", COL1, ROW3);
    ind[SCR_ENV][SEATEMP] = new Indicator(screen, "Sea Temp", COL2, ROW1);
    ind[SCR_ENV][WINDSP] = new Indicator(screen, "Wind Speed", COL2, ROW2);
    ind[SCR_ENV][WINDANGLE] = new Indicator(screen, "Apparent Wind", COL2, ROW3);

    setupMenu(screen);
    return screen;

}

lv_obj_t* createSysInfoScreen() {
    lv_obj_t* screen = lv_obj_create(NULL);
    setupCommonstyles(screen);
    setupHeader(SCR_SYSINFO, screen, "System");

    // Create a text area to display the info text
    textAreas[SCR_SYSINFO] = lv_textarea_create(screen);
    lv_obj_set_size(textAreas[SCR_SYSINFO], TFT_WIDTH, BODY_HEIGHT);
    lv_obj_align(textAreas[SCR_SYSINFO], LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_text_font(textAreas[SCR_SYSINFO], &UbuntuMonoB16,
                               LV_PART_MAIN | LV_STATE_DEFAULT);

    setupMenu(screen);
    return screen;
}

// some code from
// https://randomnerdtutorials.com/esp32-cyd-lvgl-temperature-ds18b20/
//lv_obj_t *arc;
lv_obj_t *tempTextF;
lv_obj_t *tempTextC;
lv_obj_t *timeText;
lv_obj_t *dateText;

// Set the temperature value in the arc and text label
static void set_temp(void *text_label_temp_value, int32_t v) {

// Get the latest temperature reading in Celsius or Fahrenheit
    float ds18b20_tempC = getTempC();
    float ds18b20_tempF = getTempF();
    const char degree_symbol[] = "\u00B0";

    String ds18b20_temp_textC = String(ds18b20_tempC, 0) + degree_symbol + "C";
    String ds18b20_temp_textF = String(ds18b20_tempF, 0) + degree_symbol + "F";
    String tempText = ds18b20_temp_textC + " " + ds18b20_temp_textF;
    lv_label_set_text(tempTextC, ds18b20_temp_textC.c_str());
    lv_label_set_text(tempTextF, ds18b20_temp_textF.c_str());

    struct tm tm;
    char buf[32];
    time_t now = time(NULL);
    gmtime_r(&now, &tm);

    snprintf(buf, 9, "%02d:%02d:%02d", tm.tm_hour, tm.tm_min, tm.tm_sec);
    lv_label_set_text(timeText, buf);

    strftime(buf, sizeof(buf) - 1, "%a %d %b %y", &tm);
    lv_label_set_text(dateText, buf);
}


lv_obj_t *createThermometer() {
    lv_obj_t *screen = lv_obj_create(NULL);

    // add a background image
    LV_IMAGE_DECLARE(dawlish);
    lv_obj_t * img1 = lv_image_create(screen);
    lv_image_set_src(img1, &dawlish);
    lv_obj_align(img1, LV_ALIGN_CENTER, 0, 0);

    setupCommonstyles(screen);
    setupHeader(SCR_SYSINFO, screen, "Temperature");



    tempTextC = lv_label_create(screen);
    lv_label_set_text(tempTextC, "--.--");
    lv_obj_align(tempTextC, LV_ALIGN_TOP_LEFT, 0, ROW1);
    static lv_style_t style_tempC;
    lv_style_init(&style_tempC);
    lv_style_set_text_font(&style_tempC, &RobotoCondensedVariableFont_wght52);
    lv_obj_add_style(tempTextC, &style_tempC, 0);

    // second label for farenheight
    tempTextF = lv_label_create(screen);
    static lv_style_t style_tempF;

    lv_style_init(&style_tempF);
    lv_style_set_text_font(&style_tempF, &RobotoCondensedVariableFont_wght52);
    lv_label_set_text(tempTextF, "--.--");
    lv_obj_align(tempTextF, LV_ALIGN_TOP_RIGHT, 0, ROW1);
    lv_obj_add_style(tempTextF, &style_tempF, 0);

    // Time
    timeText = lv_label_create(screen);
    static lv_style_t style_time;
    lv_label_set_text(timeText, "00:00:00");
    lv_style_init(&style_time);
    lv_style_set_text_font(&style_time, &RobotoCondensedVariableFont_wght64);
    lv_obj_align(timeText, LV_ALIGN_TOP_MID, 0, ROW2);
    lv_obj_add_style(timeText, &style_time, 0);

    // date
    dateText = lv_label_create(screen);
    static lv_style_t style_date;
    lv_label_set_text(dateText, "xx-xx-xx");
    lv_style_init(&style_date);
    lv_style_set_text_font(&style_date, &RobotoCondensedVariableFont_wght42);
    lv_obj_align(dateText, LV_ALIGN_TOP_MID, 0, ROW3);
    lv_obj_add_style(dateText, &style_date, 0);


    // Create an animation to update with the latest temperature value every 10
    // seconds
    lv_anim_t a_temp;
    lv_anim_init(&a_temp);
    lv_anim_set_exec_cb(&a_temp, set_temp);
    lv_anim_set_duration(&a_temp, 100000);
    lv_anim_set_playback_duration(&a_temp, 100000);
    lv_anim_set_repeat_count(&a_temp, LV_ANIM_REPEAT_INFINITE);
    lv_anim_start(&a_temp);

    
    setupMenu(screen);
    return screen;
}

void setup_display() {
    smartdisplay_init();
    smartdisplay_lcd_set_backlight(1.0f);
    lv_display_set_rotation(NULL, LV_DISPLAY_ROTATION_90);

    lv_theme_t* theme = NULL;

    lv_disp_t* dispp = lv_disp_get_default();
    theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
        false, &RobotoCondensedVariableFont_wght24);

    // theme = lv_theme_mono_init(dispp, false, &lv_font_montserrat_24);
    theme = lv_theme_mono_init(dispp, false, &RobotoCondensedVariableFont_wght32);

    if (theme) {
        lv_disp_set_theme(dispp, theme);
    }
    // Create the screens
    screens[SCR_ENGINE] = createEngineScreen();
    screens[SCR_NAV] = createNavScreen();
    screens[SCR_ENV] = createEnvScreen();
    screens[SCR_SYSINFO] = createSysInfoScreen();
    screens[SCR_THERMOMETER] = createThermometer();

    lv_scr_load(screens[SCR_THERMOMETER]);

    // Refresh the screen so it shows at boot up
    metersWork();
}

// Update the meters. Called regularly from the main loop/task
void metersWork(void) {
    static const uint32_t tick_delay = 50;
    lv_task_handler(); /* let the GUI do its work */
    lv_tick_inc(tick_delay);
    delay(tick_delay);
}

// Set the value of a meter using a double and precision of 2
void setMeter(Screens scr, MeterIdx idx, double value, const char* units) {
    setMeter(scr, idx, value, units, 2);
}

// Set the value of a meter using a double and set the precision
// Uses the indicator's method which smooths the values
void setMeter(Screens scr, MeterIdx idx, double value, const char* units, uint32_t prec) {
    if (scr >= 0 && scr < SCR_MAX && ind[scr][idx]) {
        ind[scr][idx]->setValue(value, units, prec);
    }
}

void setGauge(Screens scr, double value) {
    if (scr >= 0 && scr < SCR_MAX && meters[scr]) {
        meters[scr]->setVal(value);
    }
}

// Set the value of a meter using a string
void setMeter(Screens scr, MeterIdx idx, String& string) {
    if (scr >= 0 && scr < SCR_MAX && ind[scr][idx]) {
        ind[scr][idx]->setValue(string.c_str());
    }
}

// set using a char *
void setMeter(Screens scr, MeterIdx idx, const char* str) {
    if (scr >= 0 && scr < SCR_MAX && ind[scr][idx]) {
        ind[scr][idx]->setValue(str);
    }
}

// Refresh the info in the sysinfo page
void refreshSysinfo() {
    StringStream s;
    s.clear();
    getSysInfo(s);
    getNetInfo(s);
    lv_textarea_set_text(textAreas[SCR_SYSINFO], s.data.c_str());
}

// Update the time displayed on the screen.
// Uses the internal system time which will have been updated
// Only update if the seconds have changed
void updateTime() {
    static time_t last = 0;
    struct tm tm;
    char buf[10];
    time_t now = time(NULL);
    gmtime_r(&now, &tm);

    if (now > last) {
        last = now;
        snprintf(buf, 9, "%02d:%02d:%02d", tm.tm_hour, tm.tm_min, tm.tm_sec);
        bars[SCR_ENGINE]->setTime(buf);
        bars[SCR_NAV]->setTime(buf);
        bars[SCR_ENV]->setTime(buf);
        bars[SCR_SYSINFO]->setTime(buf);
    }
}
