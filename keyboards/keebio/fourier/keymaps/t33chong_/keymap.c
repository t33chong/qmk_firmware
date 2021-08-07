#include QMK_KEYBOARD_H
#include "qmk-vim/src/vim.h"
#include "qmk-vim/src/modes.h"
#include "qmk-vim/src/motions.h"

#define LAYOUT_t33chong( \
    LA1, LA2, LA3, LA4, LA5, LA6, RA1, RA2, RA3, RA4, RA5, RA6, RA7, \
    LB1, LB2, LB3, LB4, LB5, LB6,      RB1, RB2, RB3, RB4, RB5, RB7, \
    LC1, LC2, LC3, LC4, LC5, LC6,      RC1, RC3, RC4, RC5, RC6, RC7, \
    LD1, LD2, LD3, LD4, LD5, LD6,      RD2, RD1, RD4, RD5, RD6, RD7  \
    ) \
    { \
        { LA1, LA2,   LA3,   LA4, LA5, LA6,   KC_NO }, \
        { LB1, LB2,   LB3,   LB4, LB5, LB6,   KC_NO }, \
        { LC1, LC2,   LC3,   LC4, LC5, LC6,   KC_NO }, \
        { LD1, LD2,   LD3,   LD4, LD5, LD6,   KC_NO }, \
        { RA1, RA2,   RA3,   RA4, RA5, RA6,   RA7   }, \
        { RB1, RB2,   RB3,   RB4, RB5, KC_NO, RB7   }, \
        { RC1, KC_NO, RC3,   RC4, RC5, RC6,   RC7   }, \
        { RD1, RD2,   KC_NO, RD4, RD5, RD6,   RD7   } \
    }

enum _layers {
  _DEFAULT_LAYER = 0,
  _NUMERALS_LAYER,
/* #ifdef MOUSEKEY_ENABLE */
  _MOUSEKEYS_LAYER,
/* #endif */
  /* _ARROWS_LAYER, */
  _FUNCTION_LAYER,
  _QUANTUM_LAYER,
};

enum _keycodes {
  _NULVAL = SAFE_RANGE, // Dummy value used to indicate that no key is currently held
  _UNDSCR,              // Send _
  _LPAREN,              // (, or [ if shift is held, or shift if gui/alt are held
  _RPAREN,              // ), or ] if shift is held
  _BAKSPC,              // Backspace, or alt+backspace if shift is held
  _UPDOWN,              // If left+right are held, then up; else down
};

#define _CTLESC CTL_T(KC_ESC)                // Hold for control, tap for escape
#define _QUASPC LT(_QUANTUM_LAYER, KC_SPC)   // Hold for quantum layer, tap for space
#define _GNUMIN LT(_NUMERALS_LAYER, KC_MINS) // Hold for gui+number, tap for minus
/* #define _ARRUND LT(_ARROWS_LAYER, KC_NUBS)   // Hold for arrows layer, tap for underscore */
/* #define _ARRUND LT(_FUNCTION_LAYER, KC_NUBS)   // Hold for arrows layer, tap for underscore */
#define _MO_FUN MO(_FUNCTION_LAYER)          // Hold for function layer
#define _MO_NUM MO(_NUMERALS_LAYER)          // Hold for numerals layer
#define _TO_DEF TO(_DEFAULT_LAYER)           // Activate default layer
/* #ifdef MOUSEKEY_ENABLE */
#define _TO_MSK TO(_MOUSEKEYS_LAYER)         // Activate mousekeys layer
/* #else */
/* #define _TO_MSK _______ */
/* #endif */
#define _PUSHTT HYPR(KC_BSLS)                // Hold for push to talk with Shush
#define _GUIGRV G(KC_GRV)                    // Send gui+`
#define _HF(N) HYPR(KC_F ## N)               // Send hyper+function N

#define _is_mod_held (_is_alt_held || _is_ctrl_held || _is_gui_held || _is_shift_held)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEFAULT_LAYER] = LAYOUT_t33chong(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT, KC_EQL,
    _CTLESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    _LPAREN, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _RPAREN,
    /* _MO_FUN, KC_LALT, KC_LGUI, _GNUMIN, KC_LSFT, _MO_NUM,          _BAKSPC, _QUASPC, _ARRUND, KC_LEFT, _UPDOWN, KC_RGHT */
    _MO_FUN, KC_LALT, KC_LGUI, _GNUMIN, KC_LSFT, _MO_NUM,          _BAKSPC, _QUASPC, _UNDSCR, KC_LEFT, _UPDOWN, KC_RGHT
  ),
  [_NUMERALS_LAYER] = LAYOUT_t33chong(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_BSLS, KC_PIPE, KC_MINS, KC_PLUS,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_COLN,
    KC_LCBR, _HF(1),  _HF(2),  _HF(3),  _HF(4),  _HF(5),           _HF(6),  _HF(7),  _HF(8),  _HF(9),  _HF(10), KC_RCBR,
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______
  ),
