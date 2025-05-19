/**
 * \file	main.c
 * \brief
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


#ifndef TIMER_CALLBACK_FUNCTIONS_H
#include "TimerCallbackFunctions.h"
#endif
#ifndef IRQ_CALLBACK_FUNCTIONS_H
#include "IRQCallbackFunctions.h"
#endif


#ifndef LED_1
#define LED_1 15
#define LED_0 14
#endif


byte_t states;
ledOut_t ledOut;
joystick_t joystick;
display_t display;


struct repeating_timer printer;
struct repeating_timer viewResetter;


void setUp();
void initElements();
void setIRQs();
void startTimers();


int main() {
    setUp();

    setIRQs();
    startTimers();

    // Sine fine loop
    while (HABEMUS_RES_QUAE_AD_SOLVENDUM_OPUS) {
        tight_loop_contents();

        states.reset(&states);
        joystick.read(&joystick);

        switch (joystick.direction) {
            case NE:
                states.on(&states, 2);
                states.on(&states, 1);
                states.on(&states, 0);
                break;
            case NP:
                states.on(&states, 2);
                states.on(&states, 1);
                break;
            case NW:
                states.on(&states, 2);
                states.on(&states, 0);
                break;
            case EP:
                states.on(&states, 2);
                break;
            case WP:
                states.on(&states, 1);
                states.on(&states, 0);
                break;
            case SE:
                states.on(&states, 1);
                break;
            case SP:
                states.on(&states, 0);
                break;
            case SW:
                break;
            default:
                break;
        }

        ledOut.set(states.read(&states, 2));
        gpio_put(LED_1, states.read(&states, 1));
        gpio_put(LED_0, states.read(&states, 0));
    }
}

void setUp() {
    stdio_init_all();

    initElements();

    gpio_init(LED_1);
    gpio_set_dir(LED_1, GPIO_OUT);
    gpio_init(LED_0);
    gpio_set_dir(LED_0, GPIO_OUT);
}

void initElements() {
    initLedOut(&ledOut);
    initJoystick(&joystick);
    initDisplay(&display);

    initByte(&states);
}

void setIRQs() {
    gpio_set_irq_enabled_with_callback(JOYSTICK_GPIO_SW, GPIO_IRQ_EDGE_FALL, true, &joystickSwitchCallback);
}

void startTimers() {
    add_repeating_timer_ms(250, joystickDataCallback, NULL, &printer);
    add_repeating_timer_ms(2000, viewResetCallback, NULL, &viewResetter);
}
