/**
 * @file	IRQCallBackFunctions.h
 * @brief   Callback functions for interupts
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef IRQ_CALLBACK_FUNCTIONS_H
#define IRQ_CALLBACK_FUNCTIONS_H


#ifndef THE_DATA_H
#include "TheData.h"
#endif

#ifndef INPUT_MODULES_FLAGS_H
#include "InputModulesFlags.h"
#endif
#ifndef ALARM_CLABACK_FUNCTIONS_H
#include "AlarmCallbackFunctions.h"
#endif
#ifndef MODEL_H
#include "Model.h"
#endif


void callbackSwitcher(uint gpio, uint32_t events);


#endif
