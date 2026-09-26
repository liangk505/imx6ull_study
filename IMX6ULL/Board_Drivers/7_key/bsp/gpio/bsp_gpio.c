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

