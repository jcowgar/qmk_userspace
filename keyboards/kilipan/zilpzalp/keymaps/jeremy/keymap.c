#define COMBO_TERM 35

#include QMK_KEYBOARD_H
#include "zilpzalp.h"

//// definitions
// layers
enum zilpzalp_layers {
    _ALPHA,
    _NUM,
    _NAV,
    _SYM,
    _FUN
};

// custom keycodes
enum custom_keycodes {
    ALPHA = SAFE_RANGE,
    NUM,
    NAV,
    SYM,
    FUN,
    KC_MDOT
};

// LEFT HAND HOME ROW MODS
#define JC_A MT(MOD_LGUI, KC_A)
#define JC_R MT(MOD_LALT, KC_R)
#define JC_S MT(MOD_LCTL, KC_S)
#define JC_T MT(MOD_LSFT, KC_T)
#define JC_G KC_G // MT(MOD_RALT, KC_G)

// RIGHT HAND HOME ROW MODS
#define JC_M KC_M // MT(MOD_RALT, KC_M)
#define JC_N MT(MOD_LSFT, KC_N)
#define JC_E MT(MOD_LCTL, KC_E)
#define JC_I MT(MOD_LALT, KC_I)
#define JC_O MT(MOD_LGUI, KC_O)

// LAYER TAP BEHAVIORS
#define NAV_SPC LT(_NAV, KC_SPC)   // Tap for space, hold for NAV
#define NUM_BSP LT(_NUM, KC_BSPC)  // Tap for backspace, hold for NUM
#define FUN_TILD LT(_FUN, KC_NO)   // Tap for tilde, hold for FUN
#define SYM_ENT LT(_SYM, KC_ENT)   // Tap for enter, hold for SYM

// OTHER
#define KC_MDOT LSFT(RALT(KC_SCLN))

