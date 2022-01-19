#include QMK_KEYBOARD_H
#include "rgb_matrix_ledmaps.h"
#include "rgb_matrix_ledmaps.c"

enum custom_keycodes { GIT_COMMIT = SAFE_RANGE, JUMP_AUDUR, JUMP_KVIKA, QUOTE_CODE, BREAKPOINT, RGB_LAYERS_TOGGLE };

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGB_LAYERS_TOGGLE:
            if (record->event.pressed) {
                rgb_matrix_layers_toggle();
            }
            break;
        case GIT_COMMIT:
            if (record->event.pressed) {
                rgb_matrix_layers_enable();
            }
            break;

        case JUMP_AUDUR:
            if (record->event.pressed) {
                rgb_matrix_layers_disable();
            }
            break;

        case JUMP_KVIKA:
            if (record->event.pressed) {
                SEND_STRING("jump kvika-api\n");
            }
            break;
        case QUOTE_CODE:
            if (record->event.pressed) {
                SEND_STRING("```\n\n```\n");
            }
            break;
        case BREAKPOINT:
            if (record->event.pressed) {
                SEND_STRING("\nbreakpoint()\n");
            }
            break;
    };
    return true;
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right
/*  */

    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the RESET key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    //
    // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.
    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,           KC_MPLY,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_PGUP,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGDN,
        LT(2, KC_CAPS), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_END,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_DEL,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT(
        _______, KC_MYCM, KC_WHOM, KC_CALC, KC_MSEL, KC_MPRV,  KC_MNXT,  KC_MPLY, KC_MSTP, KC_MUTE, KC_VOLD, KC_VOLU, _______, KC_INS,           _______,
        RGB_LAYERS_TOGGLE, RGB_TOG, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, _______, _______, _______,          _______,
        _______, _______, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI,  BL_TOGG,  BL_BRTG, BL_ON,   BL_INC,  _______, _______, _______, RESET,            _______,
        _______, _______, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD,  BL_STEP,  _______, BL_OFF,  BL_DEC,  _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______,  _______,  NK_TOGG, _______, _______, _______, _______,          _______, RGB_MOD, _______,
        _______, _______, _______,                             _______,                             _______, _______, _______, RGB_SPD, RGB_RMOD, RGB_SPI
    ),


    [2] = LAYOUT(
        _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______, _______, _______, _______, _______,           KC_MUTE,
        QUOTE_CODE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______,  _______,  _______, _______,   _______,  _______, _______, _______, RESET,            _______,
        _______, JUMP_AUDUR, _______, _______, _______, _______,  _______,  _______, JUMP_KVIKA,  _______,  _______, _______,          _______,          _______,
        _______,          _______, _______, GIT_COMMIT, _______,  BREAKPOINT,  _______, _______, _______, _______, _______,          _______, KC_PGUP, _______,
        _______, _______, _______,                             _______,                             _______, _______, _______, KC_HOME, KC_PGDN, KC_END
    ),


};
// clang-format on

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        if (IS_LAYER_ON(2)) {
            tap_code(KC_MNXT);
        }
        if (IS_LAYER_ON(1)) {
            tap_code(KC_MS_WH_DOWN);

        } else {
            tap_code(KC_VOLU);
        }

    } else {
        if (IS_LAYER_ON(2)) {
            tap_code(KC_MPRV);
        }
        if (IS_LAYER_ON(1)) {
            tap_code(KC_MS_WH_UP);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}
#endif  // ENCODER_ENABLE

#define ______ AZURE

// clang-format off

//  RGB_MATRIX_LAYOUT_LEDMAP(
//           RED,    RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED,         RED,    RED,
//           RED,    RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED,         RED,    RED,
//           YELLOW,    YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,         YELLOW,    YELLOW,
//           YELLOW,    YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,         YELLOW,         YELLOW,    YELLOW,
//           PURPLE,    PURPLE,         PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE,         PURPLE, PURPLE, PURPLE,    PURPLE,
//           PURPLE,    PURPLE,    PURPLE, PURPLE,                         PURPLE,                         PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE,    PURPLE
//     );

const ledmap PROGMEM ledmaps[] = {
    [0] = RGB_MATRIX_LAYOUT_LEDMAP(
          PURPLE,    GREEN,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  GREEN, GREEN, GREEN, GREEN, PURPLE,  PURPLE,  PURPLE,  PURPLE,  GREEN,         ______,    PURPLE,
          GREEN,   PURPLE ,   PURPLE,   PURPLE,   PURPLE, PURPLE , PURPLE , PURPLE , PURPLE , PURPLE , PURPLE , PURPLE , PURPLE , PURPLE , GREEN,           PURPLE,    GREEN,
          GREEN,   GREEN, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE,   PURPLE,         PURPLE,    GREEN,
          GREEN,     GREEN, PURPLE, PURPLE, PURPLE, PURPLE,   PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE,    GREEN,         PURPLE,    GREEN,
          GREEN,   GREEN,            PURPLE,    PURPLE,    PURPLE,    PURPLE,    PURPLE,    PURPLE, PURPLE, PURPLE, PURPLE, PURPLE,         GREEN,    GREEN, PURPLE,    GREEN,
          PURPLE,   GREEN, YELLOW,   GREEN,                         PURPLE,                         GREEN, ORANGE, GREEN, GREEN, GREEN, GREEN,    PURPLE
    ),
    [1] = RGB_MATRIX_LAYOUT_LEDMAP(
          PURPLE,    GOLDEN,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  GREEN, GREEN, GREEN, GREEN, PURPLE,  PURPLE,  PURPLE,  PURPLE,  GREEN,         ______,    PURPLE,
          GREEN,   PURPLE ,   PURPLE,   PURPLE,   PURPLE, PURPLE , PURPLE , PURPLE , PURPLE , PURPLE , PURPLE , PURPLE , PURPLE , PURPLE , GREEN,           PURPLE,    GREEN,
          GREEN,   GREEN, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE,   PURPLE,         PURPLE,    GREEN,
          GREEN,     GREEN, PURPLE, PURPLE, PURPLE, PURPLE,   PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE,    GREEN,         PURPLE,    GREEN,
          GREEN,   GREEN,            PURPLE,    PURPLE,    PURPLE,    PURPLE,    PURPLE,    PURPLE, PURPLE, PURPLE, PURPLE, PURPLE,         GREEN,    GREEN, PURPLE,    GREEN,
          PURPLE,   GREEN, YELLOW,   GREEN,                         PURPLE,                         GREEN, ORANGE, GREEN, GREEN, GREEN, GREEN,    PURPLE
    ),
    [2] = RGB_MATRIX_LAYOUT_LEDMAP(
          PURPLE,    MAGENT,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  GREEN, GREEN, GREEN, GREEN, PURPLE,  PURPLE,  PURPLE,  PURPLE,  GREEN,         ______,    PURPLE,
          GREEN,   PURPLE ,   PURPLE,   PURPLE,   PURPLE, PURPLE , PURPLE , PURPLE , PURPLE , PURPLE , PURPLE , PURPLE , PURPLE , PURPLE , GREEN,           PURPLE,    GREEN,
          GREEN,   GREEN, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE,   PURPLE,         PURPLE,    GREEN,
          GREEN,     GREEN, PURPLE, PURPLE, PURPLE, PURPLE,   PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE,    GREEN,         PURPLE,    GREEN,
          GREEN,   GREEN,            PURPLE,    PURPLE,    PURPLE,    PURPLE,    PURPLE,    PURPLE, PURPLE, PURPLE, PURPLE, PURPLE,         GREEN,    GREEN, PURPLE,    GREEN,
          PURPLE,   GREEN, YELLOW,   GREEN,                         PURPLE,                         GREEN, ORANGE, GREEN, GREEN, GREEN, GREEN,    PURPLE
    ),
};

// clang-format on
