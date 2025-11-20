#include <Arduino.h>
#include "LDR.h"
#include "../../HAL/ADC/ADC.h"
#include "../../APP_CFG.h"



#if LDR_DEBUG == STD_ON
#define DEBUG_PRINTLN(var) Serial.println(var)
#else
#define DEBUG_PRINTLN(var)
#endif

LDR_Config_t ldr_cfg;

void LDR_Init(void){

ldr_cfg.adc_channel = LDR_ADC_PIN;    
  ldr_cfg.adc_dark = ADC_DARK;  
  ldr_cfg.adc_bright = ADC_BRIGHT;

 }


uint16_t LDR_ReadRaw(void) {
    return adc_read(ldr_cfg.adc_channel);
}

uint16_t LDR_ReadPercent(void) {
    uint16_t raw = LDR_ReadRaw();

    
    if (raw < ldr_cfg.adc_dark)   raw = ldr_cfg.adc_dark;
    if (raw > ldr_cfg.adc_bright) raw = ldr_cfg.adc_bright;


    uint16_t percent = (raw - ldr_cfg.adc_dark) * 100;
    percent /= (ldr_cfg.adc_bright - ldr_cfg.adc_dark);

    return percent;
}
