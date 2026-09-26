#include "bsp_clk.h"

void Clock_Init(void)
{
    CCM->CCGR2 = 0xFFFFFFFF;
}
