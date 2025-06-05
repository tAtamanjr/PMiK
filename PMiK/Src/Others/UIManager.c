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
    UIManager.currentView = 0b00000000;
    UIManager.nextView = 0b00000000;
    UIManager.smallChanges = 0b00000000;
    UIManager.updateView = updateView;
    UIManager.setNextView = setNextView;
    UIManager.setSmallChanges = setSmallChanges;
    drawStartView();
}

static void updateView() {
    if (UIManager.nextView && UIManager.currentView != UIManager.nextView) {
        if (UIManager.nextView & 1 << 1) {
            drawField();
        }
        UIManager.currentView = 0b00000010;
        UIManager.nextView = 0b00000000;
        UIManager.smallChanges = 0b00000000;
    } else if (UIManager.smallChanges) {
        if (UIManager.smallChanges & 1 << 0) {
            if (UIManager.currentView && 1 << 1) {
                updateAimPosition();
                UIManager.smallChanges = UIManager.smallChanges & 0 << 0;
            }
        }
        if (UIManager.smallChanges & 1 << 1) {
            UIManager.currentView = 0b00000000;
            UIManager.nextView = 0b00000010;
            UIManager.smallChanges = UIManager.smallChanges & 0 << 1;
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
