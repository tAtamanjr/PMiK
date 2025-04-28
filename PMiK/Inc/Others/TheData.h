//
// Oleksandr "tAtaman" Bolbat
// PMiK project
//

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


#ifndef DEFINES_ADC_H
#include "Defines_ADC.h"
#endif
#ifndef DEFINES_SPI_H
#include "Defines_SPI.h"
#endif
#ifndef DEFINES_DISPLAY_H
#include "Defines_Display.h"
#endif


#ifndef BYTE_H
#include "Byte.h"
#endif
#ifndef LED_OUT_H
#include "LedOut.h"
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
#ifndef JOYSTICK_H
#include "Joystick.h"
#endif
#ifndef DISPLAY_H
#include "Display.h"
#endif


#ifndef LED_OUT
#define LED_OUT CYW43_WL_GPIO_LED_PIN
#endif
#ifndef JOYSTICK_GPIO_SW
#define JOYSTICK_GPIO_SW    13
#endif
#ifndef k
#define k * 1000
#endif
#ifndef M
#define M * 1000000
#endif


extern struct Joystick joystick;
extern struct Display  display;


#endif
