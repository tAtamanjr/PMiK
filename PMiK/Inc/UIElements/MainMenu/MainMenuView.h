/**
 * @file	MainMenuView.h
 * @brief   Draw main menu view
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef MAIN_MENU_VIEW_H
#define MAIN_MENU_VIEW_H


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
#ifndef BUTTONS_DESCRIPTIONS_H
#include "ButtonsDescriptions.h"
#endif


void drawMainMenu();
void drawStartEasyGameText(color_t color);
void drawStartHardGameText(color_t color);
void drawWatchOtherText(color_t color);


#endif
