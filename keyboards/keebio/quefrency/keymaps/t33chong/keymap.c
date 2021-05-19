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
  _UNDSCR,              // Send underscore (used instead of KC_UNDS to avoid shift applying to next keypress)
  _MODGUI,              // Send command and set boolean flag
};

#define _CTLESC CTL_T(KC_ESC)          // Hold for control, tap for escape
#define _NUMMIN LT(_NUMERALS, KC_MINS) // Hold for numerals layer, tap for -
#define _MEHSPC LT(_MEH, KC_SPC)       // Hold for meh layer, tap for space
#define _HYPEQL LT(_HYPER, KC_EQL)     // Hold for hyper layer, tap for =
#define _PUSHTT HYPR(KC_BSLS)          // Hold for push to talk with Shush
#define _TTARRO TT(_ARROWS)            // Tap-toggle arrows layer
#define _MOFUNC MO(_FUNCTION)          // Activate function layer
#define _TGMOUS TG(_MOUSEKEYS)         // Toggle mousekeys layer
#define _HYP_F1 HYPR(KC_F1)
#define _HYP_F2 HYPR(KC_F2)
#define _HYP_F3 HYPR(KC_F3)
#define _HYP_F4 HYPR(KC_F4)
#define _HYP_F5 HYPR(KC_F5)
#define _HYP_F6 HYPR(KC_F6)
#define _HYP_F7 HYPR(KC_F7)
#define _HYP_F8 HYPR(KC_F8)
#define _HYP_F9 HYPR(KC_F9)
#define _HYPF10 HYPR(KC_F10)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEFAULT] = LAYOUT_t33chong(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BRMD, KC_BRMU, KC_VOLD, KC_VOLU, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          _TGMOUS, \
    _CTLESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,                   KC_ENT,  \
    KC_BSPC, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          _HYPEQL,          _MOFUNC, \
    _TTARRO, KC_LALT, _MODGUI,          KC_LSFT,          _NUMMIN,          _MEHSPC,          _UNDSCR, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
  ),
  [_NUMERALS] = LAYOUT_t33chong(
    _______, G(KC_1), G(KC_2), G(KC_3), G(KC_4), G(KC_5), G(KC_6), G(KC_7), G(KC_8), G(KC_9), G(KC_0), _______, _______, _______, _______, \
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, _______,          _______, \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,                   _______, \
    _______, _HYP_F1, _HYP_F2, _HYP_F3, _HYP_F4, _HYP_F5, _HYP_F6, _HYP_F7, _HYP_F8, _HYP_F9, _HYPF10,          _______,          _______, \
    _______, _______, _______,          _______,          _______,          _______,          _______, _______, _______, _______, _______  \
  ),
  [_ARROWS] = LAYOUT_t33chong(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,                   _______, \
    KC_LSFT, _PUSHTT, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______, \
    _______, KC_LALT, KC_LGUI,          _______,          _______,          _______,          _______, _______, _______, _______, _______  \
  ),
  [_MEH] = LAYOUT_t33chong(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_BSLS, \
    KC_ESC,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_EQL,           _______, \
    _______, _______, _______,          _______,          KC_MINS,          _______,          KC_MINS, _______, _______, _______, _______  \
  ),
  [_HYPER] = LAYOUT_t33chong(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_BSLS, \
    KC_ESC,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______, \
    _______, _______, _______,          _______,          KC_MINS,          KC_SPC,           KC_MINS, _______, _______, _______, _______  \
  ),
  [_MOUSEKEYS] = LAYOUT_t33chong(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, KC_MS_U, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
    _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, _______,                   _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______, \
    _______, _______, _______,          KC_BTN2,          KC_BTN3,          KC_BTN1,          _______, _______, _______, _______, _______  \
  ),
  [_FUNCTION] = LAYOUT_t33chong(
    KC_CLR,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  BL_TOGG, RESET,   \
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

const rgblight_segment_t PROGMEM _default_rgb[] = RGBLIGHT_LAYER_SEGMENTS({0, 16, HSV_CYAN});
const rgblight_segment_t PROGMEM _numerals_rgb[] = RGBLIGHT_LAYER_SEGMENTS({0, 16, HSV_CYAN});
const rgblight_segment_t PROGMEM _arrows_rgb[] = RGBLIGHT_LAYER_SEGMENTS({0, 16, HSV_GREEN});
const rgblight_segment_t PROGMEM _meh_rgb[] = RGBLIGHT_LAYER_SEGMENTS({0, 16, HSV_BLUE});
const rgblight_segment_t PROGMEM _hyper_rgb[] = RGBLIGHT_LAYER_SEGMENTS({0, 16, HSV_RED});
const rgblight_segment_t PROGMEM _mousekeys_rgb[] = RGBLIGHT_LAYER_SEGMENTS({0, 16, HSV_YELLOW});
const rgblight_segment_t PROGMEM _function_rgb[] = RGBLIGHT_LAYER_SEGMENTS({0, 16, HSV_MAGENTA});

const rgblight_segment_t* const PROGMEM _rgblight_layers[] = RGBLIGHT_LAYERS_LIST(
  _default_rgb,
  _numerals_rgb,
  _arrows_rgb,
  _meh_rgb,
  _hyper_rgb,
  _mousekeys_rgb,
  _function_rgb
);

void keyboard_post_init_user(void) {
  backlight_disable();
  rgblight_enable_noeeprom();
  rgblight_layers = _rgblight_layers;
}

// TODO: Turn caps lock LED off
/* extern backlight_config_t backlight_config; */
/* bool led_update_user(led_t led_state) { */
/*   if (!backlight_config.level || !backlight_config.enable) { */
/*     PORTB |= (1 << 2); */
/*   } else { */
/*     PORTB &= ~(1 << 2); */
/*   } */
/*   return true; */
/* } */

// If true, don't count a tap and a hold as repetition of the tap action
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case _CTLESC:
    case _NUMMIN:
    case _MEHSPC:
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
  rgblight_set_layer_state(_MEH, layer_state_cmp(state, _MEH));
  rgblight_set_layer_state(_HYPER, layer_state_cmp(state, _HYPER));
  rgblight_set_layer_state(_MOUSEKEYS, layer_state_cmp(state, _MOUSEKEYS));
  rgblight_set_layer_state(_FUNCTION, layer_state_cmp(state, _FUNCTION));

  return state;
}

