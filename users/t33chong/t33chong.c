#include "t33chong.h"
#include "qmk-vim/src/vim.h"

const rgblight_segment_t PROGMEM _default_layer_rgb[] = _rgb_all(HSV_CYAN);
const rgblight_segment_t PROGMEM _numerals_layer_rgb[] = _rgb_all(HSV_CYAN);
const rgblight_segment_t PROGMEM _arrows_layer_rgb[] = _rgb_all(HSV_RED);
const rgblight_segment_t PROGMEM _mousekeys_layer_rgb[] = _rgb_all(HSV_YELLOW);
const rgblight_segment_t PROGMEM _function_layer_rgb[] = _rgb_all(HSV_MAGENTA);
const rgblight_segment_t PROGMEM _quantum_layer_rgb[] = _rgb_all(HSV_CYAN);
const rgblight_segment_t PROGMEM _vim_indicator_rgb[] = RGBLIGHT_LAYER_SEGMENTS({0, 16, HSV_GREEN});
const rgblight_segment_t PROGMEM _vim_visual_indicator_rgb[] = RGBLIGHT_LAYER_SEGMENTS({3, 5, HSV_BLUE}, {11, 13, HSV_BLUE});
const rgblight_segment_t PROGMEM _vim_visual_line_indicator_rgb[] = RGBLIGHT_LAYER_SEGMENTS({2, 3, HSV_YELLOW}, {5, 6, HSV_YELLOW}, {10, 11, HSV_YELLOW}, {13, 14, HSV_YELLOW});

const rgblight_segment_t* const PROGMEM _rgblight_layers[] = RGBLIGHT_LAYERS_LIST(
  _default_layer_rgb,
  _numerals_layer_rgb,
  _arrows_layer_rgb,
  _mousekeys_layer_rgb,
  _function_layer_rgb,
  _quantum_layer_rgb,
  _vim_indicator_rgb,
  _vim_visual_indicator_rgb,
  _vim_visual_line_indicator_rgb
);

