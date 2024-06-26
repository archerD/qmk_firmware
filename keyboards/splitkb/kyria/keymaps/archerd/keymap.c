/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include <string.h>

#define LAYOUT_def( \
    L00, L01, L02, L03, L04, L05,                     R06, R07, R08, R09, R10, R11, \
    L12, L13, L14, L15, L16, L17,                     R18, R19, R20, R21, R22, R23, \
    L24, L25, L26, L27, L28, L29,                     R34, R35, R36, R37, R38, R39, \
                   L40, L41, L42, L43, L44, R45, R46, R47, R48, R49 \
        ) \
    LAYOUT( \
    L00, L01, L02, L03, L04, L05,                                 R06, R07, R08, R09, R10, R11, \
    L12, L13, L14, L15, L16, L17,                                 R18, R19, R20, R21, R22, R23, \
    L24, L25, L26, L27, L28, L29,KC_MPRV,KC_MNXT,KC_VOLD,KC_VOLU, R34, R35, R36, R37, R38, R39, \
                   L40, L41, L42,    L43,    L44,    R45,    R46, R47, R48, R49 \
       )

enum layers {
    //_QWERTY = 0,
    //_DVORAK,
    //_COLEMAK_DH,
    //_NAV,
    //_SYM,
    //_FUNCTION,
    //_ADJUST,
    _BASE = 0,
    _NAVI,
    _MOUS,
    _MEDI,
    _NUMS,
    _SYMB,
    _FUNC,
    _GAME,
};


// Aliases for readability
//#define QWERTY   DF(_QWERTY)
//#define COLEMAK  DF(_COLEMAK_DH)
//#define DVORAK   DF(_DVORAK)

//#define SYM      MO(_SYM)
//#define NAV      MO(_NAV)
//#define FKEYS    MO(_FUNCTION)
//#define ADJUST   MO(_ADJUST)

