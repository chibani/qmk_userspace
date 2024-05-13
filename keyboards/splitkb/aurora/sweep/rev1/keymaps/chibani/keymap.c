#include QMK_KEYBOARD_H
#include "chibani.h"
// #include "print.h"
#include "keymap_us_international.h"
#include "sendstring_us_international.h"

enum unicode_names {
    AE_LOWER,
    AE_UPPER,
    U_AGRAV_LOWER,
    U_AGRAV_UPPER,
    U_ACIRC_LOWER,
    U_ACIRC_UPPER,
    U_EGRAV_LOWER,
    U_EGRAV_UPPER,
    U_ECIRC_LOWER,
    U_ECIRC_UPPER,
    U_EDIAC_LOWER,
    U_EDIAC_UPPER,
    U_IDIAE_LOWER,
    U_IDIAE_UPPER,
    U_UGRAV_LOWER,
    U_UGRAV_UPPER,
    U_OE_LOWER,
    U_OE_UPPER,
};

const uint32_t PROGMEM unicode_map[] = {
    [AE_LOWER] = 0x00E6,  // æ
    [AE_UPPER] = 0x00C6,  // Æ
    [U_AGRAV_LOWER] = 0x00e0,  // à
    [U_AGRAV_UPPER] = 0x00c0,  // À
    [U_ACIRC_LOWER] = 0x00e2,  // â
    [U_ACIRC_UPPER] = 0x00c2,  // Â
    [U_EGRAV_LOWER] = 0x00e8,  // è
    [U_EGRAV_UPPER] = 0x00c8,  // È
    [U_ECIRC_LOWER] = 0x00ea,  // ê
    [U_ECIRC_UPPER] = 0x00ca,  // Ê
    [U_EDIAC_LOWER] = 0x00eb,  // ë
    [U_EDIAC_UPPER] = 0x00cb,  // Ë
    [U_IDIAE_LOWER] = 0x00ef,  // ï
    [U_IDIAE_UPPER] = 0x00cf,  // Ï
    [U_UGRAV_LOWER] = 0x00f9,  // ù
    [U_UGRAV_UPPER] = 0x00d9,  // Ù
    [U_OE_LOWER] = 0x0153,  // œ
    [U_OE_UPPER] = 0x0152,  // Œ
};

#define U_AE UP(AE_LOWER, AE_UPPER)
#define U_AGRAV UP(U_AGRAV_LOWER, U_AGRAV_UPPER)
#define U_UGRAV UP(U_UGRAV_LOWER, U_UGRAV_UPPER)
#define U_ACIRC UP(U_ACIRC_LOWER, U_ACIRC_UPPER)
#define U_EGRAV UP(U_EGRAV_LOWER, U_EGRAV_UPPER)
#define U_ECIRC UP(U_ECIRC_LOWER, U_ECIRC_UPPER)
#define U_EDIAC UP(U_EDIAC_LOWER, U_EDIAC_UPPER)
#define U_IDIAE UP(U_IDIAE_LOWER, U_IDIAE_UPPER)
#define U_OE UP(U_OE_LOWER, U_OE_UPPER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // QWERTY
	[_QWERTY] = LAYOUT(
        KC_Q, KC_W, KC_E, KC_R, KC_T,                                    KC_Y, KC_U, KC_I, KC_O, KC_P,
        LSFT_T(KC_A), LT(_FUNCTIONS,KC_S), LT(_MEDIA,KC_D), LT(_ACCENTS,KC_F), KC_G,                KC_H, LT(_SYMBOLS,KC_J), LT(_NAV,KC_K), LT(_NUMBERS,KC_L), RSFT_T(KC_SCLN),
        KC_Z, LCTL_T(KC_X), LALT_T(KC_C), KC_V, KC_B,                    KC_N, KC_M, LALT_T(KC_COMM), LCTL_T(KC_DOT), KC_SLSH,
        KC_P0, KC_BSPC,                                                  LT(_SPECIALS,KC_SPC), LT(_LAFRONCE,KC_P1)
    ),
    // MEDIA
    [_MEDIA] = LAYOUT(
        RGB_TOG, RGB_SPI, RGB_HUI, RGB_SAI, RGB_VAI,                     KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU,
        RGB_MOD, KC_BTN2, KC_NO, KC_BTN1, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE,
        RGB_RMOD, RGB_SPD, RGB_HUD, RGB_SAD, RGB_VAD,                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    // NAV
	[_NAV] = LAYOUT(
        KC_TAB, KC_PGDN, KC_UP, KC_PGUP, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS,                    KC_TRNS, KC_LGUI, KC_NO, LCTL(KC_LALT), LCA(KC_LSFT),
        KC_TRNS, KC_HOME, KC_TRNS, KC_END, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    // ACCENTS
	[_ACCENTS] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_UNDS, KC_PIPE, KC_QUOT, KC_TRNS,
        KC_CIRC, KC_ASTR, KC_AMPR, KC_NO, KC_TRNS,                       KC_HASH, KC_TILD, KC_SLSH, KC_DQUO, KC_DLR,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_MINS, KC_BSLS, KC_GRV, KC_TRNS,
        RGB_RMOD, KC_TRNS, KC_TRNS, RGB_MOD
    ),
    // SYMBOLS
	[_SYMBOLS] = LAYOUT(
        KC_TRNS, KC_COLN, KC_LT, KC_GT, KC_SCLN,                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_AT,                      KC_TRNS, KC_NO, KC_EQL, KC_PLUS, KC_PERC,
        KC_TRNS, KC_EXLM, KC_LBRC, KC_RBRC, KC_TRNS,                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    // FUNCTIONS
	[_FUNCTIONS] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10,
        KC_TRNS, KC_NO, LCTL(KC_LALT), KC_TRNS, KC_TRNS,                KC_TRNS, KC_F4, KC_F5, KC_F6, KC_F11,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F12,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    // NUMBERS
	[_NUMBERS] = LAYOUT(
        KC_PSLS, KC_7, KC_8, KC_9, KC_PPLS,                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_PAST, KC_4, KC_5, KC_6, KC_PMNS,                             KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS,
        KC_DOT, KC_1, KC_2, KC_3, KC_PEQL,                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_0, KC_TRNS, KC_ENT, KC_TRNS
    ),
    // SPECIALS
	[_SPECIALS] = LAYOUT(
        KC_TRNS, KC_TRNS, US_EURO, KC_ESC, KC_TRNS,                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL,
        KC_TRNS, KC_PERC, KC_SLSH, KC_ENT, KC_TRNS,                    DF(1), KC_LGUI, KC_TRNS, KC_TRNS, QK_DEBUG_TOGGLE,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_EXLM, KC_TRNS,                   DF(0), KC_TRNS, RALT_T(KC_COMM), RCTL_T(KC_DOT), QK_BOOT,
        KC_TRNS, KC_TAB, KC_NO, KC_TRNS
    ),
    // QWERTY-LAFAYETTish
    [_LAFRONCE] = LAYOUT(
        KC_X, U_EGRAV, U_ECIRC, US_EACU, KC_TRNS,                   KC_TRNS, U_UGRAV, U_IDIAE, U_OE, KC_TRNS,
        U_AGRAV, U_AE, U_EDIAC, KC_TRNS, KC_TRNS,              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        U_ACIRC, KC_TRNS, US_CCED, KC_TRNS, KC_TRNS,                   KC_TRNS, US_MICR, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_NO
    )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
  return true;
}
