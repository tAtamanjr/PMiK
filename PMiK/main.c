//
// Created by Oleksandr Bolbat, PMiK project
//

#if !defined(STDLIB_H)
#include "pico/stdlib.h"
#endif
#if !defined(CYW43_ARCH_H)
#include "pico/cyw43_arch.h"
#endif
#if !defined(ADC_H)
#include "hardware/adc.h"
#endif

#if !defined(BYTE_H)
#include "Byte.h"
#endif
#if !defined(DIRECTION_H)
#include "Direction.h"
#endif
#if !defined(JOYSTICK_H)
#include "Joystick.h"
#endif


#if !defined(ADC_X)
#define GPIO_X 26           // Pin for reading x position
#endif
#if !defined(ADC_Y)
#define GPIO_Y 27           // Pin for reading y position
#endif
#if !defined(GPIO_SW)
#define GPIO_SW 18          // Pin for reading state of switch in joystick
#endif
#if !defined(LED_1)
#define LED_1 16
#endif
#if !defined(LED_0)
#define LED_0 17
#endif


uint16_t xValue;
uint16_t yValue;
Direction direction;
byte_t states;
joystick_t joystick;


void picoInit();


int main() {
    picoInit();

    gpio_init(LED_1);
    gpio_set_dir(LED_1, GPIO_OUT);
    gpio_init(LED_0);
    gpio_set_dir(LED_0, GPIO_OUT);

    states = newByte();
    joystick = newJoystick();
    joystick.init(&joystick, GPIO_X, GPIO_Y);

    // Sine fine loop
    while (true) {
        states.reset(&states);
        direction = joystick.read(&joystick);

        switch (direction) {
            case UP_AND_RIGHT:
                states.on(&states, 2);
                states.on(&states, 1);
                states.on(&states, 0);
                break;
            case UP:
                states.on(&states, 2);
                states.on(&states, 1);
                break;
            case UP_AND_LEFT:
                states.on(&states, 2);
                states.on(&states, 0);
                break;
            case RIGHT:
                states.on(&states, 2);
                break;
            case LEFT:
                states.on(&states, 1);
                states.on(&states, 0);
                break;
            case DOWN_AND_RIGHT:
                states.on(&states, 1);
                break;
            case DOWN:
                states.on(&states, 0);
                break;
            case DOWN_AND_LEFT:
                break;
            default:
                break;
        }

        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, states.read(&states, 2));
        gpio_put(LED_1, states.read(&states, 1));
        gpio_put(LED_0, states.read(&states, 0));

        printf("Joystick:\n");
        printf("\tX: %d\n", joystick.xPosition);
        printf("\tY: %d\n", joystick.yPosition);
        printf("Leds: ");
        for (int i = 7; i >= 0; i--) {
            printf("%d", states.read(&states, i));
        }
        printf("\n");

        sleep_ms(100);
    }
}

void picoInit() {
    // Pico inits
    stdio_init_all();
    adc_init();

    // LED on board
    int rc = cyw43_arch_init();
    hard_assert(rc == PICO_OK);
}
