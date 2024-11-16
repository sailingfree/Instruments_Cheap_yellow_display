#pragma once
#include <Arduino.h>
#include <lvgl.h>
#include <N2kMessages.h>    // For the handy conversions

// Class for a lightweight meter
class Meter {
public:
    Meter(lv_obj_t* parent, const lv_image_dsc_t*,
        uint32_t w, uint32_t h,
        float minVal, float maxVal,
        float sweep, float off);
    void setPos(int x, int y);
    void setVal(float v);
    lv_obj_t* lvObj() { return container; }

private:
    lv_obj_t* container;
    lv_obj_t* imgObj;
    lv_obj_t* needle;
    uint32_t  width, height;
    float  min, max, sweep, offset;
    lv_point_precise_t  points[2];
    float  origx, origy;
};