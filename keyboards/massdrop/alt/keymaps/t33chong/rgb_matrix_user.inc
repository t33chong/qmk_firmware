#define _NUM_LEDS 105

// https://github.com/qmk/qmk_firmware/blob/master/quantum/rgblight_list.h
#define __GREEN RGB_GREEN
#define _YELLOW RGB_YELLOW
#define ___GOLD RGB_GOLD
#define _ORANGE RGB_ORANGE
#define ____RED RGB_RED
#define _PURPLE RGB_PURPLE
#define ___BLUE RGB_BLUE
#define __WHITE RGB_WHITE
#define ______X RGB_OFF

RGB_MATRIX_EFFECT(ALL_BLUE)
RGB_MATRIX_EFFECT(ALL_GREEN)
RGB_MATRIX_EFFECT(ALL_RED)
RGB_MATRIX_EFFECT(IRISH_FLAG)
RGB_MATRIX_EFFECT(MOUSE_KEYS)
RGB_MATRIX_EFFECT(RETRO_APPLE)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
  int _drop_alt_led_layout[_NUM_LEDS] = {
              100,      99,      98,      97,      96,      95,      94,      93,      92,      91,      90,      89,      88,      87,      86,          \
     101,       0,       1,       2,       3,       4,       5,       6,       7,       8,       9,      10,      11,      12,      13,      14,     85,  \
     102,      15,      16,      17,      18,      19,      20,      21,      22,      23,      24,      25,      26,      27,      28,      29,     84,  \
               30,      31,      32,      33,      34,      35,      36,      37,      38,      39,      40,      41,               42,      43,          \
     103,      44,      45,      46,      47,      48,      49,      50,      51,      52,      53,      54,      55,               56,      57,     83,  \
     104,      58,      59,      60,                                 61,                                 62,      63,      64,      65,      66,     82,  \
               67,      68,      69,      70,      71,      72,      73,      74,      75,      76,      77,      78,      79,      80,      81           \
  };

  static bool _set_all_leds(effect_params_t* params, int r, int g, int b) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    rgb_matrix_set_color_all(r, g, b);
    return led_max < DRIVER_LED_TOTAL;
  }

  static bool ALL_BLUE(effect_params_t* params) {
    return _set_all_leds(params, RGB_BLUE);
  }

  static bool ALL_GREEN(effect_params_t* params) {
    return _set_all_leds(params, RGB_GREEN);
  }

  static bool ALL_RED(effect_params_t* params) {
    return _set_all_leds(params, RGB_RED);
  }

  // These work, just commented out to avoid compilation error

  /* static void _set_led_range(effect_params_t* params, int from, int to, int r, int g, int b) { */
  /*   int i; */
  /*   for (i=from; i<=to; i++) { */
  /*     rgb_matrix_set_color(i, r, g, b); */
  /*   } */
  /* } */

  /* static void _set_keys_color(effect_params_t* params, int r, int g, int b) { */
  /*   _set_led_range(params, 0, 66, r, g, b); */
  /* } */

  /* static void _set_underglow_color(effect_params_t* params, int r, int g, int b) { */
  /*   _set_led_range(params, 67, 104, r, g, b); */
  /* } */

  /* static bool KEYS_UNDERGLOW_EXAMPLE(effect_params_t* params) { */
  /*   RGB_MATRIX_USE_LIMITS(led_min, led_max); */
  /*   _set_keys_color(params, RGB_GREEN); */
  /*   _set_underglow_color(params, RGB_ORANGE); */
  /*   return led_max < DRIVER_LED_TOTAL; */
  /* } */

  // End comment

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

  static bool IRISH_FLAG(effect_params_t* params) {
    int layout[_NUM_LEDS * 3] = {
          __GREEN, __GREEN, __GREEN, __GREEN, __GREEN, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, _ORANGE, _ORANGE, _ORANGE, _ORANGE, _ORANGE,          \
 __GREEN, __GREEN, __GREEN, __GREEN, __GREEN, __GREEN, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, _ORANGE, _ORANGE, _ORANGE, _ORANGE, _ORANGE, _ORANGE, \
 __GREEN, __GREEN, __GREEN, __GREEN, __GREEN, __GREEN, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, _ORANGE, _ORANGE, _ORANGE, _ORANGE, _ORANGE, _ORANGE, \
          __GREEN, __GREEN, __GREEN, __GREEN, __GREEN, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, _ORANGE, _ORANGE,          _ORANGE, _ORANGE,          \
 __GREEN, __GREEN, __GREEN, __GREEN, __GREEN, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, _ORANGE, _ORANGE, _ORANGE,          _ORANGE, _ORANGE, _ORANGE, \
 __GREEN, __GREEN, __GREEN, __GREEN,                            __WHITE,                            _ORANGE, _ORANGE, _ORANGE, _ORANGE, _ORANGE, _ORANGE, \
          __GREEN, __GREEN, __GREEN, __GREEN, __GREEN, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, _ORANGE, _ORANGE, _ORANGE, _ORANGE, _ORANGE           \
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
