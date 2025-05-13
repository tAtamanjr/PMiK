/**
 * \file	Byte.h
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef BYTE_H
#define BYTE_H


#ifndef THE_DATA_H
#include "TheData.h"
#endif


typedef struct Byte {
	uint8_t bits;

	void (*on) (struct Byte *byte, const uint8_t bit);
	void (*off) (struct Byte *byte, const uint8_t bit);
	bool (*read) (const struct Byte *byte, const uint8_t bit);
	void (*reset) (struct Byte *byte);
} byte_t;


void initByte(byte_t *byte);


#endif