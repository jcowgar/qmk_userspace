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
    _ADJUST,
    _TMUX
};

enum custom_keycodes {
  TILD_NUM = SAFE_RANGE,  // Custom keycode for tilde tap/number hold
  // Window navigation
  TM_PW, // Previous Window
  TM_NW, // Next Window
  TM_CW, // Close pane
  // Pane navigation
  TM_UP,
  TM_LEFT,
  TM_DOWN,
  TM_RGHT,
  // Window switching (1-9)
  TM_1,
  TM_2,
  TM_3,
  TM_4,
  TM_5,
  TM_6,
  TM_7,
  TM_8,
  TM_9,
  // Session switching (1-5)
  TM_S1,
  TM_S2,
  TM_S3,
  TM_S4,
  TM_S5,
  // Window/pane management
  TM_NEW, // New window
  TM_KILL, // Kill pane
  TM_FIND, // Find
  TM_COPY, // Enter copy mode
  TM_PASTE, // Paste
  TM_RENAME, // Rename window
  TM_ZOOM, // Zoom pane
  TM_RENSES, // Rename session
  // Splits
  TM_HSP, // Horizontal split
  TM_VSP,  // Vertical split
  AP_GLOB // Apple Globe Key
};

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.   ,-------------------------------------------------------------.
      AP_GLOB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B, TG(_TMUX), TG(_TMUX),   KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT, AP_GLOB,
  //|--------+--------+--------+--------+--------+--------+--------|   |-------+--------+--------+--------+--------+--------+--------|
      XXXXXXX,    JC_A,    JC_R,    JC_S,    JC_T,    KC_G,OSL(_TMUX), OSL(_TMUX),  KC_M,    JC_N,    JC_E,    JC_I,    JC_O, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------'   `-------+--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                    LT(_NUM, KC_NO), JC_NSP, KC_BSPC,    KC_DEL,  JC_SET,  KC_GRV
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYM] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.   ,-------------------------------------------------------------.
      XXXXXXX, KC_TILD,   KC_AT, KC_PIPE, KC_LBRC, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, KC_RBRC, KC_ASTR, KC_SCLN,  KC_DLR, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|   |-------+--------+--------+--------+--------+--------+--------|
      XXXXXXX,   KC_LT, KC_MINS, KC_LPRN, KC_UNDS, KC_BSLS, XXXXXXX,    XXXXXXX,  KC_GRV, KC_COLN, KC_RPRN,  KC_EQL,   KC_GT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------'   `-------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_PLUS, KC_AMPR, KC_HASH, KC_LCBR, KC_EXLM,                      XXXXXXX, KC_RCBR, KC_PERC, KC_QUES, KC_CIRC, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_NAV] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.   ,-------------------------------------------------------------.
      XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,    XXXXXXX,   KC_F6, KC_HOME,   KC_UP,  KC_END, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|   |-------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,   KC_F7,    XXXXXXX, KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------'   `-------+--------+--------+--------+--------+--------+--------|
      XXXXXXX,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,                      KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_NUM] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.   ,-------------------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,    KC_7,    KC_8,    KC_9, XXXXXXX, QK_BOOT,
  //|--------+--------+--------+--------+--------+--------+--------|   |-------+--------+--------+--------+--------+--------+--------|
      XXXXXXX,  KC_DLR,  KC_DOT, KC_COMM, KC_UNDS, XXXXXXX, XXXXXXX,    XXXXXXX, KC_ASTR,    KC_4,    KC_5,    KC_6, KC_SLSH, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------'   `-------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_PERC, KC_HASH, XXXXXXX, XXXXXXX,                      KC_PLUS,    KC_1,    KC_2,    KC_3, KC_MINS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,     KC_EQL,    KC_0, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.   ,-------------------------------------------------------------.
      XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, XXXXXXX,    XXXXXXX,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|   |-------+--------+--------+--------+--------+--------+--------|
      XXXXXXX,  KC_F11,  KC_F12, CW_TOGG, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  TSKMGR, CALTDEL, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------'   `-------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_TMUX] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.   ,-------------------------------------------------------------.
      XXXXXXX,  TM_NEW, TM_KILL, TM_FIND,TM_PASTE, TM_COPY,TG(_TMUX),   XXXXXXX, TM_ZOOM,   TM_PW,   TM_UP,   TM_NW,   TM_CW, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|   |-------+--------+--------+--------+--------+--------+--------|
      XXXXXXX,    TM_1,    TM_2,    TM_3,    TM_4,    TM_5, XXXXXXX,    XXXXXXX,  TM_HSP, TM_LEFT, TM_DOWN, TM_RGHT,  TM_VSP, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------'   `-------+--------+--------+--------+--------+--------+--------|
      XXXXXXX,    TM_6,    TM_7,    TM_8,    TM_9,TM_RENAME,                    TM_RENSES,  TM_S1,   TM_S2,   TM_S3,   TM_S4,   TM_S5,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

};

