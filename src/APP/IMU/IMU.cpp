#include <Adafruit_MPU6050.h>
#include "IMU.h"
#include "../../HAL/UART/UART.h"
#include <Wire.h>

#if IMU_DEBUG == STD_ON
#define DEBUG_PRINTLN(VAR) Serial.println(VAR)
#define DEBUG_PRINT(VAR) Serial.print(VAR)
#else
#define DEBUG_PRINTLN(VAR) 
#define DEBUG_PRINT(VAR) 
#endif

#if IMU_ENABLED == STD_ON
static Adafruit_MPU6050 mpu;
static sensors_event_t accele, gyro, temp;
#endif


void IMU_init(void)
{
#if IMU_ENABLED == STD_ON
    UARTmsg_t msg;
    while (!Serial) delay(10);

    if (!mpu.begin()) {
        msg.uart_num = UART0;
        msg.transmited_payload = "Failed to find MPU6050 chip";
        UART_writeMsg(msg);
    }
    else
    {
        mpu.setAccelerometerRange(MPU6050_RANGE_16_G);
        mpu.setGyroRange(MPU6050_RANGE_250_DEG);
        mpu.setFilterBandwidth(MPU6050_BAND_260_HZ);
    
        DEBUG_PRINTLN("");
        // delay(100);
    }
#endif
}


void IMU_updateValue(void)
{
#if IMU_ENABLED == STD_ON
    mpu.getEvent(&accele, &gyro, &temp);
#if IMU_DEBUG == STD_ON
   // TELEPLOT FORMAT
    DEBUG_PRINT(">AccelX:");
    DEBUG_PRINTLN(accele.acceleration.x);
    
    DEBUG_PRINT(">AccelY:");
    DEBUG_PRINTLN(accele.acceleration.y);
    
    DEBUG_PRINT(">AccelZ:");
    DEBUG_PRINTLN(accele.acceleration.z);
    
    DEBUG_PRINT(">GyroX:");
    DEBUG_PRINTLN(gyro.gyro.x);
    
    DEBUG_PRINT(">GyroY:");
    DEBUG_PRINTLN(gyro.gyro.y);
    
    DEBUG_PRINT(">GyroZ:");
    DEBUG_PRINTLN(gyro.gyro.z);
    
    DEBUG_PRINT(">TempC:");
    DEBUG_PRINTLN(temp.temperature);
//    delay(20);
#endif
#endif
}

sensors_event_t IMU_getAccMeasur(void)
{
#if IMU_ENABLED == STD_ON
    return accele;
#endif
}

sensors_event_t IMU_getGyroMeasur(void)
{
#if IMU_ENABLED == STD_ON
    return gyro;
#endif
}

sensors_event_t IMU_getTempMeasur(void)
{
#if IMU_ENABLED == STD_ON
    return temp;
#endif
}
