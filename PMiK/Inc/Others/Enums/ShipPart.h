/**
 * \file	ShipPart.h
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef SHIP_PART_H
#define SHIP_PART_H


typedef enum ShipPart {
	FREE_CELL,
    BOAT_HORIZONTAL,
	BOAT_VERTICAL,
    MIDDLE_PART_HORIZONTAL,
    MIDDLE_PART_VERTICLE,
    BOW_HORIZONTAL,
    BOW_VERTICLE,
    END_HORIZONTAL,
    END_VERTICLE,
    DESTROYED_SHIP_PART
} shipPart_e;


#endif
