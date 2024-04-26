#include "chibani.h"
#include "oled/oled_assets.h"

const char *get_layer_name_string(uint8_t layer) {
    switch (layer) {
        case _QWERTY:
            return OLED_RENDER_LAYOUT_QWERTY;
        case _MEDIA:
            return OLED_RENDER_LAYOUT_MEDIA;
        case _NAV:
            return OLED_RENDER_LAYOUT_NAV;
        case _ACCENTS:
            return OLED_RENDER_LAYOUT_ACCENTS;
        case _SYMBOLS:
            return OLED_RENDER_LAYOUT_SYMBOLS;
        case _FUNCTIONS:
            return OLED_RENDER_LAYOUT_FUNCTIONS;
        case _NUMBERS:
            return OLED_RENDER_LAYOUT_NUMBERS;
        case _SPECIALS:
            return OLED_RENDER_LAYOUT_SPECIALS;
        case _LAFRONCE:
            return OLED_RENDER_LAYOUT_LAFRONCE;
        case _EMOJI:
            return OLED_RENDER_LAYOUT_EMOJI;
        default:
            return "UNDEFINED";
    }
}
