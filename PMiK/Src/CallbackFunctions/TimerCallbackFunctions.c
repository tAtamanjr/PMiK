/**
 * @file	TimerCallbackFunctions.c
 * @brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef TIMER_CALLBACK_FUNCTIONS_H
#include "TimerCallbackFunctions.h"


bool updateJoystickDataCallback(struct repeating_timer *t) {
    if (!inputModulesFlags.joystickActionDebouncerFlag()) {
        joystick.update(&joystick);

        if (joystick.direction == NONE) return true;

        inputModulesFlags.setOnJoystickActionDebouncerFlag();
    }
    return true;
}

bool updateUIManagerCallback(struct repeating_timer *t) {
    UIManager.updateView();
    return true;
}

bool updateGameDataCallback(struct repeating_timer *t) {
    return true;
}

bool debuggCallback(struct repeating_timer *t) {
    printf("Joystick: %d, %d\n", joystick.position[0], joystick.position[1]);
    printf("Flags: %d\n", inputModulesFlags.flags);

    return true;
}


bool joystickDataCallback(struct repeating_timer *t) {
    if (!inputModulesFlags.joystickActionDebouncerFlag()) {
        joystick.read(&joystick);

        if (joystick.direction == NONE) return true;

        inputModulesFlags.setOnJoystickActionDebouncerFlag();
        model.reactOnJoystick();
    }
    return true;
}

bool UIManagerUpdateCallback(struct repeating_timer *t) {
    UIManager.updateView();
    return true;
}


#endif
