/**
 * \file	Ship.h
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef SHIP_H
#define SHIP_H


#ifndef THEAD_H
#include "TheData.h"
#endif

#ifndef COORDINATES_H
#include "Coordinates.h"
#endif


typedef struct Ship {
	coordinates_t bow;
	uint8_t direction;
	uint8_t length;
} ship_t;


#endif
