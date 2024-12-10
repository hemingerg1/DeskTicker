/*******************************************************************************
 * Size: 100 px
 * Bpp: 1
 * Opts: --bpp 1 --size 100 --no-compress --font Montserrat-Bold.ttf --symbols 0123456789: --format lvgl -o lv_montserrat_bold_100.c
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl.h"
#endif

#ifndef LV_MONTSERRAT_BOLD_100
#define LV_MONTSERRAT_BOLD_100 1
#endif

#if LV_MONTSERRAT_BOLD_100

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0030 "0" */
    0x0, 0x0, 0x0, 0xff, 0xf0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xff, 0xff, 0xf0, 0x0, 0x0, 0x0,
    0x0, 0x3f, 0xff, 0xff, 0xc0, 0x0, 0x0, 0x0,
    0xf, 0xff, 0xff, 0xff, 0x0, 0x0, 0x0, 0x3,
    0xff, 0xff, 0xff, 0xfc, 0x0, 0x0, 0x0, 0x7f,
    0xff, 0xff, 0xff, 0xe0, 0x0, 0x0, 0xf, 0xff,
    0xff, 0xff, 0xff, 0x0, 0x0, 0x3, 0xff, 0xff,
    0xff, 0xff, 0xfc, 0x0, 0x0, 0x7f, 0xff, 0xff,
    0xff, 0xff, 0xe0, 0x0, 0x7, 0xff, 0xff, 0xff,
    0xff, 0xfe, 0x0, 0x0, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xf0, 0x0, 0x1f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x80, 0x3, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xfc, 0x0, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xc0, 0x7, 0xff, 0xff, 0xc0, 0x3f, 0xff, 0xfe,
    0x0, 0xff, 0xff, 0xf0, 0x0, 0xff, 0xff, 0xe0,
    0xf, 0xff, 0xfc, 0x0, 0x3, 0xff, 0xff, 0x0,
    0xff, 0xff, 0x80, 0x0, 0x1f, 0xff, 0xf0, 0x1f,
    0xff, 0xf0, 0x0, 0x1, 0xff, 0xff, 0x81, 0xff,
    0xff, 0x0, 0x0, 0xf, 0xff, 0xf8, 0x3f, 0xff,
    0xe0, 0x0, 0x0, 0x7f, 0xff, 0xc3, 0xff, 0xfe,
    0x0, 0x0, 0x7, 0xff, 0xfc, 0x3f, 0xff, 0xc0,
    0x0, 0x0, 0x3f, 0xff, 0xc7, 0xff, 0xfc, 0x0,
    0x0, 0x3, 0xff, 0xfe, 0x7f, 0xff, 0x80, 0x0,
    0x0, 0x3f, 0xff, 0xe7, 0xff, 0xf8, 0x0, 0x0,
    0x1, 0xff, 0xfe, 0x7f, 0xff, 0x80, 0x0, 0x0,
    0x1f, 0xff, 0xe7, 0xff, 0xf8, 0x0, 0x0, 0x1,
    0xff, 0xfe, 0xff, 0xff, 0x80, 0x0, 0x0, 0x1f,
    0xff, 0xef, 0xff, 0xf0, 0x0, 0x0, 0x0, 0xff,
    0xff, 0xff, 0xff, 0x0, 0x0, 0x0, 0xf, 0xff,
    0xff, 0xff, 0xf0, 0x0, 0x0, 0x0, 0xff, 0xff,
    0xff, 0xff, 0x0, 0x0, 0x0, 0xf, 0xff, 0xff,
    0xff, 0xf0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xff,
    0xff, 0x0, 0x0, 0x0, 0xf, 0xff, 0xff, 0xff,
    0xf0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xff, 0xff,
    0x0, 0x0, 0x0, 0xf, 0xff, 0xff, 0xff, 0xf0,
    0x0, 0x0, 0x0, 0xff, 0xff, 0xff, 0xff, 0x0,
    0x0, 0x0, 0xf, 0xff, 0xff, 0xff, 0xf0, 0x0,
    0x0, 0x0, 0xff, 0xff, 0xff, 0xff, 0x0, 0x0,
    0x0, 0xf, 0xff, 0xff, 0xff, 0xf0, 0x0, 0x0,
    0x0, 0xff, 0xff, 0xff, 0xff, 0x0, 0x0, 0x0,
    0xf, 0xff, 0xff, 0xff, 0xf0, 0x0, 0x0, 0x0,
    0xff, 0xff, 0xff, 0xff, 0x80, 0x0, 0x0, 0x1f,
    0xff, 0xe7, 0xff, 0xf8, 0x0, 0x0, 0x1, 0xff,
    0xfe, 0x7f, 0xff, 0x80, 0x0, 0x0, 0x1f, 0xff,
    0xe7, 0xff, 0xf8, 0x0, 0x0, 0x1, 0xff, 0xfe,
    0x7f, 0xff, 0x80, 0x0, 0x0, 0x3f, 0xff, 0xe7,
    0xff, 0xfc, 0x0, 0x0, 0x3, 0xff, 0xfe, 0x3f,
    0xff, 0xc0, 0x0, 0x0, 0x3f, 0xff, 0xc3, 0xff,
    0xfe, 0x0, 0x0, 0x7, 0xff, 0xfc, 0x3f, 0xff,
    0xe0, 0x0, 0x0, 0x7f, 0xff, 0xc1, 0xff, 0xff,
    0x0, 0x0, 0xf, 0xff, 0xf8, 0x1f, 0xff, 0xf0,
    0x0, 0x1, 0xff, 0xff, 0x80, 0xff, 0xff, 0x80,
    0x0, 0x1f, 0xff, 0xf0, 0xf, 0xff, 0xfc, 0x0,
    0x3, 0xff, 0xff, 0x0, 0xff, 0xff, 0xf0, 0x0,
    0xff, 0xff, 0xf0, 0x7, 0xff, 0xff, 0xc0, 0x3f,
    0xff, 0xfe, 0x0, 0x3f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xc0, 0x3, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xfc, 0x0, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x80, 0x0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0,
    0x0, 0x7, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x0,
    0x0, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x0,
    0x3, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x0, 0x0,
    0xf, 0xff, 0xff, 0xff, 0xff, 0x0, 0x0, 0x0,
    0x7f, 0xff, 0xff, 0xff, 0xe0, 0x0, 0x0, 0x3,
    0xff, 0xff, 0xff, 0xfc, 0x0, 0x0, 0x0, 0xf,
    0xff, 0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0x3f,
    0xff, 0xff, 0xc0, 0x0, 0x0, 0x0, 0x0, 0xff,
    0xff, 0xf0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff,
    0xf0, 0x0, 0x0, 0x0,

    /* U+0031 "1" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xfc, 0x0, 0xf, 0xff, 0xf0, 0x0, 0x3f, 0xff,
    0xc0, 0x0, 0xff, 0xff, 0x0, 0x3, 0xff, 0xfc,
    0x0, 0xf, 0xff, 0xf0, 0x0, 0x3f, 0xff, 0xc0,
    0x0, 0xff, 0xff, 0x0, 0x3, 0xff, 0xfc, 0x0,
    0xf, 0xff, 0xf0, 0x0, 0x3f, 0xff, 0xc0, 0x0,
    0xff, 0xff, 0x0, 0x3, 0xff, 0xfc, 0x0, 0xf,
    0xff, 0xf0, 0x0, 0x3f, 0xff, 0xc0, 0x0, 0xff,
    0xff, 0x0, 0x3, 0xff, 0xfc, 0x0, 0xf, 0xff,
    0xf0, 0x0, 0x3f, 0xff, 0xc0, 0x0, 0xff, 0xff,
    0x0, 0x3, 0xff, 0xfc, 0x0, 0xf, 0xff, 0xf0,
    0x0, 0x3f, 0xff, 0xc0, 0x0, 0xff, 0xff, 0x0,
    0x3, 0xff, 0xfc, 0x0, 0xf, 0xff, 0xf0, 0x0,
    0x3f, 0xff, 0xc0, 0x0, 0xff, 0xff, 0x0, 0x3,
    0xff, 0xfc, 0x0, 0xf, 0xff, 0xf0, 0x0, 0x3f,
    0xff, 0xc0, 0x0, 0xff, 0xff, 0x0, 0x3, 0xff,
    0xfc, 0x0, 0xf, 0xff, 0xf0, 0x0, 0x3f, 0xff,
    0xc0, 0x0, 0xff, 0xff, 0x0, 0x3, 0xff, 0xfc,
    0x0, 0xf, 0xff, 0xf0, 0x0, 0x3f, 0xff, 0xc0,
    0x0, 0xff, 0xff, 0x0, 0x3, 0xff, 0xfc, 0x0,
    0xf, 0xff, 0xf0, 0x0, 0x3f, 0xff, 0xc0, 0x0,
    0xff, 0xff, 0x0, 0x3, 0xff, 0xfc, 0x0, 0xf,
    0xff, 0xf0, 0x0, 0x3f, 0xff, 0xc0, 0x0, 0xff,
    0xff, 0x0, 0x3, 0xff, 0xfc, 0x0, 0xf, 0xff,
    0xf0, 0x0, 0x3f, 0xff, 0xc0, 0x0, 0xff, 0xff,
    0x0, 0x3, 0xff, 0xfc, 0x0, 0xf, 0xff, 0xf0,
    0x0, 0x3f, 0xff, 0xc0, 0x0, 0xff, 0xff, 0x0,
    0x3, 0xff, 0xfc, 0x0, 0xf, 0xff, 0xf0, 0x0,
    0x3f, 0xff, 0xc0,

    /* U+0032 "2" */
    0x0, 0x0, 0x7, 0xff, 0xc0, 0x0, 0x0, 0x0,
    0x0, 0xff, 0xff, 0xfc, 0x0, 0x0, 0x0, 0x7,
    0xff, 0xff, 0xff, 0x80, 0x0, 0x0, 0x1f, 0xff,
    0xff, 0xff, 0xe0, 0x0, 0x0, 0x7f, 0xff, 0xff,
    0xff, 0xf0, 0x0, 0x1, 0xff, 0xff, 0xff, 0xff,
    0xfc, 0x0, 0x3, 0xff, 0xff, 0xff, 0xff, 0xfe,
    0x0, 0xf, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0,
    0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x3f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x7f, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xc0, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xe0, 0x7f, 0xff, 0xf8, 0x3, 0xff,
    0xff, 0xf0, 0x1f, 0xff, 0xc0, 0x0, 0x7f, 0xff,
    0xf0, 0x7, 0xff, 0x0, 0x0, 0x3f, 0xff, 0xf0,
    0x3, 0xfe, 0x0, 0x0, 0x1f, 0xff, 0xf8, 0x0,
    0xfc, 0x0, 0x0, 0xf, 0xff, 0xf8, 0x0, 0x78,
    0x0, 0x0, 0xf, 0xff, 0xf8, 0x0, 0x10, 0x0,
    0x0, 0x7, 0xff, 0xf8, 0x0, 0x0, 0x0, 0x0,
    0x7, 0xff, 0xf8, 0x0, 0x0, 0x0, 0x0, 0x7,
    0xff, 0xf8, 0x0, 0x0, 0x0, 0x0, 0x7, 0xff,
    0xf8, 0x0, 0x0, 0x0, 0x0, 0x7, 0xff, 0xf8,
    0x0, 0x0, 0x0, 0x0, 0x7, 0xff, 0xf8, 0x0,
    0x0, 0x0, 0x0, 0xf, 0xff, 0xf8, 0x0, 0x0,
    0x0, 0x0, 0xf, 0xff, 0xf0, 0x0, 0x0, 0x0,
    0x0, 0xf, 0xff, 0xf0, 0x0, 0x0, 0x0, 0x0,
    0x1f, 0xff, 0xf0, 0x0, 0x0, 0x0, 0x0, 0x3f,
    0xff, 0xf0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xff,
    0xe0, 0x0, 0x0, 0x0, 0x0, 0x7f, 0xff, 0xe0,
    0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xc0, 0x0,
    0x0, 0x0, 0x1, 0xff, 0xff, 0x80, 0x0, 0x0,
    0x0, 0x3, 0xff, 0xff, 0x80, 0x0, 0x0, 0x0,
    0x7, 0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0xf,
    0xff, 0xfe, 0x0, 0x0, 0x0, 0x0, 0x1f, 0xff,
    0xfc, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xff, 0xfc,
    0x0, 0x0, 0x0, 0x0, 0x7f, 0xff, 0xf8, 0x0,
    0x0, 0x0, 0x0, 0xff, 0xff, 0xf0, 0x0, 0x0,
    0x0, 0x1, 0xff, 0xff, 0xe0, 0x0, 0x0, 0x0,
    0x3, 0xff, 0xff, 0xc0, 0x0, 0x0, 0x0, 0x7,
    0xff, 0xff, 0x80, 0x0, 0x0, 0x0, 0xf, 0xff,
    0xff, 0x0, 0x0, 0x0, 0x0, 0x1f, 0xff, 0xfe,
    0x0, 0x0, 0x0, 0x0, 0x3f, 0xff, 0xfc, 0x0,
    0x0, 0x0, 0x0, 0x7f, 0xff, 0xf0, 0x0, 0x0,
    0x0, 0x0, 0xff, 0xff, 0xe0, 0x0, 0x0, 0x0,
    0x1, 0xff, 0xff, 0xc0, 0x0, 0x0, 0x0, 0x3,
    0xff, 0xff, 0x80, 0x0, 0x0, 0x0, 0xf, 0xff,
    0xff, 0x0, 0x0, 0x0, 0x0, 0x1f, 0xff, 0xfe,
    0x0, 0x0, 0x0, 0x0, 0x3f, 0xff, 0xfc, 0x0,
    0x0, 0x0, 0x0, 0x7f, 0xff, 0xf8, 0x0, 0x0,
    0x0, 0x0, 0xff, 0xff, 0xf0, 0x0, 0x0, 0x0,
    0x1, 0xff, 0xff, 0xe0, 0x0, 0x0, 0x0, 0x3,
    0xff, 0xff, 0xc0, 0x0, 0x0, 0x0, 0x7, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x1f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x1f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x1f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x1f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff,

    /* U+0033 "3" */
    0xf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xf,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xf, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xf8, 0xf, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf8, 0xf, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xf8, 0xf, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xf8, 0xf, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xf8, 0xf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8,
    0xf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xf,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xf, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xf8, 0xf, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf0, 0xf, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xe0, 0x0, 0x0, 0x0, 0x0, 0x7f,
    0xff, 0xc0, 0x0, 0x0, 0x0, 0x0, 0x7f, 0xff,
    0xc0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0x80,
    0x0, 0x0, 0x0, 0x1, 0xff, 0xff, 0x0, 0x0,
    0x0, 0x0, 0x3, 0xff, 0xfe, 0x0, 0x0, 0x0,
    0x0, 0x7, 0xff, 0xfc, 0x0, 0x0, 0x0, 0x0,
    0xf, 0xff, 0xf8, 0x0, 0x0, 0x0, 0x0, 0x1f,
    0xff, 0xf0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xff,
    0xe0, 0x0, 0x0, 0x0, 0x0, 0x7f, 0xff, 0xe0,
    0x0, 0x0, 0x0, 0x0, 0x7f, 0xff, 0xc0, 0x0,
    0x0, 0x0, 0x0, 0xff, 0xff, 0x80, 0x0, 0x0,
    0x0, 0x1, 0xff, 0xff, 0x0, 0x0, 0x0, 0x0,
    0x3, 0xff, 0xfe, 0x0, 0x0, 0x0, 0x0, 0x7,
    0xff, 0xfc, 0x0, 0x0, 0x0, 0x0, 0xf, 0xff,
    0xf8, 0x0, 0x0, 0x0, 0x0, 0x1f, 0xff, 0xff,
    0x80, 0x0, 0x0, 0x0, 0x1f, 0xff, 0xff, 0xf0,
    0x0, 0x0, 0x0, 0x1f, 0xff, 0xff, 0xfc, 0x0,
    0x0, 0x0, 0x1f, 0xff, 0xff, 0xff, 0x0, 0x0,
    0x0, 0x1f, 0xff, 0xff, 0xff, 0x80, 0x0, 0x0,
    0x1f, 0xff, 0xff, 0xff, 0xc0, 0x0, 0x0, 0x1f,
    0xff, 0xff, 0xff, 0xe0, 0x0, 0x0, 0x1f, 0xff,
    0xff, 0xff, 0xf0, 0x0, 0x0, 0x1f, 0xff, 0xff,
    0xff, 0xf8, 0x0, 0x0, 0x1f, 0xff, 0xff, 0xff,
    0xf8, 0x0, 0x0, 0x1f, 0xff, 0xff, 0xff, 0xfc,
    0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xfc, 0x0,
    0x0, 0x0, 0x0, 0x1f, 0xff, 0xfe, 0x0, 0x0,
    0x0, 0x0, 0x7, 0xff, 0xfe, 0x0, 0x0, 0x0,
    0x0, 0x3, 0xff, 0xfe, 0x0, 0x0, 0x0, 0x0,
    0x1, 0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0x1,
    0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff,
    0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xff,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xff, 0xff, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xff, 0xff, 0x0, 0x0, 0x0, 0x0,
    0x1, 0xff, 0xff, 0x3, 0x80, 0x0, 0x0, 0x1,
    0xff, 0xff, 0x3, 0xc0, 0x0, 0x0, 0x3, 0xff,
    0xfe, 0x7, 0xf0, 0x0, 0x0, 0x3, 0xff, 0xfe,
    0x7, 0xfc, 0x0, 0x0, 0xf, 0xff, 0xfe, 0xf,
    0xff, 0x80, 0x0, 0x1f, 0xff, 0xfc, 0xf, 0xff,
    0xf8, 0x0, 0xff, 0xff, 0xfc, 0x1f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xf8, 0x3f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xf0, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xe0, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0,
    0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x7f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0x0, 0x1f, 0xff,
    0xff, 0xff, 0xff, 0xfe, 0x0, 0x7, 0xff, 0xff,
    0xff, 0xff, 0xfc, 0x0, 0x1, 0xff, 0xff, 0xff,
    0xff, 0xf0, 0x0, 0x0, 0x3f, 0xff, 0xff, 0xff,
    0xc0, 0x0, 0x0, 0x3, 0xff, 0xff, 0xfe, 0x0,
    0x0, 0x0, 0x0, 0xf, 0xff, 0xc0, 0x0, 0x0,

    /* U+0034 "4" */
    0x0, 0x0, 0x0, 0x0, 0x7f, 0xff, 0xc0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x7f, 0xff, 0xe0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x3f, 0xff, 0xe0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x3f, 0xff, 0xe0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x3f, 0xff, 0xf0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x3f, 0xff, 0xf0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1f, 0xff, 0xf0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1f, 0xff, 0xf0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1f, 0xff, 0xf8, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1f, 0xff, 0xf8, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xf, 0xff, 0xf8, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xf, 0xff, 0xf8, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xf, 0xff, 0xfc, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xf, 0xff, 0xfc, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x7, 0xff, 0xfc, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x7, 0xff, 0xfc, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x7, 0xff, 0xfe, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x3, 0xff, 0xfe, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x3, 0xff, 0xfe, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x3, 0xff, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x3, 0xff, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1, 0xff, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1, 0xff, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1, 0xff, 0xff, 0x80,
    0x0, 0x0, 0x0, 0x0, 0x1, 0xff, 0xff, 0x80,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0x80,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0x80,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xc0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xc0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x7f, 0xff, 0xc0,
    0x1f, 0xff, 0xe0, 0x0, 0x0, 0x7f, 0xff, 0xe0,
    0xf, 0xff, 0xf0, 0x0, 0x0, 0x7f, 0xff, 0xe0,
    0x7, 0xff, 0xf8, 0x0, 0x0, 0x7f, 0xff, 0xe0,
    0x3, 0xff, 0xfc, 0x0, 0x0, 0x3f, 0xff, 0xe0,
    0x1, 0xff, 0xfe, 0x0, 0x0, 0x3f, 0xff, 0xf0,
    0x0, 0xff, 0xff, 0x0, 0x0, 0x3f, 0xff, 0xf0,
    0x0, 0x7f, 0xff, 0x80, 0x0, 0x3f, 0xff, 0xf0,
    0x0, 0x3f, 0xff, 0xc0, 0x0, 0x1f, 0xff, 0xf0,
    0x0, 0x1f, 0xff, 0xe0, 0x0, 0x1f, 0xff, 0xf8,
    0x0, 0xf, 0xff, 0xf0, 0x0, 0x1f, 0xff, 0xf8,
    0x0, 0x7, 0xff, 0xf8, 0x0, 0xf, 0xff, 0xf8,
    0x0, 0x3, 0xff, 0xfc, 0x0, 0xf, 0xff, 0xfc,
    0x0, 0x1, 0xff, 0xfe, 0x0, 0xf, 0xff, 0xfc,
    0x0, 0x0, 0xff, 0xff, 0x0, 0xf, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x3, 0xff, 0xfc, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x1, 0xff, 0xfe, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x7f, 0xff, 0x80, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x3f, 0xff, 0xc0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1f, 0xff, 0xe0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xf, 0xff, 0xf0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x7, 0xff, 0xf8, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x3, 0xff, 0xfc, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1, 0xff, 0xfe, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x7f, 0xff, 0x80,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xff, 0xc0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x1f, 0xff, 0xe0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xff, 0xf0,
    0x0,

    /* U+0035 "5" */
    0x0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x1,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x3, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x80, 0x7, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x0, 0xf, 0xff, 0xff, 0xff,
    0xff, 0xfe, 0x0, 0x1f, 0xff, 0xff, 0xff, 0xff,
    0xfc, 0x0, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xf8,
    0x0, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x0,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x1, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xc0, 0x7, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x80, 0xf, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x0, 0x1f, 0xff, 0xff, 0xff, 0xff,
    0xfe, 0x0, 0x3f, 0xff, 0x80, 0x0, 0x0, 0x0,
    0x0, 0x7f, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xff, 0xfe, 0x0, 0x0, 0x0, 0x0, 0x1, 0xff,
    0xfc, 0x0, 0x0, 0x0, 0x0, 0x3, 0xff, 0xf8,
    0x0, 0x0, 0x0, 0x0, 0x7, 0xff, 0xe0, 0x0,
    0x0, 0x0, 0x0, 0xf, 0xff, 0xc0, 0x0, 0x0,
    0x0, 0x0, 0x1f, 0xff, 0x80, 0x0, 0x0, 0x0,
    0x0, 0x7f, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xff, 0xfe, 0x0, 0x0, 0x0, 0x0, 0x1, 0xff,
    0xfc, 0x0, 0x0, 0x0, 0x0, 0x3, 0xff, 0xf8,
    0x0, 0x0, 0x0, 0x0, 0x7, 0xff, 0xf0, 0x0,
    0x0, 0x0, 0x0, 0xf, 0xff, 0xe0, 0x0, 0x0,
    0x0, 0x0, 0x1f, 0xff, 0xff, 0xfe, 0x0, 0x0,
    0x0, 0x3f, 0xff, 0xff, 0xff, 0xe0, 0x0, 0x0,
    0x7f, 0xff, 0xff, 0xff, 0xf8, 0x0, 0x0, 0xff,
    0xff, 0xff, 0xff, 0xfc, 0x0, 0x1, 0xff, 0xff,
    0xff, 0xff, 0xfe, 0x0, 0x7, 0xff, 0xff, 0xff,
    0xff, 0xfe, 0x0, 0xf, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x0, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x0, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0,
    0x7f, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x0, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xfe, 0x1, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xfe, 0x3, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xfc, 0x0, 0x0, 0x0, 0x3, 0xff,
    0xff, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x7f, 0xff,
    0xf8, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xff, 0xf0,
    0x0, 0x0, 0x0, 0x0, 0x3f, 0xff, 0xe0, 0x0,
    0x0, 0x0, 0x0, 0x3f, 0xff, 0xe0, 0x0, 0x0,
    0x0, 0x0, 0x7f, 0xff, 0xc0, 0x0, 0x0, 0x0,
    0x0, 0x7f, 0xff, 0x80, 0x0, 0x0, 0x0, 0x0,
    0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0x1, 0xff,
    0xfe, 0x0, 0x0, 0x0, 0x0, 0x3, 0xff, 0xfc,
    0x0, 0x0, 0x0, 0x0, 0x7, 0xff, 0xf8, 0x0,
    0x0, 0x0, 0x0, 0xf, 0xff, 0xf0, 0x0, 0x0,
    0x0, 0x0, 0x1f, 0xff, 0xe0, 0xe0, 0x0, 0x0,
    0x0, 0x7f, 0xff, 0xc1, 0xe0, 0x0, 0x0, 0x0,
    0xff, 0xff, 0x7, 0xf0, 0x0, 0x0, 0x3, 0xff,
    0xfe, 0xf, 0xf8, 0x0, 0x0, 0x1f, 0xff, 0xfc,
    0x3f, 0xfe, 0x0, 0x0, 0x7f, 0xff, 0xf0, 0x7f,
    0xff, 0xc0, 0x7, 0xff, 0xff, 0xe1, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x83, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xfc, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xf0, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xfc, 0x0, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf0, 0x0, 0x7f, 0xff, 0xff,
    0xff, 0xff, 0xc0, 0x0, 0x1f, 0xff, 0xff, 0xff,
    0xfe, 0x0, 0x0, 0xf, 0xff, 0xff, 0xff, 0xf0,
    0x0, 0x0, 0x1, 0xff, 0xff, 0xff, 0x0, 0x0,
    0x0, 0x0, 0xf, 0xff, 0xc0, 0x0, 0x0,

    /* U+0036 "6" */
    0x0, 0x0, 0x0, 0x7, 0xff, 0xe0, 0x0, 0x0,
    0x0, 0x0, 0x3f, 0xff, 0xff, 0xc0, 0x0, 0x0,
    0x0, 0x7f, 0xff, 0xff, 0xfe, 0x0, 0x0, 0x0,
    0x7f, 0xff, 0xff, 0xff, 0xe0, 0x0, 0x0, 0x7f,
    0xff, 0xff, 0xff, 0xfe, 0x0, 0x0, 0x7f, 0xff,
    0xff, 0xff, 0xff, 0x80, 0x0, 0x3f, 0xff, 0xff,
    0xff, 0xff, 0xc0, 0x0, 0x1f, 0xff, 0xff, 0xff,
    0xff, 0xf0, 0x0, 0x1f, 0xff, 0xff, 0xff, 0xff,
    0xf8, 0x0, 0xf, 0xff, 0xff, 0xff, 0xff, 0xfe,
    0x0, 0x7, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0,
    0x1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x0,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x0, 0x7f,
    0xff, 0xff, 0x80, 0x1f, 0xf8, 0x0, 0x3f, 0xff,
    0xfe, 0x0, 0x0, 0x7c, 0x0, 0xf, 0xff, 0xfe,
    0x0, 0x0, 0x7, 0x0, 0x7, 0xff, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x3, 0xff, 0xff, 0x80, 0x0,
    0x0, 0x0, 0x0, 0xff, 0xff, 0xc0, 0x0, 0x0,
    0x0, 0x0, 0x7f, 0xff, 0xe0, 0x0, 0x0, 0x0,
    0x0, 0x1f, 0xff, 0xf0, 0x0, 0x0, 0x0, 0x0,
    0x7, 0xff, 0xf8, 0x0, 0x0, 0x0, 0x0, 0x3,
    0xff, 0xfe, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff,
    0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xff,
    0xc0, 0x0, 0x0, 0x0, 0x0, 0x1f, 0xff, 0xe0,
    0x0, 0x0, 0x0, 0x0, 0x7, 0xff, 0xf8, 0x0,
    0x0, 0x0, 0x0, 0x1, 0xff, 0xfe, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x7f, 0xff, 0x80, 0xf, 0xfe,
    0x0, 0x0, 0x1f, 0xff, 0xc0, 0x3f, 0xff, 0xf8,
    0x0, 0xf, 0xff, 0xf0, 0x7f, 0xff, 0xff, 0xc0,
    0x3, 0xff, 0xfc, 0x3f, 0xff, 0xff, 0xf8, 0x0,
    0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 0x80, 0x3f,
    0xff, 0xdf, 0xff, 0xff, 0xff, 0xf0, 0xf, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xfe, 0x3, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xc0, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf8, 0x3f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xe3, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xf8, 0xff, 0xff, 0xff, 0xc0, 0x3f, 0xff,
    0xff, 0x3f, 0xff, 0xff, 0x80, 0x1, 0xff, 0xff,
    0xcf, 0xff, 0xff, 0xc0, 0x0, 0x3f, 0xff, 0xfb,
    0xff, 0xff, 0xe0, 0x0, 0x7, 0xff, 0xfe, 0xff,
    0xff, 0xf0, 0x0, 0x0, 0xff, 0xff, 0xbf, 0xff,
    0xf8, 0x0, 0x0, 0x1f, 0xff, 0xf7, 0xff, 0xfe,
    0x0, 0x0, 0x7, 0xff, 0xfd, 0xff, 0xff, 0x0,
    0x0, 0x0, 0xff, 0xff, 0x7f, 0xff, 0xc0, 0x0,
    0x0, 0x3f, 0xff, 0xdf, 0xff, 0xf0, 0x0, 0x0,
    0xf, 0xff, 0xf7, 0xff, 0xfc, 0x0, 0x0, 0x3,
    0xff, 0xfc, 0xff, 0xff, 0x0, 0x0, 0x0, 0xff,
    0xff, 0x3f, 0xff, 0xc0, 0x0, 0x0, 0x3f, 0xff,
    0xcf, 0xff, 0xf0, 0x0, 0x0, 0xf, 0xff, 0xf1,
    0xff, 0xfc, 0x0, 0x0, 0x7, 0xff, 0xfc, 0x7f,
    0xff, 0x80, 0x0, 0x1, 0xff, 0xfe, 0x1f, 0xff,
    0xf0, 0x0, 0x0, 0xff, 0xff, 0x83, 0xff, 0xfc,
    0x0, 0x0, 0x7f, 0xff, 0xe0, 0xff, 0xff, 0xc0,
    0x0, 0x3f, 0xff, 0xf0, 0x1f, 0xff, 0xf8, 0x0,
    0x1f, 0xff, 0xfc, 0x3, 0xff, 0xff, 0xc0, 0x3f,
    0xff, 0xfe, 0x0, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x80, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xc0, 0x3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0,
    0x0, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x0,
    0xf, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x0, 0x1,
    0xff, 0xff, 0xff, 0xff, 0xfc, 0x0, 0x0, 0x3f,
    0xff, 0xff, 0xff, 0xfe, 0x0, 0x0, 0x3, 0xff,
    0xff, 0xff, 0xff, 0x0, 0x0, 0x0, 0x3f, 0xff,
    0xff, 0xff, 0x0, 0x0, 0x0, 0x3, 0xff, 0xff,
    0xff, 0x0, 0x0, 0x0, 0x0, 0x1f, 0xff, 0xfe,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x7f, 0xfc, 0x0,
    0x0, 0x0,

    /* U+0037 "7" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xfe, 0xff, 0xfc, 0x0, 0x0, 0x7,
    0xff, 0xfe, 0xff, 0xfc, 0x0, 0x0, 0x7, 0xff,
    0xfc, 0xff, 0xfc, 0x0, 0x0, 0xf, 0xff, 0xfc,
    0xff, 0xfc, 0x0, 0x0, 0xf, 0xff, 0xf8, 0xff,
    0xfc, 0x0, 0x0, 0x1f, 0xff, 0xf8, 0xff, 0xfc,
    0x0, 0x0, 0x1f, 0xff, 0xf0, 0xff, 0xfc, 0x0,
    0x0, 0x1f, 0xff, 0xf0, 0xff, 0xfc, 0x0, 0x0,
    0x3f, 0xff, 0xf0, 0xff, 0xfc, 0x0, 0x0, 0x3f,
    0xff, 0xe0, 0xff, 0xfc, 0x0, 0x0, 0x7f, 0xff,
    0xe0, 0xff, 0xfc, 0x0, 0x0, 0x7f, 0xff, 0xc0,
    0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xc0, 0x0,
    0x0, 0x0, 0x0, 0xff, 0xff, 0x80, 0x0, 0x0,
    0x0, 0x1, 0xff, 0xff, 0x80, 0x0, 0x0, 0x0,
    0x1, 0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0x1,
    0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0x3, 0xff,
    0xff, 0x0, 0x0, 0x0, 0x0, 0x3, 0xff, 0xfe,
    0x0, 0x0, 0x0, 0x0, 0x7, 0xff, 0xfe, 0x0,
    0x0, 0x0, 0x0, 0x7, 0xff, 0xfc, 0x0, 0x0,
    0x0, 0x0, 0xf, 0xff, 0xfc, 0x0, 0x0, 0x0,
    0x0, 0xf, 0xff, 0xf8, 0x0, 0x0, 0x0, 0x0,
    0x1f, 0xff, 0xf8, 0x0, 0x0, 0x0, 0x0, 0x1f,
    0xff, 0xf8, 0x0, 0x0, 0x0, 0x0, 0x1f, 0xff,
    0xf0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xff, 0xf0,
    0x0, 0x0, 0x0, 0x0, 0x3f, 0xff, 0xe0, 0x0,
    0x0, 0x0, 0x0, 0x7f, 0xff, 0xe0, 0x0, 0x0,
    0x0, 0x0, 0x7f, 0xff, 0xc0, 0x0, 0x0, 0x0,
    0x0, 0xff, 0xff, 0xc0, 0x0, 0x0, 0x0, 0x0,
    0xff, 0xff, 0x80, 0x0, 0x0, 0x0, 0x1, 0xff,
    0xff, 0x80, 0x0, 0x0, 0x0, 0x1, 0xff, 0xff,
    0x80, 0x0, 0x0, 0x0, 0x1, 0xff, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x3, 0xff, 0xff, 0x0, 0x0,
    0x0, 0x0, 0x3, 0xff, 0xfe, 0x0, 0x0, 0x0,
    0x0, 0x7, 0xff, 0xfe, 0x0, 0x0, 0x0, 0x0,
    0x7, 0xff, 0xfc, 0x0, 0x0, 0x0, 0x0, 0xf,
    0xff, 0xfc, 0x0, 0x0, 0x0, 0x0, 0xf, 0xff,
    0xfc, 0x0, 0x0, 0x0, 0x0, 0x1f, 0xff, 0xf8,
    0x0, 0x0, 0x0, 0x0, 0x1f, 0xff, 0xf8, 0x0,
    0x0, 0x0, 0x0, 0x1f, 0xff, 0xf0, 0x0, 0x0,
    0x0, 0x0, 0x3f, 0xff, 0xf0, 0x0, 0x0, 0x0,
    0x0, 0x3f, 0xff, 0xe0, 0x0, 0x0, 0x0, 0x0,
    0x7f, 0xff, 0xe0, 0x0, 0x0, 0x0, 0x0, 0x7f,
    0xff, 0xc0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xff,
    0xc0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xc0,
    0x0, 0x0, 0x0, 0x1, 0xff, 0xff, 0x80, 0x0,
    0x0, 0x0, 0x1, 0xff, 0xff, 0x80, 0x0, 0x0,
    0x0, 0x1, 0xff, 0xff, 0x0, 0x0, 0x0, 0x0,
    0x3, 0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0x3,
    0xff, 0xfe, 0x0, 0x0, 0x0, 0x0, 0x7, 0xff,
    0xfe, 0x0, 0x0, 0x0, 0x0, 0x7, 0xff, 0xfc,
    0x0, 0x0, 0x0, 0x0, 0xf, 0xff, 0xfc, 0x0,
    0x0, 0x0,

    /* U+0038 "8" */
    0x0, 0x0, 0x1, 0xff, 0xf0, 0x0, 0x0, 0x0,
    0x0, 0x7, 0xff, 0xff, 0xf0, 0x0, 0x0, 0x0,
    0x3, 0xff, 0xff, 0xff, 0x80, 0x0, 0x0, 0x3,
    0xff, 0xff, 0xff, 0xfe, 0x0, 0x0, 0x0, 0xff,
    0xff, 0xff, 0xff, 0xe0, 0x0, 0x0, 0x7f, 0xff,
    0xff, 0xff, 0xff, 0x0, 0x0, 0x1f, 0xff, 0xff,
    0xff, 0xff, 0xf0, 0x0, 0x7, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x0, 0x1, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xf0, 0x0, 0x7f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x0, 0xf, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xe0, 0x3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe,
    0x0, 0xff, 0xff, 0xfc, 0x7, 0xff, 0xff, 0xc0,
    0x1f, 0xff, 0xfc, 0x0, 0x1f, 0xff, 0xfc, 0x3,
    0xff, 0xff, 0x0, 0x1, 0xff, 0xff, 0x80, 0xff,
    0xff, 0xc0, 0x0, 0x1f, 0xff, 0xf0, 0x1f, 0xff,
    0xf0, 0x0, 0x1, 0xff, 0xff, 0x3, 0xff, 0xfe,
    0x0, 0x0, 0x3f, 0xff, 0xe0, 0x7f, 0xff, 0x80,
    0x0, 0x3, 0xff, 0xfc, 0xf, 0xff, 0xf0, 0x0,
    0x0, 0x7f, 0xff, 0x81, 0xff, 0xfe, 0x0, 0x0,
    0xf, 0xff, 0xf0, 0x3f, 0xff, 0xc0, 0x0, 0x1,
    0xff, 0xfe, 0x7, 0xff, 0xf8, 0x0, 0x0, 0x3f,
    0xff, 0xc0, 0xff, 0xff, 0x0, 0x0, 0x7, 0xff,
    0xf8, 0x1f, 0xff, 0xf0, 0x0, 0x1, 0xff, 0xff,
    0x1, 0xff, 0xfe, 0x0, 0x0, 0x3f, 0xff, 0xc0,
    0x3f, 0xff, 0xe0, 0x0, 0xf, 0xff, 0xf8, 0x3,
    0xff, 0xfe, 0x0, 0x3, 0xff, 0xfe, 0x0, 0x7f,
    0xff, 0xf0, 0x1, 0xff, 0xff, 0xc0, 0x7, 0xff,
    0xff, 0xc1, 0xff, 0xff, 0xf0, 0x0, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xfe, 0x0, 0xf, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x80, 0x0, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xe0, 0x0, 0xf, 0xff, 0xff, 0xff,
    0xff, 0xf0, 0x0, 0x0, 0x7f, 0xff, 0xff, 0xff,
    0xfc, 0x0, 0x0, 0x3f, 0xff, 0xff, 0xff, 0xff,
    0xe0, 0x0, 0xf, 0xff, 0xff, 0xff, 0xff, 0xfe,
    0x0, 0x7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0,
    0x1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0,
    0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x1f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3, 0xff,
    0xff, 0xc0, 0x1, 0xff, 0xff, 0xe0, 0xff, 0xff,
    0xe0, 0x0, 0xf, 0xff, 0xfe, 0x1f, 0xff, 0xf0,
    0x0, 0x0, 0x7f, 0xff, 0xc7, 0xff, 0xfc, 0x0,
    0x0, 0x7, 0xff, 0xfc, 0xff, 0xff, 0x0, 0x0,
    0x0, 0xff, 0xff, 0x9f, 0xff, 0xe0, 0x0, 0x0,
    0xf, 0xff, 0xf7, 0xff, 0xf8, 0x0, 0x0, 0x1,
    0xff, 0xff, 0xff, 0xff, 0x0, 0x0, 0x0, 0x1f,
    0xff, 0xff, 0xff, 0xe0, 0x0, 0x0, 0x3, 0xff,
    0xff, 0xff, 0xfc, 0x0, 0x0, 0x0, 0x7f, 0xff,
    0xff, 0xff, 0x80, 0x0, 0x0, 0xf, 0xff, 0xff,
    0xff, 0xf0, 0x0, 0x0, 0x1, 0xff, 0xff, 0xff,
    0xfe, 0x0, 0x0, 0x0, 0x3f, 0xff, 0xff, 0xff,
    0xe0, 0x0, 0x0, 0xf, 0xff, 0xff, 0xff, 0xfc,
    0x0, 0x0, 0x1, 0xff, 0xff, 0x7f, 0xff, 0xc0,
    0x0, 0x0, 0x7f, 0xff, 0xcf, 0xff, 0xfc, 0x0,
    0x0, 0x1f, 0xff, 0xf9, 0xff, 0xff, 0xc0, 0x0,
    0x7, 0xff, 0xff, 0x1f, 0xff, 0xfe, 0x0, 0x3,
    0xff, 0xff, 0xc3, 0xff, 0xff, 0xf8, 0x3, 0xff,
    0xff, 0xf8, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xfe, 0x7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xc0, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0,
    0x7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x0,
    0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0, 0x7,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x0, 0x3f,
    0xff, 0xff, 0xff, 0xff, 0xe0, 0x0, 0x3, 0xff,
    0xff, 0xff, 0xff, 0xf8, 0x0, 0x0, 0x1f, 0xff,
    0xff, 0xff, 0xfc, 0x0, 0x0, 0x0, 0xff, 0xff,
    0xff, 0xfe, 0x0, 0x0, 0x0, 0x3, 0xff, 0xff,
    0xfe, 0x0, 0x0, 0x0, 0x0, 0x3, 0xff, 0xf8,
    0x0, 0x0, 0x0,

    /* U+0039 "9" */
    0x0, 0x0, 0x7, 0xff, 0x80, 0x0, 0x0, 0x0,
    0x0, 0x1f, 0xff, 0xfe, 0x0, 0x0, 0x0, 0x0,
    0x3f, 0xff, 0xff, 0xf0, 0x0, 0x0, 0x0, 0x3f,
    0xff, 0xff, 0xff, 0x0, 0x0, 0x0, 0x3f, 0xff,
    0xff, 0xff, 0xf0, 0x0, 0x0, 0x1f, 0xff, 0xff,
    0xff, 0xff, 0x0, 0x0, 0x1f, 0xff, 0xff, 0xff,
    0xff, 0xe0, 0x0, 0xf, 0xff, 0xff, 0xff, 0xff,
    0xfc, 0x0, 0x7, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x80, 0x1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0,
    0x0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x0,
    0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x1f,
    0xff, 0xff, 0x0, 0xff, 0xff, 0xf0, 0xf, 0xff,
    0xfe, 0x0, 0x7, 0xff, 0xfe, 0x3, 0xff, 0xff,
    0x0, 0x0, 0xff, 0xff, 0xc1, 0xff, 0xff, 0x80,
    0x0, 0xf, 0xff, 0xf0, 0x7f, 0xff, 0xc0, 0x0,
    0x3, 0xff, 0xfe, 0x1f, 0xff, 0xe0, 0x0, 0x0,
    0x7f, 0xff, 0x8f, 0xff, 0xf8, 0x0, 0x0, 0x1f,
    0xff, 0xe3, 0xff, 0xfc, 0x0, 0x0, 0x3, 0xff,
    0xfc, 0xff, 0xff, 0x0, 0x0, 0x0, 0xff, 0xff,
    0x3f, 0xff, 0xc0, 0x0, 0x0, 0x3f, 0xff, 0xcf,
    0xff, 0xf0, 0x0, 0x0, 0xf, 0xff, 0xfb, 0xff,
    0xfc, 0x0, 0x0, 0x3, 0xff, 0xfe, 0xff, 0xff,
    0x0, 0x0, 0x0, 0xff, 0xff, 0xbf, 0xff, 0xc0,
    0x0, 0x0, 0x3f, 0xff, 0xef, 0xff, 0xf8, 0x0,
    0x0, 0x1f, 0xff, 0xfb, 0xff, 0xfe, 0x0, 0x0,
    0x7, 0xff, 0xff, 0x7f, 0xff, 0xc0, 0x0, 0x3,
    0xff, 0xff, 0xdf, 0xff, 0xf8, 0x0, 0x1, 0xff,
    0xff, 0xf7, 0xff, 0xff, 0x0, 0x0, 0xff, 0xff,
    0xfc, 0xff, 0xff, 0xe0, 0x0, 0x7f, 0xff, 0xff,
    0x3f, 0xff, 0xff, 0x0, 0xff, 0xff, 0xff, 0xc7,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf1, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0x7, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xc1, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf0, 0x3f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xfc, 0x3, 0xff, 0xff, 0xff, 0xfe,
    0xff, 0xff, 0x0, 0x7f, 0xff, 0xff, 0xff, 0x3f,
    0xff, 0xc0, 0x7, 0xff, 0xff, 0xff, 0xf, 0xff,
    0xf0, 0x0, 0xff, 0xff, 0xff, 0x83, 0xff, 0xfc,
    0x0, 0x7, 0xff, 0xff, 0x0, 0xff, 0xfe, 0x0,
    0x0, 0x1f, 0xfc, 0x0, 0x7f, 0xff, 0x80, 0x0,
    0x0, 0x0, 0x0, 0x1f, 0xff, 0xe0, 0x0, 0x0,
    0x0, 0x0, 0x7, 0xff, 0xf8, 0x0, 0x0, 0x0,
    0x0, 0x1, 0xff, 0xfe, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x3f, 0xff, 0xc0, 0x0, 0x0, 0x0, 0x0, 0x1f,
    0xff, 0xf0, 0x0, 0x0, 0x0, 0x0, 0x7, 0xff,
    0xf8, 0x0, 0x0, 0x0, 0x0, 0x3, 0xff, 0xfe,
    0x0, 0x0, 0x0, 0x0, 0x1, 0xff, 0xff, 0x80,
    0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xc0, 0x0,
    0x0, 0x0, 0x0, 0x7f, 0xff, 0xf0, 0x0, 0x0,
    0x0, 0x0, 0x3f, 0xff, 0xf8, 0x0, 0x38, 0x0,
    0x0, 0x1f, 0xff, 0xfc, 0x0, 0xf, 0x80, 0x0,
    0x3f, 0xff, 0xff, 0x0, 0x7, 0xfe, 0x0, 0x7f,
    0xff, 0xff, 0x80, 0x1, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xc0, 0x0, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xe0, 0x0, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xf8,
    0x0, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x0,
    0x7, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x0, 0x3,
    0xff, 0xff, 0xff, 0xff, 0xfe, 0x0, 0x0, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x0, 0x0, 0x7f, 0xff,
    0xff, 0xff, 0xff, 0x80, 0x0, 0x1f, 0xff, 0xff,
    0xff, 0xff, 0x80, 0x0, 0x1, 0xff, 0xff, 0xff,
    0xff, 0x80, 0x0, 0x0, 0x1f, 0xff, 0xff, 0xff,
    0x80, 0x0, 0x0, 0x0, 0xff, 0xff, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x1, 0xff, 0xf8, 0x0, 0x0,
    0x0, 0x0,

    /* U+003A ":" */
    0x3, 0xf8, 0x1, 0xff, 0xc0, 0x7f, 0xfc, 0x1f,
    0xff, 0xc7, 0xff, 0xfc, 0xff, 0xff, 0xbf, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xff,
    0xff, 0x9f, 0xff, 0xf1, 0xff, 0xfc, 0x1f, 0xff,
    0x1, 0xff, 0xc0, 0xf, 0xe0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0x80,
    0x1f, 0xfc, 0x7, 0xff, 0xc1, 0xff, 0xfc, 0x7f,
    0xff, 0xcf, 0xff, 0xfb, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xef, 0xff, 0xf9, 0xff,
    0xff, 0x1f, 0xff, 0xc1, 0xff, 0xf0, 0x1f, 0xfc,
    0x0, 0xfe, 0x0};

