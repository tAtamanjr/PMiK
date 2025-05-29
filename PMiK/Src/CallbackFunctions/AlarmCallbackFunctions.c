/**
 * \file	AlarmCallbackFunctions.c
 * \brief
 */

/*
 * Copyright (c) 2025 Oleksandr "tAtaman" Bolbat
 */

#ifndef ALARM_CALLBACK_FUNCTIONS_H
#include "AlarmCallbackFunctions.h"


int64_t mainButtonAlarmCallback(alarm_id_t id, void *user_data) {
    buttonFlags.off(&buttonFlags, MAIN_WAIT_BIT);
    return 0;
}

int64_t confirmButtonAlarmCallback(alarm_id_t id, void *user_data) {
    buttonFlags.off(&buttonFlags, CONFIRM_WAIT_BIT);
    return 0;
}

int64_t suppButton1AlarmCallback(alarm_id_t id, void *user_data) {
    buttonFlags.off(&buttonFlags, SUPP1_WAIT_BIT);
    return 0;
}

// int64_t suppButton2AlarmCallback(alarm_id_t id, void *user_data) {
//     buttonFlags.off(&buttonFlags, SUPP2_WAIT_BIT);
//     return 0;
// }

int64_t joystickMoveDebouncerCallback(alarm_id_t id, void *user_data) {
    joystickMoveDebouncerFlag = 1;
    return 0;
}

int64_t resetNavyDebouncerCallback(alarm_id_t id, void *user_data) {
    resetNavyDebouncerFlag = 1;
    return 0;
}



#endif
