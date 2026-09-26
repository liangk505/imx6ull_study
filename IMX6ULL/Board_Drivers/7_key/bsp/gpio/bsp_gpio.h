#ifndef __BSP_GPIO_H
#define __BSP_GPIO_H

#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "MCIMX6Y2.h"

typedef enum _gpio_pin_direction
{
    kGPIO_DigitalInput = 0U,
    kGPIO_DigitalOutput = 1U,
}_gpio_pin_direction_t;

typedef struct _gpio_pin_config
{
    _gpio_pin_direction_t direction;
    uint8_t outputLogic;
}_gpio_pin_config_t;

void GPIO_Init(GPIO_Type * GPIOx, uint8_t PIN, _gpio_pin_config_t * config);
uint32_t GPIO_ReadPins(GPIO_Type * GPIOx);
uint8_t GPIO_ReadPin(GPIO_Type * GPIOx, uint8_t PIN);
void GPIO_WritePin(GPIO_Type * GPIOx, uint8_t PIN, uint8_t logic);

#endif // !__BSP_GPIO_H
