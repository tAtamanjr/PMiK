/**
 * \file	StartView.c
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef START_VIEW_H
#include "StartView.h"


void drawStartView() {
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

    display.drawHorizontalLine(0, 128, 128, 2, RED);
    display.fillRectangle(0, 130, 128, 34, BLACK);

    for (uint8_t x = E; x <= G; x++) {
        for(uint8_t y = 2; y <= 4; y++) {
            display.fillRectangle(19 + x * 11, 19 + y * 11, 10, 10, WATER);
        }
    }
    for (uint8_t x = I; x <= J; x++) {
        for(uint8_t y = 4; y <= 6; y++) {
            display.fillRectangle(19 + x * 11, 19 + y * 11, 10, 10, WATER);
        }
    }
    for (uint8_t x = B; x <= D; x++) {
        for(uint8_t y = 6; y <= 9; y++) {
            display.fillRectangle(19 + x * 11, 19 + y * 11, 10, 10, WATER);
        }
    }
    for (uint8_t x = F; x <= I; x++) {
        for(uint8_t y = 7; y <= 9; y++) {
            display.fillRectangle(19 + x * 11, 19 + y * 11, 10, 10, WATER);
        }
    }

    drawDestroyedBoatVertical(F, 3);
    drawDestroyedBoatHorizontal(J, 5);

    drawDamagedShipPart(F, 1);
    drawDamagedShipPart(J, 8);
    drawDestroyedBowHorizontal(G, 8);
    drawDestroyedEndHorizontal(H, 8);

    drawDamagedShipPart(B, 3);
    drawDamagedShipPart(C, 3);
    drawDestroyedBowVertical(C, 7);
    drawDestroyedMiddleVertical(C, 8);
    drawDestroyedEndVertical(C, 9);

    drawDamagedShipPart(H, 3);
    drawDamagedShipPart(H, 4);
}


#endif
