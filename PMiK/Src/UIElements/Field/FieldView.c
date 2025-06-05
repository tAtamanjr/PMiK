/**
 * \file	FieldView.c
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef FIELD_VIEW_H
#include "FieldView.h"


static void drawButtonsDescriptions();

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
                case BOW_VERTICAL:
                    drawBowVertical(x, y);
                    break;
                case MIDDLE_PART_HORIZONTAL:
                    drawMiddleHorizontal(x, y);
                    break;
                case MIDDLE_PART_VERTICAL:
                    drawMiddleVertical(x, y);
                    break;
                case END_HORIZONTAL:
                    drawEndHorizontal(x, y);
                    break;
                case END_VERTICAL:
                    drawEndVertical(x, y);
                    break;
                case DAMAGED_BOW_HORIZONTAL:
                case DAMAGED_BOW_VERTICAL:
                case DAMAGED_MIDDLE_PART_HORIZONTAL:
                case DAMAGED_MIDDLE_PART_VERTICAL:
                case DAMAGED_END_HORIZONTAL:
                case DAMAGED_END_VERTICAL:
                    drawDamagedShipPart(x, y);
                    break;
                case DESTROYED_BOAT_HORIZONTAL:
                    drawDestroyedBoatHorizontal(x, y);
                    break;
                case DESTROYED_BOAT_VERTICAL:
                    drawDestroyedBoatVertical(x, y);
                    break;
                case DESTROYED_BOW_HORIZONTAL:
                    drawDestroyedBowHorizontal(x, y);
                    break;
                case DESTROYED_BOW_VERTICAL:
                    drawDestroyedBowVertical(x, y);
                    break;
                case DESTROYED_MIDDLE_PART_HORIZONTAL:
                    drawMiddleHorizontal(x, y);
                    break;
                case DESTROYED_MIDDLE_PART_VERTICAL:
                    drawDestroyedMiddleVertical(x, y);
                    break;
                case DESTROYED_END_HORIZONTAL:
                    drawDestroyedEndHorizontal(x, y);
                    break;
                case DESTROYED_END_VERTICAL:
                    drawDestroyedEndVertical(x, y);
                    break;
                default:
                    display.fillRectangle(coordinateToPixel(x), coordinateToPixel(y), 10, 10, CLOUD);
                    break;
            }
        }
    }

    drawAim(joystick.cell->x, joystick.cell->y);

    display.drawHorizontalLine(0, 128, 128, 2, RED);
    display.fillRectangle(0, 130, 128, 34, BLACK);
    drawButtonsDescriptions();

    drawSmallLetter(joystick.cell->x, 0, 131, RED);
    drawNumber(joystick.cell->y + 1, 10, 131, RED);
}

void drawCell(const uint8_t x, const uint8_t y) {
    switch (someField.read(&someField, (coordinates_t) {x, y})) {
        case WATER_CELL:
            display.fillRectangle(coordinateToPixel(x), coordinateToPixel(y), 10, 10, WATER);
            return;
        case BOAT_HORIZONTAL:
            drawBoatHorizontal(x, y);
            return;
        case BOAT_VERTICAL:
            drawBoatVertical(x, y);
            return;
        case BOW_HORIZONTAL:
            drawBowHorizontal(x, y);
            return;
        case BOW_VERTICAL:
            drawBowVertical(x, y);
            return;
        case MIDDLE_PART_HORIZONTAL:
            drawMiddleHorizontal(x, y);
            return;
        case MIDDLE_PART_VERTICAL:
            drawMiddleVertical(x, y);
            return;
        case END_HORIZONTAL:
            drawEndHorizontal(x, y);
            return;
        case END_VERTICAL:
            drawEndVertical(x, y);
            return;
        case DAMAGED_BOW_HORIZONTAL:
        case DAMAGED_BOW_VERTICAL:
        case DAMAGED_MIDDLE_PART_HORIZONTAL:
        case DAMAGED_MIDDLE_PART_VERTICAL:
        case DAMAGED_END_HORIZONTAL:
        case DAMAGED_END_VERTICAL:
            drawDamagedShipPart(x, y);
            return;
        case DESTROYED_BOAT_HORIZONTAL:
            drawDestroyedBoatHorizontal(x, y);
            return;
        case DESTROYED_BOAT_VERTICAL:
            drawDestroyedBoatVertical(x, y);
            return;
        case DESTROYED_BOW_HORIZONTAL:
            drawDestroyedBowHorizontal(x, y);
            return;
        case DESTROYED_BOW_VERTICAL:
            drawDestroyedBowVertical(x, y);
            return;
        case DESTROYED_MIDDLE_PART_HORIZONTAL:
            drawDestroyedMiddleHorizontal(x, y);
            return;
        case DESTROYED_MIDDLE_PART_VERTICAL:
            drawDestroyedMiddleVertical(x, y);
            return;
        case DESTROYED_END_HORIZONTAL:
            drawDestroyedEndHorizontal(x, y);
            return;
        case DESTROYED_END_VERTICAL:
            drawDestroyedEndVertical(x, y);
            return;
        default:
            display.fillRectangle(coordinateToPixel(x), coordinateToPixel(y), 10, 10, CLOUD);
            return;
    }
}

void drawAim(const uint8_t x, const uint8_t y) {
    color_t color = RED;
    switch (someField.read(&someField, (coordinates_t) {x, y})) {
        case WATER_CELL:
        case DESTROYED_BOAT_HORIZONTAL:
        case DESTROYED_BOAT_VERTICAL:
        case DESTROYED_BOW_HORIZONTAL:
        case DESTROYED_BOW_VERTICAL:
        case DESTROYED_MIDDLE_PART_HORIZONTAL:
        case DESTROYED_MIDDLE_PART_VERTICAL:
        case DESTROYED_END_HORIZONTAL:
        case DESTROYED_END_VERTICAL:
            color = FIRE_YELLOW;
            break;
        default:
            break;
    }

    display.fillRectangle(coordinateToPixel(x), coordinateToPixel(y), 2, 2, color);
    display.fillRectangle(coordinateToPixelWithShift(x, 8), coordinateToPixel(y), 2, 2, color);
    display.fillRectangle(coordinateToPixelWithShift(x, 8), coordinateToPixelWithShift(y, 8), 2, 2, color);
    display.fillRectangle(coordinateToPixel(x), coordinateToPixelWithShift(y, 8), 2, 2, color);
    display.fillRectangle(coordinateToPixelWithShift(x, 1), coordinateToPixelWithShift(y, 1), 2, 2, color);
    display.fillRectangle(coordinateToPixelWithShift(x, 7), coordinateToPixelWithShift(y, 1), 2, 2, color);
    display.fillRectangle(coordinateToPixelWithShift(x, 7), coordinateToPixelWithShift(y, 7), 2, 2, color);
    display.fillRectangle(coordinateToPixelWithShift(x, 1), coordinateToPixelWithShift(y, 7), 2, 2, color);
}

static void drawButtonsDescriptions() {
    display.fillRectangle(42, 132, 4, 6, WIRE_GRAY);
    display.drawVerticalLine(41, 133, 4, 1, WIRE_GRAY);
    display.drawVerticalLine(46, 133, 4, 1, WIRE_GRAY);
    drawSmallLetter(M_s, 48, 131, WIRE_GRAY);
    drawSmallLetter(E_s, 56, 131, WIRE_GRAY);
    drawSmallLetter(N_s, 64, 131, WIRE_GRAY);
    drawSmallLetter(U_s, 72, 131, WIRE_GRAY);

    display.fillRectangle(89, 132, 4, 6, WIRE_PURPLE);
    display.drawVerticalLine(88, 133, 4, 1, WIRE_PURPLE);
    display.drawVerticalLine(93, 133, 4, 1, WIRE_PURPLE);
    drawSmallLetter(F_s, 95, 131, WIRE_PURPLE);
    drawSmallLetter(I_s, 103, 131, WIRE_PURPLE);
    drawSmallLetter(R_s, 111, 131, WIRE_PURPLE);
    drawSmallLetter(E_s, 119, 131, WIRE_PURPLE);

    display.fillRectangle(42, 148, 4, 6, WIRE_BLUE);
    display.drawVerticalLine(41, 149, 4, 1, WIRE_BLUE);
    display.drawVerticalLine(46, 149, 4, 1, WIRE_BLUE);
    drawSmallLetter(N_s, 48, 147, WIRE_BLUE);
    drawSmallLetter(O_s, 56, 147, WIRE_BLUE);
    drawSmallLetter(N_s, 64, 147, WIRE_BLUE);
    drawSmallLetter(E_s, 72, 147, WIRE_BLUE);

    display.fillRectangle(89, 148, 4, 6, WIRE_GREEN);
    display.drawVerticalLine(88, 149, 4, 1, WIRE_GREEN);
    display.drawVerticalLine(93, 149, 4, 1, WIRE_GREEN);
    drawSmallLetter(N_s, 95, 147, WIRE_GREEN);
    drawSmallLetter(O_s, 103, 147, WIRE_GREEN);
    drawSmallLetter(N_s, 111, 147, WIRE_GREEN);
    drawSmallLetter(E_s, 119, 147, WIRE_GREEN);
}


#endif
