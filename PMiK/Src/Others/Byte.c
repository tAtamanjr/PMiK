//
// Oleksandr "tAtaman" Bolbat
// PMiK project
//

#ifndef BYTE_H
#include "Byte.h"


static void on(byte_t *, unsigned char);
static void off(byte_t *, unsigned char);
static bool read(const byte_t *, unsigned char);
static void reset(byte_t *);


void initByte(byte_t *byte) {
    byte->bits = 0x00;
    byte->on = on;
    byte->off = off;
    byte->reset = reset;
    byte->read = read;
}

static void on(byte_t *byte, const unsigned char bit) {
    byte->bits |= 1 << bit;
}

static void off(byte_t *byte, const unsigned char bit) {
    byte->bits &= 0 << bit;
}

static bool read(const byte_t *byte, const unsigned char bit) {
    return (byte->bits & 1 << bit);
}

static void reset(byte_t *byte) {
    byte->bits = 0x00;
}


#endif