#include QMK_KEYBOARD_H

enum
{
    _QWERTY = 0,
    _SYMBOLS,
    _FUNCTIONS,
    _CONFIG,
    _GAME,
};

// Tap dance
enum {
  LSFT_CAPS
};

#define ESC_CTL LCTL_T(KC_ESC)
#define LS_CAPS TD(LSFT_CAPS)
#define SYM_ENT LT(_SYMBOLS, KC_ENT)
#define FUNCS MO(_FUNCTIONS)
#define CONFIG MO(_CONFIG)
#define GAME MO(_GAME)
#define C_TAB C(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_splits(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, KC_BSPC,
    ESC_CTL,          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    LS_CAPS,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                      KC_LGUI, KC_LALT, GAME,             KC_SPC,  SYM_ENT,          FUNCS,   CONFIG
      ),
  [_SYMBOLS] = LAYOUT_splits(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,  KC_DEL,
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
  [_GAME] = LAYOUT_splits(
    C_TAB,   KC_1,    KC_2,    KC_3,    KC_4,    KC_F2,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_F1,            KC_5,    KC_6,    KC_7,    KC_8,    KC_F3,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______,          KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_F4,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
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

typedef struct
{
  bool is_press_action;
  int state;
} tap;

enum
{
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  DOUBLE_SINGLE_TAP = 5, //send two single taps
  TRIPLE_TAP = 6,
  TRIPLE_HOLD = 7
};

int cur_dance (qk_tap_dance_state_t *state);

void lsft_caps_on_each_tap (qk_tap_dance_state_t *state, void *user_data);
void lsft_caps_finished (qk_tap_dance_state_t *state, void *user_data);
void lsft_caps_reset (qk_tap_dance_state_t *state, void *user_data);

/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
int cur_dance (qk_tap_dance_state_t *state)
{
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)  return SINGLE_TAP;
    //key has not been interrupted, but they key is still held. Means you want to send a 'HOLD'.
    else return SINGLE_HOLD;
  }
  else if (state->count == 2) {
    /*
     * DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
     * action when hitting 'pp'. Suggested use case for this return value is when you want to send two
     * keystrokes of the key, and not the 'double tap' action/macro.
    */
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  //Assumes no one is trying to type the same letter three times (at least not quickly).
  //If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
  //an exception here to return a 'TRIPLE_SINGLE_TAP', and define that enum just like 'DOUBLE_SINGLE_TAP'
  if (state->count == 3) {
    if (state->interrupted || !state->pressed)  return TRIPLE_TAP;
    else return TRIPLE_HOLD;
  }
  else return 8; //magic number. At some point this method will expand to work for more presses
}

static tap lsft_caps_tap_state =
{
  .is_press_action = true,
  .state = 0
};

void lsft_caps_on_each_tap (qk_tap_dance_state_t *state, void *user_data)
{
  if (state->pressed && state->count == 1)
  {
    register_mods(MOD_BIT(KC_LSHIFT));
  }
}

void lsft_caps_finished (qk_tap_dance_state_t *state, void *user_data)
{
  lsft_caps_tap_state.state = cur_dance(state);
  switch (lsft_caps_tap_state.state) {
    case SINGLE_TAP:
    case SINGLE_HOLD: break;
    case DOUBLE_SINGLE_TAP:
    case DOUBLE_TAP:
    case DOUBLE_HOLD: register_code(KC_CAPS);
    default: unregister_mods(MOD_BIT(KC_LSHIFT));
  }
}

void lsft_caps_reset (qk_tap_dance_state_t *state, void *user_data)
{
  switch (lsft_caps_tap_state.state) {
    case SINGLE_TAP:
    case SINGLE_HOLD: unregister_mods(MOD_BIT(KC_LSHIFT)); break;
    case DOUBLE_SINGLE_TAP:
    case DOUBLE_TAP:
    case DOUBLE_HOLD: unregister_code(KC_CAPS);
  }
  lsft_caps_tap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] =
{
  [LSFT_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(lsft_caps_on_each_tap, lsft_caps_finished, lsft_caps_reset),
};