//#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
//#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
//#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
//#define ALT_ENT  MT(MOD_LALT, KC_ENT)

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_def(
 //,-----------------------------------------------------------------------------------.                ,-----------------------------------------------------------------------------------.
        TG(_NUMS),      KC_QUOT,      KC_COMM,       KC_DOT,         KC_P,         KC_Y,                          KC_F,         KC_G,         KC_C,         KC_R,         KC_L,    TG(_GAME),
 //|-------------+-------------+-------------+-------------+-------------+-------------|                |-------------+-------------+-------------+-------------+-------------+-------------|
          QK_LEAD, LGUI_T(KC_A), LALT_T(KC_O), LCTL_T(KC_E), LSFT_T(KC_U),         KC_I,                          KC_D, LSFT_T(KC_H), LCTL_T(KC_T), LALT_T(KC_N), LGUI_T(KC_S),   OSL(_MEDI),
 //|-------------+-------------+-------------+-------------+-------------+-------------|                |-------------+-------------+-------------+-------------+-------------+-------------|
            KC_NO,      KC_SCLN,        KC_Q ,         KC_J,         KC_K,         KC_X,                          KC_B,         KC_M,         KC_W,        KC_V ,         KC_Z,        KC_NO,
 //|-------------+-------------+-------------+-------------+-------------+-------------|                |-------------+-------------+-------------+-------------+-------------+-------------|
                          KC_MPLY,   LT(_MEDI,KC_ESC),LT(_NAVI,KC_SPC),LT(_MOUS,KC_TAB), KC_NO,  KC_NO, LT(_SYMB,KC_ENT),LT(_NUMS,KC_BSPC),LT(_FUNC,KC_DEL), KC_MUTE
                                           //`-----------------------------------------'                `-----------------------------------------'
    ),


    [_NAVI] = LAYOUT_def(
 //,-----------------------------------------------------------------------------------.                ,-----------------------------------------------------------------------------------.
          _______,        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,                       KC_AGIN,      KC_UNDO,       KC_CUT,      KC_COPY,      KC_PSTE,      _______,
 //|-------------+-------------+-------------+-------------+-------------+-------------|                |-------------+-------------+-------------+-------------+-------------+-------------|
          _______,      KC_LGUI,      KC_LALT,      KC_LCTL,      KC_LSFT,        KC_NO,                       KC_CAPS,      KC_LEFT,      KC_DOWN,        KC_UP,      KC_RGHT,      _______,
 //|-------------+-------------+-------------+-------------+-------------+-------------|                |-------------+-------------+-------------+-------------+-------------+-------------|
          _______,        KC_NO,      KC_RALT,        KC_NO,        KC_NO,        KC_NO,                        KC_INS,      KC_HOME,      KC_PGDN,      KC_PGUP,       KC_END,      _______,
 //|-------------+-------------+-------------+-------------+-------------+-------------|                |-------------+-------------+-------------+-------------+-------------+-------------|
                                      _______,        KC_NO,        KC_NO,        KC_NO, KC_NO,  KC_NO,         KC_ENT,      KC_BSPC,       KC_DEL,      _______
                                           //`-----------------------------------------'                `-----------------------------------------'
            ),


    [_MOUS] = LAYOUT_def(
 //,-----------------------------------------------------------------------------------.                ,-----------------------------------------------------------------------------------.
          _______,        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,                         KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,      _______,
 //|-------------+-------------+-------------+-------------+-------------+-------------|                |-------------+-------------+-------------+-------------+-------------+-------------|
          _______,      KC_LGUI,      KC_LALT,      KC_LCTL,      KC_LSFT,        KC_NO,                         KC_NO,      KC_MS_L,      KC_MS_D,      KC_MS_U,      KC_MS_R,      _______,
 //|-------------+-------------+-------------+-------------+-------------+-------------|                |-------------+-------------+-------------+-------------+-------------+-------------|
          _______,        KC_NO,      KC_RALT,        KC_NO,        KC_NO,        KC_NO,                         KC_NO,      KC_WH_L,      KC_WH_D,      KC_WH_U,      KC_WH_R,      _______,
 //|-------------+-------------+-------------+-------------+-------------+-------------|                |-------------+-------------+-------------+-------------+-------------+-------------|
                                      _______,        KC_NO,        KC_NO,        KC_NO, KC_NO,  KC_NO,        KC_BTN2,      KC_BTN1,      KC_BTN3,      _______
                                           //`-----------------------------------------'                `-----------------------------------------'
            ),


    [_MEDI] = LAYOUT_def(
 //,-----------------------------------------------------------------------------------.                ,-----------------------------------------------------------------------------------.
          _______,        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,                       RGB_TOG,      RGB_MOD,      RGB_HUI,      RGB_SAI,      RGB_VAI,      RGB_SPI,
 //|-------------+-------------+-------------+-------------+-------------+-------------|                |-------------+-------------+-------------+-------------+-------------+-------------|
          _______,      KC_LGUI,      KC_LALT,      KC_LCTL,      KC_LSFT,        KC_NO,                         KC_NO,      KC_MPRV,      KC_VOLD,      KC_VOLU,      KC_MNXT,      _______,
 //|-------------+-------------+-------------+-------------+-------------+-------------|                |-------------+-------------+-------------+-------------+-------------+-------------|
          _______,        KC_NO,      KC_RALT,        KC_NO,        KC_NO,        KC_NO,                         KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,      _______,
 //|-------------+-------------+-------------+-------------+-------------+-------------|                |-------------+-------------+-------------+-------------+-------------+-------------|
                                      _______,        KC_NO,        KC_NO,        KC_NO, KC_NO,  KC_NO,        KC_MSTP,      KC_MPLY,       KC_MUTE,     _______
                                           //`-----------------------------------------'                `-----------------------------------------'
            ),

    [_NUMS] = LAYOUT_def(
 //,-----------------------------------------------------------------------------------.                ,-----------------------------------------------------------------------------------.
          _______,      KC_LBRC,         KC_1,         KC_2,         KC_3,      KC_RBRC,                         KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,      _______,
 //|-------------+-------------+-------------+-------------+-------------+-------------|                |-------------+-------------+-------------+-------------+-------------+-------------|
          _______,     KC_SLASH,         KC_4,         KC_5,         KC_6,       KC_EQL,                         KC_NO,      KC_LSFT,      KC_LCTL,      KC_LALT,      KC_LGUI,      _______,
 //|-------------+-------------+-------------+-------------+-------------+-------------|                |-------------+-------------+-------------+-------------+-------------+-------------|
          _______,      KC_BSLS,         KC_7,         KC_8,         KC_9,     KC_GRAVE,                         KC_NO,        KC_NO,        KC_NO,      KC_RALT,        KC_NO,      _______,
 //|-------------+-------------+-------------+-------------+-------------+-------------|                |-------------+-------------+-------------+-------------+-------------+-------------|
                                      _______,       KC_DOT,         KC_0,      KC_MINS, KC_NO,  KC_NO,          KC_NO,        KC_NO,        KC_NO,      _______
                                           //`-----------------------------------------'                `-----------------------------------------'
            ),

    [_SYMB] = LAYOUT_def(
 //,-----------------------------------------------------------------------------------.                ,-----------------------------------------------------------------------------------.
          _______,      KC_LCBR,      KC_EXLM,        KC_AT,      KC_HASH,      KC_RCBR,                         KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,      _______,
 //|-------------+-------------+-------------+-------------+-------------+-------------|                |-------------+-------------+-------------+-------------+-------------+-------------|
          _______,      KC_QUES,       KC_DLR,      KC_PERC,      KC_CIRC,      KC_PLUS,                         KC_NO,      KC_LSFT,      KC_LCTL,      KC_LALT,      KC_LGUI,      _______,
 //|-------------+-------------+-------------+-------------+-------------+-------------|                |-------------+-------------+-------------+-------------+-------------+-------------|
          _______,      KC_PIPE,      KC_AMPR,      KC_ASTR,      KC_LPRN,      KC_TILD,                         KC_NO,        KC_NO,        KC_NO,      KC_RALT,        KC_NO,      _______,
 //|-------------+-------------+-------------+-------------+-------------+-------------|                |-------------+-------------+-------------+-------------+-------------+-------------|
                                      _______,      KC_LPRN,      KC_RPRN,      KC_UNDS, KC_NO,  KC_NO,          KC_NO,        KC_NO,        KC_NO,      _______
                                           //`-----------------------------------------'                `-----------------------------------------'
            ),

    [_FUNC] = LAYOUT_def(
 //,-----------------------------------------------------------------------------------.                ,-----------------------------------------------------------------------------------.
          _______,       KC_F10,        KC_F1,        KC_F2,        KC_F3,      KC_PAUS,                         KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,      _______,
 //|-------------+-------------+-------------+-------------+-------------+-------------|                |-------------+-------------+-------------+-------------+-------------+-------------|
          _______,       KC_F11,        KC_F4,        KC_F5,        KC_F6,      KC_SCRL,                         KC_NO,      KC_LSFT,      KC_LCTL,      KC_LALT,      KC_LGUI,      _______,
 //|-------------+-------------+-------------+-------------+-------------+-------------|                |-------------+-------------+-------------+-------------+-------------+-------------|
          _______,       KC_F12,        KC_F7,        KC_F8,        KC_F9,      KC_PSCR,                         KC_NO,        KC_NO,        KC_NO,      KC_RALT,        KC_NO,      _______,
 //|-------------+-------------+-------------+-------------+-------------+-------------|                |-------------+-------------+-------------+-------------+-------------+-------------|
                                      _______,       KC_APP,       KC_SPC,       KC_TAB, KC_NO,  KC_NO,          KC_NO,        KC_NO,        KC_NO,      _______
                                           //`-----------------------------------------'                `-----------------------------------------'
            ),

  [_GAME] = LAYOUT_def(
  //,-----------------------------------------------------.                                  ,-----------------------------------------------------.
         KC_T,  KC_TAB,    KC_Q,    KC_X,    KC_E,    KC_R,                                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, _______,
  //|--------+--------+--------+--------+--------+--------|                                  |--------+--------+--------+--------+--------+--------|
         KC_G, KC_LSFT,    KC_A,    KC_W,    KC_D,    KC_F,                                       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, _______,
  //|--------+--------+--------+--------+--------+--------|                                  |--------+--------+--------+--------+--------+--------|
         KC_B, KC_CAPS,    KC_Z,    KC_S,    KC_C,    KC_V,                                       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, _______,
  //|--------+--------+--------+--------+--------+--------+--------|                |--------+--------+--------+--------+--------+--------+--------|
                                 _______, KC_NO,  KC_LCTL,  KC_SPC,  KC_ESC, KC_NO,    KC_ENT, KC_BSPC, KC_LGUI,   KC_F5
                                      //`--------------------------'                `--------------------------'
            )
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),