// Handle layer changes for tri-layer behavior
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYM, _NAV, _ADJUST);
}

// Press the Tmux leader key and then the specified key.
bool process_tmux_key(u_int16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        tap_code16(KC_GRV);
        tap_code16(keycode);
        return false;
    }

    return true;
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

        case AP_GLOB:
           host_consumer_send(record->event.pressed ? AC_NEXT_KEYBOARD_LAYOUT_SELECT : 0);
            return false;

        //
        // Tmux Layer
        //
        // Window navigation
        case TM_PW: return process_tmux_key(KC_P, record);
        case TM_NW: return process_tmux_key(KC_N, record);
        case TM_CW: return process_tmux_key(KC_X, record);  // Close pane

        // Pane navigation
        case TM_UP: return process_tmux_key(KC_UP, record);
        case TM_DOWN: return process_tmux_key(KC_DOWN, record);
        case TM_LEFT: return process_tmux_key(KC_LEFT, record);
        case TM_RGHT: return process_tmux_key(KC_RGHT, record);

        // Window switching (1-9)
        case TM_1: return process_tmux_key(KC_1, record);
        case TM_2: return process_tmux_key(KC_2, record);
        case TM_3: return process_tmux_key(KC_3, record);
        case TM_4: return process_tmux_key(KC_4, record);
        case TM_5: return process_tmux_key(KC_5, record);
        case TM_6: return process_tmux_key(KC_6, record);
        case TM_7: return process_tmux_key(KC_7, record);
        case TM_8: return process_tmux_key(KC_8, record);
        case TM_9: return process_tmux_key(KC_9, record);

        // Session switching (using $ prefix)
        case TM_S1:
            if (record->event.pressed) {
                tap_code16(KC_GRV);
                tap_code16(KC_DLR);
                tap_code16(KC_1);
                return false;
            }
            break;
        case TM_S2:
            if (record->event.pressed) {
                tap_code16(KC_GRV);
                tap_code16(KC_DLR);
                tap_code16(KC_2);
                return false;
            }
            break;
        case TM_S3:
            if (record->event.pressed) {
                tap_code16(KC_GRV);
                tap_code16(KC_DLR);
                tap_code16(KC_3);
                return false;
            }
            break;
        case TM_S4:
            if (record->event.pressed) {
                tap_code16(KC_GRV);
                tap_code16(KC_DLR);
                tap_code16(KC_4);
                return false;
            }
            break;
        case TM_S5:
            if (record->event.pressed) {
                tap_code16(KC_GRV);
                tap_code16(KC_DLR);
                tap_code16(KC_5);
                return false;
            }
            break;

        // Window/pane management
        case TM_NEW: return process_tmux_key(KC_C, record);  // New window
        case TM_KILL: return process_tmux_key(KC_X, record);  // Kill pane
        case TM_FIND: return process_tmux_key(KC_F, record);  // Find
        case TM_COPY: return process_tmux_key(KC_LBRC, record);  // Enter copy mode
        case TM_PASTE: return process_tmux_key(KC_RBRC, record);  // Paste
        case TM_RENAME: return process_tmux_key(KC_COMM, record);  // Rename window
        case TM_ZOOM: return process_tmux_key(KC_Z, record);  // Zoom pane
        case TM_RENSES: return process_tmux_key(KC_DLR, record);  // Rename session

        // Splits
        case TM_HSP: return process_tmux_key(KC_PERC, record);  // Horizontal split
        case TM_VSP: return process_tmux_key(KC_DQUO, record);  // Vertical split
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
