#include QMK_KEYBOARD_H

enum
{
    _QW = 0,
    _SY,
    _FN
};

#define SY_ENT LT(_SY, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* QWERTY
 *
 * ,---------+------+------+------+------+------+------+------+------+------+------+-------------.
 * | Tab     | Q    | W    | E    | R    | T    | Y    | U    | I    | O    | P    | Backspace   |
 * |---------`------`------`------`------`------`------`------`------`------`------`-------------|
 * | Ctrl     | A    | S    | D    | F    | G    | H    | J    | K    | L    | ;    | '          |
 * |----------`------`------`------`------`------`------`------`------`------`------`------------|
 * | Shift     | Z    | X    | C    | V    | B    | N    | M    | ,    | .    | /    | Shift/Ent |
 * |-----------`------`------`------`------`-----'-------`------`------`------`------`-----------|
 * | Esc     | Win     | LAlt    | Space          | SY             | FN      |         |         |
 *  `--------+---------+---------+------^^^-------+-----^^^--------+---------+---------+---------'
 */
  [_QW] = LAYOUT(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LGUI, KC_LALT, KC_LCTL,                   KC_SPC,  SY_ENT,           MO(_FN), XXXXXXX, XXXXXXX
  ),
/* Symbols
 *
 * ,---------+------+------+------+------+------+------+------+------+------+------+-------------.
 * | ~       | !    | @    | #    | $    | %    | ^    | &    | *    | (    | )    | Delete      |
 * |---------`------`------`------`------`------`------`------`------`------`------`-------------|
 * |          | 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    | 9    | 0    | `          |
 * |----------`------`------`------`------`------`------`------`------`------`------`------------|
 * |           | _    | -    | +    | =    | |    | \    | {    | [    | ]    | }    |           |
 * |-----------`------`------`------`------`-----'-------`------`------`------`------`-----------|
 * |         |         |         |                |                |         |         |         |
 *  `--------+---------+---------+------^^^-------+-----^^^--------+---------+---------+---------'
 */
  [_SY] = LAYOUT(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
    _______, KC_UNDS, KC_MINS, KC_PLUS, KC_EQL,  KC_PIPE,  KC_BSLS, KC_LCBR, KC_LBRC, KC_RBRC, KC_RCBR, _______,
    _______, _______, _______,                   _______, _______,          _______, _______, _______
  ),
/* Functions
 *
 * ,---------+------+------+------+------+------+------+------+------+------+------+-------------.
 * | Reset   | F1   | F2   | F3   | F4   |      |      |      |      |   ↑  |      | Delete      |
 * |---------`------`------`------`------`------`------`------`------`------`------`-------------|
 * |          | F5   | F6   | F7   | F8   |      |      |      |   ←  |   ↓  |   →  |            |
 * |----------`------`------`------`------`------`------`------`------`------`------`------------|
 * |           | F9   | F10  | F11  | F12  |      |      |      |      |      |      |           |
 * |-----------`------`------`------`------`-----'-------`------`------`------`------`-----------|
 * |         |         |         |                |                |         |         |         |
 *  `--------+---------+---------+------^^^-------+-----^^^--------+---------+---------+---------'
 */
  [_FN] = LAYOUT(
    RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, KC_DEL,
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, _______, _______,                   _______, _______,          _______, _______, _______
  )
};