/* #ifdef MOUSEKEY_ENABLE */
  [_MOUSEKEYS_LAYER] = LAYOUT_t33chong(
    XXXXXXX, XXXXXXX, KC_WBAK, KC_MS_U, KC_WFWD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _TO_DEF, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,          KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX, XXXXXXX,
    KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX, KC_BTN2, KC_BTN4,          KC_BTN3, KC_BTN1, KC_BTN5, XXXXXXX, XXXXXXX, XXXXXXX
  ),
/* #endif */
  /* [_ARROWS_LAYER] = LAYOUT_t33chong( */
  /*   XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, */
  /*   KC_LCTL, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX, */
  /*   KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, */
  /*   XXXXXXX, KC_LALT, KC_LGUI, KC_LALT, KC_LGUI, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX */
  /* ), */
  [_FUNCTION_LAYER] = LAYOUT_t33chong(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, _PUSHTT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),
  [_QUANTUM_LAYER] = LAYOUT_t33chong(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_ESC,  _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _TO_MSK,          _______, _______, _______, _______, _______, _______
  ),
  /* [_LAYER] = LAYOUT_t33chong( */
  /*   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, */
  /*   _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, */
  /*   _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, */
  /*   _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______ */
  /* ), */
};

/* #ifdef RGBLIGHT_ENABLE */
// Indicate layers with RGB underglow
enum _rgblight_layer_indices {
  _BLUE_RGBLIGHT_LAYER = 0,
  _CYAN_RGBLIGHT_LAYER,
  _GREEN_RGBLIGHT_LAYER,
  _MAGENTA_RGBLIGHT_LAYER,
  _RED_RGBLIGHT_LAYER,
  _YELLOW_RGBLIGHT_LAYER
};

#define _rgb_all(color) RGBLIGHT_LAYER_SEGMENTS({0, RGBLED_NUM, color})
const rgblight_segment_t PROGMEM _blue_rgblight_layer[] = _rgb_all(HSV_BLUE);
const rgblight_segment_t PROGMEM _cyan_rgblight_layer[] = _rgb_all(HSV_CYAN);
const rgblight_segment_t PROGMEM _green_rgblight_layer[] = _rgb_all(HSV_GREEN);
const rgblight_segment_t PROGMEM _magenta_rgblight_layer[] = _rgb_all(HSV_MAGENTA);
const rgblight_segment_t PROGMEM _red_rgblight_layer[] = _rgb_all(HSV_RED);
const rgblight_segment_t PROGMEM _yellow_rgblight_layer[] = _rgb_all(HSV_YELLOW);

const rgblight_segment_t* const PROGMEM _rgblight_layers[] = RGBLIGHT_LAYERS_LIST(
  _blue_rgblight_layer,
  _cyan_rgblight_layer,
  _green_rgblight_layer,
  _magenta_rgblight_layer,
  _red_rgblight_layer,
  _yellow_rgblight_layer
);

// Execute on startup
void keyboard_post_init_user(void) {
  rgblight_layers = _rgblight_layers;
  rgblight_enable_noeeprom();
}
/* #endif */

// If true, don't count a tap and a hold as repetition of the tap action
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case _CTLESC:
    case _QUASPC:
      return true;
    default:
      return false;
  }
}

// Number of milliseconds before a pressed key is registered as held
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case _CTLESC:
    /* case _QUASPC: */
      return 120;
    default:
      return TAPPING_TERM;
  }
}

// Vim mode user hooks: set custom state
void insert_mode_user(void) {
  disable_vim_mode();
/* #ifdef RGBLIGHT_ENABLE */
  rgblight_set_layer_state(_GREEN_RGBLIGHT_LAYER, false);
  rgblight_set_layer_state(_YELLOW_RGBLIGHT_LAYER, false);
}

void normal_mode_user(void) {
  rgblight_set_layer_state(_GREEN_RGBLIGHT_LAYER, true);
  rgblight_set_layer_state(_YELLOW_RGBLIGHT_LAYER, false);
}

void visual_mode_user(void) {
  rgblight_set_layer_state(_YELLOW_RGBLIGHT_LAYER, true);
}

void visual_line_mode_user(void) {
  rgblight_set_layer_state(_YELLOW_RGBLIGHT_LAYER, true);
/* #endif */
}

