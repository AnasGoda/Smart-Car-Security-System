#include<Arduino.h>
#include <Wire.h>

#include "I2C.h"


void i2c_init(void) {
    Wire.begin();
}


uint8_t i2c_read(uint8_t addr, uint8_t reg) {
    Wire.beginTransmission(addr);
    Wire.write(reg);
    Wire.endTransmission(false); 

    Wire.requestFrom(addr, (uint8_t)1);
    return Wire.read();
}


void i2c_write(uint8_t addr, uint8_t reg, uint8_t data) {
    Wire.beginTransmission(addr);
    Wire.write(reg);
    Wire.write(data);
    Wire.endTransmission();
}
