/**
 * \file	AlarmCallbackFunctions.h
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef ALARM_CALLBACK_FUNCTIONS_H
#define ALARM_CALLBACK_FUNCTIONS_H


#ifndef THE_DATA_H
#include "TheData.h"
#endif


extern uint8_t viewChangeButtonDebouncerFlag;
extern uint8_t mainActionButtonDebouncerFlag;
extern uint8_t additionalActionButtonDebouncerFlag;
extern uint8_t joystickActionDebouncerFlag;

extern alarm_id_t viewChangeButtonDebouncerAlarm;
extern alarm_id_t mainActionButtonDebouncerAlarm;
extern alarm_id_t additionalActionButtonDebouncerAlarm;
extern alarm_id_t joystickActionDebouncerAlarm;

int64_t viewChangeButtonDebouncerCallback(alarm_id_t id, void *user_data);
int64_t mainActionButtonDebouncerCallback(alarm_id_t id, void *user_data);
int64_t additionalActionButtonDebouncerCallback(alarm_id_t id, void *user_data);
int64_t joystickactionDebouncerCallback(alarm_id_t id, void *user_data);


#endif
