/**
 * @file	InputModulesFlags.c
 * @brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef INPUT_MODULES_FLAGS_H
#include "InputModulesFlags.h"


static void setOnViewChangeButtonDebouncerFlag();
static void setOnMainActionButtonDebouncerFlag();
static void setOnAdditionalActionButtonDebouncerFlag();
static void setOnJoystickActionDebouncerFlag();

static void setOffViewChangeButtonDebouncerFlag();
static void setOffMainActionButtonDebouncerFlag();
static void setOffAdditionalActionButtonDebouncerFlag();
static void setOffJoystickActionDebouncerFlag();

static bool viewChangeButtonDebouncerFlag();
static bool mainActionButtonDebouncerFlag();
static bool additionalActionButtonDebouncerFlag();
static bool joystickActionDebouncerFlag();


void initInputModulesFlags() {
    inputModulesFlags.flags = 0x00;

    inputModulesFlags.setOnViewChangeButtonDebouncerFlag = setOnViewChangeButtonDebouncerFlag;
    inputModulesFlags.setOnMainActionButtonDebouncerFlag = setOnMainActionButtonDebouncerFlag;
    inputModulesFlags.setOnAdditionalActionButtonDebouncerFlag = setOnAdditionalActionButtonDebouncerFlag;
    inputModulesFlags.setOnJoystickActionDebouncerFlag = setOnJoystickActionDebouncerFlag;

    inputModulesFlags.setOffViewChangeButtonDebouncerFlag = setOffViewChangeButtonDebouncerFlag;
    inputModulesFlags.setOffMainActionButtonDebouncerFlag = setOffMainActionButtonDebouncerFlag;
    inputModulesFlags.setOffAdditionalActionButtonDebouncerFlag = setOffAdditionalActionButtonDebouncerFlag;
    inputModulesFlags.setOffJoystickActionDebouncerFlag = setOffJoystickActionDebouncerFlag;

    inputModulesFlags.viewChangeButtonDebouncerFlag = viewChangeButtonDebouncerFlag;
    inputModulesFlags.mainActionButtonDebouncerFlag = mainActionButtonDebouncerFlag;
    inputModulesFlags.additionalActionButtonDebouncerFlag = additionalActionButtonDebouncerFlag;
    inputModulesFlags.joystickActionDebouncerFlag = joystickActionDebouncerFlag;
}


void setOnViewChangeButtonDebouncerFlag() {
    inputModulesFlags.flags |= 1 << 0;
}

void setOnMainActionButtonDebouncerFlag() {
    inputModulesFlags.flags |= 1 << 1;
}

void setOnAdditionalActionButtonDebouncerFlag() {
    inputModulesFlags.flags |= 1 << 2;
}

void setOnJoystickActionDebouncerFlag() {
    inputModulesFlags.flags |= 1 << 3;
}

void setOffViewChangeButtonDebouncerFlag() {
    inputModulesFlags.flags &= 0 << 0;
}

void setOffMainActionButtonDebouncerFlag() {
    inputModulesFlags.flags &= 0 << 1;
}

void setOffAdditionalActionButtonDebouncerFlag() {
    inputModulesFlags.flags &= 0 << 2;
}

void setOffJoystickActionDebouncerFlag() {
    inputModulesFlags.flags &= 0 << 3;
}

bool viewChangeButtonDebouncerFlag() {
    return inputModulesFlags.flags & 1 << 0;
}

bool mainActionButtonDebouncerFlag() {
    return inputModulesFlags.flags & 1 << 1;
}

bool additionalActionButtonDebouncerFlag() {
    return inputModulesFlags.flags & 1 << 2;
}

bool joystickActionDebouncerFlag() {
    return inputModulesFlags.flags & 1 << 3;
}


#endif
