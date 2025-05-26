/**
 * \file	ShipViews.c
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef SHIP_VIEWS_H
#include "ShipElements.h"


void drawBoatHorizontal(const coordinate_e x, const coordinate_e y) {
    display.fillRectangle(19 + x * 11, 19 + y * 11, 10, 10, WATER);

    display.drawHorizontalLine(19 + 4 + x * 11, 19 + y * 11, 2, 1, WOOD_BOAT);
    display.drawHorizontalLine(19 + 3 + x * 11, 19 + 1 + y * 11, 4, 1, WOOD_BOAT);
    display.fillRectangle(19 + 2 + x * 11, 19 + 2 + y * 11, 6, 8, WOOD_BOAT);
    display.drawHorizontalLine(19 + 4 + x * 11, 19 + 8 + y * 11, 2, 1, WATER);
    display.drawHorizontalLine(19 + 3 + x * 11, 19 + 9 + y * 11, 4, 1, WATER);
}

void drawBoatVertical(const coordinate_e x, const coordinate_e y) {
    display.fillRectangle(19 + x * 11, 19 + y * 11, 10, 10, WATER);

    display.drawVerticalLine(19 + x * 11, 19 + 4 + y * 11, 2, 1, WOOD_BOAT);
    display.drawVerticalLine(19 + 1 + x * 11, 19 + 3 + y * 11, 4, 1, WOOD_BOAT);
    display.fillRectangle(19 + 2 + x * 11, 19 + 2 + y * 11, 8, 6, WOOD_BOAT);
    display.drawVerticalLine(19 + 8 + x * 11, 19 + 4 + y * 11, 2, 1, WATER);
    display.drawVerticalLine(19 + 9 + x * 11, 19 + 3 + y * 11, 4, 1, WATER);
}


#endif
