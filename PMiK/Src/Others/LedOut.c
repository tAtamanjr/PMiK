/**
 * \file	LedOut.c
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef LED_OUT_H
#include "LedOut.h"


static void on();
static void off();
static void set(bool);


void initLedOut(ledOut_t *ledOut) {
    int rc = cyw43_arch_init();
    hard_assert(rc == PICO_OK);
    
    ledOut->on = on;
    ledOut->off = off;
    ledOut->set = set;
}

static void on() {
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
}

static void off() {
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
}

static void set(const bool state) {
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, state);
}


#endif