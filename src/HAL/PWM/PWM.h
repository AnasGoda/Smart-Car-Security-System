#ifndef PWM_H
#define PWM_H
#include <stdint.h>

typedef struct
{
    uint8_t  pin;
    uint8_t  channel;
    uint8_t  resolution;
    uint8_t  attenuation;
    float    dutyCyclePercentage;    
    uint32_t frequency;
}PWM_t;

void PWM_initChannel(PWM_t *channelConfig);

void PWM_setDutyCyclePrecentage(PWM_t *channelConfig);


#endif //PWM_H