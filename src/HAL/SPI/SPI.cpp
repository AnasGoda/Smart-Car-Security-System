
#include<Arduino.h>
#include <SPI.h>
#include "SPI.h"

static uint8_t cs_pin;

void spi_init(uint8_t cs) {
    cs_pin = cs;
    pinMode(cs_pin, OUTPUT);
    digitalWrite(cs_pin, HIGH);
    SPI.begin();
}

uint8_t spi_transfer(uint8_t data) {
    digitalWrite(cs_pin, LOW);
    uint8_t result = SPI.transfer(data);
    digitalWrite(cs_pin, HIGH);
    return result;
}

void spi_write(uint8_t data) {
    digitalWrite(cs_pin, LOW);
    SPI.transfer(data);
    digitalWrite(cs_pin, HIGH);
}

uint8_t spi_read() {
    digitalWrite(cs_pin, LOW);
    uint8_t data = SPI.transfer(0x00);
    digitalWrite(cs_pin, HIGH);
    return data;
}
