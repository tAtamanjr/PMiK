/**
 * @file	InputModulesFlags.h
 * @brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef INPUT_MODULES_FLAGS_H
#define INPUT_MODULES_FLAGS_H


#ifndef THE_DATA_H
#include "TheData.h"
#endif


typedef struct InputModulesFlags {
    uint8_t flags;

    void (*setOnViewChangeButtonDebouncerFlag) ();
    void (*setOnMainActionButtonDebouncerFlag) ();
    void (*setOnAdditionalActionButtonDebouncerFlag) ();
    void (*setOnJoystickActionDebouncerFlag) ();

    void (*setOffViewChangeButtonDebouncerFlag) ();
    void (*setOffMainActionButtonDebouncerFlag) ();
    void (*setOffAdditionalActionButtonDebouncerFlag) ();
    void (*setOffJoystickActionDebouncerFlag) ();

    bool (*viewChangeButtonDebouncerFlag) ();
    bool (*mainActionButtonDebouncerFlag) ();
    bool (*additionalActionButtonDebouncerFlag) ();
    bool (*joystickActionDebouncerFlag) ();
} inputModulesFlags_t;


extern inputModulesFlags_t inputModulesFlags;


void initInputModulesFlags();


#endif
