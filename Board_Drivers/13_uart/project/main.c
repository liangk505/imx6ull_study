#include "bsp_clk.h"
#include "bsp_led.h"
#include "bsp_exti.h"
#include "bsp_epit.h"
#include "bsp_keyfilter.h"
#include "bsp_uart.h"




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

    while(1)
    {
        UART1_SendString("请输入一个字符：\r\n");
        uint8_t byte = UART1_ReceiveByte();
        UART1_SendByte(byte);
        UART1_SendString("\r\n");
    }
    return 0;
}