#define MODS_SHIFT (get_mods() & MOD_BIT(KC_LSFT) || get_mods() & MOD_BIT(KC_RSFT))
#define MODS_CTRL (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTL))
#define MODS_ALT (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))
#define MODS_GUI (get_mods() & MOD_BIT(KC_LGUI) || get_mods() & MOD_BIT(KC_RGUI))
#define MODS_MEH (get_mods() & MOD_BIT(KC_LCTL) && get_mods() & MOD_BIT(KC_LSFT) && get_mods() & MOD_BIT(KC_LALT))
#define MODS_HYPER (get_mods() & MOD_BIT(KC_LCTL) && get_mods() & MOD_BIT(KC_LSFT) && get_mods() & MOD_BIT(KC_LALT) && get_mods() & MOD_BIT(KC_LGUI))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint32_t _reset_hold_timer;
  static bool _is_gui_held;
  switch (keycode) {
    case _MODGUI:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        _is_gui_held = true;
      } else {
        unregister_code(KC_LGUI);
        _is_gui_held = false;
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
    case _TGMOUS:
      if (_is_gui_held) { // Restore backslash key to original function when gui is held
        if (record->event.pressed) {
          register_code(KC_BSLS);
        } else {
          unregister_code(KC_BSLS);
        }
        return false;
      }
      return true;
    case KC_BSPC:
      // FIXME: Timing can cause shift to remain held down
      if (_is_gui_held) { // Restore left shift key to original function when gui is held
        if (record->event.pressed) {
          register_code(KC_LSFT);
        } else {
          unregister_code(KC_LSFT);
        }
        return false;
      } else if (_current_layer == _MEH) { // Send alt+backspace when meh is held
        if (record->event.pressed) {
          register_code16(A(KC_BSPC));
        } else {
          unregister_code16(A(KC_BSPC));
        }
        return false;
      } else if (_current_layer == _HYPER) { // Send forward delete when hyper is held
        if (record->event.pressed) {
          register_code(KC_DEL);
        } else {
          unregister_code(KC_DEL);
        }
        return false;
      }
      return true;
    default:
      if (_current_layer == _MEH) {
        if (keycode == _MEHSPC) {
          return true;
        }
        if (record->event.pressed) {
          register_code16(MEH(keycode));
        } else {
          unregister_code16(MEH(keycode));
        }
        return false;
      } else if (_current_layer == _HYPER) {
        if (keycode == _HYPEQL) {
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
