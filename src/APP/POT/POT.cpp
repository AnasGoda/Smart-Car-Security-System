#include <Arduino.h>
#include <stdint.h>

#include "../../APP_CFG.h"
#include "../../HAL/SensorH/SensorH.h"
#include "POT.h"


#if POT_DEBUG == STD_ON
#define DEBUG_PRINTLN(var) Serial.println(var)
#define DEBUG_PRINT(var) Serial.print(var)
#else
#define DEBUG_PRINTLN(var) 
#define DEBUG_PRINT(var) 
#endif


static SensorH_t POT_config = {.channel=SENSORH_PIN, .resolution=POT_RESOLUTION};

static uint32_t pot_value = 0;




void POT_init(void)
{
#if POT_ENABLED==STD_ON
    sensorH_init(POT_config);
#endif
}



void POT_update(void)
{
#if POT_ENABLED==STD_ON
    pot_value = sensorH_readValue(POT_config.channel);
    DEBUG_PRINT("POT Value: ");DEBUG_PRINTLN(pot_value);
    // delay(1000);
#endif
}

uint16_t POT_getValue(void)
{
#if POT_ENABLED==STD_ON
    return pot_value;
#else
    return -1;
#endif
}




