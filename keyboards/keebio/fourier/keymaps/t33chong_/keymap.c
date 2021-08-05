#include QMK_KEYBOARD_H
#include "qmk-vim/src/vim.h"
#include "qmk-vim/src/modes.h"
#include "qmk-vim/src/motions.h"

#include "print.h"

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
  _MOUSEKEYS_LAYER,
  _FUNCTION_LAYER,
  _QUANTUM_LAYER,
};

enum _keycodes {
  _NULVAL = SAFE_RANGE, // Dummy value used to indicate that no key is currently held
  _UNDSCR,              // Send _
  _VIMGRV,              // Former ` key: send ` if modifier held, else enter Vim mode
  _LPASFT,              // Former left shift key: send shift if alt/gui held, else (
  _LPAREN,
  _RPAREN,
  _BAKSPC,
};

#define _CTLESC CTL_T(KC_ESC)                // Hold for control, tap for escape
#define _QUASPC LT(_QUANTUM_LAYER, KC_SPC)   // Hold for quantum layer, tap for space
#define _GUNMIN LT(_NUMERALS_LAYER, KC_MINS) // Hold for gui+number, tap for minus
#define _MO_FUN MO(_FUNCTION_LAYER)          // Hold for function layer
#define _MO_NUM MO(_NUMERALS_LAYER)          // Hold for numerals layer
#define _TO_DEF TO(_DEFAULT_LAYER)           // Activate default layer
#define _TO_MSK TO(_MOUSEKEYS_LAYER)         // Activate mousekeys layer
#define _PUSHTT HYPR(KC_BSLS)                // Hold for push to talk with Shush
#define _GUIGRV G(KC_GRV)                    // Send gui+`
#define _HF(N) HYPR(KC_F ## N)               // Send hyper+function N

#define _is_mod_held (_is_alt_held || _is_ctrl_held || _is_gui_held || _is_shift_held)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* [_DEFAULT_LAYER] = LAYOUT_t33chong( */
  /*   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _LPAREN, _RPAREN, */
  /*   _CTLESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, */
  /*   KC_EQL,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT, */
  /*   _MO_FUN, KC_LALT, KC_LGUI, _GUNMIN, KC_LSFT, _MO_NUM,          KC_BSPC, _QUASPC, _UNDSCR, KC_LEFT, KC_UP,   KC_RGHT // TODO: arrows */
  /* ), */
  [_DEFAULT_LAYER] = LAYOUT_t33chong(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT, KC_EQL,
    _CTLESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    _LPAREN, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _RPAREN,
    _MO_FUN, KC_LALT, KC_LGUI, _GUNMIN, KC_LSFT, _MO_NUM,          _BAKSPC, _QUASPC, _UNDSCR, KC_LEFT, KC_UP,   KC_RGHT // TODO: arrows
  ),
  [_NUMERALS_LAYER] = LAYOUT_t33chong(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_BSLS, KC_PIPE, _______, _______,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    KC_LCBR, _HF(1),  _HF(2),  _HF(3),  _HF(4),  _HF(5),           _HF(6),  _HF(7),  _HF(8),  _HF(9),  _HF(10), KC_RCBR,
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______
  ),
  [_MOUSEKEYS_LAYER] = LAYOUT_t33chong(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______
  ),
  [_FUNCTION_LAYER] = LAYOUT_t33chong(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______
  ),
  [_QUANTUM_LAYER] = LAYOUT_t33chong(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______
  ),
  /* [_LAYER] = LAYOUT_t33chong( */
  /*   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, */
  /*   _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, */
  /*   _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, */
  /*   _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______ */
  /* ), */
};

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
    case _QUASPC:
      return 100;
    default:
      return TAPPING_TERM;
  }
}

// Vim mode user hooks: set custom state
void insert_mode_user(void) {
  disable_vim_mode();
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
  return state;
}

// Macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);

  if (!process_vim_mode(keycode, record)) {
    return false;
  }

  static bool _is_alt_held;
  /* static bool _is_ctrl_held; */
  static bool _is_gui_held;
  static bool _is_shift_held;
  static bool _is_gunmin_held;
  static uint16_t _pressed_fmrsft_keycode;
  static uint16_t _pressed_quantum_keycode;
  static uint16_t _pressed_lparen_keycode;
  static uint16_t _pressed_rparen_keycode;
  static uint16_t _pressed_bakspc_keycode;
  static uint16_t _pressed_numerals_keycode;
  static uint16_t _ctlesc_press_timer;

  switch (keycode) {
    // Set held modifier state
    case _CTLESC:
      if (record->event.pressed) {
        /* _is_ctrl_held = true; */
        _ctlesc_press_timer = timer_read();
      } else {
        /* _is_ctrl_held = false; */
        if (_is_shift_held && timer_elapsed(_ctlesc_press_timer) < TAPPING_TERM) {
          unregister_code(KC_LSFT);
          enable_vim_mode();
          return false;
        }
      }
      return true;
    /* case KC_ESC: */
    /*   if (record->event.pressed) { */
    /*     if (_is_shift_held) { */
    /*       unregister_code(KC_LSFT); */
    /*       enable_vim_mode(); */
    /*       return false; */
    /*     } */
    /*   } */
    /*   return true; */
    case KC_LALT:
      if (record->event.pressed) {
        _is_alt_held = true;
      } else {
        _is_alt_held = false;
      }
      return true;
    /* case KC_LCTL: // TODO: does this set _is_ctrl_held? */
    /*   if (record->event.pressed) { */
    /*     _is_ctrl_held = true; */
    /*   } else { */
    /*     _is_ctrl_held = false; */
    /*   } */
    /*   return true; */
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
    case _GUNMIN:
      if (record->event.pressed) {
        _is_gunmin_held = true;
      } else {
        _is_gunmin_held = false;
      }
      return true;

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

    case _UNDSCR: // Send _
      if (record->event.pressed) {
        register_code16(S(KC_MINS));
      } else {
        unregister_code16(S(KC_MINS));
      }
      return false;

    // Context-specific remapping of various keys
    // FIXME
    case _LPASFT: // Former left shift key: send shift if alt/gui held, else (
      if (record->event.pressed) {
        if (_is_alt_held || _is_gui_held) {
          _pressed_fmrsft_keycode = KC_LSFT;
        } else {
          _pressed_fmrsft_keycode = KC_BSPC;
        }
        register_code16(_pressed_fmrsft_keycode);
      } else {
        if (_pressed_fmrsft_keycode != _NULVAL) {
          unregister_code16(_pressed_fmrsft_keycode);
          _pressed_fmrsft_keycode = _NULVAL;
        }
      }
      return false;

    case _LPAREN:
      if (record->event.pressed) {
        if (_is_shift_held) {
          _pressed_lparen_keycode = KC_LBRC;
          unregister_code(KC_LSFT);
        } else {
          _pressed_lparen_keycode = KC_LPRN;
        }
        register_code16(_pressed_lparen_keycode);
        /* if (_is_shift_held) { */
        /*   _pressed_lparen_keycode = KC_LBRC; */
        /*   unregister_code(KC_LSFT); */
        /*   register_code16(_pressed_lparen_keycode); */
        /*   register_code(KC_LSFT); */
        /* } else { */
        /*   _pressed_lparen_keycode = KC_LPRN; */
        /*   register_code16(_pressed_lparen_keycode); */
        /* } */
        /* if (_is_shift_held) { */
        /*   register_code(KC_LSFT); */
        /* } */
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
            if (_is_gunmin_held) {
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
