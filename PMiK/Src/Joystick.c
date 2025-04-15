//
// Created by Oleksandr Bolbat, PMiK project
// Type for hendling data about state of joystick
//

#if !defined(JOYSTICK_H)
#include "Joystick.h"


static void init(joystick_t *, const uint8_t, const uint8_t);
static Direction read(joystick_t *);


joystick_t newJoystick() {
    return (joystick_t) {
        .xPosition = 0x0000,
        .yPosition = 0x0000,
        .ADC_X = 0,
        .ADC_Y = 1,
        .init = init,
        .read = read
    };
}

static void init(joystick_t *self, const uint8_t GPIO_X, const uint8_t GPIO_Y) {
    switch (GPIO_X) {
        case 26:
            self->ADC_X = 0;
            break;
        case 27:
            self->ADC_X = 1;
            break;
        default:
            self->ADC_X = 2;
            break;
    }
    switch (GPIO_Y) {
        case 27:
            self->ADC_Y = 1;
            break;
        case 26:
            self->ADC_Y = 0;
            break;
        default:
            self->ADC_Y = 2;
            break;
    }

    adc_gpio_init(GPIO_X);
    adc_gpio_init(GPIO_Y);
}

static Direction read(joystick_t *self) {
    adc_select_input(self->ADC_X);
    self->xPosition = adc_read();
    adc_select_input(self->ADC_Y);
    self->yPosition = adc_read();

    if (self->xPosition >= 3071) {
        if (self->yPosition >= 3071) return UP_AND_RIGHT;
        else if (self->yPosition <= 1024) return UP_AND_LEFT;
        else return UP;
    } else if (self->yPosition >= 3071) {
        if (self->xPosition <= 1024) return DOWN_AND_RIGHT;
        else return RIGHT;
    } else if (self->yPosition <= 1024) {
        if (self->xPosition <= 1024) return DOWN_AND_LEFT;
        else return LEFT;
    } else if (self->xPosition <= 1024) return DOWN;
    else return NONE;
}


#endif