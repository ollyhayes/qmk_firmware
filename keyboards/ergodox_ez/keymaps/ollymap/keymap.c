#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define NUMLEFT 1 // symbols
#define NUMRIGHT 2 // symbols
#define FUNCLEFT 3 // symbols
#define FUNCRIGHT 4 // symbols

typedef enum onoff_t {OFF, ON} onoff;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_GRV,     KC_1,     KC_2,    KC_3,        KC_4,    KC_5,    KC_F3,
        KC_TAB,     KC_Q,     KC_W,    KC_F,        KC_P,    KC_G,    KC_F12,
        KC_ESC,     KC_A,     KC_R,    KC_S,        KC_T,    KC_D,
        KC_LSFT,    KC_Z,     KC_X,    KC_C,        KC_V,    KC_B,    KC_NUHS,
        KC_LCTRL,   KC_LGUI,  KC_LALT, LSFT(KC_F2), KC_NUBS,
                                                             KC_F6,   KC_F8,
                                                                      KC_PGUP,
                          //KC_BSPC, KC_DEL,  KC_HOME,
                          LT(NUMLEFT, KC_BSPC), LT(FUNCLEFT,KC_DEL),  KC_HOME,
        // right hand
        KC_F5,      KC_6,     KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
        KC_LBRC,    KC_J,     KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_MINS,
                    KC_H,     KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
        KC_RBRC,    KC_K,     KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                              KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_RGUI,
        KC_F10,     KC_F11,
        KC_PGDN,
        //KC_END,     KC_ENT,   KC_SPC
        KC_END,     LT(FUNCRIGHT, KC_ENT),   LT(NUMRIGHT, KC_SPC)
    ),

    [NUMLEFT] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_TRNS,KC_TRNS,KC_KP_SLASH,KC_KP_ASTERISK,KC_KP_MINUS,KC_TRNS,
	   KC_TRNS,KC_TRNS,KC_KP_7,KC_KP_8,    KC_KP_9,       KC_KP_PLUS, KC_TRNS,
       KC_TRNS,KC_TRNS,KC_KP_4,KC_KP_5,    KC_KP_6,       KC_KP_PLUS,
       KC_TRNS,KC_TRNS,KC_KP_1,KC_KP_2,    KC_KP_3,       KC_KP_ENTER,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_KP_0,KC_KP_0,    KC_KP_DOT,
                                                          KC_TRNS,    KC_TRNS,
				                                                      KC_TRNS,
                                           KC_TRNS,       KC_TRNS,    KC_TRNS,

       // right hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
   ),
   [NUMRIGHT] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
	   KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                               KC_TRNS,KC_TRNS,
                                                       KC_TRNS,
                                       KC_TRNS,KC_TRNS,KC_TRNS,


       KC_TRNS,KC_TRNS,KC_TRNS,KC_KP_SLASH,KC_KP_ASTERISK,KC_KP_MINUS, KC_TRNS,
	   KC_TRNS,KC_TRNS,KC_KP_7,KC_KP_8,    KC_KP_9,       KC_KP_PLUS, KC_TRNS,
               KC_TRNS,KC_KP_4,KC_KP_5,    KC_KP_6,       KC_KP_PLUS, KC_TRNS,
       KC_TRNS,KC_TRNS,KC_KP_1,KC_KP_2,    KC_KP_3,       KC_KP_ENTER,KC_TRNS,
                       KC_KP_0,KC_KP_0,    KC_KP_DOT,     KC_KP_ENTER,KC_TRNS,
       KC_TRNS,KC_TRNS,
       KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS
    ),

    [FUNCLEFT] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
	   KC_TRNS,KC_TRNS,KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_TRNS,
       KC_TRNS,KC_TRNS,KC_F4,  KC_F5,  KC_F4,  KC_F11, 
       KC_TRNS,KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F12, KC_TRNS,
       KC_TRNS,KC_TRNS,KC_F10, KC_F11, KC_F12,
                                               KC_TRNS,KC_TRNS,
                                                       KC_TRNS,
                                       KC_TRNS,KC_TRNS,KC_TRNS,

       // right hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
   ),

   [FUNCRIGHT] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
	   KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                               KC_TRNS,KC_TRNS,
                                                       KC_TRNS,
                                       KC_TRNS,KC_TRNS,KC_TRNS,


       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
	   KC_TRNS,KC_F10, KC_F7,  KC_F8,  KC_F9,  KC_TRNS,KC_TRNS,
               KC_F11, KC_F4,  KC_F5,  KC_F4,  KC_TRNS,KC_TRNS,
       KC_TRNS,KC_F12, KC_F1,  KC_F2,  KC_F3,  KC_TRNS,KC_TRNS,
                       KC_F10, KC_F11, KC_F12, KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,
       KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS
    ),
};

//const uint16_t PROGMEM fn_actions[] = {
//    // ACTION_LAYER_ON(SYMB,ON_RELEASE),           // FN1 - Enable Layer 1 (Symbols)
//    // ACTION_LAYER_OFF(SYMB,ON_RELEASE)           // FN3 - Disable Layer 1 (Symbols)
//};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);
    static uint8_t oldlayer = 0;

    if(oldlayer != layer)
	{
        // Layer was just toggled.
        if(layer == BASE)
            ergodox_board_led_off();
        else
            ergodox_board_led_on();
	}
    oldlayer = layer;
}
