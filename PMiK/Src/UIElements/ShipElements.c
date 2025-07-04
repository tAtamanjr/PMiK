/**
 * @file	ShipViews.c
 * @brief   Functions for drawing ship parts on the field
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef SHIP_VIEWS_H
#include "ShipElements.h"


static void drawDamageHorizontal(const coordinate_e x, const coordinate_e y);
static void drawDamageVertical(const coordinate_e x, const coordinate_e y);


/**
 * @brief Draw boat that looks up
 * @param x - x axis coordinates on the field
 * @param y - y axis coordinates on the field
 */
void drawBoatVertical(const coordinate_e x, const coordinate_e y) {
    display.fillRectangle(coordinateToPixel(x), coordinateToPixel(y), 10, 10, WATER);

    display.drawHorizontalLine(coordinateToPixelWithShift(x, 4), coordinateToPixel(y), 2, 1, WOOD_BOAT);
    display.drawHorizontalLine(coordinateToPixelWithShift(x, 3), coordinateToPixelWithShift(y, 1), 4, 1, WOOD_BOAT);
    display.fillRectangle(coordinateToPixelWithShift(x, 2), coordinateToPixelWithShift(y, 2), 6, 8, WOOD_BOAT);
    display.drawHorizontalLine(coordinateToPixelWithShift(x, 4), coordinateToPixelWithShift(y, 8), 2, 1, WATER);
    display.drawHorizontalLine(coordinateToPixelWithShift(x, 3), coordinateToPixelWithShift(y, 9), 4, 1, WATER);
}

/**
 * @brief Draw boat that looks left
 * @param x - x axis coordinates on the field
 * @param y - y axis coordinates on the field
 */
void drawBoatHorizontal(const coordinate_e x, const coordinate_e y) {
    display.fillRectangle(coordinateToPixel(x), coordinateToPixel(y), 10, 10, WATER);

    display.drawVerticalLine(coordinateToPixel(x), 19 + 4 + y * 11, 2, 1, WOOD_BOAT);
    display.drawVerticalLine(coordinateToPixelWithShift(x, 1), coordinateToPixelWithShift(y, 3), 4, 1, WOOD_BOAT);
    display.fillRectangle(coordinateToPixelWithShift(x, 2), coordinateToPixelWithShift(y, 2), 8, 6, WOOD_BOAT);
    display.drawVerticalLine(coordinateToPixelWithShift(x, 8), coordinateToPixelWithShift(y, 4), 2, 1, WATER);
    display.drawVerticalLine(coordinateToPixelWithShift(x, 9), coordinateToPixelWithShift(y, 3), 4, 1, WATER);
}

/**
 * @brief Draw ship's bow that looks up
 * @param x - x axis coordinates on the field
 * @param y - y axis coordinates on the field
 */
void drawBowVertical(const coordinate_e x, const coordinate_e y) {
    display.fillRectangle(coordinateToPixel(x), coordinateToPixel(y), 10, 10, WATER);

    display.drawHorizontalLine(coordinateToPixelWithShift(x, 4), coordinateToPixel(y), 2, 1, METAL_SHIP);
    display.drawHorizontalLine(coordinateToPixelWithShift(x, 3), coordinateToPixelWithShift(y, 1), 4, 1, METAL_SHIP);
    display.fillRectangle(coordinateToPixelWithShift(x, 2), coordinateToPixelWithShift(y, 2), 6, 8, METAL_SHIP);
}

/**
 * @brief Draw ship's bow that looks left
 * @param x - x axis coordinates on the field
 * @param y - y axis coordinates on the field
 */
void drawBowHorizontal(const coordinate_e x, const coordinate_e y) {
    display.fillRectangle(coordinateToPixel(x), coordinateToPixel(y), 10, 10, WATER);

    display.drawVerticalLine(coordinateToPixel(x), coordinateToPixelWithShift(y, 4), 2, 1, METAL_SHIP);
    display.drawVerticalLine(coordinateToPixelWithShift(x, 1), coordinateToPixelWithShift(y, 3), 4, 1, METAL_SHIP);
    display.fillRectangle(coordinateToPixelWithShift(x, 2), coordinateToPixelWithShift(y, 2), 8, 6, METAL_SHIP);
}

