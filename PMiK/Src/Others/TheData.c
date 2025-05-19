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


#endif
