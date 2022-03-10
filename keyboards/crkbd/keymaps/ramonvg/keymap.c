/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS zFOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "drivers/sensors/pimoroni_trackball.h"
#include <print.h>

enum custom_keycodes {
    C_GUI = SAFE_RANGE,
};

enum { TD_A };

#define C_GUI_TAB MT(MOD_LGUI, KC_TAB)
#define C_ALT_BSPC MT(KC_LALT, KC_BSPC)

#define L_BASE 0
#define L_NUMBERS 1
#define L_SYMBOLS 2
#define L_ADJUST 3
// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_LGUI,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_LALT, KC_RCTL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            MO(1),   C_GUI,  KC_SPC,     KC_ENT,   MO(2), TD(TD_A)
                                      //`--------------------------'  `--------------------------'

  ),

  [L_NUMBERS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,   KC_4,    KC_5,    KC_6,    KC_0,    DEBUG,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,   KC_7,    KC_8,    KC_9,    XXXXXXX, XXXXXXX,                      XXXXXXX,    KC_M, XXXXXXX, _______, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, KC_LGUI,  KC_SPC,     KC_ENT,   MO(3), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [L_SYMBOLS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_GRV, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_EQL, KC_BSLS,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, KC_UNDS,                      KC_MINS, KC_DQUO, KC_QUOT, KC_LCBR, KC_RCBR, KC_COLN,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_SLSH, KC_PIPE, KC_SLSH, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(3),  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [L_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10 , KC_F11,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, KC_VOLD, KC_MUTE, KC_VOLU,                      KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};
// clang-format on

void keyboard_post_init_user(void) {
    pimoroni_trackball_set_rgbw(52, 235, 164, 0);
    debug_enable = true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case L_NUMBERS:
            pimoroni_trackball_set_rgbw(255, 0, 0, 0);
            break;
        case L_SYMBOLS:
            pimoroni_trackball_set_rgbw(0, 255, 0, 0);
            break;
        case L_ADJUST:
            pimoroni_trackball_set_rgbw(0, 0, 255, 0);
            break;
        default: //  for any other layers, or the default layer
            pimoroni_trackball_set_rgbw(52, 235, 164, 0);
            break;
    }
    return state;
}
bool is_shifted = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LSFT:
            if (record->event.pressed) {
                is_shifted = true;
                register_code(KC_LSFT);
            } else {
                is_shifted = false;
                unregister_code(KC_LSFT);
            }
            return false; // We handled this keypress
        case C_GUI:
            if (record->event.pressed) {
                register_code(KC_LGUI); // Change the key to be held here
                layer_on(1);
            } else {
                unregister_code(KC_LGUI); // Change the key that was held here, too!
                layer_off(1);
            }
            return false; // We handled this keypress
    }
    return true; // We didn't handle other keypresses
};

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (layer_state_is(L_NUMBERS)) {
        // mouse_report.h = mouse_report.x;
        // mouse_report.v = mouse_report.y;
        mouse_report.x = mouse_report.x * 5;
        mouse_report.y = mouse_report.y * 5;
    }
    if (layer_state_is(L_SYMBOLS)) {
        mouse_report.h = - mouse_report.x / 3;
        mouse_report.v = - mouse_report.y / 3;
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}

void dance_cln_finished(qk_tap_dance_state_t *state, void *user_data) {
    register_code(KC_RALT);
    if (state->count == 1) {
        register_code(KC_QUOT);
    }
    if (state->count == 2) {
        register_code(KC_GRV);
    }
}

void dance_cln_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_QUOT);
    }
    if (state->count == 2) {
        unregister_code(KC_GRV);
    }
    unregister_code(KC_RALT);
}

// All tap dance functions would go here. Only showing this one.
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_A] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
};
