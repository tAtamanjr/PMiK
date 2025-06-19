/**
 * @file	StartGameMenuView.c
 * @brief   Draw menu that can be accessed from start game view
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef START_GAME_MENU_VIEW_H
#include "StartGameMenuView.h"


/**
 * \brief   Draw menu that can be accessed from start game view
 */
void drawStartGameMenuView() {
    display.fillScreen(BLACK);

    drawReturnOneShipText(WHITE);
    drawResetAllShipsText(WHITE);
    drawAbortGameText(WHITE);

    display.drawHorizontalLine(0, 128, 128, 2, RED);

    display.fillRectangle(73, 151, 4, 6, WIRE_PURPLE);
    display.drawVerticalLine(72, 152, 4, 1, WIRE_PURPLE);
    display.drawVerticalLine(77, 152, 4, 1, WIRE_PURPLE);
    
    display.fillRectangle(81, 133, 4, 6, WIRE_GRAY);
    display.drawVerticalLine(80, 134, 4, 1, WIRE_GRAY);
    display.drawVerticalLine(85, 134, 4, 1, WIRE_GRAY);
    drawSmallLetter(F_s, 87, 132, WIRE_GRAY);
    drawSmallLetter(I_s, 95, 132, WIRE_GRAY);
    drawSmallLetter(E_s, 103, 132, WIRE_GRAY);
    drawSmallLetter(L_s, 111, 132, WIRE_GRAY);
    drawSmallLetter(D_s, 119, 132, WIRE_GRAY);

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
 * @brief Draw button for removing last placed ship/boat from the field
 * @param color - button's text color
 */
void drawReturnOneShipText(color_t color) {
    drawSmallLetter(R_s, 7, 38, color);
    drawSmallLetter(E_s, 15, 38, color);
    drawSmallLetter(T_s, 23, 38, color);
    drawSmallLetter(U_s, 31, 38, color);
    drawSmallLetter(R_s, 39, 38, color);
    drawSmallLetter(N_s, 47, 38, color);

    drawSmallLetter(O_s, 59, 38, color);
    drawSmallLetter(N_s, 67, 38, color);
    drawSmallLetter(E_s, 75, 38, color);

    drawSmallLetter(S_s, 87, 38, color);
    drawSmallLetter(H_s, 95, 38, color);
    drawSmallLetter(I_s, 103, 38, color);
    drawSmallLetter(P_s, 111, 38, color);
}

/**
 * @brief Draw button for removing all placed ship/boat from the field
 * @param color - button's text color
 */
void drawResetAllShipsText(color_t color) {
    drawSmallLetter(R_s, 7, 58, color);
    drawSmallLetter(E_s, 15, 58, color);
    drawSmallLetter(S_s, 23, 58, color);
    drawSmallLetter(E_s, 31, 58, color);
    drawSmallLetter(T_s, 39, 58, color);
    
    drawSmallLetter(A_s, 51, 58, color);
    drawSmallLetter(L_s, 59, 58, color);
    drawSmallLetter(L_s, 67, 58, color);
    
    drawSmallLetter(S_s, 79, 58, color);
    drawSmallLetter(H_s, 87, 58, color);
    drawSmallLetter(I_s, 95, 58, color);
    drawSmallLetter(P_s, 103, 58, color);
    drawSmallLetter(S_s, 111, 58, color);
}

/**
 * @brief Draw button for aborting game
 * @param color - button's text color
 */
void drawAbortGameText(color_t color) {
    drawSmallLetter(A_s, 26, 78, color);
    drawSmallLetter(B_s, 34, 78, color);
    drawSmallLetter(O_s, 42, 78, color);
    drawSmallLetter(R_s, 50, 78, color);
    drawSmallLetter(T_s, 58, 78, color);

    drawSmallLetter(G_s, 70, 78, color);
    drawSmallLetter(A_s, 78, 78, color);
    drawSmallLetter(M_s, 86, 78, color);
    drawSmallLetter(E_s, 94, 78, color);
}


#endif