// Vim process mode user hooks: override keycodes
uint16_t _esc_press_timer;
bool process_normal_mode_user(uint16_t keycode, const keyrecord_t *record) {
  switch (keycode) {
    case KC_ESC: // Double tap escape to exit Vim mode
      if (record->event.pressed) {
        if (timer_elapsed(_esc_press_timer) < TAPPING_TERM) {
          insert_mode();
          return false;
        }
        _esc_press_timer = timer_read();
      }
      return true;
    case KC_A: // Don't move right before entering insert mode
      if (record->event.pressed) {
        insert_mode();
        return false;
      }
      return true;
    default:
      return true;
  }
}

bool process_visual_mode_user(uint16_t keycode, const keyrecord_t *record) {
  switch (keycode) {
    case KC_ESC: // Set escape press timer for normal mode override
      if (record->event.pressed) {
        _esc_press_timer = timer_read();
      }
      return true;
    default:
      return true;
  }
}

bool process_visual_line_mode_user(uint16_t keycode, const keyrecord_t *record) {
  switch (keycode) {
    case KC_ESC: // Set escape press timer for normal mode override
      if (record->event.pressed) {
        _esc_press_timer = timer_read();
      }
      return true;
    default:
      return true;
  }
}

int _current_layer;

layer_state_t layer_state_set_user(layer_state_t state) {
  _current_layer = get_highest_layer(state);

/* #ifdef RGBLIGHT_ENABLE */
  rgblight_set_layer_state(_RED_RGBLIGHT_LAYER, (layer_state_cmp(state, _DEFAULT_LAYER || layer_state_cmp(state, _NUMERALS_LAYER)) || layer_state_cmp(state, _QUANTUM_LAYER)));
/* #ifdef MOUSEKEY_ENABLE */
  rgblight_set_layer_state(_CYAN_RGBLIGHT_LAYER, layer_state_cmp(state, _MOUSEKEYS_LAYER));
/* #endif */
  /* rgblight_set_layer_state(_BLUE_RGBLIGHT_LAYER, layer_state_cmp(state, _ARROWS_LAYER)); */
  rgblight_set_layer_state(_MAGENTA_RGBLIGHT_LAYER, layer_state_cmp(state, _FUNCTION_LAYER));
/* #endif */

  return state;
}

// Macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_vim_mode(keycode, record)) {
    return false;
  }

  static bool _is_alt_held;
  /* static bool _is_ctrl_held; */
  static bool _is_gui_held;
  static bool _is_shift_held;
  static bool _is_gnumin_held;
  static bool _is_left_held;
  static bool _is_right_held;
  static uint16_t _pressed_quantum_keycode = _NULVAL;
  static uint16_t _pressed_lparen_keycode = _NULVAL;
  static uint16_t _pressed_rparen_keycode = _NULVAL;
  static uint16_t _pressed_bakspc_keycode = _NULVAL;
  static uint16_t _pressed_updown_keycode = _NULVAL;
  static uint16_t _pressed_numerals_keycode = _NULVAL;
  static uint16_t _ctlesc_press_timer;