// /*
//  * Layer stack template
//  *
//  * ,-------------------------------------------.
//  * |        |      |      |      |      |      |
//  * |--------+------+------+------+------+------|
//  * |        |      |      |      |      |      |
//  * |--------+------+------+------+------+------+-------------.
//  * |        |      |      |      |      |      |      |      |
//  * `----------------------+------+------+------+------+------|
//  *                        |      |      |      |      |      |
//  *                        |      |      |      |      |      |
//  *                        `----------------------------------'
//  *
//  *                        ,-------------------------------------------.
//  *                        |      |      |      |      |      |        |
//  *                        |------+------+------+------+------+--------|
//  *                        |      |      |      |      |      |        |
//  *          ,-------------+------+------+------+------+------+--------|
//  *          |      |      |      |      |      |      |      |        |
//  *          |------+------+------+------+------+----------------------'
//  *          |      |      |      |      |      |
//  *          |      |      |      |      |      |
//  *          `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT_stack(
//       _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______,
//
//                                  _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______,
//                _______, _______, _______, _______, _______, _______, _______, _______,
//                _______, _______, _______, _______, _______
//     ),
};

/* liatris led disable code (currently using the led as caps lock indicator)
void keyboard_pre_init_user(void) {
  // Set liatris led pin as output
  setPinOutput(24);
  // Turn the LED off (high is off and low is on)
  writePinHigh(24);
}
 */

