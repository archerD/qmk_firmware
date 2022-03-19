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
#include <string.h>

// layers:
//  base
#define L_BASE 0
//  navigation
#define L_NAVI 1
//  mouse
#define L_MOUS 2
//  media
#define L_MEDI 3
//  numbers
#define L_NUMS 4
//  symbols
#define L_SYMS 5
//  function and system keys
#define L_FUNC 6
//  gaming
#define L_GAME 7

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_BASE] = LAYOUT_split_3x6_3( //default
 //,-----------------------------------------------------------------------------------.    ,-----------------------------------------------------------------------------------.
       TG(L_NUMS),      KC_QUOT,      KC_COMM,       KC_DOT,         KC_P,         KC_Y,              KC_F,         KC_G,         KC_C,         KC_R,         KC_L,   TG(L_GAME),
 //|-------------+-------------+-------------+-------------+-------------+-------------|    |-------------+-------------+-------------+-------------+-------------+-------------|
          KC_LEAD, LGUI_T(KC_A), LALT_T(KC_O), LCTL_T(KC_E), LSFT_T(KC_U),         KC_I,              KC_D, LSFT_T(KC_H), LCTL_T(KC_T), LALT_T(KC_N), LGUI_T(KC_S),  OSL(L_MEDI),
 //|-------------+-------------+-------------+-------------+-------------+-------------|    |-------------+-------------+-------------+-------------+-------------+-------------|
            KC_NO,      KC_SCLN, RALT_T(KC_Q),         KC_J,         KC_K,         KC_X,              KC_B,         KC_M,         KC_W, RALT_T(KC_V),         KC_Z,        KC_NO,
 //|-------------+-------------+-------------+-------------+-------------+-------------|    |-------------+-------------+-------------+-------------+-------------+-------------|
                                  LT(L_MEDI,KC_ESC),LT(L_NAVI,KC_SPC),LT(L_MOUS,KC_TAB),     LT(L_SYMS,KC_ENT),LT(L_NUMS,KC_BSPC),LT(L_FUNC,KC_DEL)
                                           //`-----------------------------------------'    `-----------------------------------------'
            ),
    [L_NAVI] = LAYOUT_split_3x6_3( //navigation
 //,-----------------------------------------------------------------------------------.    ,-----------------------------------------------------------------------------------.
          _______,        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,           KC_AGIN,      KC_UNDO,       KC_CUT,      KC_COPY,      KC_PSTE,      _______,
 //|-------------+-------------+-------------+-------------+-------------+-------------|    |-------------+-------------+-------------+-------------+-------------+-------------|
          _______,      KC_LGUI,      KC_LALT,      KC_LCTL,      KC_LSFT,        KC_NO,           KC_CAPS,      KC_LEFT,      KC_DOWN,        KC_UP,      KC_RGHT,      _______,
 //|-------------+-------------+-------------+-------------+-------------+-------------|    |-------------+-------------+-------------+-------------+-------------+-------------|
          _______,        KC_NO,      KC_RALT,        KC_NO,        KC_NO,        KC_NO,            KC_INS,      KC_HOME,      KC_PGDN,      KC_PGUP,       KC_END,      _______,
 //|-------------+-------------+-------------+-------------+-------------+-------------|    |-------------+-------------+-------------+-------------+-------------+-------------|
                                                      KC_NO,        KC_NO,        KC_NO,            KC_ENT,      KC_BSPC,       KC_DEL
                                           //`-----------------------------------------'    `-----------------------------------------'
            ),
    [L_MOUS] = LAYOUT_split_3x6_3( //mouse
 //,-----------------------------------------------------------------------------------.    ,-----------------------------------------------------------------------------------.
          _______,        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,             KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,      _______,
 //|-------------+-------------+-------------+-------------+-------------+-------------|    |-------------+-------------+-------------+-------------+-------------+-------------|
          _______,      KC_LGUI,      KC_LALT,      KC_LCTL,      KC_LSFT,        KC_NO,             KC_NO,      KC_MS_L,      KC_MS_D,      KC_MS_U,      KC_MS_R,      _______,
 //|-------------+-------------+-------------+-------------+-------------+-------------|    |-------------+-------------+-------------+-------------+-------------+-------------|
          _______,        KC_NO,      KC_RALT,        KC_NO,        KC_NO,        KC_NO,             KC_NO,      KC_WH_L,      KC_WH_D,      KC_WH_U,      KC_WH_R,      _______,
 //|-------------+-------------+-------------+-------------+-------------+-------------|    |-------------+-------------+-------------+-------------+-------------+-------------|
                                                      KC_NO,        KC_NO,        KC_NO,           KC_BTN2,      KC_BTN1,      KC_BTN3
                                           //`-----------------------------------------'    `-----------------------------------------'
            ),
    [L_MEDI] = LAYOUT_split_3x6_3( //media
 //,-----------------------------------------------------------------------------------.    ,-----------------------------------------------------------------------------------.
          _______,        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,           RGB_TOG,      RGB_MOD,      RGB_HUI,      RGB_SAI,      RGB_VAI,      RGB_SPI,
 //|-------------+-------------+-------------+-------------+-------------+-------------|    |-------------+-------------+-------------+-------------+-------------+-------------|
          _______,      KC_LGUI,      KC_LALT,      KC_LCTL,      KC_LSFT,        KC_NO,             KC_NO,      KC_MPRV,      KC_VOLD,      KC_VOLU,      KC_MNXT,      _______,
 //|-------------+-------------+-------------+-------------+-------------+-------------|    |-------------+-------------+-------------+-------------+-------------+-------------|
          _______,        KC_NO,      KC_RALT,        KC_NO,        KC_NO,        KC_NO,             KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,      _______,
 //|-------------+-------------+-------------+-------------+-------------+-------------|    |-------------+-------------+-------------+-------------+-------------+-------------|
                                                      KC_NO,        KC_NO,        KC_NO,           KC_MSTP,      KC_MPLY,       KC_MUTE
                                           //`-----------------------------------------'    `-----------------------------------------'
            ),
    [L_NUMS] = LAYOUT_split_3x6_3( //numbers
 //,-----------------------------------------------------------------------------------.    ,-----------------------------------------------------------------------------------.
          _______,      KC_LBRC,         KC_1,         KC_2,         KC_3,      KC_RBRC,             KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,      _______,
 //|-------------+-------------+-------------+-------------+-------------+-------------|    |-------------+-------------+-------------+-------------+-------------+-------------|
          _______,     KC_SLASH,         KC_4,         KC_5,         KC_6,       KC_EQL,             KC_NO,      KC_LSFT,      KC_LCTL,      KC_LALT,      KC_LGUI,      _______,
 //|-------------+-------------+-------------+-------------+-------------+-------------|    |-------------+-------------+-------------+-------------+-------------+-------------|
          _______,      KC_BSLS,         KC_7,         KC_8,         KC_9,     KC_GRAVE,             KC_NO,        KC_NO,        KC_NO,      KC_RALT,        KC_NO,      _______,
 //|-------------+-------------+-------------+-------------+-------------+-------------|    |-------------+-------------+-------------+-------------+-------------+-------------|
                                                     KC_DOT,         KC_0,      KC_MINS,             KC_NO,        KC_NO,        KC_NO
                                           //`-----------------------------------------'    `-----------------------------------------'
            ),
    [L_SYMS] = LAYOUT_split_3x6_3( // shifted numbers
 //,-----------------------------------------------------------------------------------.    ,-----------------------------------------------------------------------------------.
          _______,      KC_LCBR,      KC_EXLM,        KC_AT,      KC_HASH,      KC_RCBR,             KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,      _______,
 //|-------------+-------------+-------------+-------------+-------------+-------------|    |-------------+-------------+-------------+-------------+-------------+-------------|
          _______,      KC_QUES,       KC_DLR,      KC_PERC,      KC_CIRC,      KC_PLUS,             KC_NO,      KC_LSFT,      KC_LCTL,      KC_LALT,      KC_LGUI,      _______,
 //|-------------+-------------+-------------+-------------+-------------+-------------|    |-------------+-------------+-------------+-------------+-------------+-------------|
          _______,      KC_PIPE,      KC_AMPR,      KC_ASTR,      KC_LPRN,      KC_TILD,             KC_NO,        KC_NO,        KC_NO,      KC_RALT,        KC_NO,      _______,
 //|-------------+-------------+-------------+-------------+-------------+-------------|    |-------------+-------------+-------------+-------------+-------------+-------------|
                                                    KC_LPRN,      KC_RPRN,      KC_UNDS,             KC_NO,        KC_NO,        KC_NO
                                           //`-----------------------------------------'    `-----------------------------------------'
            ),
    [L_FUNC] = LAYOUT_split_3x6_3( //function keys
 //,-----------------------------------------------------------------------------------.    ,-----------------------------------------------------------------------------------.
          _______,       KC_F10,        KC_F1,        KC_F2,        KC_F3,      KC_PAUS,             KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,      _______,
 //|-------------+-------------+-------------+-------------+-------------+-------------|    |-------------+-------------+-------------+-------------+-------------+-------------|
          _______,       KC_F11,        KC_F4,        KC_F5,        KC_F6,      KC_SLCK,             KC_NO,      KC_LSFT,      KC_LCTL,      KC_LALT,      KC_LGUI,      _______,
 //|-------------+-------------+-------------+-------------+-------------+-------------|    |-------------+-------------+-------------+-------------+-------------+-------------|
          _______,       KC_F12,        KC_F7,        KC_F8,        KC_F9,      KC_PSCR,             KC_NO,        KC_NO,        KC_NO,      KC_RALT,        KC_NO,      _______,
 //|-------------+-------------+-------------+-------------+-------------+-------------|    |-------------+-------------+-------------+-------------+-------------+-------------|
                                                     KC_APP,       KC_SPC,       KC_TAB,             KC_NO,        KC_NO,        KC_NO
                                           //`-----------------------------------------'    `-----------------------------------------'
            ),
  [L_GAME] = LAYOUT_split_3x6_3( // gaming
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL,  KC_SPC,  KC_ESC,     KC_ENT, KC_BSPC, KC_LGUI
                                      //`--------------------------'  `--------------------------'
            ) };

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
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE_MASK (1 << L_BASE)
#define L_NAVI_MASK (1 << L_NAVI)
#define L_MOUS_MASK (1 << L_MOUS)
#define L_MEDI_MASK (1 << L_MEDI)
#define L_NUMS_MASK (1 << L_NUMS)
#define L_SYMS_MASK (1 << L_SYMS)
#define L_FUNC_MASK (1 << L_FUNC)
#define L_GAME_MASK (1 << L_GAME)

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case L_BASE:
            oled_write_ln_P(PSTR("Letters"), false);
            break;
        case L_NAVI:
            oled_write_ln_P(PSTR("Navigation"), false);
            break;
        case L_MOUS:
            oled_write_ln_P(PSTR("Mouse"), false);
            break;
        case L_MEDI:
            oled_write_ln_P(PSTR("Media"), false);
            break;
        case L_NUMS:
            oled_write_ln_P(PSTR("Numbers"), false);
            break;
        case L_SYMS:
            oled_write_ln_P(PSTR("Symbols"), false);
            break;
        case L_FUNC:
            oled_write_ln_P(PSTR("Function Keys"), false);
            break;
        case L_GAME:
            oled_write_ln_P(PSTR("Gaming"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Unknown Layer"), false);
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  char keylog_str_temp[24] = {};
  strcpy(keylog_str_temp, get_u8_str(record->event.key.row, '0'));
  strcat(keylog_str_temp, "x");
  strcat(keylog_str_temp, get_u8_str(record->event.key.col, '0'));
  strcat(keylog_str_temp, ", k");
  strcat(keylog_str_temp, get_u16_str(keycode, '0'));
  strcat(keylog_str_temp, " : ");
  strncat(keylog_str_temp, &name, 1);
  strcpy(keylog_str, keylog_str_temp);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
    oled_write_ln("", false);
}

void oled_render_led_status(void) {
    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    oled_write_P(leading ? PSTR("LDG ") : PSTR("    "), false);
    oled_write_ln("", false);
}

void oled_render_wpm(void) {
    oled_write_P(PSTR("WPM: "), false);
    oled_write_ln(get_u8_str(get_current_wpm(), ' '), false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
        oled_render_led_status();
        oled_render_wpm();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE
