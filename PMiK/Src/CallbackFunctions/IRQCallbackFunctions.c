/**
 * \file	IRQCallbackFunctions.c
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef IRQ_CALLBACK_FUNCTIONS_H
#include "IRQCallbackFunctions.h" 


void callbackSwitcher(uint gpio, uint32_t events) {
    switch (gpio) {
        case MAIN_BUTTON:
            mainButtonCallback(events);
            break;
        case CONFIRM_BUTTON:
            confirmButtonCallback(events);
            break;
        case SUPP_BUTTON_1:
            supp1ButtonCallback(events);
            break;
        case SUPP_BUTTON_2:
            supp2ButtonCallback(events);
            break;
        default:
            break;
    }
}


void mainButtonCallback(uint32_t events) {
    if (buttonFlags.read(&buttonFlags, MAIN_WAIT_BIT)) { 
        printf("Button moment\n");
        return;
    }
    buttonFlags.on(&buttonFlags, MAIN_WAIT_BIT);

    mainAlarm = add_alarm_in_ms(100, confirmButtonAlarmCallback, NULL, false);

    printf("Main button\n");
}

void confirmButtonCallback(uint32_t events) {
    if (buttonFlags.read(&buttonFlags, CONFIRM_WAIT_BIT)) { 
        printf("Button moment\n");
        return;
    }
    buttonFlags.on(&buttonFlags, CONFIRM_WAIT_BIT);

    confirmAlarm = add_alarm_in_ms(100, suppButton1AlarmCallback, NULL, false);
    
    printf("Confirm button\n");
}

void supp1ButtonCallback(uint32_t events) {
    if (buttonFlags.read(&buttonFlags, SUPP1_WAIT_BIT)) { 
        printf("Button moment\n");
        return;
    }
    buttonFlags.on(&buttonFlags, SUPP1_WAIT_BIT);

    suppAlarm1 = add_alarm_in_ms(100, suppButton2AlarmCallback, NULL, false);

    printf("Supp button 1\n");
}

void supp2ButtonCallback(uint32_t events) {
    if (buttonFlags.read(&buttonFlags, SUPP2_WAIT_BIT)) return;
    buttonFlags.on(&buttonFlags, SUPP2_WAIT_BIT);

    suppAlarm2 = add_alarm_in_ms(100, suppButton2AlarmCallback, NULL, false);

    printf("Supp button 2\n");
}


#endif
