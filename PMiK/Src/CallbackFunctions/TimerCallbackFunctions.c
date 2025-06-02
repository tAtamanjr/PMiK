/**
 * \file	TimerCallbackFunctions.h
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef TIMER_CALLBACK_FUNCTIONS_H
#include "TimerCallbackFunctions.h"


bool joystickDataCallback(struct repeating_timer *t) {
    if (joystickMoveDebouncerFlag) {
        joystick.read(&joystick);

        if (joystick.direction == NONE) return true;

        joystickMoveDebouncerFlag = 0;
        joystickMoveDebouncerAlarm = add_alarm_in_ms(150, joystickMoveDebouncerCallback, NULL, false);
        UIManager.setSmallChanges(0);
    }

    return true;
}

bool UIManagerUpdateCallback(struct repeating_timer *t) {
    UIManager.updateView();
    return true;
}


#endif
