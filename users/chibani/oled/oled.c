#include "chibani.h"
#include "quantum.h"
#include "oled/oled_assets.h"
#include <ctype.h>


void oled_render_mario(uint8_t col, uint8_t line) {
    static uint16_t timer = 0;
    static uint8_t  frame = 0;

    uint8_t current_wpm = get_current_wpm();

    if(0 == current_wpm){
        frame = 0;
    }else{

        if (timer_elapsed(timer) > get_frame_duration(current_wpm)) {
            frame++;
            if (frame == 3) {
                frame = 0;
            }
            timer = timer_read();
        }
    }

    for (uint8_t i = 0; i < 4; i++) {
        oled_set_cursor(col, line + i);
        oled_write_raw_P(mario_animation[frame][i], sizeof(mario_animation[0][0]));
    }
}

uint16_t get_frame_duration(uint16_t wpm ) {
    if(wpm == 0) {
        return 10000;
    }else {
        // Map WPM to animation speed
        // Higher WPM = faster animation (lower delay between frames)
        // Limit the range to avoid too fast/slow animations
        uint16_t min_speed = 10;  // (fastest animation)
        uint16_t max_speed = 500;  //  (slowest animation)
        uint16_t min_wpm = 20;     // WPM threshold to start speeding up
        uint16_t max_wpm = 150;    // WPM threshold for maximum speed

        // Constrain WPM to our defined range
        uint16_t constrained_wpm = wpm ;
        if (constrained_wpm < min_wpm) constrained_wpm = min_wpm;
        if (constrained_wpm > max_wpm) constrained_wpm = max_wpm;

        // Map WPM to animation speed (higher WPM = lower delay)
        return max_speed - ((constrained_wpm - min_wpm) * (max_speed - min_speed) / (max_wpm - min_wpm));
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
