#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define NUM 1 // symbols
#define FUNCTIONS 2 // symbols
#define ARR 3 // symbols

typedef enum onoff_t {OFF, ON} onoff;

enum custom_keycodes {
    DOWN3 = SAFE_RANGE,
    UP3,
    CLEFT,
    CRIGHT,
    RAND
};

// int wordCount = 231;
// const char *words[231];
int wordCount = 6231;
const char *words[6];

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_GRV,     KC_1,     KC_2,    KC_3,        KC_4,    KC_5,    KC_F3,
        KC_TAB,     KC_Q,     KC_W,    KC_F,        KC_P,    KC_G,    KC_NUBS,
        KC_ESC,     KC_A,     KC_R,    KC_S,        KC_T,    KC_D,
        KC_LSFT,    KC_Z,     KC_X,    KC_C,        KC_V,    KC_B,    KC_NUHS,
        KC_LCTRL,   KC_LGUI,  KC_LALT, MO(NUM),     KC_DEL,
                                                             KC_F12,  KC_F8,
                                                                      LSFT(KC_F2),
                                                    KC_BSPC, MO(ARR), KC_HOME,
        // right hand
        KC_F5,      KC_6,     KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
        KC_LBRC,    KC_J,     KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_MINS,
                    KC_H,     KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
        KC_RBRC,    KC_K,     KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                              MO(FUNCTIONS),RAND,KC_RALT, KC_RGUI, KC_RCTRL,
        KC_F10,     KC_F11,
        KC_INS,
        KC_END,     KC_ENT,   KC_SPC
    ),

    [NUM] = LAYOUT_ergodox(
       // left hand
       RESET,  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
	   KC_TRNS,KC_TRNS,KC_KP_7,KC_KP_8,KC_KP_9,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_KP_4,KC_KP_5,KC_KP_6,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_KP_1,KC_KP_2,KC_KP_3,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_KP_0,KC_TRNS,KC_KP_DOT,  
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
    switch (keycode) {
        case UP3:
            if (record->event.pressed) {
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

                send_string(words[rand() % wordCount]);
                return false;
            }
            break;
    }

    return true;
}

