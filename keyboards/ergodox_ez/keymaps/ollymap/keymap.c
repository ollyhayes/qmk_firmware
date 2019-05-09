#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include <avr/pgmspace.h>

#define BASE 0 // default layer
#define NUM 1 // symbols
#define FUNCTIONS 2 // symbols
#define ARR 3 // symbols

typedef enum onoff_t {OFF, ON} onoff;

const char string_0000[] PROGMEM = "Adult";
const char string_0001[] PROGMEM = "Aeroplane";
const char string_0002[] PROGMEM = "Air";
const char string_0003[] PROGMEM = "Aircraft Carrier";
const char string_0004[] PROGMEM = "Airforce";
const char string_0005[] PROGMEM = "Airport";
const char string_0006[] PROGMEM = "Album";
const char string_0007[] PROGMEM = "Alphabet";
const char string_0008[] PROGMEM = "Apple";
const char string_0009[] PROGMEM = "Arm";
const char string_0010[] PROGMEM = "Army";
const char string_0011[] PROGMEM = "Baby";
const char string_0012[] PROGMEM = "Baby";
const char string_0013[] PROGMEM = "Backpack";
const char string_0014[] PROGMEM = "Balloon";
const char string_0015[] PROGMEM = "Banana";
const char string_0016[] PROGMEM = "Bank";
const char string_0017[] PROGMEM = "Barbecue";
const char string_0018[] PROGMEM = "Bathroom";
const char string_0019[] PROGMEM = "Bathtub";
const char string_0020[] PROGMEM = "Bed";
const char string_0021[] PROGMEM = "Bed";
const char string_0022[] PROGMEM = "Bee";
const char string_0023[] PROGMEM = "Bible";
const char string_0024[] PROGMEM = "Bible";
const char string_0025[] PROGMEM = "Bird";
const char string_0026[] PROGMEM = "Bomb";
const char string_0027[] PROGMEM = "Book";
const char string_0028[] PROGMEM = "Boss";
const char string_0029[] PROGMEM = "Bottle";
const char string_0030[] PROGMEM = "Bowl";
const char string_0031[] PROGMEM = "Box";
const char string_0032[] PROGMEM = "Boy";
const char string_0033[] PROGMEM = "Brain";
const char string_0034[] PROGMEM = "Bridge";
const char string_0035[] PROGMEM = "Butterfly";
const char string_0036[] PROGMEM = "Button";
const char string_0037[] PROGMEM = "Cappuccino";
const char string_0038[] PROGMEM = "Car";
const char string_0039[] PROGMEM = "Car-race";
const char string_0040[] PROGMEM = "Carpet";
const char string_0041[] PROGMEM = "Carrot";
const char string_0042[] PROGMEM = "Cave";
const char string_0043[] PROGMEM = "Chair";
const char string_0044[] PROGMEM = "Chess Board";
const char string_0045[] PROGMEM = "Chief";
const char string_0046[] PROGMEM = "Child";
const char string_0047[] PROGMEM = "Chisel";
const char string_0048[] PROGMEM = "Chocolates";
const char string_0049[] PROGMEM = "Church";
const char string_0050[] PROGMEM = "Church";
const char string_0051[] PROGMEM = "Circle";
const char string_0052[] PROGMEM = "Circus";
const char string_0053[] PROGMEM = "Circus";
const char string_0054[] PROGMEM = "Clock";
const char string_0055[] PROGMEM = "Clown";
const char string_0056[] PROGMEM = "Coffee";
const char string_0057[] PROGMEM = "Coffee-shop";
const char string_0058[] PROGMEM = "Comet";
const char string_0059[] PROGMEM = "Compact Disc";
const char string_0060[] PROGMEM = "Compass";
const char string_0061[] PROGMEM = "Computer";
const char string_0062[] PROGMEM = "Crystal";
const char string_0063[] PROGMEM = "Cup";
const char string_0064[] PROGMEM = "Cycle";
const char string_0065[] PROGMEM = "Data Base";
const char string_0066[] PROGMEM = "Desk";
const char string_0067[] PROGMEM = "Diamond";
const char string_0068[] PROGMEM = "Dress";
const char string_0069[] PROGMEM = "Drill";
const char string_0070[] PROGMEM = "Drink";
const char string_0071[] PROGMEM = "Drum";
const char string_0072[] PROGMEM = "Dung";
const char string_0073[] PROGMEM = "Ears";
const char string_0074[] PROGMEM = "Earth";
const char string_0075[] PROGMEM = "Egg";
const char string_0076[] PROGMEM = "Electricity";
const char string_0077[] PROGMEM = "Elephant";
const char string_0078[] PROGMEM = "Eraser";
const char string_0079[] PROGMEM = "Explosive";
const char string_0080[] PROGMEM = "Eyes";
const char string_0081[] PROGMEM = "Family";
const char string_0082[] PROGMEM = "Fan";
const char string_0083[] PROGMEM = "Feather";
const char string_0084[] PROGMEM = "Festival";
const char string_0085[] PROGMEM = "Film";
const char string_0086[] PROGMEM = "Finger";
const char string_0087[] PROGMEM = "Fire";
const char string_0088[] PROGMEM = "Floodlight";
const char string_0089[] PROGMEM = "Flower";
const char string_0090[] PROGMEM = "Foot";
const char string_0091[] PROGMEM = "Fork";
const char string_0092[] PROGMEM = "Freeway";
const char string_0093[] PROGMEM = "Fruit";
const char string_0094[] PROGMEM = "Fungus";
const char string_0095[] PROGMEM = "Game";
const char string_0096[] PROGMEM = "Garden";
const char string_0097[] PROGMEM = "Gas";
const char string_0098[] PROGMEM = "Gate";
const char string_0099[] PROGMEM = "Gemstone";
const char string_0100[] PROGMEM = "Girl";
const char string_0101[] PROGMEM = "Gloves";
const char string_0102[] PROGMEM = "God";
const char string_0103[] PROGMEM = "Grapes";
const char string_0104[] PROGMEM = "Guitar";
const char string_0105[] PROGMEM = "Hammer";
const char string_0106[] PROGMEM = "Hat";
const char string_0107[] PROGMEM = "Hieroglyph";
const char string_0108[] PROGMEM = "Highway";
const char string_0109[] PROGMEM = "Horoscope";
const char string_0110[] PROGMEM = "Horse";
const char string_0111[] PROGMEM = "Hose";
const char string_0112[] PROGMEM = "Ice";
const char string_0113[] PROGMEM = "Ice-cream";
const char string_0114[] PROGMEM = "Insect";
const char string_0115[] PROGMEM = "Jet fighter";
const char string_0116[] PROGMEM = "Junk";
const char string_0117[] PROGMEM = "Kaleidoscope";
const char string_0118[] PROGMEM = "Kitchen";
const char string_0119[] PROGMEM = "Knife";
const char string_0120[] PROGMEM = "Leather jacket";
const char string_0121[] PROGMEM = "Leg";
const char string_0122[] PROGMEM = "Library";
const char string_0123[] PROGMEM = "Liquid";
const char string_0124[] PROGMEM = "Magnet";
const char string_0125[] PROGMEM = "Man";
const char string_0126[] PROGMEM = "Map";
const char string_0127[] PROGMEM = "Maze";
const char string_0128[] PROGMEM = "Meat";
const char string_0129[] PROGMEM = "Meteor";
const char string_0130[] PROGMEM = "Microscope";
const char string_0131[] PROGMEM = "Milk";
const char string_0132[] PROGMEM = "Milkshake";
const char string_0133[] PROGMEM = "Mist";
const char string_0134[] PROGMEM = "Money $$$$";
const char string_0135[] PROGMEM = "Monster";
const char string_0136[] PROGMEM = "Mosquito";
const char string_0137[] PROGMEM = "Mouth";
const char string_0138[] PROGMEM = "Nail";
const char string_0139[] PROGMEM = "Navy";
const char string_0140[] PROGMEM = "Necklace";
const char string_0141[] PROGMEM = "Needle";
const char string_0142[] PROGMEM = "Onion";
const char string_0143[] PROGMEM = "PaintBrush";
const char string_0144[] PROGMEM = "Pants";
const char string_0145[] PROGMEM = "Parachute";
const char string_0146[] PROGMEM = "Passport";
const char string_0147[] PROGMEM = "Pebble";
const char string_0148[] PROGMEM = "Pendulum";
const char string_0149[] PROGMEM = "Pepper";
const char string_0150[] PROGMEM = "Perfume";
const char string_0151[] PROGMEM = "Pillow";
const char string_0152[] PROGMEM = "Plane";
const char string_0153[] PROGMEM = "Planet";
const char string_0154[] PROGMEM = "Pocket";
const char string_0155[] PROGMEM = "Post-office";
const char string_0156[] PROGMEM = "Potato";
const char string_0157[] PROGMEM = "Printer";
const char string_0158[] PROGMEM = "Prison";
const char string_0159[] PROGMEM = "Pyramid";
const char string_0160[] PROGMEM = "Radar";
const char string_0161[] PROGMEM = "Rainbow";
const char string_0162[] PROGMEM = "Record";
const char string_0163[] PROGMEM = "Restaurant";
const char string_0164[] PROGMEM = "Rifle";
const char string_0165[] PROGMEM = "Ring";
const char string_0166[] PROGMEM = "Robot";
const char string_0167[] PROGMEM = "Rock";
const char string_0168[] PROGMEM = "Rocket";
const char string_0169[] PROGMEM = "Roof";
const char string_0170[] PROGMEM = "Room";
const char string_0171[] PROGMEM = "Rope";
const char string_0172[] PROGMEM = "Saddle";
const char string_0173[] PROGMEM = "Salt";
const char string_0174[] PROGMEM = "Sandpaper";
const char string_0175[] PROGMEM = "Sandwich";
const char string_0176[] PROGMEM = "Satellite";
const char string_0177[] PROGMEM = "School";
const char string_0178[] PROGMEM = "Sex";
const char string_0179[] PROGMEM = "Ship";
const char string_0180[] PROGMEM = "Shoes";
const char string_0181[] PROGMEM = "Shop";
const char string_0182[] PROGMEM = "Shower";
const char string_0183[] PROGMEM = "Signature";
const char string_0184[] PROGMEM = "Skeleton";
const char string_0185[] PROGMEM = "Slave";
const char string_0186[] PROGMEM = "Snail";
const char string_0187[] PROGMEM = "Software";
const char string_0188[] PROGMEM = "Solid";
const char string_0189[] PROGMEM = "Space Shuttle";
const char string_0190[] PROGMEM = "Spectrum";
const char string_0191[] PROGMEM = "Sphere";
const char string_0192[] PROGMEM = "Spice";
const char string_0193[] PROGMEM = "Spiral";
const char string_0194[] PROGMEM = "Spoon";
const char string_0195[] PROGMEM = "Sports-car";
const char string_0196[] PROGMEM = "Spot Light";
const char string_0197[] PROGMEM = "Square";
const char string_0198[] PROGMEM = "Staircase";
const char string_0199[] PROGMEM = "Star";
const char string_0200[] PROGMEM = "Stomach";
const char string_0201[] PROGMEM = "Sun";
const char string_0202[] PROGMEM = "Sunglasses";
const char string_0203[] PROGMEM = "Surveyor";
const char string_0204[] PROGMEM = "Swimming Pool";
const char string_0205[] PROGMEM = "Sword";
const char string_0206[] PROGMEM = "Table";
const char string_0207[] PROGMEM = "Tapestry";
const char string_0208[] PROGMEM = "Teeth";
const char string_0209[] PROGMEM = "Telescope";
const char string_0210[] PROGMEM = "Television";
const char string_0211[] PROGMEM = "Tennis racquet";
const char string_0212[] PROGMEM = "Thermometer";
const char string_0213[] PROGMEM = "Tiger";
const char string_0214[] PROGMEM = "Toilet";
const char string_0215[] PROGMEM = "Tongue";
const char string_0216[] PROGMEM = "Torch";
const char string_0217[] PROGMEM = "Torpedo";
const char string_0218[] PROGMEM = "Train";
const char string_0219[] PROGMEM = "Treadmill";
const char string_0220[] PROGMEM = "Triangle";
const char string_0221[] PROGMEM = "Tunnel";
const char string_0222[] PROGMEM = "Typewriter";
const char string_0223[] PROGMEM = "Umbrella";
const char string_0224[] PROGMEM = "Vacuum";
const char string_0225[] PROGMEM = "Vampire";
const char string_0226[] PROGMEM = "Videotape";
const char string_0227[] PROGMEM = "Water";
const char string_0228[] PROGMEM = "Web";
const char string_0229[] PROGMEM = "Window";
const char string_0230[] PROGMEM = "Worm";

