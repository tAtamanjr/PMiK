/**
 * @file	Model.c
 * @brief   Structure for managing all precesses
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
static void updateStartGameMenuCursor();


/**
 * @brief Initialize structure
 */
void initModel() {
    model.reactOnViewChangeButtonPressed = reactOnViewChangeButtonPressed;
    model.reactOnMainActionButtonPressed = reactOnMainActionButtonPressed;
    model.reactOnAdditionalActionButtonPressed = reactOnAdditionalActionButtonPressed;

    model.reactOnJoystick = reactOnJoystick;
}

/**
 * @brief Make changes after view change button has been pressed
 */
static void reactOnViewChangeButtonPressed() {
    switch(UIManager.currentView) {
        case START_VIEW:
            viewChangeButtonDebouncerAlarm = add_alarm_in_ms(500, viewChangeButtonDebouncerCallback, NULL, false);
            UIManager.setNextView(MAIN_MENU_VIEW);
            return;
        case MAIN_MENU_VIEW:
            inputModulesFlags.setOffViewChangeButtonDebouncerFlag();
            return;
        case START_GAME_VIEW:
            viewChangeButtonDebouncerAlarm = add_alarm_in_ms(500, viewChangeButtonDebouncerCallback, NULL, false);
            UIManager.setNextView(START_GAME_MENU_VIEW);
            return;
        case START_GAME_MENU_VIEW:
            viewChangeButtonDebouncerAlarm = add_alarm_in_ms(500, viewChangeButtonDebouncerCallback, NULL, false);
            UIManager.setNextView(START_GAME_VIEW);
            return;
        case FIELD_VIEW:
            inputModulesFlags.setOffViewChangeButtonDebouncerFlag();
            return;
        default:
            inputModulesFlags.setOffViewChangeButtonDebouncerFlag();
            return;
    }
}

/**
 * @brief Make changes after main action button has been pressed
 */
static void reactOnMainActionButtonPressed() {
    switch(UIManager.currentView) {
        case START_VIEW:
            mainActionButtonDebouncerAlarm = add_alarm_in_ms(500, mainActionButtonDebouncerCallback, NULL, false);
            UIManager.setNextView(MAIN_MENU_VIEW);
            return;
        case MAIN_MENU_VIEW:
            if (navigationData.mainMenuActiveElementIndex == 0 || navigationData.mainMenuActiveElementIndex == 1) {
                mainActionButtonDebouncerAlarm = add_alarm_in_ms(500, mainActionButtonDebouncerCallback, NULL, false);
                UIManager.setNextView(START_GAME_VIEW);
                return;
            }
            inputModulesFlags.setOffMainActionButtonDebouncerFlag();
            return;
        case START_GAME_VIEW:
            inputModulesFlags.setOffMainActionButtonDebouncerFlag();
            return;
        case START_GAME_MENU_VIEW:
            if (navigationData.placementMenuActiveElementIndex == 2) {
                mainActionButtonDebouncerAlarm = add_alarm_in_ms(500, mainActionButtonDebouncerCallback, NULL, false);
                UIManager.setNextView(MAIN_MENU_VIEW);
                navigationData.placementMenuActiveElementIndex = 0;
                return;
            }
            inputModulesFlags.setOffMainActionButtonDebouncerFlag();
            return;
        case FIELD_VIEW:
            inputModulesFlags.setOffMainActionButtonDebouncerFlag();
            return;
        default:
            inputModulesFlags.setOffMainActionButtonDebouncerFlag();
            return;
    }
}

/**
 * @brief Make changes after additional action button has been pressed
 */
static void reactOnAdditionalActionButtonPressed() {
    switch(UIManager.currentView) {
        case START_VIEW:
            additionalActionButtonDebouncerAlarm = add_alarm_in_ms(500, additionalActionButtonDebouncerCallback, NULL, false);
            UIManager.setNextView(MAIN_MENU_VIEW);
            return;
        case MAIN_MENU_VIEW:
            inputModulesFlags.setOffAdditionalActionButtonDebouncerFlag();
            return;
        case START_GAME_VIEW:
            inputModulesFlags.setOffAdditionalActionButtonDebouncerFlag();
            return;
        case FIELD_VIEW:
            inputModulesFlags.setOffAdditionalActionButtonDebouncerFlag();
            return;
        default:
            inputModulesFlags.setOffAdditionalActionButtonDebouncerFlag();
            return;
    }
}

/**
 * @brief Make changes after joystick has been moved to some side
 */
static void reactOnJoystick() {
    switch (UIManager.currentView) {
        case MAIN_MENU_VIEW:
            joystickActionDebouncerAlarm = add_alarm_in_ms(250, joystickActionDebouncerCallback, NULL, false);
            updateMainMenuCursor();
            return;
        case START_GAME_MENU_VIEW:
            joystickActionDebouncerAlarm = add_alarm_in_ms(250, joystickActionDebouncerCallback, NULL, false);
            updateStartGameMenuCursor();
            return;
        case FIELD_VIEW:
            joystickActionDebouncerAlarm = add_alarm_in_ms(150, joystickActionDebouncerCallback, NULL, false);
            UIManager.setSmallChanges(UPDATE_ON_FIELD_AIM);
            return;
        default:
            inputModulesFlags.setOffJoystickActionDebouncerFlag();
            return;
    }
}

/**
 * @brief Change main menu chose button
 */
static void updateMainMenuCursor() {
    switch (navigationData.mainMenuActiveElementIndex) {
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
            if (navigationData.mainMenuActiveElementIndex == 0) navigationData.mainMenuActiveElementIndex = 2;
            else navigationData.mainMenuActiveElementIndex -= 1;
            break;
        case SW:
        case SP:
        case SE:
            if (navigationData.mainMenuActiveElementIndex == 2) navigationData.mainMenuActiveElementIndex = 0;
            else navigationData.mainMenuActiveElementIndex += 1;
            break;
        default:
            break;
    }

    switch (navigationData.mainMenuActiveElementIndex) {
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

/**
 * @brief Update cursor position
 */
static void updateStartGameMenuCursor() {
    switch (navigationData.placementMenuActiveElementIndex) {
        case 0:
            drawReturnOneShipText(WHITE);
            break;
        case 1:
            drawResetAllShipsText(WHITE);
            break;
        case 2:
            drawAbortGameText(WHITE);
            break;
        default:
            break;
    }

    switch (joystick.direction) {
        case NW:
        case NP:
        case NE:
            if (navigationData.placementMenuActiveElementIndex == 0) navigationData.placementMenuActiveElementIndex = 2;
            else navigationData.placementMenuActiveElementIndex -= 1;
            break;
        case SW:
        case SP:
        case SE:
            if (navigationData.placementMenuActiveElementIndex == 2) navigationData.placementMenuActiveElementIndex = 0;
            else navigationData.placementMenuActiveElementIndex += 1;
            break;
        default:
            break;
    }

    switch (navigationData.placementMenuActiveElementIndex) {
        case 0:
            drawReturnOneShipText(RED);
            break;
        case 1:
            drawResetAllShipsText(RED);
            break;
        case 2:
            drawAbortGameText(RED);
            break;
        default:
            break;
    }
}

/**
 * @brief Make changes after shot
 */
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
