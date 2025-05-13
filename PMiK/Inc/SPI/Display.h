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
    void (*fillScreen) (color_t color);
    void (*drawPixel) (uint8_t x, uint8_t y, color_t color);
    void (*fillRectangle) (uint8_t x, uint8_t y, uint8_t w, uint8_t h, color_t color);
} display_t;


void initDisplay(display_t *display);


#endif