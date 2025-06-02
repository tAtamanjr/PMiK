/**
 * \file	IRQCallBackFunctions.h
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef IRQ_CALLBACK_FUNCTIONS_H
#define IRQ_CALLBACK_FUNCTIONS_H


#ifndef THE_DATA_H
#include "TheData.h"
#endif

#ifndef BYTE_H
#include "Byte.h"
#endif
#ifndef ALARM_CLABACK_FUNCTIONS_H
#include "AlarmCallbackFunctions.h"
#endif
#ifndef NAVY_PLACER_H
#include "NavyPlacer.h"
#endif
#ifndef VIEWS_H
#include "Views.h"
#endif
#ifndef UI_MANAGER_H
#include "UIManager.h"
#endif


void callbackSwitcher(uint gpio, uint32_t events);


#endif
