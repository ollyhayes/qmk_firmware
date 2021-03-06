#include "ollymap.h"
#include "version.h"
#include "words.c"

static bool shift_held = false;

static void sendUtf(const char *str) {
    register_code(KC_LCTRL);
    register_code(KC_LSFT);
    tap_code(KC_U);
    unregister_code(KC_LSFT);
    unregister_code(KC_LCTRL);
    send_string(str);
    tap_code(KC_ENTER);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool key_pressed_since_switch = false;
    static uint16_t switch_down_time = 0;
    static bool alt_ctrl_tab_used = false;

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

        case NUM_SWITCH:
            if (record->event.pressed) {
                layer_on(NUM);
                key_pressed_since_switch = false;
                switch_down_time = timer_read();
            } else {
                layer_off(NUM);

                if (!key_pressed_since_switch && timer_elapsed(switch_down_time) < 200) {
                    tap_code(KC_TAB);
                }

                // Need this or normal alt-tab doesn't work
                if (alt_ctrl_tab_used) {
                    unregister_code(KC_LALT);
                    alt_ctrl_tab_used = false;
                }
            }
            return false;

        case MO(PUNC):
            if (!record->event.pressed) {
                if (alt_ctrl_tab_used) {
                    unregister_code(KC_LALT);
                    alt_ctrl_tab_used = false;
                }
            }
            return true;

        case MO(FUNCTIONS):
            if (!record->event.pressed) {
                // if NUM_SWITCH has been lifted first, toggle to that layer
                // (4 = 2^NUM)
                if ((layer_state & 4) != 0) {
                    layer_on(FUNCTIONS);
                    return false;
                }
            }
            return true;
        
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

        // was going to make holding both controls also hold alt. went all screwy though
        // case KC_LCTRL:
        //     if (record->event.pressed) {
        //         if (keyboard_report->mods & MOD_BIT(KC_RCTRL)) {
        //             register_code(KC_LALT);
        //         }
        //     } else {
        //         if (!(keyboard_report->mods & MOD_BIT(KC_LALT))) {
        //             unregister_code(KC_LALT);
        //         }
        //     }
        //     break;
        // case KC_RCTRL: // should be able to combine these
        //     if (record->event.pressed) {
        //         if (keyboard_report->mods & MOD_BIT(KC_LCTRL)) {
        //             register_code(KC_LALT);
        //         }
        //     } else {
        //         if (!(keyboard_report->mods & MOD_BIT(KC_LALT))) {
        //             unregister_code(KC_LALT);
        //         }
        //     }
        //     break;

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

        case KC_LSFT:
        case KC_RSFT:
            shift_held = record->event.pressed;
            return true;
            break;

        case ESZET:
            if (record->event.pressed) {
                sendUtf("00df");
            }
            break;
        case A_UMLAUT:
            if (record->event.pressed) {
                if (shift_held)
                    sendUtf("00c4");
                else
                    sendUtf("00e4");
            }
            break;
        case O_UMLAUT:
            if (record->event.pressed) {
                if (shift_held)
                    sendUtf("00d6");
                else
                    sendUtf("00f6");
            }
            break;
        case U_UMLAUT:
            if (record->event.pressed) {
                if (shift_held)
                    sendUtf("00dc");
                else
                    sendUtf("00fc");
            }
            break;
        case EURO:
            if (record->event.pressed) {
                sendUtf("20ac");
            }
            break;
        case POUND:
            if (record->event.pressed) {
                sendUtf("00a3");
            }
            break;
        case DEGREES:
            if (record->event.pressed) {
                sendUtf("00b0");
            }
            break;
        case TICKING:
            if (record->event.pressed) {
                sendUtf("2713");
            }
            break;
        case CROSS:
            if (record->event.pressed) {
                sendUtf("2717");
            }
            break;
        case TERROR:
            if (record->event.pressed) {
                sendUtf("1f631");
            }
            break;
    }
    return true;
}