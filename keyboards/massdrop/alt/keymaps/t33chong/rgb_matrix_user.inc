#define _NUM_LEDS 105

// https://github.com/qmk/qmk_firmware/blob/master/quantum/rgblight_list.h
#define __GREEN RGB_GREEN
#define _YELLOW RGB_YELLOW
#define ___GOLD RGB_GOLD
#define _ORANGE RGB_ORANGE
#define ____RED RGB_RED
#define _PURPLE RGB_PURPLE
#define ___BLUE RGB_BLUE
#define ______X RGB_OFF

RGB_MATRIX_EFFECT(ALL_BLUE)
RGB_MATRIX_EFFECT(ALL_GREEN)
RGB_MATRIX_EFFECT(ALL_RED)
RGB_MATRIX_EFFECT(MOUSE_KEYS)
RGB_MATRIX_EFFECT(RETRO_APPLE)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
  int _drop_alt_led_layout[_NUM_LEDS] = {
               86,      87,      88,      89,      90,      91,      92,      93,      94,      95,      96,      97,      98,      99,     100,          \
      85,       0,       1,       2,       3,       4,       5,       6,       7,       8,       9,      10,      11,      12,      13,      14,     101, \
      84,      15,      16,      17,      18,      19,      20,      21,      22,      23,      24,      25,      26,      27,      28,      29,     102, \
               30,      31,      32,      33,      34,      35,      36,      37,      38,      39,      40,      41,               42,      43,          \
      83,      44,      45,      46,      47,      48,      49,      50,      51,      52,      53,      54,      55,               56,      57,     103, \
      82,      58,      59,      60,                                 61,                                 62,      63,      64,      65,      66,     104, \
               81,      80,      79,      78,      77,      76,      75,      74,      73,      72,      71,      70,      69,      68,      67           \
  };

  static bool ALL_BLUE(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    rgb_matrix_set_color_all(RGB_BLUE);
    return led_max < DRIVER_LED_TOTAL;
  }

  static bool ALL_GREEN(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    rgb_matrix_set_color_all(RGB_GREEN);
    return led_max < DRIVER_LED_TOTAL;
  }

  static bool ALL_RED(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    rgb_matrix_set_color_all(RGB_RED);
    return led_max < DRIVER_LED_TOTAL;
  }

  static bool _make_custom_effect(effect_params_t* params, int layout[]) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    int i;
    for (i=0; i<_NUM_LEDS; i++) {
      rgb_matrix_set_color(_drop_alt_led_layout[i], layout[i*3], layout[i*3+1], layout[i*3+2]);
    }
    return led_max < DRIVER_LED_TOTAL;
  }

  static bool RETRO_APPLE(effect_params_t* params) {
    int layout[_NUM_LEDS * 3] = {
          __GREEN, __GREEN, __GREEN, __GREEN, __GREEN, __GREEN, __GREEN, __GREEN, __GREEN, __GREEN, __GREEN, __GREEN, __GREEN, __GREEN, __GREEN,          \
 _YELLOW, __GREEN, __GREEN, __GREEN, __GREEN, __GREEN, __GREEN, __GREEN, __GREEN, __GREEN, __GREEN, __GREEN, __GREEN, __GREEN, __GREEN, __GREEN, _YELLOW, \
 _ORANGE, ___GOLD, ___GOLD, ___GOLD, ___GOLD, ___GOLD, ___GOLD, ___GOLD, ___GOLD, ___GOLD, ___GOLD, ___GOLD, ___GOLD, ___GOLD, ___GOLD, ___GOLD, _ORANGE, \
          ____RED, ____RED, ____RED, ____RED, ____RED, ____RED, ____RED, ____RED, ____RED, ____RED, ____RED, ____RED,          ____RED, ____RED,          \
 ____RED, _PURPLE, _PURPLE, _PURPLE, _PURPLE, _PURPLE, _PURPLE, _PURPLE, _PURPLE, _PURPLE, _PURPLE, _PURPLE, _PURPLE,          _PURPLE, _PURPLE, ____RED, \
 _PURPLE, ___BLUE, ___BLUE, ___BLUE,                            ___BLUE,                            ___BLUE, ___BLUE, ___BLUE, ___BLUE, ___BLUE, _PURPLE, \
          ___BLUE, ___BLUE, ___BLUE, ___BLUE, ___BLUE, ___BLUE, ___BLUE, ___BLUE, ___BLUE, ___BLUE, ___BLUE, ___BLUE, ___BLUE, ___BLUE, ___BLUE           \
    };
    return _make_custom_effect(params, layout);
  }

  static bool MOUSE_KEYS(effect_params_t* params) {
    int layout[_NUM_LEDS * 3] = {
          ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X,          \
 ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, \
 ______X, ______X, __GREEN, ___BLUE, __GREEN, _YELLOW, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, \
          ______X, ___BLUE, ___BLUE, ___BLUE, _YELLOW, ______X, ______X, ___BLUE, ___BLUE, ___BLUE, ___BLUE, ___BLUE,          ______X, ______X,          \
 ______X, ______X, __GREEN, ______X, __GREEN, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X,          ______X, ______X, ______X, \
 ______X, ______X, ______X, ______X,                            ______X,                            ______X, ______X, ______X, ______X, ______X, ______X, \
          ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X           \
    };
    return _make_custom_effect(params, layout);
  }

  /*
          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          \
 _______, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME, _______, \
 _______, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_END,  _______, \
          KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP,          \
 _______, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN, _______, \
 _______, KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             KC_UNDS, MO(X),   KC_LEFT, KC_DOWN, KC_RGHT  _______, \
          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______           \
  */

  /*
  static bool CUSTOM_EFFECT(effect_params_t* params) {
    int layout[_NUM_LEDS * 3] = {
          ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X,          \
 ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, \
 ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, \
          ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X,          ______X, ______X,          \
 ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X,          ______X, ______X, ______X, \
 ______X, ______X, ______X, ______X,                            ______X,                            ______X, ______X, ______X, ______X, ______X, ______X, \
          ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X, ______X           \
    };
    return _make_custom_effect(params, layout);
  }
  */

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
