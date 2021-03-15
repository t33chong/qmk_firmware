// From https://github.com/qmk/qmk_firmware/blob/master/quantum/rgblight_list.h
#define MY_GREEN 0x00, 0xFF, 0x00
#define MY_YELLOW 0xFF, 0xFF, 0x00
#define MY_YELLANGE 0xFF, 0xD9, 0x00
#define MY_ORANGE 0xFF, 0x80, 0x00
#define MY_RED 0xFF, 0x00, 0x00
#define MY_PURPLE 0x7A, 0x00, 0xFF
#define MY_BLUE 0x00, 0x00, 0xFF

RGB_MATRIX_EFFECT(RETRO_APPLE)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
  static bool RETRO_APPLE(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    int i;
    for (i=0; i<=14; i++) { // Row 1
      rgb_matrix_set_color(i, MY_GREEN);
    }
    for (i=15; i<=29; i++) { // Row 2
      rgb_matrix_set_color(i, MY_YELLANGE);
    }
    for (i=30; i<=43; i++) { // Row 3
      rgb_matrix_set_color(i, MY_RED);
    }
    for (i=44; i<=57; i++) { // Row 4
      rgb_matrix_set_color(i, MY_PURPLE);
    }
    for (i=58; i<=66; i++) { // Row 5
      rgb_matrix_set_color(i, MY_BLUE);
    }

    for (i=67; i<=81; i++) { // Underglow bottom
      rgb_matrix_set_color(i, MY_BLUE);
    }
    // Underglow left
    rgb_matrix_set_color(82, MY_PURPLE);
    rgb_matrix_set_color(83, MY_RED);
    rgb_matrix_set_color(84, MY_ORANGE);
    rgb_matrix_set_color(85, MY_YELLOW);
    for (i=86; i<=100; i++) { // Underglow top
      rgb_matrix_set_color(i, MY_GREEN);
    }
    // Underglow right
    rgb_matrix_set_color(101, MY_YELLOW);
    rgb_matrix_set_color(102, MY_ORANGE);
    rgb_matrix_set_color(103, MY_RED);
    rgb_matrix_set_color(104, MY_PURPLE);

    return led_max < DRIVER_LED_TOTAL;
  }
#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
