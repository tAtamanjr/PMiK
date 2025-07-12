/**
 * @file	AlarmCallbackFunctions.c
 * @brief   Callback functions for alarms
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef ALARM_CALLBACK_FUNCTIONS_H
#include "AlarmCallbackFunctions.h"


int64_t viewChangeButtonDebouncerCallback(alarm_id_t id, void *user_data) {
    inputModulesFlags.setOffViewChangeButtonDebouncerFlag();
    return 0;
}

int64_t mainActionButtonDebouncerCallback(alarm_id_t id, void *user_data) {
    inputModulesFlags.setOffMainActionButtonDebouncerFlag();
    return 0;
}

int64_t additionalActionButtonDebouncerCallback(alarm_id_t id, void *user_data) {
    inputModulesFlags.setOffAdditionalActionButtonDebouncerFlag();
    return 0;
}

int64_t joystickActionDebouncerCallback(alarm_id_t id, void *user_data) {
    inputModulesFlags.setOffJoystickActionDebouncerFlag();
    return 0;
}


#endif
