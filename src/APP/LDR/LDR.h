#ifndef LDR_H
#define LDR_H

#include <stdint.h>


typedef struct {
    uint16_t adc_channel;     
    uint16_t adc_dark;       
    uint16_t adc_bright;     
} LDR_Config_t;

extern LDR_Config_t ldr_cfg;

void LDR_Init(void);

uint16_t LDR_ReadRaw(void);


uint16_t LDR_ReadPercent(void);

#endif 
