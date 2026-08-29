#include "bsp_clk.h"

void Clock_Enable(void)
{
    CCM->CCGR0 = 0xFFFFFFFF;
    CCM->CCGR1 = 0xFFFFFFFF;
    CCM->CCGR2 = 0xFFFFFFFF;
    CCM->CCGR3 = 0xFFFFFFFF;
    CCM->CCGR4 = 0xFFFFFFFF;
    CCM->CCGR5 = 0xFFFFFFFF;
    CCM->CCGR6 = 0xFFFFFFFF;
}

void imx6u_clkinit(void)
{
    /*初始化6u的主频为528Hz*/
    if(((CCM->CCSR >> 2) & 0x1 )== 0) /*当前时钟使用的是pll_main_clk*/
    {
        CCM->CCSR &= ~(1<<8);
        CCM->CCSR |= (1 << 2);
    }
    /*设置PLL1=1056MHz*/
    CCM_ANALOG->PLL_ARM = (1<<13) | ((88<<0) & 0x7F);
    CCM->CACRR = 1; //二分频
    CCM->CCSR &= ~(1<<2); /*设置pll1_sw_clk=pll1_main_clk = 1056*/
}
