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
    joystick.read(&joystick);
    return true;
}

bool viewResetCallback(struct repeating_timer *t) {
    drawFieldView();

    for (uint i = 0; i < 3; i++) {
        switch (randomNumber(0, 1)) {
            case 0:
                drawBoatHorizontal(randomNumber(0, 9), randomNumber(0, 9));
                break;
            case 1:
                drawBoatVertical(randomNumber(0, 9), randomNumber(0, 9));
                break;
            default:
                break;
        }
    }

    drawAim(randomNumber(0, 9), randomNumber(0, 9));

    drawDownMenuElement();

    return true;
}

bool joystickMoveCallback(struct repeating_timer *t) {
    if (joystickMoveDebouncerFlag && joystick.direction != NONE) {
        joystickMoveDebouncerFlag = 0;
        joystickMoveDebouncerAlarm = add_alarm_in_ms(150, joystickMoveDebouncerCallback, NULL, false);
        
        removeAim();
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
        drawAim();
        updateCoordinates();
    }
}


#endif
