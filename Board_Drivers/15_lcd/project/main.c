#include "bsp_clk.h"
#include "bsp_led.h"
#include "bsp_exti.h"
#include "bsp_epit.h"
#include "bsp_keyfilter.h"
#include "bsp_uart.h"
#include "bsp_lcd.h"




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
    UART1_Init();
    LCD_Init();
    
    while(1)
    {
        
    }
    return 0;
}