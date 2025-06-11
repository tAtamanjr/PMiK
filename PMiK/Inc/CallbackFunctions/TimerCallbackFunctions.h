/**
 * \file	TimerCallbackFunctions.h
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
#ifndef UI_MANAGER_H
#include "UIManager.h"
#endif
#ifndef MODEL_H
#include "Model.h"
#endif
#ifndef ALARM_CLABACK_FUNCTIONS_H
#include "AlarmCallbackFunctions.h"
#endif


extern struct repeating_timer timer;
extern struct repeating_timer viewResetter;


bool joystickDataCallback(struct repeating_timer *t);
bool UIManagerUpdateCallback(struct repeating_timer *t);


#endif
