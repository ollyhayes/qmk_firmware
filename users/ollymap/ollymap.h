#include "quantum.h"

#define BASE 0
#define QWERTY 1
#define NUM 2
#define FUNCTIONS 3
#define ARR 4
#define PUNC 5
#define MEDIA 6
#define _ADJUST 7

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
  ESZET
};

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

int RGB_current_mode;