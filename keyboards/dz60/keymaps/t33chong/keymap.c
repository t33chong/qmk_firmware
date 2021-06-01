#include QMK_KEYBOARD_H

enum _layers {
  _DEFAULT = 0,
  _NUMERALS,
  _ARROWS,
  _MOUSEKEYS,
  _FUNCTION,
  _QUANTUM,
};

enum _keycodes {
  _NULVAL = SAFE_RANGE, // Dummy value used to indicate that no key is currently held
  _RESETT,              // Restart into bootloader after hold timeout
  _UNDSCR,              // Send _
  _FMRSFT,              // Former left shift key: send forward delete if shift held, or shift if alt/gui held, else backspace
  _FMRBSL,              // Former \ key: send \ if modifier held, else -
  _FMRMIN,              // Former - key: send - if modifier held, else brightness down
  _FMREQL,              // Former = key: send = if modifier held, else brightness up
  _FMRBSP,              // Former backspace key: send backspace if modifier held, else volume down
  _FMRDEL,              // Former delete key: send delete if modifier held, else volume up
};

#define _CTLESC CTL_T(KC_ESC)        // Hold for control, tap for escape
#define _QUASPC LT(_QUANTUM, KC_SPC) // Hold for quantum layer, tap for space
#define _MO_FUN MO(_FUNCTION)        // Hold for function layer
#define _MO_NUM MO(_NUMERALS)        // Hold for numerals layer
#define _TO_ARR TO(_ARROWS)          // Activate arrows layer
#define _TO_DEF TO(_DEFAULT)         // Activate default layer
#define _TO_MSK TO(_MOUSEKEYS)       // Activate mousekeys layer
#define _ALTBSP A(KC_BSPC)           // Send alt+backspace
#define _PUSHTT HYPR(KC_BSLS)        // Hold for push to talk with Shush
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEFAULT] = LAYOUT_t33chong(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _FMRMIN, _FMREQL, _FMRBSP, _FMRDEL, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          _FMRBSL, \
    _CTLESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,                   KC_ENT,  \
    _FMRSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_EQL,           _MO_FUN, \
    _PUSHTT, KC_LALT, KC_LGUI,          KC_LSFT,          _MO_NUM,          _QUASPC,          _UNDSCR, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
  ),
  [_NUMERALS] = LAYOUT_t33chong(
    _GUIGRV, G(KC_1), G(KC_2), G(KC_3), G(KC_4), G(KC_5), G(KC_6), G(KC_7), G(KC_8), G(KC_9), G(KC_0), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, KC_COLN,          KC_MINS, \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,                   KC_PLUS, \
    KC_BSPC, _HYP_F1, _HYP_F2, _HYP_F3, _HYP_F4, _HYP_F5, _HYP_F6, _HYP_F7, _HYP_F8, _HYP_F9, _HYP_F0,          KC_EQL,           XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,          XXXXXXX,          KC_SPC,           _UNDSCR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
  ),
  [_ARROWS] = LAYOUT_t33chong(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, \
    _TO_DEF, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,                   XXXXXXX, \
    KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,          XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX,          KC_LALT,          KC_LGUI,          XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
  ),
  [_MOUSEKEYS] = LAYOUT_t33chong(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, \
    _TO_DEF, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX, XXXXXXX,                   KC_BTN4, \
    KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          KC_BTN5,          XXXXXXX, \
    KC_LCTL, KC_LALT, KC_LGUI,          KC_BTN2,          KC_BTN3,          KC_BTN1,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
  ),
  [_FUNCTION] = LAYOUT_t33chong(
    XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  BL_TOGG, _RESETT, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,          XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
  ),
  [_QUANTUM] = LAYOUT_t33chong(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
    _TO_ARR, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, \
    _ALTBSP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______, \
    _______, _______, _______,          _______,          _TO_MSK,          _______,          _______, _______, _______, _______, _______  \
  ),
  /*
  [X] = LAYOUT_t33chong(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______, \
    _______, _______, _______,          _______,          _______,          _______,          _______, _______, _______, _______, _______  \
  ),
  */
};

#define _RGB_ALL(color) RGBLIGHT_LAYER_SEGMENTS({0, 16, color})
const rgblight_segment_t PROGMEM _default_rgb[] = _RGB_ALL(HSV_CYAN);
const rgblight_segment_t PROGMEM _numerals_rgb[] = _RGB_ALL(HSV_CYAN);
const rgblight_segment_t PROGMEM _arrows_rgb[] = _RGB_ALL(HSV_GREEN);
const rgblight_segment_t PROGMEM _mousekeys_rgb[] = _RGB_ALL(HSV_YELLOW);
const rgblight_segment_t PROGMEM _function_rgb[] = _RGB_ALL(HSV_MAGENTA);
const rgblight_segment_t PROGMEM _quantum_rgb[] = _RGB_ALL(HSV_RED);

const rgblight_segment_t* const PROGMEM _rgblight_layers[] = RGBLIGHT_LAYERS_LIST(
  _default_rgb,
  _numerals_rgb,
  _arrows_rgb,
  _mousekeys_rgb,
  _function_rgb,
  _quantum_rgb
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

int _current_layer;
layer_state_t layer_state_set_user(layer_state_t state) {
  _current_layer = get_highest_layer(state);

  rgblight_set_layer_state(_DEFAULT, layer_state_cmp(state, _DEFAULT));
  rgblight_set_layer_state(_NUMERALS, layer_state_cmp(state, _NUMERALS));
  rgblight_set_layer_state(_ARROWS, layer_state_cmp(state, _ARROWS));
  rgblight_set_layer_state(_MOUSEKEYS, layer_state_cmp(state, _MOUSEKEYS));
  rgblight_set_layer_state(_FUNCTION, layer_state_cmp(state, _FUNCTION));
  rgblight_set_layer_state(_QUANTUM, layer_state_cmp(state, _QUANTUM));

  return state;
}

#define _is_mod_held (_is_alt_held || _is_ctrl_held || _is_gui_held || _is_shift_held)
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint32_t _reset_hold_timer;
  static bool _is_alt_held;
  static bool _is_ctrl_held;
  static bool _is_gui_held;
  static bool _is_shift_held;
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
    case _UNDSCR:
      if (record->event.pressed) {
        register_code16(S(KC_MINS));
      } else {
        unregister_code16(S(KC_MINS));
      }
      return false;

    // Context-specific remapping of various keys
    case _FMRSFT:
      if (record->event.pressed) {
        if (_is_alt_held || _is_gui_held) { // Restore left shift key to original function when alt or gui is held
          _held_fmrsft_keycode = KC_LSFT;
        } else if (_is_shift_held) { // Send forward delete if shift is held
          _held_fmrsft_keycode = KC_DEL;
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
        if (_current_layer == _QUANTUM) { // Apply meh or hyper to keycode if right or right+left spacebars are held
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
}
