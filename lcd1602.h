
#ifndef LCD1602_H_
#define LCD1602_H_

#include "main.h"


#define LCD_Dir  DDRB
#define LCD_Port PORTB
#define RS PB0
#define EN PB1


void LCD_Command( unsigned char cmnd );
void LCD_Char( unsigned char data );
void LCD_Init (void);
void LCD_String (char *str);
void LCD_String_xy (char row, char pos, char *str);
void LCD_Clear();


#endif /* LCD1602_H_ */