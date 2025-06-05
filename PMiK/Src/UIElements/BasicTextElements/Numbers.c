/**
 * \file	Numbers.c
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef NUMBERS_H
#include "Numbers.h"


static void drawSmall0(uint8_t x, uint8_t y, color_t color);
static void drawSmall1(uint8_t x, uint8_t y, color_t color);
static void drawSmall2(uint8_t x, uint8_t y, color_t color);
static void drawSmall3(uint8_t x, uint8_t y, color_t color);
static void drawSmall4(uint8_t x, uint8_t y, color_t color);
static void drawSmall5(uint8_t x, uint8_t y, color_t color);
static void drawSmall6(uint8_t x, uint8_t y, color_t color);
static void drawSmall7(uint8_t x, uint8_t y, color_t color);
static void drawSmall8(uint8_t x, uint8_t y, color_t color);
static void drawSmall9(uint8_t x, uint8_t y, color_t color);


void drawNumber(const uint8_t number, const uint8_t x, const uint8_t y, const color_t color) {
    switch (number) {
        case 0:
            drawSmall0(x, y, color);
            return;
        case 1:
            drawSmall1(x, y, color);
            return;
        case 2:
            drawSmall2(x, y, color);
            return;
        case 3:
            drawSmall3(x, y, color);
            return;
        case 4:
            drawSmall4(x, y, color);
            return;
        case 5:
            drawSmall5(x, y, color);
            return;
        case 6:
            drawSmall6(x, y, color);
            return;
        case 7:
            drawSmall7(x, y, color);
            return;
        case 8:
            drawSmall8(x, y, color);
            return;
        case 9:
            drawSmall9(x, y, color);
            return;
        case 10:
            drawSmall1(x, y, color);
            drawSmall0(x + 8, y, color);
            return;
        default:
            return;
    }
}

static void drawSmall0(const uint8_t x, const uint8_t y, const color_t color) {
    display.drawHorizontalLine(x + 2, y, 4, 1, color);
    display.drawHorizontalLine(x + 2, y + 7, 4, 1, color);
    display.drawVerticalLine(x + 1, y + 1, 6, 1, color);
    display.drawVerticalLine(x + 6, y + 1, 6, 1, color);

    display.drawPixel(x + 5, y + 2, color);
    display.drawPixel(x + 4, y + 3, color);
    display.drawPixel(x + 3, y + 4, color);
    display.drawPixel(x + 2, y + 5, color);
}

static void drawSmall1(const uint8_t x, const uint8_t y, const color_t color) {
    display.fillRectangle(x + 3, y, 3, 2, color);
    display.drawPixel(x + 1, y + 2, color);
    display.drawPixel(x + 6, y, color);
    display.drawHorizontalLine(x + 1, y + 1, 2, 1, color);
    display.drawHorizontalLine(x + 1, y + 7, 6, 1, color);
    display.drawVerticalLine(x + 4, y + 2, 5, 1, color);
}

static void drawSmall2(const uint8_t x, const uint8_t y, const color_t color) {
    display.drawPixel(x + 6, y + 1, color);
    display.drawPixel(x + 5, y + 2, color);
    display.drawPixel(x + 4, y + 3, color);
    display.drawPixel(x + 3, y + 4, color);
    display.drawPixel(x + 2, y + 5, color);
    display.drawHorizontalLine(x + 2, y, 4, 1, color);
    display.drawHorizontalLine(x + 2, y + 7, 4, 1, color);
    display.drawVerticalLine(x + 1, y + 1, 2, 1, color);
    display.drawVerticalLine(x + 1, y + 6, 2, 1, color);
    display.drawVerticalLine(x + 6, y + 6, 2, 1, color);
}

static void drawSmall3(const uint8_t x, const uint8_t y, const color_t color) {
    display.drawPixel(x + 1, y + 1, color);
    display.drawPixel(x + 1, y + 6, color);
    display.drawHorizontalLine(x + 2, y, 4, 1, color);
    display.drawHorizontalLine(x + 3, y + 3, 3, 1, color);
    display.drawHorizontalLine(x + 2, y + 7, 4, 1, color);
    display.drawVerticalLine(x + 6, y + 1, 2, 1, color);
    display.drawVerticalLine(x + 6, y + 4, 3, 1, color);
}

static void drawSmall4(const uint8_t x, const uint8_t y, const color_t color) {
    display.drawPixel(x + 2, y + 3, color);
    display.drawHorizontalLine(x + 2, y + 5, 5, 1, color);
    display.drawVerticalLine(x + 1, y + 4, 2, 1, color);
    display.drawVerticalLine(x + 3, y + 1, 2, 1, color);
    display.drawVerticalLine(x + 5, y, 8, 1, color);
}

static void drawSmall5(const uint8_t x, const uint8_t y, const color_t color) {
    display.drawPixel(x + 1, y + 6, color);
    display.drawHorizontalLine(x + 1, y, 6, 1, color);
    display.drawHorizontalLine(x + 1, y + 3, 5, 1, color);
    display.drawHorizontalLine(x + 2, y + 7, 4, 1, color);
    display.drawVerticalLine(x + 1, y + 1, 2, 1, color);
    display.drawVerticalLine(x + 6, y + 4, 3, 1, color);
}

static void drawSmall6(const uint8_t x, const uint8_t y, const color_t color) {
    display.drawPixel(x + 6, y + 1, color);
    display.drawHorizontalLine(x + 2, y, 4, 1, color);
    display.drawHorizontalLine(x + 2, y + 3, 4, 1, color);
    display.drawHorizontalLine(x + 2, y + 7, 4, 1, color);
    display.drawVerticalLine(x + 1, y + 1, 6, 1, color);
    display.drawVerticalLine(x + 6, y + 4, 3, 1, color);
}

static void drawSmall7(const uint8_t x, const uint8_t y, const color_t color) {
    display.drawPixel(x + 1, y + 1, color);
    display.drawPixel(x + 6, y + 2, color);
    display.drawPixel(x + 4, y + 4, color);
    display.drawPixel(x + 3, y + 5, color);
    display.drawHorizontalLine(x + 1, y, 6, 1, color);
    display.drawVerticalLine(x + 5, y + 1, 7, 1, color);
}

static void drawSmall8(const uint8_t x, const uint8_t y, const color_t color) {
    display.drawHorizontalLine(x + 2, y, 4, 1, color);
    display.drawHorizontalLine(x + 2, y + 3, 2, 1, color);
    display.drawHorizontalLine(x + 4, y + 4, 2, 1, color);
    display.drawHorizontalLine(x + 2, y + 7, 4, 1, color);
    display.drawVerticalLine(x + 1, y + 1, 2, 1, color);
    display.drawVerticalLine(x + 1, y + 4, 3, 1, color);
    display.drawVerticalLine(x + 6, y + 1, 3, 1, color);
    display.drawVerticalLine(x + 6, y + 5, 2, 1, color);
}

static void drawSmall9(const uint8_t x, const uint8_t y, const color_t color) {
    display.drawPixel(x + 1, y + 6, color);
    display.drawHorizontalLine(x + 2, y, 4, 1, color);
    display.drawHorizontalLine(x + 2, y + 4, 4, 1, color);
    display.drawHorizontalLine(x + 2, y + 7, 4, 1, color);
    display.drawVerticalLine(x + 1, y + 1, 3, 1, color);
    display.drawVerticalLine(x + 6, y + 1, 6, 1, color);
}


#endif
