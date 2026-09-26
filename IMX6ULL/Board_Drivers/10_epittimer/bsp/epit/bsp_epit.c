#include "bsp_epit.h"
/*EPIT初始化*/
void EPIT1_Init(EPIT_Init_t *EPIT_InitStructure)
{
    if( EPIT_InitStructure->EPIT_Prescaler > 4095 ) EPIT_InitStructure->EPIT_Prescaler = 4095;
    //CR清零
    EPIT1->CR = 0;
    EPIT1->CR = (EPIT_InitStructure->EPIT_ENMODE << 1) | \
    (EPIT_InitStructure->EPIT_Compare_Interrput << 2) | \
    (EPIT_InitStructure->EPIT_Reload_Control << 3) | \
    (EPIT_InitStructure->EPIT_Prescaler << 4) | \
    (EPIT_InitStructure->EPIT_Clock_Source << 24);
    EPIT1->LR = EPIT_InitStructure->EPIT_Load_Value;
    EPIT1->CMPR = EPIT_InitStructure->EPIT_Compare_Value;

    //初始化中断
    GIC_EnableIRQ(EPIT1_IRQn);
    system_register_irqhandler(EPIT1_IRQn, EPIT1_irqhandler, NULL);
}

void EPIT1_Enable(void)
{
    EPIT1->CR |= (1 << 0);
}

void EPIT1_irqhandler(unsigned int gicciar, void *param)
{
    static uint8_t LED_Flag = 0;
    if(EPIT1->SR & (1 << 0))
    {
        LED_Flag = !LED_Flag;
        if(LED_Flag) LED_ON();
        else LED_OFF();
    }
    EPIT1->SR |= (1 << 0);
}


