/* Copyright 2019 Benjamin Davis
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H

// Tap dance
enum {
  LSFT_CAPS,
  RSFT_CAPS
};

// Layers
enum
{
    _QW = 0,
    _LS = 1,
    _RS = 2,
    _OV = 3,
    _FN = 4
};

#define LS_CAPS TD(LSFT_CAPS)
#define RS_CAPS TD(RSFT_CAPS)

#define OV_LCTL LM(_OV, MOD_LCTL)
#define OV_LGUI LM(_OV, MOD_LGUI)
#define OV_LALT LM(_OV, MOD_LALT)
#define OV_RALT LM(_OV, MOD_LALT | MOD_LCTL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QW] = LAYOUT_ansi(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,  KC_HOME,\
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,          KC_PGUP, \
    OV_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,  \
    LS_CAPS,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RS_CAPS,          KC_UP,   KC_END, \
    KC_F13,  OV_LGUI, OV_LALT,                            KC_SPC,                             OV_RALT, MO(_FN),          KC_LEFT, KC_DOWN, KC_RGHT),

  [_LS] = LAYOUT_ansi(
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______,          _______,          _______,  \
    _______,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______,          _______, _______, \
    _______, _______, _______,                            _______,                            _______, _______,          _______, _______, _______),

  [_RS] = LAYOUT_ansi(
    _______, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
    _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,          _______, \
    _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          _______,          _______,  \
    _______,          _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,          _______, _______, \
    _______, _______, _______,                            _______,                            _______, _______,          _______, _______, _______),

  [_OV] = LAYOUT_ansi(
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,  _______, \
    _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, _______,          _______, \
    _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          _______,          _______,  \
    _______,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,          _______, _______, \
    _______, _______, _______,                            _______,                            _______, _______,          _______, _______, _______),

  [_FN] = LAYOUT_ansi(
    RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, \
    _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, KC_DEL,           _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,  \
    _______,          _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,          KC_PGUP, _______, \
    _______, _______, _______,                            _______,                            _______, _______,          KC_HOME, KC_PGDN, KC_END)
  };

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
    layer_on(_LS);
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
    default: unregister_mods(MOD_BIT(KC_LSHIFT)); layer_off(_LS);
  }
}

void lsft_caps_reset (qk_tap_dance_state_t *state, void *user_data)
{
  switch (lsft_caps_tap_state.state) {
    case SINGLE_TAP:
    case SINGLE_HOLD: unregister_mods(MOD_BIT(KC_LSHIFT)); layer_off(_LS); break;
    case DOUBLE_SINGLE_TAP:
    case DOUBLE_TAP:
    case DOUBLE_HOLD: unregister_code(KC_CAPS);
  }
  lsft_caps_tap_state.state = 0;
}

static tap rsft_caps_tap_state =
{
  .is_press_action = true,
  .state = 0
};

void rsft_caps_on_each_tap (qk_tap_dance_state_t *state, void *user_data)
{
  if (state->pressed && state->count == 1)
  {
    register_mods(MOD_BIT(KC_RSHIFT));
    layer_on(_RS);
  }
}

void rsft_caps_finished (qk_tap_dance_state_t *state, void *user_data)
{
  rsft_caps_tap_state.state = cur_dance(state);
  switch (rsft_caps_tap_state.state) {
    case SINGLE_TAP:
    case SINGLE_HOLD: break;
    case DOUBLE_SINGLE_TAP:
    case DOUBLE_TAP:
    case DOUBLE_HOLD: register_code(KC_CAPS);
    default: unregister_mods(MOD_BIT(KC_RSHIFT)); layer_off(_RS);
  }
}

void rsft_caps_reset (qk_tap_dance_state_t *state, void *user_data)
{
  switch (rsft_caps_tap_state.state) {
    case SINGLE_TAP:
    case SINGLE_HOLD: unregister_mods(MOD_BIT(KC_RSHIFT)); layer_off(_RS); break;
    case DOUBLE_SINGLE_TAP:
    case DOUBLE_TAP:
    case DOUBLE_HOLD: unregister_code(KC_CAPS);
  }
  rsft_caps_tap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] =
{
  [LSFT_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(lsft_caps_on_each_tap, lsft_caps_finished, lsft_caps_reset),
  [RSFT_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(rsft_caps_on_each_tap, rsft_caps_finished, rsft_caps_reset)
};
