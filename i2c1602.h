#ifndef I2C1602_H_
#define I2C1602_H_

#include "main.h"

#define ADDR_1 0b01001110//device address 0b0100(A2,A1,A0)0


void LCD_I2C_Cmd(uint8_t cmd);
void LCD_I2C_Char(uint8_t data);
void LCD_I2C_Init(void);
void LCD_I2C_String(uint8_t *str);
void LCD_I2C_String_xy(uint8_t row, uint8_t pos, uint8_t *str);
void LCD_I2C_Clear(void);




#endif /* I2C1602_H_ */