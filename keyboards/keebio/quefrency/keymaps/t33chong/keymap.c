#include QMK_KEYBOARD_H

enum my_layers {
  _DEFAULT = 0,
  _NUMERALS,
  _ARROWS,
  _MEH,
  _HYPER,
  _MOUSEKEYS,
  _FUNCTION,
};

enum my_keycodes {
  __RESET = SAFE_RANGE, // Restart into bootloader after hold timeout
  _ARRMSK,              // Hold to activate arrows layer, tap to toggle mousekeys layer
  _HYPFUN,              // Hold to activate hyper layer, tap to toggle function layer
  _ALTBSP,              // Send alt+backspace
  _UNDSCR,              // Send underscore (used instead of KC_UNDS to avoid shift applying to next keypress)
  _MODGUI,              // Send command and set boolean flag
};

#define H HYPR
#define _CTLESC CTL_T(KC_ESC)         // Hold for control, tap for escape
#define _MEHMIN LT(_MEH, KC_MINS)     // Hold for meh layer, tap for -
#define _NUMSPC LT(_NUMERALS, KC_SPC) // Hold for numerals layer, tap for space
#define _PUSHTT HYPR(KC_BSLS)         // Hold for push to talk with Shush
#define _ALTLFT A(KC_LEFT)            // Send alt+left
#define _ALTRGT A(KC_RGHT)            // Send alt+right

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEFAULT] = LAYOUT_t33chong(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BRMD, KC_BRMU, KC_VOLD, KC_VOLU, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_BSLS, \
    _CTLESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,                   KC_ENT,  \
    KC_BSPC, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_EQL,           KC_UP,   \
    _ARRMSK, KC_LALT, _MODGUI,          KC_LSFT,          _MEHMIN,          _NUMSPC,          _UNDSCR, _HYPFUN, KC_LEFT, KC_RGHT, KC_DOWN  \
  ),
  [_NUMERALS] = LAYOUT_t33chong(
    _______, G(KC_1), G(KC_2), G(KC_3), G(KC_4), G(KC_5), G(KC_6), G(KC_7), G(KC_8), G(KC_9), G(KC_0), _______, _______, _______, _______, \
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, _______,          _______, \
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,                   _______, \
    _ALTBSP, H(KC_1), H(KC_2), H(KC_3), H(KC_4), H(KC_5), H(KC_6), H(KC_7), H(KC_8), H(KC_9), H(KC_0),          _______,          _______, \
    _______, _______, _______,          _______,          _______,          _______,          _______, _______, _______, _______, _______  \
  ),
  [_ARROWS] = LAYOUT_t33chong(
    _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _ALTLFT, KC_UP,   _ALTRGT, _______, _______, _______,          _______, \
    _______, _______, _______, _______, _______, _______, C(KC_A), KC_LEFT, KC_DOWN, KC_RGHT, C(KC_E), _______,                   _______, \
    KC_LSFT, _______, _______, _______, _______, _______, _______, _______, KC_END,  _______, _______,          _______,          _______, \
    _______, _PUSHTT, _______,          _______,          _______,          _______,          _______, _______, _______, _______, _______  \
  ),
  [_MEH] = LAYOUT_t33chong(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
    KC_ESC,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_EQL,           _______, \
    _______, _______, _______,          _______,          _______,          KC_SPC,           KC_MINS, _______, _______, _______, _______  \
  ),
  [_HYPER] = LAYOUT_t33chong(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
    KC_ESC,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_EQL,           _______, \
    _______, _______, _______,          _______,          _______,          KC_SPC,           KC_MINS, _______, _______, _______, _______  \
  ),
  [_MOUSEKEYS] = LAYOUT_t33chong(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, KC_MS_U, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
    _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, _______,                   _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______, \
    _______, _______, _______,          KC_BTN2,          KC_BTN3,          KC_BTN1,          _______, _______, _______, _______, _______  \
  ),
  [_FUNCTION] = LAYOUT_t33chong(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  BL_TOGG, RESET,   \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______, \
    _______, _______, _______,          _______,          _______,          _______,          _______, _______, _______, _______, _______  \
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

void keyboard_post_init_user(void) {
  backlight_disable();
  rgblight_enable_noeeprom();
  rgblight_setrgb(RGB_CYAN);
}

// If true, don't count a tap and a hold as repetition of the tap action
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case _CTLESC:
    case _NUMSPC:
      return true;
    default:
      return false;
  }
}

bool _is_meh_active;
bool _is_hyper_active;

