#include "bsp_key.h"

void Key_Init(void)
{
    IOMUXC_SetPinMux(IOMUXC_UART1_CTS_B_GPIO1_IO18,0);

    IOMUXC_SetPinConfig(IOMUXC_UART1_CTS_B_GPIO1_IO18,0xF080);
    GPIO1->GDIR &= ~(1<<18);
}

uint32_t GPIO_ReadPins(uint32_t num)
{
    uint32_t temp = 0;
    temp = GPIO1->DR & num;
    return temp;
}

uint8_t Key_GetNum(void)
{
    uint8_t Key_Num = 0;
    if(( GPIO_ReadPins(1<<18) & (1<<18) )== 0)
    {
        delay(20);
        if(( GPIO_ReadPins(1<<18) & (1<<18) )== 0)
        {
            while(! (GPIO_ReadPins(1<<18) & (1<<18) ) );
            delay(20);
            Key_Num = 1;
        }
        
    }
    return Key_Num;
}