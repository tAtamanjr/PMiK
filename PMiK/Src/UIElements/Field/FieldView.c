/**
 * \file	FieldView.c
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef FIELD_VIEW_H
#include "FieldView.h"


void drawField() {
    display.fillRectangle(0, 0, 128, 128, WHITE);

    display.fillRectangle(19, 19, 109, 109, CLOUD);
    display.drawHorizontalLine(0, 17, 128, 2, BLACK);
    display.drawVerticalLine(17, 0, 128, 2, BLACK);
    for (uint8_t i = 1; i < 10; i++) {
        display.drawHorizontalLine(0, 18 + i * 11, 128, 1, BLACK);
        display.drawVerticalLine(18 + i * 11, 0, 128, 1, BLACK);
    }

    drawBigLetter(B_b, 1, 3, BLACK);
    drawBigLetter(B_b, 9, 3, BLACK);

    for (uint8_t letter = 0; letter <= 9; letter++) {
        drawSmallLetter(letter, 20 + 11 * letter, 8, BLACK);
    }
    for (uint8_t number = 1; number <= 9; number++) {
        drawNumber(number, 8, 20 + 11 * (number - 1), BLACK);
    }
    drawNumber(10, 0, 119, BLACK);

    for (uint8_t y = A; y <= J; y++) {
        for (uint8_t x = A; x <= J; x++) {
            switch (someField.read(&someField, (coordinates_t) {x, y})) {
                case BOAT_HORIZONTAL:
                    drawBoatHorizontal(x, y);
                    break;
                case BOAT_VERTICAL:
                    drawBoatVertical(x, y);
                    break;
                case BOW_HORIZONTAL:
                    drawBowHorizontal(x, y);
                    break;
                case BOW_VERTICLE:
                    drawBowVertical(x, y);
                    break;
                case MIDDLE_PART_HORIZONTAL:
                    drawMiddleHorizontal(x, y);
                    break;
                case MIDDLE_PART_VERTICLE:
                    drawMiddleVertical(x, y);
                    break;
                case END_HORIZONTAL:
                    drawEndHorizontal(x, y);
                    break;
                case END_VERTICLE:
                    drawEndVertical(x, y);
                    break;
                default:
                    break;
            }
        }
    }

    drawAim(joystick.cell->x, joystick.cell->y);

    display.drawHorizontalLine(0, 128, 128, 2, RED);
    display.fillRectangle(0, 130, 128, 34, BLACK);

    drawSmallLetter(joystick.cell->x, 1, 131, RED);
    drawNumber(joystick.cell->y + 1, 11, 131, RED);
}

void drawCell(const uint8_t x, const uint8_t y) {
    switch (someField.read(&someField, (coordinates_t) {x, y})) {
    case BOAT_HORIZONTAL:
        drawBoatHorizontal(x, y);
        return;
    case BOAT_VERTICAL:
        drawBoatVertical(x, y);
        return;
    case BOW_HORIZONTAL:
        drawBowHorizontal(x, y);
        return;
    case BOW_VERTICLE:
        drawBowVertical(x, y);
        return;
    case MIDDLE_PART_HORIZONTAL:
        drawMiddleHorizontal(x, y);
        return;
    case MIDDLE_PART_VERTICLE:
        drawMiddleVertical(x, y);
        return;
    case END_HORIZONTAL:
        drawEndHorizontal(x, y);
        return;
    case END_VERTICLE:
        drawEndVertical(x, y);
        return;
    default:
        display.fillRectangle(19 + x * 11, 19 + y * 11, 10, 10, CLOUD);
        return;
    }
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


#endif
