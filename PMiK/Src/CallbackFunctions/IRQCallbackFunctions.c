/**
 * \file	IRQCallbackFunctions.c
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef IRQ_CALLBACK_FUNCTIONS_H
#include "IRQCallbackFunctions.h" 


static void resetNavyCallback();
static void fireCallback();


void callbackSwitcher(uint gpio, uint32_t events) {
    switch (gpio) {
        case MAIN_BUTTON:
            resetNavyCallback();
            return;
        case CONFIRM_BUTTON:
            fireCallback();
            return;
        case SUPP_BUTTON_1:
            printf("Supp button 1\n");
            return;
        case SUPP_BUTTON_2:
            printf("Supp button 2\n");
            return;
        default:
            return;
    }
}

static void resetNavyCallback() {
    if (resetNavyDebouncerFlag) {
        resetNavyDebouncerFlag = 0;
        resetNavyDebouncerAlarm = add_alarm_in_ms(1000, resetNavyDebouncerCallback, NULL, false);

        while (!placeNavy(&someField))
        UIManager.setSmallChanges(1);
    }
}

static void fireCallback() {
    if (fireDebouncerFlag) {
        fireDebouncerFlag = 0;
        fireDebouncerAlarm = add_alarm_in_ms(250, fireDebouncerCallback, NULL, false);
        
        switch (someField.read(&someField, (coordinates_t) {joystick.cell->x, joystick.cell->y})) {
            case CLOUD_CELL:
                someField.set(&someField, (coordinates_t) {joystick.cell->x, joystick.cell->y}, WATER_CELL);
                break;
            case BOAT_HORIZONTAL:
                someField.set(&someField, (coordinates_t) {joystick.cell->x, joystick.cell->y}, DESTROYED_BOAT_HORIZONTAL);
                break;
            case BOAT_VERTICAL:
                someField.set(&someField, (coordinates_t) {joystick.cell->x, joystick.cell->y}, DESTROYED_BOAT_VERTICAL);
                break;
            case BOW_HORIZONTAL:
                someField.set(&someField, (coordinates_t) {joystick.cell->x, joystick.cell->y}, DAMAGED_BOW_HORIZONTAL);
                break;
            case BOW_VERTICAL:
                someField.set(&someField, (coordinates_t) {joystick.cell->x, joystick.cell->y}, DAMAGED_BOW_VERTICAL);
                break;
            case MIDDLE_PART_HORIZONTAL:
                someField.set(&someField, (coordinates_t) {joystick.cell->x, joystick.cell->y}, DAMAGED_MIDDLE_PART_HORIZONTAL);
                break;
            case MIDDLE_PART_VERTICAL:
                someField.set(&someField, (coordinates_t) {joystick.cell->x, joystick.cell->y}, DAMAGED_MIDDLE_PART_VERTICAL);
                break;
            case END_HORIZONTAL:
                someField.set(&someField, (coordinates_t) {joystick.cell->x, joystick.cell->y}, DAMAGED_END_HORIZONTAL);
                break;
            case END_VERTICAL:
                someField.set(&someField, (coordinates_t) {joystick.cell->x, joystick.cell->y}, DAMAGED_END_VERTICAL);
                break;
            case DAMAGED_BOW_HORIZONTAL:
                someField.set(&someField, (coordinates_t) {joystick.cell->x, joystick.cell->y}, DESTROYED_BOW_HORIZONTAL);
                break;
            case DAMAGED_BOW_VERTICAL:
                someField.set(&someField, (coordinates_t) {joystick.cell->x, joystick.cell->y}, DESTROYED_BOW_VERTICAL);
                break;
            case DAMAGED_MIDDLE_PART_HORIZONTAL:
                someField.set(&someField, (coordinates_t) {joystick.cell->x, joystick.cell->y}, DESTROYED_MIDDLE_PART_HORIZONTAL);
                break;
            case DAMAGED_MIDDLE_PART_VERTICAL:
                someField.set(&someField, (coordinates_t) {joystick.cell->x, joystick.cell->y}, DESTROYED_MIDDLE_PART_VERTICAL);
                break;
            case DAMAGED_END_HORIZONTAL:
                someField.set(&someField, (coordinates_t) {joystick.cell->x, joystick.cell->y}, DESTROYED_END_HORIZONTAL);
                break;
            case DAMAGED_END_VERTICAL:
                someField.set(&someField, (coordinates_t) {joystick.cell->x, joystick.cell->y}, DESTROYED_END_VERTICAL);
                break;
            case WATER_CELL:
            case DESTROYED_BOAT_HORIZONTAL:
            case DESTROYED_BOAT_VERTICAL:
            case DESTROYED_BOW_HORIZONTAL:
            case DESTROYED_BOW_VERTICAL:
            case DESTROYED_MIDDLE_PART_HORIZONTAL:
            case DESTROYED_MIDDLE_PART_VERTICAL:
            case DESTROYED_END_HORIZONTAL:
            case DESTROYED_END_VERTICAL:
                return;
            default:
                break;
        }
        UIManager.setSmallChanges(2);
    }
}


#endif
