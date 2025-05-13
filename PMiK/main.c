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


#ifndef LED_1
#define LED_1 15
#define LED_0 14
#endif


byte_t states;
ledOut_t ledOut;
joystick_t joystick;
display_t display;


void setUp();
void initElements();
void setIRQs();
void startTimers();


int main() {
    setUp();

    setIRQs();
    startTimers();

    // display.fillScreen(BLACK);
    // color_t colors[6] = {GRAY, WHITE, ORANGE, RED, YELLOW, BLUE};
    drawFieldView(&display);
    drawBoat(&display, 0, 0);
    drawBoat(&display, 4, 5);
    drawBoat(&display, 9, 7);

    // Sine fine loop
    while (true) {
        states.reset(&states);
        joystick.read(&joystick);

        switch (joystick.direction) {
            case NE:
                states.on(&states, 2);
                states.on(&states, 1);
                states.on(&states, 0);
                break;
            case N:
                states.on(&states, 2);
                states.on(&states, 1);
                break;
            case NW:
                states.on(&states, 2);
                states.on(&states, 0);
                break;
            case E:
                states.on(&states, 2);
                break;
            case W:
                states.on(&states, 1);
                states.on(&states, 0);
                break;
            case SE:
                states.on(&states, 1);
                break;
            case S:
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

        // display.fillRectangle(x, y, 50, 30, BLACK);
        // x += 7;
        // y += 7;
        // if ((x + 50) >= DISPLAY_SIZE_X) {
        //     x = 0;
        //     colorIndex++;
        //     if (colorIndex >= 6) colorIndex = 0;
        // }
        // if ((y + 30) >= DISPLAY_SIZE_Y) {
        //     y = 0;
        //     colorIndex++;
        //     if (colorIndex >= 6) colorIndex = 0;
        // }
        // display.fillRectangle(x, y, 50, 30, colors[colorIndex]);
        // sleep_ms(100);
    }
}

void setUp() {
    stdio_init_all();
    initElements();

    gpio_init(LED_1);
    gpio_set_dir(LED_1, GPIO_OUT);
    gpio_init(LED_0);
    gpio_set_dir(LED_0, GPIO_OUT);

    // x = 10;
    // y = 10;

    // colorIndex = 0;
}

void initElements() {
    initLedOut(&ledOut);
    initJoystick(&joystick);
    initDisplay(&display);

    initByte(&states);
}

void startTimers() {
    struct repeating_timer printer;
    add_repeating_timer_ms(250, joystickDataCallback, NULL, &printer);
}

void setIRQs() {
    gpio_set_irq_enabled_with_callback(JOYSTICK_GPIO_SW, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL, true, &joystickSwitchCallback);
}