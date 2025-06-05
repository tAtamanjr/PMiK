/**
 * \file	ShipViews.c
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef SHIP_VIEWS_H
#include "ShipElements.h"


static uint8_t cc(const uint8_t coord, const uint8_t shift) {
    return 19 + coord * 11 + shift;
}

static uint8_t cc0(const uint8_t coord) {
    return 19 + coord * 11;
}

static void drawDamageHorizontal(const coordinate_e x, const coordinate_e y);
static void drawDamageVertical(const coordinate_e x, const coordinate_e y);


void drawBoatVertical(const coordinate_e x, const coordinate_e y) {
    display.fillRectangle(cc0(x), cc0(y), 10, 10, WATER);

    display.drawHorizontalLine(cc(x, 4), cc0(y), 2, 1, WOOD_BOAT);
    display.drawHorizontalLine(cc(x, 3), cc(y, 1), 4, 1, WOOD_BOAT);
    display.fillRectangle(cc(x, 2), cc(y, 2), 6, 8, WOOD_BOAT);
    display.drawHorizontalLine(cc(x, 4), cc(y, 8), 2, 1, WATER);
    display.drawHorizontalLine(cc(x, 3), cc(y, 9), 4, 1, WATER);
}

void drawBoatHorizontal(const coordinate_e x, const coordinate_e y) {
    display.fillRectangle(cc0(x), cc0(y), 10, 10, WATER);

    display.drawVerticalLine(cc0(x), 19 + 4 + y * 11, 2, 1, WOOD_BOAT);
    display.drawVerticalLine(cc(x, 1), cc(y, 3), 4, 1, WOOD_BOAT);
    display.fillRectangle(cc(x, 2), cc(y, 2), 8, 6, WOOD_BOAT);
    display.drawVerticalLine(cc(x, 8), cc(y, 4), 2, 1, WATER);
    display.drawVerticalLine(cc(x, 9), cc(y, 3), 4, 1, WATER);
}

void drawBowVertical(const coordinate_e x, const coordinate_e y) {
    display.fillRectangle(cc0(x), cc0(y), 10, 10, WATER);

    display.drawHorizontalLine(cc(x, 4), cc0(y), 2, 1, METAL_SHIP);
    display.drawHorizontalLine(cc(x, 3), cc(y, 1), 4, 1, METAL_SHIP);
    display.fillRectangle(cc(x, 2), cc(y, 2), 6, 8, METAL_SHIP);
}

void drawBowHorizontal(const coordinate_e x, const coordinate_e y) {
    display.fillRectangle(cc0(x), cc0(y), 10, 10, WATER);

    display.drawVerticalLine(cc0(x), cc(y, 4), 2, 1, METAL_SHIP);
    display.drawVerticalLine(cc(x, 1), cc(y, 3), 4, 1, METAL_SHIP);
    display.fillRectangle(cc(x, 2), cc(y, 2), 8, 6, METAL_SHIP);
}

void drawMiddleHorizontal(const coordinate_e x, const coordinate_e y) {
    display.fillRectangle(cc0(x), cc0(y), 10, 10, WATER);

    display.fillRectangle(cc0(x), cc(y, 2), 10, 6, METAL_SHIP);
}

void drawMiddleVertical(const coordinate_e x, const coordinate_e y) {
    display.fillRectangle(cc0(x), cc0(y), 10, 10, WATER);

    display.fillRectangle(cc(x, 2), cc0(y), 6, 10, METAL_SHIP);
}

void drawEndVertical(const coordinate_e x, const coordinate_e y) {
    display.fillRectangle(cc0(x), cc0(y), 10, 10, WATER);

    display.fillRectangle(cc(x, 2), cc0(y), 6, 10, METAL_SHIP);
    display.drawHorizontalLine(cc(x, 4), cc(y, 8), 2, 1, WATER);
    display.drawHorizontalLine(cc(x, 3), cc(y, 9), 4, 1, WATER);
}

void drawEndHorizontal(const coordinate_e x, const coordinate_e y) {
    display.fillRectangle(cc0(x), cc0(y), 10, 10, WATER);

    display.fillRectangle(cc0(x), 19 + 2 + y * 11, 10, 6, METAL_SHIP);
    display.drawVerticalLine(19 + 8 + x * 11, 19 + 4 + y * 11, 2, 1, WATER);
    display.drawVerticalLine(19 + 9 + x * 11, 19 + 3 + y * 11, 4, 1, WATER);
}

void drawDamagedShipPart(const coordinate_e x, const coordinate_e y) {
    display.fillRectangle(cc0(x), cc0(y), 10, 10, CLOUD);
    
    display.fillRectangle(cc0(x), cc(y, 3), 2, 4, CLOUD_DARK);
    display.drawVerticalLine(cc(x, 2), cc(y, 1), 3, 1, CLOUD_DARK);
    display.fillRectangle(cc(x, 2), cc(y, 3), 6, 6, CLOUD_BLACK);
    display.drawHorizontalLine(cc(x, 5), cc(y, 1), 2, 1, CLOUD_DARK);
    display.drawHorizontalLine(cc(x, 6), cc(y, 2), 2, 1, CLOUD_DARK);
    display.fillRectangle(cc(x, 8), cc(y, 4), 2, 3, CLOUD_DARK);
    display.drawHorizontalLine(cc(x, 6), cc(y, 7), 2, 1, CLOUD_DARK);
    display.fillRectangle(cc(x, 3), cc(y, 8), 5, 2, CLOUD_DARK);
    display.drawHorizontalLine(cc(x, 4), cc(y, 2), 2, 1, CLOUD_BLACK);
    display.drawVerticalLine(cc(x, 1), cc(y, 6), 3, 1, CLOUD_BLACK);
    display.drawPixel(cc(x, 5), cc(y, 3), FIRE_RED);
    display.drawHorizontalLine(cc(x, 4), cc(y, 4), 3, 1, FIRE_RED);
    display.drawVerticalLine(cc(x, 3), cc(y, 5), 2, 1, FIRE_RED);
    display.drawPixel(cc(x, 5), cc(y, 4), FIRE_ORANGE);
    display.fillRectangle(cc(x, 4), cc(y, 5), 3, 2, FIRE_ORANGE);
    display.drawPixel(cc(x, 5), cc(y, 6), FIRE_YELLOW);
    display.drawHorizontalLine(cc(x, 4), cc(y, 7), 2, 1, FIRE_YELLOW);
}

static void drawDamageHorizontal(const coordinate_e x, const coordinate_e y) {
    display.fillRectangle(cc(x, 2), cc(y, 2), 2, 2, FIRE_ORANGE);
    display.drawPixel(cc(x, 1), cc(y, 3), FIRE_ORANGE);
    display.drawPixel(cc(x, 2), cc(y, 2), FIRE_YELLOW);

    display.fillRectangle(cc(x, 4), cc(y, 5), 2, 4, CLOUD_BLACK);
    display.fillRectangle(cc(x, 3), cc(y, 5), 2, 3, FIRE_RED);
    display.drawPixel(cc(x, 3), cc(y, 5), FIRE_ORANGE);
    display.drawPixel(cc(x, 2), cc(y, 6), FIRE_ORANGE);
    display.drawPixel(cc(x, 3), cc(y, 6), FIRE_YELLOW);
    display.drawVerticalLine(cc(x, 6), cc(y, 6), 3, 1, CLOUD_DARK);

    display.fillRectangle(cc(x, 7), cc(y, 2), 3, 3, CLOUD_BLACK);
    display.fillRectangle(cc(x, 7), cc(y, 2), 2, 2, FIRE_RED);
    display.drawPixel(cc(x, 7), cc(y, 2), FIRE_ORANGE);
    display.drawHorizontalLine(cc(x, 8), cc(y, 5), 2, 1, CLOUD_DARK);
}

static void drawDamageVertical(const coordinate_e x, const coordinate_e y) {
    display.fillRectangle(cc(x, 2), cc(y, 2), 2, 2, FIRE_ORANGE);
    display.drawPixel(cc(x, 2), cc(y, 2), FIRE_YELLOW);

    display.fillRectangle(cc(x, 4), cc(y, 5), 2, 4, CLOUD_BLACK);
    display.fillRectangle(cc(x, 3), cc(y, 5), 2, 3, FIRE_RED);
    display.drawPixel(cc(x, 3), cc(y, 5), FIRE_ORANGE);
    display.drawPixel(cc(x, 2), cc(y, 6), FIRE_ORANGE);
    display.drawPixel(cc(x, 3), cc(y, 6), FIRE_YELLOW);
    display.drawVerticalLine(cc(x, 6), cc(y, 6), 3, 1, CLOUD_DARK);

    display.fillRectangle(cc(x, 6), cc(y, 2), 3, 3, CLOUD_BLACK);
    display.fillRectangle(cc(x, 6), cc(y, 2), 2, 2, FIRE_RED);
    display.drawPixel(cc(x, 6), cc(y, 2), FIRE_ORANGE);
    display.drawVerticalLine(cc(x, 9), cc(y, 2), 4, 1, CLOUD_DARK);
    display.drawHorizontalLine(cc(x, 7), cc(y, 5), 2, 1, CLOUD_DARK);
}

void drawDestroyedBoatHorizontal(const coordinate_e x, const coordinate_e y) {
    drawBoatHorizontal(x, y);
    drawDamageHorizontal(x, y);
}

void drawDestroyedBoatVertical(const coordinate_e x, const coordinate_e y) {
    drawBoatVertical(x, y);
    drawDamageVertical(x, y);
}

void drawDestroyedBowHorizontal(const coordinate_e x, const coordinate_e y) {
    drawBowHorizontal(x, y);
    drawDamageHorizontal(x, y);
}

void drawDestroyedBowVertical(const coordinate_e x, const coordinate_e y) {
    drawBowVertical(x, y);
    drawDamageVertical(x, y);
}

void drawDestroyedMiddleHorizontal(const coordinate_e x, const coordinate_e y) {
    drawMiddleHorizontal(x, y);
    drawDamageHorizontal(x, y);
}

void drawDestroyedMiddleVertical(const coordinate_e x, const coordinate_e y) {
    drawMiddleVertical(x, y);
    drawDamageVertical(x, y);
}

void drawDestroyedEndHorizontal(const coordinate_e x, const coordinate_e y) {
    drawEndHorizontal(x, y);
    drawDamageHorizontal(x, y);
}

void drawDestroyedEndVertical(const coordinate_e x, const coordinate_e y) {
    drawEndVertical(x, y);
    drawDamageVertical(x, y);
}


#endif
