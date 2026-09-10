#ifndef __BSP_LED_H
#define __BSP_LED_H

#include "fsl_common.h"
#include "MCIMX6Y2.h"
#include "fsl_iomuxc.h"

void LED_Init(void);
void LED_ON(void);
void LED_OFF(void);


#endif // !__BSP_LED_H
