/**
 * \file	Letters.c
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef LETTERS_H
#include "Letters.h"


static void drawBigB(uint8_t x, uint8_t y, color_t color);

static void drawSmallA(uint8_t x, uint8_t y, color_t color);
static void drawSmallB(uint8_t x, uint8_t y, color_t color);
static void drawSmallC(uint8_t x, uint8_t y, color_t color);
static void drawSmallD(uint8_t x, uint8_t y, color_t color);
static void drawSmallE(uint8_t x, uint8_t y, color_t color);
static void drawSmallF(uint8_t x, uint8_t y, color_t color);
static void drawSmallG(uint8_t x, uint8_t y, color_t color);
static void drawSmallH(uint8_t x, uint8_t y, color_t color);
static void drawSmallI(uint8_t x, uint8_t y, color_t color);
static void drawSmallJ(uint8_t x, uint8_t y, color_t color);


void drawBigLetter(const letter_e letter, const uint8_t x, const uint8_t y, const color_t color) {
    switch (letter) {
        case B_b:
            drawBigB(x, y, color);
        default:
            return;
    }
}

void drawSmallLetter(const letter_e letter, const uint8_t x, const uint8_t y, const color_t color) {
    switch (letter) {
        case A_s:
            drawSmallA(x, y, color);
            return;
        case B_s:
            drawSmallB(x, y, color);
            return;
        case C_s:
            drawSmallC(x, y, color);
            return;
        case D_s:
            drawSmallD(x, y, color);
            return;
        case E_s:
            drawSmallE(x, y, color);
            return;
        case F_s:
            drawSmallF(x, y, color);
            return;
        case G_s:
            drawSmallG(x, y, color);
            return;
        case H_s:
            drawSmallH(x, y, color);
            return;
        case I_s:
            drawSmallI(x, y, color);
            return;
        case J_s:
            drawSmallJ(x, y, color);
            return;
        default:
            return;
    }
}

static void drawBigB(const uint8_t x, const uint8_t y, const color_t color) {
    display.drawVerticalLine(x, y, 13, 2, color);
    display.drawHorizontalLine(x + 2, y, 3, 2, color);
    display.drawHorizontalLine(x + 2, y + 5, 3, 2, color);
    display.drawHorizontalLine(x + 2, y + 11, 3, 2, color);
    display.drawVerticalLine(x + 5, y + 2, 3, 2, color);
    display.drawVerticalLine(x + 5, y + 7, 4, 2, color);
    display.drawVerticalLine(x + 5, y + 1, 11, 1, color);
}

static void drawSmallA(const uint8_t x, const uint8_t y, const color_t color) {
    display.drawHorizontalLine(x + 3, y, 2, 1, color);
    display.drawPixel(x + 2, y + 1, color);
    display.drawPixel(x + 5, y + 1, color);
    display.drawVerticalLine(x + 1, y + 2, 6, 1, color);
    display.drawVerticalLine(x + 6, y + 2, 6, 1, color);
    display.drawHorizontalLine(x + 2, y + 4, 4, 1, color);
}

static void drawSmallB(const uint8_t x, const uint8_t y, const color_t color) {
    display.drawVerticalLine(x + 1, y, 8, 1, color);
    display.drawHorizontalLine(x + 2, y, 3, 1, color);
    display.drawHorizontalLine(x + 2, y + 3, 4, 1, color);
    display.drawHorizontalLine(x + 2, y + 7, 4, 1, color);
    display.drawVerticalLine(x + 5, y + 1, 2, 1, color);
    display.drawVerticalLine(x + 6, y + 4, 3, 1, color);
}

static void drawSmallC(const uint8_t x, const uint8_t y, const color_t color) {
    display.drawHorizontalLine(x + 2, y, 4, 1, color);
    display.drawHorizontalLine(x + 2, y + 7, 4, 1, color);
    display.drawVerticalLine(x + 1, y + 1, 6, 1, color);
    display.drawVerticalLine(x + 6, y + 1, 2, 1, color);
    display.drawVerticalLine(x + 6, y + 5, 2, 1, color);
}

static void drawSmallD(const uint8_t x, const uint8_t y, const color_t color) {
    display.drawHorizontalLine(x + 1, y, 5, 1, color);
    display.drawHorizontalLine(x + 1, y + 7, 5, 1, color);
    display.drawVerticalLine(x + 1, y, 8, 1, color);
    display.drawVerticalLine(x + 6, y + 1, 6, 1, color);
}

static void drawSmallE(const uint8_t x, const uint8_t y, const color_t color) {
    display.drawHorizontalLine(x + 2, y, 4, 1, color);
    display.drawHorizontalLine(x + 2, y + 3, 3, 1, color);
    display.drawHorizontalLine(x + 2, y + 7, 4, 1, color);
    display.drawVerticalLine(x + 1, y + 1, 2, 1, color);
    display.drawVerticalLine(x + 1, y + 4, 3, 1, color);
    display.drawPixel(x + 6, y + 1, color);
    display.drawPixel(x + 6, y + 6, color);
}

static void drawSmallF(const uint8_t x, const uint8_t y, const color_t color) {
    display.drawHorizontalLine(x + 2, y, 5, 1, color);
    display.drawHorizontalLine(x + 2, y + 3, 3, 1, color);
    display.drawVerticalLine(x + 1, y, 8, 1, color);
}

static void drawSmallG(const uint8_t x, const uint8_t y, const color_t color) {
    display.drawHorizontalLine(x + 2, y, 4, 1, color);
    display.drawHorizontalLine(x + 4, y + 4, 3, 1, color);
    display.drawHorizontalLine(x + 2, y + 7, 4, 1, color);
    display.drawPixel(x + 6, y + 1, color);
    display.drawVerticalLine(x + 1, y + 1, 6, 1, color);
    display.drawVerticalLine(x + 6, y + 5, 2, 1, color);
}

static void drawSmallH(const uint8_t x, const uint8_t y, const color_t color) {
    display.drawVerticalLine(x + 1, y, 8, 1, color);
    display.drawVerticalLine(x + 6, y, 8, 1, color);
    display.drawHorizontalLine(x + 2, y + 3, 4, 1, color);
}

static void drawSmallI(const uint8_t x, const uint8_t y, const color_t color) {
    display.drawHorizontalLine(x + 1, y, 6, 1, color);
    display.drawHorizontalLine(x + 1, y + 7, 6, 1, color);
    display.drawVerticalLine(x + 4, y + 1, 3, 1, color);
    display.drawVerticalLine(x + 3, y + 4, 3, 1, color);
}

static void drawSmallJ(const uint8_t x, const uint8_t y, const color_t color) {
    display.drawHorizontalLine(x + 3, y, 4, 1, color);
    display.drawHorizontalLine(x + 2, y + 7, 3, 1, color);
    display.drawVerticalLine(x + 1, y + 5, 2, 1, color);
    display.drawVerticalLine(x + 5, y + 1, 6, 1, color);
}


#endif
