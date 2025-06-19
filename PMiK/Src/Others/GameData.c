/**
 * @file	GameData.c
 * @brief	Usefull data and functions during the game
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef GAME_DATA_H
#include "GameData.h"


/**
 * @brief Initialize structures
 */
void initGameData() {
    gameData = (gameData_t) {{4, 3, 3, 2, 2, 2, 1, 1, 1, 1}, 0, 0, (coordinates_t) {A, 0}};
    initField(&gameData.field);
}

/**
 * @brief Check if ship's part/boat can be placed in some on field cell
 * @param field - field where ship's part/boat wanted to be placed
 * @param ship - ship parameters
 */
uint8_t findPlaceForShip(const field_t *field, const ship_t *ship) {
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
