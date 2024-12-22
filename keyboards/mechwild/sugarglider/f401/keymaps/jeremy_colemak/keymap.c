/*
 * Copyright 2024 Jeremy Cowgar <jeremy@cowgar.com>
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

// Row 1
const uint16_t PROGMEM tilda_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM at_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM hash_combo[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM dollar_combo[] = {KC_P, KC_B, COMBO_END};
const uint16_t PROGMEM caret_combo[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM or_combo[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM and_combo[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM backtick_combo[] = {KC_Y, KC_QUOT, COMBO_END};

// Row 2
const uint16_t PROGMEM obracket_combo[] = {KC_A, KC_R, COMBO_END};
const uint16_t PROGMEM obrace_combo[] = {KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM oparen_combo[] = {KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM exclamation_combo[] = {KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM equal_combo[] = {KC_M, KC_N, COMBO_END};
const uint16_t PROGMEM cparen_combo[] = {KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM cbrace_combo[] = {KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM cbracket_combo[] = {KC_I, KC_O, COMBO_END};

// Row 3
const uint16_t PROGMEM backslash_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM asterisk_combo[] = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM slash_combo[] = {KC_D, KC_V, COMBO_END};
const uint16_t PROGMEM plus_combo[] = {KC_K, KC_H, COMBO_END};
const uint16_t PROGMEM minus_combo[] = {KC_H, KC_COMMA, COMBO_END};
const uint16_t PROGMEM pipe_gt_combo[] = {KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM dash_gt_combo[] = {KC_DOT, KC_SLSH, COMBO_END};

// Multiple Rows
const uint16_t PROGMEM esc_combo[] = {KC_U, KC_N, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_F, KC_T, COMBO_END};
const uint16_t PROGMEM percent_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM colon_combo[] = {KC_T, KC_V, COMBO_END};
const uint16_t PROGMEM semi_combo[] = {KC_N, KC_K, COMBO_END};
const uint16_t PROGMEM underscore_combo[] = {KC_E, KC_H, COMBO_END};
const uint16_t PROGMEM email_combo[] = {KC_W, KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM name_combo[] = {KC_J, KC_C, COMBO_END};

enum combo_events {
     EMAIL_COMBO,
     NAME_COMBO,
     PIPE_GT_COMBO,
     DASH_GT_COMBO,
};

combo_t key_combos[] = {
    // Ordered combos (must match order of combo_events)
    COMBO(email_combo, KC_NO),
    COMBO(name_combo, KC_NO),
    COMBO(pipe_gt_combo, KC_NO),
    COMBO(dash_gt_combo, KC_NO),

    // Key based combos
    COMBO(and_combo, KC_AMPR),
    COMBO(asterisk_combo, KC_ASTR),
    COMBO(at_combo, KC_AT),
    COMBO(backslash_combo, KC_BSLS),
    COMBO(backtick_combo, KC_GRV),
    COMBO(caret_combo, KC_CIRC),
    COMBO(cbrace_combo, KC_RCBR),
    COMBO(cbracket_combo, KC_RBRC),
    COMBO(colon_combo, KC_COLON),
    COMBO(cparen_combo, KC_RPRN),
    COMBO(dollar_combo, KC_DLR),
    COMBO(equal_combo, KC_EQUAL),
    COMBO(esc_combo, KC_ESC),
    COMBO(exclamation_combo, KC_EXLM),
    COMBO(hash_combo, KC_HASH),
    COMBO(minus_combo, KC_MINS),
    COMBO(obrace_combo, KC_LCBR),
    COMBO(obracket_combo, KC_LBRC),
    COMBO(oparen_combo, KC_LPRN),
    COMBO(or_combo, KC_PIPE),
    COMBO(percent_combo, KC_PERC),
    COMBO(plus_combo, KC_PLUS),
    COMBO(semi_combo, KC_SCLN),
    COMBO(slash_combo, KC_SLSH),
    COMBO(tab_combo, KC_TAB),
    COMBO(tilda_combo, KC_TILD),
    COMBO(underscore_combo, KC_UNDS),
};

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _CLMK,
	_NAV,
	_NUM,
    _FN,
    _MOUSE
};

#define JC_CENT LCTL_T(KC_ENT)
#define JC_SBSP LSFT_T(KC_BSPC)
#define JC_SDEL LSFT_T(KC_DEL)
#define JC_STAB LSFT_T(KC_TAB)
#define JC_FET  LT(_FN, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_CLMK] = LAYOUT(                                                            
  //|--------+---------+---------+---------+---------+---------\     +---------+---------+---------+     /---------+---------+---------+---------+---------+---------|
      KC_LALT,     KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,                   TAP_UP,                     KC_J,     KC_L,     KC_U,     KC_Y,  KC_QUOT,  KC_LALT, 
      KC_LCTL,     KC_A,     KC_R,     KC_S,     KC_T,     KC_G,        _______,   TAP_DN,                     KC_M,     KC_N,     KC_E,     KC_I,     KC_O,  JC_CENT, 
      KC_LGUI,     KC_Z,     KC_X,     KC_C,     KC_D,     KC_V,                  TAP_TOG,                     KC_K,     KC_H,  KC_COMM,   KC_DOT,  KC_SLSH,  KC_LGUI,    
  //|--------+---------+---------+---------+---------+---------\     +---------+---------+---------+     /---------+---------+---------+---------+---------+---------|
                          KC_MUTE, MO(_NAV),   KC_SPC,  JC_SBSP,     KC_MS_BTN1,  QK_BOOT,KC_MS_BTN2,       JC_SDEL,   JC_FET, MO(_NUM),  KC_MUTE
  ),
  [_NAV] = LAYOUT(                                                 
  //|--------+---------+---------+---------+---------+---------\     +---------+---------+---------+     /---------+---------+---------+---------+---------+---------|
      _______,  _______,  _______,  _______,  _______,  _______,                            _______,        _______,  KC_HOME,    KC_UP,   KC_END,  _______,  _______,
      _______,  KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  _______,                   _______, _______,        KC_PGUP,  KC_LEFT,  KC_DOWN,  KC_RGHT,  _______,  _______,
      _______,  _______,  _______,  _______,  _______,  _______,                            _______,        KC_PGDN,  _______,  _______,  _______,  _______,  _______,
  //|--------+---------+---------+---------+---------+---------\     +---------+---------+---------+     /---------+---------+---------+---------+---------+---------|
                          _______,  _______,  _______,  _______,        _______,  _______,  _______,        _______,  _______,  _______,  _______
  ),                                                                                                                 
  [_NUM] = LAYOUT(                                                                                                 
  //|--------+---------+---------+---------+---------+---------\     +---------+---------+---------+     /---------+---------+---------+---------+---------+---------|
      _______,  KC_MINS,     KC_7,     KC_8,     KC_9,  _______,                            _______,        _______,  _______,  _______,  _______,  QK_BOOT, _______,
      _______,  KC_PLUS,     KC_4,     KC_5,     KC_6,  KC_ASTR,                  _______,  _______,         KC_EQL,   KC_DLR,  KC_HASH,  KC_PERC,  _______, _______,
      _______,     KC_0,     KC_1,     KC_2,     KC_3,  KC_SLSH,                            _______,        _______,  _______,  _______,  _______,  RM_TOGG, _______,
  //|--------+---------+---------+---------+---------+---------\     +---------+---------+---------+     /---------+---------+---------+---------+---------+---------|
                          _______,  KC_COMM,   KC_DOT,  KC_UNDS,        _______,  _______,   _______,       _______,  _______,  _______, _______
  ),                                                                                                                 
  [_FN] = LAYOUT(                                                                                                
  //|--------+---------+---------+---------+---------+---------\     +---------+---------+---------+     /---------+---------+---------+---------+---------+---------|
      _______,   KC_F15,   KC_F7,    KC_F8,    KC_F9,    KC_F10,                            _______,        _______,  _______,  _______,  _______,  _______,  _______,
      _______,   KC_F14,   KC_F4,    KC_F5,    KC_F6,    KC_F11,                   _______, _______,        _______,  KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  _______,
      _______,   KC_F13,   KC_F1,    KC_F2,    KC_F3,    KC_F12,                            _______,        _______,  _______,  _______,  _______,  _______,  _______,
  //|--------+---------+---------+---------+---------+---------\     +---------+---------+---------+     /---------+---------+---------+---------+---------+---------|
                          _______,  _______,  _______,  _______,        _______,  _______,  _______,        _______,  _______,  _______,  _______
  ),
  [_MOUSE] = LAYOUT(                                                                                                
 //|--------+---------+---------+---------+---------+---------\     +---------+---------+---------+     /---------+---------+---------+---------+---------+---------|
     _______,  _______,  _______,  _______,  _______,  _______,                  _______,  _______,        _______,  _______,  _______,  _______,  _______,         
     _______,  _______,  _______,  _______,  _______,  _______,        _______,  _______,  _______,        _______,  _______,  _______,  _______,  _______,
     _______,  _______,  _______,  _______,  _______,  _______,                  _______,  _______,        _______,  _______,  _______,  _______,  _______,
 //|--------+---------+---------+---------+---------+---------\     +---------+---------+---------+     /---------+---------+---------+---------+---------+---------|
                         _______,  _______,  _______,  _______,        _______,  _______,  _______,        _______,  _______,  _______,  _______
  )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_CLMK]  = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(KC_VOLU, KC_VOLD),  ENCODER_CCW_CW(KC_PGUP, KC_PGDN),  ENCODER_CCW_CW(KC_WH_U, KC_WH_D)  },
    [_NAV]   = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT), ENCODER_CCW_CW(KC_HOME, KC_END),   ENCODER_CCW_CW(DPI_UP, DPI_DN)    },
    [_NUM]   = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_HOME, KC_END),   ENCODER_CCW_CW(KC_LEFT, KC_RIGHT), ENCODER_CCW_CW(KC_HOME, KC_END)   },
    [_FN]    = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_BRID, KC_BRIU),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(KC_BRID, KC_BRIU)  },
    [_MOUSE] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_BRID, KC_BRIU),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(KC_BRID, KC_BRIU)  }
};
#endif

void pointing_device_init_user(void) {
    set_auto_mouse_layer(_MOUSE);
    set_auto_mouse_enable(true);
}

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case EMAIL_COMBO:
        if (pressed) {
            SEND_STRING("jeremy@cowgar.com");
        }
        break;

    case NAME_COMBO:
        if (pressed) {
            SEND_STRING("Jeremy Cowgar");
        }
        break;

    case PIPE_GT_COMBO:
      if (pressed) {
        SEND_STRING("|>");
      }
      break;

    case DASH_GT_COMBO:
      if (pressed) {
          SEND_STRING("->");
      }
      break;
  }
}
