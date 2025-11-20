#ifndef GPIO_H
#define GPIO_H
#include <stdint.h>

typedef struct
{
    uint8_t pin_num;
    uint8_t pin_mode;
    uint8_t pin_value;
}GPIO_t;

void GPIO_initPin(GPIO_t &pinConfig);

uint8_t GPIO_readPinValue(uint8_t pin_num);

void GPIO_writePinValue(GPIO_t &pinConfig);



#endif //GPIO_h