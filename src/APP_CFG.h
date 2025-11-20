#ifndef APP_CFG_H
#define APP_CFG_H

// General Definitions
#define STD_ON  1
#define STD_OFF 0
#define Wi_Fi    1
#define BLE     2
#define _4G     3

// General Constants
#define POT_RESOLUTION                   12
#define LM35_RESOLUTION                  12
#define MAX_TEMP_RANGE                   150
#define LED_LOW_THREWSHOLD_PECENTAGE     30.0
#define LED_HIGH_THREWSHOLD_PECENTAGE    80.0
#define BLYNK_STREAM_TIME                10UL


#define WIFI_SSID                        "Inspiron"
#define WIFI_PASSWORD                    "12345ASDF"

#define WIFI_RETRY_INTERVAL_MS 3000
#define WIFI_MAX_RETRIES       3
#define WIFI_MAX_INPUT 64

// LDR configurations
#define  ADC_DARK       250
#define  ADC_BRIGHT     3150


// Ultrasound configurations
#define ultra_MAX_DISTANCE_CM          400
#define ultra_TIMEOUT_US             50000 


// Module Status(enable/disable)
#define GPIO_ENABLED            STD_ON
#define COMMUINCATION_MODULE    Wi_Fi
#define WIFI_ENABLED            STD_OFF
#define UART_ENABLED            STD_ON
#define PWM_ENABLED             STD_OFF
#define SENSORH_ENABLED         STD_ON
#define POT_ENABLED             STD_ON
#define LM35_ENABLED            STD_ON
#define DIMER_ENABLED           STD_OFF
#define ChatApp_ENABLED         STD_OFF
#define ultra_ENABLED           STD_ON
#define IMU_ENABLED             STD_ON

// Debug Status (enable/disable)
#define GPIO_DEBUG              STD_OFF
#define UART_DEBUG              STD_OFF
#define WIFI_DEBUG              STD_OFF
#define PWM_DEBUG               STD_OFF
#define ADC_DEBUG               STD_ON
#define LDR_DEBUG               STD_ON
#define SENSORH_DEBUG           STD_OFF
#define POT_DEBUG               STD_OFF
#define LM35_DEBUG              STD_OFF
#define DIMER_DEBUG             STD_OFF
#define ChatApp_DEBUG           STD_OFF
#define ultra_DEBUG             STD_ON
#define IMU_DEBUG               STD_ON
#define SEND_MSG_DEBUG          STD_ON


//Pin Configuration
#define SENSORH_PIN         0
#define LM35_PIN            4
#define IMU_SCL_PIN         22
#define IMU_SDA_PIN         21
#define LDR_ADC_PIN         34
#define ultra_TRIGGER_PIN   14
#define ultra_ECHO_PIN      12
#define SIM800L_RX_PIN       16
#define SIM800L_TX_PIN       17
#define SIM800L_BAUD_RATE 115200

// UART CONFIGS
#define UART0_BAUD_RATE 115200
#define UART0_TX_PIN    1
#define UART0_RX_PIN    3
#define UART0_FRAME_CFG SERIAL_8N1

#define UART2_BAUD_RATE 115200
#define UART2_TX_PIN    17
#define UART2_RX_PIN    16
#define UART2_FRAME_CFG SERIAL_8N1
// Blyink configuratoins
#define BLYNK_TEMPLATE_ID           "TMPL24plAGa53"
#define BLYNK_TEMPLATE_NAME         "ESP32-NTI"
#define BLYNK_AUTH_TOKEN            "B8JaK3Ri5Jv5Y_W8iOoCYJjHYE6HQDeu"



#endif //APP_CFG_H