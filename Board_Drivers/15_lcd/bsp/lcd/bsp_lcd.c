#include "bsp_lcd.h"

void LCD_Init(void)
{
    unsigned short id = LCD_ReadID();
    printf("LCD ID = %d\n", id);
}

unsigned short LCD_ReadID(void)
{
    unsigned char id = 0;
    //打开模拟开关
    IOMUXC_SetPinMux(IOMUXC_LCD_VSYNC_GPIO3_IO03,0);
    IOMUXC_SetPinConfig(IOMUXC_LCD_VSYNC_GPIO3_IO03,0x10B0);
    _gpio_pin_config_t lcd_io_config;
    lcd_io_config.direction = kGPIO_DigitalOutput;
    lcd_io_config.outputLogic = 1;
    GPIO_Init(GPIO3, 3, &lcd_io_config);

    IOMUXC_SetPinMux(IOMUXC_LCD_DATA07_GPIO3_IO12,0);
    IOMUXC_SetPinMux(IOMUXC_LCD_DATA15_GPIO3_IO20,0);
    IOMUXC_SetPinMux(IOMUXC_LCD_DATA23_GPIO3_IO28,0);

    IOMUXC_SetPinConfig(IOMUXC_LCD_DATA07_GPIO3_IO12,0xF080);
    IOMUXC_SetPinConfig(IOMUXC_LCD_DATA15_GPIO3_IO20,0xF080);
    IOMUXC_SetPinConfig(IOMUXC_LCD_DATA23_GPIO3_IO28,0xF080);

    lcd_io_config.direction = kGPIO_DigitalInput;
    GPIO_Init(GPIO3, 12, &lcd_io_config);
    GPIO_Init(GPIO3, 20, &lcd_io_config);
    GPIO_Init(GPIO3, 28, &lcd_io_config);

    id = (unsigned char)GPIO_ReadPin(GPIO3, 28);
    id |= (unsigned char)GPIO_ReadPin(GPIO3, 20) << 1;
    id |= (unsigned char)GPIO_ReadPin(GPIO3, 12) << 2;

    if(id == 0) return ATK4342;
    else if(id == 1) return ATK7084;
    else if(id == 2) return ATK7016;
    else if(id == 4) return ATK4384;
    else if(id == 5) return ATK1018;
    else if(id == 7) return ATKVGA;
    else return 0;
}
