#ifndef __BSP_GPIO_H
#define __BSP_GPIO_H

#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "MCIMX6Y2.h"

typedef enum _gpio_interrupt_mode
{
    kGPIO_Nointmode = 0U,//无触发
    kGPIO_IntLowLevel = 1U,
    kGPIO_IntHighLevel = 2U,
    kGPIO_IntRiseEdge = 3U,
    kGPIO_IntFallingEdge = 4U,
    kGPIO_IntRiseOrFallingEdge = 5U,
}_gpio_interrput_mode_t;

typedef enum _gpio_pin_direction
{
    kGPIO_DigitalInput = 0U,
    kGPIO_DigitalOutput = 1U,
}_gpio_pin_direction_t;

typedef struct _gpio_pin_config
{
    _gpio_pin_direction_t direction;
    uint8_t outputLogic;
    _gpio_interrput_mode_t interruptMode;
}_gpio_pin_config_t;

void GPIO_Init(GPIO_Type * GPIOx, uint8_t PIN, _gpio_pin_config_t * config);
uint32_t GPIO_ReadPins(GPIO_Type * GPIOx);
uint8_t GPIO_ReadPin(GPIO_Type * GPIOx, uint8_t PIN);
void GPIO_WritePin(GPIO_Type * GPIOx, uint8_t PIN, uint8_t logic);
void GPIO_Interrupt_Enable(GPIO_Type *GPIOx, uint8_t PIN);
void GPIO_Interrupt_Disable(GPIO_Type *GPIOx, uint8_t PIN);
void GPIO_Clear_InterruptFlag(GPIO_Type *GPIOx, uint8_t PIN);
void GPIO_Interrupt_Init(GPIO_Type *GPIOx, uint8_t PIN, _gpio_interrput_mode_t pin_interrupt_config);

#endif // !__BSP_GPIO_H
