/**
 * @file	Field.h
 * @brief   Game field
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef FIELD_H
#define FIELD_H


#ifndef THE_DATA_H
#include "TheData.h"
#endif
#ifndef COORDINATES_H
#include "Coordinates.h"
#endif


typedef struct Field {
	uint8_t self[FIELD_SIZE * FIELD_SIZE];

	void (*set) (struct Field *field, coordinates_t cell, uint8_t value);
	uint8_t (*read) (const struct Field *field, coordinates_t cell);
} field_t;


void initField(field_t *field);


#endif
