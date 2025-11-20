// #include "APP_CFG.h"
// #include <Arduino.h>
// #include <WiFi.h>
// #include <WiFiClient.h>

// #include <BlynkSimpleEsp32.h>
// #include "APP/BLYNK/BlynkApp.h"
// #include "APP/LDR/LDR.h"
// #include "APP/LM35/LM35.h"
// #include "APP/IMU/IMU.h"

// struct APP_DATA
// {
//     uint16_t LDR_value_Data;
//     double LM35_Data;
//     double accel_x_Data;
//     double accel_y_Data;
//     double accel_z_Data;
//     double gyro_x_Data; 
//     double gyro_y_Data; 
//     double gyro_z_Data; 
//     double imu_tempr_Data;

// }DATA;

// void BLYNK_MAIN (void)
// {
//     DATA.LDR_value_Data = LDR_ReadRaw();
//     IMU_updateValue();

//     sensors_event_t imu_accel_values = IMU_getAccMeasur();

//     DATA.accel_x_Data = imu_accel_values.acceleration.x;
//     DATA.accel_y_Data = imu_accel_values.acceleration.y;
//     DATA.accel_z_Data = imu_accel_values.acceleration.z;
    
//     sensors_event_t imu_gyro_values = IMU_getGyroMeasur();

//     DATA.gyro_x_Data = imu_gyro_values.gyro.x;
//     DATA.gyro_y_Data = imu_gyro_values.gyro.y;
//     DATA.gyro_z_Data = imu_gyro_values.gyro.z;

//     sensors_event_t imu_tempr_valurs =  IMU_getTempMeasur();

//     DATA.imu_tempr_Data = imu_tempr_valurs.temperature;

//     LM35_update();
//     LM35_getTemp(DATA.LM35_Data);
//     Blynk.virtualWrite(V0,DATA.LM35_Data);
// }