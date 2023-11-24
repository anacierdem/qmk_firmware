/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#define SCROLL_DIVISOR_H 15.0
#define SCROLL_DIVISOR_V 15.0

#define L_THUMB MT(MOD_LCTL,KC_SPC)
#define R_THUMB LT(LAYER_FUNCTIONS,KC_SPC)
#define L1_SW TT(LAYER_NUMBERS)
#define L2_SW TT(LAYER_SYMBOLS)
#define L5_SW TT(LAYER_ADJUST)

enum LAYER {
    LAYER_QWERTY,
    LAYER_NUMBERS,
    LAYER_SYMBOLS,
    LAYER_FUNCTIONS,
    LAYER_MOUSE,
    LAYER_ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                                   ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                        KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                                   |--------+--------+--------+--------+--------+--------|
      KC_LALT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                        KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                                   |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                        KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, RSFT_T(KC_ENT),
  //|--------+--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   L1_SW, L_THUMB,                   R_THUMB,   L2_SW,  KC_ENT
                                      //`--------------------------'                 `--------------------------'

  ),

  [LAYER_NUMBERS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                                   ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
  //|--------+--------+--------+--------+--------+--------|                                   |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                                     KC_PSLS,   KC_P4,   KC_P5,   KC_P6, KC_PMNS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                                   |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                                     KC_PAST,   KC_P1,   KC_P2,   KC_P3, KC_PPLS, _______,
  //|--------+--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT, _______, _______,                   _______, KC_RALT,   KC_P0
                                      //`--------------------------'                 `--------------------------'
  ),

  [LAYER_SYMBOLS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                                   ,-----------------------------------------------------.
       KC_ESC, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                                   |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                                     KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                                   |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                                     KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,                   _______, _______, KC_RALT
                                      //`--------------------------'                 `--------------------------'
  ),

  [LAYER_FUNCTIONS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                                   ,-----------------------------------------------------.
       KC_TAB,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                     KC_MPLY, KC_HOME,   KC_UP, KC_PGUP, XXXXXXX,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                                   |--------+--------+--------+--------+--------+--------|
      _______,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,                                     KC_MNXT, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                                   |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                                     KC_MPRV, KC_END,  KC_MPLY, KC_PGDN, XXXXXXX,   L5_SW,
  //|--------+--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------+--------|
                                          _______, KC_LALT, _______,                   _______, _______, KC_RALT
                                      //`--------------------------'                 `--------------------------'
  ),

  [LAYER_MOUSE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                                   ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                                   |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                                     KC_BTN2, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                                   |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,                   KC_BTN1, KC_BTN3, _______
                                      //`--------------------------'                 `--------------------------'
  ),

  [LAYER_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                                   ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                                   |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                                   |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, _______, KC_SPC,                    _______, _______, KC_ENT
                                      //`--------------------------'                 `--------------------------'
  ),
};

#ifdef RGBLIGHT_ENABLE
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 2, HSV_GREEN}, {11, 2, HSV_GREEN}, {17, 2, HSV_GREEN}, {24, 2, HSV_GREEN}, {32, 2, HSV_GREEN}, {38, 2, HSV_GREEN}
);

const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 2, HSV_RED}, {11, 2, HSV_RED}, {17, 2, HSV_RED}, {24, 2, HSV_RED}, {32, 2, HSV_RED}, {38, 2, HSV_RED}
);


const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_layer1_layer,
    my_layer2_layer
);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, 1));
    rgblight_set_layer_state(1, layer_state_cmp(state, 2));
    return state;
}
#endif

#ifdef TAP_DANCE_ENABLE
tap_dance_action_t tap_dance_actions[] = {};
#endif

#ifdef POINTING_DEVICE_ENABLE
void pointing_device_init_user(void) {
    set_auto_mouse_layer(LAYER_MOUSE);
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
}

bool set_scrolling = false;

// Variables to store accumulated scroll values
float scroll_accumulated_h = 0;
float scroll_accumulated_v = 0;

// Function to handle mouse reports and perform drag scrolling
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    // Check if drag scrolling is active
    if (set_scrolling) {
        // Calculate and accumulate scroll values based on mouse movement and divisors
        scroll_accumulated_h += (float)mouse_report.x / SCROLL_DIVISOR_H;
        scroll_accumulated_v += (float)mouse_report.y / SCROLL_DIVISOR_V;

        // Assign integer parts of accumulated scroll values to the mouse report
        mouse_report.h = (int8_t)scroll_accumulated_h;
        mouse_report.v = -(int8_t)scroll_accumulated_v;

        // Update accumulated scroll values by subtracting the integer parts
        scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
        scroll_accumulated_v -= (int8_t)scroll_accumulated_v;

        // Clear the X and Y values of the mouse report
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == L1_SW || keycode == L2_SW || keycode == L_THUMB || keycode == R_THUMB) {
        set_scrolling = record->event.pressed;
    }
    return true;
}
#endif