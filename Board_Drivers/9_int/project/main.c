#include "imx6u.h"
#include "bsp_clk.h"
#include "bsp_delay.h"
#include "bsp_led.h"
#include "bsp_beep.h"
#include "bsp_key.h"
#include "bsp_int.h"



int main()
{
    Int_Init();
    imx6u_clkinit();
    Clock_Enable();
    LED_Init();
    beep_Init();
    Key_Init();
    

    volatile uint32_t i = 0;
    uint8_t LED_Flag = 0;
    uint8_t beep_Flag = 0;
    uint8_t KeyNum = 0;
    beep_switch(beep_Flag);
    while(1)
    {

        i++;
        if(i >= 500000)
        {
            i = 0;
            LED_Flag = !LED_Flag;
            if(LED_Flag == 1)
            {
                LED_ON();
            }
            else
            {
                LED_OFF();
            }
        }

        KeyNum = Key_GetNum();
        if(KeyNum == 1)
        {
            beep_switch(beep_Flag);
            beep_Flag = !beep_Flag;
        }

    }
    return 0;
}