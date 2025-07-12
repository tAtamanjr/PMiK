/**
 * @file	WL_GPIO_LED.c
 * @brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef WL_GPIO_LED_H
#include "WL_GPIO_LED.h"


static void on();
static void off();
static void toggle();
static void set(bool);


void initWL_GPIO_LED() {
    int rc = cyw43_arch_init();
    hard_assert(rc == PICO_OK);
    
    WL_GPIO_LED.on = on;
    WL_GPIO_LED.off = off;
    WL_GPIO_LED.toggle = toggle;
    WL_GPIO_LED.set = set;
}

static void on() {
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
}

static void off() {
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
}

static void toggle() {
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, !cyw43_arch_gpio_get(CYW43_WL_GPIO_LED_PIN));
}

static void set(const bool state) {
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, state);
}


#endif