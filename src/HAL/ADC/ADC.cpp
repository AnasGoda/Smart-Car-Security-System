
#include <Arduino.h>
#include "ADC.h"

static uint16_t adc_max_value = 4095; 


void adc_init(uint8_t resolution) {
    if (resolution < 9) resolution = 9;
    if (resolution > 12) resolution = 12;
    
    analogReadResolution(resolution);
    analogSetAttenuation(ADC_11db);
    
    
    adc_max_value = (1 << resolution) - 1;
}


uint16_t adc_read(uint8_t pin) {
    return (uint16_t)analogRead(pin);
}

uint8_t adc_read_percent(uint8_t pin) {
    uint16_t value = adc_read(pin);
    return (uint8_t)((value * 100UL) / adc_max_value);
}