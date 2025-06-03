/**
 * \file	TextElements.c
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef TEXT_ELEMENTS_H
#include "TextElements.h"


void drawFieldTextElements() {
    drawBigLetter(B_b, 1, 3, BLACK);
    drawBigLetter(B_b, 9, 3, BLACK);
    for (uint8_t letter = 0; letter <= 9; letter++) {
        drawSmallLetter(letter, 20 + 11 * letter, 8, BLACK);
    }
    for (uint8_t number = 1; number <= 9; number++) {
        drawNumber(number, 8, 20 + 11 * (number - 1), BLACK);
    }
    drawNumber(10, 0, 119, BLACK);
}

void updateAimCellData() {
    display.fillRectangle(0, 130, 28, 10, BLACK);
    drawSmallLetter(joystick.cell->x, 1, 131, RED);
    drawNumber(joystick.cell->y + 1, 11, 131, RED);
}

void drawFieldLogo() {
    drawBigLetter(B_b, 1, 3, BLACK);
    drawBigLetter(B_b, 9, 3, BLACK);
}


#endif
