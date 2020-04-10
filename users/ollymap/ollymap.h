#include "quantum.h"

#define BASE 0
#define QWERTY 1
#define GAMES 2
#define NUM 3
#define FUNCTIONS 4
#define ARR 5
#define PUNC 6
#define DUBPUNC 7
#define MEDIA 8
#define _ADJUST 9

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
  RGBRST,
  ESZET,
  A_UMLAUT,
  O_UMLAUT,
  U_UMLAUT,
  EURO,
  POUND,
  DEGREES,
  TICKING,
  CROSS,
  TERROR,
};

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

int RGB_current_mode;