/**
 * @file	Enum_Direction.h
 * @brief	Enumeration with all possible letters
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef ENUM_DIRECTION_H
#define ENUM_DIRECTION_H


typedef enum Direction {
//  Compass  |  Angle  |  Clock  |  Joystick X  |  Joystick Y
    NONE,   //    ¯\_('_')_/¯    |    middle    |    middle
    NP,     //    90   |    12   |    > 3071    |    middle
    NE,     //    45   |   1,5   |    > 3071    |    > 3071
    EP,     //     0   |     3   |    middle    |    > 3071
    SE,     //   315   |   4,5   |    > 1024    |    > 3071
    SP,     //   270   |     6   |    > 1024    |    middle
    SW,     //   225   |   7,5   |    > 1024    |    > 1024
    WP,     //   180   |     9   |    middle    |    > 1024
    NW      //   135   |  10,5   |    > 3071    |    > 1024
} direction_e;


#endif
