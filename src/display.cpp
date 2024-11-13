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

static const uint32_t border = 1, padding = 0;

static void buttonHandler(lv_event_t* e);

lv_obj_t* screens[SCR_MAX];
static Indicator* ind[SCR_MAX][12];
static InfoBar* bars[SCR_MAX];
static lv_obj_t* gauges[SCR_MAX];
static lv_obj_t* needles[SCR_MAX];
static Meter* meters[SCR_MAX];

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

// simple meter 
Meter::Meter(lv_obj_t* parent, const lv_image_dsc_t* img, uint32_t w, uint32_t h, uint32_t min, uint32_t max, uint32_t start, uint32_t end) {
    Serial.printf("Creating Meter %d %d %d %d %d %d\n",
        w, h, min, max, start, end);
    width = w;
    height = h;
    static lv_style_t style;
    static lv_style_t needleStyle;
    lv_style_init(&style);
    container = lv_obj_create(parent);
    lv_obj_remove_flag(container, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_size(container, w, h);
    lv_style_set_pad_all(&style, 0);
    lv_obj_add_style(container, &style, 0);

    imgObj = lv_image_create(container);
    lv_img_set_src(imgObj, img);
    lv_obj_set_size(imgObj, w - 5, h - 5);
    needle = lv_line_create(imgObj);
    lv_style_init(&needleStyle);
    lv_style_set_line_width(&needleStyle, 8);
    lv_style_set_line_color(&needleStyle, lv_palette_main(LV_PALETTE_RED));
    lv_style_set_line_rounded(&needleStyle, true);
    lv_obj_add_style(needle, & needleStyle, 0);
    origx = width / 2;
    origy = height / 2;
}

void Meter::setVal(uint32_t v) {
    Serial.printf("Setting meter value %d\n");
    points[0].x = origx;
    points[0].y = origy;
    points[1].x = origx + 50;
    points[1].y = origy - 50;
    lv_line_set_points(needle, points, 2);
    Serial.printf("NEEDLE %d %d %d %d\n", points[0].x,
    points[0].y,
    points[1].x,
    points[1].y);
}


void Meter::setPos(int x, int y) {
    lv_obj_set_pos(container, x, y);
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
            //  refreshData(s);
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
    menuBar->addButton("GPS", SCR_GNSS);
    menuBar->addButton("Env", SCR_ENV);
    menuBar->addButton("Info", SCR_SYSINFO);
}

// create a container for a gauge or other display object
// setting styles etc
static lv_obj_t* createContainer(lv_obj_t* cont) {
    lv_obj_t* container = lv_obj_create(cont);
    return container;
}

lv_obj_t* createNavScreen() {
    lv_obj_t* screen = lv_obj_create(NULL);

    setupCommonstyles(screen);
    setupHeader(SCR_NAV, screen, "Nav");

    ind[SCR_NAV][NAV_SOG] = new Indicator(screen, "SOG", COL1, ROW1);
    ind[SCR_NAV][NAV_COG] = new Indicator(screen, "COG", COL1, ROW2);
    ind[SCR_NAV][DEPTH] = new Indicator(screen, "Depth", COL1, ROW3);

#if USE_SCALE
    // Create a container for a gauge for the Wind
    lv_obj_t* container = createContainer(screen);

    lv_obj_set_size(container, (TFT_WIDTH / 2) - 2 * padding, BODY_HEIGHT - 2 * padding);
    lv_obj_set_pos(container, COL2, ROW1);
    lv_obj_clear_flag(container, LV_OBJ_FLAG_SCROLLABLE);

    static lv_style_t style;
    lv_style_init(&style);

    // Scale for the wind direction
    lv_obj_t* scale = lv_scale_create(container);
    int32_t  width = MIN(TFT_WIDTH / 2, BODY_HEIGHT);
    int32_t  height = width;

    lv_obj_set_size(scale, width, height);
    lv_scale_set_mode(scale, LV_SCALE_MODE_ROUND_INNER);
    lv_obj_set_style_bg_opa(scale, LV_OPA_80, 0);
    lv_obj_set_style_bg_color(scale, lv_color_black(), 0);
    lv_obj_set_style_radius(scale, LV_RADIUS_CIRCLE, 0);
    lv_obj_set_style_clip_corner(scale, true, 0);
    lv_obj_center(scale);

    lv_scale_set_label_show(scale, true);

    lv_scale_set_total_tick_count(scale, 61);
    lv_scale_set_major_tick_every(scale, 5);


    lv_obj_set_style_length(scale, 5, LV_PART_ITEMS);
    lv_obj_set_style_length(scale, 10, LV_PART_INDICATOR);

    lv_scale_set_range(scale, 0, 360);
    lv_scale_set_angle_range(scale, 360);
    lv_scale_set_rotation(scale, 270);

    static lv_style_t indicator_style;
    lv_style_init(&indicator_style);

    /* Label style properties */
    lv_style_set_text_font(&indicator_style, &RobotoCondensedVariableFont_wght12);
    lv_style_set_text_color(&indicator_style, lv_palette_main(LV_PALETTE_YELLOW));

    /* Major tick properties */
    lv_style_set_line_color(&indicator_style, lv_palette_main(LV_PALETTE_YELLOW));
    lv_style_set_length(&indicator_style, 8); /* tick length */
    lv_style_set_line_width(&indicator_style, 2); /* tick width */
    lv_obj_add_style(scale, &indicator_style, LV_PART_INDICATOR);

    static const char* compass_ticks[] = {
                "", "30", "60", "90", "120", "150", "180", "210", "240", "270", "300", "330", "360" };
    lv_scale_set_text_src(scale, compass_ticks);

    static lv_style_t scale_style;
    lv_style_init(&scale_style);
    lv_style_set_line_width(&scale_style, 6);

    lv_obj_add_style(scale, &scale_style, LV_PART_ANY);
    lv_obj_t* needle = lv_line_create(scale);


    lv_obj_set_style_line_width(needle, 5, 0);
    lv_obj_set_style_line_rounded(needle, true, 0);
    lv_obj_set_style_line_color(needle, lv_palette_main(LV_PALETTE_RED), 0);

    // Label in the dial
    const char* lab = "App Wind";
    lv_obj_t* label = lv_label_create(scale);
    lv_label_set_text(label, lab);

    lv_obj_set_style_text_font(label, &RobotoCondensedVariableFont_wght12, 0);
    lv_obj_set_style_text_color(label, lv_palette_main(LV_PALETTE_YELLOW), 0);
    lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, 0);
    uint32_t w = lv_text_get_width(lab, strlen(lab), &RobotoCondensedVariableFont_wght12, 1);
    lv_obj_set_pos(label, TFT_WIDTH / 4 - (w / 2), TFT_HEIGHT / 3);

    // Save the scale line and image for updates
    gauges[SCR_NAV] = scale;
    needles[SCR_NAV] = needle;

    // set an initial value
    setGauge(SCR_NAV, 0.0);
#else

#endif
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
#if USE_SCALE
    // Create a container for a gauge
    lv_obj_t* container = createContainer(screen);
    lv_obj_set_size(container, (TFT_WIDTH / 2) - 2 * padding, BODY_HEIGHT - 2 * padding);
    lv_obj_set_pos(container, COL2, ROW1);
    lv_obj_clear_flag(container, LV_OBJ_FLAG_SCROLLABLE);

    // Meter for the RPM
    lv_obj_t* scale = lv_scale_create(container);
    int32_t  width = MIN(TFT_WIDTH / 2, BODY_HEIGHT);
    int32_t  height = width;

    lv_obj_set_size(scale, width, height);
    lv_scale_set_mode(scale, LV_SCALE_MODE_ROUND_INNER);
    lv_obj_set_style_bg_opa(scale, LV_OPA_80, 0);
    lv_obj_set_style_bg_color(scale, lv_color_black(), 0);
    lv_obj_set_style_radius(scale, LV_RADIUS_CIRCLE, 0);
    lv_obj_set_style_clip_corner(scale, true, 0);
    lv_obj_center(scale);

    static lv_style_t indicator_style;
    lv_style_init(&indicator_style);

    /* Label style properties */
    lv_style_set_text_font(&indicator_style, &RobotoCondensedVariableFont_wght24);
    lv_style_set_text_color(&indicator_style, lv_palette_main(LV_PALETTE_YELLOW));

    /* Major tick properties */
    lv_style_set_line_color(&indicator_style, lv_palette_main(LV_PALETTE_YELLOW));
    lv_style_set_length(&indicator_style, 8); /* tick length */
    lv_style_set_line_width(&indicator_style, 2); /* tick width */
    lv_obj_add_style(scale, &indicator_style, LV_PART_INDICATOR);

    static const char* rpm_ticks[] = { "0", "5", "10", "15", "20", "25", "30", "35" };
    lv_scale_set_text_src(scale, rpm_ticks);
    lv_scale_set_label_show(scale, true);
    lv_scale_set_total_tick_count(scale, 31);
    lv_scale_set_major_tick_every(scale, 5);

    lv_obj_set_style_length(scale, 5, LV_PART_ITEMS);
    lv_obj_set_style_length(scale, 10, LV_PART_INDICATOR);
    lv_scale_set_range(scale, 1, 3500);

    lv_scale_set_angle_range(scale, 270);
    lv_scale_set_rotation(scale, 135);

    static lv_style_t scale_style;
    lv_style_init(&scale_style);
    lv_style_set_line_width(&scale_style, 6);

    lv_obj_add_style(scale, &scale_style, LV_PART_ANY);

    lv_obj_t* needle = lv_image_create(scale);
    needle = lv_line_create(scale);
    lv_obj_set_style_line_width(needle, 5, 0);
    lv_obj_set_style_line_rounded(needle, true, 0);
    lv_obj_set_style_line_color(needle, lv_palette_main(LV_PALETTE_RED), 0);
    lv_scale_set_line_needle_value(scale, needle, 50, 10);

    // Label in the dial
    const char* lab = "RPM x100";
    lv_obj_t* label = lv_label_create(scale);
    lv_label_set_text(label, lab);

    lv_obj_set_style_text_font(label, &RobotoCondensedVariableFont_wght12, 0);
    lv_obj_set_style_text_color(label, lv_palette_main(LV_PALETTE_YELLOW), 0);
    lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, 0);
    uint32_t w = lv_text_get_width(lab, strlen(lab), &RobotoCondensedVariableFont_wght12, 1);
    lv_obj_set_pos(label, TFT_WIDTH / 4 - (w / 2), TFT_HEIGHT / 3);

    // Save the scale line and image for updates
    gauges[SCR_ENGINE] = scale;
    needles[SCR_ENGINE] = needle;
    setGauge(SCR_ENGINE, 0.0);
