/**
 * \file	Joystick.c
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef JOYSTICK_H
#include "Joystick.h"


static void read();
static void updateCell();


void initJoystick() {
    gpio_init(13);

    adc_init();

    adc_gpio_init(JOYSTICK_ADC_X);
    adc_gpio_init(JOYSTICK_ADC_Y);

    joystick.position[0] = 0x8fff;
    joystick.position[1] = 0x8fff;
    joystick.cell->x = randomNumber(0, 9);
    joystick.cell->y = randomNumber(0, 9);
    joystick.direction = NONE;
    joystick.read = read;
    joystick.updateCell = updateCell;
}

static void read() {
    adc_select_input(JOYSTICK_ADC_X);
    joystick.position[0] = adc_read();
    adc_select_input(JOYSTICK_ADC_Y);
    joystick.position[1] = adc_read();

    if (joystick.position[0] >= 3071) {
        if (joystick.position[1] >= 3071) joystick.direction = NE;
        else if (joystick.position[1] <= 1024) joystick.direction = NW;
        else joystick.direction = NP;
    } else if (joystick.position[1] >= 3071) {
        if (joystick.position[0] <= 1024) joystick.direction = SE;
        else joystick.direction = EP;
    } else if (joystick.position[1] <= 1024) {
        if (joystick.position[0] <= 1024) joystick.direction = SW;
        else joystick.direction = WP;
    } else if (joystick.position[0] <= 1024) joystick.direction = SP;
    else joystick.direction = NONE;
}

static void updateCell() {
    switch(joystick.direction) {
        case NE:
            if (joystick.cell->x != J) joystick.cell->x++;
            if (joystick.cell->y != A) joystick.cell->y--;
            break;
        case NP:
            if (joystick.cell->y != A) joystick.cell->y--;
            break;
        case NW:
            if (joystick.cell->x != A) joystick.cell->x--;
            if (joystick.cell->y != A) joystick.cell->y--;
            break;
        case EP:
            if (joystick.cell->x != J) joystick.cell->x++;
            break;
        case WP:
            if (joystick.cell->x != A) joystick.cell->x--;
            break;
        case SE:
            if (joystick.cell->x != J) joystick.cell->x++;
            if (joystick.cell->y != J) joystick.cell->y++;
            break;
        case SP:
            if (joystick.cell->y != J) joystick.cell->y++;
            break;
        case SW:
            if (joystick.cell->x != A) joystick.cell->x--;
            if (joystick.cell->y != J) joystick.cell->y++;
            break;
        default:
            break;
    }
}


#endif