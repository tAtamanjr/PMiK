/**
 * \file	Model.c
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef MODEL_H
#include "Model.h"


static void reactOnViewChangeButtonPressed();
static void reactOnMainActionButtonPressed();
static void reactOnAdditionalActionButtonPressed();

static void reactOnJoystick();
static void updateMainMenuCursor();


void initModel() {
    model.mainMenuElementIndex = 0;

    model.reactOnViewChangeButtonPressed = reactOnViewChangeButtonPressed;
    model.reactOnMainActionButtonPressed = reactOnMainActionButtonPressed;
    model.reactOnAdditionalActionButtonPressed = reactOnAdditionalActionButtonPressed;

    model.reactOnJoystick = reactOnJoystick;
}

static void reactOnViewChangeButtonPressed() {
    switch(UIManager.currentView) {
        case START_VIEW:
            viewChangeButtonDebouncerAlarm = add_alarm_in_ms(500, viewChangeButtonDebouncerCallback, NULL, false);
            UIManager.setNextView(MAIN_MENU_VIEW);
            return;
        case MAIN_MENU_VIEW:
            viewChangeButtonDebouncerFlag = 1;
            return;
        case START_GAME_VIEW:
            viewChangeButtonDebouncerFlag = 1;
            return;            
        case FIELD_VIEW:
            viewChangeButtonDebouncerFlag = 1;
            return;
        default:
            viewChangeButtonDebouncerFlag = 1;
            return;
    }
}

static void reactOnMainActionButtonPressed() {
    switch(UIManager.currentView) {
        case START_VIEW:
            mainActionButtonDebouncerAlarm = add_alarm_in_ms(500, mainActionButtonDebouncerCallback, NULL, false);
            UIManager.setNextView(MAIN_MENU_VIEW);
            return;
        case MAIN_MENU_VIEW:
            if (model.mainMenuElementIndex == 0 || model.mainMenuElementIndex == 1) {
                mainActionButtonDebouncerAlarm = add_alarm_in_ms(500, mainActionButtonDebouncerCallback, NULL, false);
                UIManager.setNextView(START_GAME_VIEW);
                return;
            }
            mainActionButtonDebouncerFlag = 1;
            return;
        case START_GAME_VIEW:
            mainActionButtonDebouncerFlag = 1;
            return;
        case FIELD_VIEW:
            mainActionButtonDebouncerFlag = 1;
            return;
        default:
            mainActionButtonDebouncerFlag = 1;
            return;
    }
}

static void reactOnAdditionalActionButtonPressed() {
    switch(UIManager.currentView) {
        case START_VIEW:
            additionalActionButtonDebouncerAlarm = add_alarm_in_ms(500, additionalActionButtonDebouncerCallback, NULL, false);
            UIManager.setNextView(MAIN_MENU_VIEW);
            return;
        case MAIN_MENU_VIEW:
            additionalActionButtonDebouncerFlag = 1;
            return;
        case START_GAME_VIEW:
            additionalActionButtonDebouncerFlag = 1;
            return;
        case FIELD_VIEW:
            additionalActionButtonDebouncerFlag = 1;
            return;
        default:
            additionalActionButtonDebouncerFlag = 1;
            return;
    }
}

static void reactOnJoystick() {
    switch (UIManager.currentView) {
        case MAIN_MENU_VIEW:
            joystickActionDebouncerAlarm = add_alarm_in_ms(250, joystickactionDebouncerCallback, NULL, false);
            updateMainMenuCursor();
            return;
        case FIELD_VIEW:
            joystickActionDebouncerAlarm = add_alarm_in_ms(150, joystickactionDebouncerCallback, NULL, false);
            UIManager.setSmallChanges(UPDATE_ON_FIELD_AIM);
            return;
        default:
            joystickActionDebouncerFlag = 1;
            return;
    }
}

static void updateMainMenuCursor() {
    switch (model.mainMenuElementIndex) {
        case 0:
            drawStartEasyGameText(WHITE);
            break;
        case 1:
            drawStartHardGameText(WHITE);
            break;
        case 2:
            drawWatchOtherText(WHITE);
            break;
        default:
            break;
    }

    switch (joystick.direction) {
        case NW:
        case NP:
        case NE:
            if (model.mainMenuElementIndex == 0) model.mainMenuElementIndex = 2;
            else model.mainMenuElementIndex -= 1;
            break;
        case SW:
        case SP:
        case SE:
            if (model.mainMenuElementIndex == 2) model.mainMenuElementIndex = 0;
            else model.mainMenuElementIndex += 1;
            break;
        default:
            break;
    }

    switch (model.mainMenuElementIndex) {
        case 0:
            drawStartEasyGameText(RED);
            break;
        case 1:
            drawStartHardGameText(RED);
            break;
        case 2:
            drawWatchOtherText(FIRE_YELLOW);
            break;
        default:
            break;
    }
}

static void fireCallback() {
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
        UIManager.setSmallChanges(UPDATE_CELL);
    
}


#endif
