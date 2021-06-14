#include "t33chong.h"
#include "qmk-vim/src/vim.h"
#include "qmk-vim/src/modes.h"

// Indicate layers with RGB underglow
const rgblight_segment_t PROGMEM _cyan_rgblight_layer[] = _rgb_all(HSV_CYAN);
const rgblight_segment_t PROGMEM _green_rgblight_layer[] = _rgb_all(HSV_GREEN);
const rgblight_segment_t PROGMEM _yellow_rgblight_layer[] = _rgb_all(HSV_YELLOW);
const rgblight_segment_t PROGMEM _red_rgblight_layer[] = _rgb_all(HSV_RED);
const rgblight_segment_t PROGMEM _magenta_rgblight_layer[] = _rgb_all(HSV_MAGENTA);

const rgblight_segment_t* const PROGMEM _rgblight_layers[] = RGBLIGHT_LAYERS_LIST(
  _cyan_rgblight_layer,
  _green_rgblight_layer,
  _yellow_rgblight_layer,
  _red_rgblight_layer,
  _magenta_rgblight_layer
);

int _current_layer;

// Allow for keyboard-specific layer state
__attribute__ ((weak))
layer_state_t layer_state_set_keymap(layer_state_t state) {
  return state;
}

// Layer state
layer_state_t layer_state_set_user(layer_state_t state) {
  _current_layer = get_highest_layer(state);

  rgblight_set_layer_state(_CYAN_RGBLIGHT_LAYER, (layer_state_cmp(state, _DEFAULT_LAYER || layer_state_cmp(state, _NUMERALS_LAYER)) || layer_state_cmp(state, _QUANTUM_LAYER)));
  rgblight_set_layer_state(_RED_RGBLIGHT_LAYER, layer_state_cmp(state, _MOUSEKEYS_LAYER));
  rgblight_set_layer_state(_MAGENTA_RGBLIGHT_LAYER, layer_state_cmp(state, _FUNCTION_LAYER));

  return layer_state_set_keymap(state);
}

// Execute on startup
void keyboard_post_init_user(void) {
  backlight_disable();
  rgblight_layers = _rgblight_layers;
  rgblight_enable_noeeprom();
}

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

// Vim mode user hooks: set custom state
void insert_mode_user(void) {
  disable_vim_mode();
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
    case KC_I: // Exit Vim mode
      if (record->event.pressed) {
        insert_mode();
      }
      return false;
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
    case KC_I: // Exit Vim mode
      if (record->event.pressed) {
        insert_mode();
      }
      return false;
    case KC_ESC: // Set escape press timer for normal mode override
      if (record->event.pressed) {
        _esc_press_timer = timer_read();
      }
      return true;
    default:
      return true;
  }
}

// Allow for keyboard-specific macros
__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

// Macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_vim_mode(keycode, record)) {
    return false;
  }

  static uint16_t _reset_hold_timer;
  static bool _is_alt_held;
  static bool _is_ctrl_held;
  static bool _is_gui_held;
  static bool _is_shift_held;
  static bool _was_kc_grv_pressed;
  static uint16_t _held_fmrsft_keycode;
  static uint16_t _held_fmrbsl_keycode;
  static uint16_t _held_fmrmin_keycode;
  static uint16_t _held_fmreql_keycode;
  static uint16_t _held_fmrbsp_keycode;
  static uint16_t _held_fmrdel_keycode;
  static uint16_t _held_quantum_keycode;

  switch (keycode) {
    // Set held modifier state
    case _CTLESC:
      if (record->event.pressed) {
        _is_ctrl_held = true;
      } else {
        _is_ctrl_held = false;
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

    case _RESETT: // Restart into bootloader after hold timeout
      if (record->event.pressed) {
          _reset_hold_timer = timer_read();
      } else {
        if (timer_elapsed(_reset_hold_timer) >= 500) {
          reset_keyboard();
        }
      }
      return false;
    case _CLRKBD: // Clear all held keycodes
      if (record->event.pressed) {
        clear_keyboard();
        layer_move(_DEFAULT_LAYER);
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
    case _VIMGRV: // Former ` key: send ` if modifier held, else enter Vim mode
      if (record->event.pressed) {
        if (_is_mod_held) {
          register_code(KC_GRV);
          _was_kc_grv_pressed = true;
        } else {
          enable_vim_mode();
        }
      } else {
        if (_was_kc_grv_pressed) {
          unregister_code(KC_GRV);
          _was_kc_grv_pressed = false;
        }
      }
      return false;
    case _FMRSFT: // Former left shift key: send shift if alt/gui held, else backspace
      if (record->event.pressed) {
        if (_is_alt_held || _is_gui_held) {
          _held_fmrsft_keycode = KC_LSFT;
        } else {
          _held_fmrsft_keycode = KC_BSPC;
        }
        register_code16(_held_fmrsft_keycode);
      } else {
        if (_held_fmrsft_keycode != _NULVAL) {
          unregister_code16(_held_fmrsft_keycode);
          _held_fmrsft_keycode = _NULVAL;
        }
      }
      return false;
    case _FMRBSL: // Former \ key: send \ if modifier held, else -
      if (record->event.pressed) {
        if (_is_mod_held) {
          _held_fmrbsl_keycode = KC_BSLS;
        } else {
          _held_fmrbsl_keycode = KC_MINS;
        }
        register_code16(_held_fmrbsl_keycode);
      } else {
        if (_held_fmrbsl_keycode != _NULVAL) {
          unregister_code16(_held_fmrbsl_keycode);
          _held_fmrbsl_keycode = _NULVAL;
        }
      }
      return false;
    case _FMRMIN: // Former - key: send - if modifier held, else brightness down
      if (record->event.pressed) {
        if (_is_mod_held) {
          _held_fmrmin_keycode = KC_MINS;
        } else {
          _held_fmrmin_keycode = KC_BRMD;
        }
        register_code16(_held_fmrmin_keycode);
      } else {
        if (_held_fmrmin_keycode != _NULVAL) {
          unregister_code16(_held_fmrmin_keycode);
          _held_fmrmin_keycode = _NULVAL;
        }
      }
      return false;
    case _FMREQL: // Former = key: send = if modifier held, else brightness up
      if (record->event.pressed) {
        if (_is_mod_held) {
          _held_fmreql_keycode = KC_EQL;
        } else {
          _held_fmreql_keycode = KC_BRMU;
        }
        register_code16(_held_fmreql_keycode);
      } else {
        if (_held_fmreql_keycode != _NULVAL) {
          unregister_code16(_held_fmreql_keycode);
          _held_fmreql_keycode = _NULVAL;
        }
      }
      return false;
    case _FMRBSP: // Former backspace key: send backspace if modifier held, else volume down
      if (record->event.pressed) {
        if (_is_mod_held) {
          _held_fmrbsp_keycode = KC_BSPC;
        } else {
          _held_fmrbsp_keycode = KC_VOLD;
        }
        register_code16(_held_fmrbsp_keycode);
      } else {
        if (_held_fmrbsp_keycode != _NULVAL) {
          unregister_code16(_held_fmrbsp_keycode);
          _held_fmrbsp_keycode = _NULVAL;
        }
      }
      return false;
    case _FMRDEL: // Former delete key: send delete if modifier held, else volume up
      if (record->event.pressed) {
        if (_is_mod_held) {
          _held_fmrdel_keycode = KC_DEL;
        } else {
          _held_fmrdel_keycode = KC_VOLU;
        }
        register_code16(_held_fmrdel_keycode);
      } else {
        if (_held_fmrdel_keycode != _NULVAL) {
          unregister_code16(_held_fmrdel_keycode);
          _held_fmrdel_keycode = _NULVAL;
        }
      }
      return false;

    // Exempt special keys on quantum layer from meh/hyper passthrough
    case _ALTBSP:
    case _TO_MSK:
    case _QUASPC:
      return true;

    default:
      if (record->event.pressed) {
        // Apply meh to keycode if right spacebar held, hyper if right+left spacebars held
        if (_current_layer == _QUANTUM_LAYER) {
          if (_is_shift_held) {
            _held_quantum_keycode = HYPR(keycode);
          } else {
            _held_quantum_keycode = MEH(keycode);
          }
          register_code16(_held_quantum_keycode);
          return false;
        }
      } else {
        if (_held_quantum_keycode != _NULVAL) {
          unregister_code16(_held_quantum_keycode);
          _held_quantum_keycode = _NULVAL;
          return false;
        }
      }
      return true; // Process all other keycodes normally
  }
  return process_record_keymap(keycode, record);
}
