/**
 * @file	Joystick.h
 * @brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef JOYSTICK_H
#define JOYSTICK_H


#ifndef THE_DATA_H
#include "TheData.h"
#endif

#ifndef COORDINATES_H
#include "Coordinates.h"
#endif


typedef struct Joystick {
    uint16_t position[2];
    direction_e direction;

    void (*update) ();

    coordinates_t cell[2];

    void (*read) ();
    void (*updateCell) ();
} joystick_t;


extern joystick_t joystick;


void initJoystick();


#endif