#include "Arduino.h"
#include "../../APP_CFG.h"

#include "ultra.h"


//Debug 
#if ultra_DEBUG == STD_ON
    #define DEBUG_PRINT(x)      Serial.print(x)
    #define DEBUG_PRINTLN(x)    Serial.println(x)
#else
    #define DEBUG_PRINT(x)
    #define DEBUG_PRINTLN(x)
#endif




static float s_last_distance = -1;


void ultra_init(void) {
    #if ultra_ENABLED == STD_ON
    
    DEBUG_PRINTLN("ultra: Initializing...");
    DEBUG_PRINT("Trigger Pin: ");
    DEBUG_PRINTLN(ultra_TRIGGER_PIN);
    DEBUG_PRINT("Echo Pin: ");
    DEBUG_PRINTLN(ultra_ECHO_PIN);
    
    pinMode(ultra_TRIGGER_PIN, OUTPUT);
    pinMode(ultra_ECHO_PIN, INPUT);
    
    digitalWrite(ultra_TRIGGER_PIN, LOW);
    
    DEBUG_PRINTLN("ultra: Initialization done");
    
    #endif
}

float ultra_measureDistance(void) {
    #if ultra_ENABLED == STD_ON
    
    unsigned long duration_us;
    float distance_cm;
    
    DEBUG_PRINTLN("ultra: Measuring...");
    
    //Send trigger pulse 
    digitalWrite(ultra_TRIGGER_PIN, LOW);
    delayMicroseconds(2);
    
    digitalWrite(ultra_TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(ultra_TRIGGER_PIN, LOW);
    
    // echo pulse duration 
    duration_us = pulseIn(ultra_ECHO_PIN, HIGH, ultra_TIMEOUT_US);
    
    DEBUG_PRINT("Duration (us): ");
    DEBUG_PRINTLN(duration_us);
    
    if (duration_us == 0) {
        DEBUG_PRINTLN("ultra: Timeout - No echo received");
        s_last_distance = -1;
        return -1;
    }
    
    //Calculate distance: duration/58 = cm 
    distance_cm = (float)duration_us / 58.0f;
    
    DEBUG_PRINT("Distance (cm): ");
    DEBUG_PRINTLN(distance_cm);
    
    //Check if valid 
    if (distance_cm == 0 || distance_cm > ultra_MAX_DISTANCE_CM) {
        DEBUG_PRINTLN("ultra: Out of range");
        s_last_distance = -1;
        return -1;
    } else {
        DEBUG_PRINTLN("ultra: OK");
        s_last_distance = distance_cm;
        return distance_cm;
    }
    
    #else
    return -1;
    #endif
}