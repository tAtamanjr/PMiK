//
// Oleksandr "tAtaman" Bolbat
// PMiK project
//

#ifndef DEFINES_DISPLAY_H
#define DEFINES_DISPLAY_H


#define COLOR_T uint16_t

#define DISPLAY_SIZE_Y  160
#define DISPLAY_SIZE_X  128
#define OFFSET_X        2
#define OFFSET_Y        1

#define DELAY_MS    1

#define SEND_COMMAND    0
#define SEND_DATA       1

#define SWRESET 0b00000001
#define SLPOUT  0b00010001
#define DISPON  0b00101001
#define INVON   0b00100001
#define COLMOD  0b00111010
#define FRMCTR1 0b10110001

#define RAMWR   0b00101100
#define CASET   0b00101010
#define RASET   0b00101011

#define SELECT_DISPLAY      gpio_put(GPIO_CS, 0)
#define DESELECT_DISPLAY    gpio_put(GPIO_CS, 1)




#endif
