/*******************************************************************************
 * Size: 16 px
 * Bpp: 1
 * Opts: --bpp 1 --size 16 --no-compress --font UbuntuMono-R.ttf --range 20-255 --format lvgl -o UbuntuMonoR16.c
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef UBUNTUMONOR16
#define UBUNTUMONOR16 1
#endif

#if UBUNTUMONOR16

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+001D "\u001d" */
    0x0,

    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0x55, 0x54, 0xf0,

    /* U+0022 "\"" */
    0x99, 0x99,

    /* U+0023 "#" */
    0x24, 0x4b, 0xf9, 0x66, 0xc9, 0x3f, 0xa4, 0x48,
    0x90,

    /* U+0024 "$" */
    0x23, 0xe1, 0xc, 0x30, 0xc1, 0x8, 0x7c, 0x42,
    0x0,

    /* U+0025 "%" */
    0x63, 0x2a, 0x74, 0xc7, 0x2, 0x8a, 0x95, 0x4b,
    0x88,

    /* U+0026 "&" */
    0x30, 0x91, 0x22, 0xc7, 0xe, 0xa7, 0x46, 0x8c,
    0xec,

    /* U+0027 "'" */
    0xf0,

    /* U+0028 "(" */
    0x13, 0x64, 0xc8, 0x88, 0x88, 0xc4, 0x63, 0x10,

    /* U+0029 ")" */
    0x8c, 0x62, 0x31, 0x11, 0x11, 0x32, 0x6c, 0x80,

    /* U+002A "*" */
    0x25, 0x7e, 0xc5, 0x28,

    /* U+002B "+" */
    0x10, 0x20, 0x47, 0xf1, 0x2, 0x4, 0x0,

    /* U+002C "," */
    0x6c, 0xa8,

    /* U+002D "-" */
    0xf0,

    /* U+002E "." */
    0xf0,

    /* U+002F "/" */
    0xc, 0x20, 0x86, 0x10, 0x43, 0xc, 0x20, 0x86,
    0x10, 0x43, 0x0,

    /* U+0030 "0" */
    0x79, 0x28, 0x6d, 0xb6, 0x18, 0x61, 0x49, 0xc0,

    /* U+0031 "1" */
    0x23, 0x28, 0x42, 0x10, 0x84, 0x27, 0xc0,

    /* U+0032 "2" */
    0xf2, 0x20, 0x82, 0x10, 0xc6, 0x10, 0xc3, 0xf0,

    /* U+0033 "3" */
    0xf2, 0x20, 0x82, 0x70, 0x30, 0x41, 0xf, 0xe0,

    /* U+0034 "4" */
    0xc, 0x38, 0x51, 0x24, 0x58, 0xbf, 0x82, 0x4,
    0x8,

    /* U+0035 "5" */
    0x7d, 0x4, 0x10, 0x78, 0x30, 0x41, 0xf, 0xe0,

    /* U+0036 "6" */
    0x1d, 0x84, 0x3e, 0x8e, 0x18, 0x61, 0x49, 0xe0,

    /* U+0037 "7" */
    0xfc, 0x30, 0x86, 0x10, 0xc2, 0x8, 0x21, 0x80,

    /* U+0038 "8" */
    0x7a, 0x38, 0x61, 0x79, 0x68, 0x61, 0x85, 0xe0,

    /* U+0039 "9" */
    0x7b, 0x28, 0x61, 0xc5, 0xf0, 0x42, 0x1b, 0x80,

    /* U+003A ":" */
    0xf0, 0xf,

    /* U+003B ";" */
    0x6c, 0x0, 0xd9, 0x50,

    /* U+003C "<" */
    0x0, 0x1d, 0xc6, 0xe, 0x3, 0x81, 0x0,

    /* U+003D "=" */
    0xfe, 0x0, 0x7, 0xf0,

    /* U+003E ">" */
    0x1, 0xc0, 0x70, 0x30, 0xee, 0x10, 0x0,

    /* U+003F "?" */
    0xf0, 0x42, 0x33, 0x31, 0x0, 0x63, 0x0,

    /* U+0040 "@" */
    0x3c, 0xc9, 0xc, 0xfb, 0x34, 0x68, 0xd1, 0xb3,
    0x3d, 0x3, 0x1, 0xc0,

    /* U+0041 "A" */
    0x18, 0x18, 0x24, 0x24, 0x24, 0x66, 0x7e, 0x42,
    0x42, 0xc3,

    /* U+0042 "B" */
    0xfa, 0x38, 0x63, 0xfa, 0x38, 0x61, 0x8f, 0xe0,

    /* U+0043 "C" */
    0x3d, 0xc, 0x20, 0x82, 0x8, 0x20, 0x40, 0xf0,

    /* U+0044 "D" */
    0xf2, 0x28, 0x61, 0x86, 0x18, 0x61, 0x8b, 0xc0,

    /* U+0045 "E" */
    0xfa, 0x8, 0x20, 0xfa, 0x8, 0x20, 0x83, 0xf0,

    /* U+0046 "F" */
    0xfc, 0x21, 0xf, 0xc2, 0x10, 0x84, 0x0,

    /* U+0047 "G" */
    0x3d, 0x1c, 0x20, 0x82, 0x18, 0x71, 0x44, 0xf0,

    /* U+0048 "H" */
    0x86, 0x18, 0x61, 0xfe, 0x18, 0x61, 0x86, 0x10,

    /* U+0049 "I" */
    0xf9, 0x8, 0x42, 0x10, 0x84, 0x27, 0xc0,

    /* U+004A "J" */
    0x3c, 0x10, 0x41, 0x4, 0x10, 0x41, 0xd, 0xe0,

    /* U+004B "K" */
    0x8d, 0x12, 0x45, 0xe, 0x1c, 0x24, 0x4c, 0x8d,
    0x8,

    /* U+004C "L" */
    0x82, 0x8, 0x20, 0x82, 0x8, 0x20, 0x83, 0xf0,

    /* U+004D "M" */
    0xc7, 0x8f, 0xbd, 0x5a, 0xb2, 0x60, 0xc1, 0x83,
    0x4,

    /* U+004E "N" */
    0x87, 0x1e, 0x69, 0xb6, 0x59, 0x63, 0x8e, 0x10,

    /* U+004F "O" */
    0x38, 0x8a, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x44,
    0x70,

    /* U+0050 "P" */
    0xfa, 0x38, 0x61, 0x8f, 0xe8, 0x20, 0x82, 0x0,

    /* U+0051 "Q" */
    0x38, 0x8a, 0xc, 0x18, 0x30, 0x60, 0xc1, 0xc6,
    0xf8, 0xe0, 0xc0, 0xe0,

    /* U+0052 "R" */
    0xf9, 0x1a, 0x14, 0x28, 0xdf, 0x26, 0x44, 0x85,
    0x8,

    /* U+0053 "S" */
    0x7e, 0x8, 0x20, 0x70, 0x60, 0x41, 0x7, 0xe0,

    /* U+0054 "T" */
    0xfe, 0x20, 0x40, 0x81, 0x2, 0x4, 0x8, 0x10,
    0x20,

    /* U+0055 "U" */
    0x86, 0x18, 0x61, 0x86, 0x18, 0x61, 0xcd, 0xe0,

    /* U+0056 "V" */
    0xc3, 0x42, 0x42, 0x42, 0x66, 0x24, 0x24, 0x3c,
    0x18, 0x18,

    /* U+0057 "W" */
    0x83, 0x6, 0xc, 0x19, 0x35, 0x6a, 0xf7, 0xc7,
    0x8c,

    /* U+0058 "X" */
    0x42, 0x66, 0x24, 0x3c, 0x18, 0x18, 0x2c, 0x24,
    0x66, 0x42,

    /* U+0059 "Y" */
    0xc3, 0x8d, 0x13, 0x62, 0x82, 0x4, 0x8, 0x10,
    0x20,

    /* U+005A "Z" */
    0xfc, 0x30, 0x84, 0x30, 0x86, 0x10, 0xc3, 0xf0,

    /* U+005B "[" */
    0xf8, 0x88, 0x88, 0x88, 0x88, 0x88, 0x8f,

    /* U+005C "\\" */
    0xc1, 0x4, 0x18, 0x20, 0x83, 0xc, 0x10, 0x41,
    0x82, 0x8, 0x30,

    /* U+005D "]" */
    0xf1, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1f,

    /* U+005E "^" */
    0x30, 0xc4, 0x92, 0x86, 0x10,

    /* U+005F "_" */
    0xff,

    /* U+0060 "`" */
    0xa4,

    /* U+0061 "a" */
    0x78, 0x30, 0x5f, 0xc6, 0x18, 0x5f,

    /* U+0062 "b" */
    0x82, 0x8, 0x20, 0xf2, 0x28, 0x61, 0x86, 0x18,
    0xbc,

    /* U+0063 "c" */
    0x3d, 0x8, 0x20, 0x82, 0x4, 0xf,

    /* U+0064 "d" */
    0x4, 0x10, 0x41, 0x3d, 0x18, 0x61, 0x86, 0x14,
    0x4f,

    /* U+0065 "e" */
    0x39, 0x38, 0x7f, 0x82, 0x4, 0xf,

    /* U+0066 "f" */
    0x1e, 0x40, 0x87, 0xe2, 0x4, 0x8, 0x10, 0x20,
    0x40, 0x80,

    /* U+0067 "g" */
    0x3d, 0x18, 0x61, 0x86, 0x14, 0x5f, 0x4, 0x3f,
    0x80,

    /* U+0068 "h" */
    0x82, 0x8, 0x20, 0xfa, 0x38, 0x61, 0x86, 0x18,
    0x61,

    /* U+0069 "i" */
    0x61, 0x80, 0x38, 0x20, 0x82, 0x8, 0x20, 0x81,
    0xc0,

    /* U+006A "j" */
    0x18, 0xc0, 0xf0, 0x84, 0x21, 0x8, 0x42, 0x10,
    0xf8,

    /* U+006B "k" */
    0x82, 0x8, 0x20, 0x8a, 0x6b, 0x30, 0xe2, 0x48,
    0xa3,

    /* U+006C "l" */
    0xe0, 0x82, 0x8, 0x20, 0x82, 0x8, 0x20, 0x81,
    0xc0,

    /* U+006D "m" */
    0xed, 0x26, 0x4c, 0x99, 0x30, 0x60, 0xc1,

    /* U+006E "n" */
    0xfa, 0x38, 0x61, 0x86, 0x18, 0x61,

    /* U+006F "o" */
    0x38, 0x8a, 0xc, 0x18, 0x30, 0x51, 0x1c,

    /* U+0070 "p" */
    0xf2, 0x28, 0x61, 0x86, 0x18, 0xbc, 0x82, 0x8,
    0x0,

    /* U+0071 "q" */
    0x3d, 0x18, 0x61, 0x86, 0x14, 0x4f, 0x4, 0x10,
    0x40,

    /* U+0072 "r" */
    0xfc, 0x21, 0x8, 0x42, 0x10,

    /* U+0073 "s" */
    0x7e, 0x8, 0x1c, 0x18, 0x10, 0x7e,

    /* U+0074 "t" */
    0x20, 0x8f, 0xc8, 0x20, 0x82, 0x8, 0x20, 0x70,

    /* U+0075 "u" */
    0x86, 0x18, 0x61, 0x86, 0x1c, 0x5f,

    /* U+0076 "v" */
    0x42, 0x42, 0x66, 0x24, 0x24, 0x3c, 0x18, 0x18,

    /* U+0077 "w" */
    0xc3, 0xc3, 0x5a, 0x5a, 0x5a, 0x66, 0x66, 0x66,

    /* U+0078 "x" */
    0x42, 0x24, 0x3c, 0x18, 0x18, 0x24, 0x66, 0x42,

    /* U+0079 "y" */
    0x87, 0x1c, 0xd2, 0x49, 0xa3, 0x8c, 0x10, 0x8c,
    0x0,

    /* U+007A "z" */
    0xfc, 0x31, 0x8c, 0x21, 0x8c, 0x3f,

    /* U+007B "{" */
    0x1c, 0x82, 0x8, 0x20, 0x8c, 0x8, 0x20, 0x82,
    0x8, 0x20, 0x70,

    /* U+007C "|" */
    0xff, 0xfc,

    /* U+007D "}" */
    0xe0, 0x41, 0x4, 0x10, 0x40, 0xc4, 0x10, 0x41,
    0x4, 0x13, 0x80,

    /* U+007E "~" */
    0xe6, 0x70,

    /* U+00A0 " " */
    0x0,

    /* U+00A1 "¡" */
    0xf0, 0x55, 0x54,

    /* U+00A2 "¢" */
    0x10, 0x43, 0xd0, 0x82, 0x8, 0x20, 0x40, 0xf1,
    0x4,

    /* U+00A3 "£" */
    0x3c, 0x81, 0x2, 0xf, 0x88, 0x10, 0x20, 0x40,
    0xfc,

    /* U+00A4 "¤" */
    0x0, 0xf9, 0xb2, 0x24, 0x49, 0x9f, 0x0,

    /* U+00A5 "¥" */
    0xc3, 0x46, 0x64, 0x2c, 0x38, 0x7e, 0x10, 0x7e,
    0x10, 0x10,

    /* U+00A6 "¦" */
    0xfc, 0xfc,

    /* U+00A7 "§" */
    0x39, 0x4, 0x1c, 0xda, 0x18, 0x5b, 0x38, 0x20,
    0xbc,

    /* U+00A8 "¨" */
    0x99,

    /* U+00A9 "©" */
    0x38, 0x8a, 0x6d, 0x1a, 0x33, 0x51, 0x1c,

    /* U+00AA "ª" */
    0x71, 0xf9, 0xf0,

    /* U+00AB "«" */
    0x69, 0x2d, 0x36, 0x48, 0x0,

    /* U+00AC "¬" */
    0xfc, 0x10, 0x41, 0x4,

    /* U+00AD "­" */
    0xf0,

    /* U+00AE "®" */
    0x38, 0x8a, 0xed, 0x5b, 0xb5, 0x51, 0x1c,

    /* U+00AF "¯" */
    0xf0,

    /* U+00B0 "°" */
    0x69, 0x96,

    /* U+00B1 "±" */
    0x10, 0x20, 0x47, 0xf1, 0x2, 0x4, 0x0, 0xfe,

    /* U+00B2 "²" */
    0x71, 0x24, 0xf0,

    /* U+00B3 "³" */
    0xf6, 0x11, 0xe0,

    /* U+00B4 "´" */
    0x58,

    /* U+00B5 "µ" */
    0x86, 0x18, 0x61, 0x86, 0x1c, 0x7f, 0x82, 0x8,
    0x0,

    /* U+00B6 "¶" */
    0x3e, 0xe7, 0xcf, 0x9f, 0x2e, 0x44, 0x89, 0x12,
    0x24, 0x48, 0x91, 0x20,

    /* U+00B7 "·" */
    0xf0,

    /* U+00B8 "¸" */
    0x47, 0x80,

    /* U+00B9 "¹" */
    0x26, 0x22, 0xf0,

    /* U+00BA "º" */
    0x74, 0x63, 0x17, 0x0,

    /* U+00BB "»" */
    0x59, 0x22, 0xda, 0x48, 0x0,

    /* U+00BC "¼" */
    0x45, 0x89, 0x22, 0x41, 0x6, 0x9, 0x36, 0x55,
    0xbe, 0x10,

    /* U+00BD "½" */
    0x23, 0x62, 0x24, 0x24, 0x8, 0x10, 0x17, 0x21,
    0x62, 0x47,

    /* U+00BE "¾" */
    0xe2, 0x22, 0x64, 0x24, 0xe8, 0x18, 0x10, 0x26,
    0x2a, 0x4f, 0xc2,

    /* U+00BF "¿" */
    0x31, 0x80, 0x3, 0x11, 0x10, 0x84, 0x1e,

    /* U+00C0 "À" */
    0x10, 0x10, 0x8, 0x0, 0x18, 0x18, 0x24, 0x24,
    0x24, 0x66, 0x7e, 0x42, 0x42, 0xc3,

    /* U+00C1 "Á" */
    0x8, 0x8, 0x10, 0x0, 0x18, 0x18, 0x24, 0x24,
    0x24, 0x66, 0x7e, 0x42, 0x42, 0xc3,

    /* U+00C2 "Â" */
    0x18, 0x24, 0x0, 0x18, 0x18, 0x24, 0x24, 0x24,
    0x66, 0x7e, 0x42, 0x42, 0xc3,

    /* U+00C3 "Ã" */
    0x3c, 0x0, 0x0, 0x18, 0x18, 0x24, 0x24, 0x24,
    0x66, 0x7e, 0x42, 0x42, 0xc3,

    /* U+00C4 "Ä" */
    0x24, 0x24, 0x0, 0x18, 0x3c, 0x24, 0x24, 0x24,
    0x46, 0x7e, 0x42, 0x42, 0xc3,

    /* U+00C5 "Å" */
    0x38, 0x50, 0xa1, 0xc2, 0x85, 0x1b, 0x22, 0x45,
    0xfa, 0x1c, 0x18, 0x20,

    /* U+00C6 "Æ" */
    0x1e, 0x30, 0xa1, 0x42, 0xed, 0x1e, 0x24, 0x49,
    0x9c,

    /* U+00C7 "Ç" */
    0x3c, 0x83, 0x4, 0x8, 0x10, 0x20, 0x60, 0x40,
    0x78, 0x40, 0x43, 0x80,

    /* U+00C8 "È" */
    0x1, 0x83, 0x0, 0xfa, 0x8, 0x20, 0xfa, 0x8,
    0x20, 0x83, 0xf0,

    /* U+00C9 "É" */
    0x0, 0xc2, 0x0, 0xfa, 0x8, 0x20, 0xfa, 0x8,
    0x20, 0x83, 0xf0,

    /* U+00CA "Ê" */
    0x21, 0x40, 0x3e, 0x82, 0x8, 0x3e, 0x82, 0x8,
    0x20, 0xfc,

    /* U+00CB "Ë" */
    0x49, 0x20, 0x3f, 0x82, 0x8, 0x3e, 0x82, 0x8,
    0x20, 0xfc,

    /* U+00CC "Ì" */
    0x3, 0xc, 0xf, 0x90, 0x84, 0x21, 0x8, 0x42,
    0x7c,

    /* U+00CD "Í" */
    0x1, 0x88, 0xf, 0x90, 0x84, 0x21, 0x8, 0x42,
    0x7c,

    /* U+00CE "Î" */
    0x22, 0x81, 0xf2, 0x10, 0x84, 0x21, 0x8, 0x4f,
    0x80,

    /* U+00CF "Ï" */
    0x52, 0x81, 0xf2, 0x10, 0x84, 0x21, 0x8, 0x4f,
    0x80,

    /* U+00D0 "Ð" */
    0x78, 0x89, 0x1a, 0x1f, 0x28, 0x50, 0xa1, 0x44,
    0xf0,

    /* U+00D1 "Ñ" */
    0x78, 0x0, 0x21, 0xc7, 0x9a, 0x6d, 0x96, 0x58,
    0xe3, 0x84,

    /* U+00D2 "Ò" */
    0x30, 0x30, 0x1, 0xc4, 0x50, 0x60, 0xc1, 0x83,
    0x6, 0xa, 0x23, 0x80,

    /* U+00D3 "Ó" */
    0x8, 0x20, 0x1, 0xc4, 0x50, 0x60, 0xc1, 0x83,
    0x6, 0xa, 0x23, 0x80,

    /* U+00D4 "Ô" */
    0x10, 0x50, 0x1, 0xc4, 0x50, 0x60, 0xc1, 0x83,
    0x6, 0xa, 0x23, 0x80,

    /* U+00D5 "Õ" */
    0x34, 0xb0, 0x0, 0x3, 0x88, 0xa0, 0xc1, 0x83,
    0x6, 0xc, 0x14, 0x47, 0x0,

    /* U+00D6 "Ö" */
    0x28, 0x50, 0x0, 0x3, 0x88, 0xa0, 0xc1, 0x83,
    0x6, 0xc, 0x14, 0x47, 0x0,

    /* U+00D7 "×" */
    0xcd, 0xe3, 0x1e, 0xcc, 0x0,

    /* U+00D8 "Ø" */
    0x3c, 0x8a, 0x3c, 0x59, 0x36, 0x68, 0xf1, 0x45,
    0xf0,

    /* U+00D9 "Ù" */
    0x0, 0x81, 0x0, 0x86, 0x18, 0x61, 0x86, 0x18,
    0x61, 0xcd, 0xe0,

    /* U+00DA "Ú" */
    0x0, 0x42, 0x0, 0x86, 0x18, 0x61, 0x86, 0x18,
    0x61, 0xcd, 0xe0,

    /* U+00DB "Û" */
    0x31, 0x20, 0x21, 0x86, 0x18, 0x61, 0x86, 0x18,
    0x73, 0x78,

    /* U+00DC "Ü" */
    0x49, 0x20, 0x0, 0x86, 0x18, 0x61, 0x86, 0x18,
    0x61, 0xcd, 0xe0,

    /* U+00DD "Ý" */
    0x0, 0x30, 0x40, 0xc, 0x38, 0xd1, 0x36, 0x28,
    0x20, 0x40, 0x81, 0x2, 0x0,

    /* U+00DE "Þ" */
    0x83, 0xc8, 0xe1, 0x86, 0x18, 0xbc, 0x82, 0x0,

    /* U+00DF "ß" */
    0x72, 0x28, 0xa6, 0xb2, 0x89, 0xa3, 0x86, 0x1b,
    0x80,

    /* U+00E0 "à" */
    0x20, 0xc1, 0x0, 0x78, 0x30, 0x5f, 0xc6, 0x18,
    0x5f,

    /* U+00E1 "á" */
    0x0, 0x63, 0x0, 0x78, 0x30, 0x5f, 0xc6, 0x18,
    0x5f,

    /* U+00E2 "â" */
    0x0, 0xc6, 0x80, 0x78, 0x30, 0x5f, 0xc6, 0x18,
    0x5f,

    /* U+00E3 "ã" */
    0x78, 0x7, 0x83, 0x5, 0xfc, 0x61, 0x85, 0xf0,

    /* U+00E4 "ä" */
    0x49, 0x27, 0x81, 0x5, 0xfc, 0x61, 0x85, 0xf0,

    /* U+00E5 "å" */
    0x79, 0xe0, 0x1e, 0xc, 0x17, 0xf1, 0x86, 0x17,
    0xc0,

    /* U+00E6 "æ" */
    0xec, 0x24, 0x4b, 0xf9, 0x12, 0x26, 0x3f,

    /* U+00E7 "ç" */
    0x3d, 0x8, 0x20, 0x82, 0x4, 0xf, 0x10, 0x43,
    0x0,

    /* U+00E8 "è" */
    0x20, 0x81, 0x0, 0x39, 0x38, 0x7f, 0x82, 0x4,
    0xf,

    /* U+00E9 "é" */
    0x0, 0x42, 0x0, 0x39, 0x38, 0x7f, 0x82, 0x4,
    0xf,

    /* U+00EA "ê" */
    0x0, 0xc6, 0x80, 0x39, 0x38, 0x7f, 0x82, 0x4,
    0xf,

    /* U+00EB "ë" */
    0x28, 0xa3, 0x93, 0x87, 0xf8, 0x20, 0x40, 0xe0,

    /* U+00EC "ì" */
    0x41, 0x82, 0x0, 0xe0, 0x82, 0x8, 0x20, 0x82,
    0x7,

    /* U+00ED "í" */
    0x0, 0x84, 0x0, 0xe0, 0x82, 0x8, 0x20, 0x82,
    0x7,

    /* U+00EE "î" */
    0x1, 0x85, 0x0, 0xe0, 0x82, 0x8, 0x20, 0x82,
    0x7,

    /* U+00EF "ï" */
    0x92, 0x4e, 0x8, 0x20, 0x82, 0x8, 0x20, 0x70,

    /* U+00F0 "ð" */
    0x30, 0x73, 0x81, 0x7f, 0x18, 0x61, 0x87, 0x27,
    0x80,

    /* U+00F1 "ñ" */
    0x78, 0xf, 0xa3, 0x86, 0x18, 0x61, 0x86, 0x10,

    /* U+00F2 "ò" */
    0x0, 0x60, 0x60, 0x3, 0x88, 0xa0, 0xc1, 0x83,
    0x5, 0x11, 0xc0,

    /* U+00F3 "ó" */
    0x8, 0x30, 0xc0, 0x3, 0x88, 0xa0, 0xc1, 0x83,
    0x5, 0x11, 0xc0,

    /* U+00F4 "ô" */
    0x10, 0x71, 0xb0, 0x3, 0x88, 0xa0, 0xc1, 0x83,
    0x5, 0x11, 0xc0,

    /* U+00F5 "õ" */
    0x7c, 0x0, 0xe2, 0x28, 0x30, 0x60, 0xc1, 0x44,
    0x70,

    /* U+00F6 "ö" */
    0x28, 0x50, 0xe3, 0x2c, 0x38, 0x70, 0xe1, 0x64,
    0x70,

    /* U+00F7 "÷" */
    0x30, 0x60, 0x7, 0xf0, 0x0, 0xc, 0x18,

    /* U+00F8 "ø" */
    0x3e, 0x8e, 0x3c, 0xdb, 0x3c, 0x71, 0x7c,

    /* U+00F9 "ù" */
    0x20, 0xc1, 0x80, 0x86, 0x18, 0x61, 0x86, 0x1c,
    0x5f,

    /* U+00FA "ú" */
    0x0, 0x42, 0x0, 0x86, 0x18, 0x61, 0x86, 0x1c,
    0x5f,

    /* U+00FB "û" */
    0x0, 0xc4, 0x80, 0x86, 0x18, 0x61, 0x86, 0x1c,
    0x5f,

    /* U+00FC "ü" */
    0x49, 0x28, 0x61, 0x86, 0x18, 0x61, 0xc5, 0xf0,

    /* U+00FD "ý" */
    0x10, 0x42, 0x0, 0x87, 0x1c, 0xd2, 0x49, 0xa3,
    0x8c, 0x10, 0x8c, 0x0,

    /* U+00FE "þ" */
    0x82, 0x8, 0x20, 0xf2, 0x28, 0x61, 0x86, 0x18,
    0xbc, 0x82, 0x8, 0x0,

    /* U+00FF "ÿ" */
    0x49, 0x28, 0x63, 0xcb, 0x24, 0x9e, 0x70, 0xc3,
    0x18, 0xc0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 128, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 128, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2, .adv_w = 128, .box_w = 2, .box_h = 10, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 5, .adv_w = 128, .box_w = 4, .box_h = 4, .ofs_x = 2, .ofs_y = 7},
    {.bitmap_index = 7, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 16, .adv_w = 128, .box_w = 5, .box_h = 13, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 25, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 34, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 43, .adv_w = 128, .box_w = 1, .box_h = 4, .ofs_x = 3, .ofs_y = 7},
    {.bitmap_index = 44, .adv_w = 128, .box_w = 4, .box_h = 15, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 52, .adv_w = 128, .box_w = 4, .box_h = 15, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 60, .adv_w = 128, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 64, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 71, .adv_w = 128, .box_w = 3, .box_h = 5, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 73, .adv_w = 128, .box_w = 4, .box_h = 1, .ofs_x = 2, .ofs_y = 4},
    {.bitmap_index = 74, .adv_w = 128, .box_w = 2, .box_h = 2, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 75, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 86, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 94, .adv_w = 128, .box_w = 5, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 101, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 109, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 117, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 126, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 134, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 142, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 150, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 158, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 166, .adv_w = 128, .box_w = 2, .box_h = 8, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 168, .adv_w = 128, .box_w = 3, .box_h = 10, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 172, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 179, .adv_w = 128, .box_w = 7, .box_h = 4, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 183, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 190, .adv_w = 128, .box_w = 5, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 197, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 209, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 219, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 227, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 235, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 243, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 251, .adv_w = 128, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 258, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 266, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 274, .adv_w = 128, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 281, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 289, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 298, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 306, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 315, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 323, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 332, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 340, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 352, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 361, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 369, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 378, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 386, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 396, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 405, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 415, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 424, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 432, .adv_w = 128, .box_w = 4, .box_h = 14, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 439, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 450, .adv_w = 128, .box_w = 4, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 457, .adv_w = 128, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 462, .adv_w = 128, .box_w = 8, .box_h = 1, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 463, .adv_w = 128, .box_w = 2, .box_h = 3, .ofs_x = 3, .ofs_y = 9},
    {.bitmap_index = 464, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 470, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 479, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 485, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 494, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 500, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 510, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 519, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 528, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 537, .adv_w = 128, .box_w = 5, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 546, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 555, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 564, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 571, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 577, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 584, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 593, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 602, .adv_w = 128, .box_w = 5, .box_h = 8, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 607, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 613, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 621, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 627, .adv_w = 128, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 635, .adv_w = 128, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 643, .adv_w = 128, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 651, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 660, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 666, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 677, .adv_w = 128, .box_w = 1, .box_h = 14, .ofs_x = 3, .ofs_y = -3},
    {.bitmap_index = 679, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 690, .adv_w = 128, .box_w = 6, .box_h = 2, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 692, .adv_w = 128, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 693, .adv_w = 128, .box_w = 2, .box_h = 11, .ofs_x = 3, .ofs_y = -3},
    {.bitmap_index = 696, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 705, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 714, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 721, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 731, .adv_w = 128, .box_w = 1, .box_h = 14, .ofs_x = 3, .ofs_y = -3},
    {.bitmap_index = 733, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 742, .adv_w = 128, .box_w = 4, .box_h = 2, .ofs_x = 2, .ofs_y = 9},
    {.bitmap_index = 743, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 750, .adv_w = 128, .box_w = 4, .box_h = 5, .ofs_x = 2, .ofs_y = 5},
    {.bitmap_index = 753, .adv_w = 128, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 758, .adv_w = 128, .box_w = 6, .box_h = 5, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 762, .adv_w = 128, .box_w = 4, .box_h = 1, .ofs_x = 2, .ofs_y = 4},
    {.bitmap_index = 763, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 770, .adv_w = 128, .box_w = 4, .box_h = 1, .ofs_x = 2, .ofs_y = 10},
    {.bitmap_index = 771, .adv_w = 128, .box_w = 4, .box_h = 4, .ofs_x = 2, .ofs_y = 7},
    {.bitmap_index = 773, .adv_w = 128, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 781, .adv_w = 128, .box_w = 4, .box_h = 5, .ofs_x = 2, .ofs_y = 5},
    {.bitmap_index = 784, .adv_w = 128, .box_w = 4, .box_h = 5, .ofs_x = 2, .ofs_y = 5},
    {.bitmap_index = 787, .adv_w = 128, .box_w = 2, .box_h = 3, .ofs_x = 3, .ofs_y = 9},
    {.bitmap_index = 788, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 797, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 809, .adv_w = 128, .box_w = 2, .box_h = 2, .ofs_x = 3, .ofs_y = 3},
    {.bitmap_index = 810, .adv_w = 128, .box_w = 3, .box_h = 3, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 812, .adv_w = 128, .box_w = 4, .box_h = 5, .ofs_x = 2, .ofs_y = 5},
    {.bitmap_index = 815, .adv_w = 128, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 819, .adv_w = 128, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 824, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 834, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 844, .adv_w = 128, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 855, .adv_w = 128, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 862, .adv_w = 128, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 876, .adv_w = 128, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 890, .adv_w = 128, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 903, .adv_w = 128, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 916, .adv_w = 128, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 929, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 941, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 950, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 962, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 973, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 984, .adv_w = 128, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 994, .adv_w = 128, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1004, .adv_w = 128, .box_w = 5, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1013, .adv_w = 128, .box_w = 5, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1022, .adv_w = 128, .box_w = 5, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1031, .adv_w = 128, .box_w = 5, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1040, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1049, .adv_w = 128, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1059, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1071, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1083, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1095, .adv_w = 128, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1108, .adv_w = 128, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1121, .adv_w = 128, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 1126, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1135, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1146, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1157, .adv_w = 128, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1167, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1178, .adv_w = 128, .box_w = 7, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1191, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1199, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1208, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1217, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1226, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1235, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1243, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1251, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1260, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1267, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1276, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1285, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1294, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1303, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1311, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1320, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1329, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1338, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1346, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1355, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1363, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1374, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1385, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1396, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1405, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1414, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1421, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1428, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1437, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1446, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1455, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1463, .adv_w = 128, .box_w = 6, .box_h = 15, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1475, .adv_w = 128, .box_w = 6, .box_h = 15, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1487, .adv_w = 128, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = -3}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 29, .range_length = 1, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 2,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 160, .range_length = 96, .glyph_id_start = 97,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
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
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 3,
    .bpp = 1,
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
const lv_font_t UbuntuMonoR16 = {
#else
lv_font_t UbuntuMonoR16 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 17,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 0,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if UBUNTUMONOR16*/

