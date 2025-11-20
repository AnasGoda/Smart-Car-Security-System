#include <Arduino.h>
#include <math.h>
#include "../../APP_CFG.h"
#include "../../HAL/SensorH/SensorH.h"
#include "LM35.h"



#if LM35_DEBUG == STD_ON
#define DEBUG_PRINTLN(var) Serial.println(var)
#define DEBUG_PRINT(var) Serial.print(var)
#else
#define DEBUG_PRINTLN(var)
#define DEBUG_PRINT(var)
#endif



static SensorH_t config = {.channel=LM35_PIN, 
                           .resolution=LM35_RESOLUTION};
static double temp = 0.0;


void LM35_init(void)
{
#if LM35_ENABLED==STD_ON
    sensorH_init(config);
#endif
}


void LM35_update(void)
{
#if LM35_ENABLED==STD_ON
    uint16_t lm35_value = sensorH_readValue(config.channel);
    double stepSize = 5.0 / (pow(2, config.resolution) - 1);
    temp = lm35_value * stepSize*MAX_TEMP_RANGE; // LM35 gives 10mV per degree Celsius
    DEBUG_PRINT("Calculated Temperature (C): ");DEBUG_PRINTLN(temp);
    DEBUG_PRINT("LM35 Value: ");DEBUG_PRINTLN(lm35_value);
    // delay(1000);
#endif
}


void LM35_getTemp(double& temperature)
{
#if LM35_ENABLED==STD_ON
    temperature = temp;
#endif
}