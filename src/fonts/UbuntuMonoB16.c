/*******************************************************************************
 * Size: 16 px
 * Bpp: 1
 * Opts: --bpp 1 --size 16 --no-compress --font UbuntuMono-B.ttf --range 20-255 --format lvgl -o UbuntuMonoB16.c
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef UBUNTUMONOB16
#define UBUNTUMONOB16 1
#endif

#if UBUNTUMONOB16

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
    0xff, 0xf0, 0xf0,

    /* U+0022 "\"" */
    0xde, 0xf7, 0xb0,

    /* U+0023 "#" */
    0x34, 0x4b, 0xff, 0xf6, 0xcd, 0xbf, 0xff, 0x48,
    0xb0,

    /* U+0024 "$" */
    0x30, 0xc7, 0xf0, 0xc3, 0xc7, 0x87, 0xe, 0x3f,
    0xcc, 0x30,

    /* U+0025 "%" */
    0x63, 0xf6, 0xfe, 0xfc, 0x78, 0x1e, 0x3f, 0x7f,
    0x6f, 0xc6,

    /* U+0026 "&" */
    0x38, 0xf9, 0xb3, 0x63, 0x8e, 0xf3, 0xe3, 0xfe,
    0xec,

    /* U+0027 "'" */
    0xff, 0xc0,

    /* U+0028 "(" */
    0x8, 0xcc, 0xc6, 0x63, 0x18, 0xc6, 0x38, 0xc3,
    0x1c, 0x20,

    /* U+0029 ")" */
    0x86, 0x18, 0x63, 0xc, 0x63, 0x18, 0xcc, 0x66,
    0x72, 0x0,

    /* U+002A "*" */
    0x32, 0xdf, 0xcc, 0x79, 0x20,

    /* U+002B "+" */
    0x30, 0x63, 0xff, 0xf3, 0x6, 0xc, 0x0,

    /* U+002C "," */
    0x77, 0x73, 0xe0,

    /* U+002D "-" */
    0xff,

    /* U+002E "." */
    0xff, 0x80,

    /* U+002F "/" */
    0xc, 0x31, 0x86, 0x18, 0xe3, 0xc, 0x71, 0x86,
    0x18, 0xc3, 0x0,

    /* U+0030 "0" */
    0x79, 0xec, 0xff, 0xff, 0x3c, 0xf3, 0x79, 0xe0,

    /* U+0031 "1" */
    0x18, 0x71, 0xe0, 0xc1, 0x83, 0x6, 0xc, 0x7e,
    0xfc,

    /* U+0032 "2" */
    0x79, 0xfa, 0x30, 0x61, 0x86, 0x18, 0x60, 0xff,
    0xfc,

    /* U+0033 "3" */
    0x7b, 0xf0, 0xde, 0x78, 0x30, 0xc3, 0xff, 0xe0,

    /* U+0034 "4" */
    0xc, 0x38, 0xf1, 0x66, 0xd9, 0xbf, 0xff, 0xc,
    0x18,

    /* U+0035 "5" */
    0x7d, 0xf4, 0x10, 0x78, 0x70, 0xc3, 0xff, 0xe0,

    /* U+0036 "6" */
    0x1c, 0x79, 0x87, 0xef, 0xf8, 0xf1, 0xe3, 0x7c,
    0x70,

    /* U+0037 "7" */
    0xff, 0xf1, 0xc6, 0x30, 0xc3, 0x18, 0x61, 0x80,

    /* U+0038 "8" */
    0x7d, 0xff, 0x1e, 0x37, 0xcf, 0xb1, 0xe3, 0xfe,
    0xf8,

    /* U+0039 "9" */
    0x79, 0xfb, 0x1e, 0x3f, 0xef, 0xc3, 0x8e, 0x78,
    0xe0,

    /* U+003A ":" */
    0xff, 0x81, 0xff,

    /* U+003B ";" */
    0x77, 0x70, 0x7, 0x77, 0x3e,

    /* U+003C "<" */
    0x4, 0x3d, 0xe7, 0xf, 0x7, 0xc3, 0x0,

    /* U+003D "=" */
    0xff, 0xfc, 0x7, 0xff, 0xe0,

    /* U+003E ">" */
    0x41, 0xe0, 0xf0, 0x71, 0xff, 0x18, 0x0,

    /* U+003F "?" */
    0xfb, 0xf8, 0xc3, 0x18, 0xc7, 0x0, 0x71, 0xc0,

    /* U+0040 "@" */
    0x3c, 0xf9, 0x9e, 0x3d, 0xff, 0xfd, 0xfb, 0xf7,
    0xff, 0x7b, 0x7, 0xe7, 0xc0,

    /* U+0041 "A" */
    0x18, 0x3c, 0x3c, 0x3c, 0x24, 0x66, 0x7e, 0x7e,
    0xe6, 0xc3,

    /* U+0042 "B" */
    0xf9, 0xfb, 0x36, 0x6f, 0x9f, 0xb1, 0xe3, 0xff,
    0xf0,

    /* U+0043 "C" */
    0x3e, 0xff, 0x8e, 0xc, 0x18, 0x30, 0x70, 0x7e,
    0x7c,

    /* U+0044 "D" */
    0xf9, 0xfb, 0x3e, 0x3c, 0x78, 0xf1, 0xe7, 0xfd,
    0xf0,

    /* U+0045 "E" */
    0xfd, 0xfb, 0x6, 0xf, 0xdf, 0xb0, 0x60, 0xff,
    0xfc,

    /* U+0046 "F" */
    0xff, 0xfc, 0x30, 0xff, 0xfc, 0x30, 0xc3, 0x0,

    /* U+0047 "G" */
    0x3e, 0xff, 0x8e, 0xc, 0x18, 0xf1, 0xf3, 0x7e,
    0x7c,

    /* U+0048 "H" */
    0xc7, 0x8f, 0x1e, 0x3f, 0xff, 0xf1, 0xe3, 0xc7,
    0x8c,

    /* U+0049 "I" */
    0xff, 0xf3, 0xc, 0x30, 0xc3, 0xc, 0xff, 0xf0,

    /* U+004A "J" */
    0x7e, 0xfc, 0x18, 0x30, 0x60, 0xc1, 0xa3, 0x7e,
    0xf8,

    /* U+004B "K" */
    0xcf, 0x9b, 0x67, 0xcf, 0x1f, 0x36, 0x66, 0xcf,
    0x8c,

    /* U+004C "L" */
    0xc3, 0xc, 0x30, 0xc3, 0xc, 0x30, 0xff, 0xf0,

    /* U+004D "M" */
    0xcf, 0xdf, 0xbf, 0x7f, 0xfa, 0xf1, 0xe3, 0xc7,
    0x8c,

    /* U+004E "N" */
    0xc7, 0xcf, 0x9f, 0xbd, 0x7b, 0xf3, 0xe7, 0xc7,
    0x8c,

    /* U+004F "O" */
    0x38, 0xfb, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0x7c,
    0x70,

    /* U+0050 "P" */
    0xf9, 0xff, 0x1e, 0x3c, 0x7f, 0xfe, 0x60, 0xc1,
    0x80,

    /* U+0051 "Q" */
    0x38, 0xfb, 0xbe, 0x3c, 0x78, 0xf1, 0xe3, 0xee,
    0xf8, 0xe0, 0xc0, 0xe0,

    /* U+0052 "R" */
    0xf9, 0xfb, 0x36, 0x6f, 0xdf, 0x36, 0x66, 0xcd,
    0x98,

    /* U+0053 "S" */
    0x7d, 0xfb, 0x6, 0x7, 0x3, 0x81, 0xc3, 0xfe,
    0xf8,

    /* U+0054 "T" */
    0xff, 0xfc, 0x60, 0xc1, 0x83, 0x6, 0xc, 0x18,
    0x30,

    /* U+0055 "U" */
    0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xfe,
    0xf8,

    /* U+0056 "V" */
    0xc3, 0x66, 0x66, 0x66, 0x66, 0x24, 0x3c, 0x3c,
    0x3c, 0x18,

    /* U+0057 "W" */
    0xc7, 0x8f, 0x1e, 0x3d, 0x7f, 0xfb, 0xf7, 0xef,
    0xcc,

    /* U+0058 "X" */
    0x66, 0x66, 0x3c, 0x3c, 0x18, 0x3c, 0x3c, 0x66,
    0x66, 0xe7,

    /* U+0059 "Y" */
    0xc3, 0x66, 0x66, 0x34, 0x3c, 0x18, 0x18, 0x18,
    0x18, 0x18,

    /* U+005A "Z" */
    0xff, 0xfc, 0x30, 0xe1, 0x86, 0x18, 0x30, 0xff,
    0xfc,

    /* U+005B "[" */
    0xff, 0xf1, 0x8c, 0x63, 0x18, 0xc6, 0x31, 0x8f,
    0xfc,

    /* U+005C "\\" */
    0xc3, 0x6, 0x18, 0x60, 0xc3, 0xc, 0x38, 0x61,
    0x86, 0xc, 0x30,

    /* U+005D "]" */
    0xff, 0xc6, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x3f,
    0xfc,

    /* U+005E "^" */
    0x18, 0x3c, 0x3c, 0x66, 0x66, 0x42,

    /* U+005F "_" */
    0xff, 0xff,

    /* U+0060 "`" */
    0x67, 0x0,

    /* U+0061 "a" */
    0x79, 0xf0, 0xdf, 0xff, 0x3f, 0xdf,

    /* U+0062 "b" */
    0x1, 0x83, 0x6, 0xf, 0x9f, 0xb1, 0xe3, 0xc7,
    0x9f, 0xf7, 0xc0,

    /* U+0063 "c" */
    0x3e, 0xfb, 0x86, 0xc, 0x1c, 0x1f, 0x9f,

    /* U+0064 "d" */
    0x0, 0x30, 0xc3, 0x7f, 0xfc, 0xf3, 0xcf, 0x37,
    0xdf,

    /* U+0065 "e" */
    0x38, 0xfb, 0x1f, 0xff, 0xf8, 0x1f, 0x1f,

    /* U+0066 "f" */
    0x1e, 0x3e, 0x30, 0xfe, 0xfe, 0x30, 0x30, 0x30,
    0x30, 0x30, 0x30,

    /* U+0067 "g" */
    0x3d, 0xfc, 0xf3, 0xcf, 0x3f, 0xdf, 0xf, 0xff,
    0x80,

    /* U+0068 "h" */
    0x3, 0xc, 0x30, 0xfb, 0xfc, 0xf3, 0xcf, 0x3c,
    0xf3,

    /* U+0069 "i" */
    0x38, 0x38, 0x0, 0xf8, 0xf8, 0x18, 0x18, 0x18,
    0x18, 0x1f, 0xf,

    /* U+006A "j" */
    0x1c, 0x70, 0x3f, 0xfc, 0x30, 0xc3, 0xc, 0x30,
    0xe3, 0xff, 0xe0,

    /* U+006B "k" */
    0x41, 0x83, 0x6, 0xc, 0xdb, 0x34, 0x78, 0xf1,
    0xb3, 0x36, 0x70,

    /* U+006C "l" */
    0xf1, 0xe0, 0xc1, 0x83, 0x6, 0xc, 0x18, 0x30,
    0x7c, 0x78,

    /* U+006D "m" */
    0xfe, 0xff, 0xdb, 0xdb, 0xdb, 0xc3, 0xc3, 0xc3,

    /* U+006E "n" */
    0xfb, 0xfc, 0xf3, 0xcf, 0x3c, 0xf3,

    /* U+006F "o" */
    0x38, 0xfb, 0x1e, 0x3c, 0x78, 0xdf, 0x1c,

    /* U+0070 "p" */
    0xf3, 0xec, 0xf3, 0xcf, 0x3f, 0xfe, 0xc3, 0xc,
    0x0,

    /* U+0071 "q" */
    0x3e, 0xff, 0x9e, 0x3c, 0x78, 0xdf, 0xbf, 0x6,
    0xc, 0x18,

    /* U+0072 "r" */
    0xff, 0xfc, 0x30, 0xc3, 0xc, 0x30,

    /* U+0073 "s" */
    0x7f, 0xfc, 0x38, 0x38, 0x3f, 0xfe,

    /* U+0074 "t" */
    0x30, 0x63, 0xff, 0xf3, 0x6, 0xc, 0x18, 0x3e,
    0x3c,

    /* U+0075 "u" */
    0xcf, 0x3c, 0xf3, 0xcf, 0x3f, 0xdf,

    /* U+0076 "v" */
    0xc3, 0x66, 0x66, 0x66, 0x3c, 0x3c, 0x38, 0x18,

    /* U+0077 "w" */
    0xc3, 0xc3, 0xdb, 0x5a, 0x5a, 0x7e, 0x66, 0x66,

    /* U+0078 "x" */
    0x66, 0x66, 0x3c, 0x18, 0x1c, 0x3c, 0x66, 0x66,

    /* U+0079 "y" */
    0x66, 0x66, 0x66, 0x36, 0x34, 0x3c, 0x1c, 0x18,
    0x18, 0x70, 0xf0,

    /* U+007A "z" */
    0xff, 0xf1, 0x8c, 0x71, 0x8f, 0xff,

    /* U+007B "{" */
    0x1c, 0xf3, 0xc, 0x30, 0xce, 0x38, 0x30, 0xc3,
    0xc, 0x3c, 0x70,

    /* U+007C "|" */
    0xff, 0xff, 0xff, 0xf0,

    /* U+007D "}" */
    0xf1, 0xf0, 0x60, 0xc1, 0x83, 0x3, 0x87, 0x18,
    0x30, 0x60, 0xcf, 0x9e, 0x0,

    /* U+007E "~" */
    0x73, 0x7e, 0xce,

    /* U+00A0 " " */
    0x0,

    /* U+00A1 "¡" */
    0xf0, 0x3f, 0xfc,

    /* U+00A2 "¢" */
    0x18, 0x30, 0xf3, 0xee, 0x18, 0x30, 0x70, 0x7c,
    0x7c, 0x60, 0xc0,

    /* U+00A3 "£" */
    0x3c, 0xf9, 0x83, 0xf, 0xdf, 0x98, 0x30, 0x7e,
    0xfc,

    /* U+00A4 "¤" */
    0x42, 0xff, 0x7e, 0x66, 0x66, 0x7e, 0xff, 0x42,

    /* U+00A5 "¥" */
    0x62, 0x66, 0x24, 0x3c, 0x7e, 0x7e, 0x18, 0x7e,
    0x7e, 0x18,

    /* U+00A6 "¦" */
    0xff, 0xf0, 0xff, 0xf0,

    /* U+00A7 "§" */
    0x3d, 0xf4, 0x18, 0x7b, 0x7c, 0xfb, 0x78, 0x78,
    0xff, 0xf8,

    /* U+00A8 "¨" */
    0xde, 0xc0,

    /* U+00A9 "©" */
    0x38, 0x8a, 0x6d, 0x1a, 0x33, 0x51, 0x1c,

    /* U+00AA "ª" */
    0x78, 0x30, 0xdf, 0x4d, 0xf0,

    /* U+00AB "«" */
    0x1, 0xb4, 0xb6, 0xd9, 0x32, 0x40,

    /* U+00AC "¬" */
    0xff, 0xfc, 0x18, 0x30, 0x60, 0xc0,

    /* U+00AD "­" */
    0xff,

    /* U+00AE "®" */
    0x38, 0x8a, 0xed, 0x5b, 0xb5, 0x51, 0x1c,

    /* U+00AF "¯" */
    0xff, 0xc0,

    /* U+00B0 "°" */
    0x77, 0xf7, 0xf7, 0x0,

    /* U+00B1 "±" */
    0x30, 0x63, 0xff, 0xf3, 0x6, 0xc, 0x7f, 0xfe,

    /* U+00B2 "²" */
    0xeb, 0x36, 0xcf,

    /* U+00B3 "³" */
    0xf3, 0x73, 0x3e,

    /* U+00B4 "´" */
    0x36, 0x0,

    /* U+00B5 "µ" */
    0xcf, 0x3c, 0xf3, 0xcf, 0x3f, 0xff, 0xc3, 0xc,
    0x0,

    /* U+00B6 "¶" */
    0x3f, 0x7f, 0x7b, 0xfb, 0x7b, 0x7b, 0x1b, 0x1b,
    0x1b, 0x1b, 0x1b, 0x1b, 0x1b,

    /* U+00B7 "·" */
    0xff, 0x80,

    /* U+00B8 "¸" */
    0x4f, 0x80,

    /* U+00B9 "¹" */
    0x67, 0x38, 0xc6, 0x7c,

    /* U+00BA "º" */
    0x7b, 0x3c, 0xf3, 0xcd, 0xe0,

    /* U+00BB "»" */
    0x3, 0x64, 0x9b, 0x6f, 0x29, 0x80,

    /* U+00BC "¼" */
    0x66, 0xec, 0x6c, 0x78, 0x18, 0x30, 0x36, 0x6e,
    0x6e, 0x6f, 0xc6,

    /* U+00BD "½" */
    0x65, 0xd9, 0xa3, 0xc1, 0x6, 0xf, 0xb1, 0x65,
    0x9c,

    /* U+00BE "¾" */
    0xe3, 0x26, 0x66, 0x2c, 0xec, 0x18, 0x18, 0x37,
    0x3b, 0x6f, 0x43,

    /* U+00BF "¿" */
    0x31, 0x8c, 0x3, 0x19, 0x98, 0xcf, 0xde,

    /* U+00C0 "À" */
    0x0, 0x18, 0x1c, 0x0, 0x18, 0x3c, 0x3c, 0x3c,
    0x24, 0x66, 0x7e, 0x7e, 0xe6, 0xc3,

    /* U+00C1 "Á" */
    0x0, 0x18, 0x38, 0x0, 0x18, 0x3c, 0x3c, 0x3c,
    0x24, 0x66, 0x7e, 0x7e, 0xe6, 0xc3,

    /* U+00C2 "Â" */
    0x0, 0x18, 0x3c, 0x0, 0x18, 0x3c, 0x3c, 0x3c,
    0x24, 0x66, 0x7e, 0x7e, 0xe6, 0xc3,

    /* U+00C3 "Ã" */
    0x34, 0x3c, 0x2c, 0x0, 0x18, 0x3c, 0x3c, 0x3c,
    0x24, 0x66, 0x7e, 0x7e, 0xe6, 0xc3,

    /* U+00C4 "Ä" */
    0x6c, 0xd8, 0x1, 0xc3, 0x85, 0x1b, 0x36, 0x6c,
    0xfb, 0xfe, 0x3c, 0x60,

    /* U+00C5 "Å" */
    0x38, 0x50, 0xa1, 0xc3, 0x85, 0xb, 0x36, 0x6c,
    0xfb, 0xfe, 0x3c, 0x60,

    /* U+00C6 "Æ" */
    0x1f, 0x1f, 0x3c, 0x3c, 0x2e, 0x6e, 0x7c, 0x7c,
    0xcf, 0xcf,

    /* U+00C7 "Ç" */
    0x3e, 0xff, 0x86, 0xc, 0x18, 0x30, 0x70, 0x7e,
    0x7c, 0x60, 0x43, 0x80,

    /* U+00C8 "È" */
    0x0, 0x60, 0xe0, 0xf, 0xdf, 0xb0, 0x60, 0xfd,
    0xfb, 0x6, 0xf, 0xff, 0xc0,

    /* U+00C9 "É" */
    0x0, 0x61, 0xc0, 0xf, 0xdf, 0xb0, 0x60, 0xfd,
    0xfb, 0x6, 0xf, 0xff, 0xc0,

    /* U+00CA "Ê" */
    0x0, 0x61, 0xe0, 0xf, 0xdf, 0xb0, 0x60, 0xfd,
    0xfb, 0x6, 0xf, 0xff, 0xc0,

    /* U+00CB "Ë" */
    0xd9, 0xb0, 0x7, 0xef, 0xd8, 0x30, 0x7c, 0xf9,
    0x83, 0x7, 0xff, 0xe0,

    /* U+00CC "Ì" */
    0x0, 0xc3, 0x80, 0xff, 0xf3, 0xc, 0x30, 0xc3,
    0xc, 0xff, 0xf0,

    /* U+00CD "Í" */
    0x0, 0xc7, 0x0, 0xff, 0xf3, 0xc, 0x30, 0xc3,
    0xc, 0xff, 0xf0,

    /* U+00CE "Î" */
    0x0, 0xc7, 0x80, 0xff, 0xf3, 0xc, 0x30, 0xc3,
    0xc, 0xff, 0xf0,

    /* U+00CF "Ï" */
    0x6d, 0xb0, 0x3f, 0xfc, 0xc3, 0xc, 0x30, 0xc3,
    0x3f, 0xfc,

    /* U+00D0 "Ð" */
    0x78, 0xf9, 0xbb, 0x3f, 0x7e, 0xd9, 0xb7, 0x7c,
    0xf0,

    /* U+00D1 "Ñ" */
    0x34, 0xf9, 0x60, 0xc, 0x7c, 0xf9, 0xfb, 0xd7,
    0xbf, 0x3e, 0x7c, 0x78, 0xc0,

    /* U+00D2 "Ò" */
    0x30, 0x70, 0x21, 0xc7, 0xd8, 0xf1, 0xe3, 0xc7,
    0x8f, 0x1b, 0xe3, 0x80,

    /* U+00D3 "Ó" */
    0x18, 0x70, 0x81, 0xc7, 0xd8, 0xf1, 0xe3, 0xc7,
    0x8f, 0x1b, 0xe3, 0x80,

    /* U+00D4 "Ô" */
    0x10, 0x70, 0x1, 0xc7, 0xd8, 0xf1, 0xe3, 0xc7,
    0x8f, 0x1b, 0xe3, 0x80,

    /* U+00D5 "Õ" */
    0x34, 0xf9, 0x60, 0x3, 0x8f, 0xb1, 0xe3, 0xc7,
    0x8f, 0x1e, 0x37, 0xc7, 0x0,

    /* U+00D6 "Ö" */
    0x6c, 0xd8, 0x0, 0x3, 0x8f, 0xb1, 0xe3, 0xc7,
    0x8f, 0x1e, 0x37, 0xc7, 0x0,

    /* U+00D7 "×" */
    0x3, 0x37, 0x8c, 0x7b, 0x30, 0x0,

    /* U+00D8 "Ø" */
    0x3c, 0xfb, 0x3e, 0x7d, 0x7e, 0xf9, 0xf3, 0x7d,
    0xf0,

    /* U+00D9 "Ù" */
    0x0, 0x60, 0xe0, 0xc, 0x78, 0xf1, 0xe3, 0xc7,
    0x8f, 0x1e, 0x3f, 0xef, 0x80,

    /* U+00DA "Ú" */
    0x0, 0x30, 0xe0, 0xc, 0x78, 0xf1, 0xe3, 0xc7,
    0x8f, 0x1e, 0x3f, 0xef, 0x80,

    /* U+00DB "Û" */
    0x0, 0x71, 0xb0, 0xc, 0x78, 0xf1, 0xe3, 0xc7,
    0x8f, 0x1e, 0x3f, 0xef, 0x80,

    /* U+00DC "Ü" */
    0x6c, 0xd8, 0x0, 0xc, 0x78, 0xf1, 0xe3, 0xc7,
    0x8f, 0x1e, 0x3f, 0xef, 0x80,

    /* U+00DD "Ý" */
    0x0, 0xc, 0x18, 0x0, 0xc3, 0x66, 0x66, 0x34,
    0x3c, 0x18, 0x18, 0x18, 0x18, 0x18,

    /* U+00DE "Þ" */
    0xc1, 0xf3, 0xf6, 0x3c, 0x78, 0xff, 0x7c, 0xc1,
    0x80,

    /* U+00DF "ß" */
    0x79, 0xfb, 0x36, 0x6d, 0x9b, 0x37, 0x67, 0xc7,
    0xbf, 0x70,

    /* U+00E0 "à" */
    0x30, 0xc0, 0x1e, 0x7c, 0x37, 0xff, 0xcf, 0xf7,
    0xc0,

    /* U+00E1 "á" */
    0x10, 0xc0, 0x1e, 0x7c, 0x37, 0xff, 0xcf, 0xf7,
    0xc0,

    /* U+00E2 "â" */
    0x31, 0xe0, 0x1e, 0x7c, 0x37, 0xff, 0xcf, 0xf7,
    0xc0,

    /* U+00E3 "ã" */
    0x69, 0xe5, 0x9e, 0x7c, 0x37, 0xff, 0xcf, 0xf7,
    0xc0,

    /* U+00E4 "ä" */
    0x6d, 0xb0, 0x1e, 0x7c, 0x37, 0xff, 0xcf, 0xf7,
    0xc0,

    /* U+00E5 "å" */
    0x38, 0xe0, 0x1e, 0x7c, 0x37, 0xff, 0xcf, 0xf7,
    0xc0,

    /* U+00E6 "æ" */
    0x6e, 0x7e, 0x1a, 0x7e, 0xff, 0xd8, 0xfe, 0x7e,

    /* U+00E7 "ç" */
    0x3e, 0xfb, 0x86, 0xc, 0x1c, 0x1f, 0x9f, 0x18,
    0x10, 0xe0,

    /* U+00E8 "è" */
    0x30, 0x70, 0x1, 0xc7, 0xd8, 0xff, 0xff, 0xc0,
    0xf8, 0xf8,

    /* U+00E9 "é" */
    0x18, 0x70, 0x1, 0xc7, 0xd8, 0xff, 0xff, 0xc0,
    0xf8, 0xf8,

    /* U+00EA "ê" */
    0x18, 0xd8, 0x1, 0xc7, 0xd8, 0xff, 0xff, 0xc0,
    0xf8, 0xf8,

    /* U+00EB "ë" */
    0x6c, 0xd8, 0x1, 0xc7, 0xd8, 0xff, 0xff, 0xc0,
    0xf8, 0xf0,

    /* U+00EC "ì" */
    0x0, 0xe0, 0xe0, 0xf, 0x1e, 0xc, 0x18, 0x30,
    0x60, 0xf8, 0xf0,

    /* U+00ED "í" */
    0x0, 0x30, 0xc0, 0xf, 0x1e, 0xc, 0x18, 0x30,
    0x60, 0xf8, 0xf0,

    /* U+00EE "î" */
    0x0, 0x61, 0xe0, 0xf, 0x1e, 0xc, 0x18, 0x30,
    0x60, 0xf8, 0xf0,

    /* U+00EF "ï" */
    0x6c, 0xd8, 0x7, 0xcf, 0x83, 0x6, 0xc, 0x18,
    0x3c, 0x38,

    /* U+00F0 "ð" */
    0x10, 0x70, 0x79, 0xe0, 0x67, 0xff, 0xe3, 0xc7,
    0x9d, 0xf1, 0xc0,

    /* U+00F1 "ñ" */
    0x69, 0xe5, 0xbe, 0xff, 0x3c, 0xf3, 0xcf, 0x3c,
    0xc0,

    /* U+00F2 "ò" */
    0x30, 0x70, 0x1, 0xc7, 0xd8, 0xf1, 0xe3, 0xc6,
    0xf8, 0xe0,

    /* U+00F3 "ó" */
    0x18, 0x70, 0x1, 0xc7, 0xd8, 0xf1, 0xe3, 0xc6,
    0xf8, 0xe0,

    /* U+00F4 "ô" */
    0x38, 0xd8, 0x1, 0xc7, 0xd8, 0xf1, 0xe3, 0xc6,
    0xf8, 0xe0,

    /* U+00F5 "õ" */
    0x34, 0xf9, 0x21, 0xc7, 0xd8, 0xf1, 0xe3, 0xc6,
    0xf8, 0xe0,

    /* U+00F6 "ö" */
    0x6c, 0xd8, 0x1, 0xc7, 0xd8, 0xf1, 0xe3, 0xc6,
    0xf8, 0xe0,

    /* U+00F7 "÷" */
    0x30, 0x60, 0x7, 0xff, 0xe0, 0xc, 0x18,

    /* U+00F8 "ø" */
    0x3e, 0xfb, 0x3e, 0xff, 0x7c, 0xdf, 0x7c,

    /* U+00F9 "ù" */
    0x1, 0xc3, 0x0, 0xcf, 0x3c, 0xf3, 0xcf, 0x3f,
    0xdf,

    /* U+00FA "ú" */
    0x0, 0xc3, 0x0, 0xcf, 0x3c, 0xf3, 0xcf, 0x3f,
    0xdf,

    /* U+00FB "û" */
    0x0, 0xc7, 0x80, 0xcf, 0x3c, 0xf3, 0xcf, 0x3f,
    0xdf,

    /* U+00FC "ü" */
    0xcf, 0x30, 0x33, 0xcf, 0x3c, 0xf3, 0xcf, 0xf7,
    0xc0,

    /* U+00FD "ý" */
    0x0, 0x1c, 0x38, 0x0, 0x66, 0x66, 0x66, 0x36,
    0x34, 0x3c, 0x1c, 0x18, 0x18, 0x70, 0xf0,

    /* U+00FE "þ" */
    0x3, 0xc, 0x30, 0xfb, 0xec, 0xf3, 0xcf, 0x3f,
    0xfe, 0xc3, 0xc, 0x0,

    /* U+00FF "ÿ" */
    0x6c, 0xd8, 0x6, 0x36, 0x4d, 0x9b, 0x16, 0x38,
    0x70, 0x61, 0x8f, 0x1c, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 128, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 128, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2, .adv_w = 128, .box_w = 2, .box_h = 10, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 5, .adv_w = 128, .box_w = 5, .box_h = 4, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 8, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 17, .adv_w = 128, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 27, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 37, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 46, .adv_w = 128, .box_w = 2, .box_h = 5, .ofs_x = 3, .ofs_y = 6},
    {.bitmap_index = 48, .adv_w = 128, .box_w = 5, .box_h = 15, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 58, .adv_w = 128, .box_w = 5, .box_h = 15, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 68, .adv_w = 128, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 73, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 80, .adv_w = 128, .box_w = 4, .box_h = 5, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 83, .adv_w = 128, .box_w = 4, .box_h = 2, .ofs_x = 2, .ofs_y = 3},
    {.bitmap_index = 84, .adv_w = 128, .box_w = 3, .box_h = 3, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 86, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 97, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 105, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 114, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 123, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 131, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 140, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 148, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 157, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 165, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 174, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 183, .adv_w = 128, .box_w = 3, .box_h = 8, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 186, .adv_w = 128, .box_w = 4, .box_h = 10, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 191, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 198, .adv_w = 128, .box_w = 7, .box_h = 5, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 203, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 210, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 218, .adv_w = 128, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 231, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 241, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 250, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 259, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 268, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 277, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 285, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 294, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 303, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 311, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 320, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 329, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 337, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 346, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 355, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 364, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 373, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 385, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 394, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 403, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 412, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 421, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 431, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 440, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 450, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 460, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 469, .adv_w = 128, .box_w = 5, .box_h = 14, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 478, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 489, .adv_w = 128, .box_w = 5, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 498, .adv_w = 128, .box_w = 8, .box_h = 6, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 504, .adv_w = 128, .box_w = 8, .box_h = 2, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 506, .adv_w = 128, .box_w = 4, .box_h = 3, .ofs_x = 2, .ofs_y = 8},
    {.bitmap_index = 508, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 514, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 525, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 532, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 541, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 548, .adv_w = 128, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 559, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 568, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 577, .adv_w = 128, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 588, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 599, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 610, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 620, .adv_w = 128, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 628, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 634, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 641, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 650, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 660, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 666, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 672, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 681, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 687, .adv_w = 128, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 695, .adv_w = 128, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 703, .adv_w = 128, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 711, .adv_w = 128, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 722, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 728, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 739, .adv_w = 128, .box_w = 2, .box_h = 14, .ofs_x = 3, .ofs_y = -3},
    {.bitmap_index = 743, .adv_w = 128, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 756, .adv_w = 128, .box_w = 8, .box_h = 3, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 759, .adv_w = 128, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 760, .adv_w = 128, .box_w = 2, .box_h = 11, .ofs_x = 3, .ofs_y = -3},
    {.bitmap_index = 763, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 774, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 783, .adv_w = 128, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 791, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 801, .adv_w = 128, .box_w = 2, .box_h = 14, .ofs_x = 3, .ofs_y = -3},
    {.bitmap_index = 805, .adv_w = 128, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 815, .adv_w = 128, .box_w = 5, .box_h = 2, .ofs_x = 1, .ofs_y = 9},
    {.bitmap_index = 817, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 824, .adv_w = 128, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 829, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 835, .adv_w = 128, .box_w = 7, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 841, .adv_w = 128, .box_w = 4, .box_h = 2, .ofs_x = 2, .ofs_y = 3},
    {.bitmap_index = 842, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 849, .adv_w = 128, .box_w = 5, .box_h = 2, .ofs_x = 2, .ofs_y = 9},
    {.bitmap_index = 851, .adv_w = 128, .box_w = 5, .box_h = 5, .ofs_x = 2, .ofs_y = 7},
    {.bitmap_index = 855, .adv_w = 128, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 863, .adv_w = 128, .box_w = 4, .box_h = 6, .ofs_x = 2, .ofs_y = 4},
    {.bitmap_index = 866, .adv_w = 128, .box_w = 4, .box_h = 6, .ofs_x = 2, .ofs_y = 4},
    {.bitmap_index = 869, .adv_w = 128, .box_w = 4, .box_h = 3, .ofs_x = 2, .ofs_y = 8},
    {.bitmap_index = 871, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 880, .adv_w = 128, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 893, .adv_w = 128, .box_w = 3, .box_h = 3, .ofs_x = 3, .ofs_y = 3},
    {.bitmap_index = 895, .adv_w = 128, .box_w = 3, .box_h = 3, .ofs_x = 3, .ofs_y = -3},
    {.bitmap_index = 897, .adv_w = 128, .box_w = 5, .box_h = 6, .ofs_x = 2, .ofs_y = 4},
    {.bitmap_index = 901, .adv_w = 128, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 906, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 912, .adv_w = 128, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 923, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 932, .adv_w = 128, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 943, .adv_w = 128, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 950, .adv_w = 128, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 964, .adv_w = 128, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 978, .adv_w = 128, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 992, .adv_w = 128, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1006, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1018, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1030, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1040, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1052, .adv_w = 128, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1065, .adv_w = 128, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1078, .adv_w = 128, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1091, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1103, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1114, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1125, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1136, .adv_w = 128, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1146, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1155, .adv_w = 128, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1168, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1180, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1192, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1204, .adv_w = 128, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1217, .adv_w = 128, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1230, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 1236, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1245, .adv_w = 128, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1258, .adv_w = 128, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1271, .adv_w = 128, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1284, .adv_w = 128, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1297, .adv_w = 128, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1311, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1320, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1330, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1339, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1348, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1357, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1366, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1375, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1384, .adv_w = 128, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1392, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1402, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1412, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1422, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1432, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1442, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1453, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1464, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1475, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1485, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1496, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1505, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1515, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1525, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1535, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1545, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1555, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1562, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1569, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1578, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1587, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1596, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1605, .adv_w = 128, .box_w = 8, .box_h = 15, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1620, .adv_w = 128, .box_w = 6, .box_h = 15, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1632, .adv_w = 128, .box_w = 7, .box_h = 14, .ofs_x = 0, .ofs_y = -3}
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
const lv_font_t UbuntuMonoB16 = {
#else
lv_font_t UbuntuMonoB16 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 18,          /*The maximum line height required by the font*/
    .base_line = 4,             /*Baseline measured from the bottom of the line*/
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



#endif /*#if UBUNTUMONOB16*/

