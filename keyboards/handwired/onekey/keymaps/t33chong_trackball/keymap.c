#include QMK_KEYBOARD_H

#define LAYOUT_5way(KA, KB, KC, KD, KP) { {KA}, {KB}, {KC}, {KD}, {KP} }
/* #define LAYOUT_5way(KA, KB, KC, KD, KP) {{ KA, KB, KC, KD, KP }} */
/* #define LAYOUT_5way(KA, KB, KC, KD, KP) { KA, KB, KC, KD, KP } */

/* #define LAYOUT_5way( \ */
/*     KA, KB, KC, KD, KP \ */
/*     ) { \ */
/*   { KA }, \ */
/*   { KB }, \ */
/*   { KC }, \ */
/*   { KD }, \ */
/*   { KP } \ */
/* } */

/* #define LAYOUT_5way(K10, K20, K30, K40, K50) { {K10}, {K20}, {K30}, {K40}, {K50} } */
/* #define LAYOUT_5way(K10, K20, K30, K40, K50) { {K10, K20, K30, K40, K50} } */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_5way(KC_RGHT, KC_UP, KC_LEFT, KC_DOWN, KC_ENT),
};

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
  mouse_report.h = mouse_report.x;
  mouse_report.v = -mouse_report.y;
  mouse_report.x = mouse_report.y = 0;
  return mouse_report;
}

bool is_blue = true;
uint16_t trackball_click_timer;

uint8_t pointing_device_handle_buttons(uint8_t buttons, bool pressed, pointing_device_buttons_t button) {
  /* if (pressed) { */
  /*   if (is_blue) { */
  /*     pimoroni_trackball_set_rgbw(255, 0, 0, 0); */
  /*   } else { */
  /*     pimoroni_trackball_set_rgbw(0, 0, 255, 0); */
  /*   } */
  /*   is_blue = !is_blue; */
  /* } */
  /* return buttons; */
  if (pressed) {
    trackball_click_timer = timer_read();
  } else {
    if (timer_elapsed(trackball_click_timer) < TAPPING_TERM) {
      if (is_blue) {
        pimoroni_trackball_set_rgbw(255, 0, 0, 0);
      } else {
        pimoroni_trackball_set_rgbw(0, 0, 255, 0);
      }
      is_blue = !is_blue;
    }
  }
  return buttons;
}

void keyboard_post_init_user(void) {
  pimoroni_trackball_set_rgbw(0, 0, 255, 0);
}
