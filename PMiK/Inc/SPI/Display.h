//
// Oleksandr "tAtaman" Bolbat
// PMiK project
//

#ifndef DISPLAY_H
#define DISPLAY_H


#ifndef THE_DATA_H
#include "TheData.h"
#endif


typedef struct Display {
    void (*setPixel) (const unsigned char x, const unsigned char y, const COLOR_T color);
} display_t;


void initDisplay(display_t *display);


#endif