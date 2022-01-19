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
