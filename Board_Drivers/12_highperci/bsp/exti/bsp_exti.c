#include "bsp_exti.h"

void Exti_Init(void)
{
    IOMUXC_SetPinMux(IOMUXC_UART1_CTS_B_GPIO1_IO18,0);
    IOMUXC_SetPinConfig(IOMUXC_UART1_CTS_B_GPIO1_IO18,0xF080);
    _gpio_pin_config_t config;
    config.direction = kGPIO_DigitalInput;
    config.interruptMode = kGPIO_IntFallingEdge;
    GPIO_Init(GPIO1, 18, &config);

    GIC_EnableIRQ(GPIO1_Combined_16_31_IRQn);

    // system_register_irqhandler(GPIO1_Combined_16_31_IRQn, GPIO1_IO18_IRQHandler, NULL);

    GPIO_Interrupt_Enable(GPIO1, 18);
}

// void GPIO1_IO18_IRQHandler(unsigned int gicciar, void *param)
// {
//     static uint8_t status = 0;
//     delay(10);
//     if(GPIO_ReadPin(GPIO1, 18) == 0)
//     {
//         status = !status;
//         beep_switch(status);
//     }
//     GPIO_Clear_InterruptFlag(GPIO1, 18);
// }
