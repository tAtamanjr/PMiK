/**
 * \file	TheData.h
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef THE_DATA_H
#define THE_DATA_H


#ifndef STDLIB_H
#include "pico/stdlib.h"
#endif
#ifndef CYW43_ARCH_H
#include "pico/cyw43_arch.h"
#endif
#ifndef GPIO_H
#include "hardware/gpio.h"
#endif
#ifndef ADC_H
#include "hardware/adc.h"
#endif
#ifndef SPI_H
#include "hardware/spi.h"
#endif


#ifndef COLOR_H
#include "Color.h"
#endif
#ifndef DEFINES_ADC_H
#include "Defines_ADC.h"
#endif
#ifndef DEFINES_JOYSTICK_H
#include "Defines_Joystick.h"
#endif
#ifndef DEFINES_SPI_H
#include "Defines_SPI.h"
#endif
#ifndef DEFINES_DISPLAY_H
#include "Defines_Display.h"
#endif


#ifndef DIRECTION_H
#include "Direction.h"
#endif


#ifndef TIMER_CALLBACK_FUNCTIONS_H
#include "TimerCallbackFunctions.h"
#endif
#ifndef IRQ_CALLBACK_FUNCTIONS_H
#include "IRQCallbackFunctions.h"
#endif


extern struct Joystick joystick;
extern struct Display  display;


#endif
