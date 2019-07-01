#include QMK_KEYBOARD_H
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

#define BASE 0 // default layer
#define NUM 1 // symbols
#define FUNCTIONS 2 // symbols
#define ARR 3 // symbols
#define PUNC 4 // symbols
#define _ADJUST 5

enum custom_keycodes {
  DOWN3 = SAFE_RANGE,
  UP3,
  CLEFT,
  CRIGHT,
  RAND,
  NUM_SWITCH,
  ALTTAB,
  CTLTAB,
  SALTTAB,
  SCTLTAB,
  ADJUST,
  BACKLIT,
  RGBRST
};

#define KC______ KC_TRNS
#define KC_XXXXX KC_NO
#define KC_RST   RESET
#define KC_LRST  RGBRST
#define KC_LTOG  RGB_TOG
#define KC_LHUI  RGB_HUI
#define KC_LHUD  RGB_HUD
#define KC_LSAI  RGB_SAI
#define KC_LSAD  RGB_SAD
#define KC_LVAI  RGB_VAI
#define KC_LVAD  RGB_VAD
#define KC_LMOD  RGB_MOD

// windows key
// qwerty layer
// del & insert
// should ctrl be moved?

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
        NUM_SWITCH,KC_Q,   KC_W,     KC_E,     KC_R,     KC_T,                      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,  MO(FUNCTIONS),\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
        KC_ESC,     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                      KC_H,     KC_J,     KC_K,     KC_L,  KC_SCLN,  KC_ENT,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       KC_LSFT,     KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                      KC_N,     KC_M,  KC_COMM,   KC_DOT,  KC_SLSH,  KC_RSFT,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  KC_LCTRL,MO(PUNC),LT(ARR, KC_BSPC),      KC_SPC, MO(PUNC), KC_RCTRL\
                              //`--------------------'  `--------------------'
  ),

  [NUM] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
      KC_TRNS,KC_TRNS,KC_7,KC_8,KC_9,KC_TRNS,          KC_TRNS,KC_7,KC_8,KC_9,KC_TRNS,KC_TRNS,\
  //|------+------+------+------+------+------|                ---+------+--------+------+------|
      KC_TRNS,KC_TRNS,KC_4,KC_5,KC_6,KC_TRNS,          ALTTAB,KC_4,KC_5,KC_6,KC_TRNS,KC_TRNS,\
  //|------+------+------+------+------+------|                ---+------+--------+------+------|
      KC_TRNS,   KC_0,KC_1,KC_2,KC_3,KC_TRNS,          SALTTAB,KC_1,KC_2,KC_3,KC_TRNS,KC_TRNS,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  KC_DOT, KC_TRNS,KC_TRNS,   KC_TRNS, KC_0, KC_DOT  \
                              //`--------------------'  `--------------------'
  ),

  [FUNCTIONS] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
      KC_TRNS,KC_F12,KC_F7,KC_F8,KC_F9,C(KC_GRV),       KC_F12,KC_F7,KC_F8,KC_F9,KC_LALT,KC_TRNS,\
  //|------+------+------+------+----|                |------+-------+------+----|  ------|
      KC_TRNS,KC_F11,KC_F4,KC_F5,KC_F6,CTLTAB,          KC_F11,KC_F4,KC_F5,KC_F6,KC_TRNS,KC_TRNS,\
  //|------+------+------+------+----|                |------+-------+------+----|  ------|
      KC_TRNS,KC_F10,KC_F1,KC_F2,KC_F3,SCTLTAB,         KC_F10,KC_F1,KC_F2,KC_F3,KC_TRNS,KC_TRNS,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  KC_TRNS, KC_TRNS,   KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS \
                              //`--------------------'  `--------------------'
  ),

  [ARR] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
      KC_TRNS,KC_TRNS,KC_HOME,KC_PGUP,KC_PGDN,KC_END,          KC_HOME,KC_PGDN,KC_PGUP,KC_END, KC_TRNS,KC_BSPC,\
  //|------+------+------+------+------+------|                ---+------+------+------|       ---+------|
      KC_TRNS,KC_TRNS,KC_LEFT,KC_UP,  KC_DOWN,KC_RGHT,         KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,KC_TRNS,KC_TRNS,\
  //|------+------+------+------+------+------|                ---+------+------+------|       ---+------|
      KC_TRNS,KC_TRNS,CLEFT,  UP3,    DOWN3,  CRIGHT,          CLEFT,  DOWN3,  UP3,    CRIGHT,  KC_TRNS,KC_TRNS,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  KC_TRNS, KC_TRNS,   KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS \
                              //`--------------------'  `--------------------'
  ),

  [PUNC] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
      KC_TRNS,S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),          S(KC_6),   S(KC_7),   S(KC_8),    S(KC_9), S(KC_0),KC_TRNS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      KC_TRNS,S(KC_NUBS),S(KC_GRV),KC_LBRC,KC_RBRC,S(KC_NUHS),          KC_QUOT,   S(KC_LBRC),S(KC_RBRC), KC_MINS, S(KC_EQL),KC_TRNS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      KC_TRNS,KC_NUBS, KC_GRV,  KC_TRNS, KC_TRNS, KC_NUHS,           S(KC_QUOT),KC_TRNS,   KC_TRNS,    S(KC_MINS),KC_EQL,KC_TRNS,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  KC_TRNS, KC_TRNS,   KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS \
                              //`--------------------'  `--------------------'
  ),
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool key_pressed_since_switch = false;
    static bool alt_ctrl_tab_used = false;
    static bool alt_ctrl_held = false;

    if (record->event.pressed) {
        key_pressed_since_switch = true;
    }

  switch (keycode) {
    case UP3:
        if (record->event.pressed) {
            tap_code(KC_UP);
            tap_code(KC_UP);
            tap_code(KC_UP);
            tap_code(KC_UP);
            return false;
        }
        break;

    case DOWN3:
        if (record->event.pressed) {
            tap_code(KC_DOWN);
            tap_code(KC_DOWN);
            tap_code(KC_DOWN);
            tap_code(KC_DOWN);
            return false;
        }
        break;

    case CLEFT:
        if (record->event.pressed) {
            register_code(KC_LCTRL);
            tap_code(KC_LEFT);
            unregister_code(KC_LCTRL);
            return false;
        }
        break;

    case CRIGHT:
        if (record->event.pressed) {
            register_code(KC_LCTRL);
            tap_code(KC_RIGHT);
            unregister_code(KC_LCTRL);
            return false;
        }
        break;
    
    // case RAND: ;
    //     if (record->event.pressed) {
    //       //send_string(words[rand() % wordCount]);
    // //need to get this out of program space
    // //http://www.nongnu.org/avr-libc/user-manual/pgmspace.html

    // char buffer[15];// = "test";

    // strcpy_P(buffer, (PGM_P)pgm_read_word(&(words_table[rand() % wordCount])));
    //         send_string(buffer);
    //         SEND_STRING(" ");
    //         return false;
    //     }
    //     break;

    case MO(FUNCTIONS):
        if (!record->event.pressed && alt_ctrl_tab_used) {
            unregister_code(KC_LCTRL);
            alt_ctrl_tab_used = false;
        }
        return true;

    case NUM_SWITCH:
        if (record->event.pressed) {

            if (alt_ctrl_held) {
                tap_code(KC_TAB);
                return false;
            }

            layer_on(NUM);
            key_pressed_since_switch = false;
        } else {
            layer_off(NUM);

            if (!key_pressed_since_switch) {
                tap_code(KC_TAB);
            }

            if (alt_ctrl_tab_used) {
                unregister_code(KC_LALT);
                alt_ctrl_tab_used = false;
            }
        }
        return false;
    
    case ALTTAB:
        if (record->event.pressed) {
            alt_ctrl_tab_used = true;
            register_code(KC_LALT);
            tap_code(KC_TAB);
        }
        return false;
    case SALTTAB:
        if (record->event.pressed) {
            alt_ctrl_tab_used = true;
            register_code(KC_LALT);
            register_code(KC_LSFT);
            tap_code(KC_TAB);
            unregister_code(KC_LSFT);
        }
        return false;

    case CTLTAB:
        if (record->event.pressed) {
            alt_ctrl_tab_used = true;
            register_code(KC_LCTRL);
            tap_code(KC_TAB);
        }
        return false;
    case SCTLTAB:
        if (record->event.pressed) {
            alt_ctrl_tab_used = true;
            register_code(KC_LCTRL);
            register_code(KC_LSFT);
            tap_code(KC_TAB);
            unregister_code(KC_LSFT);
        }
        return false;

    case KC_LCTRL:
    case KC_LALT:
        alt_ctrl_held = record->event.pressed;
        break;

    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
        break;
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
      break;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  }
  return true;
}
