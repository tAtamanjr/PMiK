/**
 * \file	BasicViews.h
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef BASIC_VIEWS_H
#define BASIC_VIEWS_H


#ifndef THE_DATA_H
#include "TheData.h"
#endif

#ifndef JOYSTICK_H
#include "Joystick.h"
#endif
#ifndef DISPLAY_H
#include "Display.h"
#endif
#ifndef SHIP_ELEMENTS_H
#include "ShipElements.h"
#endif
#ifndef TEXT_ELEMENTS_H
#include "TextElements.h"
#endif
#ifndef FILED_H
#include "Field.h"
#endif


void drawFieldView();
void drawMenuView();
void drawDownMenuElement();
void drawCloudCell(uint8_t x, uint8_t y);
void drawAim();
void removeAim();
void updateCoordinates();


#endif
