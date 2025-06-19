/**
 * @file	StartGameMenuView.h
 * @brief   Draw menu that can be accessed from start game view
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef START_GAME_MENU_VIEW_H
#define START_GAME_MENU_VIEW_H


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
#ifndef BUTTONS_DESCRIPTIONS_H
#include "ButtonsDescriptions.h"
#endif


void drawStartGameMenuView();
void drawReturnOneShipText(color_t color);
void drawResetAllShipsText(color_t color);
void drawAbortGameText(color_t color);


#endif
