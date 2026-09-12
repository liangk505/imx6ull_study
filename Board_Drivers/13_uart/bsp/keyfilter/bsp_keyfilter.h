#ifndef __BSP_KEYFILTER_H
#define __BSP_KEYFILTER_H

#include "imx6u.h"
#include "bsp_key.h"
#include "bsp_exti.h"
#include "bsp_epit.h"
#include "bsp_beep.h"
void Keyfilter_Epit_Init(void);
void EPIT1_irqhandler(unsigned int gicciar, void *param);
void GPIO1_16_31_IRQHandler(unsigned int gicciar, void *Param);
void Keyfilter_Init(void);
void Keyfilter_Epit_Reset(uint32_t value);

#endif 
