/**
 * \file	Display.h
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef DISPLAY_H
#define DISPLAY_H


#ifndef THE_DATA_H
#include "TheData.h"
#endif


typedef struct Display {
    void (*fillScreen) (const color_t color);
    void (*drawPixel) (const uint8_t x, const uint8_t y, const color_t color);
    void (*fillRectangle) (const uint8_t x, const uint8_t y, uint8_t w, uint8_t h, const color_t color);
    void (*drawHorizontalLine) (const uint8_t x, const uint8_t y, uint8_t l, uint8_t w, const color_t color);
    void (*drawVerticalLine) (const uint8_t x, const uint8_t y, uint8_t l, uint8_t w, const color_t color);
} display_t;


extern display_t display;


void initDisplay();


#endif