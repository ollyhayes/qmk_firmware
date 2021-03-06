#include QMK_KEYBOARD_H
#include "ollymap.h"

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
        NUM_SWITCH,KC_Q,   KC_W,     KC_F,     KC_P,     KC_G,                      KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  KC_BSPC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
        KC_ESC,     KC_A,     KC_R,     KC_S,     KC_T,     KC_D,                      KC_H,     KC_N,     KC_E,     KC_I,  KC_O,  KC_ENT,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       KC_LSFT,     KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                      KC_K,     KC_M,  KC_COMM,   KC_DOT,  KC_SLSH,  KC_RSFT,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  KC_LCTRL,MO(PUNC),MO(ARR),      KC_SPC, MO(PUNC), KC_RCTRL\
                              //`--------------------'  `--------------------'
  ),

  [QWERTY] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
        KC_TRNS,     KC_Q,   KC_W,     KC_E,     KC_R,     KC_T,                      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,  KC_TRNS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
        KC_TRNS,     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                      KC_H,     KC_J,     KC_K,     KC_L,  KC_SCLN,  KC_TRNS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       KC_TRNS,      KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                      KC_N,     KC_M,  KC_COMM,   KC_DOT,  KC_SLSH,  KC_TRNS,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  KC_TRNS, KC_TRNS,   KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS \
                              //`--------------------'  `--------------------'
  ),

  [GAMES] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
        KC_TRNS,     KC_Q,   KC_W,     KC_E,     KC_R,     KC_T,                      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,  KC_TRNS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
        KC_TRNS,     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                      KC_H,     KC_J,     KC_K,     KC_L,  KC_SCLN,  KC_TRNS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       KC_TRNS,      KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                      KC_N,     KC_M,  KC_COMM,   KC_DOT,  KC_SLSH,  KC_TRNS,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  KC_TRNS, KC_LALT,   KC_SPACE,      MO(ARR), KC_TRNS, KC_TRNS \
                              //`--------------------'  `--------------------'
  ),

  [NUM] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
      KC_TRNS,MO(FUNCTIONS),KC_7,KC_8,KC_9,KC_TRNS,    C(KC_GRV),KC_7,KC_8,KC_9,KC_TRNS,KC_TRNS,\
  //|------+------+------+------+------+------|                ---+------+--------+------+------|
      KC_TRNS,MO(MEDIA),KC_4,KC_5,KC_6,KC_TRNS,          KC_NO,KC_4,KC_5,KC_6,KC_TRNS,KC_TRNS,\
  //|------+------+------+------+------+------|                ---+------+--------+------+------|
        KC_TRNS,   KC_0,KC_1,KC_2,KC_3,KC_TRNS,         KC_NO,KC_1,KC_2,KC_3,KC_TRNS,KC_TRNS,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  KC_DOT, KC_TRNS,KC_TRNS,   KC_TRNS, KC_0, KC_DOT  \
                              //`--------------------'  `--------------------'
  ),

  [FUNCTIONS] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
      KC_TRNS,KC_TRNS,KC_TRNS,KC_F8,KC_F9,KC_F12,       KC_F12,KC_F7,KC_F8,KC_F9,KC_TRNS,KC_TRNS,\
  //|------+------+------+------+----|                |------+-------+------+----|  ------|
      TG(FUNCTIONS),KC_TRNS,KC_F4,KC_F5,KC_F6,KC_F11,     KC_F11,KC_F4,KC_F5,KC_F6,KC_TRNS,KC_TRNS,\
  //|------+------+------+------+----|                |------+-------+------+----|  ------|
      KC_TRNS,KC_TRNS,KC_F1,KC_F2,KC_F3,KC_F10,         KC_F10,KC_F1,KC_F2,KC_F3,KC_TRNS,KC_TRNS,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  KC_TRNS, KC_TRNS,   KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS \
                              //`--------------------'  `--------------------'
  ),

  [ARR] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
      KC_TRNS,RAND,KC_HOME,KC_PGUP,KC_PGDN,KC_END,          KC_HOME,KC_PGDN,KC_PGUP,KC_END, RAND,KC_TRNS,\
  //|------+------+------+------+------+------|                ---+------+------+------|       ---+------|
      KC_ENT,KC_DEL,KC_LEFT,KC_UP,  KC_DOWN,KC_RGHT,         KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,KC_DEL,KC_TRNS,\
  //|------+------+------+------+------+------|                ---+------+------+------|       ---+------|
      KC_TRNS,KC_INS,CLEFT,KC_LGUI,KC_LALT,CRIGHT,          CLEFT,  DOWN3,  UP3,    CRIGHT,  KC_INS,KC_TRNS,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  KC_TRNS, KC_F12,   KC_TRNS,      KC_TRNS, KC_F12, KC_TRNS \
                              //`--------------------'  `--------------------'
  ),

  [PUNC] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
      ALTTAB,S(KC_1), S(KC_2), EURO, S(KC_4), S(KC_5),          S(KC_6),   S(KC_7),   S(KC_8),    S(KC_9), S(KC_0),KC_TRNS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      KC_TRNS,S(KC_NUBS),S(KC_GRV),KC_LBRC,KC_RBRC,S(KC_NUHS),          KC_QUOT,   S(KC_LBRC),S(KC_RBRC), KC_MINS, S(KC_EQL),KC_TRNS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      KC_TRNS,KC_NUBS, KC_GRV,  KC_LGUI, KC_LALT, KC_NUHS,           S(KC_QUOT),KC_LALT,KC_LGUI,S(KC_MINS),KC_EQL,KC_TRNS,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  KC_TRNS, MO(DUBPUNC),   KC_TRNS,      KC_TRNS, MO(DUBPUNC), KC_TRNS \
                              //`--------------------'  `--------------------'
  ),

  [MEDIA] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
      RESET,RGB_RMOD,RGB_MOD,RGB_TOG,RGB_HUD,RGB_HUI,                RGB_HUD,RGB_HUI,RGB_TOG,RGB_MOD,RGB_RMOD,KC_SLEP,\
  //|------+------+------+------+------+------|                                |------+------+------+------+------+------|
      DF(QWERTY),KC_TRNS,KC_TRNS,KC_VOLD,KC_VOLU,RGB_MODE_PLAIN,     RGB_MODE_PLAIN,KC_VOLD,KC_VOLU,KC_TRNS,KC_TRNS,KC_TRNS,\
  //|------+------+------+------+------+------|                                |------+------+------+------+------+------|
      DF(BASE),DF(GAMES),RGB_VAD,RGB_VAI,RGB_SAD,RGB_SAI,                RGB_SAD,RGB_SAI,RGB_VAD,RGB_VAI,KC_TRNS,KC_TRNS,\
  //|------+------+------+------+------+------+------|                  |------+------+------+------+------+------+------|
                                  KC_TRNS, KC_TRNS,                   KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS \
                              //`--------------------'  `--------------------'
  ),

  [DUBPUNC] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
      KC_TRNS,KC_TRNS,KC_TRNS,POUND,KC_TRNS,KC_TRNS,                KC_TRNS,KC_TRNS,U_UMLAUT,KC_TRNS,KC_TRNS,KC_TRNS,\
  //|------+------+------+------+------+------|                                |------+------+------+------+------+------|
      KC_TRNS,A_UMLAUT,KC_TRNS,ESZET,TICKING,KC_TRNS,                DEGREES,KC_TRNS,KC_TRNS,KC_TRNS,O_UMLAUT,KC_TRNS,\
  //|------+------+------+------+------+------|                                |------+------+------+------+------+------|
      KC_TRNS,TERROR,CROSS,KC_TRNS,KC_TRNS,KC_TRNS,                KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,\
  //|------+------+------+------+------+------+------|                  |------+------+------+------+------+------+------|
                                  KC_TRNS, KC_TRNS,                   KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS \
                              //`--------------------'  `--------------------'
  )
};

