#ifndef __BSP_EXTI_H
#define __BSP_EXTI_H

#include "imx6u.h"
#include "bsp_key.h"
#include "bsp_int.h"
#include "bsp_delay.h"
#include "bsp_beep.h"

void Exti_Init(void);
void GPIO1_IO18_IRQHandler(unsigned int gicciar, void *param);

#endif // !__BSP_EXTI_H
