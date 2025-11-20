#ifndef ADC_H
#define ADC_H
#include <Arduino.h>
#include <stdint.h>

void adc_init(uint8_t resolution);

uint16_t adc_read(uint8_t pin);


uint8_t adc_read_percent(uint8_t pin);

#endif 