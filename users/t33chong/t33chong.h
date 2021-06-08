#pragma once

#include QMK_KEYBOARD_H

enum _layers {
  _DEFAULT_LAYER = 0,
  _NUMERALS_LAYER,
  _MOUSEKEYS_LAYER,
  _FUNCTION_LAYER,
  _QUANTUM_LAYER,
  _LIGHTING_LAYER_SAFE_RANGE
};

enum _lighting_layers {
  _VIM_INDICATOR = _LIGHTING_LAYER_SAFE_RANGE
};

enum _keycodes {
  _NULVAL = SAFE_RANGE, // Dummy value used to indicate that no key is currently held
  _RESETT,              // Restart into bootloader after hold timeout
  _CLRKBD,              // Clear all held keycodes
  _UNDSCR,              // Send _
  _VIMGRV,              // Former ` key: send ` if alt/ctrl/gui held, else enter Vim mode
  _FMRSFT,              // Former left shift key: send forward delete if shift held, or shift if alt/gui held, else backspace
  _FMRBSL,              // Former \ key: send \ if modifier held, else -
  _FMRMIN,              // Former - key: send - if modifier held, else brightness down
  _FMREQL,              // Former = key: send = if modifier held, else brightness up
  _FMRBSP,              // Former backspace key: send backspace if modifier held, else volume down
  _FMRDEL,              // Former delete key: send delete if modifier held, else volume up
};

#define _CTLESC CTL_T(KC_ESC)              // Hold for control, tap for escape
#define _QUASPC LT(_QUANTUM_LAYER, KC_SPC) // Hold for quantum layer, tap for space
#define _MO_FUN MO(_FUNCTION_LAYER)        // Hold for function layer
#define _MO_NUM MO(_NUMERALS_LAYER)        // Hold for numerals layer
#define _TO_DEF TO(_DEFAULT_LAYER)         // Activate default layer
#define _TO_MSK TO(_MOUSEKEYS_LAYER)       // Activate mousekeys layer
#define _ALTBSP A(KC_BSPC)                 // Send alt+backspace
#define _PUSHTT HYPR(KC_BSLS)              // Hold for push to talk with Shush
#define _GUIGRV G(KC_GRV)
#define _HYP_F1 HYPR(KC_F1)
#define _HYP_F2 HYPR(KC_F2)
#define _HYP_F3 HYPR(KC_F3)
#define _HYP_F4 HYPR(KC_F4)
#define _HYP_F5 HYPR(KC_F5)
#define _HYP_F6 HYPR(KC_F6)
#define _HYP_F7 HYPR(KC_F7)
#define _HYP_F8 HYPR(KC_F8)
#define _HYP_F9 HYPR(KC_F9)
#define _HYP_F0 HYPR(KC_F10)

#define _is_mod_held (_is_alt_held || _is_ctrl_held || _is_gui_held || _is_shift_held)
#define _layout(...) LAYOUT_t33chong(__VA_ARGS__)
#define _rgb_all(color) RGBLIGHT_LAYER_SEGMENTS({0, 16, color})

/*
#define _MAP \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______, \
    _______, _______, _______,          _______,          _______,          _______,          _______, _______, _______, _______, _______
*/

#define _DEFAULT_MAP \
    _VIMGRV, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _FMRMIN, _FMREQL, _FMRBSP, _FMRDEL, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          _FMRBSL, \
    _CTLESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,                   KC_ENT,  \
    _FMRSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_EQL,           _MO_FUN, \
    _PUSHTT, KC_LALT, KC_LGUI,          KC_LSFT,          _MO_NUM,          _QUASPC,          _UNDSCR, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT

#define _NUMERALS_MAP \
    _GUIGRV, G(KC_1), G(KC_2), G(KC_3), G(KC_4), G(KC_5), G(KC_6), G(KC_7), G(KC_8), G(KC_9), G(KC_0), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, KC_COLN,          KC_MINS, \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,                   KC_PLUS, \
    KC_BSPC, _HYP_F1, _HYP_F2, _HYP_F3, _HYP_F4, _HYP_F5, _HYP_F6, _HYP_F7, _HYP_F8, _HYP_F9, _HYP_F0,          KC_EQL,           _______, \
    XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,          XXXXXXX,          KC_SPC,           _UNDSCR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

#define _MOUSEKEYS_MAP \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, KC_WBAK, KC_MS_U, KC_WFWD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, \
    _TO_DEF, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX, XXXXXXX,                   KC_BTN4, \
    KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          KC_BTN5,          _______, \
    KC_LCTL, KC_LALT, KC_LGUI,          KC_BTN2,          KC_BTN3,          KC_BTN1,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

#define _FUNCTION_MAP \
    _CLRKBD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  BL_TOGG, _RESETT, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, \
    KC_DEL,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,          _______, \
    XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

#define _QUANTUM_MAP \
    KC_GRV,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,  \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_BSLS, \
    KC_ESC,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, \
    _ALTBSP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______, \
    _______, _______, _______,          _______,          _TO_MSK,          _______,          _______, _______, _______, _______, _______
