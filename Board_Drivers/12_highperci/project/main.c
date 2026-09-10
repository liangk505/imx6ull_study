#include "bsp_clk.h"
#include "bsp_led.h"
#include "bsp_exti.h"
#include "bsp_epit.h"
#include "bsp_keyfilter.h"



int main()
{
    Int_Init();
    imx6u_clkinit();
    Clock_Enable();
    LED_Init();
    beep_Init();
    Keyfilter_Init();
    Keyfilter_Epit_Init();
    delay_Init();

    uint8_t LED_Flag = 0;
    while(1)
    {
        LED_Flag = !LED_Flag;
        if(LED_Flag) LED_ON();
        else LED_OFF();
        delay_ms(500);
    }
    return 0;
}