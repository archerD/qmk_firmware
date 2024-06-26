/*
Copyright 2021 @mangoiv

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

enum layer_number {
  _BASE,
  _NAVI,
  _MOUS,
  _MEDI,
  _NUMS,
  _SYMB,
  _FUNC,
  _GAME
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] =  LAYOUT(
             KC_QUOT,      KC_COMM,       KC_DOT,         KC_P,         KC_Y,             /*|*/          KC_F,         KC_G,         KC_C,         KC_R,         KC_L,
        LGUI_T(KC_A), LALT_T(KC_O), LCTL_T(KC_E), LSFT_T(KC_U),         KC_I,             /*|*/          KC_D, LSFT_T(KC_H), LCTL_T(KC_T), LALT_T(KC_N), LGUI_T(KC_S),
             KC_SCLN, RALT_T(KC_Q),         KC_J,         KC_K,         KC_X,             /*|*/          KC_B,         KC_M,         KC_W, RALT_T(KC_V),         KC_Z,
                                                        KC_LEAD,                          /*|*/                      TG(_GAME),
                                  LT(_MEDI,KC_ESC), LT(_NAVI,KC_SPC), LT(_MOUS,KC_TAB),   /*|*/  LT(_SYMB,KC_ENT),LT(_NUMS,KC_BSPC),LT(_FUNC,KC_DEL)
    ),
    [_NAVI] = LAYOUT(
            KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,     /*|*/      KC_AGIN,      KC_UNDO,       KC_CUT,      KC_COPY,      KC_PSTE,
          KC_LGUI,      KC_LALT,      KC_LCTL,      KC_LSFT,        KC_NO,     /*|*/      KC_CAPS,      KC_LEFT,      KC_DOWN,        KC_UP,      KC_RGHT,
            KC_NO,      KC_RALT,        KC_NO,        KC_NO,        KC_NO,     /*|*/       KC_INS,      KC_HOME,      KC_PGDN,      KC_PGUP,       KC_END,
                                                    _______,                   /*|*/                    _______,
                                        KC_NO,        KC_NO,        KC_NO,     /*|*/       KC_ENT,      KC_BSPC,       KC_DEL
    ),
    [_MOUS] = LAYOUT(
            KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,      /*|*/       KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,
          KC_LGUI,      KC_LALT,      KC_LCTL,      KC_LSFT,        KC_NO,      /*|*/       KC_NO,      KC_MS_L,      KC_MS_D,      KC_MS_U,      KC_MS_R,
            KC_NO,      KC_RALT,        KC_NO,        KC_NO,        KC_NO,      /*|*/       KC_NO,      KC_WH_L,      KC_WH_D,      KC_WH_U,      KC_WH_R,
                                                    _______,                    /*|*/                   _______,
                                        KC_NO,        KC_NO,        KC_NO,      /*|*/     KC_BTN2,      KC_BTN1,      KC_BTN3
    ),
    [_MEDI] = LAYOUT(
            KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,      /*|*/     RGB_TOG,      RGB_MOD,      RGB_HUI,      RGB_SAI,      RGB_VAI,
          KC_LGUI,      KC_LALT,      KC_LCTL,      KC_LSFT,        KC_NO,      /*|*/       KC_NO,      KC_MPRV,      KC_VOLD,      KC_VOLU,      KC_MNXT,
            KC_NO,      KC_RALT,        KC_NO,        KC_NO,        KC_NO,      /*|*/       KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,
                                                    _______,                    /*|*/                   _______,
                                        KC_NO,        KC_NO,        KC_NO,      /*|*/     KC_MSTP,      KC_MPLY,       KC_MUTE
    ),
    [_NUMS] = LAYOUT(
           KC_LBRC,         KC_1,         KC_2,         KC_3,      KC_RBRC,      /*|*/       KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,
          KC_SLASH,         KC_4,         KC_5,         KC_6,       KC_EQL,      /*|*/       KC_NO,      KC_LSFT,      KC_LCTL,      KC_LALT,      KC_LGUI,
           KC_BSLS,         KC_7,         KC_8,         KC_9,     KC_GRAVE,      /*|*/       KC_NO,        KC_NO,        KC_NO,      KC_RALT,        KC_NO,
                                                     _______,                    /*|*/                   _______,
                                        KC_DOT,         KC_0,      KC_MINS,      /*|*/       KC_NO,        KC_NO,        KC_NO
    ),
    [_SYMB] = LAYOUT(
          KC_LCBR,      KC_EXLM,        KC_AT,      KC_HASH,      KC_RCBR,       /*|*/      KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,
          KC_QUES,       KC_DLR,      KC_PERC,      KC_CIRC,      KC_PLUS,       /*|*/      KC_NO,      KC_LSFT,      KC_LCTL,      KC_LALT,      KC_LGUI,
          KC_PIPE,      KC_AMPR,      KC_ASTR,      KC_LPRN,      KC_TILD,       /*|*/      KC_NO,        KC_NO,        KC_NO,      KC_RALT,        KC_NO,
                                                    _______,                     /*|*/                  _______,
                                      KC_LPRN,      KC_RPRN,      KC_UNDS,       /*|*/      KC_NO,        KC_NO,        KC_NO
    ),
    [_FUNC] = LAYOUT(
           KC_F10,        KC_F1,        KC_F2,        KC_F3,      KC_PAUS,       /*|*/      KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,
           KC_F11,        KC_F4,        KC_F5,        KC_F6,      KC_SLCK,       /*|*/      KC_NO,      KC_LSFT,      KC_LCTL,      KC_LALT,      KC_LGUI,
           KC_F12,        KC_F7,        KC_F8,        KC_F9,      KC_PSCR,       /*|*/      KC_NO,        KC_NO,        KC_NO,      KC_RALT,        KC_NO,
                                                    _______,                     /*|*/                  _______,
                                       KC_APP,       KC_SPC,       KC_TAB,       /*|*/      KC_NO,        KC_NO,        KC_NO
    ),
    [_GAME] = LAYOUT(
           KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,   /*|*/    KC_T,     KC_Y,    KC_U,    KC_I,    KC_O,
          KC_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,   /*|*/    KC_G,     KC_H,    KC_J,    KC_K,    KC_L,
          KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,   /*|*/    KC_B,     KC_N,    KC_M, KC_COMM,  KC_DOT,
                                     _______,            /*|*/           _______,
                            KC_LCTL,  KC_SPC,  KC_ESC,   /*|*/   KC_ENT, KC_BSPC, KC_LGUI
    )
};

