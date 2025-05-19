/**
 * \file	BasicViews.h
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef BASIC_VIEWS_H
#define BASIC_VIEWS_H


#ifndef DISPLAY_H
#include "Display.h"
#endif
#ifndef SHIP_VIEWS_H
#include "ShipViews.h"
#endif


void drawFieldView(const display_t *display);
void drawMenuView(const display_t *display);


#endif
