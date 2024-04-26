#pragma once

#include "quantum.h"

void render_mod_status(uint8_t modifiers, uint8_t col, uint8_t line);
void render_space(void);
void render_layer_state(void);
void render_mod_status_gui_alt(uint8_t modifiers);
void render_mod_status_ctrl_shift(uint8_t modifiers);
void oled_render_mario(uint8_t col, uint8_t line);
void render_default_layer_state(uint8_t col, uint8_t line);
void render_rgb_hsv(uint8_t col, uint8_t line);

void render_default_layer_state(uint8_t col, uint8_t line);
void oled_render_current_layer(uint8_t layer, uint8_t col, uint8_t line);
