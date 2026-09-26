#ifndef __BSP_EPIT_H
#define __BSP_EPIT_H

#include "imx6u.h"
#include "bsp_int.h"
#include "bsp_led.h"

typedef struct 
{
    uint8_t EPIT_ENMODE;
    uint8_t EPIT_Compare_Interrput;
    uint8_t EPIT_Reload_Control;
    uint16_t EPIT_Prescaler;
    uint32_t EPIT_Load_Value;
    uint8_t EPIT_Clock_Source;
    uint32_t EPIT_Compare_Value;
}EPIT_Init_t;

void EPIT1_Init(EPIT_Init_t *EPIT_InitStructure);
void EPIT1_Enable(void);
void EPIT1_irqhandler(unsigned int gicciar, void *param);

#endif 