/* leader code */
void leader_end_user(void) {
    if (leader_sequence_one_key(KC_SPC)) {
        SEND_STRING("Leader Stuff");
    } else if (leader_sequence_one_key(QK_LEAD)) {
        // do nothing, just exit leader mode.
    } else if (leader_sequence_two_keys(KC_B, KC_D)) {
        // Print firmware build time
        SEND_STRING(__DATE__);
    } else if (leader_sequence_two_keys(KC_B, KC_I)) {
        // adapted https://stackoverflow.com/a/64718070/18362972
        unsigned int compileYear = (__DATE__[7] - '0') * 1000 + (__DATE__[8] - '0') * 100 + (__DATE__[9] - '0') * 10 + (__DATE__[10] - '0');
        unsigned int compileMonth = (__DATE__[0] == 'J') ? ((__DATE__[1] == 'a') ? 1 : ((__DATE__[2] == 'n') ? 6 : 7))    // Jan, Jun or Jul
            : (__DATE__[0] == 'F') ? 2                                                              // Feb
            : (__DATE__[0] == 'M') ? ((__DATE__[2] == 'r') ? 3 : 5)                                 // Mar or May
            : (__DATE__[0] == 'A') ? ((__DATE__[1] == 'p') ? 4 : 8)                                 // Apr or Aug
            : (__DATE__[0] == 'S') ? 9                                                              // Sep
            : (__DATE__[0] == 'O') ? 10                                                             // Oct
            : (__DATE__[0] == 'N') ? 11                                                             // Nov
            : (__DATE__[0] == 'D') ? 12                                                             // Dec
            : 0;
        unsigned int compileDay = (__DATE__[4] == ' ') ? (__DATE__[5] - '0') : (__DATE__[4] - '0') * 10 + (__DATE__[5] - '0');

        char IsoDate[] =
            {   compileYear/1000 + '0', (compileYear % 1000)/100 + '0', (compileYear % 100)/10 + '0', compileYear % 10 + '0',
                '-',  compileMonth/10 + '0', compileMonth%10 + '0',
                '-',  compileDay/10 + '0', compileDay%10 + '0',
                0
            };

        send_string(IsoDate);
        SEND_STRING("T");
        SEND_STRING(__TIME__);
    }
}

/* encoder support */
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {

    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_MNXT);
        } else {
            tap_code(KC_MPRV);
        }
    } else if (index == 1) {
        // mouse up/down
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return false;
}
#endif

/* oled support */
#ifdef OLED_ENABLE

/* keylogging for oled display */
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

//bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//  if (record->event.pressed) {
//    set_keylog(keycode, record);
//  }
//  return true;
//}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
    oled_write_ln("", false);
}

void oled_render_layer_state(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state|default_layer_state)) {
        case _BASE:
            oled_write_ln_P(PSTR("Letters"), false);
            break;
        case _NAVI:
            oled_write_ln_P(PSTR("Navigation"), false);
            break;
        case _MOUS:
            oled_write_ln_P(PSTR("Mouse"), false);
            break;
        case _MEDI:
            oled_write_ln_P(PSTR("Media"), false);
            break;
        case _NUMS:
            oled_write_ln_P(PSTR("Numbers"), false);
            break;
        case _SYMB:
            oled_write_ln_P(PSTR("Symbols"), false);
            break;
        case _FUNC:
            oled_write_ln_P(PSTR("Function Keys"), false);
            break;
        case _GAME:
            oled_write_ln_P(PSTR("Gaming"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
    }
}

void oled_render_led_status(void) {
    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    oled_write_P(leader_sequence_active() ? PSTR("LDG ") : PSTR("    "), false);
    oled_write_ln("", false);
}

#ifdef WPM_ENABLED
void oled_render_wpm(void) {
    oled_write_P(PSTR("WPM: "), false);
    oled_write_ln(get_u8_str(get_current_wpm(), ' '), false);
}
#endif

void oled_render_qmk_logo(void) {
    // QMK Logo and version information
    // clang-format off
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
    // clang-format on

    oled_write_P(qmk_logo, false);
}

void oled_render_kyria_logo(void) {
    // clang-format off
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    // clang-format on
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}


bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_qmk_logo();

        oled_write_P(PSTR("Kyria rev2.1\n"), false);

        oled_render_keylog();

        oled_render_layer_state();

        oled_render_led_status();

#ifdef WPM_ENABLED
        oled_render_wpm();
#endif
    } else {
        oled_render_kyria_logo();
    }
    return false;
}

#endif

