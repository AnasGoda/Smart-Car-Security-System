#include <Arduino.h>
#include "../../APP_CFG.h"
#include "GPIO.h"


#if GPIO_DEBUG == STD_ON
#define DEBUG_PRINTLN(VAR) Serial.println(VAR)
#define DEBUG_PRINT(VAR) Serial.print(VAR)
#else
#define DEBUG_PRINTLN(VAR) 
#define DEBUG_PRINT(VAR) 
#endif


void GPIO_initPin(GPIO_t &pinConfig)
{
#if GPIO_ENABLED == STD_ON
    pinMode(pinConfig.pin_num,pinConfig.pin_mode);
    DEBUG_PRINTLN("Initialized pin :" + String(pinConfig.pin_num) + "with mode" + String(pinConfig.pin_mode));
#endif
}

uint8_t GPIO_readPinValue(uint8_t pin_num)
{
#if GPIO_ENABLED == STD_ON
    uint8_t pin_value = digitalRead(pin_num);
    DEBUG_PRINTLN("Read pin value is :" + String(pin_value) + " from GPIO pin " + String(pin_num));
    return pin_value;
#else
    return 0;
#endif
}

void GPIO_writePinValue(GPIO_t &pinConfig)
{
#if GPIO_ENABLED == STD_ON
    digitalWrite(pinConfig.pin_num,pinConfig.pin_value);
    DEBUG_PRINTLN("Wrote pin value is :" + String(pinConfig.pin_value) + " from GPIO pin " + String(pinConfig.pin_num));
#endif
}