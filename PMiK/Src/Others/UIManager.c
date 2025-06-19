/**
 * @file	UIManager.c
 * @brief   Manage views and change them
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef UI_MANAGER_H
#include "UIManager.h"


static void updateView();
static void setNextView(uint8_t);
static void setSmallChanges(uint8_t);
static void changeView();
static void updateCurrentView();

/**
 * @brief Initialize UIManager structure
 */
void initUIManager() {
    UIManager.currentView = START_VIEW;
    UIManager.nextView = 0b00000000;
    UIManager.smallChanges = 0b00000000;
    UIManager.updateView = updateView;
    UIManager.setNextView = setNextView;
    UIManager.setSmallChanges = setSmallChanges;
    drawStartView();
}

/**
 * @brief Change current view/update current view or do nothing
 */
static void updateView() {
    if (UIManager.nextView && UIManager.currentView != UIManager.nextView) {
        changeView();
    } else if (UIManager.smallChanges) {
        updateCurrentView();
    }
}

/**
 * @brief Set next view parameter so UIManager can change current view to next one
 */
static void setNextView(const uint8_t view) {
    UIManager.nextView = view;
}

/**
 * @brief Set next view parameter so UIManager can update current view
 */
static void setSmallChanges(const uint8_t changes) {
    UIManager.smallChanges = UIManager.smallChanges | 1 << changes;
}

/**
 * @brief Change current view to the next one
 */
static void changeView() {
    switch (UIManager.nextView) {
        case MAIN_MENU_VIEW:
            drawMainMenu();
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
            break;
        case START_GAME_VIEW:
            drawStartGameView();
            break;
        case START_GAME_MENU_VIEW:
            drawStartGameMenuView();
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
            break;
        case FIELD_VIEW:
            drawField();
            drawButtonsDescriptions(FIELD_VIEW);
            break;
        default:
            return;
    }
    UIManager.currentView = UIManager.nextView;
    UIManager.nextView = 0b00000000;
    UIManager.smallChanges = NO_CHANGES;
}

/**
 * @brief Update current view
 */
static void updateCurrentView() {
    if (UIManager.smallChanges & 1 << 2) {
            UIManager.currentView = 0b00000000;
            UIManager.nextView = 0b00000010;
            UIManager.smallChanges = UIManager.smallChanges & 0 << 2;
        }
        if (UIManager.smallChanges & 1 << UPDATE_CELL) {
            if (UIManager.currentView & FIELD_VIEW) {
                drawCell(joystick.cell->x, joystick.cell->y);
                drawAim(joystick.cell->x, joystick.cell->y);
                UIManager.smallChanges = UIManager.smallChanges & 0 << UPDATE_CELL;
            }
        }
        if (UIManager.smallChanges & 1 << UPDATE_ON_FIELD_AIM) {
            if (UIManager.currentView == FIELD_VIEW) {
                updateAimPosition();
                UIManager.smallChanges = UIManager.smallChanges & 0 << UPDATE_ON_FIELD_AIM;
            }
        }
}


#endif