// combos
enum combo_events {
    CAPSWORD_COMBO,
    Q_COMBO,
    Z_COMBO,
    V_COMBO,
    B_COMBO,
    J_COMBO,  // Added J combo
    MINUS_COMBO,
    SLASH_COMBO,
    SEMI_COMBO,
    QUOT_COMBO,
    ESC_COMBO,  // Added from crkbd
    TAB_COMBO,  // Added from crkbd
    EMAIL_COMBO,  // Added from crkbd
    NAME_COMBO,  // Added from crkbd
    PIPE_GT_COMBO,  // Added from crkbd
    DASH_GT_COMBO,  // Added from crkbd
    EQUAL_GT_COMBO,  // Added from crkbd
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

// Original zilpzalp combos
const uint16_t PROGMEM capsword_combo[] = {JC_S, JC_T, COMBO_END};  // Changed to match crkbd
const uint16_t PROGMEM q_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM b_combo[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM z_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM v_combo[] = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM j_combo[] = {KC_L, KC_K, COMBO_END};  // J between L and K
const uint16_t PROGMEM minus_combo[] = {JC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM slash_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM semi_combo[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM quot_combo[] = {KC_L, KC_U, COMBO_END};

// Additional combos from crkbd
const uint16_t PROGMEM esc_combo[] = {KC_U, JC_N, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_F, JC_T, COMBO_END};
const uint16_t PROGMEM email_combo[] = {KC_W, KC_K, COMBO_END};  // Changed from W,J to W,K
const uint16_t PROGMEM name_combo[] = {KC_K, KC_C, COMBO_END};  // Changed from J,C to K,C
const uint16_t PROGMEM pipe_gt_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM dash_gt_combo[] = {KC_DOT, KC_H, COMBO_END};  // Changed to use H instead of slash
const uint16_t PROGMEM equal_gt_combo[] = {JC_N, KC_DOT, COMBO_END};

combo_t key_combos[] = {
    [CAPSWORD_COMBO] = COMBO(capsword_combo, CW_TOGG),
    [Q_COMBO] = COMBO(q_combo, KC_Q),
    [B_COMBO] = COMBO(b_combo, KC_B),
    [Z_COMBO] = COMBO(z_combo, KC_Z),
    [V_COMBO] = COMBO(v_combo, KC_V),
    [J_COMBO] = COMBO(j_combo, KC_J),
    [MINUS_COMBO] = COMBO(minus_combo, KC_MINUS),
    [SLASH_COMBO] = COMBO(slash_combo, KC_SLASH),
    [SEMI_COMBO] = COMBO(semi_combo, KC_SCLN),
    [QUOT_COMBO] = COMBO(quot_combo, KC_QUOT),
    [ESC_COMBO] = COMBO(esc_combo, KC_ESC),
    [TAB_COMBO] = COMBO(tab_combo, KC_TAB),
    [EMAIL_COMBO] = COMBO(email_combo, KC_NO),
    [NAME_COMBO] = COMBO(name_combo, KC_NO),
    [PIPE_GT_COMBO] = COMBO(pipe_gt_combo, KC_NO),
    [DASH_GT_COMBO] = COMBO(dash_gt_combo, KC_NO),
    [EQUAL_GT_COMBO] = COMBO(equal_gt_combo, KC_NO),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     *             B                   '
     *     ┌───┬───┬───┬───┐   ┌───┬───┬───┬───┐
     *   Q │ W │ F │ P │ K │   │ J │ L │ U │ Y │ ;
     * ┌───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┐
     * │ A │ R │ S │ T │ G │   │ M │ N │ E │ I │ O │
     * └───┼───┼───┼───┼───┘   └───┼───┼───┼───┼───┘
     *   Z │ X │ C │ D │ V       - │ H │ , │ . │ /
     *     └───┴───┼───┼───┐   ┌───┼───┼───┴───┘
     *             │SPC│BSP│   │ ~ │ENT│
     *             └───┴───┘   └───┴───┘
     */
    [_ALPHA] = LAYOUT(
                 KC_W,    KC_F,    KC_P,    KC_K,    KC_L,    KC_U,    KC_Y,    KC_QUOT,  // J combo between L and K
          JC_A,  JC_R,    JC_S,    JC_T,    JC_G,    JC_M,    JC_N,    JC_E,    JC_I,   JC_O,
                 KC_X,    KC_C,    KC_D,                      KC_H,    KC_COMM, KC_DOT,
                                   NAV_SPC, NUM_BSP, FUN_TILD,SYM_ENT
    ),
    [_NUM] = LAYOUT(
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,
        KC_DLR,  KC_DOT,  KC_COMM, KC_UNDS, XXXXXXX, KC_ASTR, KC_4,    KC_5,    KC_6,    KC_SLSH,
                 XXXXXXX, KC_PERC, KC_HASH,                   KC_1,    KC_2,    KC_3,
                                   QK_BOOT, _______, KC_EQL,  KC_0
    ),
    [_NAV] = LAYOUT(
                 KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F6,   KC_HOME, KC_UP,   KC_END,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,
                 KC_F8,   KC_F9,   KC_F10,                    KC_PGDN, XXXXXXX, XXXXXXX,
                                   _______, _______, _______, _______
    ),
    [_SYM] = LAYOUT(
                 KC_TILD, KC_AT,   KC_PIPE, KC_LBRC, KC_RBRC, KC_ASTR, KC_SCLN, KC_DLR,
        KC_LT,   KC_MINS, KC_LPRN, KC_UNDS, KC_BSLS, KC_GRV,  KC_COLN, KC_RPRN, KC_EQL,  KC_GT,
                 KC_PLUS, KC_AMPR, KC_HASH,                   KC_RCBR, KC_PERC, KC_QUES,
                                   _______, _______, _______, _______
    ),
    [_FUN] = LAYOUT(
                 KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F12,  KC_F7,   KC_F8,   KC_F9,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_F10,
                 KC_F5,   KC_F6,   KC_F11,                    KC_F1,   KC_F2,   KC_F3,
                                   _______, _______, _______, _______
    )
};

// Process custom keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_FUN, KC_NO):
            if (record->tap.count && record->event.pressed) {
                // On tap, send tilde
                tap_code16(S(KC_GRV));  // Send shifted grave for tilde
                return false;
            }
            break;
    }
    return true;
}

// Process combo events
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
