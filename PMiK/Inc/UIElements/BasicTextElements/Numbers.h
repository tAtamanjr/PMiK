/**
 * @file	Numbers.h
 * @brief   Draw number on the display
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef NUMBERS_H
#define NUMBERS_H


#ifndef THE_DATA_H
#include "TheData.h"
#endif

#ifndef DISPLAY_H
#include "Display.h"
#endif


void drawNumber(uint8_t number, uint8_t x, uint8_t y, color_t color);


#endif