void keyboard_pre_init_user(void) {
    words[0] = "Adult";
    words[1] = "Aeroplane";
    words[2] = "Air";
    words[3] = "Aircraft Carrier";
    words[4] = "Airforce";
    words[5] = "Airport";
    // words[6] = "Album";
    // words[7] = "Alphabet";
    // words[8] = "Apple";
    // words[9] = "Arm";
    // words[10] = "Army";
    // words[11] = "Baby";
    // words[12] = "Baby";
    // words[13] = "Backpack";
    // words[14] = "Balloon";
    // words[15] = "Banana";
    // words[16] = "Bank";
    // words[17] = "Barbecue";
    // words[18] = "Bathroom";
    // words[19] = "Bathtub";
    // words[20] = "Bed";
    // words[21] = "Bed";
    // words[22] = "Bee";
    // words[23] = "Bible";
    // words[24] = "Bible";
    // words[25] = "Bird";
    // words[26] = "Bomb";
    // words[27] = "Book";
    // words[28] = "Boss";
    // words[29] = "Bottle";
    // words[30] = "Bowl";
    // words[31] = "Box";
    // words[32] = "Boy";
    // words[33] = "Brain";
    // words[34] = "Bridge";
    // words[35] = "Butterfly";
    // words[36] = "Button";
    // words[37] = "Cappuccino";
    // words[38] = "Car";
    // words[39] = "Car-race";
    // words[40] = "Carpet";
    // words[41] = "Carrot";
    // words[42] = "Cave";
    // words[43] = "Chair";
    // words[44] = "Chess Board";
    // words[45] = "Chief";
    // words[46] = "Child";
    // words[47] = "Chisel";
    // words[48] = "Chocolates";
    // words[49] = "Church";
    // words[50] = "Church";
    // words[51] = "Circle";
    // words[52] = "Circus";
    // words[53] = "Circus";
    // words[54] = "Clock";
    // words[55]= "Clown";
    // words[56] = "Coffee";
    // words[57] = "Coffee-shop";
    // words[58] = "Comet";
    // words[59] = "Compact Disc";
    // words[60] = "Compass";
    // words[61] = "Computer";
    // words[62] = "Crystal";
    // words[63] = "Cup";
    // words[64] = "Cycle";
    // words[65] = "Data Base";
    // words[66] = "Desk";
    // words[67] = "Diamond";
    // words[68] = "Dress";
    // words[69] = "Drill";
    // words[70] = "Drink";
    // words[71] = "Drum";
    // words[72] = "Dung";
    // words[73] = "Ears";
    // words[74] = "Earth";
    // words[75] = "Egg";
    // words[76] = "Electricity";
    // words[77] = "Elephant";
    // words[78] = "Eraser";
    // words[79] = "Explosive";
    // words[80] = "Eyes";
    // words[81] = "Family";
    // words[82] = "Fan";
    // words[83] = "Feather";
    // words[84] = "Festival";
    // words[85] = "Film";
    // words[86] = "Finger";
    // words[87] = "Fire";
    // words[88] = "Floodlight";
    // words[89] = "Flower";
    // words[90] = "Foot";
    // words[91] = "Fork";
    // words[92] = "Freeway";
    // words[93] = "Fruit";
    // words[94] = "Fungus";
    // words[95] = "Game";
    // words[96] = "Garden";
    // words[97] = "Gas";
    // words[98] = "Gate";
    // words[99] = "Gemstone";
    // words[100] = "Girl";
    // words[101] = "Gloves";
    // words[102] = "God";
    // words[103] = "Grapes";
    // words[104] = "Guitar";
    // words[105] = "Hammer";
    // words[106] = "Hat";
    // words[107] = "Hieroglyph";
    // words[108] = "Highway";
    // words[109] = "Horoscope";
    // words[110] = "Horse";
    // words[111] = "Hose";
    // words[112] = "Ice";
    // words[113] = "Ice-cream";
    // words[114] = "Insect";
    // words[115] = "Jet fighter";
    // words[116] = "Junk";
    // words[117] = "Kaleidoscope";
    // words[118] = "Kitchen";
    // words[119] = "Knife";
    // words[120] = "Leather jacket";
    // words[121] = "Leg";
    // words[122] = "Library";
    // words[123] = "Liquid";
    // words[124] = "Magnet";
    // words[125] = "Man";
    // words[126] = "Map";
    // words[127] = "Maze";
    // words[128] = "Meat";
    // words[129] = "Meteor";
    // words[130] = "Microscope";
    // words[131] = "Milk";
    // words[132] = "Milkshake";
    // words[133] = "Mist";
    // words[134] = "Money $$$$";
    // words[135] = "Monster";
    // words[136] = "Mosquito";
    // words[137] = "Mouth";
    // words[138] = "Nail";
    // words[139] = "Navy";
    // words[140] = "Necklace";
    // words[141] = "Needle";
    // words[142] = "Onion";
    // words[143] = "PaintBrush";
    // words[144] = "Pants";
    // words[145] = "Parachute";
    // words[146] = "Passport";
    // words[147] = "Pebble";
    // words[148] = "Pendulum";
    // words[149] = "Pepper";
    // words[150] = "Perfume";
    // words[151] = "Pillow";
    // words[152] = "Plane";
    // words[153] = "Planet";
    // words[154] = "Pocket";
    // words[155] = "Post-office";
    // words[156] = "Potato";
    // words[157] = "Printer";
    // words[158] = "Prison";
    // words[159] = "Pyramid";
    // words[160] = "Radar";
    // words[161] = "Rainbow";
    // words[162] = "Record";
    // words[163] = "Restaurant";
    // words[164] = "Rifle";
    // words[165] = "Ring";
    // words[166] = "Robot";
    // words[167] = "Rock";
    // words[168] = "Rocket";
    // words[169] = "Roof";
    // words[170] = "Room";
    // words[171] = "Rope";
    // words[172] = "Saddle";
    // words[173] = "Salt";
    // words[174] = "Sandpaper";
    // words[175] = "Sandwich";
    // words[176] = "Satellite";
    // words[177] = "School";
    // words[178] = "Sex";
    // words[179] = "Ship";
    // words[180] = "Shoes";
    // words[181] = "Shop";
    // words[182] = "Shower";
    // words[183] = "Signature";
    // words[184] = "Skeleton";
    // words[185] = "Slave";
    // words[186] = "Snail";
    // words[187] = "Software";
    // words[188] = "Solid";
    // words[189] = "Space Shuttle";
    // words[190] = "Spectrum";
    // words[191] = "Sphere";
    // words[192] = "Spice";
    // words[193] = "Spiral";
    // words[194] = "Spoon";
    // words[195] = "Sports-car";
    // words[196] = "Spot Light";
    // words[197] = "Square";
    // words[198] = "Staircase";
    // words[199] = "Star";
    // words[200] = "Stomach";
    // words[201] = "Sun";
    // words[202] = "Sunglasses";
    // words[203] = "Surveyor";
    // words[204] = "Swimming Pool";
    // words[205] = "Sword";
    // words[206] = "Table";
    // words[207] = "Tapestry";
    // words[208] = "Teeth";
    // words[209] = "Telescope";
    // words[210] = "Television";
    // words[211] = "Tennis racquet";
    // words[212] = "Thermometer";
    // words[213] = "Tiger";
    // words[214] = "Toilet";
    // words[215] = "Tongue";
    // words[216] = "Torch";
    // words[217] = "Torpedo";
    // words[218] = "Train";
    // words[219] = "Treadmill";
    // words[220] = "Triangle";
    // words[221] = "Tunnel";
    // words[222] = "Typewriter";
    // words[223] = "Umbrella";
    // words[224] = "Vacuum";
    // words[225] = "Vampire";
    // words[226] = "Videotape";
    // words[227] = "Water";
    // words[228] = "Web";
    // words[229] = "Window";
    // words[230] = "Worm";
}