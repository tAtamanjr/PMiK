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
// extern alarm_id_t suppAlarm2;
extern uint8_t joystickMoveDebouncerFlag;
extern alarm_id_t joystickMoveDebouncerAlarm;


int64_t mainButtonAlarmCallback(alarm_id_t id, void *user_data);
int64_t confirmButtonAlarmCallback(alarm_id_t id, void *user_data);
int64_t suppButton1AlarmCallback(alarm_id_t id, void *user_data);
// int64_t suppButton2AlarmCallback(alarm_id_t id, void *user_data);
int64_t joystickMoveDebouncerCallback(alarm_id_t id, void *user_data);


#endif
