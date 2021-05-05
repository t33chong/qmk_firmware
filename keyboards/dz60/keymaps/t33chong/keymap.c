#include QMK_KEYBOARD_H

enum my_layers {
  _DEFAULT = 0,
  _ARROWS,
  _NUMPAD,
  _MEH,
  _HYPER,
  _MOUSEKEYS,
  _FUNCTION,
};

enum my_keycodes {
  _ARRNUM = SAFE_RANGE, // Hold to activate arrows layer, tap to toggle numpad layer
  _FUNMSK,              // Hold to activate function layer, tap to toggle mousekeys layer
  _ALTBSP,              // Send alt+backspace
  _UNDSCR,              // Send underscore
};

#define _CTLESC LCTL_T(KC_ESC)     // Hold for control, tap for escape
#define _MEHMIN LT(_MEH, KC_MINS)  // Hold for meh, tap for -
#define _HYPSPC LT(_HYPER, KC_SPC) // Hold for hyper, tap for space
#define _SFTEQL LSFT_T(KC_EQL)     // Hold for shift, tap for =
#define _PUSHTT HYPR(KC_BSLS)      // Hold for push to talk with Shush

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEFAULT] = LAYOUT_t33chong(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BRMD, KC_BRMU, KC_VOLD, KC_VOLU, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_BSLS, \
    _CTLESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,                   KC_ENT,  \
    KC_BSPC, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          _SFTEQL,          _FUNMSK, \
    _ARRNUM, KC_LALT, KC_LGUI,          KC_LSFT,          _MEHMIN,          _HYPSPC,          _UNDSCR, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
  ),
  [_ARROWS] = LAYOUT_t33chong(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,                   _______, \
    KC_LSFT, _PUSHTT, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______, \
    _______, _______, _______,          _______,          _______,          _______,          _______, _______, _______, _______, _______  \
  ),
  [_NUMPAD] = LAYOUT_t33chong(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LPRN, KC_RPRN, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, KC_COLN, KC_KP_7, KC_KP_8, KC_KP_9, KC_PSLS, KC_PAST, KC_PERC,          _______, \
    _______, _______, _______, _______, _______, _______, KC_BSPC, KC_KP_4, KC_KP_5, KC_KP_6, KC_PMNS, KC_PPLS,                   _______, \
    _______, _______, _______, _______, _______, _______, KC_UNDS, KC_KP_1, KC_KP_2, KC_KP_3, KC_PDOT,          KC_EQL,           _______, \
    _______, _______, _______,          _______,          _______,          KC_KP_0,          _______, _______, _______, _______, _______  \
  ),
  [_MEH] = LAYOUT_t33chong(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
    KC_ESC,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_EQL,           _______, \
    _______, _______, _______,          _PUSHTT,          _______,          KC_SPC,           KC_MINS, _______, _______, _______, _______  \
  ),
  [_HYPER] = LAYOUT_t33chong(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
    KC_ESC,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, \
    _ALTBSP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_EQL,           _______, \
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
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, RESET,   \
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
  backlight_enable();
  backlight_level(BACKLIGHT_LEVELS);
  rgblight_enable_noeeprom();
  rgblight_setrgb(RGB_CYAN);
}

// If true, don't count a tap and a hold as repetition of the tap action
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case _CTLESC:
      return true;
    default:
      return false;
  }
}

// Indicate layer with RGB underglow lighting effect
// https://docs.qmk.fm/#/custom_quantum_functions?id=layer-change-code
// https://github.com/qmk/qmk_firmware/blob/master/quantum/rgblight_list.h
bool _is_meh_active;
bool _is_hyper_active;
layer_state_t layer_state_set_user(layer_state_t state) {
  int _current_layer = get_highest_layer(state);
  switch (_current_layer) {
    case _ARROWS:
      rgblight_setrgb(RGB_GREEN);
      break;
    case _NUMPAD:
      rgblight_setrgb(RGB_RED);
      break;
    case _MOUSEKEYS:
      rgblight_setrgb(RGB_YELLOW);
      break;
    case _FUNCTION:
      rgblight_setrgb(RGB_MAGENTA);
      break;
    case _HYPER:
      rgblight_setrgb(RGB_BLUE);
      break;
    default:
      rgblight_setrgb(RGB_CYAN);
      break;
  }
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

#define MODS_SHIFT (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint32_t _arrnum_key_timer;
  static uint32_t _funmsk_key_timer;
  switch (keycode) {
    case _ALTBSP:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_BSPC)));
      }
      return false;
    case _ARRNUM:
      if (record->event.pressed) {
        _arrnum_key_timer = timer_read32();
        layer_on(_ARROWS);
      } else {
        layer_off(_ARROWS);
        if (timer_elapsed32(_arrnum_key_timer) < TAPPING_TERM) {
          layer_invert(_NUMPAD);
        }
      }
      return false;
    case _FUNMSK:
      if (record->event.pressed) {
        _funmsk_key_timer = timer_read32();
        layer_on(_FUNCTION);
      } else {
        layer_off(_FUNCTION);
        if (timer_elapsed32(_funmsk_key_timer) < TAPPING_TERM) {
          layer_invert(_MOUSEKEYS);
        }
      }
      return false;
    case _UNDSCR:
      if (record->event.pressed) {
        if (MODS_SHIFT) {
          tap_code(KC_MINS);
        } else {
          SEND_STRING("_");
        }
      }
      return false;
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
        if (keycode == _HYPSPC) {
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
