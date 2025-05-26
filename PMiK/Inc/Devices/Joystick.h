/**
 * \file	Joystick.h
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#if !defined(JOYSTICK_H)
#define JOYSTICK_H


#ifndef THE_DATA_H
#include "TheData.h"
#endif


typedef struct Joystick {
    uint16_t position[2];
    uint8_t cell[2];
    direction_e direction;

    void (*read) (struct Joystick *joystick);
} joystick_t;


extern joystick_t joystick;


void initJoystick(joystick_t *joystick);


#endif