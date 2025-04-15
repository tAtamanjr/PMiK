//
// Created by Oleksandr Bolbat, PMiK project
// Type for helding flags
//

#if !defined(BYTE_H)
#define BYTE_H


#if !defined(STDLIB_H)
#include "pico/stdlib.h"
#endif


typedef struct Byte {
	uint8_t bits;

	void (*on) (struct Byte *, const uint8_t);
	void (*off) (struct Byte *, const uint8_t);
	bool (*read) (const struct Byte *, const uint8_t);
	void (*reset) (struct Byte *);
} byte_t;


byte_t newByte();


#endif