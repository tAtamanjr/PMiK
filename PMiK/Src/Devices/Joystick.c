/**
 * \file	Joystick.c
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef JOYSTICK_H
#include "Joystick.h"


static void read(joystick_t *);


void initJoystick(joystick_t *joystick) {
    gpio_init(13);

    adc_init();

    adc_gpio_init(JOYSTICK_ADC_X);
    adc_gpio_init(JOYSTICK_ADC_Y);

    joystick->position[0] = 0x8fff;
    joystick->position[1] = 0x8fff;
    joystick->cell[0] = 0x00;
    joystick->cell[1] = 0x00;
    joystick->direction = NONE;
    joystick->read = read;
}

static void read(joystick_t *joystick) {
    adc_select_input(JOYSTICK_ADC_X);
    joystick->position[0] = adc_read();
    adc_select_input(JOYSTICK_ADC_Y);
    joystick->position[1] = adc_read();

    if (joystick->position[0] >= 3071) {
        if (joystick->position[1] >= 3071) joystick->direction = NE;
        else if (joystick->position[1] <= 1024) joystick->direction = NW;
        else joystick->direction = NP;
    } else if (joystick->position[1] >= 3071) {
        if (joystick->position[0] <= 1024) joystick->direction = SE;
        else joystick->direction = EP;
    } else if (joystick->position[1] <= 1024) {
        if (joystick->position[0] <= 1024) joystick->direction = SW;
        else joystick->direction = WP;
    } else if (joystick->position[0] <= 1024) joystick->direction = SP;
    else joystick->direction = NONE;
}


#endif