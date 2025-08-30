#define COMBO_TERM 35

#include QMK_KEYBOARD_H

// Defines for key combinations
#define JC_CENT LCTL_T(KC_ENT)
#define JC_SBSP LSFT_T(KC_BSPC)
#define JC_SDEL LSFT_T(KC_DEL)
#define JC_STAB LSFT_T(KC_TAB)
#define JC_FET  LT(_FN, KC_ENT)
#define JC_SET  LT(_SYM, KC_ENT)
#define JC_NSP  LT(_NAV, KC_SPC)

#define JC_A MT(MOD_LGUI, KC_A)
#define JC_R MT(MOD_LALT, KC_R)
#define JC_S MT(MOD_LCTL, KC_S)
#define JC_T MT(MOD_LSFT, KC_T)

#define JC_N MT(MOD_LSFT, KC_N)
#define JC_E MT(MOD_LCTL, KC_E)
#define JC_I MT(MOD_LALT, KC_I)
#define JC_O MT(MOD_LGUI, KC_O)

// Combos
const uint16_t PROGMEM esc_combo[] = {KC_U, JC_N, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_F, JC_T, COMBO_END};
const uint16_t PROGMEM email_combo[] = {KC_W, KC_J, COMBO_END};
const uint16_t PROGMEM name_combo[] = {KC_J, KC_C, COMBO_END};
const uint16_t PROGMEM pipe_gt_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM dash_gt_combo[] = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM equal_gt_combo[] = {JC_N, KC_DOT, COMBO_END};

enum combo_events {
    EMAIL_COMBO,
    NAME_COMBO,
    PIPE_GT_COMBO,
    DASH_GT_COMBO,
    EQUAL_GT_COMBO
};

combo_t key_combos[] = {
    COMBO(email_combo, KC_NO),
    COMBO(name_combo, KC_NO),
    COMBO(pipe_gt_combo, KC_NO),
    COMBO(dash_gt_combo, KC_NO),
    COMBO(equal_gt_combo, KC_NO),
    COMBO(esc_combo, KC_ESC),
    COMBO(tab_combo, KC_TAB),
};

enum layers {
    MAC_BASE,
    WIN_BASE,
    _SYM,
    _NAV,
    _NUM,
    _FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_69(
        KC_ESC,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          TG(_NUM),
        KC_TAB,  KC_Q,     KC_W,     KC_F,    KC_P,    KC_B,    KC_J,     KC_L,    KC_U,    KC_Y,    KC_QUOT,  KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_PGUP,
        CW_TOGG, JC_A,     JC_R,     JC_S,    JC_T,    KC_G,              KC_M,    JC_N,    JC_E,    JC_I,     JC_O,     KC_SCLN,  KC_ENT,           KC_PGDN,
        KC_LSFT,           KC_Z,     KC_X,    KC_C,    KC_D,    KC_V,     KC_UNDS, KC_K,    KC_H,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT, KC_UP,
        KC_LCTL, KC_LOPT,  KC_LCMD,           JC_NSP,           KC_GRV,   KC_GRV,           JC_SET,            KC_RCMD,            KC_LEFT, KC_DOWN, KC_RGHT),

    [WIN_BASE] = LAYOUT_ansi_69(
        KC_ESC,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          TG(_NUM),
        KC_TAB,  KC_Q,     KC_W,     KC_F,    KC_P,    KC_B,    KC_J,     KC_L,    KC_U,    KC_Y,    KC_QUOT,  KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_PGUP,
        CW_TOGG, JC_A,     JC_R,     JC_S,    JC_T,    KC_G,              KC_M,    JC_N,    JC_E,    JC_I,     JC_O,     KC_SCLN,  KC_ENT,           KC_PGDN,
        KC_LSFT,           KC_Z,     KC_X,    KC_C,    KC_D,    KC_V,     KC_UNDS, KC_K,    KC_H,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT, KC_UP,
        KC_LCTL, KC_LWIN,  KC_LALT,           KC_SPC,           KC_GRV,   KC_GRV,           JC_SET,            KC_RALT,            KC_LEFT, KC_DOWN, KC_RGHT),

    [_SYM] = LAYOUT_ansi_69(
        KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           _______,
        _______, KC_TILD, KC_AT,   KC_PIPE, KC_LBRC, _______, _______, KC_RBRC, KC_ASTR, KC_SCLN, KC_DLR,  _______, _______, _______,          _______,
        _______, KC_LT,   KC_MINS, KC_LPRN, KC_UNDS, KC_BSLS,          KC_GRV,  KC_COLN, KC_RPRN, KC_EQL,  KC_GT,   _______, _______,          _______,
        _______, KC_PLUS, KC_AMPR, KC_HASH, KC_LCBR, KC_EXLM, _______, _______, KC_RCBR, KC_PERC, KC_QUES, KC_CIRC, _______, _______,
        _______, _______, _______,          _______,          _______, _______,          _______,          _______,          _______, _______, _______),

    [_NAV] = LAYOUT_ansi_69(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           _______,
        _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_UP,   KC_END,  _______, _______, _______, _______,          _______,
        _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,          KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, KC_PGDN, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,          _______,          _______, _______,          _______,          _______,          _______, _______, _______),

    [_NUM] = LAYOUT_ansi_69(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           _______,
        _______, KC_MINS, KC_7,    KC_8,    KC_9,    _______, _______, _______, _______, _______, QK_BOOT, UG_SPDD, UG_SPDU, _______,          UG_HUEU,
        _______, KC_PLUS, KC_4,    KC_5,    KC_6,    KC_ASTR,          KC_EQL,  KC_DLR,  KC_HASH, KC_PERC, _______, _______, UG_TOGG,          UG_HUED,
        _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_SLSH, _______, _______, _______, UG_VALD, UG_VALU, _______, _______, UG_SATU,
        _______, _______, _______,          _______,          _______, _______,          _______,          _______,          UG_NEXT, UG_SATD, UG_PREV),

    [_FN] = LAYOUT_ansi_69(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, KC_F15,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, KC_F14,  KC_F4,   KC_F5,   KC_F6,   KC_F11,           _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______, _______,          _______,
        _______, KC_F13,  KC_F1,   KC_F2,   KC_F3,   KC_F12,  _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,          _______,          _______, _______,          _______,          _______,          _______, _______, QK_BOOT)
};

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
