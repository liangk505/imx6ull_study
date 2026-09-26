#include "bsp_key.h"

void Key_Init(void)
{
    IOMUXC_SetPinMux(IOMUXC_UART1_CTS_B_GPIO1_IO18,0);
    IOMUXC_SetPinConfig(IOMUXC_UART1_CTS_B_GPIO1_IO18,0xF080);
    _gpio_pin_config_t config;
    config.direction = kGPIO_DigitalInput;
    GPIO_Init(GPIO1, 18, &config);
    // GPIO1->GDIR &= ~(1 << 18);
}


uint8_t Key_GetNum(void)
{
    uint8_t Key_Num = 0;

    if(((GPIO_ReadPins(GPIO1) & (1<<18)) == 0))
    {
        delay(10);
        if(( GPIO_ReadPins(GPIO1) & (1<<18) )== 0)
        {
            while(!(GPIO_ReadPins(GPIO1) & (1<<18) ) );
            delay(10);
            Key_Num = 1;
        }
    }
    return Key_Num;
}