/**
 * \file	ShipElements.h
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef SHIP_VIEWS_H
#define SHIP_VIEWS_H


#ifndef THE_DATA_H
#include "TheData.h"
#endif

#ifndef DISPLAY_H
#include "Display.h"
#endif


void drawBoatHorizontal(const coordinate_e x, const coordinate_e y);
void drawBowHorizontal(const coordinate_e x, const coordinate_e y);
void drawMiddleHorizontal(const coordinate_e x, const coordinate_e y);
void drawEndHorizontal(const coordinate_e x, const coordinate_e y);
void drawBoatVertical(const coordinate_e x, const coordinate_e y);
void drawBowVertical(const coordinate_e x, const coordinate_e y);
void drawMiddleVertical(const coordinate_e x, const coordinate_e y);
void drawEndVertical(const coordinate_e x, const coordinate_e y);


#endif
