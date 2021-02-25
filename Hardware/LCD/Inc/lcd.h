//
// Created by kai on 2021/2/15.
//

#ifndef OPENHANDHELD_LCD_H
#define OPENHANDHELD_LCD_H

#include "main.h"

#define    USE_ASCII_FONT_LIB             1       //使用ASCII字符显示请打开该宏(值设为1)
#define    USE_PICTURE_DISPLAY            1       //使用图片显示请打开该宏(值设为1)

#define    LCD_PWR(n)       do{\
                               n?\
                               HAL_GPIO_WritePin(LCD_LED_GPIO_Port,LCD_LED_Pin,GPIO_PIN_SET):\
                               HAL_GPIO_WritePin(LCD_LED_GPIO_Port,LCD_LED_Pin,GPIO_PIN_RESET);\
                            }while(0U)
#define    LCD_WR_RS(n)     do{\
                               n?\
                               HAL_GPIO_WritePin(LCD_DC_GPIO_Port,LCD_DC_Pin,GPIO_PIN_SET):\
                               HAL_GPIO_WritePin(LCD_DC_GPIO_Port,LCD_DC_Pin,GPIO_PIN_RESET);\
                            }while(0U)
#define    LCD_RST(n)       do{\
                                n?\
                                HAL_GPIO_WritePin(LCD_RST_GPIO_Port,LCD_RST_Pin,GPIO_PIN_SET):\
                                HAL_GPIO_WritePin(LCD_RST_GPIO_Port,LCD_RST_Pin,GPIO_PIN_RESET);\
                            }while(0U)

#define LCD_Width 240
#define LCD_Height 240

//画笔颜色
#define WHITE         0xFFFF    //白色
#define YELLOW        0xFFE0    //黄色
#define BRRED          0XFC07    //棕红色
#define PINK          0XF81F    //粉色
#define RED           0xF800    //红色
#define BROWN          0XBC40    //棕色
#define GRAY          0X8430    //灰色
#define GBLUE          0X07FF    //兰色
#define GREEN         0x07E0    //绿色
#define BLUE          0x001F    //蓝色
#define BLACK         0x0000    //黑色

void LCD_Address_Set(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);

void LCD_DisplayOn(void);

void LCD_DisplayOff(void);

void LCD_Clear(uint16_t color);

void LCD_Init(void);            //LCD初始化函数

void LCD_Draw_ColorPoint(uint16_t x, uint16_t y, uint16_t color);

void LCD_Draw_ColorLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);

void LCD_Draw_ColorRect(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);

void LCD_Draw_ColorCircle(uint16_t x, uint16_t y, uint16_t r, uint16_t color);

void LCD_Fill(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);

#if USE_ASCII_FONT_LIB

void LCD_ShowChar(uint16_t x, uint16_t y, char ch, uint16_t back_color, uint16_t font_color, uint8_t font_size);

void LCD_ShowCharStr(uint16_t x, uint16_t y, uint8_t max_width, char *str, uint16_t back_color, uint16_t font_color,
                     uint8_t font_size);

#endif /* USE_ASCII_FONT_LIB */

void LCD_Draw_ColorSixPointStar(uint16_t x, uint16_t y, uint8_t r, uint16_t color);

#if USE_PICTURE_DISPLAY
void LCD_Show_Image(uint16_t x, uint16_t y, uint16_t width, uint16_t height, const uint8_t *p);
#endif /*USE_PICTURE_DISPLAY */


#endif //OPENHANDHELD_LCD_H
