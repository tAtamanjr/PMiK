/**
 * @file	GameData.h
 * @brief	Usefull data and functions during the game
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef GAME_DATA_H
#define GAME_DATA_H


#ifndef THE_DATA_H
#include "TheData.h"
#endif

#ifndef COORDINATES_H
#include "Coordinates.h"
#endif
#ifndef FIELD_H
#include "Field.h"
#endif
#ifndef SHIP_H
#include "Ship.h"
#endif


typedef struct GameData {
    uint8_t ships[SHIPS_AMOUNT];
    uint8_t index;
    uint8_t direction;
    coordinates_t position;
    field_t field;
} gameData_t;


extern gameData_t gameData;


void initGameData();
uint8_t findPlaceForShip(const field_t *, const ship_t *);


#endif
