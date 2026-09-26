#ifndef __BSP_UART_H
#define __BSP_UART_H

#include "imx6u.h"
#include "bsp_gpio.h"
#include "stdio.h"

void UART1_Disable(void);
void UART1_Enable(void);
void UART1_Reset(void);
void UART1_IO_Init(void);
void UART1_Init(void);
void UART1_Clock_Init(void);
void UART1_SendByte(uint8_t c);
uint8_t UART1_ReceiveByte(void);
void UART1_SendString(char *Array);
void uart_setbaudrate(UART_Type *base, unsigned int baudrate, unsigned int srcclock_hz);
#endif // !__BSP_UART_H