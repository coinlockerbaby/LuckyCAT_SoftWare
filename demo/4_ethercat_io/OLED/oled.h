#ifndef __OLED_H
#define __OLED_H

#include "board.h"
#include "hpm_gpio_drv.h"

//-----------------OLED端口定义----------------

#define OLED_SCL_Clr() gpio_write_pin(HPM_GPIO0, GPIO_DO_GPIOD, 7U, 0) // SCL
#define OLED_SCL_Set() gpio_write_pin(HPM_GPIO0, GPIO_DO_GPIOD, 7U, 1)

#define OLED_SDA_Clr() gpio_write_pin(HPM_GPIO0, GPIO_DO_GPIOD, 6U, 0) // DIN
#define OLED_SDA_Set() gpio_write_pin(HPM_GPIO0, GPIO_DO_GPIOD, 6U, 1)

#define OLED_CMD 0  // 写命令
#define OLED_DATA 1 // 写数据

void OLED_ClearPoint(uint8_t x, uint8_t y);
void OLED_ColorTurn(uint8_t i);
void OLED_DisplayTurn(uint8_t i);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_WaitAck(void);
void Send_Byte(uint8_t dat);
void OLED_WR_Byte(uint8_t dat, uint8_t mode);
void OLED_DisPlay_On(void);
void OLED_DisPlay_Off(void);
void OLED_Refresh(void);
void OLED_Clear(void);
void OLED_DrawPoint(uint8_t x, uint8_t y, uint8_t t);
void OLED_DrawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t mode);
void OLED_DrawCircle(uint8_t x, uint8_t y, uint8_t r);
void OLED_ShowChar(uint8_t x, uint8_t y, uint8_t chr, uint8_t size1, uint8_t mode);
void OLED_ShowChar6x8(uint8_t x, uint8_t y, uint8_t chr, uint8_t mode);
void OLED_ShowString(uint8_t x, uint8_t y, uint8_t *chr, uint8_t size1, uint8_t mode);
void OLED_ShowNum(uint8_t x, uint8_t y, uint32_t num, uint8_t len, uint8_t size1, uint8_t mode);
void OLED_ShowChinese(uint8_t x, uint8_t y, uint8_t num, uint8_t size1, uint8_t mode);
void OLED_ScrollDisplay(uint8_t num, uint8_t space, uint8_t mode);
void OLED_ShowPicture(uint8_t x, uint8_t y, uint8_t sizex, uint8_t sizey, uint8_t BMP[], uint8_t mode);
void OLED_Init(void);

#endif
