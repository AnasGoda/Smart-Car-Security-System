#include <Arduino.h>
#include "../../APP_CFG.h"
#include "SensorH.h"

#if SENSORH_DEBUG == STD_ON
#define DEBUG_PRINTLN(VAR) Serial.println(VAR)
#define DEBUG_PRINT(VAR) Serial.print(VAR)
#else
#define DEBUG_PRINTLN(VAR) 
#define DEBUG_PRINT(VAR) 
#endif

void sensorH_init(SensorH_t& configurations)
{
#if SENSORH_ENABLED == STD_ON
    DEBUG_PRINTLN("SensorH Initialized");
    DEBUG_PRINTLN("Sensor Channel is : " + String(configurations.channel));
    DEBUG_PRINTLN("Sensor ADC Resolution is : " + String(configurations.resolution));
    analogReadResolution(configurations.resolution);
    DEBUG_PRINTLN("Sensor ADC Attenuation is : " + String(configurations.attenuation));
    analogSetPinAttenuation(configurations.channel ,configurations.attenuation);
#endif
}

uint32_t sensorH_readValue(uint8_t channel)
{
#if SENSORH_ENABLED == STD_ON
    uint32_t sensorValue = analogRead(channel);
    DEBUG_PRINTLN("Read sensor value from channel " + String(channel) + "and the Value is: " + String(sensorValue));
    return sensorValue;
#else
    return -1;
#endif
}