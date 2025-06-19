/**
 * @file	NavigationData.c
 * @brief   Structure will be used to keep data about which button on menu is being chose
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef NAVIGATION_DATA_H
#include "NavigationData.h"


/**
 * @brief Initialize structure
 */
void initNavigationData() {
    navigationData.mainMenuActiveElementIndex = 0;
    navigationData.placementCoordanates = (coordinates_t) {A, 0};
    navigationData.placementMenuActiveElementIndex = 0;
    navigationData.fireCoordinates = (coordinates_t) {A, 0};
}


#endif
