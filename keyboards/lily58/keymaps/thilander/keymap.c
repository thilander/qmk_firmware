#include QMK_KEYBOARD_H
#include "keymap_us_international.h"
#include "sendstring_us_international.h"

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
  _QWERTY_SWE
};

enum custom_keycodes {
    MAC_ARING = SAFE_RANGE,   // Å / å
    MAC_ADIA,              // Ä / ä
    MAC_ODIA,              // Ö / ö
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
    KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,
    KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,   KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
                        KC_LGUI, KC_LALT, MO(_LOWER), KC_SPC,      KC_ENT, MO(_RAISE), KC_BSPC, KC_RSFT
  ),
  [_LOWER] = LAYOUT(
    KC_ESC , KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5 ,                    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_UP  , KC_TRNS, KC_TRNS, MAC_ARING,
    KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN , KC_END, KC_TRNS,                   KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, MAC_ODIA, MAC_ADIA,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSLS,
                           KC_TRNS, KC_TRNS, MO(_LOWER), KC_TRNS, KC_TRNS, TG(_QWERTY_SWE), KC_DEL, KC_TRNS
  ),
  [_RAISE] = LAYOUT(
      KC_ESC , KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_BSPC,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,   KC_7,    KC_8,    KC_9,    KC_TRNS, MAC_ARING,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,   KC_4,    KC_5,    KC_6,    MAC_ODIA, MAC_ADIA,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_TRNS,   KC_1,    KC_2,    KC_3,    KC_TRNS, KC_BSLS,
                              KC_TRNS, KC_TRNS, MO(_LOWER),  KC_TRNS, KC_TRNS, MO(_RAISE), KC_DEL, KC_TRNS
  ),
  [_ADJUST] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, KC_KB_VOLUME_UP,   XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, KC_KB_VOLUME_DOWN, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_KB_MUTE,        XXXXXXX, XXXXXXX, XXXXXXX,
                                KC_TRNS, KC_TRNS, MO(_LOWER), KC_TRNS, KC_TRNS, MO(_RAISE), KC_TRNS, KC_TRNS
  ),
  [_QWERTY_SWE] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MAC_ARING,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MAC_ODIA, MAC_ADIA,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                            KC_TRNS, KC_TRNS, MO(_LOWER), KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OLED_ENABLE
    if (record->event.pressed) {
    set_keylog(keycode, record);
    }
#endif

    uint8_t mods    = get_mods() | get_oneshot_mods();
    bool    shifted = mods & MOD_MASK_SHIFT;

    switch (keycode) {
    //
    // Å / å
    //
    case MAC_ARING:
        if (!record->event.pressed) return false;

        if (shifted) {
            // Temporarily remove Shift to avoid interfering with the output
            del_mods(MOD_MASK_SHIFT);
            del_oneshot_mods(MOD_MASK_SHIFT);

            // Option+Shift+A → Å
            register_code(KC_LALT);
            register_code(KC_LSFT);
            tap_code(KC_A);
            unregister_code(KC_LSFT);
            unregister_code(KC_LALT);

            // Restore mods
            set_mods(mods);
        } else {
            // Option+A → å
            register_code(KC_LALT);
            tap_code(KC_A);
            unregister_code(KC_LALT);
        }
        return false;

    //
    // Ä / ä
    //
    case MAC_ADIA:
        if (!record->event.pressed) return false;

        // Remove Shift before dead key! (fixes “¨A”)
        del_mods(MOD_MASK_SHIFT);
        del_oneshot_mods(MOD_MASK_SHIFT);

        // Option+U (dead diaeresis)
        register_code(KC_LALT);
        tap_code(KC_U);
        unregister_code(KC_LALT);

        // Restore Shift if needed
        if (shifted) {
            register_code(KC_LSFT);
            tap_code(KC_A); // Ä
            unregister_code(KC_LSFT);
        } else {
            tap_code(KC_A); // ä
        }

        // Restore original mods
        set_mods(mods);
        return false;

    //
    // Ö / ö
    //
    case MAC_ODIA:
        if (!record->event.pressed) return false;

        // Remove Shift before dead key (fixes “¨O”)
        del_mods(MOD_MASK_SHIFT);
        del_oneshot_mods(MOD_MASK_SHIFT);

        // Option+U (dead diaeresis)
        register_code(KC_LALT);
        tap_code(KC_U);
        unregister_code(KC_LALT);

        // Restore Shift if needed
        if (shifted) {
            register_code(KC_LSFT);
            tap_code(KC_O); // Ö
            unregister_code(KC_LSFT);
        } else {
            tap_code(KC_O); // ö
        }

        // Restore original mods
        set_mods(mods);
        return false;
    }

    return true;
}
