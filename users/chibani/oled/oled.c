#include "chibani.h"
#include "quantum.h"
#include "oled/oled_assets.h"
#include <ctype.h>


void oled_render_mario(uint8_t col, uint8_t line) {
    static uint16_t timer = 0;
    static uint8_t  frame = 0;
    if (timer_elapsed(timer) > 200) {
        frame++;
        if (frame == 3) {
            frame = 0;
        }
        timer = timer_read();
    }
    for (uint8_t i = 0; i < 4; i++) {
        oled_set_cursor(col, line + i);
        oled_write_raw_P(mario_animation[frame][i], sizeof(mario_animation[0][0]));
    }
}

void render_rgb_hsv(uint8_t col, uint8_t line) {
    oled_set_cursor(col, line);
    oled_write_P(PSTR("HSV: "), false);
#ifdef RGB_MATRIX_ENABLE
    oled_write(get_u8_str(rgb_matrix_get_hue(), ' '), false);
    oled_write_P(PSTR(", "), false);
    oled_write(get_u8_str(rgb_matrix_get_sat(), ' '), false);
    oled_write_P(PSTR(", "), false);
    oled_write(get_u8_str(rgb_matrix_get_val(), ' '), false);
#elif RGBLIGHT_ENABLE
    if (is_rgblight_startup_running()) {
        oled_write_P(PSTR("Start Animation"), false);
    } else {
        oled_write(get_u8_str(rgblight_get_hue(), ' '), false);
        oled_write_P(PSTR(", "), false);
        oled_write(get_u8_str(rgblight_get_sat(), ' '), false);
        oled_write_P(PSTR(", "), false);
        oled_write(get_u8_str(rgblight_get_val(), ' '), false);
    }
#endif
}

void render_default_layer_state(uint8_t col, uint8_t line) {
    oled_set_cursor(col, line);
#ifdef OLED_DISPLAY_VERBOSE
    static char          layer_state_buffer[11] = {0};
    static layer_state_t old_state              = 0;

    if (old_state != default_layer_state) {
        snprintf(layer_state_buffer, sizeof(layer_state_buffer), "%-10s",
                 get_layer_name_string(default_layer_state, false));
        old_state = default_layer_state;
    }
    oled_write(layer_state_buffer, false);
    oled_advance_page(true);
#else
    oled_write(get_layer_name_string(get_highest_layer(default_layer_state)), false);
#endif
}

void oled_render_current_layer(uint8_t layer, uint8_t col, uint8_t line) {
    oled_set_cursor(col, line);
    oled_write(get_layer_name_string(layer), false);
}
