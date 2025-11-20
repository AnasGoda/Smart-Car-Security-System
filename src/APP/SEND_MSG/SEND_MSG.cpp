#include "APP_CFG.h"
#include <Arduino.h>
#include <WiFi.h>
#include "HAL/SIM800L/SIM800L.h"
#include "SEND_MSG.h"
#include "APP/IMU/IMU.h"


#if SEND_MSG_DEBUG == STD_ON
#define DEBUG_PRINTLN(var) Serial.println(var)
#define DEBUG_PRINT(var) Serial.print(var)
#else
#define DEBUG_PRINTLN(var) 
#define DEBUG_PRINT(var) 
#endif



void  SendWarningMessage(struct APP_DATA &data_meas)
{
    String sms_msg;
    bool temp_flag = 0, accel_flag = 0, light_flag = 0, distance_flag = 0;

    double accel_vec = sqrt(data_meas.accel_x_Data*data_meas.accel_x_Data + 
                            data_meas.accel_y_Data*data_meas.accel_y_Data + 
                            data_meas.accel_z_Data*data_meas.accel_z_Data );
    
    if ( WiFi.status() != WL_CONNECTED && data_meas.LM35_Data >= 70)
    {
        sms_msg.concat("إلحق الدنيا بتولع....\n");
        temp_flag= 1;
        DEBUG_PRINTLN(sms_msg);

    }
    if (WiFi.status() != WL_CONNECTED && accel_vec >= 15)
    
    {
        sms_msg.concat("إلحق العربيه بتتحرك لوحدها او بتنسرق!!!\n");
        accel_flag=1;
        DEBUG_PRINTLN(sms_msg);
    }
    
    if (WiFi.status() != WL_CONNECTED && data_meas.LDR_value_Data <= 250 )
    {
        sms_msg.concat("الدنيا ضلمة ....\n");
        light_flag=1;
        DEBUG_PRINTLN(sms_msg);
    }
    if (WiFi.status() != WL_CONNECTED && data_meas.ultra_sonic_Data < 50 )
    {
        sms_msg.concat( "إلحق هنعمل حادثة....\n");
        distance_flag=1;
        DEBUG_PRINTLN(sms_msg);
    }
    if (temp_flag || accel_flag || light_flag || distance_flag)
    {
        DEBUG_PRINTLN(sms_msg);
        SIM800L_sendSMS("+201015407032", sms_msg);
    }
}
