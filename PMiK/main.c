/**
 * \file	main.c
 * \brief   Project for PMiK, "Programowanie mikrokontrolerów"
 *          Game BattleShips
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef THE_DATA_H
#include "TheData.h"
#endif

#ifndef BYTE_H
#include "Byte.h"
#endif
#ifndef LED_OUT_H
#include "LedOut.h"
#endif
#ifndef JOYSTICK_H
#include "Joystick.h"
#endif
#ifndef DISPLAY_H
#include "Display.h"
#endif
#ifndef VIEWS_H
#include "Views.h"
#endif
#ifndef FIELD_H
#include "Field.h"
#endif
#ifndef NAVY_PLACER_H
#include "NavyPlacer.h"
#endif

#ifndef ALARM_CALLBACK_FUNCTIONS_H
#include "AlarmCallbackFunctions.h"
#endif
#ifndef TIMER_CALLBACK_FUNCTIONS_H
#include "TimerCallbackFunctions.h"
#endif
#ifndef IRQ_CALLBACK_FUNCTIONS_H
#include "IRQCallbackFunctions.h"
#endif


// byte_t states;
ledOut_t ledOut;
joystick_t joystick;
uint8_t joystickMoveDebouncerFlag;
display_t display;
byte_t buttonFlags;
field_t someField;

alarm_id_t mainAlarm;
alarm_id_t confirmAlarm;
alarm_id_t suppAlarm1;
// alarm_id_t suppAlarm2;
alarm_id_t joystickMoveDebouncerAlarm;

struct repeating_timer joystickUpdateTimer;
struct repeating_timer joystickMoveTimer;
struct repeating_timer viewResetter;


void setUp();
void initElements();
void setIRQs();
void startTimers();


int main() {
    setUp();

    setIRQs();
    startTimers();

    while (!placeNavy(&someField))
    sleep_ms(100);
    drawFieldView();
    drawDownMenuElement();
    drawAim();
    updateCoordinates();

    // Sine fine loop
    while (HABEMUS_RES_QUAE_AD_SOLVENDUM_OPUS) tight_loop_contents();
}

void setUp() {
    stdio_init_all();
    sleep_ms(500);

    initElements();
    sleep_ms(500);

    // gpio_init(15);
    // gpio_set_dir(15, GPIO_OUT);
    // gpio_init(14);
    // gpio_set_dir(14, GPIO_OUT);
}

void initElements() {
    initLedOut(&ledOut);
    initJoystick(&joystick);
    initDisplay(&display);

    gpio_init(MAIN_BUTTON);
    gpio_set_dir(MAIN_BUTTON, GPIO_IN);

    gpio_init(CONFIRM_BUTTON);
    gpio_set_dir(CONFIRM_BUTTON, GPIO_IN);

    gpio_init(SUPP_BUTTON_1);
    gpio_set_dir(SUPP_BUTTON_1, GPIO_IN);

    gpio_init(SUPP_BUTTON_2);
    gpio_set_dir(SUPP_BUTTON_2, GPIO_IN);

    initByte(&buttonFlags);
    initField(&someField);
    // initByte(&states);
    joystickMoveDebouncerFlag = 1;
}

void setIRQs() {
    gpio_set_irq_enabled_with_callback(MAIN_BUTTON, GPIO_IRQ_EDGE_FALL, true, &callbackSwitcher);
    gpio_set_irq_enabled(CONFIRM_BUTTON, GPIO_IRQ_EDGE_FALL, true);
    gpio_set_irq_enabled(SUPP_BUTTON_1, GPIO_IRQ_EDGE_FALL, true);
    gpio_set_irq_enabled(SUPP_BUTTON_2, GPIO_IRQ_EDGE_FALL, true);
}

void startTimers() {
    add_repeating_timer_ms(50, joystickDataCallback, NULL, &joystickUpdateTimer);
    add_repeating_timer_ms(50, joystickMoveCallback, NULL, &joystickMoveTimer);
    // add_repeating_timer_ms(1500, viewResetCallback, NULL, &viewResetter);
}
