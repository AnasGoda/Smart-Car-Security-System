// #include <Arduino.h>
// #include "../../APP_CFG.h"
// #include "PWM.h"

// #if PWM_DEBUG == STD_ON
// #define DEBUG_PRINTLN(VAR) Serial.println(VAR)
// #define DEBUG_PRINT(VAR) Serial.print(VAR)
// #else
// #define DEBUG_PRINTLN(VAR) 
// #define DEBUG_PRINT(VAR) 
// #endif


// void PWM_initChannel(PWM_t *channelConfig)
// {
// #if PWM_ENABLED == STD_ON    
//     DEBUG_PRINTLN("Initializing PWM Channel" + String(channelConfig->channel));
//     ledcSetup(channelConfig->channel,channelConfig->frequency ,channelConfig->resolution);
//     DEBUG_PRINTLN("Channel = " + String(channelConfig->channel) + " is at Freq = " + String(channelConfig->frequency) + " and Resolution = " + String(channelConfig->resolution));
//     ledcAttachPin(channelConfig->pin,channelConfig->channel);
//     DEBUG_PRINTLN("Channel = " + String(channelConfig->channel) + " is attached to pin = " + String(channelConfig->pin));
// #endif
// }


// void PWM_setDutyCyclePrecentage(PWM_t *channelConfig)
// {
// #if PWM_ENABLED == STD_ON    
//     if(channelConfig->dutyCyclePercentage < 0.0)
//     {
//         channelConfig->dutyCyclePercentage = 0.0;
//     }
//     else if (channelConfig->dutyCyclePercentage > 100.0)
//     {
//         channelConfig->dutyCyclePercentage = 100.0;
//     }

//     DEBUG_PRINTLN("Setting duty cycle for  Channel = " + String(channelConfig->channel));
//     uint32_t dutyCycle= (channelConfig->dutyCyclePercentage / 100.0) * ((1<<channelConfig->resolution) - 1);
//     ledcWrite(channelConfig->channel, dutyCycle);
//     DEBUG_PRINTLN("Duty Cycle Set to: " + String(channelConfig->dutyCyclePercentage) + "%");
// #endif
// }