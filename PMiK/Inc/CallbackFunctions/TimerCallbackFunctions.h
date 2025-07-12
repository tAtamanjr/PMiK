/**
 * @file	TimerCallbackFunctions.h
 * @brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef TIMER_CALLBACK_FUNCTIONS_H
#define TIMER_CALLBACK_FUNCTIONS_H


#ifndef THE_DATA_H
#include "TheData.h"
#endif

#ifndef INPUT_MODULES_FLAGS_H
#include "InputModulesFlags.h"
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


extern struct repeating_timer joystickTimer;
extern struct repeating_timer UIManagerTimer;
extern struct repeating_timer modelTimer;

extern struct repeating_timer debuggTimer;

extern struct repeating_timer timer;
extern struct repeating_timer viewResetter;


bool updateJoystickDataCallback(struct repeating_timer *t);
bool updateUIManagerCallback(struct repeating_timer *t);
bool updateGameDataCallback(struct repeating_timer *t);

bool debuggCallback(struct repeating_timer *t);

bool joystickDataCallback(struct repeating_timer *t);
bool UIManagerUpdateCallback(struct repeating_timer *t);


#endif
