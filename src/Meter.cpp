#include <Arduino.h>
#include <lvgl.h>
#include <Meter.h>

// simple meter 
// w and h = width and height of the meter
// min and max is the minimum and maximum values of the meter
// start and end are the angle in degrees of the meter
// offset is the angle of the start 
// all anges relative to the top centre.
Meter::Meter(lv_obj_t* parent, const lv_image_dsc_t* img, 
            uint32_t w, uint32_t h, 
            float minVal, float maxVal, 
            float sw, float off) {
    width = w;
    height = h;
    min = minVal;
    max = maxVal;
    offset = off;
    sweep = sw;    // Assume end > start
    Serial.printf("Creating Meter %ld %ld %f %f %f %f\n",
        w, h, min, max, sweep, offset);

    static lv_style_t style;
    static lv_style_t needleStyle;
    lv_style_init(&style);
    container = lv_obj_create(parent);
    lv_obj_remove_flag(container, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_size(container, width, height);
    lv_style_set_pad_all(&style, 0);
    lv_obj_add_style(container, &style, 0);

    imgObj = lv_image_create(container);
    lv_img_set_src(imgObj, img);
    lv_obj_set_size(imgObj, width - 5, height - 5);
    needle = lv_line_create(imgObj);
    lv_style_init(&needleStyle);
    lv_style_set_line_width(&needleStyle, 8);
    lv_style_set_line_color(&needleStyle, lv_palette_main(LV_PALETTE_RED));
    lv_style_set_line_rounded(&needleStyle, true);
    lv_obj_add_style(needle, & needleStyle, 0);
    origx = width / 2;
    origy = height / 2;
}

void Meter::setVal(float val) {
    double theta;
    uint32_t radius = (width / 2) - 15;

    theta = (val / max * DegToRad(sweep)) + DegToRad(offset);
    points[0].x = origx;
    points[0].y = origy;

    points[1].x = origx + (sin(theta) * radius);
    points[1].y = origy - (cos(theta) * radius);
    lv_line_set_points(needle, points, 2);

}


void Meter::setPos(int x, int y) {
    lv_obj_set_pos(container, x, y);
}

