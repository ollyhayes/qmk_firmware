#include QMK_KEYBOARD_H
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif
#include "ollymap.h"

extern keymap_config_t keymap_config;

extern uint8_t is_master;

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

  [NUM] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
      KC_TRNS,MO(FUNCTIONS),KC_7,KC_8,KC_9,KC_TRNS,    C(KC_GRV),KC_7,KC_8,KC_9,KC_TRNS,KC_TRNS,\
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
      KC_TRNS,KC_TRNS,MO(MEDIA),KC_F8,KC_F9,KC_F12,       KC_F12,KC_F7,KC_F8,KC_F9,KC_TRNS,KC_TRNS,\
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
      KC_TRNS,KC_TRNS,KC_HOME,KC_PGUP,KC_PGDN,KC_END,          KC_HOME,KC_PGDN,KC_PGUP,KC_END, KC_TRNS,KC_TRNS,\
  //|------+------+------+------+------+------|                ---+------+------+------|       ---+------|
      KC_TRNS,KC_DEL,KC_LEFT,KC_UP,  KC_DOWN,KC_RGHT,         KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,KC_DEL,KC_TRNS,\
  //|------+------+------+------+------+------|                ---+------+------+------|       ---+------|
      KC_TRNS,KC_INS,CLEFT,KC_LGUI,KC_LALT,CRIGHT,          CLEFT,  DOWN3,  UP3,    CRIGHT,  KC_INS,KC_TRNS,\
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
      KC_TRNS,KC_NUBS, KC_GRV,  KC_LGUI, KC_LALT, KC_NUHS,           S(KC_QUOT),KC_LALT,KC_LGUI,S(KC_MINS),KC_EQL,KC_TRNS,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  KC_TRNS, KC_TRNS,   KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS \
                              //`--------------------'  `--------------------'
  ),

  [MEDIA] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
      RESET,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_WAKE,KC_SLEP,\
  //|------+------+------+------+------+------|                                |------+------+------+------+------+------|
      DF(QWERTY),KC_TRNS,KC_TRNS,KC_VOLU,KC_VOLD,KC_TRNS,                KC_TRNS,KC_VOLD,KC_VOLU,KC_TRNS,KC_TRNS,KC_CALC,\
  //|------+------+------+------+------+------|                                |------+------+------+------+------+------|
      DF(BASE),KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                KC_TRNS,KC_MPRV,KC_MNXT,KC_MPLY,KC_TRNS,KC_TRNS,\
  //|------+------+------+------+------+------+------|                  |------+------+------+------+------+------+------|
                                  KC_TRNS, KC_TRNS,                   KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS \
                              //`--------------------'  `--------------------'
  ),
};

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