/* #ifdef CONSOLE_ENABLE */
/*   uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count); */
/* #endif */

  switch (keycode) {
    // Set held modifier state
    case _CTLESC:
      if (record->event.pressed) {
        /* _is_ctrl_held = true; */
        _ctlesc_press_timer = timer_read();
      } else {
        /* _is_ctrl_held = false; */
        if (_is_shift_held && timer_elapsed(_ctlesc_press_timer) < TAPPING_TERM) {
          clear_mods();
          if (vim_mode_enabled()) {
            insert_mode();
          } else {
            enable_vim_mode();
          }
          return false;
        }
      }
      return true;
    case KC_LALT:
      if (record->event.pressed) {
        _is_alt_held = true;
      } else {
        _is_alt_held = false;
      }
      return true;
    case KC_LGUI:
      if (record->event.pressed) {
        _is_gui_held = true;
      } else {
        _is_gui_held = false;
      }
      return true;
    case KC_LSFT:
      if (record->event.pressed) {
        _is_shift_held = true;
      } else {
        _is_shift_held = false;
      }
      return true;
    case _GNUMIN:
      if (record->event.pressed) {
        _is_gnumin_held = true;
      } else {
        _is_gnumin_held = false;
      }
      return true;
    case KC_LEFT:
      if (record->event.pressed) {
        _is_left_held = true;
        if (_is_right_held) {
          unregister_code(KC_RGHT);
          return false;
        }
      } else {
        _is_left_held = false;
      }
      return true;
    case KC_RGHT:
      if (record->event.pressed) {
        _is_right_held = true;
        if (_is_left_held) {
          unregister_code(KC_LEFT);
          return false;
        }
      } else {
        _is_right_held = false;
      }
      return true;
    case _UPDOWN: // If left+right are held, then up; else down
      if (record->event.pressed) {
        if (_is_left_held && _is_right_held) {
          _pressed_updown_keycode = KC_UP;
        } else {
          _pressed_updown_keycode = KC_DOWN;
        }
        register_code(_pressed_updown_keycode);
      } else {
        if (_pressed_updown_keycode != _NULVAL) {
          unregister_code(_pressed_updown_keycode);
          _pressed_updown_keycode = _NULVAL;
        }
      }
      return false;

    case _BAKSPC:
      if (record->event.pressed) {
        if (_is_shift_held) {
          _pressed_bakspc_keycode = A(KC_BSPC);
          unregister_code(KC_LSFT);
        } else {
          _pressed_bakspc_keycode = KC_BSPC;
        }
        register_code16(_pressed_bakspc_keycode);
      } else {
        if (_pressed_bakspc_keycode != _NULVAL) {
          unregister_code16(_pressed_bakspc_keycode);
          _pressed_bakspc_keycode = _NULVAL;
        }
        if (_is_shift_held) {
          register_code(KC_LSFT);
        }
      }
      return false;

    /* case LSFT(KC_NUBS): */
    /* case KC_NUBS: // Repurpose to send _, since shifted keys don't work with layer tap */
    case _UNDSCR: // Repurpose to send _, since shifted keys don't work with layer tap
      if (record->event.pressed) {
        /* if (_is_shift_held) { */
        /*   unregister_code(KC_LSFT); */
        /* } */
        register_code16(S(KC_MINS));
      } else {
        unregister_code16(S(KC_MINS));
        /* if (_is_shift_held) { */
        /*   register_code(KC_LSFT); */
        /* } */
      }
      return false;

    case _LPAREN:
      if (record->event.pressed) {
        if (_is_alt_held || _is_gui_held) { // Send shift if alt/gui held, else (
          _pressed_lparen_keycode = KC_LSFT;
        } else if (_is_shift_held) {
          _pressed_lparen_keycode = KC_LBRC;
          unregister_code(KC_LSFT);
        } else {
          _pressed_lparen_keycode = KC_LPRN;
        }
        register_code16(_pressed_lparen_keycode);
      } else {
        if (_pressed_lparen_keycode != _NULVAL) {
          unregister_code16(_pressed_lparen_keycode);
          _pressed_lparen_keycode = _NULVAL;
        }
        if (_is_shift_held) {
          register_code(KC_LSFT);
        }
      }
      return false;
    case _RPAREN:
      if (record->event.pressed) {
        if (_is_shift_held) {
          _pressed_rparen_keycode = KC_RBRC;
          unregister_code(KC_LSFT);
          register_code16(_pressed_rparen_keycode);
          register_code(KC_LSFT);
        } else {
          _pressed_rparen_keycode = KC_RPRN;
          register_code16(_pressed_rparen_keycode);
        }
      } else {
        if (_pressed_rparen_keycode != _NULVAL) {
          unregister_code16(_pressed_rparen_keycode);
          _pressed_rparen_keycode = _NULVAL;
        }
      }
      return false;

    // Exempt special keys on quantum layer from meh/hyper passthrough
    case _TO_MSK:
    case _QUASPC:
      return true;

    default:
      if (record->event.pressed) {
        switch (_current_layer) {
          // Apply meh to keycode if right spacebar held, hyper if right+left spacebars held
          case _QUANTUM_LAYER:
            if (_is_shift_held) {
              _pressed_quantum_keycode = HYPR(keycode);
            } else {
              _pressed_quantum_keycode = MEH(keycode);
            }
            register_code16(_pressed_quantum_keycode);
            return false;
          case _NUMERALS_LAYER:
            if (_is_gnumin_held) {
              _pressed_numerals_keycode = G(keycode);
              register_code16(_pressed_numerals_keycode);
              return false;
            }
            return true;
          default:
            return true;
        }
      } else {
        if (_pressed_quantum_keycode != _NULVAL) {
          unregister_code16(_pressed_quantum_keycode);
          _pressed_quantum_keycode = _NULVAL;
          return false;
        }
        if (_pressed_numerals_keycode != _NULVAL) {
          unregister_code16(_pressed_numerals_keycode);
          _pressed_numerals_keycode = _NULVAL;
          return false;
        }
      }
      return true; // Process all other keycodes normally
  }
}
