#ifndef UART_H
#define UART_H

#include <stdint.h>

typedef enum
{
    UART0=0,
    UART2=2,
    MAX_LENGTH=2
}UARTn_t;


typedef struct 
{
    uint8_t Tx;
    uint8_t Rx;
    uint32_t frame_cfg;
    uint32_t baud_rate;
}UART_t;

typedef struct 
{
    UARTn_t uart_num;
    String recieved_payload;
    const char* transmited_payload;
}UARTmsg_t;


void UART_init(void);

void UART_readMsg(UARTmsg_t& msg);

void UART_writeMsg(UARTmsg_t& msg);

#endif //UART_H