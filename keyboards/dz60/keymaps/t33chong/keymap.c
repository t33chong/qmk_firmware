#include QMK_KEYBOARD_H
#include "print.h"

enum _layers {
  _DEFAULT = 0,
  /* _META, */
  _NUMERALS,
  _ARROWS,
  _MEH,
  /* _HYPER, */
  _MOUSEKEYS,
  _FUNCTION,
};

enum _keycodes {
  __RESET = SAFE_RANGE, // Restart into bootloader after hold timeout
  _UNDSCR,              // Send _
};

#define _CTLESC CTL_T(KC_ESC)          // Hold for control, tap for escape
#define _MEHMIN LT(_MEH, KC_MINS)      // Hold for meh layer, tap for -
#define _MEHSPC LT(_MEH, KC_SPC)       // Hold for meh layer, tap for space
/* #define _HYPEQL LT(_HYPER, KC_EQL)     // Hold for hyper layer, tap for = */
#define _MO_FUN MO(_FUNCTION)          // Hold for function layer
#define _MO_NUM MO(_NUMERALS)          // Hold for numerals layer
/* #define _MO_MET MO(_META)              // Hold for meta layer */
/* #define _MO_MEH MO(_MEH)               // Hold for meh layer */
/* #define _MO_HYP MO(_HYPER)             // Hold for hyper layer */
#define _TO_ARR TO(_ARROWS)            // Activate arrows layer
#define _TO_DEF TO(_DEFAULT)           // Activate default layer
#define _TO_MSK TO(_MOUSEKEYS)         // Activate mousekeys layer
#define _PUSHTT HYPR(KC_BSLS)          // Hold for push to talk with Shush
#define _ALTBSP A(KC_BSPC)             // Send alt+backspace
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
#define _HYPF10 HYPR(KC_F10)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEFAULT] = LAYOUT_t33chong(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BRMD, KC_BRMU, KC_VOLD, KC_VOLU, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_MINS, \
    _CTLESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,                   KC_ENT,  \
    /* KC_BSPC, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          _HYPEQL,          _MO_FUN, \ */
    KC_BSPC, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_EQL,           _MO_FUN, \
    _PUSHTT, KC_LALT, KC_LGUI,          KC_LSFT,          _MO_NUM,          _MEHSPC,          _UNDSCR, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
  ),
  /* [_META] = LAYOUT_t33chong( */
  /*   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \ */
  /*   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \ */
  /*   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, \ */
  /*   _ALTBSP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______, \ */
  /*   _______, _PUSHTT, _______,          _TO_ARR,          _TO_MSK,          _______,          _______, _______, _______, _______, _______  \ */
  /* ), */
  [_NUMERALS] = LAYOUT_t33chong(
    _GUIGRV, G(KC_1), G(KC_2), G(KC_3), G(KC_4), G(KC_5), G(KC_6), G(KC_7), G(KC_8), G(KC_9), G(KC_0), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, KC_COLN,          KC_MINS, \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,                   KC_PLUS, \
    KC_BSPC, _HYP_F1, _HYP_F2, _HYP_F3, _HYP_F4, _HYP_F5, _HYP_F6, _HYP_F7, _HYP_F8, _HYP_F9, _HYPF10,          KC_EQL,           XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,          XXXXXXX,          KC_SPC,           _UNDSCR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
  ),
  [_ARROWS] = LAYOUT_t33chong(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, \
    _TO_DEF, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,                   XXXXXXX, \
    KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,          XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX,          KC_LALT,          KC_LGUI,          XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
  ),
  // TODO: Consolidate meh and hyper into quantum layer; meh + gui = hyper
  [_MEH] = LAYOUT_t33chong(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,  \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_BSLS, \
    _TO_ARR, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, \
    _ALTBSP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_EQL,           _______, \
    _______, _______, _______,          _______,          _TO_MSK,          _______,          _______, _______, _______, _______, _______  \
  ),
  /* [_HYPER] = LAYOUT_t33chong( */
  /*   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,  \ */
  /*   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_BSLS, \ */
  /*   KC_ESC,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, \ */
  /*   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______, \ */
  /*   _______, _______, _______,          _______,          _______,          KC_SPC,           _______, _______, _______, _______, _______  \ */
  /* ), */
  [_MOUSEKEYS] = LAYOUT_t33chong(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, \
    _TO_DEF, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX, XXXXXXX,                   KC_BTN4, \
    KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          KC_BTN5,          XXXXXXX, \
    KC_LCTL, KC_LALT, KC_LGUI,          KC_BTN2,          KC_BTN3,          KC_BTN1,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
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

#define _RGB_ALL(color) RGBLIGHT_LAYER_SEGMENTS({0, 16, color})
const rgblight_segment_t PROGMEM _default_rgb[] = _RGB_ALL(HSV_CYAN);
/* const rgblight_segment_t PROGMEM _meta_rgb[] = _RGB_ALL(HSV_WHITE); */
const rgblight_segment_t PROGMEM _numerals_rgb[] = _RGB_ALL(HSV_CYAN);
const rgblight_segment_t PROGMEM _arrows_rgb[] = _RGB_ALL(HSV_GREEN);
const rgblight_segment_t PROGMEM _meh_rgb[] = _RGB_ALL(HSV_BLUE);
/* const rgblight_segment_t PROGMEM _hyper_rgb[] = _RGB_ALL(HSV_RED); */
const rgblight_segment_t PROGMEM _mousekeys_rgb[] = _RGB_ALL(HSV_YELLOW);
const rgblight_segment_t PROGMEM _function_rgb[] = _RGB_ALL(HSV_MAGENTA);

const rgblight_segment_t* const PROGMEM _rgblight_layers[] = RGBLIGHT_LAYERS_LIST(
  _default_rgb,
  /* _meta_rgb, */
  _numerals_rgb,
  _arrows_rgb,
  _meh_rgb,
  /* _hyper_rgb, */
  _mousekeys_rgb,
  _function_rgb
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
  /* rgblight_set_layer_state(_META, layer_state_cmp(state, _META)); */
  rgblight_set_layer_state(_NUMERALS, layer_state_cmp(state, _NUMERALS));
  rgblight_set_layer_state(_ARROWS, layer_state_cmp(state, _ARROWS));
  rgblight_set_layer_state(_MEH, layer_state_cmp(state, _MEH));
  /* rgblight_set_layer_state(_HYPER, layer_state_cmp(state, _HYPER)); */
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

bool _was__MEHMIN_used_as_KC_BSLS;
bool _was_KC_BSPC_used_as_KC_LSFT;
bool _was_KC_BSPC_used_as__ALTBSP;
bool _was_KC_BSPC_used_as_KC_DEL;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint32_t _reset_hold_timer;
  static bool _is_alt_held;
  static bool _is_gui_held;
  /* static bool _is_shift_held; */
  /* static uint16_t _held_keycode; */
  dprintf("keycode: %s", keycode);
  switch (keycode) {
    case _UNDSCR:
      if (record->event.pressed) {
        register_code16(S(KC_MINS));
      } else {
        unregister_code16(S(KC_MINS));
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
    case _MEHMIN:
      if (_is_gui_held && record->event.pressed) { // Restore backslash key to original function when gui is held
        register_code(KC_BSLS);
        _was__MEHMIN_used_as_KC_BSLS = true;
        return false;
      }
      if (_was__MEHMIN_used_as_KC_BSLS && !record->event.pressed) {
        unregister_code(KC_BSLS);
        _was__MEHMIN_used_as_KC_BSLS = false;
        return false;
      }
      return true;
    case _TO_ARR:
    case _TO_MSK:
    case _MEHSPC:
    /* case _HYPEQL: */
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
    /* case KC_LSFT: */
    /*   if (record->event.pressed) { */
    /*     _is_shift_held = true; */
    /*   } else { */
    /*     _is_shift_held = false; */
    /*   } */
    /*   return true; */
    case KC_BSPC:
      if (record->event.pressed) {
        if (_is_alt_held || _is_gui_held) { // Restore left shift key to original function when alt or gui is held
          register_code(KC_LSFT);
          _was_KC_BSPC_used_as_KC_LSFT = true;
          return false;
        }
        /* if (_current_layer == _MEH) { // Send alt+backspace when meh is held */
        /*   register_code16(_ALTBSP); */
        /*   _was_KC_BSPC_used_as__ALTBSP = true; */
        /*   return false; */
        /* } */
        /* if (_current_layer == _HYPER) { // Send forward delete when hyper is held */
        /*   register_code(KC_DEL); */
        /*   _was_KC_BSPC_used_as_KC_DEL = true; */
        /*   return false; */
        /* } */
      } else {
        if (_was_KC_BSPC_used_as_KC_LSFT) {
          unregister_code(KC_LSFT);
          _was_KC_BSPC_used_as_KC_LSFT = false;
        }
        if (_was_KC_BSPC_used_as__ALTBSP) {
          unregister_code16(_ALTBSP);
          _was_KC_BSPC_used_as__ALTBSP = false;
        }
        if (_was_KC_BSPC_used_as_KC_DEL) {
          unregister_code(KC_DEL);
          _was_KC_BSPC_used_as_KC_DEL = false;
        }
      }
      return true;
    default:
      /* if (record->event.pressed) { */
      /*   if (_current_layer == _MEH) { */
      /*     if (_is_shift_held) { */
      /*       _held_keycode = HYPR(keycode); */
      /*     } else { */
      /*       _held_keycode = MEH(keycode); */
      /*     } */
      /*     register_code16(_held_keycode); */
      /*   } */
      /*   return false; */
      /* } else { */
      /*   if (_held_keycode > -1) { */
      /*     unregister_code16(_held_keycode); */
      /*     _held_keycode = -1; */
      /*     return false; */
      /*   } */ 
      /* } */

      /* if (_current_layer == _MEH) { */
      /*   /1* if (keycode == _MEHSPC) { *1/ */
      /*   /1* if (keycode == _MEHMIN) { *1/ */

      /*   /1* if (keycode == _MEHSPC || keycode == _MO_MEH) { *1/ */
      /*   /1*   return true; *1/ */
      /*   /1* } *1/ */
      /*   if (record->event.pressed) { */
      /*     register_code16(MEH(keycode)); */
      /*   } else { */
      /*     unregister_code16(MEH(keycode)); */
      /*   } */
      /*   return false; */
      /* } else if (_current_layer == _HYPER) { */
      /*   /1* if (keycode == _HYPEQL || keycode == _MO_HYP) { *1/ */

      /*   /1* if (keycode == _HYPEQL) { *1/ */
      /*   /1*   return true; *1/ */
      /*   /1* } *1/ */
      /*   if (record->event.pressed) { */
      /*     register_code16(HYPR(keycode)); */
      /*   } else { */
      /*     unregister_code16(HYPR(keycode)); */
      /*   } */
      /*   return false; */
      /* } */
      return true; // Process all other keycodes normally
  }
}
