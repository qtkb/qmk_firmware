#include QMK_KEYBOARD_H

extern uint8_t is_master;

enum layers {
  _QWERTY = 0,
  _SYMBOL,
  _FUN,
  _ADJUST,
};

enum custom_keycodes {
  RGBRST = SAFE_RANGE,
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

#define FUN     MO(_FUN)
#define ADJUST  MO(_ADJUST)
#define SYM_ENT LT(_SYMBOL, KC_ENT)
#define SNIP    S(G(KC_S))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_split_3x6_3( \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,     KC_O,   KC_P,    KC_BSPC,\
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,     KC_L,   KC_SCLN, KC_QUOT,\
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,\
                                      KC_LALT, KC_LCTL, KC_SPC,  SYM_ENT, FUN,     ADJUST \
),
[_SYMBOL] = LAYOUT_split_3x6_3( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV, \
  _______, KC_UNDS, KC_MINS, KC_PLUS, KC_EQL,  KC_PIPE,                   KC_BSLS, KC_LCBR, KC_LBRC, KC_RBRC, KC_RCBR, _______, \
                                      _______, _______, _______, _______, _______, _______\
),
[_FUN] = LAYOUT_split_3x6_3( \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX,                   XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, KC_DEL, \
  _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX,                   XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_MPLY, XXXXXXX, \
  _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,                   XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______, \
                                      _______, _______, _______, _______, _______, _______ \
),
[_ADJUST] = LAYOUT_split_3x6_3( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   RGBRST,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, SNIP,    XXXXXXX, XXXXXXX, XXXXXXX,                   RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, XXXXXXX,\
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, XXXXXXX,\
                                      _______, _______, _______, _______, _______, _______ \
)
};

void matrix_init_user(void) {
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    //matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case RGBRST:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          eeconfig_update_rgblight_default();
          rgblight_enable();
        #endif
        #ifdef RGB_MATRIX_ENABLE
          eeconfig_update_rgb_matrix_default();
          rgb_matrix_enable();
        #endif
      }
      break;
  }
  return true;
}
