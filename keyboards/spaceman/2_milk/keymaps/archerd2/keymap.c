#include QMK_KEYBOARD_H

enum combos {
    VOLUME_MUTE,
};

const uint16_t PROGMEM vuvd_combo[] = {KC_VOLU, KC_VOLD, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(vuvd_combo, KC_MUTE),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
      [0] = LAYOUT(
          KC_VOLU,
          KC_VOLD
          )
};
