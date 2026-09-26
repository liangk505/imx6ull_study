#ifndef __BSP_LCD_H
#define __BSP_LCD_H

#include "imx6u.h"
#include "bsp_gpio.h"
#include "stdio.h"

/* 屏幕ID */
#define ATK4342		0X4342	/* 4.3寸480*272 	*/
#define ATK4384		0X4384	/* 4.3寸800*480 	*/
#define ATK7084		0X7084	/* 7寸800*480 		*/
#define ATK7016		0X7016	/* 7寸1024*600 		*/
#define ATK1018		0X1018	/* 10.1寸1280*800 	*/
#define ATKVGA		0xff00 /* VGA */

unsigned short LCD_ReadID(void);
void LCD_Init(void);
void LCD_GPIO_Init(void);
#endif 

