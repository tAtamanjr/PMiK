/**
 * \file	IRQCallBackFunctions
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


void joystickSwitchCallback(uint gpio, uint32_t events);


#endif
