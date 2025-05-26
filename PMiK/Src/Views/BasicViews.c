/**
 * \file	ShipElements.c
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef BASIC_VIEWS_H
#include "BasicViews.h"


void drawFieldView() {
    display.fillRectangle(0, 0, 128, 128, WHITE);

    display.fillRectangle(19, 19, 109, 109, CLOUD);
    display.drawHorizontalLine(0, 17, 128, 2, BLACK);
    display.drawVerticalLine(17, 0, 128, 2, BLACK);
    for (uint8_t i = 1; i < 10; i++) {
        display.drawHorizontalLine(0, 18 + i * 11, 128, 1, BLACK);
        display.drawVerticalLine(18 + i * 11, 0, 128, 1, BLACK);
    }

    drawFieldLogo();
    drawFieldCoordinates();
}

void drawDownMenuElement() {
    display.drawHorizontalLine(0, 128, 128, 2, RED);
    display.fillRectangle(0, 130, 128, 34, BLACK);
}

void drawMenuView() {
    display.fillScreen(BLACK);
}

void drawCloudCell(const uint8_t x, const uint8_t y) {
    display.fillRectangle(19 + x * 11, 19 + y * 11, 10, 10, CLOUD);
}

void drawAim(const uint8_t x, const uint8_t y) {
    display.fillRectangle(19 + x * 11, 19 + y * 11, 2, 2, RED);
    display.fillRectangle(19 + x * 11 + 8, 19 + y * 11, 2, 2, RED);
    display.fillRectangle(19 + x * 11 + 8, 19 + y * 11 + 8, 2, 2, RED);
    display.fillRectangle(19 + x * 11, 19 + y * 11 + 8, 2, 2, RED);
    display.fillRectangle(19 + x * 11 + 1, 19 + y * 11 + 1, 2, 2, RED);
    display.fillRectangle(19 + x * 11 + 7, 19 + y * 11 + 1, 2, 2, RED);
    display.fillRectangle(19 + x * 11 + 7, 19 + y * 11 + 7, 2, 2, RED);
    display.fillRectangle(19 + x * 11 + 1, 19 + y * 11 + 7, 2, 2, RED);
}

void removeAim(const uint8_t x, const uint8_t y) {
    drawCloudCell(x, y);
}


#endif