/**
 * @brief Draw ship's middle part that looks up
 * @param x - x axis coordinates on the field
 * @param y - y axis coordinates on the field
 */
void drawMiddleHorizontal(const coordinate_e x, const coordinate_e y) {
    display.fillRectangle(coordinateToPixel(x), coordinateToPixel(y), 10, 10, WATER);

    display.fillRectangle(coordinateToPixel(x), coordinateToPixelWithShift(y, 2), 10, 6, METAL_SHIP);
}

/**
 * @brief Draw ship's middle part that looks left
 * @param x - x axis coordinates on the field
 * @param y - y axis coordinates on the field
 */
void drawMiddleVertical(const coordinate_e x, const coordinate_e y) {
    display.fillRectangle(coordinateToPixel(x), coordinateToPixel(y), 10, 10, WATER);

    display.fillRectangle(coordinateToPixelWithShift(x, 2), coordinateToPixel(y), 6, 10, METAL_SHIP);
}

/**
 * @brief Draw ship's end that looks up
 * @param x - x axis coordinates on the field
 * @param y - y axis coordinates on the field
 */
void drawEndVertical(const coordinate_e x, const coordinate_e y) {
    display.fillRectangle(coordinateToPixel(x), coordinateToPixel(y), 10, 10, WATER);

    display.fillRectangle(coordinateToPixelWithShift(x, 2), coordinateToPixel(y), 6, 10, METAL_SHIP);
    display.drawHorizontalLine(coordinateToPixelWithShift(x, 4), coordinateToPixelWithShift(y, 8), 2, 1, WATER);
    display.drawHorizontalLine(coordinateToPixelWithShift(x, 3), coordinateToPixelWithShift(y, 9), 4, 1, WATER);
}

/**
 * @brief Draw ship's end that looks left
 * @param x - x axis coordinates on the field
 * @param y - y axis coordinates on the field
 */
void drawEndHorizontal(const coordinate_e x, const coordinate_e y) {
    display.fillRectangle(coordinateToPixel(x), coordinateToPixel(y), 10, 10, WATER);

    display.fillRectangle(coordinateToPixel(x), 19 + 2 + y * 11, 10, 6, METAL_SHIP);
    display.drawVerticalLine(19 + 8 + x * 11, 19 + 4 + y * 11, 2, 1, WATER);
    display.drawVerticalLine(19 + 9 + x * 11, 19 + 3 + y * 11, 4, 1, WATER);
}

/**
 * @brief Draw damaged ship part/boat that looks like cloud with fire and smoke
 * @param x - x axis coordinates on the field
 * @param y - y axis coordinates on the field
 */
void drawDamagedShipPart(const coordinate_e x, const coordinate_e y) {
    display.fillRectangle(coordinateToPixel(x), coordinateToPixel(y), 10, 10, CLOUD);
    
    display.fillRectangle(coordinateToPixel(x), coordinateToPixelWithShift(y, 3), 2, 4, CLOUD_DARK);
    display.drawVerticalLine(coordinateToPixelWithShift(x, 2), coordinateToPixelWithShift(y, 1), 3, 1, CLOUD_DARK);
    display.fillRectangle(coordinateToPixelWithShift(x, 2), coordinateToPixelWithShift(y, 3), 6, 6, CLOUD_BLACK);
    display.drawHorizontalLine(coordinateToPixelWithShift(x, 5), coordinateToPixelWithShift(y, 1), 2, 1, CLOUD_DARK);
    display.drawHorizontalLine(coordinateToPixelWithShift(x, 6), coordinateToPixelWithShift(y, 2), 2, 1, CLOUD_DARK);
    display.fillRectangle(coordinateToPixelWithShift(x, 8), coordinateToPixelWithShift(y, 4), 2, 3, CLOUD_DARK);
    display.drawHorizontalLine(coordinateToPixelWithShift(x, 6), coordinateToPixelWithShift(y, 7), 2, 1, CLOUD_DARK);
    display.fillRectangle(coordinateToPixelWithShift(x, 3), coordinateToPixelWithShift(y, 8), 5, 2, CLOUD_DARK);
    display.drawHorizontalLine(coordinateToPixelWithShift(x, 4), coordinateToPixelWithShift(y, 2), 2, 1, CLOUD_BLACK);
    display.drawVerticalLine(coordinateToPixelWithShift(x, 1), coordinateToPixelWithShift(y, 6), 3, 1, CLOUD_BLACK);
    display.drawPixel(coordinateToPixelWithShift(x, 5), coordinateToPixelWithShift(y, 3), FIRE_RED);
    display.drawHorizontalLine(coordinateToPixelWithShift(x, 4), coordinateToPixelWithShift(y, 4), 3, 1, FIRE_RED);
    display.drawVerticalLine(coordinateToPixelWithShift(x, 3), coordinateToPixelWithShift(y, 5), 2, 1, FIRE_RED);
    display.drawPixel(coordinateToPixelWithShift(x, 5), coordinateToPixelWithShift(y, 4), FIRE_ORANGE);
    display.fillRectangle(coordinateToPixelWithShift(x, 4), coordinateToPixelWithShift(y, 5), 3, 2, FIRE_ORANGE);
    display.drawPixel(coordinateToPixelWithShift(x, 5), coordinateToPixelWithShift(y, 6), FIRE_YELLOW);
    display.drawHorizontalLine(coordinateToPixelWithShift(x, 4), coordinateToPixelWithShift(y, 7), 2, 1, FIRE_YELLOW);
}

