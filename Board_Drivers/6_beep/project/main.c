
#include "bsp_clk.h"
#include "bsp_delay.h"
#include "bsp_led.h"
#include "bsp_beep.h"

int main()
{
    Clock_Init();
    LED_Init();
    beep_Init();


    while(1)
    {
        LED_OFF();
        beep_switch(0);
        delay(1000);
        LED_ON();
        beep_switch(1);
        delay(1000);

    }
    return 0;
}