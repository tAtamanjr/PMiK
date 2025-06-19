/**
 * @file	StartView.c
 * @brief   Draw start view
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef START_VIEW_H
#include "StartView.h"


/**
 * @brief Draw field with placed ships/boats and down menu
 */
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

    display.fillRectangle(89, 133, 4, 6, WIRE_GRAY);
    display.drawVerticalLine(88, 134, 4, 1, WIRE_GRAY);
    display.drawVerticalLine(93, 134, 4, 1, WIRE_GRAY);

    display.fillRectangle(42, 151, 4, 6, WIRE_PURPLE);
    display.drawVerticalLine(41, 152, 4, 1, WIRE_PURPLE);
    display.drawVerticalLine(46, 152, 4, 1, WIRE_PURPLE);

    display.fillRectangle(89, 151, 4, 6, WIRE_BLUE);
    display.drawVerticalLine(88, 152, 4, 1, WIRE_BLUE);
    display.drawVerticalLine(93, 152, 4, 1, WIRE_BLUE);

    drawSmallLetter(M_s, 95, 132, WIRE_GRAY);
    drawSmallLetter(E_s, 103, 132, WIRE_GRAY);
    drawSmallLetter(N_s, 111, 132, WIRE_GRAY);
    drawSmallLetter(U_s, 119, 132, WIRE_GRAY);

    drawSmallLetter(M_s, 48, 150, WIRE_PURPLE);
    drawSmallLetter(E_s, 56, 150, WIRE_PURPLE);
    drawSmallLetter(N_s, 64, 150, WIRE_PURPLE);
    drawSmallLetter(U_s, 72, 150, WIRE_PURPLE);
    
    drawSmallLetter(M_s, 95, 150, WIRE_BLUE);
    drawSmallLetter(E_s, 103, 150, WIRE_BLUE);
    drawSmallLetter(N_s, 111, 150, WIRE_BLUE);
    drawSmallLetter(U_s, 119, 150, WIRE_BLUE);

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
