/**
 * Copyright 2025 Jeremy Cowgar <jeremy@cowgar.com>
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

#define JC_CENT LCTL_T(KC_ENT)
#define JC_SBSP LSFT_T(KC_BSPC)
#define JC_SDEL LSFT_T(KC_DEL)
#define JC_NDEL LT(_NUM, KC_DEL)
#define JC_STAB LSFT_T(KC_TAB)
#define JC_FET  LT(_FN, KC_ENT)
#define JC_SET  LT(_SYM, KC_ENT)
#define JC_SSP  LT(_SYM, KC_SPC)

#define JC_A MT(MOD_LGUI, KC_A)
#define JC_R MT(MOD_LALT, KC_R)
#define JC_S MT(MOD_LCTL, KC_S)
#define JC_T MT(MOD_LSFT, KC_T)

#define JC_N MT(MOD_LSFT, KC_N)
#define JC_E MT(MOD_LCTL, KC_E)
#define JC_I MT(MOD_LALT, KC_I)
#define JC_O MT(MOD_LGUI, KC_O)

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
const uint16_t PROGMEM obracket_combo[] = {JC_A, JC_R, COMBO_END};
const uint16_t PROGMEM obrace_combo[] = {JC_R, JC_S, COMBO_END};
const uint16_t PROGMEM oparen_combo[] = {JC_S, JC_T, COMBO_END};
const uint16_t PROGMEM exclamation_combo[] = {JC_T, KC_G, COMBO_END};
const uint16_t PROGMEM equal_combo[] = {KC_M, JC_N, COMBO_END};
const uint16_t PROGMEM cparen_combo[] = {JC_N, JC_E, COMBO_END};
const uint16_t PROGMEM cbrace_combo[] = {JC_E, JC_I, COMBO_END};
const uint16_t PROGMEM cbracket_combo[] = {JC_I, JC_O, COMBO_END};

// Row 3
const uint16_t PROGMEM backslash_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM asterisk_combo[] = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM slash_combo[] = {KC_D, KC_V, COMBO_END};
const uint16_t PROGMEM plus_combo[] = {KC_K, KC_H, COMBO_END};
const uint16_t PROGMEM minus_combo[] = {KC_H, KC_COMMA, COMBO_END};
const uint16_t PROGMEM pipe_gt_combo[] = {KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM dash_gt_combo[] = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM equal_gt_combo[] = {JC_N, KC_DOT, COMBO_END};

// Multiple Rows
const uint16_t PROGMEM esc_combo[] = {KC_U, JC_N, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_F, JC_T, COMBO_END};
const uint16_t PROGMEM percent_combo[] = {JC_S, KC_D, COMBO_END};
const uint16_t PROGMEM colon_combo[] = {JC_T, KC_V, COMBO_END};
const uint16_t PROGMEM semi_combo[] = {JC_N, KC_K, COMBO_END};
const uint16_t PROGMEM underscore_combo[] = {JC_E, KC_H, COMBO_END};
const uint16_t PROGMEM email_combo[] = {KC_W, KC_J, COMBO_END};
const uint16_t PROGMEM name_combo[] = {KC_J, KC_C, COMBO_END};

enum combo_events {
     EMAIL_COMBO,
     NAME_COMBO,
     PIPE_GT_COMBO,
     DASH_GT_COMBO,
     EQUAL_GT_COMBO
};

combo_t key_combos[] = {
    // Ordered combos (must match order of combo_events)
    COMBO(email_combo, KC_NO),
    COMBO(name_combo, KC_NO),
    COMBO(pipe_gt_combo, KC_NO),
    COMBO(dash_gt_combo, KC_NO),
    COMBO(equal_gt_combo, KC_NO),

    // Key based combos
    //COMBO(and_combo, KC_AMPR),
    //COMBO(asterisk_combo, KC_ASTR),
    //COMBO(at_combo, KC_AT),
    //COMBO(backslash_combo, KC_BSLS),
    //COMBO(backtick_combo, KC_GRV),
    //COMBO(caret_combo, KC_CIRC),
    //COMBO(cbrace_combo, KC_RCBR),
    //COMBO(cbracket_combo, KC_RBRC),
    //COMBO(colon_combo, KC_COLON),
    //COMBO(cparen_combo, KC_RPRN),
    //COMBO(dollar_combo, KC_DLR),
    //COMBO(equal_combo, KC_EQUAL),
    COMBO(esc_combo, KC_ESC),
    //COMBO(exclamation_combo, KC_EXLM),
    //COMBO(hash_combo, KC_HASH),
    //COMBO(minus_combo, KC_MINS),
    //COMBO(obrace_combo, KC_LCBR),
    //COMBO(obracket_combo, KC_LBRC),
    //COMBO(oparen_combo, KC_LPRN),
    //COMBO(or_combo, KC_PIPE),
    //COMBO(percent_combo, KC_PERC),
    //COMBO(plus_combo, KC_PLUS),
    //COMBO(semi_combo, KC_SCLN),
    //COMBO(slash_combo, KC_SLSH),
    COMBO(tab_combo, KC_TAB),
    //COMBO(tilda_combo, KC_TILD),
    //COMBO(underscore_combo, KC_UNDS),
};

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _CLMK,
    _SYM,
    _NAV,
    _NUM,
    _FN,
    _MOUSE
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_CLMK] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,       KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT, KC_BSLS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LSFT,    JC_A,    JC_R,    JC_S,    JC_T,    KC_G,       KC_M,    JC_N,    JC_E,    JC_I,    JC_O, KC_QUOT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,       KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, KC_LALT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                   MO(_NAV),JC_SSP, JC_SBSP,      JC_NDEL, JC_SET,
                                           MO(_FN), CW_TOGG,     TG(_NUM)
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [_SYM] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, KC_TILD,   KC_AT, KC_PIPE, KC_LBRC, _______,    _______, KC_RBRC, KC_ASTR, KC_SCLN,  KC_DLR, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______,   KC_LT, KC_MINS, KC_LPRN, KC_UNDS, KC_BSLS,     KC_GRV,KC_COLON, KC_RPRN,KC_EQUAL,   KC_GT, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, KC_PLUS, KC_AMPR, KC_HASH, KC_LCBR, KC_EXLM,    _______, KC_RCBR, KC_PERC, KC_QUES, KC_CIRC, _______,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, _______, _______,    _______, _______,
                                           _______, _______,    _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [_NAV] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, _______, _______, _______, _______, _______,    _______, KC_HOME,   KC_UP,  KC_END, _______, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, TG(_NAV),    KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, _______, _______, _______, _______, _______,    KC_PGDN, _______, _______, _______, _______, _______,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, _______, _______,    _______, _______,
                                           _______, _______,    _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [_NUM] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, _______,    KC_7,    KC_8,    KC_9, _______,    _______, _______, _______, _______, _______, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______,KC_MINUS,    KC_4,    KC_5,    KC_6, KC_ASTR,    _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, KC_PLUS,    KC_1,    KC_2,    KC_3, KC_SLSH,    _______, _______, _______, _______, _______, _______,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                     KC_0, _______, _______,    _______, _______,
                                           _______, _______,    _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [_FN] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       _______, _______, _______, _______, _______, _______,    DPI_MOD,DPI_RMOD, _______, _______,  EE_CLR, QK_BOOT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______,  KC_F15,   KC_F7,   KC_F8,   KC_F9,  KC_F10,    _______, _______, _______, _______, _______, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______,  KC_F14,   KC_F4,   KC_F5,   KC_F6,  KC_F11,    _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______,  KC_F13,   KC_F1,   KC_F2,   KC_F3,  KC_F12,    _______, _______, _______, _______, _______, _______,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, _______, _______,    _______, _______,
                                           _______, _______,    _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [_MOUSE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, _______, MS_BTN3, MS_BTN2, MS_BTN1, _______,    _______, _______, _______, _______, _______, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, _______, _______,    _______, _______,
                                           _______, _______,    _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  
  //[LAYER_LOWER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
  //   KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
  //   RM_NEXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_LBRC,   KC_P7,   KC_P8,   KC_P9, KC_RBRC, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
  //   RM_TOGG, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,    KC_PPLS,   KC_P4,   KC_P5,   KC_P6, KC_PMNS, KC_PEQL,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
  //   RM_PREV, XXXXXXX, XXXXXXX, XXXXXXX, EE_CLR,  QK_BOOT,    KC_PAST,   KC_P1,   KC_P2,   KC_P3, KC_PSLS, KC_PDOT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
  //                              XXXXXXX, XXXXXXX, _______,    XXXXXXX, _______,
  //                                       XXXXXXX, XXXXXXX,      KC_P0
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  //),

  //[LAYER_RAISE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
  //    KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
  //   KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
  //   KC_MPLY, KC_LEFT,   KC_UP, KC_DOWN, KC_RGHT, XXXXXXX,    XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_MUTE,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
  //   KC_MPRV, KC_HOME, KC_PGUP, KC_PGDN,  KC_END, XXXXXXX,    QK_BOOT, EE_CLR,  XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
  //                              _______, _______, XXXXXXX,    _______, XXXXXXX,
  //                                       _______, _______,    XXXXXXX
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  //),

  //[BLANK] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
  //   _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
  //   _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
  //   _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
  //   _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
  //                              _______, _______, _______,    _______, _______,
  //                                       _______, _______,    _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  //),
};
// clang-format on

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

    case EQUAL_GT_COMBO:
        if (pressed) {
            SEND_STRING("=>");
        }
        break;
  }
}
