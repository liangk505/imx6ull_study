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
    int a = 0,b = 0;
    while(1)
    {
        printf("请输入两个整数：\r\n");
        scanf("%d %d",&a,&b);
        printf("两数和为：%d",a+b);
    }
    return 0;
}