/**
 * \file	LedOut.h
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef LED_OUT_H
#define LED_OUT_H


#ifndef THE_DATA_H
#include "TheData.h"
#endif


typedef struct LedOut {
    void (*on) ();
    void (*off) ();
    void (*set) (const bool);
    void (*toggle) ();
} ledOut_t;


void initLedOut();


#endif