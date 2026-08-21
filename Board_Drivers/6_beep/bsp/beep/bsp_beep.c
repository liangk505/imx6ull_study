#include "bsp_beep.h"

void beep_Init(void)
{
    IOMUXC_SetPinMux(IOMUXC_SNVS_SNVS_TAMPER1_GPIO5_IO01, 0);
    IOMUXC_SetPinConfig(IOMUXC_SNVS_SNVS_TAMPER1_GPIO5_IO01,0x10b0);
    GPIO5->GDIR |= (1<<1);
    GPIO5->DR &= ~(1<<1);
}

void beep_switch(uint8_t status)
{
    if(status == 1)
    {
        GPIO5->DR &= (0<<1);
    }
    if(status == 0)
    {
        GPIO5->DR |= (1<<1);
    }
}
