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
#ifndef RAND_H
#include "pico/rand.h"
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
#ifndef TIMER_H
#include "hardware/timer.h"
#endif

#ifndef DEFINES_OTHER_H
#include "Defines_Other.h"
#endif
#ifndef DEFINES_BUTTONS_H
#include "Defines_Buttons.h"
#endif
#ifndef DEFINES_COLOR_H
#include "Defines_Color.h"
#endif
#ifndef DEFINES_GAME_H
#include "Defines_Game.h"
#endif
#ifndef DEFINES_ADC_H
#include "Defines_ADC.h"
#endif
#ifndef DEFINES_SPI_H
#include "Defines_SPI.h"
#endif
#ifndef DEFINES_DISPLAY_H
#include "Defines_Display.h"
#endif
#ifndef DEFINES_UI_MANAGER
#include "Defines_UIManager.h"
#endif

#ifndef ENUM_COORDINATE_H
#include "Enum_Coordinate.h"
#endif
#ifndef ENUM_DIFFICULTY_H
#include "Enum_Difficulty.h"
#endif
#ifndef ENUM_DIRECTION_H
#include "Enum_Direction.h"
#endif
#ifndef ENUM_LETTER_H
#include "Enum_Letter.h"
#endif
#ifndef ENUM_SHIP_PART_H
#include "Enum_ShipPart.h"
#endif
#ifndef ENUM_SHOT_RESULT_H
#include "Enum_ShotResult.h"
#endif


extern struct LedOut ledOut;
extern struct Byte buttonFlags;
extern struct Field someField;


uint8_t randomNumber(const uint8_t min, const uint8_t max);


#endif
