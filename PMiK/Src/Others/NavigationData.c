/**
 * \file	NavigationData.c
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef NAVIGATION_DATA_H
#include "NavigationData.h"


void initNavigationData() {
    navigationData.mainMenuActiveElementIndex = 0;
    navigationData.placementCoordanates = (coordinates_t) {A, 0};
    navigationData.placementMenuActiveElementIndex = 0;
    navigationData.fireCoordinates = (coordinates_t) {A, 0};
}


#endif
