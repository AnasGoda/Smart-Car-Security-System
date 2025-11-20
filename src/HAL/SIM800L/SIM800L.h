// ========================================
// File: SIM800L.h
// ========================================
#ifndef SIM800L_H
#define SIM800L_H

#include <Arduino.h>
#include <HardwareSerial.h>

// تعريف الـ Pins
#define SIM800L_RX_PIN 16
#define SIM800L_TX_PIN 17
#define SIM800L_BAUD_RATE 115200

// Return status
typedef enum {
    SIM800L_OK = 0,
    SIM800L_ERROR
} SIM800L_Status_t;

// Signal Quality
typedef enum {
    SIGNAL_POOR = 0,
    SIGNAL_WEAK,
    SIGNAL_GOOD,
    SIGNAL_EXCELLENT
} SignalQuality_t;

// دوال التهيئة
void SIM800L_init(uint8_t rxPin = SIM800L_RX_PIN, uint8_t txPin = SIM800L_TX_PIN);

// دوال فحص الحالة
bool SIM800L_checkSIM();
SignalQuality_t SIM800L_getSignalQuality();
int SIM800L_getSignalRSSI();

// دوال إرسال واستقبال
SIM800L_Status_t SIM800L_sendSMS(const String& phoneNumber, const String& message);
String SIM800L_sendATCommand(const String& command, uint16_t timeout);

// دوال مساعدة
void SIM800L_printResponse();
bool SIM800L_waitForResponse(const String& expected, uint16_t timeout);

#endif // SIM800L_H