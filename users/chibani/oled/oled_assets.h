#pragma once

// clang-format off

#    define OLED_RENDER_LAYOUT_QWERTY     "QWERT"
#    define OLED_RENDER_LAYOUT_NAV        "Nav  "
#    define OLED_RENDER_LAYOUT_MEDIA      "Media"
#    define OLED_RENDER_LAYOUT_ACCENTS    "Accen"
#    define OLED_RENDER_LAYOUT_SYMBOLS    "Symbol"
#    define OLED_RENDER_LAYOUT_FUNCTIONS  "Funct"
#    define OLED_RENDER_LAYOUT_NUMBERS    "Num  "
#    define OLED_RENDER_LAYOUT_SPECIALS   "Spec "
#    define OLED_RENDER_LAYOUT_LAFRONCE   "Fr   "
#    define OLED_RENDER_LAYOUT_EMOJI   "Emoji"

static const char PROGMEM mario_animation[4][4][16] = {
    {
        { 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x20, 0x20, 0x20, 0x20, 0xc0, 0x00, 0x00, 0x00, 0x00 },
        { 0x00, 0x78, 0x8e, 0x09, 0x38, 0x7c, 0x26, 0x82, 0xc3, 0x9b, 0x03, 0x1f, 0x17, 0x97, 0x62, 0x00 },
        { 0x00, 0xf8, 0xc6, 0x83, 0x03, 0x06, 0x3c, 0xcc, 0x84, 0x85, 0x85, 0xcb, 0x71, 0xc0, 0x00, 0x00 },
        { 0x00, 0x00, 0x0f, 0xff, 0x9f, 0x9f, 0x9f, 0x9f, 0x9e, 0xbe, 0xdf, 0x1f, 0x0e, 0x03, 0x00, 0x00 }
    },
    {
        { 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x20, 0x20, 0x20, 0x20, 0xc0, 0x00, 0x00, 0x00, 0x00 },
        { 0x00, 0x78, 0x8e, 0x09, 0x38, 0x7c, 0x26, 0x82, 0xc3, 0x9b, 0x83, 0x1b, 0x1f, 0x97, 0xe2, 0x80 },
        { 0xf0, 0x8c, 0x02, 0x63, 0x93, 0x0e, 0x0c, 0x0c, 0x94, 0x65, 0x8d, 0x9b, 0x71, 0xc9, 0x30, 0x00 },
        { 0x00, 0x3b, 0x47, 0x9f, 0xbf, 0xbf, 0xbf, 0xdf, 0x0e, 0x1e, 0x7f, 0x9f, 0x8e, 0x47, 0x24, 0x18 }
    },
    {
        { 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x20, 0x20, 0x20, 0x60, 0xc0, 0x00, 0x00, 0x00, 0x00 },
        { 0x60, 0x98, 0x0e, 0x39, 0x7c, 0x24, 0x82, 0xc3, 0x9b, 0x83, 0x1b, 0x03, 0x9f, 0xe6, 0x80, 0x00 },
        { 0x70, 0x88, 0xc5, 0x23, 0x12, 0x12, 0x14, 0x2c, 0xfd, 0x65, 0x45, 0x8f, 0x99, 0x74, 0xc4, 0x38 },
        { 0x3c, 0x46, 0x41, 0x3d, 0x3e, 0x1e, 0x1e, 0x1f, 0x0f, 0x0e, 0x0e, 0x1f, 0x21, 0x20, 0x30, 0x1f }
    },
    {
        { 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x90, 0xc8, 0xc8, 0xc8, 0xd8, 0xf0, 0xc8, 0x88, 0x08, 0xf0 },
        { 0x18, 0x26, 0x43, 0xce, 0x9f, 0x89, 0x20, 0x30, 0x66, 0x60, 0x46, 0xc0, 0x67, 0x39, 0xe1, 0x1e },
        { 0x1c, 0xa2, 0x71, 0x48, 0x84, 0x84, 0x85, 0xcb, 0xff, 0x99, 0x91, 0xe3, 0x66, 0x1d, 0x30, 0xc0 },
        { 0x0f, 0x11, 0x10, 0x0f, 0x0f, 0x07, 0x07, 0x07, 0x03, 0x03, 0x03, 0x07, 0x08, 0x08, 0x0c, 0x07 }
    }
};
