#include QMK_KEYBOARD_H
#include "rgb_matrix_ledmaps.h"
#include "rgb_matrix_ledmaps.c"
#include "encoder.c"


enum custom_keycodes { GIT_COMMIT = SAFE_RANGE, JUMP_AUDUR, JUMP_KVIKA, QUOTE_CODE, BREAKPOINT, RGB_LAYERS_TOGGLE, BRB};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    };
    switch (keycode) {
        case RGB_LAYERS_TOGGLE:
            rgb_matrix_layers_toggle();
            break;
        case GIT_COMMIT:
            SEND_STRING("git commit");
            break;
        case JUMP_AUDUR:
            SEND_STRING("jump audur-api\n");
            break;
        case JUMP_KVIKA:
            SEND_STRING("jump kvika-api\n");
            break;
        case QUOTE_CODE:
            SEND_STRING("```\n\n```\n");
            break;
        case BREAKPOINT:
            SEND_STRING("\nbreakpoint()\n");
            break;
        case BRB:
            // Move to chat workspace 
            register_code(KC_LGUI);
            tap_code(KC_C);
            unregister_code(KC_LGUI);

            // Search for channel            
            wait_ms(500);
            register_code(KC_LCTL);
            tap_code(KC_K);
            unregister_code(KC_LCTL);
            wait_ms(500);
     
            SEND_STRING("kvika-backend");
            tap_code(KC_ENT);

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
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          _______,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          TO(3),
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_END,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_DEL,
        KC_LCTL, KC_LGUI, KC_LALT,                             KC_SPC,                            KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT(
        //KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,           KC_MPLY,
        _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______, _______, _______, _______, _______,           KC_MPLY,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          TO(1),
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          _______,
        LT(2, KC_CAPS), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           _______,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, _______,   _______,
        KC_LCTL, KC_LGUI, KC_LALT,                             LT(3, KC_SPC),                             KC_RALT, MO(1),   KC_RCTL, _______, _______, _______
    ),

    [2] = LAYOUT(
        _______, KC_MYCM, KC_WHOM, KC_CALC, KC_MSEL, KC_MPRV,  KC_MNXT,  KC_MPLY, KC_MSTP, KC_MUTE, KC_VOLD, KC_VOLU, _______, KC_INS,           _______,
        RGB_LAYERS_TOGGLE, RGB_TOG, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, _______, _______, _______,          TO(2),
        _______, _______, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI,  BL_TOGG,  BL_BRTG, BL_ON,   BL_INC,  _______, _______, _______, RESET,             TO(0),
        _______, _______, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD,  BL_STEP,  _______, BL_OFF,  BL_DEC,  _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______,  _______,  NK_TOGG, _______, _______, _______, _______,          _______, RGB_MOD, _______,
        _______, _______, _______,                             _______,                             _______, _______, _______, RGB_SPD, RGB_RMOD, RGB_SPI
    ),


    [3] = LAYOUT(
        _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______, _______, _______, _______, _______,           KC_MUTE,
        QUOTE_CODE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           TO(3),
        _______, _______, _______, _______, _______, _______,  _______,  _______, _______,   _______,  _______, _______, _______, _______,             TO(1),
        _______, JUMP_AUDUR, _______, _______, _______, _______,  KC_HOME,  KC_PGUP, KC_PGDN,  KC_END,  _______, _______,          _______,          _______,
        _______,          _______, _______, GIT_COMMIT, _______,  BREAKPOINT,  _______, _______, _______, _______, _______,          _______, KC_PGUP, _______,
        _______, _______, _______,                             BRB,                             _______, _______, _______, KC_HOME, KC_PGDN, KC_END
    ),

    [4] = LAYOUT(
        _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______, _______, _______, _______, _______,           _______,
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           TO(4),
        _______, _______, _______, _______, _______, _______,  _______,  _______, _______,   _______,  _______, _______, _______, _______,            TO(2),
        _______, _______, _______, _______, _______, _______,  KC_LEFT,  KC_DOWN, KC_UP,  KC_RGHT,  _______, _______,          _______,           _______,
        _______,          _______, _______, _______, _______,  _______,  _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                             _______,                             _______, _______, _______, _______, _______, _______
    ),


};
// clang-format on

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
          PURPLE,    GREEN,  PURPLE,  YELLOW,  PURPLE,  PURPLE,  GREEN, GREEN, GREEN, GREEN, PURPLE,  PURPLE,  PURPLE,  PURPLE,  GREEN,         ______,    PURPLE,
          GREEN,   PURPLE ,   PURPLE,   PURPLE,   PURPLE, PURPLE , PURPLE , PURPLE , PURPLE , PURPLE , PURPLE , PURPLE , PURPLE , PURPLE , GREEN,           PURPLE,    GREEN,
          GREEN,   GREEN, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE,   PURPLE,         PURPLE,    GREEN,
          GREEN,     GREEN, PURPLE, PURPLE, PURPLE, PURPLE,   PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE,    GREEN,         PURPLE,    GREEN,
          GREEN,   GREEN,            PURPLE,    PURPLE,    PURPLE,    PURPLE,    PURPLE,    PURPLE, PURPLE, PURPLE, PURPLE, PURPLE,         GREEN,    GREEN, PURPLE,    GREEN,
          PURPLE,   GREEN, YELLOW,   GREEN,                         PURPLE,                         GREEN, ORANGE, GREEN, GREEN, GREEN, GREEN,    PURPLE
    ),
    [2] = RGB_MATRIX_LAYOUT_LEDMAP(
          PURPLE,    GREEN,  PURPLE,  PURPLE,  YELLOW,  PURPLE,  GREEN, GREEN, GREEN, GREEN, PURPLE,  PURPLE,  PURPLE,  PURPLE,  GREEN,         ______,    PURPLE,
          GREEN,   PURPLE ,   PURPLE,   PURPLE,   PURPLE, PURPLE , PURPLE , PURPLE , PURPLE , PURPLE , PURPLE , PURPLE , PURPLE , PURPLE , GREEN,           PURPLE,    GREEN,
          GREEN,   GREEN, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE,   PURPLE,         PURPLE,    GREEN,
          GREEN,     GREEN, PURPLE, PURPLE, PURPLE, PURPLE,   PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE,    GREEN,         PURPLE,    GREEN,
          GREEN,   GREEN,            PURPLE,    PURPLE,    PURPLE,    PURPLE,    PURPLE,    PURPLE, PURPLE, PURPLE, PURPLE, PURPLE,         GREEN,    GREEN, PURPLE,    GREEN,
          PURPLE,   GREEN, YELLOW,   GREEN,                         PURPLE,                         GREEN, ORANGE, GREEN, GREEN, GREEN, GREEN,    PURPLE
    ),
    [3] = RGB_MATRIX_LAYOUT_LEDMAP(
          PURPLE,    GREEN,  PURPLE,  PURPLE,  PURPLE,  YELLOW,  GREEN, GREEN, GREEN, GREEN, PURPLE,  PURPLE,  PURPLE,  PURPLE,  GREEN,         ______,    PURPLE,
          GREEN,   PURPLE ,   PURPLE,   PURPLE,   PURPLE, PURPLE , PURPLE , PURPLE , PURPLE , PURPLE , PURPLE , PURPLE , PURPLE , PURPLE , GREEN,           PURPLE,    GREEN,
          GREEN,   GREEN, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE,   PURPLE,         PURPLE,    GREEN,
          GREEN,     GREEN, PURPLE, PURPLE, PURPLE, PURPLE,   PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE,    GREEN,         PURPLE,    GREEN,
          GREEN,   GREEN,            PURPLE,    PURPLE,    PURPLE,    PURPLE,    PURPLE,    PURPLE, PURPLE, PURPLE, PURPLE, PURPLE,         GREEN,    GREEN, PURPLE,    GREEN,
          PURPLE,   GREEN, YELLOW,   GREEN,                         PURPLE,                         GREEN, ORANGE, GREEN, GREEN, GREEN, GREEN,    PURPLE
    ),
    [4] = RGB_MATRIX_LAYOUT_LEDMAP(
          PURPLE,    GREEN,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  YELLOW, GREEN, GREEN, GREEN, PURPLE,  PURPLE,  PURPLE,  PURPLE,  GREEN,         ______,    PURPLE,
          GREEN,   PURPLE ,   PURPLE,   PURPLE,   PURPLE, PURPLE , PURPLE , PURPLE , PURPLE , PURPLE , PURPLE , PURPLE , PURPLE , PURPLE , GREEN,           PURPLE,    GREEN,
          GREEN,   GREEN, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE,   PURPLE,         PURPLE,    GREEN,
          GREEN,     GREEN, PURPLE, PURPLE, PURPLE, PURPLE,   PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE,    GREEN,         PURPLE,    GREEN,
          GREEN,   GREEN,            PURPLE,    PURPLE,    PURPLE,    PURPLE,    PURPLE,    PURPLE, PURPLE, PURPLE, PURPLE, PURPLE,         GREEN,    GREEN, PURPLE,    GREEN,
          PURPLE,   GREEN, YELLOW,   GREEN,                         PURPLE,                         GREEN, ORANGE, GREEN, GREEN, GREEN, GREEN,    PURPLE
    ),
};

// clang-format on