// leader code
LEADER_EXTERNS();
void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_ONE_KEY(KC_SPC) {
            SEND_STRING("Leader Stuff");
        }
        SEQ_ONE_KEY(KC_LEAD) {
            SEND_STRING("Crazy thing");
        }
    }
}

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
 if (is_keyboard_master()) {
    if(is_keyboard_left()){
      return OLED_ROTATION_270;
      }
      else {
        return OLED_ROTATION_90;
      }
    } else {
	    return OLED_ROTATION_0;
    }
}

static void render_logo(void) {
  static const char PROGMEM drac_logo[] = {
    // drac_logo, 128x64px
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
    0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x0c, 0x18, 0x78, 0xf0, 0xf0, 0xe0, 0xe0, 0xc0,
    0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff,
    0xff, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x07, 0x3e, 0xfc, 0xf0, 0x00, 0x00, 0x00,
    0xf0, 0xf0, 0x60, 0x30, 0x30, 0x30, 0x00, 0x00, 0xe0, 0xe0, 0x30, 0x30, 0x30, 0x30, 0x30, 0xe0,
    0xe0, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0x70, 0x30, 0x30, 0x30, 0x70, 0xe0, 0xc0, 0x00, 0x00,
    0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0,
    0x80, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xf8, 0xf0, 0x80, 0xc0, 0xe0, 0xf0, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x3f, 0xff, 0xff,
    0xff, 0xff, 0xfe, 0xfc, 0xf8, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff,
    0xff, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xc0, 0xe0, 0x7c, 0x3f, 0x0f, 0x00, 0x00, 0x00,
    0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0xf8, 0xcc, 0x8c, 0x84, 0x86, 0x86, 0xc6, 0xff,
    0xff, 0x80, 0x80, 0x00, 0x3f, 0x7f, 0xe0, 0xc0, 0x80, 0x80, 0x80, 0xc0, 0xf0, 0x71, 0x00, 0x00,
    0x1f, 0xff, 0xff, 0x80, 0x80, 0x80, 0x80, 0xc0, 0xf8, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x03, 0x03, 0x03, 0x07, 0x0f, 0x0f, 0x0f, 0x1f,
    0x7f, 0x7f, 0x3e, 0x3e, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xf8, 0xf8, 0xfc,
    0xfc, 0xfe, 0xfe, 0x7e, 0x7c, 0x78, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00,
    0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfe, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff,
    0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x60, 0x60,
    0x60, 0x60, 0x60, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xe0, 0x60, 0x60, 0x60, 0xc0,
    0xc0, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07,
    0x0f, 0x3e, 0x7c, 0xfc, 0xf8, 0xf8, 0xf8, 0xf8, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf8,
    0xf8, 0xf8, 0xfc, 0xfc, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x7f, 0x3f, 0x1f, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff,
    0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf1, 0x99, 0x18, 0x08,
    0x0c, 0x0c, 0x8c, 0xff, 0xff, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xc1, 0x80, 0x00, 0x00, 0x00, 0x80,
    0xc3, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x0f, 0x0f, 0x0f, 0x1f, 0x1f, 0x1f, 0x1f,
    0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x0f, 0x0f, 0x07, 0x07, 0x03, 0x03, 0x01,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
    0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03,
    0x03, 0x03, 0x01, 0x01, 0x03, 0x03, 0x03, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x01,
    0x01, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
  };
  oled_write_raw_P(drac_logo, sizeof(drac_logo));
}

