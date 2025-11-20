#ifndef ultra_H
#define ultra_H

#include <stdint.h>


void ultra_init(void);

//return Distance in cm (integer), or -1 if out of range
float ultra_measureDistance(void);

#endif 