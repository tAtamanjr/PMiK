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
#ifndef INPUT_MODULES_FLAGS_H
#include "InputModulesFlags.h"
#endif
#ifndef LED_OUT_H
#include "WL_GPIO_LED.h"
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


inputModulesFlags_t inputModulesFlags;

alarm_id_t viewChangeButtonDebouncerAlarm;
alarm_id_t mainActionButtonDebouncerAlarm;
alarm_id_t additionalActionButtonDebouncerAlarm;

WL_GPIO_LED_t WL_GPIO_LED;
joystick_t joystick;
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

struct repeating_timer joystickTimer;
struct repeating_timer UIManagerTimer;
struct repeating_timer modelTimer;

struct repeating_timer debuggTimer;

struct repeating_timer joystickUpdateTimer;


void setUp();
void initSupport();
void initModules();
void initButtons();
void initUI();
void setIRQs();
void startTimers();


int main() {
    setUp();

    setIRQs();
    startTimers();

    // Sine fine loop
    while (HABEMUS_RES_QUAE_AD_SOLVENDUM_OPUS) tight_loop_contents();
}

void setUp() {
    stdio_init_all();
    sleep_ms(500);

    initSupport();
    initModules();
    initUI();

    initByte(&buttonFlags);
    initField(&someField);

    resetNavyDebouncerFlag = 1;
    fireDebouncerFlag = 1;
    sleep_ms(500);
}

void initSupport() {
    initInputModulesFlags();
}

void initModules() {
    initWL_GPIO_LED();
    initButtons();
    initJoystick();
    initDisplay();
}

void initButtons() {
    gpio_init(VIEW_CHANGE_BUTTON);
    gpio_set_dir(VIEW_CHANGE_BUTTON, GPIO_IN);

    gpio_init(MAIN_ACTION_BUTTON);
    gpio_set_dir(MAIN_ACTION_BUTTON, GPIO_IN);

    gpio_init(ADDITIONAL_ACTION_BUTTON);
    gpio_set_dir(ADDITIONAL_ACTION_BUTTON, GPIO_IN);
}

void initUI() {
    initNavigationData();
    initUIManager();
    initModel();
}

void setIRQs() {
    gpio_set_irq_enabled_with_callback(VIEW_CHANGE_BUTTON, GPIO_IRQ_EDGE_RISE, true, &callbackSwitcher);
    gpio_set_irq_enabled(MAIN_ACTION_BUTTON, GPIO_IRQ_EDGE_RISE, true);
    gpio_set_irq_enabled(ADDITIONAL_ACTION_BUTTON, GPIO_IRQ_EDGE_RISE, true);
}

void startTimers() {
    add_repeating_timer_ms(50, joystickDataCallback, NULL, &joystickUpdateTimer);

    // add_repeating_timer_ms(25, updateJoystickDataCallback, NULL, &joystickTimer);
    add_repeating_timer_ms(25, updateUIManagerCallback, NULL, &UIManagerTimer);
    add_repeating_timer_ms(50, updateGameDataCallback, NULL, &modelTimer);

    add_repeating_timer_ms(100, debuggCallback, NULL, &debuggTimer);
}
