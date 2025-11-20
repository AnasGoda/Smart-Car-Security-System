// ========================================
// File: SIM800L.cpp
// ========================================
#include "SIM800L.h"

// متغير Serial خاص بالـ SIM800L
static HardwareSerial* sim800 = nullptr;

// ========================================
// تهيئة المودول
// ========================================
void SIM800L_init(uint8_t rxPin, uint8_t txPin) {
    // إنشاء كائن Serial
    sim800 = new HardwareSerial(1);
    
    // بدء Serial
    sim800->begin(SIM800L_BAUD_RATE, SERIAL_8N1, rxPin, txPin);
    delay(3000);
    
    Serial.println("Initializing SIM800L module...");
    
    // إرسال أوامر التهيئة
    SIM800L_sendATCommand("AT", 1000);              // فحص الاتصال
    SIM800L_sendATCommand("ATE0", 1000);            // إيقاف Echo
    SIM800L_sendATCommand("AT+CMGF=1", 1000);       // وضع Text Mode
    SIM800L_sendATCommand("AT+CNMI=1,2,0,0,0", 1000); // إعدادات SMS
    
    Serial.println("✓ SIM800L initialized!");
}

// ========================================
// فحص وجود شريحة SIM
// ========================================
bool SIM800L_checkSIM() {
    if (!sim800) return false;
    
    String response = SIM800L_sendATCommand("AT+CPIN?", 2000);
    
    if (response.indexOf("READY") != -1) {
        Serial.println("✓ SIM card is ready!");
        return true;
    } else if (response.indexOf("SIM PIN") != -1) {
        Serial.println("✗ SIM card requires PIN");
        return false;
    } else {
        Serial.println("✗ SIM card not detected");
        return false;
    }
}

// ========================================
// الحصول على قيمة RSSI
// ========================================
int SIM800L_getSignalRSSI() {
    if (!sim800) return -1;
    
    String response = SIM800L_sendATCommand("AT+CSQ", 1000);
    
    int startIdx = response.indexOf("+CSQ: ");
    if (startIdx != -1) {
        int commaIdx = response.indexOf(",", startIdx);
        String rssi = response.substring(startIdx + 6, commaIdx);
        return rssi.toInt();
    }
    
    return -1;
}

// ========================================
// الحصول على جودة الإشارة
// ========================================
SignalQuality_t SIM800L_getSignalQuality() {
    int rssi = SIM800L_getSignalRSSI();
    
    Serial.print("Signal RSSI: ");
    Serial.print(rssi);
    
    if (rssi >= 20 && rssi <= 31) {
        Serial.println(" (Excellent)");
        return SIGNAL_EXCELLENT;
    } else if (rssi >= 10 && rssi < 20) {
        Serial.println(" (Good)");
        return SIGNAL_GOOD;
    } else if (rssi >= 5 && rssi < 10) {
        Serial.println(" (Weak)");
        return SIGNAL_WEAK;
    } else {
        Serial.println(" (Poor)");
        return SIGNAL_POOR;
    }
}

// ========================================
// إرسال رسالة SMS
// ========================================
SIM800L_Status_t SIM800L_sendSMS(const String& phoneNumber, const String& message) {
    if (!sim800) return SIM800L_ERROR;
    
    Serial.println("Sending SMS to: " + phoneNumber);
    
    // بدء إرسال الرسالة
    sim800->print("AT+CMGS=\"");
    sim800->print(phoneNumber);
    sim800->println("\"");
    delay(1000);
    
    // إرسال محتوى الرسالة
    sim800->print(message);
    delay(500);
    
    // إرسال Ctrl+Z (ASCII 26)
    sim800->write(26);
    
    // انتظار الرد
    String response = "";
    unsigned long startTime = millis();
    
    while (millis() - startTime < 10000) {
        while (sim800->available()) {
            char c = sim800->read();
            response += c;
            Serial.write(c);
        }
        
        if (response.indexOf("OK") != -1 || response.indexOf("+CMGS") != -1) {
            Serial.println("\n✓ SMS sent successfully!");
            return SIM800L_OK;
        }
        
        if (response.indexOf("ERROR") != -1) {
            Serial.println("\n✗ SMS sending failed!");
            return SIM800L_ERROR;
        }
    }
    
    Serial.println("\n✗ SMS timeout!");
    return SIM800L_ERROR;
}

// ========================================
// إرسال أمر AT
// ========================================
String SIM800L_sendATCommand(const String& command, uint16_t timeout) {
    if (!sim800) return "";
    
    String response = "";
    
    Serial.println(">>> " + command);
    
    sim800->println(command);
    
    unsigned long startTime = millis();
    while (millis() - startTime < timeout) {
        while (sim800->available()) {
            char c = sim800->read();
            response += c;
        }
        
        if (response.indexOf("OK") != -1 || response.indexOf("ERROR") != -1) {
            break;
        }
    }
    
    Serial.println("<<< " + response);
    return response;
}

// ========================================
// طباعة جميع الردود من المودول
// ========================================
void SIM800L_printResponse() {
    if (!sim800) return;
    
    while (sim800->available()) {
        Serial.write(sim800->read());
    }
}

// ========================================
// انتظار رد معين
// ========================================
bool SIM800L_waitForResponse(const String& expected, uint16_t timeout) {
    if (!sim800) return false;
    
    String response = "";
    unsigned long startTime = millis();
    
    while (millis() - startTime < timeout) {
        while (sim800->available()) {
            response += (char)sim800->read();
        }
        
        if (response.indexOf(expected) != -1) {
            return true;
        }
    }
    
    return false;
}
