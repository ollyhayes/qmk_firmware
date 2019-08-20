#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include <avr/pgmspace.h>
#include "ollymap.h"

typedef enum onoff_t {OFF, ON} onoff;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_GRV,     KC_1,     KC_2,    KC_3,        KC_4,    KC_5,    KC_F3,
        NUM_SWITCH, KC_Q,     KC_W,    KC_F,        KC_P,    KC_G,    KC_NO,
        KC_ESC,     KC_A,     KC_R,    KC_S,        KC_T,    KC_D,
        KC_LSFT,    KC_Z,     KC_X,    KC_C,        KC_V,    KC_B,    KC_DEL,
        KC_LCTRL,   KC_LGUI,  KC_LALT, KC_LCTRL,    MO(PUNC),
                                                             KC_F12,  KC_F8,
                                                                      LSFT(KC_F2),
                                                    KC_BSPC, MO(ARR), KC_HOME,
        // right hand
        KC_F5,      KC_6,     KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_VOLU,    KC_J,     KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
                    KC_H,     KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT,
        KC_VOLD,    KC_K,     KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                              MO(PUNC),KC_RCTRL,KC_RALT, KC_RGUI, KC_RCTRL,
        KC_F10,     KC_F11,
        KC_INS,
        KC_END,     KC_ENT,   KC_SPC
    ),

    [QWERTY] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_Q,    KC_W,    KC_E,        KC_R,    KC_T,KC_TRNS,
        KC_TRNS, KC_A,    KC_S,    KC_D,        KC_F,    KC_G,
        KC_TRNS, KC_Z,    KC_X,    KC_C,        KC_V,    KC_B,KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                    KC_TRNS, KC_TRNS,
                                                             KC_TRNS,
                                           KC_TRNS, KC_TRNS, KC_TRNS,

        // RIGHT HAND
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_TRNS,
                 KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_TRNS,
        KC_TRNS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [NUM] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
	   KC_TRNS,MO(FUNCTIONS),KC_7,KC_8,KC_9,KC_TRNS,KC_TRNS,
       KC_TRNS,MO(MEDIA),KC_4,KC_5,KC_6,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_1,KC_2,KC_3,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_0,KC_TRNS,KC_DOT,  
                                               KC_TRNS,KC_TRNS,
                                                       KC_TRNS,
                                       KC_TRNS,KC_TRNS,KC_TRNS,

       KC_TRNS,KC_TRNS,KC_TRNS,KC_KP_SLASH,KC_KP_ASTERISK,KC_KP_MINUS, KC_TRNS,
	   KC_TRNS,C(KC_GRV),KC_7,   KC_8,       KC_9,          KC_KP_PLUS,  KC_TRNS,
               ALTTAB, KC_4,   KC_5,       KC_6,          KC_KP_PLUS,  KC_TRNS,
       KC_TRNS,SALTTAB,KC_1, KC_2,       KC_3,          KC_KP_ENTER, KC_TRNS,
                       KC_0,   KC_0,       KC_DOT,        KC_KP_ENTER, KC_TRNS,
       KC_TRNS,KC_TRNS,
       KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS
   ),

    [FUNCTIONS] = LAYOUT_ergodox(
       // LEFT HAND
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_F7,  KC_F8,  KC_F9,  KC_F12,KC_TRNS,
       TG(FUNCTIONS),KC_TRNS,KC_F4,  KC_F5,  KC_F6,  KC_F11,
       KC_TRNS,KC_TRNS,KC_F1,KC_F2, KC_F3,  KC_F10,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                               KC_TRNS,KC_TRNS,
                                                       KC_TRNS,
                                       KC_TRNS,KC_TRNS,KC_TRNS,

       // right hand
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
	   KC_TRNS,KC_F12, KC_F7,  KC_F8,  KC_F9,  KC_TRNS,KC_TRNS,
               KC_F11, KC_F4,  KC_F5,  KC_F6,  KC_TRNS,KC_TRNS,
       KC_TRNS,KC_F10, KC_F1,  KC_F2,  KC_F3,  KC_TRNS,KC_TRNS,
                       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,
       KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS
   ),

    [ARR] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
	   KC_TRNS,KC_TRNS,KC_HOME,KC_PGDN,KC_PGUP,KC_END, KC_TRNS,
       KC_TRNS,KC_DEL,KC_LEFT,KC_UP,  KC_DOWN,KC_RGHT, 
       KC_TRNS,KC_INS,CLEFT,  KC_LGUI,KC_LALT,CRIGHT, KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                               KC_TRNS,KC_TRNS,
                                                       KC_TRNS,
                                       KC_TRNS,KC_TRNS,KC_TRNS,

        // right hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_TRNS, KC_TRNS,
                KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DEL, KC_TRNS,
       KC_TRNS, CLEFT,   DOWN3,   UP3,     CRIGHT,  KC_INS, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [PUNC] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	   KC_TRNS, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), KC_TRNS,
       KC_TRNS, S(KC_NUBS),S(KC_GRV),KC_LBRC,KC_RBRC,S(KC_NUHS),
       KC_TRNS, KC_NUBS, KC_GRV,  KC_LGUI,KC_LALT, KC_NUHS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                    KC_TRNS, KC_TRNS,
                                                             KC_TRNS,
                                           KC_TRNS, KC_TRNS, KC_TRNS,

        // right hand
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,
	    KC_TRNS, S(KC_6),   S(KC_7),   S(KC_8),    S(KC_9), S(KC_0), KC_TRNS,
                 KC_QUOT,   S(KC_LBRC),S(KC_RBRC), KC_MINS, S(KC_EQL),KC_TRNS,
        KC_TRNS, S(KC_QUOT),KC_LALT,   KC_RGUI,    S(KC_MINS),KC_EQL, KC_TRNS,
                 KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS
    ),
    
    [MEDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	   RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       DF(QWERTY),KC_TRNS, KC_CALC, KC_VOLU,KC_VOLD, KC_TRNS,  
       DF(BASE),KC_TRNS, KC_MPLY, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                    KC_TRNS, KC_TRNS,
                                                             KC_TRNS,
                                           KC_TRNS, KC_TRNS, KC_TRNS,

        // right hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_WAKE, KC_SLEP,
                KC_TRNS, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS, KC_CALC,
       KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_MPLY, KC_TRNS, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
    ),



    // [MEDIA] = LAYOUT_ergodox(
    //    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	//    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  
    //    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //                                                 KC_TRNS, KC_TRNS,
    //                                                          KC_TRNS,
    //                                        KC_TRNS, KC_TRNS, KC_TRNS,

    //     // right hand
    //    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //    KC_TRNS, KC_TRNS,
    //    KC_TRNS,
    //    KC_TRNS, KC_TRNS, KC_TRNS
    // ),
};

// Runs constantly in the background, in a loop.
// can switch this for layer_state_set_user
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