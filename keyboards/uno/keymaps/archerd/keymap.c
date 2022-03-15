
#include QMK_KEYBOARD_H

enum uno_keycode
{
  UNO = SAFE_RANGE
};

enum encoder_names {
	_ENCODER,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
            KC_MUTE
            )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == _ENCODER) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
        return false;
    }
    return true;
}

#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom(); // Enables RGB, without saving settings
  rgblight_sethsv_noeeprom(HSV_GREEN);
  rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
}
#endif

