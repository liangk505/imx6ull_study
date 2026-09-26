#include "fsl_iomuxc.h"
#include "MCIMX6Y2.h"

void Clock_Init(void)
{
    CCM->CCGR2 = 0xFFFFFFFF;
}
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

void delay_short(volatile unsigned int n)
{
    while(n--)
    {

    }
}

void delay(volatile unsigned int n)
{
    while(n--)
    {
        delay_short(0x7ff);
    }
}

void LED_OFF(void)
{
    GPIO1->DR |= (1<<3);
}

int main()
{
    Clock_Init();
    LED_Init();


    while(1)
    {
        LED_OFF();
        delay(1000);
        LED_ON();
        delay(1000);

    }
    return 0;
}