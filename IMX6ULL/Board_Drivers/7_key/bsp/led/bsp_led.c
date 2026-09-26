#include "bsp_led.h"

void LED_Init(void)
{
    IOMUXC_SetPinMux(IOMUXC_GPIO1_IO03_GPIO1_IO03,0);
    IOMUXC_SetPinConfig(IOMUXC_GPIO1_IO03_GPIO1_IO03,0x10B0);
    GPIO1->GDIR = 0x00000008;
    GPIO1->DR = 0x00000008;     //初始LED为关
}

void LED_ON(void)
{
    GPIO1->DR &= ~(1<<3);
}

void LED_OFF(void)
{
    GPIO1->DR |= (1<<3);
}
