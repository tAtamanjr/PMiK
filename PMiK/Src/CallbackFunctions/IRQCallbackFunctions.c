/**
 * \file	IRQCallbackFunctions.c
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef IRQ_CALLBACK_FUNCTIONS_H
#include "IRQCallbackFunctions.h" 


static void resetNavyCallback();
// static void mainButtonCallback(uint32_t events);
// static void confirmButtonCallback(uint32_t events);
// static void supp1ButtonCallback(uint32_t events);
// static void supp2ButtonCallback(uint32_t events);


void callbackSwitcher(uint gpio, uint32_t events) {
    switch (gpio) {
        case MAIN_BUTTON:
            // mainButtonCallback(events);
            resetNavyCallback();
            // printf("Main button\n");
            break;
        case CONFIRM_BUTTON:
            // confirmButtonCallback(events);
            printf("Confirm button\n");
            break;
        case SUPP_BUTTON_1:
            // supp1ButtonCallback(events);
            printf("Supp button 1\n");
            break;
        case SUPP_BUTTON_2:
            // supp2ButtonCallback(events);
            printf("Supp button 2\n");
            break;
        default:
            break;
    }
}

static void resetNavyCallback() {
    if (resetNavyDebouncerFlag) {
        resetNavyDebouncerFlag = 0;
        joystickMoveDebouncerAlarm = add_alarm_in_ms(1000, resetNavyDebouncerCallback, NULL, false);

        while (!placeNavy(&someField))
        UIManager.setSmallChanges(1);
    }
}

// static void mainButtonCallback(uint32_t events) {
//     if (buttonFlags.read(&buttonFlags, MAIN_WAIT_BIT)) { 
//         printf("Button moment\n");
//         return;
//     }
//     buttonFlags.on(&buttonFlags, MAIN_WAIT_BIT);

//     mainAlarm = add_alarm_in_ms(100, confirmButtonAlarmCallback, NULL, false);

//     printf("Main button\n");
// }

// static void confirmButtonCallback(uint32_t events) {
//     if (buttonFlags.read(&buttonFlags, CONFIRM_WAIT_BIT)) { 
//         printf("Button moment\n");
//         return;
//     }
//     buttonFlags.on(&buttonFlags, CONFIRM_WAIT_BIT);

//     confirmAlarm = add_alarm_in_ms(100, suppButton1AlarmCallback, NULL, false);
    
//     printf("Confirm button\n");
// }

// static void supp1ButtonCallback(uint32_t events) {
//     if (buttonFlags.read(&buttonFlags, SUPP1_WAIT_BIT)) { 
//         printf("Button moment\n");
//         return;
//     }
//     buttonFlags.on(&buttonFlags, SUPP1_WAIT_BIT);

//     suppAlarm1 = add_alarm_in_ms(100, suppButton2AlarmCallback, NULL, false);

//     printf("Supp button 1\n");
// }

// static void supp2ButtonCallback(uint32_t events) {
//     if (buttonFlags.read(&buttonFlags, SUPP2_WAIT_BIT)) return;
//     buttonFlags.on(&buttonFlags, SUPP2_WAIT_BIT);

//     suppAlarm2 = add_alarm_in_ms(100, suppButton2AlarmCallback, NULL, false);

//     printf("Supp button 2\n");
// }


#endif
