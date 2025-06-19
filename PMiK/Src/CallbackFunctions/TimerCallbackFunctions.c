/**
 * @file	TimerCallbackFunctions.h
 * @brief   Callback functions for timers
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef TIMER_CALLBACK_FUNCTIONS_H
#include "TimerCallbackFunctions.h"


bool joystickDataCallback(struct repeating_timer *t) {
    if (joystickActionDebouncerFlag) {
        joystick.read(&joystick);

        if (joystick.direction == NONE) return true;

        joystickActionDebouncerFlag = 0;
        model.reactOnJoystick();
    }
    return true;
}

bool UIManagerUpdateCallback(struct repeating_timer *t) {
    UIManager.updateView();
    return true;
}


#endif