/**
 * @brief Draw damage elements to boat/ship's part that looks up
 * @param x - x axis coordinates on the field
 * @param y - y axis coordinates on the field
 */
static void drawDamageHorizontal(const coordinate_e x, const coordinate_e y) {
    display.fillRectangle(coordinateToPixelWithShift(x, 2), coordinateToPixelWithShift(y, 2), 2, 2, FIRE_ORANGE);
    display.drawPixel(coordinateToPixelWithShift(x, 1), coordinateToPixelWithShift(y, 3), FIRE_ORANGE);
    display.drawPixel(coordinateToPixelWithShift(x, 2), coordinateToPixelWithShift(y, 2), FIRE_YELLOW);

    display.fillRectangle(coordinateToPixelWithShift(x, 4), coordinateToPixelWithShift(y, 5), 2, 4, CLOUD_BLACK);
    display.fillRectangle(coordinateToPixelWithShift(x, 3), coordinateToPixelWithShift(y, 5), 2, 3, FIRE_RED);
    display.drawPixel(coordinateToPixelWithShift(x, 3), coordinateToPixelWithShift(y, 5), FIRE_ORANGE);
    display.drawPixel(coordinateToPixelWithShift(x, 2), coordinateToPixelWithShift(y, 6), FIRE_ORANGE);
    display.drawPixel(coordinateToPixelWithShift(x, 3), coordinateToPixelWithShift(y, 6), FIRE_YELLOW);
    display.drawVerticalLine(coordinateToPixelWithShift(x, 6), coordinateToPixelWithShift(y, 6), 3, 1, CLOUD_DARK);

    display.fillRectangle(coordinateToPixelWithShift(x, 7), coordinateToPixelWithShift(y, 2), 3, 3, CLOUD_BLACK);
    display.fillRectangle(coordinateToPixelWithShift(x, 7), coordinateToPixelWithShift(y, 2), 2, 2, FIRE_RED);
    display.drawPixel(coordinateToPixelWithShift(x, 7), coordinateToPixelWithShift(y, 2), FIRE_ORANGE);
    display.drawHorizontalLine(coordinateToPixelWithShift(x, 8), coordinateToPixelWithShift(y, 5), 2, 1, CLOUD_DARK);
}

/**
 * @brief Draw damage elements to boat/ship's part that looks left
 * @param x - x axis coordinates on the field
 * @param y - y axis coordinates on the field
 */