static void render_status(void) {
    oled_write_P(PSTR("This is\n~~~~~~~~~\nDracu\nLad\n~~~~~~~~~\nv1.0\n~~~~~~~~~\n"), false);
    uint8_t n = get_current_wpm();
    char    wpm_counter[4];
    wpm_counter[3] = '\0';
    wpm_counter[2] = '0' + n % 10;
    wpm_counter[1] = (n /= 10) % 10 ? '0' + (n) % 10 : (n / 10) % 10 ? '0' : ' ';
    wpm_counter[0] = n / 10 ? '0' + n / 10 : ' ';
    oled_write_P(PSTR("WPM:"), false);
    oled_write(wpm_counter, false);
    oled_write_P(PSTR("\n"), false);
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.caps_lock ? PSTR("CAPS ") : PSTR("     "), false);
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(leading ? PSTR("L") : PSTR(" "), false);
    oled_write_P(PSTR("\n"), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("Base    "), false);
            break;
        case _NAVI:
            oled_write_P(PSTR("Nav     "), false);
            break;
        case _MOUS:
            oled_write_P(PSTR("Mouse   "), false);
            break;
        case _MEDI:
            oled_write_P(PSTR("Media   "), false);
            break;
        case _NUMS:
            oled_write_P(PSTR("Numbers "), false);
            break;
        case _SYMB:
            oled_write_P(PSTR("Symbols "), false);
            break;
        case _FUNC:
            oled_write_P(PSTR("Function"), false);
            break;
        case _GAME:
            oled_write_P(PSTR("Gaming  "), false);
            break;
        default:
            oled_write_P(PSTR("Unknown "), false);
    }
}

bool oled_task_user(void) {
      if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_logo();
    }
    return false;
}

#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 2) {
      if(clockwise) {
        tap_code(KC_PGUP);
      }
      else{
        tap_code(KC_PGDN);
      }
    }
    else if (index == 3  ) {
        // Page up/Page down
        if (clockwise) {
          tap_code(KC_WH_U);
        } else {
          tap_code(KC_WH_D);
        }
    }
    return true;
}
#endif
