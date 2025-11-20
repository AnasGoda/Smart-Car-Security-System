#include "APP_CFG.h"
#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include "HAL/SIM800L/SIM800L.h"
#include "HAL/GPIO/GPIO.h"
#include "APP/LDR/LDR.h"
#include "APP/LM35/LM35.h"
#include "APP/IMU/IMU.h"
#include "APP/BLYNK/BlynkApp.h"
#include "APP/ULTRASOUND/ultra.h"
#include <BlynkSimpleEsp32.h>
#include "APP/SEND_MSG/SEND_MSG.h"



void BLYNK_MAIN (void);

static struct APP_DATA DATA;

static bool activate_systems=0;
static GPIO_t blinking_led= {.pin_num = 2, .pin_mode=OUTPUT,.pin_value=0};



char SSID[]    = "POCO M3";
char PASWORD[] = "123456789";

BlynkTimer timer;

void setup(void)
{
  Serial.begin(UART0_BAUD_RATE);
  Blynk.begin(BLYNK_AUTH_TOKEN, SSID, PASWORD);
  SIM800L_init();
  
  GPIO_initPin(blinking_led);
  LDR_Init();
  LM35_init();
  IMU_init();
  timer.setInterval(BLYNK_STREAM_TIME, BLYNK_MAIN);
}

void loop()
{
  Blynk.run();
  timer.run();
}

BLYNK_WRITE(V5)
{
  activate_systems =param.asInt();
}

BLYNK_WRITE(V1)
{
  blinking_led.pin_value=param.asInt();
  GPIO_writePinValue(blinking_led);
}

void BLYNK_MAIN (void)
{
  if (activate_systems)
  {
    DATA.LDR_value_Data = LDR_ReadRaw();
    
    IMU_updateValue();
    
    sensors_event_t imu_accel_values = IMU_getAccMeasur();
    
    DATA.accel_x_Data = imu_accel_values.acceleration.x;
    DATA.accel_y_Data = imu_accel_values.acceleration.y;
    DATA.accel_z_Data = imu_accel_values.acceleration.z;
    
    
    sensors_event_t imu_gyro_values = IMU_getGyroMeasur();
    
    DATA.gyro_x_Data = imu_gyro_values.gyro.x;
    DATA.gyro_y_Data = imu_gyro_values.gyro.y;
    DATA.gyro_z_Data = imu_gyro_values.gyro.z;
    
    
    sensors_event_t imu_tempr_valurs =  IMU_getTempMeasur();
    
    DATA.imu_tempr_Data = imu_tempr_valurs.temperature;
    
    DATA.ultra_sonic_Data = ultra_measureDistance();
    LM35_update();
    LM35_getTemp(DATA.LM35_Data);

    // Sending a warring messages in case of fire, moving the car, someone approtches, or no light
    SendWarningMessage(DATA);

    Blynk.virtualWrite(V0,DATA.LM35_Data);
    Blynk.virtualWrite(V2,DATA.LDR_value_Data);
    Blynk.virtualWrite(V3,DATA.accel_x_Data);
    Blynk.virtualWrite(V4,DATA.gyro_x_Data);
    Blynk.virtualWrite(V7,DATA.ultra_sonic_Data);

  }
}



