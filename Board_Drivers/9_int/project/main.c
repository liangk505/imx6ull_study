#include "bsp_clk.h"
#include "bsp_led.h"
#include "bsp_exti.h"



int main()
{
    Int_Init();
    imx6u_clkinit();
    Clock_Enable();
    LED_Init();
    beep_Init();
    Key_Init();
    Exti_Init();
    

    uint8_t LED_Flag = 0;
    uint8_t beep_Flag = 0;
    beep_switch(beep_Flag);
    while(1)
    {
        LED_Flag = !LED_Flag;
        if(LED_Flag == 1)
        {
            LED_ON();
        }
        else
        {
            LED_OFF();
        }
        delay(500);
    }
    return 0;
}