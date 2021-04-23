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

// TODO:
// Make right space + backspace send alt + backspace

#define _CTLESC LCTL_T(KC_ESC)  // Hold for control, tap for escape
#define _HYPSPC HYPR_T(KC_SPC)  // Hold for hyper, tap for space
#define _MEHSPC MEH_T(KC_SPC)   // Hold for meh, tap for space
#define _SFTMNS LSFT_T(KC_MINS) // Hold for shift, tap for - or caps lock when shifted
#define _SFTEQL RSFT_T(KC_EQL)  // Hold for shift, tap for = or + when shifted
#define _LYRFUN MO(_FUNCTION)   // Hold to toggle function layer

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
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______, \
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
  rgblight_enable_noeeprom();
  rgblight_setrgb(RGB_CYAN);
}

// TODO:
// Make rshift + lshift toggle caps lock
// Make ctrl toggle num layer when tapped (and continue activating arrow layer when held)
// Make right space + backspace send alt + backspace

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

#define MODS_SHIFT (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))
#define MODS_GUI (get_mods() & MOD_BIT(KC_LGUI) || get_mods() & MOD_BIT(KC_RGUI))
#define MODS_MEH MODS_SHIFT && MODS_CTRL && MODS_ALT
#define MODS_HYPER MODS_MEH && MODS_GUI

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
    case _SFTMNS:
      // Toggles caps lock if pressed while shift is held
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
    case KC_BSPC:
      if (MODS_HYPER) {
        /* if (record->event.pressed) { */
        /*   /1* register_code(KC_LALT); *1/ */
        /*   /1* register_code(KC_BSPC); *1/ */
        /*   register_code16(LALT(KC_BSPC)); */
        /* } else { */
        /*   /1* unregister_code(KC_BSPC); *1/ */
        /*   /1* unregister_code(KC_LALT); *1/ */
        /*   unregister_code16(LALT(KC_BSPC)); */
        /* } */

        /* if (record->event.pressed) { */
        /*   /1* unregister_code16(KC_HYPR); *1/ */
        /*   unregister_code(KC_LSHIFT); */
        /*   unregister_code(KC_LCTRL); */
        /*   unregister_code(KC_LALT); */
        /*   unregister_code(KC_LGUI); */
        /*   SEND_STRING(SS_LALT(SS_TAP(X_BSPC))); */
        /* } else { */
        /*   register_code(KC_LSHIFT); */
        /*   register_code(KC_LCTRL); */
        /*   register_code(KC_LALT); */
        /*   register_code(KC_LGUI); */
        /* } */

        /* if (record->event.pressed) { */
        /*   unregister_code(KC_LSHIFT); */
        /*   unregister_code(KC_LCTRL); */
        /*   unregister_code(KC_LGUI); */
        /*   register_code(KC_BSPC); */
        /* } else { */
        /*   unregister_code(KC_BSPC); */
        /*   register_code(KC_LSHIFT); */
        /*   register_code(KC_LCTRL); */
        /*   register_code(KC_LGUI); */
        /* } */

        if (record->event.pressed) {
          unregister_code16(KC_HYPR);
          register_code(KC_LALT);
          register_code(KC_BSPC);
        } else {
          unregister_code(KC_BSPC);
          unregister_code(KC_LALT);
          register_code16(KC_HYPR);
        }

        return false;
      }
      return true;
    default:
      return true; // Process all other keycodes normally
  }
}
