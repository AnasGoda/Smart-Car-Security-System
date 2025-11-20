#ifndef SENSORH_H
#define SENSORH_H
#include <Arduino.h>

#include <stdint.h>



typedef struct
{
    uint8_t channel;
    uint8_t resolution;
    adc_attenuation_t attenuation;
}SensorH_t;

void sensorH_init(SensorH_t& configurations);

uint32_t sensorH_readValue(uint8_t channel);




#endif // SENSORH_H