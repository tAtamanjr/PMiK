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

#ifndef BYTE_H
#include "Byte.h"
#endif


extern alarm_id_t mainAlarm;
extern alarm_id_t confirmAlarm;
extern alarm_id_t suppAlarm1;
extern uint8_t joystickMoveDebouncerFlag;
extern uint8_t resetNavyDebouncerFlag;
extern uint8_t fireDebouncerFlag;
extern alarm_id_t joystickMoveDebouncerAlarm;
extern alarm_id_t resetNavyDebouncerAlarm;
extern alarm_id_t fireDebouncerAlarm;


int64_t mainButtonAlarmCallback(alarm_id_t id, void *user_data);
int64_t confirmButtonAlarmCallback(alarm_id_t id, void *user_data);
int64_t suppButton1AlarmCallback(alarm_id_t id, void *user_data);
int64_t joystickMoveDebouncerCallback(alarm_id_t id, void *user_data);
int64_t resetNavyDebouncerCallback(alarm_id_t id, void *user_data);
int64_t fireDebouncerCallback(alarm_id_t id, void *user_data);


#endif