void keyboard_post_init_user(void) {
  backlight_disable();
  rgblight_enable_noeeprom();
  rgblight_layers = _rgblight_layers;
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

__attribute__ ((weak))
layer_state_t layer_state_set_keymap(layer_state_t state) {
  return state;
}

int _current_layer;
layer_state_t layer_state_set_user(layer_state_t state) {
  _current_layer = get_highest_layer(state);

  rgblight_set_layer_state(_DEFAULT_LAYER, layer_state_cmp(state, _DEFAULT_LAYER));
  rgblight_set_layer_state(_NUMERALS_LAYER, layer_state_cmp(state, _NUMERALS_LAYER));
  rgblight_set_layer_state(_ARROWS_LAYER, layer_state_cmp(state, _ARROWS_LAYER));
  rgblight_set_layer_state(_MOUSEKEYS_LAYER, layer_state_cmp(state, _MOUSEKEYS_LAYER));
  rgblight_set_layer_state(_FUNCTION_LAYER, layer_state_cmp(state, _FUNCTION_LAYER));
  rgblight_set_layer_state(_QUANTUM_LAYER, layer_state_cmp(state, _QUANTUM_LAYER));

  return layer_state_set_keymap(state);
}

void insert_mode_user(void) {
  disable_vim_mode();
  rgblight_set_layer_state(_VIM_INDICATOR, false);
  rgblight_set_layer_state(_VIM_VISUAL_INDICATOR, false);
  rgblight_set_layer_state(_VIM_VISUAL_LINE_INDICATOR, false);
}

void normal_mode_user(void) {
  rgblight_set_layer_state(_VIM_INDICATOR, true);
  rgblight_set_layer_state(_VIM_VISUAL_INDICATOR, false);
  rgblight_set_layer_state(_VIM_VISUAL_LINE_INDICATOR, false);
}

void visual_mode_user(void) {
  rgblight_set_layer_state(_VIM_INDICATOR, true);
  rgblight_set_layer_state(_VIM_VISUAL_INDICATOR, true);
  rgblight_set_layer_state(_VIM_VISUAL_LINE_INDICATOR, false);
}

void visual_line_mode_user(void) {
  rgblight_set_layer_state(_VIM_INDICATOR, true);
  rgblight_set_layer_state(_VIM_VISUAL_INDICATOR, true);
  rgblight_set_layer_state(_VIM_VISUAL_LINE_INDICATOR, true);
}

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_vim_mode(keycode, record)) {
    return false;
  }

  static uint32_t _reset_hold_timer;
  static bool _is_alt_held;
  static bool _is_ctrl_held;
  static bool _is_gui_held;
  static bool _is_shift_held;
  static bool _was_kc_grv_held;
  static uint16_t _held_fmrsft_keycode;
  static uint16_t _held_fmrbsl_keycode;
  static uint16_t _held_fmrmin_keycode;
  static uint16_t _held_fmreql_keycode;
  static uint16_t _held_fmrbsp_keycode;
  static uint16_t _held_fmrdel_keycode;
  static uint16_t _held_quantum_keycode;

  switch (keycode) {
    // Set modifier held booleans
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

    case _RESETT:
      if (record->event.pressed) {
          _reset_hold_timer = timer_read32();
      } else {
        if (timer_elapsed32(_reset_hold_timer) >= 500) {
          reset_keyboard();
        }
      }
      return false;
    case _CLRKBD:
      if (record->event.pressed) {
        clear_keyboard();
        layer_move(_DEFAULT_LAYER);
      }
      return false;
    case _UNDSCR:
      if (record->event.pressed) {
        register_code16(S(KC_MINS));
      } else {
        unregister_code16(S(KC_MINS));
      }
      return false;

    // Context-specific remapping of various keys
    case _VIMGRV:
      if (record->event.pressed) {
        if (_is_mod_held) {
          register_code(KC_GRV);
          _was_kc_grv_held = true;
        } else {
          enable_vim_mode();
        }
      } else {
        if (_was_kc_grv_held) {
          unregister_code(KC_GRV);
          _was_kc_grv_held = false;
        }
      }
      return false;
    case _FMRSFT:
      if (record->event.pressed) {
        if (_is_alt_held || _is_gui_held) { // Restore left shift key to original function when alt or gui is held
          _held_fmrsft_keycode = KC_LSFT;
        } else { // Otherwise send backspace
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
    case _FMRBSL:
      if (record->event.pressed) {
        if (_is_mod_held) { // Restore \ key to original function when modifier is held
          _held_fmrbsl_keycode = KC_BSLS;
        } else { // Otherwise send -
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
    case _FMRMIN:
      if (record->event.pressed) {
        if (_is_mod_held) { // Restore - key to original function when modifier is held
          _held_fmrmin_keycode = KC_MINS;
        } else { // Otherwise send brightness down
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
    case _FMREQL:
      if (record->event.pressed) {
        if (_is_mod_held) { // Restore = key to original function when modifier is held
          _held_fmreql_keycode = KC_EQL;
        } else { // Otherwise send brightness up
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
    case _FMRBSP:
      if (record->event.pressed) {
        if (_is_mod_held) { // Restore backspace key to original function when modifier is held
          _held_fmrbsp_keycode = KC_BSPC;
        } else { // Otherwise send volume down
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
    case _FMRDEL:
      if (record->event.pressed) {
        if (_is_mod_held) { // Restore delete key to original function when modifier is held
          _held_fmrdel_keycode = KC_DEL;
        } else { // Otherwise send volume up
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
    case _TO_ARR:
    case _TO_MSK:
    case _QUASPC:
      return true;

    default:
      if (record->event.pressed) {
        if (_current_layer == _QUANTUM_LAYER) { // Apply meh or hyper to keycode if right or right+left spacebars are held
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
