/**
 * @file	Field.c
 * @brief   Game field
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef FIELD_H
#include "Field.h"


static void set(field_t *, coordinates_t, uint8_t);
static uint8_t read(const field_t *, coordinates_t);


/**
 * @brief Initialize structure
 */
void initField(field_t *field) {
	*field = (field_t) {
          .self = {0},
          .set = set,
          .read = read
    };
}

/**
 * @brief Set field cell to some value
 * @param field - field to be changed
 * @param cell - on field cell to be changed
 * @param value - value to set
 */
static void set(field_t *field, const coordinates_t cell, const uint8_t value) {
    if (cell.x > J || cell.y > J) return;
	field->self[cell.x + cell.y * FIELD_SIZE] = value;
}

/**
 * @brief Read field cell
 * @param field - field to be readed
 * @param cell - on field cell to be readed
 */
static uint8_t read(const field_t *field, const coordinates_t cell) {
	if (cell.x > J || cell.y > J) return UNDEFINED_COORDINATE;
	return field->self[cell.x + cell.y * FIELD_SIZE];
}


#endif