#else 
    LV_IMG_DECLARE(rpm);
    uint32_t w = MIN(TFT_WIDTH / 2, BODY_HEIGHT);
    uint32_t h = w;
    meters[SCR_ENGINE] = new Meter(screen, &rpm, w, h, 0, 30, 180 + 45, 90 + 45);
    meters[SCR_ENGINE]->setPos(TFT_WIDTH / 2, BAR_HEIGHT);
    meters[SCR_ENGINE]->setVal(1000);
#endif
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
    ind[SCR_ENV][SEATEMP] = new Indicator(screen, "Air Temp", COL2, ROW1);
    ind[SCR_ENV][WINDSP] = new Indicator(screen, "Humidity", COL2, ROW2);
    ind[SCR_ENV][WINDANGLE] = new Indicator(screen, "Pressure", COL2, ROW3);


    setupMenu(screen);
    return screen;

}

lv_obj_t* createGnssScreen() {
    lv_obj_t* screen = lv_obj_create(NULL);

    setupCommonstyles(screen);
    setupHeader(SCR_GNSS, screen, "GPS");

    ind[SCR_GNSS][GNSS_HDOP] = new Indicator(screen, "HDOP", COL1, ROW1);
    ind[SCR_GNSS][GNSS_SATS] = new Indicator(screen, "Sats", COL2, ROW1);
    ind[SCR_GNSS][GNSS_LAT] = new Indicator(screen, "LAT", COL1, ROW2);
    ind[SCR_GNSS][GNSS_LON] = new Indicator(screen, "LON", COL2, ROW2);
    ind[SCR_GNSS][GNSS_SOG] = new Indicator(screen, "SOG Kts", COL1, ROW3);
    ind[SCR_GNSS][GNSS_COG] = new Indicator(screen, "COG deg", COL2, ROW3);

    setupMenu(screen);
    return screen;
}


