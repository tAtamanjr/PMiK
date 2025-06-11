/**
 * \file	Model.h
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef MODEL_H
#define MODEL_H


#ifndef THE_DATA_H
#include "TheData.h"
#endif

#ifndef JOYSTICK_H
#include "Joystick.h"
#endif
#ifndef DISPLAY_H
#include "Display.h"
#endif
#ifndef UI_MANAGER_H
#include "UIManager.h"
#endif
#ifndef ALARM_CALLBACK_FUNCTIONS_H
#include "AlarmCallbackFunctions.h"
#endif


typedef struct Model {
    uint8_t mainMenuElementIndex;

    void (*reactOnViewChangeButtonPressed) ();
    void (*reactOnMainActionButtonPressed) ();
    void (*reactOnAdditionalActionButtonPressed) ();

    void (*reactOnJoystick) ();
} model_t;


extern model_t model;


void initModel();


#endif
