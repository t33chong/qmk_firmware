#include QMK_KEYBOARD_H

enum alt_keycodes {
  U_T_AUTO = SAFE_RANGE, //USB Extra Port Toggle Auto Detect / Always Active
  U_T_AGCR,              //USB Toggle Automatic GCR control
  DBG_TOG,               //DEBUG Toggle On / Off
  DBG_MTRX,              //DEBUG Toggle Matrix Prints
  DBG_KBD,               //DEBUG Toggle Keyboard Prints
  DBG_MOU,               //DEBUG Toggle Mouse Prints
  MD_BOOT,               //Restart into bootloader after hold timeout
  NEW_SAFE_RANGE
};

enum my_keycodes {
  MY_UNDS = NEW_SAFE_RANGE, // Use instead of KC_UNDS to avoid shift applying to next keypress
  /* MY_SFBS,                  // Hold for shift, tap for alt+backspace */
};

enum my_layers {
  _DEFAULT = 0,
  _MOUSE_KEYS,
  _NUMPAD,
  _GAMING,
  _GAMING2,
  _BURRITO,
  _BURRITO2,
  _FUNCTION,
};

#define MY_GUEQ LGUI_T(KC_EQL)        // Hold for command, tap for equal sign
#define MY_CTES LCTL_T(KC_ESC)        // Hold for control, tap for escape
#define MY_HYSP HYPR_T(KC_SPC)        // Hold for hyper, tap for space
#define MY_SFBS LSFT_T(KC_BSPC)       // Hold for shift, tap for backspace
#define MY_SFCA RSFT_T(KC_CAPS)       // Hold for shift, tap for caps lock
#define MY_ESG2 LT(_GAMING2, KC_ESC)  // Hold for gaming arrows layer, tap for escape
#define MY_HYBS HYPR(KC_BSLS)         // Hold for push to talk with Shush
#define MY_TGMK TG(_MOUSE_KEYS)       // Press to toggle mouse keys layer
#define MY_MONP MO(_NUMPAD)           // Hold to toggle numpad layer
#define MY_TGGM TG(_GAMING)           // Press to toggle gaming layer
#define MY_TGBR TG(_BURRITO)          // Press to toggle burrito layer
#define MY_MOFN MO(_FUNCTION)         // Hold to toggle numpad layer
#define MY_LTSP LT(_BURRITO2, KC_SPC) // Hold to toggle burrito layer, tap for space

// TODO: Hold tab for yuiohjklnm,. shortcuts like the ones I set up with BTT. Would switch to a new layer where holding space selects text
// Hold lshift and tap rshift for =

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEFAULT] = LAYOUT_65_ansi_blocker(
          KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, MY_TGGM, \
          KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, MY_TGBR, \
          MY_CTES, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP, \
          MY_SFBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MY_SFCA,          KC_UP,   KC_PGDN, \
          MY_MONP, KC_LALT, MY_GUEQ,                            MY_HYSP,                            MY_UNDS, MY_MOFN, KC_LEFT, KC_DOWN, KC_RGHT  \
  ),
  [_MOUSE_KEYS] = LAYOUT_65_ansi_blocker(
          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
          _______, KC_WH_U, KC_MS_U, KC_WH_D, KC_HOME, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
          _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_END,  _______, _______, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, KC_BTN5,          _______, _______, \
          _______, KC_WH_L, _______, KC_WH_R, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
          _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
  ),
  [_NUMPAD] = LAYOUT_65_ansi_blocker(
          _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LPRN, KC_RPRN, _______, _______, _______, _______, \
          _______, _______, _______, _______, _______, _______, _______, KC_KP_7, KC_KP_8, KC_KP_9, KC_PSLS, KC_PAST, KC_PERC, _______, _______, \
          _______, _______, _______, _______, _______, _______, KC_BSPC, KC_KP_4, KC_KP_5, KC_KP_6, KC_PMNS, KC_PPLS,          _______, _______, \
          _______, _______, _______, _______, _______, _______, MY_UNDS, KC_KP_1, KC_KP_2, KC_KP_3, KC_PDOT, KC_EQL,           _______, _______, \
          _______, MY_HYBS, _______,                            KC_KP_0,                            KC_SPC,  _______, _______, _______, _______  \
  ),
  [_GAMING] = LAYOUT_65_ansi_blocker(
          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
          MY_ESG2, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
          KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
          KC_LCTL, KC_EQL,  KC_LALT,                            _______,                            _______, KC_LGUI, _______, _______, _______  \
  ),
  [_GAMING2] = LAYOUT_65_ansi_blocker( // WASD arrows/mirror image
          _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______, _______, _______, _______, _______, _______, _______, _______, \
          _______, KC_P,    KC_UP,   KC_I,    KC_U,    KC_Y,    _______, _______, _______, _______, _______, _______, _______, _______, _______, \
          _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_J,    KC_H,    _______, _______, _______, _______, _______, _______,          _______, _______, \
          _______, KC_SLSH, KC_DOT,  KC_COMM, KC_M,    KC_N,    _______, _______, _______, _______, _______, _______,          _______, _______, \
          _______, _______, _______,                            KC_ENT,                             _______, _______, _______, _______, _______  \
  ),
  [_BURRITO] = LAYOUT_65_ansi_blocker( // Enables typing while holding a burrito in one hand
          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
          _______, _______, _______,                            MY_LTSP,                            _______, _______, _______, _______, _______  \
  ),
  [_BURRITO2] = LAYOUT_65_ansi_blocker( // Mirror image, akin to the swap hands feature
          KC_EQL,  KC_MINS, KC_0,    KC_9,    KC_8,    KC_7,    KC_6,    KC_5,    KC_4,    KC_3,    KC_2,    KC_1,    KC_GRV,  _______, _______, \
          KC_BSPC, KC_P,    KC_O,    KC_I,    KC_U,    KC_Y,    KC_T,    KC_R,    KC_E,    KC_W,    KC_Q,    KC_TAB,  _______, _______, _______, \
          KC_ENT,  KC_SCLN, KC_L,    KC_K,    KC_J,    KC_H,    KC_G,    KC_F,    KC_D,    KC_S,    KC_A,    MY_CTES,          _______, _______, \
          _______, KC_SLSH, KC_DOT,  KC_COMM, KC_M,    KC_N,    KC_B,    KC_V,    KC_C,    KC_X,    KC_Z,    _______,          _______, _______, \
          _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
  ),
  [_FUNCTION] = LAYOUT_65_ansi_blocker(
          _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, MD_BOOT, \
          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
          MY_TGMK, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_PGUP, _______, \
          _______, _______, _______,                            _______,                            _______, _______, KC_HOME, KC_PGDN, KC_END   \
  ),
  /*
  [X] = LAYOUT_65_ansi_blocker(
          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
          _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
  ),
  */
};

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MY_CTES:
    case MY_HYSP:
    case MY_ESG2:
      return true;
    default:
      return false;
  }
}

