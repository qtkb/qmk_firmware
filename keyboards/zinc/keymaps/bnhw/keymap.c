#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
rgblight_config_t RGB_current_config;
#endif
#ifdef RGB_MATRIX_ENABLE
#include "rgb_matrix_config.h"
extern rgb_config_t rgb_matrix_config;
rgb_config_t RGB_current_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  BACKLIT,
  RGBRST
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

//Macros
#define M_SAMPLE M(KC_SAMPLEMACRO)
#define SFT_ENT RSFT_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { \
  /* Qwerty
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  | Sh/En|
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Esc  | Win  | Win  | Alt  |ADJUST|Space |             | RAISE| LOWER| Left | Down |  Up  | Right|
   * `-----------------------------------------'             `-----------------------------------------'
   */
[_QWERTY] = LAYOUT_ortho_4x12(
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT, \
      KC_ESC,  KC_LGUI, KC_LGUI, KC_LALT, ADJUST,  KC_SPC,                    RAISE,   LOWER,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
      ),

  /* Lower
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |  F1  |  F2  |  F3  |  F4  |      |             |      |      |      |   ↑  |      | Del  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  F5  |  F6  |  F7  |  F8  |      |             |      |      |   ←  |   ↓  |   →  |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  F9  |  F10 |  F11 |  F12 |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * `-----------------------------------------'             `-----------------------------------------'
   */
  [_LOWER] = LAYOUT_ortho_4x12( \
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, KC_DEL, \
      _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX,                   XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, \
      _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______ \
      ),

  /* Raise
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  | Del  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  |   `  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |   _  |   -  |   +  |   =  |   |  |             |   \  |   {  |   [  |   ]  |   }  |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      | Home | PgDn | PgUp | End  |
   * `-----------------------------------------'             `-----------------------------------------'
   */
  [_RAISE] = LAYOUT_ortho_4x12( \
      KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
      _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV, \
      _______, KC_UNDS, KC_MINS, KC_PLUS, KC_EQL,  KC_PIPE,                   KC_BSLS, KC_LCBR, KC_LBRC, KC_RBRC, KC_RCBR, _______, \
      _______, _______, _______, _______, _______, _______,                   _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END \
      ),

  /* Adjust (Lower + Raise)
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |Reset |RGBRST|      |      |      |             | Mac  |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |RGB ON| HUE+ | SAT+ | VAL+ | SPD+ |             | Win  |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      | MODE | HUE- | SAT- | VAL- | SPD- |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * `-----------------------------------------'             `-----------------------------------------'
   */
    [_ADJUST] =  LAYOUT_ortho_4x12( \
      XXXXXXX, RESET,   RGBRST,  XXXXXXX, XXXXXXX, XXXXXXX,                   AG_NORM, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,                   AG_SWAP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
      XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX\
      )
};

// define variables for reactive RGB
bool TOG_STATUS = false;

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    #ifdef RGBLIGHT_ENABLE
        rgblight_mode_noeeprom(RGB_current_config.mode);  // revert RGB to initial mode prior to RGB mode change
    #endif
    #ifdef RGB_MATRIX_ENABLE
        rgb_matrix_mode_noeeprom(RGB_current_config.mode);  // revert RGB to initial mode prior to RGB mode change
    #endif
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;

    case LOWER:
      if (record->event.pressed) {
          //not sure how to have keyboard check mode and set it to a variable, so my work around
          //uses another variable that would be set to true after the first time a reactive key is pressed.
        if (TOG_STATUS) { //TOG_STATUS checks is another reactive key currently pressed, only changes RGB mode if returns false
        } else {
          TOG_STATUS = !TOG_STATUS;
          #ifdef RGBLIGHT_ENABLE
           rgblight_mode_noeeprom(16);
          #endif
          #ifdef RGB_MATRIX_ENABLE
           rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_MULTISPLASH);
          #endif
        }
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode_noeeprom(RGB_current_config.mode);
        #endif
        #ifdef RGB_MATRIX_ENABLE
          rgb_matrix_mode_noeeprom(RGB_current_config.mode);
        #endif
        TOG_STATUS = false;
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;

    case RAISE:
      if (record->event.pressed) {
        //not sure how to have keyboard check mode and set it to a variable, so my work around
        //uses another variable that would be set to true after the first time a reactive key is pressed.
        if (TOG_STATUS) { //TOG_STATUS checks is another reactive key currently pressed, only changes RGB mode if returns false
        } else {
          TOG_STATUS = !TOG_STATUS;
          #ifdef RGBLIGHT_ENABLE
            rgblight_mode_noeeprom(15);
          #endif
          #ifdef RGB_MATRIX_ENABLE
           rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_MULTISPLASH);
          #endif
        }
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode_noeeprom(RGB_current_config.mode);  // revert RGB to initial mode prior to RGB mode change
        #endif
        #ifdef RGB_MATRIX_ENABLE
          rgb_matrix_mode_noeeprom(RGB_current_config.mode);  // revert RGB to initial mode prior to RGB mode change
        #endif
        layer_off(_RAISE);
        TOG_STATUS = false;
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;

    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
        break;
      //led operations - RGB mode change now updates the RGB_current_mode to allow the right RGB mode to be set after reactive keys are released
    case RGB_MOD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode_noeeprom(RGB_current_config.mode);
          rgblight_step();
          RGB_current_config.mode = rgblight_config.mode;
        #endif
        #ifdef RGB_MATRIX_ENABLE
          rgb_matrix_mode_noeeprom(RGB_current_config.mode);
          rgb_matrix_step();
          RGB_current_config.mode = rgb_matrix_config.mode;
        #endif
      }
      return false;
      break;

    case RGBRST:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_config = rgblight_config;
        #endif
        #ifdef RGB_MATRIX_ENABLE
          eeconfig_update_rgb_matrix_default();
          rgb_matrix_enable();
          RGB_current_config = rgb_matrix_config;
        #endif
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      rgblight_init();
      RGB_current_config = rgblight_config;
    #endif
    #ifdef RGB_MATRIX_ENABLE
    if (!is_master)
    {
        swap_matrix_hands(&g_led_config);
    }

    rgb_matrix_init();
    RGB_current_config = rgb_matrix_config;
    #endif
}

void suspend_power_down_user(void)
{
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_user(void)
{
    rgb_matrix_set_suspend_state(false);
}
