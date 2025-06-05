/**
 * \file	ButtonsDescriptions.h
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef BUTTONS_DESCRIPTIONS_H
#include "ButtonsDescriptions.h"


static void drawButtonsDescriptionsForStartView();
static void drawButtonsDescriptionsForFieldView();

void drawButtonsDescriptions(const uint8_t view) {
    display.fillRectangle(39, 130, 88, 33, BLACK);

    display.fillRectangle(42, 133, 4, 6, WIRE_GRAY);
    display.drawVerticalLine(41, 134, 4, 1, WIRE_GRAY);
    display.drawVerticalLine(46, 134, 4, 1, WIRE_GRAY);

    display.fillRectangle(89, 133, 4, 6, WIRE_PURPLE);
    display.drawVerticalLine(88, 134, 4, 1, WIRE_PURPLE);
    display.drawVerticalLine(93, 134, 4, 1, WIRE_PURPLE);

    display.fillRectangle(42, 151, 4, 6, WIRE_BLUE);
    display.drawVerticalLine(41, 152, 4, 1, WIRE_BLUE);
    display.drawVerticalLine(46, 152, 4, 1, WIRE_BLUE);

    display.fillRectangle(89, 151, 4, 6, WIRE_GREEN);
    display.drawVerticalLine(88, 152, 4, 1, WIRE_GREEN);
    display.drawVerticalLine(93, 152, 4, 1, WIRE_GREEN);

    switch(view) {
        case START_VIEW:
            drawButtonsDescriptionsForStartView();
            return;
        case FIELD_VIEW:
            drawButtonsDescriptionsForFieldView();
            return;
        default:
            return;
    }
}

static void drawButtonsDescriptionsForStartView() {
    drawSmallLetter(M_s, 48, 132, WIRE_GRAY);
    drawSmallLetter(E_s, 56, 132, WIRE_GRAY);
    drawSmallLetter(N_s, 64, 132, WIRE_GRAY);
    drawSmallLetter(U_s, 72, 132, WIRE_GRAY);

    drawSmallLetter(M_s, 95, 132, WIRE_PURPLE);
    drawSmallLetter(E_s, 103, 132, WIRE_PURPLE);
    drawSmallLetter(N_s, 111, 132, WIRE_PURPLE);
    drawSmallLetter(U_s, 119, 132, WIRE_PURPLE);

    drawSmallLetter(M_s, 48, 150, WIRE_BLUE);
    drawSmallLetter(E_s, 56, 150, WIRE_BLUE);
    drawSmallLetter(N_s, 64, 150, WIRE_BLUE);
    drawSmallLetter(U_s, 72, 150, WIRE_BLUE);

    
    drawSmallLetter(M_s, 95, 150, WIRE_GREEN);
    drawSmallLetter(E_s, 103, 150, WIRE_GREEN);
    drawSmallLetter(N_s, 111, 150, WIRE_GREEN);
    drawSmallLetter(U_s, 119, 150, WIRE_GREEN);
}

static void drawButtonsDescriptionsForFieldView() {
    drawSmallLetter(M_s, 48, 132, WIRE_GRAY);
    drawSmallLetter(E_s, 56, 132, WIRE_GRAY);
    drawSmallLetter(N_s, 64, 132, WIRE_GRAY);
    drawSmallLetter(U_s, 72, 132, WIRE_GRAY);

    drawSmallLetter(F_s, 95, 132, WIRE_PURPLE);
    drawSmallLetter(I_s, 103, 132, WIRE_PURPLE);
    drawSmallLetter(R_s, 111, 132, WIRE_PURPLE);
    drawSmallLetter(E_s, 119, 132, WIRE_PURPLE);

    drawSmallLetter(N_s, 48, 150, WIRE_BLUE);
    drawSmallLetter(O_s, 56, 150, WIRE_BLUE);
    drawSmallLetter(N_s, 64, 150, WIRE_BLUE);
    drawSmallLetter(E_s, 72, 150, WIRE_BLUE);

    
    drawSmallLetter(N_s, 95, 150, WIRE_GREEN);
    drawSmallLetter(O_s, 103, 150, WIRE_GREEN);
    drawSmallLetter(N_s, 111, 150, WIRE_GREEN);
    drawSmallLetter(E_s, 119, 150, WIRE_GREEN);
}


#endif