lv_obj_t* createSysInfoScreen() {
    lv_obj_t* screen = lv_obj_create(NULL);
    setupCommonstyles(screen);
    setupHeader(SCR_SYSINFO, screen, "System");

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
    screens[SCR_GNSS] = createGnssScreen();
    screens[SCR_ENV] = createEnvScreen();
    screens[SCR_SYSINFO] = createSysInfoScreen();

    lv_scr_load(screens[SCR_ENGINE]);
}

// Update a value using double and optional units
void display_write(MeterIdx obj, double value, const char* units, uint32_t prec) {
    ind[SCR_GNSS][obj]->setValue(value, units, prec);
}

// Update using a pre-formatted char *
void display_write(MeterIdx obj, const char* value) {
    ind[SCR_GNSS][obj]->setValue(value);
}

// Upadte the time on the screen
void updateTime(StringStream t) {
    bars[SCR_GNSS]->setTime(t.data.c_str());
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
    if (scr >= 0 && scr < SCR_MAX && gauges[scr] && needles[scr]) {
        lv_scale_set_line_needle_value(gauges[scr], needles[scr], TFT_WIDTH, (int32_t)value);
        metersWork();
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

    if (now > last) {
        last = now;
        snprintf(buf, 9, "%02d:%02d:%02d", tm.tm_hour, tm.tm_min, tm.tm_sec);
        setMeter(SCR_GNSS, GNSS_TIME, buf);
        bars[SCR_ENGINE]->setTime(buf);
        bars[SCR_NAV]->setTime(buf);
        bars[SCR_GNSS]->setTime(buf);
        bars[SCR_ENV]->setTime(buf);
        bars[SCR_SYSINFO]->setTime(buf);
    }
}
