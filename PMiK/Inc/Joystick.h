//
// Created by Oleksandr Bolbat, PMiK project
// Type for hendling data about state of joystick
//

#if !defined(JOYSTICK_H)
#define JOYSTICK_H


#if !defined(STDLIB_H)
#include "pico/stdlib.h"
#endif
#if !defined(ADC_H)
#include "hardware/adc.h"
#endif

#if !defined(DIRECTION_H)
#include "Direction.h"
#endif


typedef struct Joystick {
    uint16_t xPosition;
    uint16_t yPosition;

    uint8_t ADC_X;
    uint8_t ADC_Y;

    void (*init) (struct Joystick *, const uint8_t, const uint8_t);
    Direction (*read) (struct Joystick *);
} joystick_t;


joystick_t newJoystick();


#endif