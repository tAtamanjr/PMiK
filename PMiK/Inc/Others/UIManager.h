/**
 * @file	UIManager.h
 * @brief   Manage views and change them
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef UI_MANAGER_H
#define UI_MANAGER_H


#ifndef THE_DATA_H
#include "TheData.h"
#endif

#ifndef UI_ELEMENTS_H
#include "UIElements.h"
#endif
#ifndef NAVIGATION_DATA_H
#include "NavigationData.h"
#endif


typedef struct UIManagerStruct {
    uint8_t currentView;
    uint8_t nextView;
    uint8_t smallChanges;

    void (*updateView) ();
    void (*setNextView) (uint8_t view);
    void (*setSmallChanges) (uint8_t changes);
} UIManager_t;


extern UIManager_t UIManager;


void initUIManager();


#endif
