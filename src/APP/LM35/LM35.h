#ifndef LM35_H
#define LM35_H



void LM35_init(void);

void LM35_update(void);

void LM35_getTemp(double& temperature);


#endif // LM35_H