/**
 * \file	TextElements.c
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef TEXT_ELEMENTS_H
#include "TextElements.h"


static void drawSmall0(uint8_t, uint8_t, color_t);
static void drawSmall1(uint8_t, uint8_t, color_t);
static void drawSmall2(uint8_t, uint8_t, color_t);
static void drawSmall3(uint8_t, uint8_t, color_t);
static void drawSmall4(uint8_t, uint8_t, color_t);
static void drawSmall5(uint8_t, uint8_t, color_t);
static void drawSmall6(uint8_t, uint8_t, color_t);
static void drawSmall7(uint8_t, uint8_t, color_t);
static void drawSmall8(uint8_t, uint8_t, color_t);
static void drawSmall9(uint8_t, uint8_t, color_t);
static void drawSmallA(uint8_t, uint8_t, color_t);
static void drawSmallB(uint8_t, uint8_t, color_t);
static void drawBigB(uint8_t, uint8_t, color_t);
static void drawSmallC(uint8_t, uint8_t, color_t);
static void drawSmallD(uint8_t, uint8_t, color_t);
static void drawSmallE(uint8_t, uint8_t, color_t);
static void drawSmallF(uint8_t, uint8_t, color_t);
static void drawSmallG(uint8_t, uint8_t, color_t);
static void drawSmallH(uint8_t, uint8_t, color_t);
static void drawSmallI(uint8_t, uint8_t, color_t);
static void drawSmallJ(uint8_t, uint8_t, color_t);


void drawFieldLogo() {
    drawBigB(1, 3, BLACK);
    drawBigB(9, 3, BLACK);
}

void drawFieldCoordinates() {
    drawSmallA(20, 8, BLACK);
    drawSmallB(31, 8, BLACK);
    drawSmallC(42, 8, BLACK);
    drawSmallD(53, 8, BLACK);
    drawSmallE(64, 8, BLACK);
    drawSmallF(75, 8, BLACK);
    drawSmallG(86, 8, BLACK);
    drawSmallH(97, 8, BLACK);
    drawSmallI(108, 8, BLACK);
    drawSmallJ(119, 8, BLACK);
    drawSmall1(8, 20, BLACK);
    drawSmall2(8, 31, BLACK);
    drawSmall3(8, 42, BLACK);
    drawSmall4(8, 53, BLACK);
    drawSmall5(8, 64, BLACK);
    drawSmall6(8, 75, BLACK);
    drawSmall7(8, 86, BLACK);
    drawSmall8(8, 97, BLACK);
    drawSmall9(8, 108, BLACK);
    drawSmall1(0, 119, BLACK); drawSmall0(8, 119, BLACK);
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

static void drawBigB(const uint8_t x, const uint8_t y, const color_t color) {
    display.drawVerticalLine(x, y, 13, 2, color);
    display.drawHorizontalLine(x + 2, y, 3, 2, color);
    display.drawHorizontalLine(x + 2, y + 5, 3, 2, color);
    display.drawHorizontalLine(x + 2, y + 11, 3, 2, color);
    display.drawVerticalLine(x + 5, y + 2, 3, 2, color);
    display.drawVerticalLine(x + 5, y + 8, 3, 2, color);
    display.drawVerticalLine(x + 5, y + 1, 11, 1, color);
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

static void drawSmall0(const uint8_t x, const uint8_t y, const color_t color) {
    display.drawHorizontalLine(x + 2, y, 4, 1, color);
    display.drawHorizontalLine(x + 2, y + 7, 4, 1, color);
    display.drawVerticalLine(x + 1, y + 1, 6, 1, color);
    display.drawVerticalLine(x + 6, y + 1, 6, 1, color);
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
