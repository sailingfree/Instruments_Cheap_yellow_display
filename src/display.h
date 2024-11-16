// Display handler
#pragma once 

#include <Arduino.h>
#include <lvgl.h>
#include <StringStream.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

#define HEIGH_IND   (TFT_HEIGHT/4)
#define HEIGHT_INFO (TFT_HEIGHT/8)

// Define the positions of elements on the screen.
// The elements are laid out in a grid with a header and footer
#define BAR_HEIGHT      (TFT_HEIGHT / 8)
#define BAR_MENU_HEIGHT (TFT_HEIGHT / 6) 
#define BAR_WIDTH       (TFT_WIDTH)
#define BAR_ROW_TOP     (0)
#define BAR_ROW_BOTTOM  (TFT_HEIGHT - BAR_MENU_HEIGHT)
#define BODY_HEIGHT     (TFT_HEIGHT - BAR_HEIGHT - BAR_MENU_HEIGHT)
#define IND_HEIGHT      (BODY_HEIGHT / 3)
#define IND_WIDTH       (TFT_WIDTH / 2)
#define ROW1            (BAR_HEIGHT)
#define ROW2            (ROW1 + IND_HEIGHT)
#define ROW3            (ROW2 + IND_HEIGHT)
#define COL1            (0)
#define COL2            (TFT_WIDTH / 2)

class Txt {
public:
    uint16_t x;
    uint16_t y;
    uint16_t w;
    uint16_t h;
};

// Define the screens. This is the ordfer they are in at startup
typedef enum {
    SCR_BOOT,
    SCR_ENGINE,
    SCR_NAV,
    SCR_GNSS,
    SCR_ENV,
    SCR_NETWORK,
    SCR_SYSINFO,
    SCR_MSGS,
    SCR_MAX
} Screens;

// Indicator indexes
typedef enum {
    HOUSEV = 0,
    HOUSEI = 1,
    ENGINEV = 2,

    // Indexes for the nav info screen
    NAV_SOG = 0,
    DEPTH = 1,
    NAV_COG = 2,

    // Indexes for the GNSS screen
    GNSS_SATS = 0,
    GNSS_HDOP = 1,
    GNSS_TIME = 2,
    GNSS_LAT,
    GNSS_LON,
    GNSS_SOG,
    GNSS_COG,

    // Environmental
    AIRTEMP = 0,
    HUM = 1,
    PRESSURE = 2,
    SEATEMP = 3,
    WINDSP = 4,
    WINDANGLE = 5,
} MeterIdx;


// screen menu buttons
typedef enum {
    BTN_GPS,
    BTN_SKY,
    BTN_INFO1,
    BTN_MAX
}BTN;


// This class implements a rectangle container which has a main display for
// eg voltage, a smaller header. It is designed to work with the lvgl library
// on an ESP32 or similar.
// It has a fixed size.
class Indicator {
public:
    // Constructor:
    Indicator(lv_obj_t* parent, const char* label, uint32_t x, uint32_t y);
    void setValue(const char* value);

    // Set the value of a meter using a double and set the precision
    void setValue(double value, const char* units, uint32_t prec);

    //Change the main indicator font
    void setFont(const lv_font_t* value);

    // private:
    lv_obj_t* container;
    lv_obj_t* label;
    lv_obj_t* text;

    lv_style_t text_style;
    lv_style_t value_style;
    lv_style_t style;

    // The interval used for moving averages
    static const int interval = 4;
};

// Class to implement a full width info text area. 
class InfoBar {
public:
    InfoBar(lv_obj_t* parent, uint32_t y);
    void setValue(const char* value);
    void setTime(const char* t);

    bool isActive;

    lv_obj_t* container;
    lv_obj_t* text;
    lv_obj_t* curTime;
};


class MenuBar {
public:
    MenuBar(lv_obj_t* parent, uint32_t y);

    void addButton(const char* label, Screens target);
    lv_obj_t* addActionButton(const char* label, void (*ptr)(lv_event_t*));
    lv_obj_t* container;
};

typedef struct Buttons {
    BTN btn;
    Screens target;
    const char* label;
}Buttons;



void setup_display();
void display_write(MeterIdx obj, double value, const char* units, uint32_t precision);
void display_write(MeterIdx obj, const char* value);
void updateTime(StringStream t);
void metersWork(void);
void setMeter(Screens scr, MeterIdx ind, double, const char*, uint32_t prec = 2);
void setMeter(Screens scr, MeterIdx ind, const char*);
void setMeter(Screens scr, MeterIdx ind, String& val);
void setGauge(Screens scr, double);
void setVlabel(Screens, String&);
void setilabel(Screens scr, String&);
void loadScreen();
void displayText(const char*);
// Time display update
void updateTime();
