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

    uint32_t reg = 0;
    reg = CCM_ANALOG->PFD_528;
    reg &= ~(0x3F3F3F3F);
    reg |= (32 << 24);
    reg |= (24 << 16);
    reg |= (16 << 8);
    reg |= (27 << 0);
    CCM_ANALOG->PFD_528 = reg;

    reg = CCM_ANALOG->PFD_480;
    reg &= ~(0x3F3F3F3F);
    reg |= (19 << 24);
    reg |= (17 << 16);
    reg |= (16 << 8);
    reg |= (12 << 0);
    CCM_ANALOG->PFD_480 = reg;

    CCM->CBCMR &= ~(3 << 18);   //清零
    CCM->CBCMR |= (1 << 18);

    CCM->CBCDR &= ~(1 << 25);
    while(( CCM->CDHIPR & (1 << 5) ) == 1);
    reg = CCM->CBCDR;
    reg &= ~(7 << 10);   //AHB_PODF
    reg |= (2 << 10);
    CCM->CBCDR = reg;
    while(( CCM->CDHIPR & (1 << 1) ) == 1);
    
    CCM->CBCDR &= ~(3 << 8);
    CCM->CBCDR |= (1 << 8);

    CCM->CSCMR1 &= ~(1 << 6);
    CCM->CSCMR1 &= ~(63 << 0);
}