// If true, don't count a tap and a hold as repetition of the tap action
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MY_CTES:
    case MY_LTSP:
      return true;
    default:
      return false;
  }
}

// Indicate layer with RGB matrix effect
// https://docs.qmk.fm/#/custom_quantum_functions?id=layer-change-code
uint8_t _current_rgb_matrix_mode;
layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(state)) {
    case _MOUSE_KEYS:
      _current_rgb_matrix_mode = RGB_MATRIX_CUSTOM_MOUSE_KEYS;
      autoshift_disable();
      break;
    case _GAMING:
      _current_rgb_matrix_mode = RGB_MATRIX_CUSTOM_RADIOACTIVE_BARBERSHOP;
      autoshift_disable();
      break;
    case _GAMING2:
      _current_rgb_matrix_mode = RGB_MATRIX_CUSTOM_RADIOACTIVE_BARBERSHOP2;
      autoshift_disable();
      break;
    case _BURRITO:
      _current_rgb_matrix_mode = RGB_MATRIX_CUSTOM_BURRITO;
      autoshift_enable();
      break;
    case _BURRITO2:
      _current_rgb_matrix_mode = RGB_MATRIX_CUSTOM_BURRITO2;
      autoshift_enable();
      break;
    case _NUMPAD:
      _current_rgb_matrix_mode = RGB_MATRIX_CUSTOM_NUMPAD;
      autoshift_disable();
      break;
    case _FUNCTION:
      _current_rgb_matrix_mode = RGB_MATRIX_CUSTOM_RETRO_APPLE;
      autoshift_disable();
      break;
    default:
      _current_rgb_matrix_mode = RGB_MATRIX_CUSTOM_ROYGCB;
      autoshift_disable();
      break;
  }
  rgb_matrix_mode(_current_rgb_matrix_mode);
  return state;
}

bool led_update_user(led_t led_state) {
  if (led_state.caps_lock) {
    rgb_matrix_mode(RGB_MATRIX_CUSTOM_ALL_RED);
  } else {
    rgb_matrix_mode(_current_rgb_matrix_mode);
  }
  return true;
}

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint32_t boot_key_timer;
  /* static uint32_t sfbs_key_timer; */

  switch (keycode) {
    case U_T_AUTO:
      if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
        TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
      }
      return false;
    case U_T_AGCR:
      if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
        TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
      }
      return false;
    case DBG_TOG:
      if (record->event.pressed) {
        TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
      }
      return false;
    case DBG_MTRX:
      if (record->event.pressed) {
        TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
      }
      return false;
    case DBG_KBD:
      if (record->event.pressed) {
        TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
      }
      return false;
    case DBG_MOU:
      if (record->event.pressed) {
        TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
      }
      return false;
    case MD_BOOT:
      if (record->event.pressed) {
          boot_key_timer = timer_read32();
      } else {
        if (timer_elapsed32(boot_key_timer) >= 500) {
          reset_keyboard();
        }
      }
      return false;
    case RGB_TOG:
    if (record->event.pressed) {
      switch (rgb_matrix_get_flags()) {
      case LED_FLAG_ALL: {
        rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR);
        rgb_matrix_set_color_all(0, 0, 0);
        }
        break;
      case (LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR): {
        rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
        rgb_matrix_set_color_all(0, 0, 0);
        }
        break;
      case LED_FLAG_UNDERGLOW: {
        rgb_matrix_set_flags(LED_FLAG_NONE);
        rgb_matrix_disable_noeeprom();
        }
        break;
      default: {
        rgb_matrix_set_flags(LED_FLAG_ALL);
        rgb_matrix_enable_noeeprom();
        }
        break;
      }
    }
    return false;
    case MY_UNDS:
      if (record->event.pressed) {
        SEND_STRING("_");
      }
      return false;
    /* case MY_SFBS: // https://redd.it/afm9ii */
    /*   if (record->event.pressed) { */
    /*     sfbs_key_timer = timer_read(); */
    /*     register_code(KC_LSFT); */
    /*   } else { */
    /*     unregister_code(KC_LSFT); */
    /*     if (timer_elapsed(sfbs_key_timer) < TAPPING_TERM) { */
    /*       SEND_STRING(SS_LALT(SS_TAP(X_BSPC))); */
    /*     } */
    /*   } */
    /*   return false; */
    default:
      /* if (record->event.pressed && keycode != MY_SFBS) { */
      /*   sfbs_key_timer = 0; */
      /* } */
      return true; //Process all other keycodes normally
  }
}
