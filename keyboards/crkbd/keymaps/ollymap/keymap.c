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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
        NUM_SWITCH,KC_Q,   KC_W,     KC_E,     KC_R,     KC_T,                      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,  MO(FUNCTIONS),\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
        KC_ESC,     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                      KC_H,     KC_J,     KC_K,     KC_L,  KC_SCLN,  KC_LCTRL,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       KC_LSFT,     KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                      KC_N,     KC_M,  KC_COMM,   KC_DOT,  KC_SLSH,  KC_RSFT,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  MO(PUNC),MO(ARR),KC_BSPC,      KC_SPC, KC_ENT, MO(PUNC) \
                              //`--------------------'  `--------------------'
  ),

//   [NUM] = LAYOUT_kc( \
//   //,-----------------------------------------.                ,-----------------------------------------.
//         ESC,     1,     2,     3,     4,     5,                      6,     7,     8,     9,     0,  BSPC,\
//   //|------+------+------+------+------+------|                |------+------+------+------+------+------|
//       CTLTB,    F1,    F2,    F3,    F4,    F5,                     F6,    F7,    F8,    F9,   F10, XXXXX,\
//   //|------+------+------+------+------+------|                |------+------+------+------+------+------|
//        LSFT,   F11,   F12,   F13,   F14,   F15,                    F16,   F17,   F18,   F19,   F20, XXXXX,\
//   //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
//                                   GUIEI, LOWER,   SPC,      ENT, RAISE, ALTKN \
//                               //`--------------------'  `--------------------'
//   ),

//   [FUNCTIONS] = LAYOUT_kc( \
//   //,-----------------------------------------.                ,-----------------------------------------.
//         ESC,  EXLM,    AT,  HASH,   DLR,  PERC,                   CIRC,  AMPR,  ASTR,  LPRN,  RPRN,  BSPC,\
//   //|------+------+------+------+------+------|                |------+------+------+------+------+------|
//       CTLTB, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,                   MINS,   EQL,  LCBR,  RCBR,  PIPE,   GRV,\
//   //|------+------+------+------+------+------|                |------+------+------+------+------+------|
//        LSFT, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,                   UNDS,  PLUS,  LBRC,  RBRC,  BSLS,  TILD,\
//   //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
//                                   GUIEI, LOWER,   SPC,      ENT, RAISE, ALTKN \
//                               //`--------------------'  `--------------------'
//   ),

//   [ARR] = LAYOUT_kc( \
//   //,-----------------------------------------.                ,-----------------------------------------.
//         ESC,  EXLM,    AT,  HASH,   DLR,  PERC,                   CIRC,  AMPR,  ASTR,  LPRN,  RPRN,  BSPC,\
//   //|------+------+------+------+------+------|                |------+------+------+------+------+------|
//       CTLTB, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,                   MINS,   EQL,  LCBR,  RCBR,  PIPE,   GRV,\
//   //|------+------+------+------+------+------|                |------+------+------+------+------+------|
//        LSFT, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,                   UNDS,  PLUS,  LBRC,  RBRC,  BSLS,  TILD,\
//   //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
//                                   GUIEI, LOWER,   SPC,      ENT, RAISE, ALTKN \
//                               //`--------------------'  `--------------------'
//   ),

//   [PUNC] = LAYOUT_kc( \
//   //,-----------------------------------------.                ,-----------------------------------------.
//         RST,  LRST, XXXXX, XXXXX, XXXXX, XXXXX,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
//   //|------+------+------+------+------+------|                |------+------+------+------+------+------|
//        LTOG,  LHUI,  LSAI,  LVAI, XXXXX, XXXXX,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
//   //|------+------+------+------+------+------|                |------+------+------+------+------+------|
//        LMOD,  LHUD,  LSAD,  LVAD, XXXXX, XXXXX,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
//   //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
//                                   GUIEI, LOWER,   SPC,      ENT, RAISE, ALTKN \
//                               //`--------------------'  `--------------------'
//   )
// };

//   [_ADJUST] = LAYOUT_kc( \
//   //,-----------------------------------------.                ,-----------------------------------------.
//         RST,  LRST, XXXXX, XXXXX, XXXXX, XXXXX,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
//   //|------+------+------+------+------+------|                |------+------+------+------+------+------|
//        LTOG,  LHUI,  LSAI,  LVAI, XXXXX, XXXXX,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
//   //|------+------+------+------+------+------|                |------+------+------+------+------+------|
//        LMOD,  LHUD,  LSAD,  LVAD, XXXXX, XXXXX,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
//   //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
//                                   GUIEI, LOWER,   SPC,      ENT, RAISE, ALTKN \
//                               //`--------------------'  `--------------------'
//   )


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
  switch (keycode) {
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
