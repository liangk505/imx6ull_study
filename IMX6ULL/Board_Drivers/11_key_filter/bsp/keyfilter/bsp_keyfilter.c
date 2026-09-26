#include "bsp_keyfilter.h"

void Keyfilter_Epit_Init(void)
{
    EPIT_Init_t EPIT_InitStructure;
    EPIT_InitStructure.EPIT_Clock_Source = 1;
    EPIT_InitStructure.EPIT_Compare_Interrput = 1;
    EPIT_InitStructure.EPIT_ENMODE = 1;
    EPIT_InitStructure.EPIT_Reload_Control = 1;
    EPIT_InitStructure.EPIT_Prescaler = 0;
    EPIT_InitStructure.EPIT_Compare_Value = 0;
    EPIT_InitStructure.EPIT_Load_Value = 66000000/100;
    EPIT1_Init(&EPIT_InitStructure);
}

void EPIT1_irqhandler(unsigned int gicciar, void *param)
{
    static uint8_t Beep_Flag = 0;
    if(EPIT1->SR & (1 << 0))
    {
        EPIT1_Disable();
        if( GPIO_ReadPin(GPIO1, 18) == 0)
        {
            beep_switch(Beep_Flag);
            Beep_Flag = !Beep_Flag;
        }
    }
    EPIT1->SR |= (1 << 0);
}

void Keyfilter_Epit_Reset(uint32_t value)
{
    EPIT1_Disable();
    EPIT1->LR = value;
    EPIT1_Enable();
}
    

void Keyfilter_Init(void)
{
    IOMUXC_SetPinMux(IOMUXC_UART1_CTS_B_GPIO1_IO18,0);
    IOMUXC_SetPinConfig(IOMUXC_UART1_CTS_B_GPIO1_IO18,0xF080);
    _gpio_pin_config_t config;
    config.direction = kGPIO_DigitalInput;
    config.interruptMode = kGPIO_IntFallingEdge;
    GPIO_Init(GPIO1, 18, &config);

    GIC_EnableIRQ(GPIO1_Combined_16_31_IRQn);

    system_register_irqhandler(GPIO1_Combined_16_31_IRQn, GPIO1_16_31_IRQHandler, NULL);

    GPIO_Interrupt_Enable(GPIO1, 18);
}

void GPIO1_16_31_IRQHandler(unsigned int gicciar, void *Param)
{
    if( GPIO1->ISR & (1 << 18))
    {
        Keyfilter_Epit_Reset(66000000/100);
    }
    GPIO_Clear_InterruptFlag(GPIO1, 18);
}
