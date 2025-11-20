#ifndef I2C_H
#define I2C_H

#include <stdint.h>


void i2c_init(void);


void i2c_write(uint8_t device_addr, uint8_t reg_addr, uint8_t data);


uint8_t i2c_read(uint8_t device_addr, uint8_t reg_addr);

#endif