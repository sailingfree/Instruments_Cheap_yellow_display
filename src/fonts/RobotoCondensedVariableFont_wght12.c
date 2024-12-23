/*******************************************************************************
 * Size: 12 px
 * Bpp: 2
 * Opts: --bpp 2 --size 12 --no-compress --font RobotoCondensed-VariableFont_wght.ttf --range 32-127 --format lvgl -o RobotoCondensedVariableFont_wght12.c
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef ROBOTOCONDENSEDVARIABLEFONT_WGHT12
#define ROBOTOCONDENSEDVARIABLEFONT_WGHT12 1
#endif

#if ROBOTOCONDENSEDVARIABLEFONT_WGHT12

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */

    /* U+0021 "!" */
    0x30, 0xc3, 0xc, 0x30, 0xc2, 0x0, 0x30,

    /* U+0022 "\"" */
    0x28, 0x28, 0x18, 0x0,

    /* U+0023 "#" */
    0x2, 0x20, 0x15, 0x43, 0xff, 0x2, 0x20, 0xc,
    0xc0, 0xff, 0xc0, 0x88, 0x6, 0x60, 0x15, 0x40,

    /* U+0024 "$" */
    0x6, 0x0, 0x60, 0x1f, 0x43, 0x4c, 0x30, 0x83,
    0x40, 0xb, 0x0, 0x1c, 0x20, 0xc3, 0xc, 0x1f,
    0x40, 0x50, 0x0, 0x0,

    /* U+0025 "%" */
    0x2c, 0x0, 0x52, 0x20, 0x52, 0x50, 0x28, 0x80,
    0x2, 0x0, 0x2, 0x74, 0x8, 0xcc, 0x8, 0xc8,
    0x0, 0x78,

    /* U+0026 "&" */
    0xf, 0x0, 0x96, 0x3, 0x58, 0x7, 0xc0, 0x1e,
    0x10, 0xdc, 0xc6, 0x1e, 0xc, 0x38, 0x1f, 0xb0,

    /* U+0027 "'" */
    0x55, 0x50,

    /* U+0028 "(" */
    0x0, 0x9, 0x8, 0x24, 0x30, 0x30, 0x30, 0x30,
    0x30, 0x30, 0x30, 0x14, 0xc, 0x5,

    /* U+0029 ")" */
    0x2, 0x43, 0x9, 0x18, 0x30, 0xc3, 0xc, 0x31,
    0x88, 0x21, 0x0,

    /* U+002A "*" */
    0xc, 0x13, 0x17, 0xf8, 0x74, 0x33, 0x0, 0x0,

    /* U+002B "+" */
    0x5, 0x0, 0xa0, 0xa, 0x7, 0xfd, 0xa, 0x0,
    0xa0, 0xa, 0x0, 0x0,

    /* U+002C "," */
    0x76, 0x90,

    /* U+002D "-" */
    0xb8,

    /* U+002E "." */
    0x10, 0xc0,

    /* U+002F "/" */
    0x3, 0x1, 0x80, 0x90, 0x30, 0x8, 0x5, 0x3,
    0x0, 0xc0, 0x60, 0x20, 0x0,

    /* U+0030 "0" */
    0x1f, 0x43, 0xc, 0x30, 0xc6, 0xc, 0x60, 0xd6,
    0xc, 0x30, 0xc3, 0x1c, 0x1f, 0x40,

    /* U+0031 "1" */
    0x6, 0x3b, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7,
    0x7,

    /* U+0032 "2" */
    0x1f, 0x43, 0x1c, 0x50, 0xc0, 0xc, 0x2, 0x40,
    0x70, 0xc, 0x3, 0x40, 0x7f, 0xd0,

    /* U+0033 "3" */
    0x1f, 0x43, 0x1c, 0x10, 0xc0, 0x1c, 0xf, 0x40,
    0x1c, 0x10, 0xc3, 0xc, 0x2f, 0x40,

    /* U+0034 "4" */
    0x3, 0xc0, 0x38, 0xa, 0x80, 0x98, 0x21, 0x82,
    0x18, 0xbf, 0xe0, 0x18, 0x1, 0x80,

    /* U+0035 "5" */
    0x2f, 0xc2, 0x40, 0x20, 0x3, 0xf4, 0x15, 0xc0,
    0x9, 0x10, 0x93, 0xc, 0x1f, 0x40,

    /* U+0036 "6" */
    0xb, 0x42, 0xc0, 0x30, 0x3, 0xb4, 0x34, 0xc3,
    0x9, 0x30, 0x93, 0x4c, 0xf, 0x40,

    /* U+0037 "7" */
    0x7f, 0xd0, 0xc, 0x1, 0x80, 0x24, 0x3, 0x0,
    0x60, 0x9, 0x0, 0xc0, 0x18, 0x0,

    /* U+0038 "8" */
    0x1f, 0x43, 0x1c, 0x30, 0xc3, 0x1c, 0x1f, 0x43,
    0xc, 0x70, 0xc3, 0xc, 0x1f, 0x40,

    /* U+0039 "9" */
    0x1f, 0x3, 0x1c, 0x60, 0xc6, 0xc, 0x31, 0xc1,
    0xec, 0x0, 0xc0, 0x34, 0x1d, 0x0,

    /* U+003A ":" */
    0x30, 0x40, 0x0, 0x0, 0x43, 0x0,

    /* U+003B ";" */
    0x30, 0x40, 0x0, 0x0, 0x83, 0x18, 0x40,

    /* U+003C "<" */
    0x1, 0x43, 0xcb, 0x41, 0xe0, 0xb, 0x40, 0x10,

    /* U+003D "=" */
    0x3f, 0xc0, 0x0, 0x0, 0xff, 0x0, 0x0,

    /* U+003E ">" */
    0x20, 0x2, 0xd0, 0x2, 0xc0, 0x78, 0x3c, 0x1,
    0x0,

    /* U+003F "?" */
    0x2e, 0x1c, 0x90, 0x24, 0xc, 0xa, 0x3, 0x0,
    0x40, 0x0, 0xc, 0x0,

    /* U+0040 "@" */
    0x2, 0xf8, 0x3, 0x41, 0x82, 0x40, 0x20, 0xc3,
    0xc5, 0x22, 0x24, 0x98, 0xc8, 0x25, 0x22, 0x9,
    0x8c, 0xc5, 0x22, 0x9e, 0xc, 0x0, 0x1, 0x80,
    0x0, 0x1f, 0xc0,

    /* U+0041 "A" */
    0x3, 0x0, 0x1d, 0x0, 0xe8, 0x3, 0x30, 0x18,
    0x90, 0x91, 0x83, 0xff, 0x1c, 0xc, 0xa0, 0x28,

    /* U+0042 "B" */
    0x3f, 0x83, 0xa, 0x30, 0x63, 0x9, 0x3f, 0xc3,
    0xa, 0x30, 0x73, 0xa, 0x3f, 0xc0,

    /* U+0043 "C" */
    0xb, 0xd0, 0xe1, 0xc3, 0x3, 0xc, 0x0, 0x70,
    0x0, 0xc0, 0x3, 0x3, 0xd, 0x1c, 0xb, 0xd0,

    /* U+0044 "D" */
    0x3f, 0x80, 0xc2, 0x83, 0x3, 0xc, 0xc, 0x30,
    0x30, 0xc0, 0xc3, 0x3, 0xc, 0x28, 0x3f, 0x80,

    /* U+0045 "E" */
    0x3f, 0xd3, 0x0, 0x30, 0x3, 0x0, 0x3f, 0xc3,
    0x0, 0x30, 0x3, 0x0, 0x3f, 0xe0,

    /* U+0046 "F" */
    0x3f, 0xd3, 0x0, 0x30, 0x3, 0x0, 0x3f, 0xc3,
    0x0, 0x30, 0x3, 0x0, 0x30, 0x0,

    /* U+0047 "G" */
    0xf, 0xd0, 0xd1, 0xc3, 0x1, 0xc, 0x0, 0x71,
    0xf4, 0xc0, 0xd3, 0x3, 0x4e, 0xc, 0xb, 0xd0,

    /* U+0048 "H" */
    0x30, 0x28, 0xc0, 0xa3, 0x2, 0x8c, 0xa, 0x3f,
    0xf8, 0xc0, 0xa3, 0x2, 0x8c, 0xa, 0x30, 0x28,

    /* U+0049 "I" */
    0x30, 0xc3, 0xc, 0x30, 0xc3, 0xc, 0x30,

    /* U+004A "J" */
    0x0, 0xc0, 0x30, 0xc, 0x3, 0x0, 0xc0, 0x35,
    0xd, 0xca, 0x2f, 0x0,

    /* U+004B "K" */
    0x30, 0x70, 0xc3, 0x3, 0x28, 0xd, 0xc0, 0x3f,
    0x0, 0xdd, 0x3, 0xc, 0xc, 0x28, 0x30, 0x30,

    /* U+004C "L" */
    0x30, 0x3, 0x0, 0x30, 0x3, 0x0, 0x30, 0x3,
    0x0, 0x30, 0x3, 0x0, 0x3f, 0xd0,

    /* U+004D "M" */
    0x34, 0x7, 0xf, 0x2, 0xc3, 0xc0, 0xf0, 0xe4,
    0x6c, 0x36, 0x27, 0xc, 0xcc, 0xc3, 0x26, 0x30,
    0xc7, 0x4c, 0x30, 0xc3, 0x0,

    /* U+004E "N" */
    0x30, 0x28, 0xe0, 0xa3, 0xc2, 0x8d, 0x8a, 0x33,
    0x28, 0xc6, 0xa3, 0xf, 0x8c, 0x1e, 0x30, 0x38,

    /* U+004F "O" */
    0xb, 0xc0, 0xe1, 0xc3, 0x3, 0x4c, 0x9, 0x70,
    0x24, 0xc0, 0x93, 0x3, 0x4e, 0x1c, 0xb, 0xc0,

    /* U+0050 "P" */
    0x3f, 0xd0, 0xc1, 0xc3, 0x3, 0xc, 0x1c, 0x3f,
    0xd0, 0xc0, 0x3, 0x0, 0xc, 0x0, 0x30, 0x0,

    /* U+0051 "Q" */
    0xf, 0xc0, 0xe1, 0xc3, 0x3, 0x5c, 0x9, 0x70,
    0x25, 0xc0, 0x93, 0x3, 0x4d, 0x1c, 0xb, 0xe0,
    0x0, 0xd0, 0x0, 0x0,

    /* U+0052 "R" */
    0x3f, 0xc0, 0xc2, 0x83, 0x7, 0xc, 0x28, 0x3f,
    0xc0, 0xc7, 0x3, 0xc, 0xc, 0x28, 0x30, 0x30,

    /* U+0053 "S" */
    0x1f, 0x83, 0xd, 0x30, 0x53, 0x40, 0xb, 0x40,
    0xd, 0x50, 0x63, 0xa, 0x1f, 0x80,

    /* U+0054 "T" */
    0xbf, 0xf0, 0x60, 0x6, 0x0, 0x60, 0x6, 0x0,
    0x60, 0x6, 0x0, 0x60, 0x6, 0x0,

    /* U+0055 "U" */
    0x30, 0x30, 0xc0, 0xc3, 0x3, 0xc, 0xc, 0x30,
    0x30, 0xc0, 0xc3, 0x3, 0xd, 0x2c, 0x1f, 0xc0,

    /* U+0056 "V" */
    0xa0, 0x35, 0xc0, 0xc3, 0x6, 0x9, 0x24, 0x18,
    0xc0, 0x33, 0x0, 0xe8, 0x2, 0xd0, 0x3, 0x0,

    /* U+0057 "W" */
    0x60, 0xc1, 0x98, 0x34, 0xa3, 0x1e, 0x24, 0xc9,
    0xcc, 0x27, 0x33, 0x9, 0xc9, 0xc1, 0xe1, 0xe0,
    0x34, 0x34, 0xc, 0xc, 0x0,

    /* U+0058 "X" */
    0x70, 0x70, 0xd3, 0x41, 0xcc, 0x3, 0xd0, 0x7,
    0x0, 0x3d, 0x1, 0xcc, 0xd, 0x24, 0x70, 0x70,

    /* U+0059 "Y" */
    0xa0, 0x70, 0xc2, 0x43, 0x4c, 0x6, 0x60, 0xf,
    0x0, 0x1c, 0x0, 0x60, 0x1, 0x80, 0x6, 0x0,

    /* U+005A "Z" */
    0x7f, 0xf0, 0xd, 0x1, 0x80, 0x30, 0xa, 0x0,
    0xc0, 0x28, 0x3, 0x0, 0x7f, 0xf0,

    /* U+005B "[" */
    0x38, 0xc3, 0xc, 0x30, 0xc3, 0xc, 0x30, 0xc3,
    0xc, 0x38,

    /* U+005C "\\" */
    0x90, 0x8, 0x3, 0x0, 0x90, 0x18, 0x3, 0x0,
    0xc0, 0x18, 0x3, 0x0, 0xc0,

    /* U+005D "]" */
    0xf0, 0xc3, 0xc, 0x30, 0xc3, 0xc, 0x30, 0xc3,
    0xc, 0xf0,

    /* U+005E "^" */
    0x8, 0x7, 0x3, 0x80, 0xd8, 0x63, 0x0,

    /* U+005F "_" */
    0xff, 0x80,

    /* U+0060 "`" */
    0x70, 0x90,

    /* U+0061 "a" */
    0x1f, 0x43, 0x1c, 0x0, 0xc1, 0xfc, 0x30, 0xc7,
    0x1c, 0x2e, 0xc0,

    /* U+0062 "b" */
    0x30, 0x3, 0x0, 0x30, 0x3, 0xb4, 0x30, 0xc3,
    0x9, 0x30, 0x93, 0x9, 0x30, 0xc3, 0xb4,

    /* U+0063 "c" */
    0x1f, 0x43, 0xc, 0x60, 0x46, 0x0, 0x60, 0x3,
    0xc, 0x1f, 0x40,

    /* U+0064 "d" */
    0x0, 0xc0, 0xc, 0x0, 0xc2, 0xec, 0x30, 0xc6,
    0xc, 0x60, 0xc6, 0xc, 0x30, 0xc2, 0xec,

    /* U+0065 "e" */
    0x1f, 0x43, 0x1c, 0x60, 0xc7, 0xfc, 0x60, 0x3,
    0x4, 0x1f, 0x80,

    /* U+0066 "f" */
    0xe, 0x28, 0x34, 0xbd, 0x34, 0x34, 0x34, 0x34,
    0x34, 0x34,

    /* U+0067 "g" */
    0x2e, 0xc3, 0xc, 0x60, 0xc6, 0xc, 0x60, 0xc3,
    0xc, 0x2e, 0xc0, 0xc, 0x11, 0xc2, 0xf4,

    /* U+0068 "h" */
    0x30, 0x3, 0x0, 0x30, 0x3, 0xb4, 0x31, 0xc3,
    0xc, 0x30, 0xc3, 0xc, 0x30, 0xc3, 0xc,

    /* U+0069 "i" */
    0x30, 0x33, 0x33, 0x33, 0x30,

    /* U+006A "j" */
    0x8, 0x0, 0xc3, 0xc, 0x30, 0xc3, 0xc, 0x31,
    0xcd,

    /* U+006B "k" */
    0x30, 0x3, 0x0, 0x30, 0x3, 0x28, 0x33, 0x3,
    0xd0, 0x3d, 0x3, 0x70, 0x32, 0x43, 0xc,

    /* U+006C "l" */
    0x33, 0x33, 0x33, 0x33, 0x33,

    /* U+006D "m" */
    0x3b, 0x6e, 0xc, 0x34, 0xc3, 0xc, 0x30, 0xc3,
    0xd, 0x30, 0xc3, 0x4c, 0x30, 0xd3, 0xc, 0x34,

    /* U+006E "n" */
    0x3b, 0x43, 0xc, 0x30, 0xc3, 0xc, 0x30, 0xc3,
    0xc, 0x30, 0xc0,

    /* U+006F "o" */
    0x1f, 0x43, 0xc, 0x60, 0x96, 0x9, 0x60, 0x93,
    0xc, 0x1f, 0x40,

    /* U+0070 "p" */
    0x3b, 0x43, 0xc, 0x30, 0x93, 0x9, 0x30, 0x93,
    0xc, 0x3f, 0x43, 0x0, 0x30, 0x3, 0x0,

    /* U+0071 "q" */
    0x2e, 0xc3, 0xc, 0x60, 0xc6, 0xc, 0x60, 0xc3,
    0xc, 0x2e, 0xc0, 0xc, 0x0, 0xc0, 0xc,

    /* U+0072 "r" */
    0x3d, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30,

    /* U+0073 "s" */
    0x2f, 0xc, 0x63, 0x0, 0x78, 0x2, 0x8c, 0x72,
    0xf4,

    /* U+0074 "t" */
    0x10, 0x30, 0xfc, 0x30, 0x30, 0x30, 0x30, 0x30,
    0x1c,

    /* U+0075 "u" */
    0x30, 0xc3, 0xc, 0x30, 0xc3, 0xc, 0x30, 0xc3,
    0x1c, 0x2e, 0xc0,

    /* U+0076 "v" */
    0x91, 0x98, 0x93, 0x30, 0xcc, 0x2a, 0x3, 0x40,
    0xc0,

    /* U+0077 "w" */
    0x93, 0x89, 0x63, 0x8c, 0x33, 0xcc, 0x36, 0xd8,
    0x2d, 0xb4, 0x1c, 0x74, 0x1c, 0x30,

    /* U+0078 "x" */
    0x72, 0x8c, 0xc1, 0xe0, 0x34, 0x1e, 0xc, 0xc6,
    0x18,

    /* U+0079 "y" */
    0x91, 0x98, 0x93, 0x30, 0xdc, 0x2a, 0x7, 0x40,
    0xc0, 0x30, 0x28, 0x1c, 0x0,

    /* U+007A "z" */
    0x7f, 0xc0, 0xd0, 0x60, 0x30, 0x28, 0xc, 0x7,
    0xfc,

    /* U+007B "{" */
    0x4, 0xc, 0x18, 0x24, 0x24, 0x34, 0xf0, 0x34,
    0x24, 0x24, 0x18, 0xc, 0x5,

    /* U+007C "|" */
    0xff, 0xff, 0xfc,

    /* U+007D "}" */
    0x40, 0x70, 0x30, 0x30, 0x30, 0x24, 0xd, 0x24,
    0x30, 0x30, 0x30, 0x70, 0x40,

    /* U+007E "~" */
    0x2e, 0x24, 0x8b, 0xc0, 0x0, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 44, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 0, .adv_w = 47, .box_w = 3, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 7, .adv_w = 62, .box_w = 4, .box_h = 4, .ofs_x = 0, .ofs_y = 6},
    {.bitmap_index = 11, .adv_w = 105, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 27, .adv_w = 95, .box_w = 6, .box_h = 13, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 47, .adv_w = 122, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 65, .adv_w = 104, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 81, .adv_w = 34, .box_w = 2, .box_h = 4, .ofs_x = 0, .ofs_y = 6},
    {.bitmap_index = 83, .adv_w = 60, .box_w = 4, .box_h = 14, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 97, .adv_w = 61, .box_w = 3, .box_h = 14, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 108, .adv_w = 83, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 116, .adv_w = 95, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 128, .adv_w = 38, .box_w = 2, .box_h = 4, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 130, .adv_w = 48, .box_w = 3, .box_h = 1, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 131, .adv_w = 51, .box_w = 3, .box_h = 2, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 133, .adv_w = 71, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 146, .adv_w = 95, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 160, .adv_w = 95, .box_w = 4, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 169, .adv_w = 95, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 183, .adv_w = 95, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 197, .adv_w = 95, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 211, .adv_w = 95, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 225, .adv_w = 95, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 239, .adv_w = 95, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 253, .adv_w = 95, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 267, .adv_w = 95, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 281, .adv_w = 45, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 287, .adv_w = 39, .box_w = 3, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 294, .adv_w = 86, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 302, .adv_w = 92, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 309, .adv_w = 88, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 318, .adv_w = 81, .box_w = 5, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 330, .adv_w = 148, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 357, .adv_w = 111, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 373, .adv_w = 105, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 387, .adv_w = 109, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 403, .adv_w = 110, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 419, .adv_w = 95, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 433, .adv_w = 92, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 447, .adv_w = 113, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 463, .adv_w = 119, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 479, .adv_w = 48, .box_w = 3, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 486, .adv_w = 93, .box_w = 5, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 498, .adv_w = 105, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 514, .adv_w = 91, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 528, .adv_w = 145, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 549, .adv_w = 119, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 565, .adv_w = 115, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 581, .adv_w = 106, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 597, .adv_w = 115, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 617, .adv_w = 102, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 633, .adv_w = 100, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 647, .adv_w = 100, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 661, .adv_w = 108, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 677, .adv_w = 108, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 693, .adv_w = 146, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 714, .adv_w = 106, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 730, .adv_w = 101, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 746, .adv_w = 100, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 760, .adv_w = 48, .box_w = 3, .box_h = 13, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 770, .adv_w = 71, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 783, .adv_w = 48, .box_w = 3, .box_h = 13, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 793, .adv_w = 71, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 800, .adv_w = 78, .box_w = 5, .box_h = 1, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 802, .adv_w = 59, .box_w = 3, .box_h = 2, .ofs_x = 0, .ofs_y = 8},
    {.bitmap_index = 804, .adv_w = 92, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 815, .adv_w = 95, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 830, .adv_w = 89, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 841, .adv_w = 95, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 856, .adv_w = 90, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 867, .adv_w = 61, .box_w = 4, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 877, .adv_w = 95, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 892, .adv_w = 93, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 907, .adv_w = 44, .box_w = 2, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 912, .adv_w = 43, .box_w = 3, .box_h = 12, .ofs_x = -1, .ofs_y = -3},
    {.bitmap_index = 921, .adv_w = 87, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 936, .adv_w = 44, .box_w = 2, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 941, .adv_w = 145, .box_w = 9, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 957, .adv_w = 93, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 968, .adv_w = 96, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 979, .adv_w = 95, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 994, .adv_w = 96, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1009, .adv_w = 59, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1016, .adv_w = 88, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1025, .adv_w = 57, .box_w = 4, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1034, .adv_w = 93, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1045, .adv_w = 82, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1054, .adv_w = 125, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1068, .adv_w = 84, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1077, .adv_w = 80, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1090, .adv_w = 84, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1099, .adv_w = 59, .box_w = 4, .box_h = 13, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1112, .adv_w = 47, .box_w = 1, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1115, .adv_w = 59, .box_w = 4, .box_h = 13, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1128, .adv_w = 113, .box_w = 7, .box_h = 3, .ofs_x = 0, .ofs_y = 2}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Pair left and right glyphs for kerning*/
static const uint8_t kern_pair_glyph_ids[] =
{
    3, 3,
    3, 8,
    8, 3,
    8, 8,
    13, 3,
    13, 8,
    15, 3,
    15, 8,
    16, 16
};

/* Kerning between the respective left and right glyphs
 * 4.4 format which needs to scaled with `kern_scale`*/
static const int8_t kern_pair_values[] =
{
    -10, -10, -10, -10, -16, -16, -16, -16,
    -21
};

/*Collect the kern pair's data in one place*/
static const lv_font_fmt_txt_kern_pair_t kern_pairs =
{
    .glyph_ids = kern_pair_glyph_ids,
    .values = kern_pair_values,
    .pair_cnt = 9,
    .glyph_ids_size = 0
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_pairs,
    .kern_scale = 16,
    .cmap_num = 1,
    .bpp = 2,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t RobotoCondensedVariableFont_wght12 = {
#else
lv_font_t RobotoCondensedVariableFont_wght12 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 14,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if ROBOTOCONDENSEDVARIABLEFONT_WGHT12*/

