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
    viewChangeButtonDebouncerFlag = 1;
    return 0;
}

int64_t mainActionButtonDebouncerCallback(alarm_id_t id, void *user_data) {
    mainActionButtonDebouncerFlag = 1;
    return 0;
}

int64_t additionalActionButtonDebouncerCallback(alarm_id_t id, void *user_data) {
    additionalActionButtonDebouncerFlag = 1;
    return 0;
}

int64_t joystickactionDebouncerCallback(alarm_id_t id, void *user_data) {
    joystickActionDebouncerFlag = 1;
    return 0;
}


#endif
