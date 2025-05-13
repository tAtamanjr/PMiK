/**
 * \file	TimerCallbackFunctions
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef TIMER_CALLBACK_FUNCTIONS_H
#include "TimerCallbackFunctions.h"


bool joystickDataCallback(__unused struct repeating_timer *t) {
    printf("============\n");
    printf("Joystick:\n");
    printf("\t- X: %d\n", joystick.position[0]);
    printf("\t- Y: %d\n", joystick.position[1]);
    printf("============\n");
    
    return true;
}


#endif
