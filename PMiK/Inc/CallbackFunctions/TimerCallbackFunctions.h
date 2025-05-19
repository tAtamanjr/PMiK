/**
 * \file	TimerCallbackFunctions
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef TIMER_CALLBACK_FUNCTIONS_H
#define TIMER_CALLBACK_FUNCTIONS_H


#ifndef THE_DATA_H
#include "TheData.h"
#endif

#ifndef JOYSTICK_H
#include "Joystick.h"
#endif
#ifndef VIEWS_H
#include "Views.h"
#endif


bool joystickDataCallback(struct repeating_timer *t);
bool viewResetCallback(struct repeating_timer *t);


#endif
