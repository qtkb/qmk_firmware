#include QMK_KEYBOARD_H

enum layers
{
  _QWERTY = 0,
  _SYM,
  _LFN,
  _RFN,
};

enum custom_keycodes
{
  ALT_TAB = SAFE_RANGE,
  CTL_TAB,
};

#define MOD_TAB_TIMEOUT 1000

#define SH_Z    LSFT_T(KC_Z)
#define SH_SLSH RSFT_T(KC_SLSH)
#define RFN_BS  LT(_RFN, KC_BSPC)
#define SYM_ENT LT(_SYM, KC_ENT)
#define SNIP    S(G(KC_S))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
[_QWERTY] = LAYOUT( \
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,     KC_O,   KC_P,   \
  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,     KC_L,   KC_SCLN,\
  SH_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM,  KC_DOT, SH_SLSH,\
                                      KC_LCTL, KC_SPC,  SYM_ENT, RFN_BS\
),
[_SYM]    = LAYOUT( \
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,\
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   \
  KC_UNDS, KC_MINS, KC_PLUS, KC_EQL,  KC_PIPE,                   KC_BSLS, KC_LCBR, KC_LBRC, KC_RBRC, KC_RCBR,\
                                      _______, _______, _______, _______\
),
[_RFN]    = LAYOUT( \
  ALT_TAB, KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, KC_DEL,\
  CTL_TAB, SNIP,    XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_MPLY,\
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,\
                                      _______, _______, _______, _______\
)
};

enum tab_mod
{
  NO_MOD = 0,
  MOD_ALT,
  MOD_CTL,
};

enum tab_mod tab_mod_held = NO_MOD;
uint16_t mod_tab_timer = 0;

void clear_mod(void)
{
    switch (tab_mod_held)
    {
    case MOD_ALT:
        unregister_code(KC_LALT);
        break;
    case MOD_CTL:
        unregister_code(KC_LCTL);
        break;
    default:
        break;
    }

    tab_mod_held = NO_MOD;
}

void mod_for_tab(enum tab_mod mod)
{
    mod_tab_timer = timer_read();

    if (mod == tab_mod_held)
    {
        return;
    }

    clear_mod();
    tab_mod_held = mod;

    switch (tab_mod_held)
    {
    case MOD_ALT:
        register_code(KC_LALT);
        break;
    case MOD_CTL:
        register_code(KC_LCTL);
        break;
    default:
        break;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode)
    {
    case ALT_TAB:
        if (record->event.pressed)
        {
            mod_for_tab(MOD_ALT);
            register_code(KC_TAB);
        }
        else
        {
            unregister_code(KC_TAB);
        }
        break;
    case CTL_TAB:
        if (record->event.pressed)
        {
            mod_for_tab(MOD_CTL);
            register_code(KC_TAB);
        }
        else
        {
            unregister_code(KC_TAB);
        }
        break;
    default:
        clear_mod();
        break;
    }
    return true;
};

void matrix_scan_user(void)
{
    if (tab_mod_held && timer_elapsed(mod_tab_timer) > MOD_TAB_TIMEOUT)
    {
        clear_mod();
    }
}

// Esc, Tilde, Grave, Quote, Double-quote
