/**
 * @file	MainMenuView.c
 * @brief   Draw main menu view
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef MAIN_MENU_VIEW_H
#include "MainMenuView.h"


/**
 * @brief Draw main menu view
 */
void drawMainMenu() {
    display.fillScreen(BLACK);

    drawStartEasyGameText(WHITE);
    drawStartHardGameText(WHITE);
    drawWatchOtherText(WHITE);

    display.drawHorizontalLine(0, 128, 128, 2, RED);

    display.fillRectangle(73, 151, 4, 6, WIRE_PURPLE);
    display.drawVerticalLine(72, 152, 4, 1, WIRE_PURPLE);
    display.drawVerticalLine(77, 152, 4, 1, WIRE_PURPLE);
    
    drawSmallLetter(C_s, 79, 150, WIRE_PURPLE);
    drawSmallLetter(H_s, 87, 150, WIRE_PURPLE);
    drawSmallLetter(O_s, 95, 150, WIRE_PURPLE);
    drawSmallLetter(O_s, 103, 150, WIRE_PURPLE);
    drawSmallLetter(S_s, 111, 150, WIRE_PURPLE);
    drawSmallLetter(E_s, 119, 150, WIRE_PURPLE);
}

/**
 * @brief Draw button for starting game with easy bot
 * @param color - button's text color
 */
void drawStartEasyGameText(color_t color) {
    drawSmallLetter(S_s, 7, 38, color);
    drawSmallLetter(T_s, 15, 38, color);
    drawSmallLetter(A_s, 23, 38, color);
    drawSmallLetter(R_s, 31, 38, color);
    drawSmallLetter(T_s, 39, 38, color);

    drawSmallLetter(E_s, 51, 38, color);
    drawSmallLetter(A_s, 59, 38, color);
    drawSmallLetter(S_s, 67, 38, color);
    drawSmallLetter(Y_s, 75, 38, color);

    drawSmallLetter(G_s, 87, 38, color);
    drawSmallLetter(A_s, 95, 38, color);
    drawSmallLetter(M_s, 103, 38, color);
    drawSmallLetter(E_s, 111, 38, color);
}

/**
 * @brief Draw button for starting game with hard bot
 * @param color - button's text color
 */
void drawStartHardGameText(color_t color) {
    drawSmallLetter(S_s, 7, 58, color);
    drawSmallLetter(T_s, 15, 58, color);
    drawSmallLetter(A_s, 23, 58, color);
    drawSmallLetter(R_s, 31, 58, color);
    drawSmallLetter(T_s, 39, 58, color);

    drawSmallLetter(H_s, 51, 58, color);
    drawSmallLetter(A_s, 59, 58, color);
    drawSmallLetter(R_s, 67, 58, color);
    drawSmallLetter(D_s, 75, 58, color);

    drawSmallLetter(G_s, 87, 58, color);
    drawSmallLetter(A_s, 95, 58, color);
    drawSmallLetter(M_s, 103, 58, color);
    drawSmallLetter(E_s, 111, 58, color);
}

/**
 * @brief Currently unused button
 * @param color - button's text color
 */
void drawWatchOtherText(color_t color) {
    drawSmallLetter(W_s, 22, 78, color);
    drawSmallLetter(A_s, 30, 78, color);
    drawSmallLetter(T_s, 38, 78, color);
    drawSmallLetter(C_s, 46, 78, color);
    drawSmallLetter(H_s, 54, 78, color);

    drawSmallLetter(O_s, 66, 78, color);
    drawSmallLetter(T_s, 74, 78, color);
    drawSmallLetter(H_s, 82, 78, color);
    drawSmallLetter(E_s, 90, 78, color);
    drawSmallLetter(R_s, 98, 78, color);
}


#endif
