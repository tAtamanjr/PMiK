/**
 * @file	Letters.h
 * @brief   Draw letters on the display
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef LETTERS_H
#define LETTERS_H


#ifndef THE_DATA_H
#include "TheData.h"
#endif

#ifndef DISPLAY_H
#include "Display.h"
#endif


void drawBigLetter(letter_e letter, uint8_t x, uint8_t y, color_t color);
void drawSmallLetter(letter_e letter, uint8_t x, uint8_t y, color_t color);


#endif
