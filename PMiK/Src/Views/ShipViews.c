/**
 * \file	ShipViews.c
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef SHIP_VIEWS_H
#include "ShipViews.h"


void drawBoat(display_t *display, uint8_t x, uint8_t y) {
    display->fillRectangle(15 + x * 10, 15 + y * 10, 8, 8, WATER);
    display->fillRectangle(18 + x * 10, 15 + y * 10, 2, 1, WOOD_BOAT);
    display->fillRectangle(17 + x * 10, 16 + y * 10, 4, 7, WOOD_BOAT);
    display->fillRectangle(18 + x * 10, 22 + y * 10, 2, 1, WATER);
}


#endif