/*
// old media keys with rgb - disabling to put german letters in
//   [MEDIA] = LAYOUT( \
//   //,-----------------------------------------.                ,-----------------------------------------.
//       RESET,RGB_RMOD,RGB_MOD,RGB_TOG,RGB_HUD,RGB_HUI,                RGB_HUD,RGB_HUI,RGB_TOG,RGB_MOD,RGB_RMOD,KC_SLEP,\
//   //|------+------+------+------+------+------|                                |------+------+------+------+------+------|
//       DF(QWERTY),KC_TRNS,KC_CALC,KC_VOLD,KC_VOLU,RGB_MODE_PLAIN,     RGB_MODE_PLAIN,KC_VOLD,KC_VOLU,KC_TRNS,KC_TRNS,KC_CALC,\
//   //|------+------+------+------+------+------|                                |------+------+------+------+------+------|
//       DF(BASE),KC_TRNS,RGB_VAD,RGB_VAI,RGB_SAD,RGB_SAI,                RGB_SAD,RGB_SAI,RGB_VAD,RGB_VAI,KC_TRNS,KC_TRNS,\
//   //|------+------+------+------+------+------+------|                  |------+------+------+------+------+------+------|
//                                   KC_TRNS, KC_TRNS,                   KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS \
//                               //`--------------------'  `--------------------'
//   )
*/

/*
  [TEMPLATE] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
      KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,\
  //|------+------+------+------+------+------|                                |------+------+------+------+------+------|
      KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,\
  //|------+------+------+------+------+------|                                |------+------+------+------+------+------|
      KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,\
  //|------+------+------+------+------+------+------|                  |------+------+------+------+------+------+------|
                                  KC_TRNS, KC_TRNS,                   KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS \
                              //`--------------------'  `--------------------'
  ),
  */

// int RGB_current_mode;

// void matrix_init_user(void) {
//     #ifdef RGBLIGHT_ENABLE
//       RGB_current_mode = rgblight_config.mode;
//     #endif
// }