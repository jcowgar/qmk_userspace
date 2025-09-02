#define COMBO_TERM 35

#include QMK_KEYBOARD_H

// Defines for key combinations
#define JC_NSP  LT(_NAV, KC_SPC)
#define JC_SET  LT(_SYM, KC_ENT)

// Home row mods for Colemak Mod DH
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
const uint16_t PROGMEM caps_word_combo[] = {JC_S, JC_T, COMBO_END};
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
    COMBO(caps_word_combo, CW_TOGG),
};

enum layer_names {
    _COLEMAK,
    _SYM,
    _NAV,
    _NUM,
    _ADJUST
};

enum custom_keycodes {
  TILD_NUM = SAFE_RANGE,  // Custom keycode for tilde tap/number hold
};

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak Mod DH
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   F  |   P  |   B  |           |   J  |   L  |   U  |   Y  |   '  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   R  |   S  |   T  |   G  |           |   M  |   N  |   E  |   I  |   O  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   D  |   V  |           |   K  |   H  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  | Ctrl | LOWER|      |    |      | RAISE| Shift|
 *                  `-------------| Space|    |BckSpc|------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_COLEMAK] = LAYOUT_split_3x5_3(
  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,         KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
  JC_A,    JC_R,    JC_S,    JC_T,    KC_G,         KC_M,    JC_N,    JC_E,    JC_I,    JC_O,
  KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,         KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                    LT(_NUM, KC_NO), JC_NSP, KC_BSPC,      KC_DEL,  JC_SET,  KC_GRV
),

/* Symbol Layer (_SYM)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   ~  |   @  |   |  |   [  |      |           |      |   ]  |   *  |   ;  |   $  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   <  |   -  |   (  |   _  |   \  |           |   `  |   :  |   )  |   =  |   >  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   +  |   &  |   #  |   {  |   !  |           |      |   }  |   %  |   ?  |   ^  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |      |      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_SYM] = LAYOUT_split_3x5_3(
  KC_TILD, KC_AT,   KC_PIPE, KC_LBRC, _______,      _______, KC_RBRC, KC_ASTR, KC_SCLN, KC_DLR,
  KC_LT,   KC_MINS, KC_LPRN, KC_UNDS, KC_BSLS,      KC_GRV,  KC_COLN, KC_RPRN, KC_EQL,  KC_GT,
  KC_PLUS, KC_AMPR, KC_HASH, KC_LCBR, KC_EXLM,      _______, KC_RCBR, KC_PERC, KC_QUES, KC_CIRC,
                    _______, _______, _______,      _______, _______, _______
),

/* Navigation Layer (_NAV)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |           |  F6  | Home |  Up  | End  |  F10 |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  GUI |  Alt | Ctrl | Shift|      |           | PgUp | Left | Down | Right|  F11 |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           | PgDn |  F7  |  F8  |  F9  |  F12 |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |      |      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_NAV] = LAYOUT_split_3x5_3(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_HOME, KC_UP,   KC_END,  KC_F10,
  KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,      KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, KC_F11,
  _______, _______, _______, _______, _______,      KC_PGDN, KC_F7,   KC_F8,   KC_F9,   KC_F12,
                    _______, _______, _______,      _______, _______, _______
),

/* Number Layer (_NUM)
 *
 * ,----------------------------------.           ,----------------------------------.
 * | Boot |      |      |      |      |           |      |   7  |   8  |   9  |   -  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |   %  |   #  |   $  |   =  |           |   *  |   4  |   5  |   6  |   +  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   _  |   .  |   ,  |      |      |           |   /  |   1  |   2  |   3  |   0  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |      |      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_NUM] = LAYOUT_split_3x5_3(
  QK_BOOT, _______, _______, _______, _______,      _______, KC_7,    KC_8,    KC_9,    KC_MINS,
  _______, KC_PERC, KC_HASH, KC_DLR,  KC_EQL,       KC_ASTR, KC_4,    KC_5,    KC_6,    KC_PLUS,
  KC_UNDS, KC_DOT,  KC_COMM, _______, _______,      KC_SLSH, KC_1,    KC_2,    KC_3,    KC_0,
                    _______, _______, _______,      _______, _______, _______
),

/* Adjust Layer (accessed by holding both SYM and NAV)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |           |   F6 |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F11 |  F12 | CapsW|      |      |           |      |      |      |Taskmg|caltde|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | Reset|      |      |      |      |           |      |      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |      |      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_ADJUST] = LAYOUT_split_3x5_3(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
  KC_F11,  KC_F12,  CW_TOGG, _______, _______,      _______, _______, _______, TSKMGR,  CALTDEL,
  QK_BOOT, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
                    _______, _______, _______,      _______, _______, _______
)
};

// Handle layer changes for tri-layer behavior
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYM, _NAV, _ADJUST);
}

// Process custom keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_NUM, KC_NO):
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
