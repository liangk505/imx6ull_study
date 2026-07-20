#include "bsp_clk.h"
#include "bsp_delay.h"
#include "bsp_led.h"

int main()
{
    Clock_Init();
    LED_Init();


    while(1)
    {
        LED_OFF();
        delay(1000);
        LED_ON();
        delay(1000);

    }
    return 0;
}