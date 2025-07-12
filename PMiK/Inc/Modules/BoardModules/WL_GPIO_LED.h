/**
 * @file	WL_GPIO_LED.h
 * @brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef WL_GPIO_LED_H
#define WL_GPIO_LED_H


#ifndef THE_DATA_H
#include "TheData.h"
#endif


typedef struct WL_GPIO_LED {
    void (*on) ();
    void (*off) ();
    void (*toggle) ();
    void (*set) (const bool);
} WL_GPIO_LED_t;


extern WL_GPIO_LED_t WL_GPIO_LED;


void initWL_GPIO_LED();


#endif
