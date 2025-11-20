#ifndef IMU_H
#define IMU_H

#include <Adafruit_Sensor.h>


struct APP_DATA
{
    uint16_t LDR_value_Data;
    double LM35_Data;
    double accel_x_Data;
    double accel_y_Data;
    double accel_z_Data;
    double gyro_x_Data; 
    double gyro_y_Data; 
    double gyro_z_Data; 
    double imu_tempr_Data;
    float ultra_sonic_Data;
};

void IMU_init(void);

void IMU_updateValue(void);

sensors_event_t IMU_getAccMeasur(void);

sensors_event_t IMU_getGyroMeasur(void);

sensors_event_t IMU_getTempMeasur(void);




#endif //IMU_H