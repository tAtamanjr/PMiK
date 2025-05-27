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

    for (uint8_t y = A; y <= J; y++) {
        for (uint8_t x = A; x <= J; x++) {
            if (someField.read(&someField, (coordinates_t) {x = x, y = y}) == BOAT_HORIZONTAL) drawBoatHorizontal(x, y);
            else if (someField.read(&someField, (coordinates_t) {x = x, y = y}) == BOAT_VERTICAL) drawBoatVertical(x, y);
            else if (someField.read(&someField, (coordinates_t) {x = x, y = y}) == BOW_HORIZONTAL) drawBowHorizontal(x, y);
            else if (someField.read(&someField, (coordinates_t) {x = x, y = y}) == BOW_VERTICLE) drawBowVertical(x, y);
            else if (someField.read(&someField, (coordinates_t) {x = x, y = y}) == MIDDLE_PART_HORIZONTAL) drawMiddleHorizontal(x, y);
            else if (someField.read(&someField, (coordinates_t) {x = x, y = y}) == MIDDLE_PART_VERTICLE) drawMiddleVertical(x, y);
            else if (someField.read(&someField, (coordinates_t) {x = x, y = y}) == END_HORIZONTAL) drawEndHorizontal(x, y);
            else if (someField.read(&someField, (coordinates_t) {x = x, y = y}) == END_VERTICLE) drawEndVertical(x, y);
        }
    }
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

void drawAim() {
    display.fillRectangle(19 + joystick.cell->x * 11, 19 + joystick.cell->y * 11, 2, 2, RED);
    display.fillRectangle(19 + joystick.cell->x * 11 + 8, 19 + joystick.cell->y * 11, 2, 2, RED);
    display.fillRectangle(19 + joystick.cell->x * 11 + 8, 19 + joystick.cell->y * 11 + 8, 2, 2, RED);
    display.fillRectangle(19 + joystick.cell->x * 11, 19 + joystick.cell->y * 11 + 8, 2, 2, RED);
    display.fillRectangle(19 + joystick.cell->x * 11 + 1, 19 + joystick.cell->y * 11 + 1, 2, 2, RED);
    display.fillRectangle(19 + joystick.cell->x * 11 + 7, 19 + joystick.cell->y * 11 + 1, 2, 2, RED);
    display.fillRectangle(19 + joystick.cell->x * 11 + 7, 19 + joystick.cell->y * 11 + 7, 2, 2, RED);
    display.fillRectangle(19 + joystick.cell->x * 11 + 1, 19 + joystick.cell->y * 11 + 7, 2, 2, RED);
}

void removeAim() {
    if (someField.read(&someField, (coordinates_t) {joystick.cell->x, joystick.cell->y}) == BOAT_HORIZONTAL) drawBoatHorizontal(joystick.cell->x, joystick.cell->y);
    else if (someField.read(&someField, (coordinates_t) {joystick.cell->x, joystick.cell->y}) == BOAT_VERTICAL) drawBoatVertical(joystick.cell->x, joystick.cell->y);
    else if (someField.read(&someField, (coordinates_t) {joystick.cell->x, joystick.cell->y}) == BOW_HORIZONTAL) drawBowHorizontal(joystick.cell->x, joystick.cell->y);
    else if (someField.read(&someField, (coordinates_t) {joystick.cell->x, joystick.cell->y}) == BOW_VERTICLE) drawBowVertical(joystick.cell->x, joystick.cell->y);
    else if (someField.read(&someField, (coordinates_t) {joystick.cell->x, joystick.cell->y}) == MIDDLE_PART_HORIZONTAL) drawMiddleHorizontal(joystick.cell->x, joystick.cell->y);
    else if (someField.read(&someField, (coordinates_t) {joystick.cell->x, joystick.cell->y}) == MIDDLE_PART_VERTICLE) drawMiddleVertical(joystick.cell->x, joystick.cell->y);
    else if (someField.read(&someField, (coordinates_t) {joystick.cell->x, joystick.cell->y}) == END_HORIZONTAL) drawEndHorizontal(joystick.cell->x, joystick.cell->y);
    else if (someField.read(&someField, (coordinates_t) {joystick.cell->x, joystick.cell->y}) == END_VERTICLE) drawEndVertical(joystick.cell->x, joystick.cell->y);
    else drawCloudCell(joystick.cell->x, joystick.cell->y);
}

void updateCoordinates() {
    display.fillRectangle(0, 130, 28, 10, BLACK);
    switch(joystick.cell->x) {
        case A:
            drawSmallA(1, 131, RED);
            break;
        case B:
            drawSmallB(1, 131, RED);
            break;
        case C:
            drawSmallC(1, 131, RED);
            break;
        case D:
            drawSmallD(1, 131, RED);
            break;
        case E:
            drawSmallE(1, 131, RED);
            break;
        case F:
            drawSmallF(1, 131, RED);
            break;
        case G:
            drawSmallG(1, 131, RED);
            break;
        case H:
            drawSmallH(1, 131, RED);
            break;
        case I:
            drawSmallI(1, 131, RED);
            break;
        case J:
            drawSmallJ(1, 131, RED);
            break;
        default:
            break;
    }
    switch(joystick.cell->y) {
        case A:
            drawSmall1(11, 131, RED);
            break;
        case B:
            drawSmall2(11, 131, RED);
            break;
        case C:
            drawSmall3(11, 131, RED);
            break;
        case D:
            drawSmall4(11, 131, RED);
            break;
        case E:
            drawSmall5(11, 131, RED);
            break;
        case F:
            drawSmall6(11, 131, RED);
            break;
        case G:
            drawSmall7(11, 131, RED);
            break;
        case H:
            drawSmall8(11, 131, RED);
            break;
        case I:
            drawSmall9(11, 131, RED);
            break;
        case J:
            drawSmall1(11, 131, RED); drawSmall0(19, 131, RED);
            break;
        default:
            break;
    }
}


#endif