PGM_P const words_table[] PROGMEM =
{
	string_0000,
	string_0001,
	string_0002,
	string_0003,
	string_0004,
	string_0005,
	string_0006,
	string_0007,
	string_0008,
	string_0009,
	string_0010,
	string_0011,
	string_0012,
	string_0013,
	string_0014,
	string_0015,
	string_0016,
	string_0017,
	string_0018,
	string_0019,
	string_0020,
	string_0021,
	string_0022,
	string_0023,
	string_0024,
	string_0025,
	string_0026,
	string_0027,
	string_0028,
	string_0029,
	string_0030,
	string_0031,
	string_0032,
	string_0033,
	string_0034,
	string_0035,
	string_0036,
	string_0037,
	string_0038,
	string_0039,
	string_0040,
	string_0041,
	string_0042,
	string_0043,
	string_0044,
	string_0045,
	string_0046,
	string_0047,
	string_0048,
	string_0049,
	string_0050,
	string_0051,
	string_0052,
	string_0053,
	string_0054,
	string_0055,
	string_0056,
	string_0057,
	string_0058,
	string_0059,
	string_0060,
	string_0061,
	string_0062,
	string_0063,
	string_0064,
	string_0065,
	string_0066,
	string_0067,
	string_0068,
	string_0069,
	string_0070,
	string_0071,
	string_0072,
	string_0073,
	string_0074,
	string_0075,
	string_0076,
	string_0077,
	string_0078,
	string_0079,
	string_0080,
	string_0081,
	string_0082,
	string_0083,
	string_0084,
	string_0085,
	string_0086,
	string_0087,
	string_0088,
	string_0089,
	string_0090,
	string_0091,
	string_0092,
	string_0093,
	string_0094,
	string_0095,
	string_0096,
	string_0097,
	string_0098,
	string_0099,
	string_0100,
	string_0101,
	string_0102,
	string_0103,
	string_0104,
	string_0105,
	string_0106,
	string_0107,
	string_0108,
	string_0109,
	string_0110,
	string_0111,
	string_0112,
	string_0113,
	string_0114,
	string_0115,
	string_0116,
	string_0117,
	string_0118,
	string_0119,
	string_0120,
	string_0121,
	string_0122,
	string_0123,
	string_0124,
	string_0125,
	string_0126,
	string_0127,
	string_0128,
	string_0129,
	string_0130,
	string_0131,
	string_0132,
	string_0133,
	string_0134,
	string_0135,
	string_0136,
	string_0137,
	string_0138,
	string_0139,
	string_0140,
	string_0141,
	string_0142,
	string_0143,
	string_0144,
	string_0145,
	string_0146,
	string_0147,
	string_0148,
	string_0149,
	string_0150,
	string_0151,
	string_0152,
	string_0153,
	string_0154,
	string_0155,
	string_0156,
	string_0157,
	string_0158,
	string_0159,
	string_0160,
	string_0161,
	string_0162,
	string_0163,
	string_0164,
	string_0165,
	string_0166,
	string_0167,
	string_0168,
	string_0169,
	string_0170,
	string_0171,
	string_0172,
	string_0173,
	string_0174,
	string_0175,
	string_0176,
	string_0177,
	string_0178,
	string_0179,
	string_0180,
	string_0181,
	string_0182,
	string_0183,
	string_0184,
	string_0185,
	string_0186,
	string_0187,
	string_0188,
	string_0189,
	string_0190,
	string_0191,
	string_0192,
	string_0193,
	string_0194,
	string_0195,
	string_0196,
	string_0197,
	string_0198,
	string_0199,
	string_0200,
	string_0201,
	string_0202,
	string_0203,
	string_0204,
	string_0205,
	string_0206,
	string_0207,
	string_0208,
	string_0209,
	string_0210,
	string_0211,
	string_0212,
	string_0213,
	string_0214,
	string_0215,
	string_0216,
	string_0217,
	string_0218,
	string_0219,
	string_0220,
	string_0221,
	string_0222,
	string_0223,
	string_0224,
	string_0225,
	string_0226,
	string_0227,
	string_0228,
	string_0229,
	string_0230
};

int wordCount = 231;

enum custom_keycodes {
    DOWN3 = SAFE_RANGE,
    UP3,
    CLEFT,
    CRIGHT,
    RAND
};

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
    }
    return true;
}