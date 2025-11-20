#include <Arduino.h>
#include "../../APP_CFG.h"
#include "UART.h"

#if UART_DEBUG == STD_ON
#define DEBUG_PRINTLN(VAR) Serial.println(VAR)
#define DEBUG_PRINT(VAR) Serial.print(VAR)
#else
#define DEBUG_PRINTLN(VAR) 
#define DEBUG_PRINT(VAR) 
#endif

static UART_t uart[MAX_LENGTH] = {
    {.Tx=UART0_TX_PIN,.Rx=UART0_RX_PIN,.frame_cfg=UART0_FRAME_CFG,.baud_rate=UART0_BAUD_RATE},
    {.Tx=UART2_TX_PIN,.Rx=UART2_RX_PIN,.frame_cfg=UART2_FRAME_CFG,.baud_rate=UART2_BAUD_RATE}
};

static HardwareSerial mySerials[MAX_LENGTH] = {{Serial},{Serial2}};

void UART_init(void)
{
#if UART_ENABLED == STD_ON
    for(uint8_t i=0; i<MAX_LENGTH; i++)
    {
        mySerials[i].begin(uart[i].baud_rate,uart[i].frame_cfg,uart[i].Rx,uart[i].Tx);
        DEBUG_PRINTLN("UART " + String(i) + " is Initialized with baudrate = " + String(uart[i].baud_rate));
    }
#endif
}

void UART_readMsg(UARTmsg_t& msg)
{
#if UART_ENABLED == STD_ON
    if(mySerials[msg.uart_num].available())
    {
        msg.recieved_payload = mySerials[msg.uart_num].readStringUntil('\n');
        DEBUG_PRINTLN("Recieved Payload is : " + msg.recieved_payload);
    }
#endif
}

void UART_writeMsg(UARTmsg_t& msg)
{
#if UART_ENABLED == STD_ON
    mySerials[msg.uart_num].println(msg.transmited_payload);
    DEBUG_PRINTLN("Sent payload is :" + String(msg.transmited_payload));
#endif
}
