/**
 * \file	FieldView.h
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef FIELD_VIEW_H
#define FIELD_VIEW_H


#ifndef THE_DATA_H
#include "TheData.h"
#endif

#ifndef JOYSTICK_H
#include "Joystick.h"
#endif
#ifndef DISPLAY_H
#include "Display.h"
#endif
#ifndef LETTERS_H
#include "Letters.h"
#endif
#ifndef NUMBERS_H
#include "Numbers.h"
#endif
#ifndef SHIP_ELEMENTS_H
#include "ShipElements.h"
#endif
#ifndef FILED_H
#include "Field.h"
#endif


void drawField();
void drawAim(uint8_t x, uint8_t y);
void drawCell(uint8_t x, uint8_t y);


#endif
