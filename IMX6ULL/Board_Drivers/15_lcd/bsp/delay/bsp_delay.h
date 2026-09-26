#ifndef __BSP_DELAY_H
#define __BSP_DELAY_H

#include "imx6u.h"
#include "bsp_int.h"
#include "bsp_led.h"

void delay_short(volatile unsigned int n);
void delay(volatile unsigned int n);
// void GPT1_Handler(unsigned int giccia, void * Param);
void GPT1_Enable();
void delay_us(uint32_t us);
void delay_ms(uint32_t ms);
void delay_Init(void);
#endif // !__BSP_DELAY_H
