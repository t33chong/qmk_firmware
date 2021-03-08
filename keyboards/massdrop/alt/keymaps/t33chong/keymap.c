#include QMK_KEYBOARD_H

enum alt_keycodes {
    U_T_AUTO = SAFE_RANGE, //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,              //USB Toggle Automatic GCR control
    DBG_TOG,               //DEBUG Toggle On / Off
    DBG_MTRX,              //DEBUG Toggle Matrix Prints
    DBG_KBD,               //DEBUG Toggle Keyboard Prints
    DBG_MOU,               //DEBUG Toggle Mouse Prints
    MD_BOOT,               //Restart into bootloader after hold timeout
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_65_ansi_blocker(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_END,  \
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN, \
        KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             KC_UNDS, MO(15),  KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    [1] = LAYOUT_65_ansi_blocker(
     /* KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME, \ */
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
     /* KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_END,  \ */
        _______, KC_WH_U, KC_MS_U, KC_WH_D, KC_HOME, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
     /* KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP, \ */
        _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_END,  _______, _______, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, KC_BTN5,          _______, _______, \
     /* KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN, \ */
        _______, KC_WH_L, _______, KC_WH_R, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
     /* KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             KC_UNDS, MO(15),  KC_LEFT, KC_DOWN, KC_RGHT  \ */
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
    ),
    [15] = LAYOUT_65_ansi_blocker( // ALT swaps ALT with CMD, CMD resets it
     /* KC_GRV,      KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,        KC_7,      KC_8,         KC_9,        KC_0,         KC_MINS,      KC_EQL,       KC_BSPC,      KC_HOME, \ */
        HYPR(KC_GRV),KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,       KC_F7,     KC_F8,        KC_F9,       KC_F10,       KC_F11,       KC_F12,       HYPR(KC_BSPC),MD_BOOT, \
     /* KC_TAB,      KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      KC_Y,        KC_U,      KC_I,         KC_O,        KC_P,         KC_LBRC,      KC_RBRC,      KC_BSLS,      KC_END,  \ */
        HYPR(KC_TAB),HYPR(KC_Q),HYPR(KC_W),HYPR(KC_E),HYPR(KC_R),HYPR(KC_T),HYPR(KC_Y),  HYPR(KC_U),HYPR(KC_I),   HYPR(KC_O),  HYPR(KC_P),   HYPR(KC_LBRC),HYPR(KC_RBRC),HYPR(KC_BSLS),_______, \
     /* KC_ESC,      KC_A,      KC_S,      KC_D,      KC_F,      KC_G,      KC_H,        KC_J,      KC_K,         KC_L,        KC_SCLN,      KC_QUOT,                    KC_ENT,       KC_PGUP, \ */
        TG(1),       HYPR(KC_A),HYPR(KC_S),HYPR(KC_D),HYPR(KC_F),HYPR(KC_G),HYPR(KC_H),  HYPR(KC_J),HYPR(KC_K),   HYPR(KC_L),  HYPR(KC_SCLN),HYPR(KC_QUOT),              HYPR(KC_ENT), RGB_RMOD,\
     /* KC_LSFT,     KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_N,        KC_M,      KC_COMM,      KC_DOT,      KC_SLSH,      KC_RSFT,                    KC_UP,        KC_PGDN, \ */
        _______,     HYPR(KC_Z),HYPR(KC_X),HYPR(KC_C),HYPR(KC_V),HYPR(KC_B),HYPR(KC_N),  HYPR(KC_M),HYPR(KC_COMM),HYPR(KC_DOT),HYPR(KC_SLSH),_______,                    KC_PGUP,      RGB_MOD, \
     /* KC_LCTL,     KC_LALT,   KC_LGUI,                                    KC_SPC,                                            KC_UNDS,      MO(15),       KC_LEFT,      KC_DOWN,      KC_RGHT  \ */
        _______,     LAG_SWP,   LAG_NRM,                                    HYPR(KC_SPC),                                      HYPR(KC_UNDS),_______,      KC_HOME,      KC_PGDN,      KC_END   \
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

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

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
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
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
        default:
            return true; //Process all other keycodes normally
    }
}
