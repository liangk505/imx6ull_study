#include "bsp_delay.h"

void delay_Init(void)
{
    GPT1->CR = 0;
    GPT1->CR |= (1 << 15);//软件复位
    while( (GPT1->CR >> 15) & 0x01);
    
    GPT1->CR = (1 << 1) | (1 << 6);
    GPT1->PR = 65;
    //频率是1MHz,所以一个计数是1us,0xffffffff = 4,294,967,295 71min左右溢出
    GPT1->OCR[0] = 0xffffffff;
    // GPT1->IR = (1 << 0);

    // GIC_EnableIRQ(GPT1_IRQn);
    // system_register_irqhandler(GPT1_IRQn, GPT1_Handler, NULL);
    GPT1_Enable();
}

void delay_us(uint32_t us)
{
    uint32_t tim1 = 0;
    tim1 = GPT1->CNT;
    while((GPT1->CNT - tim1) < us);
}

void delay_ms(uint32_t ms)
{
    int i = 0;
    for(i = 0; i < ms; i++)
    {
        delay_us(1000);
    }
}

void GPT1_Enable()
{
    GPT1->CR |= (1 << 0);
}
#if 0
void GPT1_Handler(unsigned int giccia, void * Param)
{
    static uint8_t LED_Flag = 0;
    if( GPT1->SR & (1 << 0))
    {
        LED_Flag = !LED_Flag;
        if(LED_Flag) LED_ON();
        else LED_OFF();
    }
    GPT1->SR |= (1 << 0);
}
#endif

void delay_short(volatile unsigned int n)
{
    while(n--)
    {

    }
}

void delay(volatile unsigned int n)
{
    while(n--)
    {
        delay_short(0x7ff);
    }
}
