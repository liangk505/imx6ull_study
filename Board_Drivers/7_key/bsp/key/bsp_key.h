#ifndef __BSP_KEY_H
#define __BSP_KEY_H

#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "MCIMX6Y2.h"
#include "bsp_delay.h"


uint8_t Key_GetNum(void);
void Key_Init(void);

#endif // !__BSP_KEY_H
