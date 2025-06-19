/**
 * @file	IRQCallbackFunctions.c
 * @brief   Callback functions for interupts
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef IRQ_CALLBACK_FUNCTIONS_H
#include "IRQCallbackFunctions.h" 


static void viewChangeButtonPressed();
static void mainActionButtonPressed();
static void additionalActionButtonPressed();


void callbackSwitcher(uint gpio, uint32_t events) {
    switch (gpio) {
        case VIEW_CHANGE_BUTTON:
            viewChangeButtonPressed();
            return;
        case MAIN_ACTION_BUTTON:
            mainActionButtonPressed();
            return;
        case ADDITIONAL_ACTION_BUTTON:
            additionalActionButtonPressed();
            return;
        default:
            return;
    }
}


static void viewChangeButtonPressed() {
    if (viewChangeButtonDebouncerFlag) {
        viewChangeButtonDebouncerFlag = 0;
        model.reactOnViewChangeButtonPressed();
    }
}

static void mainActionButtonPressed() {
    if (mainActionButtonDebouncerFlag) {
        mainActionButtonDebouncerFlag = 0;
        model.reactOnMainActionButtonPressed();
    }
}

static void additionalActionButtonPressed() {
    if (additionalActionButtonDebouncerFlag) {
        additionalActionButtonDebouncerFlag = 0;
        model.reactOnAdditionalActionButtonPressed();
    }
}


#endif
