/**
 * @file	TheData.h
 * @brief   Useful functions
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef THE_DATA_H
#include "TheData.h"


/**
 * @brief Generate random number
 * @param min - minimum value
 * @param max - maximum value
 */
uint8_t randomNumber(const uint8_t min, const uint8_t max) {
    return ((uint8_t) get_rand_32()) % (max - min + 1) + min;
}

/**
 * @brief Convert on field coordinates to on display pixel
 * @param coordinate - on field coordinate
 */
uint8_t coordinateToPixel(const uint8_t coordinate) {
    return 19 + coordinate * 11;
}

/**
 * @brief Convert on field coordinates to on display pixel and adds some shift
 * @param coordinate - on field coordinate
 * @param shift - shift
 */
uint8_t coordinateToPixelWithShift(const uint8_t coordinate, const uint8_t shift) {
    return 19 + coordinate * 11 + shift;
}


#endif
