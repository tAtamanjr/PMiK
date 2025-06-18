/**
 * \file	NavigationData.h
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef NAVIGATION_DATA_H
#define NAVIGATION_DATA_H


#ifndef THE_DATA_H
#include "TheData.h"
#endif

#ifndef COORDINATES_H
#include "Coordinates.h"
#endif


typedef struct NavigationData {
    uint8_t mainMenuActiveElementIndex;
    coordinates_t placementCoordanates;
    uint8_t placementMenuActiveElementIndex;
    coordinates_t fireCoordinates;
} navigationData_t;


extern navigationData_t navigationData;


void initNavigationData();


#endif
