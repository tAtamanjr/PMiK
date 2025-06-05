/**
 * \file	TheData.h
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef THE_DATA_H
#include "TheData.h"


uint8_t randomNumber(const uint8_t min, const uint8_t max) {
    return ((uint8_t) get_rand_32()) % (max - min + 1) + min;
}

uint8_t coordinateToPixel(const uint8_t coordinate) {
    return 19 + coordinate * 11;
}

uint8_t coordinateToPixelWithShift(const uint8_t coordinate, const uint8_t shift) {
    return 19 + coordinate * 11 + shift;
}


#endif
