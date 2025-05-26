/**
 * \file	Byte.c
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef BYTE_H
#include "Byte.h"


static void on(byte_t *, uint8_t);
static void off(byte_t *, uint8_t);
static uint8_t read(const byte_t *, uint8_t);
static void reset(byte_t *);


void initByte(byte_t *byte) {
    byte->bits = 0x00;
    byte->on = on;
    byte->off = off;
    byte->reset = reset;
    byte->read = read;
}

static void on(byte_t *byte, const uint8_t bit) {
    byte->bits |= 1 << bit;
}

static void off(byte_t *byte, const uint8_t bit) {
    byte->bits &= 0 << bit;
}

static uint8_t read(const byte_t *byte, const uint8_t bit) {
    return (byte->bits & 1 << bit);
}

static void reset(byte_t *byte) {
    byte->bits = 0x00;
}


#endif