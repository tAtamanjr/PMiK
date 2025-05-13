/**
 * \file	Defines_SPI.h
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef DEFINES_SPI_H
#define DEFINES_SPI_H


#define SPI_PORT    spi0
#define GPIO_SCK    18
#define GPIO_SDA    19
#define GPIO_CS     17
#define GPIO_DC     16
#define GPIO_RESET  21


#define RST_SLEEP       sleep_ms(100)
#define INIT_SLEEP      sleep_ms(150)

#define SET_DC_0        gpio_put(GPIO_DC, 0)
#define SET_DC_1        gpio_put(GPIO_DC, 1)
#define SET_CS_0        gpio_put(GPIO_CS, 0)
#define SET_CS_1        gpio_put(GPIO_CS, 1)
#define SET_RST_0       gpio_put(GPIO_RESET, 0)
#define SET_RST_1       gpio_put(GPIO_RESET, 1)


#endif
