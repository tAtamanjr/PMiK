/**
 * \file	UIManager.c
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef UI_MANAGER_H
#include "UIManager.h"


static void updateView();
static void setNextView(uint8_t);
static void setSmallChanges(uint8_t);


void initUIManager() {
    UIManager.currentView = START_VIEW;
    UIManager.nextView = 0b00000000;
    UIManager.smallChanges = 0b00000000;
    UIManager.updateView = updateView;
    UIManager.setNextView = setNextView;
    UIManager.setSmallChanges = setSmallChanges;
    drawStartView();
    drawButtonsDescriptions(UIManager.currentView);
}

static void updateView() {
    if (UIManager.nextView && UIManager.currentView != UIManager.nextView) {
        if (UIManager.nextView == FIELD_VIEW) {
            drawField();
            drawButtonsDescriptions(FIELD_VIEW);
        }
        UIManager.currentView = FIELD_VIEW;
        UIManager.nextView = 0b00000000;
        UIManager.smallChanges = 0b00000000;
    } else if (UIManager.smallChanges) {
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
}

static void setNextView(const uint8_t view) {
    UIManager.nextView = view;
}

static void setSmallChanges(const uint8_t changes) {
    UIManager.smallChanges = UIManager.smallChanges | 1 << changes;
}


#endif
