/**
 * @file	AlarmCallbackFunctions.h
 * @brief   Callback functions for alarms
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef ALARM_CALLBACK_FUNCTIONS_H
#define ALARM_CALLBACK_FUNCTIONS_H


#ifndef THE_DATA_H
#include "TheData.h"
#endif

#ifndef INPUT_MODULES_FLAGS_H
#include "InputModulesFlags.h"
#endif


extern alarm_id_t viewChangeButtonDebouncerAlarm;
extern alarm_id_t mainActionButtonDebouncerAlarm;
extern alarm_id_t additionalActionButtonDebouncerAlarm;
extern alarm_id_t joystickActionDebouncerAlarm;


int64_t viewChangeButtonDebouncerCallback(alarm_id_t id, void *user_data);
int64_t mainActionButtonDebouncerCallback(alarm_id_t id, void *user_data);
int64_t additionalActionButtonDebouncerCallback(alarm_id_t id, void *user_data);
int64_t joystickActionDebouncerCallback(alarm_id_t id, void *user_data);


#endif
