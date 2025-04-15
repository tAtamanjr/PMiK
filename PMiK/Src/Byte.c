//
// Created by Oleksandr Bolbat, PMiK project
// Type for helding flags
//

#if !defined(BYTE_H)
#include "byte.h"


static void on(byte_t *, const uint8_t);
static void off(byte_t *, const uint8_t);
static bool read(const byte_t *, const uint8_t);
static void reset(byte_t *);


byte_t newByte() {
    return (byte_t) {
        .bits = 0x00,
        .on = on,
        .off = off,
        .reset = reset,
        .read = read
    };
}

static void on(byte_t *self, const uint8_t bit) {
    self->bits |= 1 << bit;
}

static void off(byte_t *self, const uint8_t bit) {
    self->bits &= 0 << bit;
}

static bool read(const byte_t *self, const uint8_t bit) {
    return (self->bits & 1 << bit);
}

static void reset(byte_t *self) {
    self->bits = 0x00;
}


#endif