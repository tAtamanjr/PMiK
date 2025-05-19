/**
 * \file	BasicViews.c
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef BASIC_VIEWS_H
#include "BasicViews.h"


void drawFieldView(const display_t *display) {
    display->fillScreen(BLACK);

    display->fillRectangle(14, 14, 100, 100, CLOUD);


    for (uint8_t x = 13; x <= 113; x += 10) {
        display->drawVerticalLine(x, 0, 128, 2, WHITE);
    }
    for (uint8_t y = 13; y <= 113; y += 10) {
        display->drawHorizontalLine(0, y, 128, 2, WHITE);
    }

    display->drawHorizontalLine(0, 128, 128, 2, ORANGE);
}

void drawMenuView(const display_t *display) {
    display->fillScreen(BLACK);
}


#endif