static void drawDamageVertical(const coordinate_e x, const coordinate_e y) {
    display.fillRectangle(coordinateToPixelWithShift(x, 2), coordinateToPixelWithShift(y, 2), 2, 2, FIRE_ORANGE);
    display.drawPixel(coordinateToPixelWithShift(x, 2), coordinateToPixelWithShift(y, 2), FIRE_YELLOW);

    display.fillRectangle(coordinateToPixelWithShift(x, 4), coordinateToPixelWithShift(y, 5), 2, 4, CLOUD_BLACK);
    display.fillRectangle(coordinateToPixelWithShift(x, 3), coordinateToPixelWithShift(y, 5), 2, 3, FIRE_RED);
    display.drawPixel(coordinateToPixelWithShift(x, 3), coordinateToPixelWithShift(y, 5), FIRE_ORANGE);
    display.drawPixel(coordinateToPixelWithShift(x, 2), coordinateToPixelWithShift(y, 6), FIRE_ORANGE);
    display.drawPixel(coordinateToPixelWithShift(x, 3), coordinateToPixelWithShift(y, 6), FIRE_YELLOW);
    display.drawVerticalLine(coordinateToPixelWithShift(x, 6), coordinateToPixelWithShift(y, 6), 3, 1, CLOUD_DARK);

    display.fillRectangle(coordinateToPixelWithShift(x, 6), coordinateToPixelWithShift(y, 2), 3, 3, CLOUD_BLACK);
    display.fillRectangle(coordinateToPixelWithShift(x, 6), coordinateToPixelWithShift(y, 2), 2, 2, FIRE_RED);
    display.drawPixel(coordinateToPixelWithShift(x, 6), coordinateToPixelWithShift(y, 2), FIRE_ORANGE);
    display.drawVerticalLine(coordinateToPixelWithShift(x, 9), coordinateToPixelWithShift(y, 2), 4, 1, CLOUD_DARK);
    display.drawHorizontalLine(coordinateToPixelWithShift(x, 7), coordinateToPixelWithShift(y, 5), 2, 1, CLOUD_DARK);
}

/**
 * @brief Draw destroyed boat that looks up
 * @param x - x axis coordinates on the field
 * @param y - y axis coordinates on the field
 */
void drawDestroyedBoatHorizontal(const coordinate_e x, const coordinate_e y) {
    drawBoatHorizontal(x, y);
    drawDamageHorizontal(x, y);
}

/**
 * @brief Draw destroyed boat that looks left
 * @param x - x axis coordinates on the field
 * @param y - y axis coordinates on the field
 */
void drawDestroyedBoatVertical(const coordinate_e x, const coordinate_e y) {
    drawBoatVertical(x, y);
    drawDamageVertical(x, y);
}

/**
 * @brief Draw destroyed ships's bow that looks up
 * @param x - x axis coordinates on the field
 * @param y - y axis coordinates on the field
 */
void drawDestroyedBowHorizontal(const coordinate_e x, const coordinate_e y) {
    drawBowHorizontal(x, y);
    drawDamageHorizontal(x, y);
}

/**
 * @brief Draw destroyed ship's bow that looks left
 * @param x - x axis coordinates on the field
 * @param y - y axis coordinates on the field
 */
void drawDestroyedBowVertical(const coordinate_e x, const coordinate_e y) {
    drawBowVertical(x, y);
    drawDamageVertical(x, y);
}

/**
 * @brief Draw destroyed ship's middle part that looks up
 * @param x - x axis coordinates on the field
 * @param y - y axis coordinates on the field
 */
void drawDestroyedMiddleHorizontal(const coordinate_e x, const coordinate_e y) {
    drawMiddleHorizontal(x, y);
    drawDamageHorizontal(x, y);
}

/**
 * @brief Draw destroyed ship's middle part that looks left
 * @param x - x axis coordinates on the field
 * @param y - y axis coordinates on the field
 */
void drawDestroyedMiddleVertical(const coordinate_e x, const coordinate_e y) {
    drawMiddleVertical(x, y);
    drawDamageVertical(x, y);
}

/**
 * @brief Draw destroyed ship's end that looks up
 * @param x - x axis coordinates on the field
 * @param y - y axis coordinates on the field
 */
void drawDestroyedEndHorizontal(const coordinate_e x, const coordinate_e y) {
    drawEndHorizontal(x, y);
    drawDamageHorizontal(x, y);
}

/**
 * @brief Draw destroyed ship's end that looks left
 * @param x - x axis coordinates on the field
 * @param y - y axis coordinates on the field
 */
void drawDestroyedEndVertical(const coordinate_e x, const coordinate_e y) {
    drawEndVertical(x, y);
    drawDamageVertical(x, y);
}


#endif
