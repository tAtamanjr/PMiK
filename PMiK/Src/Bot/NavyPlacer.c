/**
 * \file	NavyPlacer.c
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef NAVY_PLACER_H
#include "NavyPlacer.h"


static uint8_t generateRandomCoordinates(field_t *, ship_t *);
static uint8_t chooseCoordinatesFromFreeSpace(field_t *, ship_t *);
static uint8_t findPlaceForShip(const field_t *, const ship_t *);


uint8_t placeNavy(field_t *field) {
	for (uint8_t index = 0; index < SHIPS_AMOUNT; index++) {
		const uint8_t ships[SHIPS_AMOUNT] = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1};
		const uint8_t direction = randomNumber(0, 1);

		ship_t ship = (ship_t) {(coordinates_t) {UNDEFINED_COORDINATE, UNDEFINED_COORDINATE}, direction, ships[index]};

		if (generateRandomCoordinates(field, &ship) == 0) {
			if (chooseCoordinatesFromFreeSpace(field, &ship) == 0) {
				initField(field);
				return 0;
			}
		}
	}
	return 1;
}

static uint8_t generateRandomCoordinates(field_t *field, ship_t *ship) {
	uint8_t tries = 0;

	do {
		if (ship->direction) {
			ship->bow.x = randomNumber(0, FIELD_SIZE - ship->length);
			ship->bow.y = randomNumber(0, J);
		} else {
			ship->bow.x = randomNumber(0, J);
			ship->bow.y = randomNumber(0, FIELD_SIZE - ship->length);
		}
		if (findPlaceForShip(field, ship)) {
			if (ship->direction) {
				if (ship->length == 1) field->set(field, (coordinates_t) {ship->bow.x, ship->bow.y}, BOAT_HORIZONTAL);
				else {
					for (uint8_t x = ship->bow.x; x < ship->bow.x + ship->length; x++) {
						if (x == ship->bow.x) field->set(field, (coordinates_t) {ship->bow.x, ship->bow.y}, BOW_HORIZONTAL);
						else if (x == ship->bow.x + ship->length - 1) field->set(field, (coordinates_t) {x, ship->bow.y}, END_HORIZONTAL);
						else field->set(field, (coordinates_t) {x, ship->bow.y}, MIDDLE_PART_HORIZONTAL);
					}
				}
				return 1;
			} else {
				if (ship->length == 1) field->set(field, (coordinates_t) {ship->bow.x, ship->bow.y}, BOAT_VERTICAL);
				else {
					for (uint8_t y = ship->bow.y; y < ship->bow.y + ship->length; y++) {
						if (y == ship->bow.y) field->set(field, (coordinates_t) {ship->bow.x, ship->bow.y}, BOW_VERTICLE);
						else if (y == ship->bow.y + ship->length - 1) field->set(field, (coordinates_t) {ship->bow.x, y}, END_VERTICLE);
						else field->set(field, (coordinates_t) {ship->bow.x, y}, MIDDLE_PART_VERTICLE);
					}
				}
				return 1;
			}
		}
	} while (tries++ < 5);
	return 0;
}

static uint8_t chooseCoordinatesFromFreeSpace(field_t *field, ship_t *ship) {
	if (ship->direction) {
		for (uint8_t y = 0; y < FIELD_SIZE; y++) {
			for (uint8_t x = 0; x < (uint8_t) (FIELD_SIZE - ship->length + 1); x++) {
				if (field->read(field, (coordinates_t) {x, y})) {
					ship->bow.x = x;
					ship->bow.y = y;

					if (findPlaceForShip(field, ship)) {
						if (ship->length == 1) field->set(field, (coordinates_t) {x, y}, BOAT_HORIZONTAL);
						else {
							for (uint8_t res = x; res < x + ship->length; res++) {
								if (res == x) field->set(field, (coordinates_t) {x, y}, BOW_HORIZONTAL);
								else if (res == x + ship->length - 1) field->set(field, (coordinates_t) {res, y}, END_HORIZONTAL);
								else field->set(field, (coordinates_t) {res, y}, MIDDLE_PART_HORIZONTAL);
							}
						}
						return 1;
					}
				}
			}
		}
	} else {
		for (uint8_t y = 0; y < (uint8_t) (FIELD_SIZE - ship->length + 1); y++) {
			for (uint8_t x = 0; x < FIELD_SIZE; x++) {
				if (field->read(field, (coordinates_t) {x, y})) {
					ship->bow.x = x;
					ship->bow.y = y;

					if (findPlaceForShip(field, ship)) {
						if (ship->length == 1) field->set(field, (coordinates_t) {x, y}, BOAT_VERTICAL);
						else {
							for (uint8_t res = y; res < y + ship->length; res++) {
								if (res == y) field->set(field, (coordinates_t) {x, y}, BOW_VERTICLE);
								else if (res == y + ship->length - 1) field->set(field, (coordinates_t) {x, res}, END_VERTICLE);
								else field->set(field, (coordinates_t) {x, res}, MIDDLE_PART_VERTICLE);
							}
						}
						return 1;
					}
				}
			}
		}
	}
	return 0;
}

static uint8_t findPlaceForShip(const field_t *field, const ship_t *ship) {
	uint8_t startX;
	uint8_t startY;
	uint8_t endX;
	uint8_t endY;

	if (ship->direction) {
		if (!ship->bow.x) startX = 0;
		else startX = ship->bow.x - 1;
		if (ship->bow.x == FIELD_SIZE - ship->length) endX = J;
		else endX = ship->bow.x + ship->length;
		if (!ship->bow.y) startY = 0;
		else startY = ship->bow.y - 1;
		if (ship->bow.y == FIELD_SIZE - 1) endY = J;
		else endY = ship->bow.y + 1;
	} else {
		if (!ship->bow.x) startX = 0;
		else startX = ship->bow.x - 1;
		if (ship->bow.x == FIELD_SIZE - 1) endX = J;
		else endX = ship->bow.x + 1;
		if (!ship->bow.y) startY = 0;
		else startY = ship->bow.y - 1;
		if (ship->bow.y == FIELD_SIZE - ship->length) endY = J;
		else endY = ship->bow.y + ship->length;
	}

	for (uint8_t y = startY; y <= endY; y++) {
		for (uint8_t x = startX; x <= endX; x++) {
			if (field->read(field, (coordinates_t) {x, y})) return 0;
		}
	}

	return 1;
}


#endif
