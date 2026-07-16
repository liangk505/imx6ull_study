#include "main.h"

/*使能时钟*/
void Clock_Enable()
{
    CCM_CCGR1 = 0xffffffff;
}

void LED_Init()
{
    IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO03 = 0x00000005;
    IOMUXC_SW_PAD_CTL_PAD_GPIO1_IO03 = 0x000000b0;

    GPIOx_GDIR = 0x00000008;
    GPIOx_DR = 0x00000008;/*关闭LED*/
}

void delay_short(volatile unsigned int n)
{
    while(n--)
    {

    }
}

void delay_ms(volatile unsigned int n)
{
    while (n--)
    {
        /* code */
        delay_short(0x7ff);
    }
    
}

void LED_OFF()
{
    GPIOx_DR |= (1<<3);
}

void LED_ON()
{
    GPIOx_DR &= ~(1<<3);
}
int main()
{
    Clock_Enable();
    LED_Init();

    while (1)
    {
        /* code */
        delay_ms(500);
        LED_ON();
        delay_ms(500);
        LED_OFF();
    }
    return 0;
}