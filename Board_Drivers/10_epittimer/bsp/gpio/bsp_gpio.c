#include "bsp_gpio.h"

void GPIO_Init(GPIO_Type * GPIOx, uint8_t PIN, _gpio_pin_config_t * config)
{
    if(config->direction == kGPIO_DigitalInput)
    {
        GPIOx->GDIR &= ~(1<<PIN);
    }
    else
    {
        GPIOx->GDIR |= (1<<PIN);
        GPIO_WritePin(GPIOx,PIN,config->outputLogic);
    }
    GPIO_Interrupt_Init(GPIOx, PIN, config->interruptMode);
}

uint32_t GPIO_ReadPins(GPIO_Type * GPIOx)
{
    uint32_t temp = 0;
    temp = GPIOx->DR;
    return temp;
}

uint8_t GPIO_ReadPin(GPIO_Type * GPIOx, uint8_t PIN)
{
    uint32_t temp = GPIO_ReadPins(GPIOx);
    uint8_t re = (temp & (1<<PIN) ) == 0 ? 0 : 1;
    return re;
}

void GPIO_WritePin(GPIO_Type * GPIOx, uint8_t PIN, uint8_t logic)
{
    if(logic == 1)
    {
        GPIOx->DR |= (logic<<PIN);
    }
    else if(logic == 0)
    {
        GPIOx->DR &= ~(1<<PIN);
    }
}

void GPIO_Interrupt_Enable(GPIO_Type *GPIOx, uint8_t PIN)
{
    GPIOx->IMR |= (1 << PIN);
}

void GPIO_Interrupt_Disable(GPIO_Type *GPIOx, uint8_t PIN)
{
    GPIOx->IMR &= ~(1 << PIN);
}

void GPIO_Clear_InterruptFlag(GPIO_Type *GPIOx, uint8_t PIN)
{
    GPIOx->ISR |= (1 << PIN);
}

void GPIO_Interrupt_Init(GPIO_Type *GPIOx, uint8_t PIN, _gpio_interrput_mode_t pin_interrupt_config)
{
    volatile uint32_t *icr;
    uint32_t icrShift = 0;
    icrShift = PIN;
    GPIOx->EDGE_SEL &= ~(1 << PIN);

    if(PIN < 16)
    {
        icr = &(GPIOx->ICR1);
    }
    else
    {
        icr = &(GPIOx->ICR2);
        icrShift -= 16;
    }

    switch (pin_interrupt_config)
    {
    case kGPIO_IntLowLevel:
        *icr &= ~(3 << (2*icrShift));
        break;
    case kGPIO_IntHighLevel:
        *icr &= ~(3 << (2*icrShift));
        *icr |= (1 << (2*icrShift));
        break;
    case kGPIO_IntRiseEdge:
        *icr &= ~(3 << (2*icrShift));
        *icr |= (2 << (2*icrShift));
        break;
    case kGPIO_IntFallingEdge:
        *icr &= ~(3 << (2*icrShift));
        *icr |= (3 << (2*icrShift));
        break;
    case kGPIO_IntRiseOrFallingEdge:
        GPIOx->EDGE_SEL |= (1 << PIN);
        break;
    default:
        break;
    }
}
