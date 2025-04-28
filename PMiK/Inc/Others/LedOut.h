//
// Oleksandr "tAtaman" Bolbat
// PMiK project
//

#ifndef LED_OUT_H
#define LED_OUT_H


#ifndef THE_DATA_H
#include "TheData.h"
#endif


typedef struct LedOut {
    void (*on) ();
    void (*off) ();
    void (*set) (const bool);
} ledOut_t;


void initLedOut(ledOut_t *ledOut);


#endif