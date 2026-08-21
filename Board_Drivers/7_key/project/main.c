
#include "bsp_clk.h"
#include "bsp_delay.h"
#include "bsp_led.h"
#include "bsp_beep.h"
#include "bsp_key.h"



int main()
{
    Clock_Init();
    LED_Init();
    beep_Init();
    Key_Init();

    uint8_t beep_flag = 0;
    uint8_t KeyNum = 0;
    while(1)
    {

        KeyNum = Key_GetNum();
        if(KeyNum == 1)
        {
            beep_switch(!beep_flag);
            beep_flag = !beep_flag;
        }

    }
    return 0;
}