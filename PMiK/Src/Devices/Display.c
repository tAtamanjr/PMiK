/**
 * \file	Display.c
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef DISPLAY_H
#include "Display.h"


static inline void sendCommand(uint8_t);
static inline void sendData(uint8_t *, size_t);
static void hardReset();
static void setWindow(uint8_t, uint8_t, uint8_t, uint8_t);
static void fillScreen(color_t);
static void drawPixel(uint8_t, uint8_t, color_t);
static void fillRectangle(uint8_t, uint8_t, uint8_t, uint8_t, color_t);
static void drawHorizontalLine(uint8_t, uint8_t, uint8_t, uint8_t, color_t);
static void drawVerticalLine(uint8_t, uint8_t, uint8_t, uint8_t, color_t);


void initDisplay(display_t *display) {
    gpio_init(GPIO_CS);
    gpio_init(GPIO_DC);
    gpio_init(GPIO_RESET);

    gpio_set_dir(GPIO_CS, GPIO_OUT);
    gpio_set_dir(GPIO_DC, GPIO_OUT);
    gpio_set_dir(GPIO_RESET, GPIO_OUT);

    spi_init(SPI_PORT, 20 * 1000 * 1000);
    gpio_set_function(GPIO_SCK, GPIO_FUNC_SPI);
    gpio_set_function(GPIO_SDA, GPIO_FUNC_SPI);

    SET_CS_1;

    hardReset();

    sendCommand(SWRESET);
    INIT_SLEEP;
    sendCommand(SLPOUT);
    INIT_SLEEP;

    sendCommand(COLMOD);
    uint8_t colorMode = 0x05; //16 bit colors
    sendData(&colorMode, 1);

    sendCommand(MADCTL);
    uint8_t madctl = 0x00; //16 bit colors
    sendData(&madctl, 1);

    sendCommand(DISPON);
    INIT_SLEEP;

    display->fillScreen = fillScreen;
    display->drawPixel = drawPixel;
    display->fillRectangle = fillRectangle;
    display->drawHorizontalLine = drawHorizontalLine;
    display->drawVerticalLine = drawVerticalLine;
}

static void fillScreen(color_t color) {
    fillRectangle(0, 0, DISPLAY_SIZE_X, DISPLAY_SIZE_Y, color);
}

static void drawPixel(uint8_t x, uint8_t y, color_t color) {
    if (x >= DISPLAY_SIZE_X || y >= DISPLAY_SIZE_Y) return;
    setWindow(x, y, x, y);
    uint8_t data[2] = {color >> 8, color & 0xff};
    sendData(data, 2);
}

static void fillRectangle(uint8_t x, uint8_t y, uint8_t w, uint8_t h, color_t color) {
    if (x >= DISPLAY_SIZE_X || y >= DISPLAY_SIZE_Y) return;
    if ((x + w - 1) >= DISPLAY_SIZE_X) w = DISPLAY_SIZE_X - x;
    if ((y + h - 1) >= DISPLAY_SIZE_Y) h = DISPLAY_SIZE_Y - y;

    setWindow(x, y, x + w - 1, y + h - 1);

    uint8_t data[2] = {color >> 8,  color & 0xff};
    for (int i = 0; i < w * h; i++) {
        sendData(data, 2);
    }
}

void drawHorizontalLine(uint8_t x, uint8_t y, uint8_t l, uint8_t w, color_t color) {
    if (x >= DISPLAY_SIZE_X || y >= DISPLAY_SIZE_Y) return;
    if ((x + l - 1) >= DISPLAY_SIZE_X) l = DISPLAY_SIZE_X - x;
    if ((y + w - 1) >= DISPLAY_SIZE_Y) w = DISPLAY_SIZE_Y - y;

    setWindow(x, y, x + l - 1, y + w - 1);

    uint8_t data[2] = {color >> 8,  color & 0xff};
    for (int i = 0; i < l * w; i++) {
        sendData(data, 2);
    }
}

void drawVerticalLine(uint8_t x, uint8_t y, uint8_t l, uint8_t w, color_t color) {
    if (x >= DISPLAY_SIZE_X || y >= DISPLAY_SIZE_Y) return;
    if ((x + w - 1) >= DISPLAY_SIZE_X) w = DISPLAY_SIZE_X - x;
    if ((y + l - 1) >= DISPLAY_SIZE_Y) l = DISPLAY_SIZE_Y - y;

    setWindow(x, y, x + w - 1, y + l - 1);

    uint8_t data[2] = {color >> 8,  color & 0xff};
    for (int i = 0; i < l * w; i++) {
        sendData(data, 2);
    }
}


static inline void sendCommand(uint8_t cmd) {
    SET_DC_0;
    SET_CS_0;
    spi_write_blocking(SPI_PORT, &cmd, 1);
    SET_CS_1;
}

static inline void sendData(uint8_t *data, size_t len) {
    SET_DC_1;
    SET_CS_0;
    spi_write_blocking(SPI_PORT, data, len);
    SET_CS_1;
}

static void hardReset(void) {
    SET_RST_0;
    RST_SLEEP;
    SET_RST_1;
    RST_SLEEP;
}

void setWindow(uint8_t startX, uint8_t startY, uint8_t endX, uint8_t endY) {
    uint8_t data[4];

    sendCommand(CASET);
    data[0] = 0; data[1] = startX;
    data[2] = 0; data[3] = endX;
    sendData(data, 4);

    sendCommand(RASET);
    data[0] = 0; data[1] = startY;
    data[2] = 0; data[3] = endY;
    sendData(data, 4);

    sendCommand(RAMWR);
}


#endif