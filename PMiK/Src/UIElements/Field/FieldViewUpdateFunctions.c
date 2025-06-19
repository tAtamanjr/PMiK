/**
 * @file	FieldViewUpdateFunctions.c
 * @brief   Change field view elements
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef FIELD_VIEW_UPDATE_FUNCTIONS_H
#include "FieldViewUpdateFunctions.h"


/**
 * @brief Change aim position
 */
void updateAimPosition() {
    drawCell(joystick.cell->x, joystick.cell->y);
    joystick.updateCell();
    drawAim(joystick.cell->x, joystick.cell->y);
    display.fillRectangle(0, 130, 26, 10, BLACK);
    drawSmallLetter(joystick.cell->x, 0, 132, RED);
    drawNumber(joystick.cell->y + 1, 10, 132, RED);
}


#endif
