//
// Oleksandr "tAtaman" Bolbat
// PMiK project
//

#ifndef DISPLAY_H
#include "Display.h"

inline static void init();
inline static void reset();
inline static void writeCommand(unsigned char);
inline static void writeByte(unsigned char);
static void setPixel(unsigned char, unsigned char, COLOR_T);


void initDisplay(display_t *display) {
    init();

    display->setPixel = setPixel;
}

static void setPixel(const unsigned char x, const unsigned char y, const COLOR_T color) {

}

inline static void init() {
    reset();
    sleep_ms(DELAY_MS);

    writeCommand(SWRESET);
    sleep_ms(DELAY_MS);
    writeCommand(SLPOUT);
    sleep_ms(200);

    writeCommand(COLMOD);
    writeByte(0x05);
    writeCommand(DISPON);
}

inline static void reset() {
    DESELECT_DISPLAY;

    gpio_put(GPIO_RESET, 0);
    sleep_ms(120);

    gpio_put(GPIO_RESET, 1);
    SELECT_DISPLAY;
}

inline static void writeCommand(const unsigned char command) {
    gpio_put(GPIO_DC, SEND_COMMAND);
    spi_write_blocking(spi_default, &command, 1);
}

inline static void writeByte(const unsigned char byte) {
    gpio_put(GPIO_DC, SEND_DATA);
    spi_write_blocking(spi_default, &byte, 1);
}


#endif