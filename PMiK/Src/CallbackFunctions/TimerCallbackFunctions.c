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
    // states.reset(&states);
    joystick.read(&joystick);

    // switch (joystick.direction) {
    //     case NE:
    //         states.on(&states, 2);
    //         states.on(&states, 1);
    //         states.on(&states, 0);
    //         break;
    //     case NP:
    //         states.on(&states, 2);
    //         states.on(&states, 1);
    //         break;
    //     case NW:
    //         states.on(&states, 2);
    //         states.on(&states, 0);
    //         break;
    //     case EP:
    //         states.on(&states, 2);
    //         break;
    //     case WP:
    //         states.on(&states, 1);
    //         states.on(&states, 0);
    //         break;
    //     case SE:
    //         states.on(&states, 1);
    //         break;
    //     case SP:
    //         states.on(&states, 0);
    //         break;
    //     case SW:
    //         break;
    //     default:
    //         break;
    // }

    // ledOut.set(states.read(&states, 2));
    // gpio_put(15, states.read(&states, 1));
    // gpio_put(14, states.read(&states, 0));
    
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
        
        removeAim(joystick.cell[0], joystick.cell[1]);
        switch(joystick.direction) {
            case NE:
                if (joystick.cell[0] != J) joystick.cell[0]++;
                if (joystick.cell[1] != A) joystick.cell[1]--;
                break;
            case NP:
                if (joystick.cell[1] != A) joystick.cell[1]--;
                break;
            case NW:
                if (joystick.cell[0] != A) joystick.cell[0]--;
                if (joystick.cell[1] != A) joystick.cell[1]--;
                break;
            case EP:
                if (joystick.cell[0] != J) joystick.cell[0]++;
                break;
            case WP:
                if (joystick.cell[0] != A) joystick.cell[0]--;
                break;
            case SE:
                if (joystick.cell[0] != J) joystick.cell[0]++;
                if (joystick.cell[1] != J) joystick.cell[1]++;
                break;
            case SP:
                if (joystick.cell[1] != J) joystick.cell[1]++;
                break;
            case SW:
                if (joystick.cell[0] != A) joystick.cell[0]--;
                if (joystick.cell[1] != J) joystick.cell[1]++;
                break;
            default:
                break;
        }
        drawAim(joystick.cell[0], joystick.cell[1]);
    }
}


#endif
