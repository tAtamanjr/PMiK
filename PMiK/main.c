//
// Oleksandr "tAtaman" Bolbat
// PMiK project
//

#ifndef THE_DATA_H
#include "TheData.h"
#endif

#ifndef LED_1
#define LED_1 15
#define LED_0 14
#endif


byte_t states;
ledOut_t ledOut;
joystick_t joystick;
display_t display;


void setUp();
void setUpADC();
void setUpSPI();
void startTimers();
void setIRQ();


int main() {
    setUp();

    initByte(&states);
    initLedOut(&ledOut);
    initJoystick(&joystick);
    initDisplay(&display);

    startTimers();
    setIRQ();

    // Sine fine loop
    while (true) {
        states.reset(&states);
        joystick.read(&joystick);

        switch (joystick.direction) {
            case NE:
                states.on(&states, 2);
                states.on(&states, 1);
                states.on(&states, 0);
                break;
            case N:
                states.on(&states, 2);
                states.on(&states, 1);
                break;
            case NW:
                states.on(&states, 2);
                states.on(&states, 0);
                break;
            case E:
                states.on(&states, 2);
                break;
            case W:
                states.on(&states, 1);
                states.on(&states, 0);
                break;
            case SE:
                states.on(&states, 1);
                break;
            case S:
                states.on(&states, 0);
                break;
            case SW:
                break;
            default:
                break;
        }

        ledOut.set(states.read(&states, 2));
        gpio_put(LED_1, states.read(&states, 1));
        gpio_put(LED_0, states.read(&states, 0));
    }
}

void setUp() {
    stdio_init_all();
    setUpADC();
    setUpSPI();

    gpio_init(LED_1);
    gpio_set_dir(LED_1, GPIO_OUT);
    gpio_init(LED_0);
    gpio_set_dir(LED_0, GPIO_OUT);
}


void setUpADC() {
    adc_init();

    adc_gpio_init(JOYSTICK_GPIO_X);
    adc_gpio_init(JOYSTICK_GPIO_Y);

    gpio_init(JOYSTICK_GPIO_SW);
}


void setUpSPI() {
    spi_init(spi_default, 100 M);
    gpio_set_function(GPIO_SCK, GPIO_FUNC_SPI);
    gpio_set_function(GPIO_SDA, GPIO_FUNC_SPI);

    gpio_init(GPIO_CS);
    gpio_init(GPIO_DC);
    gpio_init(GPIO_LED);
    gpio_init(GPIO_RESET);
    
    gpio_set_dir(GPIO_CS, GPIO_OUT);
    gpio_set_dir(GPIO_DC, GPIO_OUT);
    gpio_set_dir(GPIO_LED, GPIO_OUT);
    gpio_set_dir(GPIO_RESET, GPIO_OUT);
    
    gpio_put(GPIO_CS, 1);
    gpio_put(GPIO_DC, 1);
    gpio_put(GPIO_LED, 1);
    gpio_put(GPIO_RESET, 1);
}

void startTimers() {
    struct repeating_timer timer;
    add_repeating_timer_ms(250, joystickDataCallback, NULL, &timer);
}

void setIRQ() {
    gpio_set_irq_enabled_with_callback(JOYSTICK_GPIO_SW, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL, true, &joystickSwitchCallback);
}