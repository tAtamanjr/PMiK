//
// Oleksandr "tAtaman" Bolbat
// PMiK project
//

#ifndef IRQ_CALLBACK_FUNCTIONS_H
#include "IRQCallbackFunctions.h" 


void joystickSwitchCallback(uint gpio, uint32_t events) {
    printf("Switch released\n");
}


#endif
