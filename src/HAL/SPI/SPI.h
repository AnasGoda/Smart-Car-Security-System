#ifndef SPI_H
#define SPI_H

#include <stdint.h>

// Initialize SPI
void spi_init(uint8_t cs_pin);

// Transfer data
uint8_t spi_transfer(uint8_t data);

// Write data
void spi_write(uint8_t data);

// Read data
uint8_t spi_read();

#endif