/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 1086, .box_w = 60, .box_h = 73, .ofs_x = 4, .ofs_y = -1},
    {.bitmap_index = 548, .adv_w = 627, .box_w = 30, .box_h = 71, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 815, .adv_w = 944, .box_w = 56, .box_h = 71, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1312, .adv_w = 947, .box_w = 56, .box_h = 72, .ofs_x = -1, .ofs_y = -1},
    {.bitmap_index = 1816, .adv_w = 1102, .box_w = 65, .box_h = 71, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 2393, .adv_w = 952, .box_w = 55, .box_h = 72, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 2888, .adv_w = 1019, .box_w = 58, .box_h = 73, .ofs_x = 4, .ofs_y = -1},
    {.bitmap_index = 3418, .adv_w = 992, .box_w = 56, .box_h = 70, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 3908, .adv_w = 1056, .box_w = 59, .box_h = 73, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 4447, .adv_w = 1019, .box_w = 58, .box_h = 73, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 4977, .adv_w = 419, .box_w = 19, .box_h = 55, .ofs_x = 3, .ofs_y = -1}};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
    {
        {.range_start = 48, .range_length = 11, .glyph_id_start = 1, .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY}};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static lv_font_fmt_txt_glyph_cache_t cache;
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
    .cmap_num = 1,
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
const lv_font_t lv_montserrat_bold_100 = {
#else
lv_font_t lv_montserrat_bold_100 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt, /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt, /*Function pointer to get glyph's bitmap*/
    .line_height = 73,                              /*The maximum line height required by the font*/
    .base_line = 1,                                 /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -10,
    .underline_thickness = 5,
#endif
    .dsc = &font_dsc, /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};

#endif /*#if LV_MONTSERRAT_BOLD_100*/
