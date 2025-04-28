//
// Oleksandr "tAtaman" Bolbat
// PMiK project
//

#if !defined(JOYSTICK_H)
#define JOYSTICK_H


#ifndef THE_DATA_H
#include "TheData.h"
#endif


typedef struct Joystick {
    uint16_t position[2];
    direction_e direction;

    void (*read) (struct Joystick *joystick);
} joystick_t;


void initJoystick(joystick_t *joystick);


#endif