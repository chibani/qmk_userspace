
#pragma once
#include QMK_KEYBOARD_H

#if defined(OLED_ENABLE)
#    include "oled/oled.h"
#endif

enum userspace_layers {
    _QWERTY             = 0,
    _MEDIA,
    _NAV,
    _ACCENTS,
    _SYMBOLS,
    _FUNCTIONS,
    _NUMBERS,
    _SPECIALS,
    _LAFRONCE,
};
