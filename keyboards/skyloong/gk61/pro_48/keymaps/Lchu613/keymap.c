// Copyright 2021 JZ-Skyloong (@JZ-Skyloong)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _FN1,
    _FN2,
    _FN3,
    _FNX,
    _TM
};

// Tap Dance Declarations
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

enum {
    TD_RSFT_FN3, // Our custom tap dance key
};

// Function associated with all tap dances
td_state_t cur_dance(tap_dance_state_t *state);

// Functions associated with individual tap dances
void ql_finished(tap_dance_state_t *state, void *user_data);
void ql_reset(tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │Bsp│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │Tab│ Q │ W │ E | R │ T │ Y │ U │ I │ O │ P │ [ │ ] │ \ │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │Cap│ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │   |Ent│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │Sft│ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │   |Mo3|   │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │Ctl│GUI│Alt│   │Spc│Spc│Mut│   |Mo1|Mo3│Alt│Ctl│   │Mo2|
     * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
     */
    [_BASE] = LAYOUT_all(
         KC_ESC,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,        KC_6,     KC_7,        KC_8,      KC_9,        KC_0,     KC_MINS,    KC_EQL,         KC_BSPC,
         KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,        KC_Y,     KC_U,        KC_I,      KC_O,        KC_P,     KC_LBRC,   KC_RBRC,         KC_BSLS,
        KC_LCTL,     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,        KC_H,     KC_J,        KC_K,      KC_L,     KC_SCLN,     KC_QUOT,                     KC_ENT,
        KC_LSFT,     KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,        KC_N,     KC_M,     KC_COMM,    KC_DOT,     KC_SLSH,                         TD(TD_RSFT_FN3),
        KC_LCTL,  KC_LGUI,  KC_LALT,             KC_SPC,   KC_SPC,     KC_MUTE,              MO(_FN1),   KC_RALT,    MO(_FN3),     KC_RCTL,              MO(_FN2)
    ),

     [_FN1] = LAYOUT_all(
        KC_GRV,     KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,       KC_F6,    KC_F7,       KC_F8,     KC_F9,      KC_F10,      KC_F11,    KC_F12,          KC_DEL,
        KC_CAPS,  KC_BTN3,  KC_HOME,  KC_MS_U,   KC_END,  KC_BTN1,     KC_PGUP,  KC_HOME,      KC_INS,    KC_END,      KC_DEL,     KC_BSPC,   _______,         _______,
        _______,  KC_BTN4,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_BTN2,     KC_LEFT,  KC_DOWN,       KC_UP,   KC_RGHT,      KC_ENT,     _______,                    _______,
        _______,  KC_BTN5,  KC_MPRV,  KC_MPLY,  KC_MNXT,  _______,     KC_PGDN,  KC_VOLD,     KC_VOLU,   KC_MUTE,     _______,                _______,
        _______,  _______,  _______,            _______,  _______,     KC_MPLY,               _______,   _______,     _______,     _______,              MO(_FNX)
    ),

    [_FN2] =  LAYOUT_all(
        KC_GRV ,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,       KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,    KC_F11,   KC_F12,    KC_DEL,
        KC_CAPS,  _______,  _______,  _______,  RGB_M_R,  _______,     _______,  _______,  _______,  _______,  RGB_M_P,  RGB_RMOD,  RGB_MOD,   RGB_TOG,
        _______,  _______,  RGB_SAI,  _______,  _______,  _______,     RGB_HUI,  _______,  _______,  _______,  RGB_SPD,   RGB_SPI,             _______,
        _______,  KC_SLEP,  _______,  _______,  _______,  RGB_VAI,     _______,  _______,  RGB_VAD,  RGB_VAI,  KC_UP,               KC_RSFT, 
        _______,  _______,  _______,            _______,  _______,     _______,            _______,  KC_LEFT,  KC_DOWN,  KC_RIGHT,             _______
    ),

    [_FN3] = LAYOUT_all(
        KC_GRV,     KC_F1,    KC_F2,     KC_F3,    KC_F4,      KC_F5,       KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_DEL,
        KC_CAPS,  _______,  _______,   _______,  _______,    _______,     _______,  _______,  KC_PSCR,  KC_SCRL,  KC_PAUS,    KC_UP,  _______,  _______,
        _______,  _______,  _______,   _______,  _______,    _______,     _______,  _______,  KC_HOME,  KC_PGUP,  KC_LEFT,  KC_RGHT,            _______,
        _______,  _______,  _______,   _______,  _______,    _______,     _______,  _______,   KC_END,  KC_PGDN,  KC_DOWN,            KC_RSFT,
        _______,  _______,  _______,             _______,    _______,     _______,            _______,  _______,  _______,  _______,            _______
    ),

    [_FNX] = LAYOUT_all(
        TO(_BASE),_______,  _______,   _______,  _______,    _______,     _______,  _______,  _______,  _______,  _______,  _______,  _______,  QK_BOOT,
        _______,  _______,  _______,   _______,  _______,    TO(_TM),     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,   _______,  _______,    _______,     _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,   _______,  _______,    _______,     _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,             _______,    _______,     _______,            _______,  _______,  _______,  _______,            _______
    ),

    [_TM] = LAYOUT_all(
        _______,  _______,  _______,   _______,  _______,    _______,     _______,  _______,  _______,  _______,  _______,  _______,  KC_PAST,  _______,
        _______,    KC_P1,    KC_P2,     KC_P3,  _______,    _______,     _______,  _______,    KC_UP,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,   _______,  _______,    _______,     _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  _______,  _______,            _______,
        _______,  _______,  _______,   _______,  _______,    _______,     _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,             _______,    _______,     _______,            _______,  _______,  _______,  _______,            _______
    ),
};

// Determine the current tap dance state
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        if (!state->pressed) return TD_DOUBLE_TAP;
        else return TD_DOUBLE_HOLD;
    }
    else return TD_UNKNOWN;
}

// Initialize tap structure associated with example tap dance key
static td_tap_t ql_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// Functions that control what our tap dance key does
void ql_finished(tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case TD_SINGLE_HOLD:
            layer_on(_FN3);
            break;
        case TD_DOUBLE_HOLD:
            register_code(KC_RSFT);
            break;
        default:
            break;
    }
}

void ql_reset(tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    switch (ql_tap_state.state) {
        case TD_SINGLE_HOLD:
            layer_off(_FN3);
            break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_RSFT);
            break;
        default:
            break;
    }
    ql_tap_state.state = TD_NONE;
}

// Associate our tap dance key with its functionality
tap_dance_action_t tap_dance_actions[] = {
    [TD_RSFT_FN3] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ql_finished, ql_reset)
};

// Set a long-ish tapping term for tap-dance keys
//uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
//    switch (keycode) {
//        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
//            return 275;
//        default:
//            return TAPPING_TERM;
//    }
//}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_FN1]  = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_FN2]  = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI) },
    [_FN3]  = { ENCODER_CCW_CW(_______, _______) },
    [_FNX]  = { ENCODER_CCW_CW(_______, _______) },
    [_TM]   = { ENCODER_CCW_CW(_______, _______) }
};
#endif

