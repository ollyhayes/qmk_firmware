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

enum custom_keycodes {
    DOWN3 = SAFE_RANGE,
    UP3,
    CLEFT,
    CRIGHT,
    RAND
};

int wordCount = 231;
const char *words[231];

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
	            //send_string(words[rand() % wordCount]);
				//need to get this out of program space
				//http://www.nongnu.org/avr-libc/user-manual/pgmspace.html
                SEND_STRING(" ");
                return false;
            }
            break;
    }
    return true;
}

void keyboard_pre_init_user(void) {

	words[0] = string_0000;
	words[1] = string_0001;
	words[2] = string_0002;
	words[3] = string_0003;
	words[4] = string_0004;
	words[5] = string_0005;
	words[6] = string_0006;
	words[7] = string_0007;
	words[8] = string_0008;
	words[9] = string_0009;
	words[10] = string_0010;
	words[11] = string_0011;
	words[12] = string_0012;
	words[13] = string_0013;
	words[14] = string_0014;
	words[15] = string_0015;
	words[16] = string_0016;
	words[17] = string_0017;
	words[18] = string_0018;
	words[19] = string_0019;
	words[20] = string_0020;
	words[21] = string_0021;
	words[22] = string_0022;
	words[23] = string_0023;
	words[24] = string_0024;
	words[25] = string_0025;
	words[26] = string_0026;
	words[27] = string_0027;
	words[28] = string_0028;
	words[29] = string_0029;
	words[30] = string_0030;
	words[31] = string_0031;
	words[32] = string_0032;
	words[33] = string_0033;
	words[34] = string_0034;
	words[35] = string_0035;
	words[36] = string_0036;
	words[37] = string_0037;
	words[38] = string_0038;
	words[39] = string_0039;
	words[40] = string_0040;
	words[41] = string_0041;
	words[42] = string_0042;
	words[43] = string_0043;
	words[44] = string_0044;
	words[45] = string_0045;
	words[46] = string_0046;
	words[47] = string_0047;
	words[48] = string_0048;
	words[49] = string_0049;
	words[50] = string_0050;
	words[51] = string_0051;
	words[52] = string_0052;
	words[53] = string_0053;
	words[54] = string_0054;
	words[55] = string_0055;
	words[56] = string_0056;
	words[57] = string_0057;
	words[58] = string_0058;
	words[59] = string_0059;
	words[60] = string_0060;
	words[61] = string_0061;
	words[62] = string_0062;
	words[63] = string_0063;
	words[64] = string_0064;
	words[65] = string_0065;
	words[66] = string_0066;
	words[67] = string_0067;
	words[68] = string_0068;
	words[69] = string_0069;
	words[70] = string_0070;
	words[71] = string_0071;
	words[72] = string_0072;
	words[73] = string_0073;
	words[74] = string_0074;
	words[75] = string_0075;
	words[76] = string_0076;
	words[77] = string_0077;
	words[78] = string_0078;
	words[79] = string_0079;
	words[80] = string_0080;
	words[81] = string_0081;
	words[82] = string_0082;
	words[83] = string_0083;
	words[84] = string_0084;
	words[85] = string_0085;
	words[86] = string_0086;
	words[87] = string_0087;
	words[88] = string_0088;
	words[89] = string_0089;
	words[90] = string_0090;
	words[91] = string_0091;
	words[92] = string_0092;
	words[93] = string_0093;
	words[94] = string_0094;
	words[95] = string_0095;
	words[96] = string_0096;
	words[97] = string_0097;
	words[98] = string_0098;
	words[99] = string_0099;
	words[100] = string_0100;
	words[101] = string_0101;
	words[102] = string_0102;
	words[103] = string_0103;
	words[104] = string_0104;
	words[105] = string_0105;
	words[106] = string_0106;
	words[107] = string_0107;
	words[108] = string_0108;
	words[109] = string_0109;
	words[110] = string_0110;
	words[111] = string_0111;
	words[112] = string_0112;
	words[113] = string_0113;
	words[114] = string_0114;
	words[115] = string_0115;
	words[116] = string_0116;
	words[117] = string_0117;
	words[118] = string_0118;
	words[119] = string_0119;
	words[120] = string_0120;
	words[121] = string_0121;
	words[122] = string_0122;
	words[123] = string_0123;
	words[124] = string_0124;
	words[125] = string_0125;
	words[126] = string_0126;
	words[127] = string_0127;
	words[128] = string_0128;
	words[129] = string_0129;
	words[130] = string_0130;
	words[131] = string_0131;
	words[132] = string_0132;
	words[133] = string_0133;
	words[134] = string_0134;
	words[135] = string_0135;
	words[136] = string_0136;
	words[137] = string_0137;
	words[138] = string_0138;
	words[139] = string_0139;
	words[140] = string_0140;
	words[141] = string_0141;
	words[142] = string_0142;
	words[143] = string_0143;
	words[144] = string_0144;
	words[145] = string_0145;
	words[146] = string_0146;
	words[147] = string_0147;
	words[148] = string_0148;
	words[149] = string_0149;
	words[150] = string_0150;
	words[151] = string_0151;
	words[152] = string_0152;
	words[153] = string_0153;
	words[154] = string_0154;
	words[155] = string_0155;
	words[156] = string_0156;
	words[157] = string_0157;
	words[158] = string_0158;
	words[159] = string_0159;
	words[160] = string_0160;
	words[161] = string_0161;
	words[162] = string_0162;
	words[163] = string_0163;
	words[164] = string_0164;
	words[165] = string_0165;
	words[166] = string_0166;
	words[167] = string_0167;
	words[168] = string_0168;
	words[169] = string_0169;
	words[170] = string_0170;
	words[171] = string_0171;
	words[172] = string_0172;
	words[173] = string_0173;
	words[174] = string_0174;
	words[175] = string_0175;
	words[176] = string_0176;
	words[177] = string_0177;
	words[178] = string_0178;
	words[179] = string_0179;
	words[180] = string_0180;
	words[181] = string_0181;
	words[182] = string_0182;
	words[183] = string_0183;
	words[184] = string_0184;
	words[185] = string_0185;
	words[186] = string_0186;
	words[187] = string_0187;
	words[188] = string_0188;
	words[189] = string_0189;
	words[190] = string_0190;
	words[191] = string_0191;
	words[192] = string_0192;
	words[193] = string_0193;
	words[194] = string_0194;
	words[195] = string_0195;
	words[196] = string_0196;
	words[197] = string_0197;
	words[198] = string_0198;
	words[199] = string_0199;
	words[200] = string_0200;
	words[201] = string_0201;
	words[202] = string_0202;
	words[203] = string_0203;
	words[204] = string_0204;
	words[205] = string_0205;
	words[206] = string_0206;
	words[207] = string_0207;
	words[208] = string_0208;
	words[209] = string_0209;
	words[210] = string_0210;
	words[211] = string_0211;
	words[212] = string_0212;
	words[213] = string_0213;
	words[214] = string_0214;
	words[215] = string_0215;
	words[216] = string_0216;
	words[217] = string_0217;
	words[218] = string_0218;
	words[219] = string_0219;
	words[220] = string_0220;
	words[221] = string_0221;
	words[222] = string_0222;
	words[223] = string_0223;
	words[224] = string_0224;
	words[225] = string_0225;
	words[226] = string_0226;
	words[227] = string_0227;
	words[228] = string_0228;
	words[229] = string_0229;
	words[230] = string_0230;

}