layer_state_t layer_state_set_user(layer_state_t state) {
  int _current_layer = get_highest_layer(state);

  // Indicate layer with RGB underglow lighting effect
  // https://docs.qmk.fm/#/custom_quantum_functions?id=layer-change-code
  // https://github.com/qmk/qmk_firmware/blob/master/quantum/rgblight_list.h
  switch (_current_layer) {
    case _ARROWS:
      rgblight_setrgb(RGB_GREEN);
      break;
    case _NUMERALS:
      rgblight_setrgb(RGB_WHITE);
      break;
    case _MOUSEKEYS:
      rgblight_setrgb(RGB_YELLOW);
      break;
    case _FUNCTION:
      rgblight_setrgb(RGB_MAGENTA);
      break;
    case _MEH:
      rgblight_setrgb(RGB_BLUE);
      break;
    case _HYPER:
      rgblight_setrgb(RGB_RED);
      break;
    default:
      rgblight_setrgb(RGB_CYAN);
      break;
  }

  // Set layer booleans
  switch (_current_layer) {
    case _MEH:
      _is_meh_active = true;
      _is_hyper_active = false;
      break;
    case _HYPER:
      _is_meh_active = false;
      _is_hyper_active = true;
      break;
    default:
      _is_meh_active = false;
      _is_hyper_active = false;
      break;
  }

  return state;
}

#define MODS_SHIFT (get_mods() & MOD_BIT(KC_LSFT) || get_mods() & MOD_BIT(KC_RSFT))
#define MODS_CTRL (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTL))
#define MODS_ALT (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))
#define MODS_GUI (get_mods() & MOD_BIT(KC_LGUI) || get_mods() & MOD_BIT(KC_RGUI))
#define MODS_MEH (get_mods() & MOD_BIT(KC_LCTL) && get_mods() & MOD_BIT(KC_LSFT) && get_mods() & MOD_BIT(KC_LALT))
#define MODS_HYPER (get_mods() & MOD_BIT(KC_LCTL) && get_mods() & MOD_BIT(KC_LSFT) && get_mods() & MOD_BIT(KC_LALT) && get_mods() & MOD_BIT(KC_LGUI))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint32_t _arrmsk_hold_timer;
  static uint32_t _hypfun_hold_timer;
  static uint32_t _reset_hold_timer;
  static bool _is_gui_held;
  switch (keycode) {
    case _ALTBSP:
      if (record->event.pressed) {
        register_code16(A(KC_BSPC));
      } else {
        unregister_code16(A(KC_BSPC));
      }
      return false;
    case _ARRMSK:
      if (record->event.pressed) {
        _arrmsk_hold_timer = timer_read32();
        layer_on(_ARROWS);
      } else {
        layer_off(_ARROWS);
        if (timer_elapsed32(_arrmsk_hold_timer) < TAPPING_TERM) {
          layer_invert(_MOUSEKEYS);
        }
      }
      return false;
    case _MODGUI:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        _is_gui_held = true;
      } else {
        unregister_code(KC_LGUI);
        _is_gui_held = false;
      }
      return false;
    case _HYPFUN:
      if (record->event.pressed) {
        _hypfun_hold_timer = timer_read32();
        layer_on(_HYPER);
      } else {
        layer_off(_HYPER);
        if (timer_elapsed32(_hypfun_hold_timer) < TAPPING_TERM) {
          layer_invert(_FUNCTION);
        }
      }
      return false;
    case __RESET:
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
    case KC_BSPC:
      if (_is_gui_held) { // Restore left shift key to original function when gui is held
        if (record->event.pressed) {
          register_code(KC_LSFT);
        } else {
          unregister_code(KC_LSFT);
        }
        return false;
      } else if (_is_meh_active) { // Make backspace send forward delete when meh is held
        if (record->event.pressed) {
          register_code(KC_DEL);
        } else {
          unregister_code(KC_DEL);
        }
        return false;
      }
      return true;
    default:
      if (_is_meh_active) {
        if (keycode == _MEHMIN) {
          return true;
        }
        if (record->event.pressed) {
          register_code16(MEH(keycode));
        } else {
          unregister_code16(MEH(keycode));
        }
        return false;
      } else if (_is_hyper_active) {
        if (keycode == _HYPFUN) {
          return true;
        }
        if (record->event.pressed) {
          register_code16(HYPR(keycode));
        } else {
          unregister_code16(HYPR(keycode));
        }
        return false;
      }
      return true; // Process all other keycodes normally
  }
}
