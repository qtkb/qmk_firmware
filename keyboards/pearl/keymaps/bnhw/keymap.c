#include QMK_KEYBOARD_H

enum
{
    _QWERTY = 0,
    _SYMBOLS,
    _FUNCTIONS,
    _CONFIG
};

#define SYM_ENT LT(_SYMBOLS, KC_ENT)
#define FUNCS MO(_FUNCTIONS)
#define CONFIG MO(_CONFIG)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_splits(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, KC_DEL,
    KC_LCTL,          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                      KC_LGUI, KC_LALT, KC_ESC,           KC_SPC,  SYM_ENT,          FUNCS,   CONFIG
      ),
  [_SYMBOLS] = LAYOUT_splits(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, _______,
    _______,          KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
    _______,          KC_UNDS, KC_MINS, KC_PLUS, KC_EQL,  KC_PIPE, KC_BSLS, KC_LCBR, KC_LBRC, KC_RBRC, KC_RCBR, _______,
                      _______, _______, _______,          _______, _______,          _______, _______
  ),
  [_FUNCTIONS] = LAYOUT_splits(
    XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX,
    _______,          KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,
    _______,          KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                      _______, _______, _______,          _______, _______,          _______, _______
  ),
  [_CONFIG] = LAYOUT_splits(
    RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______,          RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______,          RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                      _______, _______, _______,          _______, _______,          _______, _______
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  // if we are on layer 1
  if (state & (1<<1)){
    // light num lock led
    PORTD |= (1 << PD0);
  }
  else{
    PORTD &= ~(1 << PD0);
  }
  // if we are on layer 2
  if (state & (1<<2)){
    // light caps lock led
    PORTD |= (1 << PD1);
  }
  else{
    PORTD &= ~(1 << PD1);
  }
  // if we are on layer 3
  if (state & (1<<3)){
    // light scroll lock led
    PORTD |= (1 << PD6);
  }
  else{
    PORTD &= ~(1 << PD6);
  }
    return state;
  return state;
}
