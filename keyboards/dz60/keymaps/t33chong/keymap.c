#include QMK_KEYBOARD_H

enum my_layers {
  _DEFAULT = 0,
  _ARROWS,
  _NUMPAD,
  _FUNCTION,
};

enum my_keycodes {
  __RESET = SAFE_RANGE, // Restart into bootloader after hold timeout
  _UNDSCR,              // Use instead of KC_UNDS to avoid shift applying to next keypress
  _ARRNUM,              // Hold to activate arrows layer, tap to toggle numpad layer
};

#define _CTLESC LCTL_T(KC_ESC)  // Hold for control, tap for escape
#define _HYPSPC HYPR_T(KC_SPC)  // Hold for hyper, tap for space
#define _MEHSPC MEH_T(KC_SPC)   // Hold for meh, tap for space
#define _SFTMNS LSFT_T(KC_MINS) // Hold for shift, tap for - or caps lock when shifted
#define _SFTEQL RSFT_T(KC_EQL)  // Hold for shift, tap for = or + when shifted
#define _LYRFUN MO(_FUNCTION)   // Hold to toggle function layer
#define _HYPBSL HYPR(KC_BSLS)   // Hold for push to talk with Shush

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEFAULT] = LAYOUT_t33chong(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BRMD, KC_BRMU, KC_VOLD, KC_VOLU, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_BSLS, \
    _CTLESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,                   KC_ENT,  \
    _SFTMNS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          _SFTEQL,          _LYRFUN, \
    _ARRNUM, KC_LALT, KC_LGUI,          _MEHSPC,          KC_BSPC,          _HYPSPC,          _UNDSCR, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
  ),
  [_ARROWS] = LAYOUT_t33chong(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,                   _______, \
    _______, _HYPBSL, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______, \
    _______, _______, _______,          _______,          _______,          _______,          _______, _______, _______, _______, _______  \
  ),
  [_NUMPAD] = LAYOUT_t33chong(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LPRN, KC_RPRN, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, KC_KP_7, KC_KP_8, KC_KP_9, KC_PSLS, KC_PAST, KC_PERC,          _______, \
    _______, _______, _______, _______, _______, _______, KC_BSPC, KC_KP_4, KC_KP_5, KC_KP_6, KC_PMNS, KC_PPLS,                   _______, \
    _______, _______, _______, _______, _______, _______, _UNDSCR, KC_KP_1, KC_KP_2, KC_KP_3, KC_PDOT,          KC_EQL,           _______, \
    _______, _______, _______,          _______,          _______,          KC_KP_0,          _______, _______, _______, _______, _______  \
  ),
  [_FUNCTION] = LAYOUT_t33chong(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, __RESET, \
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

// If true, given a pressed modifier, pressed key, released modifier, and released key, register both as taps
// If false, register a held modifier
bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case _CTLESC:
    case _HYPSPC:
    case _MEHSPC:
    case _SFTEQL:
    case _SFTMNS:
      return true;
    default:
      return false;
  }
}

// If true, given a pressed modifier, tapped key, and released modifier all within TAPPING_TERM, register a held modifier
// If false, count both as taps
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case _SFTEQL:
    case _SFTMNS:
      return true;
    default:
      return false;
  }
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

// Number of milliseconds before a pressed key is registered as held
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case _SFTEQL:
    case _SFTMNS:
      return 120;
    default:
      return TAPPING_TERM;
  }
}

// Indicate layer and caps lock status with RGB underglow lighting effect
// https://docs.qmk.fm/#/custom_quantum_functions?id=layer-change-code
// https://github.com/qmk/qmk_firmware/blob/master/quantum/rgblight_list.h
int _current_layer = 0;
bool _is_caps_lock_on = false;

void _set_rgblight_color(int current_layer, bool is_caps_lock_on) {
  switch (current_layer) {
    case _ARROWS:
      rgblight_setrgb(RGB_ORANGE);
      break;
    case _NUMPAD:
      rgblight_setrgb(RGB_GREEN);
      break;
    case _FUNCTION:
      rgblight_setrgb(RGB_PURPLE);
      break;
    default:
      rgblight_setrgb(RGB_CYAN);
      break;
  }
  if (is_caps_lock_on) {
    rgblight_setrgb_range(RGB_RED, 8, 16); // Bottom half
  }
}

layer_state_t layer_state_set_user(layer_state_t state) {
  _current_layer = get_highest_layer(state);
  _set_rgblight_color(_current_layer, _is_caps_lock_on);
  return state;
}

bool led_update_user(led_t led_state) {
  _is_caps_lock_on = led_state.caps_lock;
  _set_rgblight_color(_current_layer, _is_caps_lock_on);
  return true;
}

#define MODS_SHIFT (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))
#define MODS_GUI (get_mods() & MOD_BIT(KC_LGUI) || get_mods() & MOD_BIT(KC_RGUI))
#define MODS_MEH (MODS_SHIFT && MODS_CTRL && MODS_ALT)
#define MODS_HYPER (MODS_MEH && MODS_GUI)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint32_t _reset_key_timer;
  static uint32_t _arrnum_key_timer;

  switch (keycode) {
    case __RESET:
      if (record->event.pressed) {
          _reset_key_timer = timer_read32();
      } else {
        if (timer_elapsed32(_reset_key_timer) >= 500) {
          reset_keyboard();
        }
      }
      return false;
    case _UNDSCR:
      if (record->event.pressed) {
        SEND_STRING("_");
      }
      return false;
    case _SFTMNS: // Toggles caps lock if pressed while shift is held
      if (MODS_SHIFT && record->event.pressed) {
        tap_code(KC_CAPS);
        return false;
      }
      return true;
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
    default:
      return true; // Process all other keycodes normally
  }
}
