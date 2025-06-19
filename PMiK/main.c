/**
 * @file	main.c
 * @brief   Project for PMiK, "Programowanie mikrokontrolerów"
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
#include "UIElements.h"
#endif
#ifndef FIELD_H
#include "Field.h"
#endif
#ifndef NAVY_PLACER_H
#include "NavyPlacer.h"
#endif
#ifndef UI_MANAGER_H
#include "UIManager.h"
#endif
#ifndef NAVIGATION_DATA_H
#include "NavigationData.h"
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


uint8_t viewChangeButtonDebouncerFlag;
uint8_t mainActionButtonDebouncerFlag;
uint8_t additionalActionButtonDebouncerFlag;
alarm_id_t viewChangeButtonDebouncerAlarm;
alarm_id_t mainActionButtonDebouncerAlarm;
alarm_id_t additionalActionButtonDebouncerAlarm;

// byte_t states;
ledOut_t ledOut;
joystick_t joystick;
uint8_t joystickActionDebouncerFlag;
uint8_t resetNavyDebouncerFlag;
uint8_t fireDebouncerFlag;
display_t display;
byte_t buttonFlags;
field_t someField;
UIManager_t UIManager;
model_t model;
navigationData_t navigationData;

alarm_id_t mainAlarm;
alarm_id_t confirmAlarm;
alarm_id_t suppAlarm1;
alarm_id_t joystickActionDebouncerAlarm;
alarm_id_t resetNavyDebouncerAlarm;
alarm_id_t fireDebouncerAlarm;

struct repeating_timer UIManagerUpdater;
struct repeating_timer joystickUpdateTimer;
struct repeating_timer joystickMoveTimer;
struct repeating_timer viewResetter;


void setUp();
void initElements();
void setIRQs();
void startTimers();


/**
 * @brief Initialize RPI2 Pico, modules, structures, enable interupts and start timers
 */
int main() {
    setUp();

    setIRQs();
    startTimers();

    // Sine fine loop
    while (HABEMUS_RES_QUAE_AD_SOLVENDUM_OPUS) tight_loop_contents();
}

/**
 * @brief Initialize everything
 */
void setUp() {
    stdio_init_all();
    sleep_ms(500);

    initElements();
    sleep_ms(500);
}

/**
 * @brief Initialize everyting except RPI2 Pico
 */
void initElements() {
    initLedOut();
    initJoystick();
    initDisplay();
    initNavigationData();
    initUIManager();
    initModel();

    gpio_init(VIEW_CHANGE_BUTTON);
    gpio_set_dir(VIEW_CHANGE_BUTTON, GPIO_IN);

    gpio_init(MAIN_ACTION_BUTTON);
    gpio_set_dir(MAIN_ACTION_BUTTON, GPIO_IN);

    gpio_init(ADDITIONAL_ACTION_BUTTON);
    gpio_set_dir(ADDITIONAL_ACTION_BUTTON, GPIO_IN);

    initByte(&buttonFlags);
    initField(&someField);

    viewChangeButtonDebouncerFlag = 1;
    mainActionButtonDebouncerFlag = 1;
    additionalActionButtonDebouncerFlag = 1;

    joystickActionDebouncerFlag = 1;
    resetNavyDebouncerFlag = 1;
    fireDebouncerFlag = 1;
}

/**
 * @brief Enable intrupts
 */
void setIRQs() {
    gpio_set_irq_enabled_with_callback(VIEW_CHANGE_BUTTON, GPIO_IRQ_EDGE_RISE, true, &callbackSwitcher);
    gpio_set_irq_enabled(MAIN_ACTION_BUTTON, GPIO_IRQ_EDGE_RISE, true);
    gpio_set_irq_enabled(ADDITIONAL_ACTION_BUTTON, GPIO_IRQ_EDGE_RISE, true);
}

/**
 * @brief Start timers
 */
void startTimers() {
    add_repeating_timer_ms(25, UIManagerUpdateCallback, NULL, &UIManagerUpdater);
    add_repeating_timer_ms(50, joystickDataCallback, NULL, &joystickUpdateTimer);
}
