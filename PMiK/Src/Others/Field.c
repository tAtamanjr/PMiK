/**
 * \file	Field.c
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef FIELD_H
#include "Field.h"


static void set(field_t *, coordinates_t, uint8_t);
static uint8_t read(const field_t *, coordinates_t);


void initField(field_t *field) {
	*field = (field_t) {
          .self = {0},
          .set = set,
          .read = read
    };
}

static void set(field_t *field, const coordinates_t cell, const uint8_t value) {
    if (cell.x == UNDEFINED_COORDINATE || cell.x > J || cell.y == UNDEFINED_COORDINATE || cell.y > J) return;
	field->self[cell.x + cell.y * FIELD_SIZE] = value;
}

static uint8_t read(const field_t *field, const coordinates_t cell) {
	if (cell.x > J || cell.y > J) return UNDEFINED_COORDINATE;
	return field->self[cell.x + cell.y * FIELD_SIZE];
}


#endif
