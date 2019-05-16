#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include <avr/pgmspace.h>
#include "words.c"

#define BASE 0 // default layer
#define EASY 1 // default layer
#define NUM 2 // symbols
#define FUNCTIONS 3 // symbols
#define ARR 4 // symbols
#define PUNC 5 // symbols

typedef enum onoff_t {OFF, ON} onoff;

enum custom_keycodes {
    DOWN3 = SAFE_RANGE,
    UP3,
    CLEFT,
    CRIGHT,
    RAND,
    PUNC_SWITCH,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_NO,      KC_NO,    KC_NO,   KC_NO,       KC_NO,   KC_NO,   KC_F3,
        PUNC_SWITCH,KC_Q,     KC_W,    KC_F,        KC_P,    KC_G,    KC_NO,
        KC_ESC,     KC_A, KC_R,    KC_S,        KC_T,    KC_D,
        KC_LSFT,    KC_Z,     KC_X,    KC_C,        KC_V,    KC_B,    KC_NO,
        KC_LCTRL,   KC_LGUI,  KC_LALT, MO(NUM),     KC_DEL,
                                                             KC_F12,  KC_F8,
                                                                      LSFT(KC_F2),
                                                    KC_BSPC, MO(ARR), KC_HOME,
        // right hand
        KC_F5,      KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,      KC_J,     KC_L,    KC_U,    KC_Y,    KC_SCLN, MO(PUNC),
                    KC_H,     KC_N,    KC_E,    KC_I,    KC_O,    KC_NO,
        KC_NO,      KC_K,     KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                              MO(FUNCTIONS),RAND,TG(EASY), KC_RGUI, KC_RCTRL,
        KC_F10,     KC_F11,
        KC_INS,
        KC_END,     KC_ENT,   KC_SPC
    ),

    [EASY] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_GRV,     KC_1,     KC_2,    KC_3,        KC_4,    KC_5,    KC_F3,
        PUNC_SWITCH,KC_Q,     KC_W,    KC_F,        KC_P,    KC_G,    KC_NUBS,
        KC_ESC,     KC_A,     KC_R,    KC_S,        KC_T,    KC_D,
        KC_LSFT,    KC_Z,     KC_X,    KC_C,        KC_V,    KC_B,    KC_NUHS,
        KC_LCTRL,   KC_LGUI,  KC_LALT, MO(NUM),     KC_DEL,
                                                             KC_F12,  KC_F8,
                                                                      LSFT(KC_F2),
                                                    KC_BSPC, MO(ARR), KC_HOME,
        // right hand
        KC_F5,      KC_6,     KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
        KC_LBRC,    KC_J,     KC_L,    KC_U,    KC_Y,    KC_SCLN, MO(PUNC),
                    KC_H,     KC_N,    KC_E,    KC_I,    KC_O,    KC_NO,
        KC_RBRC,    KC_K,     KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                              MO(FUNCTIONS),RAND,TG(EASY),KC_RGUI, KC_RCTRL,
        KC_F10,     KC_F11,
        KC_INS,
        KC_END,     KC_ENT,   KC_SPC
    ),

    [NUM] = LAYOUT_ergodox(
       // left hand
       RESET,  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
	   KC_TRNS,KC_TRNS,KC_7,KC_8,KC_9,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_4,KC_5,KC_6,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_1,KC_2,KC_3,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_0,KC_TRNS,KC_DOT,  
                                               KC_TRNS,KC_TRNS,
                                                       KC_TRNS,
                                       KC_TRNS,KC_TRNS,KC_TRNS,

       KC_TRNS,KC_TRNS,KC_TRNS,KC_KP_SLASH,KC_KP_ASTERISK,KC_KP_MINUS, KC_TRNS,
	   KC_TRNS,KC_TRNS,KC_7,   KC_8,       KC_9,          KC_KP_PLUS,  KC_TRNS,
               KC_TRNS,KC_4,   KC_5,       KC_6,          KC_KP_PLUS,  KC_TRNS,
       KC_TRNS,KC_TRNS,KC_1,   KC_2,       KC_3,          KC_KP_ENTER, KC_TRNS,
                       KC_0,   KC_0,       KC_DOT,        KC_KP_ENTER, KC_TRNS,
       KC_TRNS,KC_TRNS,
       KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS
   ),

    [FUNCTIONS] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
	   KC_TRNS,KC_TRNS,KC_F7,  KC_F8,  KC_F9,  KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_F4,  KC_F5,  KC_F4,  KC_TRNS,
       KC_TRNS,KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_F10, KC_F11, KC_F12, 
                                               KC_TRNS,KC_TRNS,
                                                       KC_TRNS,
                                       KC_TRNS,KC_TRNS,KC_TRNS,

       // right hand
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
	   KC_TRNS,KC_F10, KC_F7,  KC_F8,  KC_F9,  KC_TRNS,KC_TRNS,
               KC_F11, KC_F4,  KC_F5,  KC_F4,  KC_TRNS,KC_TRNS,
       KC_TRNS,KC_F12, KC_F1,  KC_F2,  KC_F3,  KC_TRNS,KC_TRNS,
                       KC_TRNS,KC_F11, KC_F12, KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,
       KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS
   ),

    [ARR] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
	   KC_TRNS,KC_TRNS,KC_HOME,KC_PGDN,KC_PGUP,KC_END, KC_TRNS,
       KC_TRNS,KC_TRNS,KC_LEFT,KC_UP,  KC_DOWN,KC_RGHT, 
       KC_TRNS,KC_TRNS,CLEFT,  DOWN3,  UP3,    CRIGHT, KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                               KC_TRNS,KC_TRNS,
                                                       KC_TRNS,
                                       KC_TRNS,KC_TRNS,KC_TRNS,

        // right hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_TRNS, KC_TRNS,
                KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS,
       KC_TRNS, CLEFT,   DOWN3,   UP3,     CRIGHT,  KC_TRNS, KC_TRNS,
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
       KC_TRNS, KC_NUBS, KC_GRV,  KC_TRNS, KC_TRNS, KC_NUHS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                    KC_TRNS, KC_TRNS,
                                                             KC_TRNS,
                                           KC_TRNS, KC_TRNS, KC_TRNS,

        // right hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS,
	   KC_TRNS, S(KC_6), S(KC_7), S(KC_8),       S(KC_9), S(KC_0), KC_TRNS,
                KC_QUOT, S(KC_LBRC),S(KC_RBRC),  KC_MINS, S(KC_EQL),KC_TRNS,
       KC_TRNS, S(KC_QUOT),KC_TRNS,KC_TRNS,    S(KC_MINS),KC_EQL, KC_TRNS,
                         KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
    ),

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
};

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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool key_pressed_since_punc = false;

    if (record->event.pressed) {
        key_pressed_since_punc = true;
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
        
        case RAND: ;
            if (record->event.pressed) {
	            //send_string(words[rand() % wordCount]);
				//need to get this out of program space
				//http://www.nongnu.org/avr-libc/user-manual/pgmspace.html

				char buffer[15];// = "test";

				strcpy_P(buffer, (PGM_P)pgm_read_word(&(words_table[rand() % wordCount])));
                send_string(buffer);
                SEND_STRING(" ");
                return false;
            }
            break;

        case  PUNC_SWITCH:
            if (record->event.pressed) {
                layer_on(PUNC);
                key_pressed_since_punc = false;
            } else {
                layer_off(PUNC);

                if (!key_pressed_since_punc)
                    tap_code(KC_TAB);
            }
            return false;
    }
    return true;
}