#include "bsp_clk.h"
#include "bsp_led.h"
#include "bsp_exti.h"
#include "bsp_epit.h"



int main()
{
    Int_Init();
    imx6u_clkinit();
    Clock_Enable();
    LED_Init();
    beep_Init();
    Key_Init();
    Exti_Init();

    EPIT_Init_t EPIT_InitStructure;
    EPIT_InitStructure.EPIT_Clock_Source = 1;
    EPIT_InitStructure.EPIT_Compare_Interrput = 1;
    EPIT_InitStructure.EPIT_ENMODE = 1;
    EPIT_InitStructure.EPIT_Reload_Control = 1;
    EPIT_InitStructure.EPIT_Prescaler = 0;
    EPIT_InitStructure.EPIT_Compare_Value = 0;
    EPIT_InitStructure.EPIT_Load_Value = 33000000;
    EPIT1_Init(&EPIT_InitStructure);
    EPIT1_Enable();
    

    uint8_t beep_Flag = 0;
    beep_switch(beep_Flag);
    while(1)
    {

    }
    return 0;
}