/**
 * \file	TimerCallbackFunctions
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef TIMER_CALLBACK_FUNCTIONS_H
#include "TimerCallbackFunctions.h"


bool joystickDataCallback(struct repeating_timer *t) {
    printf("============\n");
    printf("Joystick:\n");
    printf("\t- X: %d\n", joystick.position[0]);
    printf("\t- Y: %d\n", joystick.position[1]);
    printf("============\n");
    
    return true;
}

bool viewResetCallback(struct repeating_timer *t) {
    drawFieldView(&display);

    drawBoat(&display, randomNumber(0, 9), randomNumber(0, 9));
    drawBoat(&display, randomNumber(0, 9), randomNumber(0, 9));
    drawBoat(&display, randomNumber(0, 9), randomNumber(0, 9));

    return true;
}


#endif
