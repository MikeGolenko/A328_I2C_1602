#include "i2c1602.h"

void LCD_I2C_Cmd(uint8_t cmd){
	I2C_Start();
	I2C_SendByte(ADDR_1);
	I2C_SendByte((cmd&0xF0)|0b00001100);//lowest half-byte + 0b0000(K)(E)(RW)(RS)
	I2C_SendByte((cmd&0xF0)|0b00001000);//0b0000(K)(E)(RW)(RS)
	I2C_Stop();
	_delay_us(200);
	I2C_Start();
	I2C_SendByte(ADDR_1);
	I2C_SendByte(((cmd<<4)&0xF0)|0b00001100);//highest half-byte + 0b0000(K)(E)(RW)(RS)
	I2C_SendByte(((cmd<<4)&0xF0)|0b00001000);//0b0000(K)(E)(RW)(RS)
	I2C_Stop();	
}
void LCD_I2C_Char(uint8_t data){
	I2C_Start();
	I2C_SendByte(ADDR_1);
	I2C_SendByte((data&0xF0)|0b00001101);//lowest half-byte + 0b0000(K)(E)(RW)(RS)
	I2C_SendByte((data&0xF0)|0b00001001);//0b0000(K)(E)(RW)(RS)
	I2C_Stop();
	_delay_us(200);
	I2C_Start();
	I2C_SendByte(ADDR_1);
	I2C_SendByte(((data<<4)&0xF0)|0b00001101);//highest half-byte + 0b0000(K)(E)(RW)(RS)
	I2C_SendByte(((data<<4)&0xF0)|0b00001001);//0b0000(K)(E)(RW)(RS)
	I2C_Stop();	
}
void LCD_I2C_Init(void){
	LCD_I2C_Cmd(0x02);//going back
	LCD_I2C_Cmd(0x28);//4 bit, 2 line, 5*8 point
	LCD_I2C_Cmd(0x0C);//display ONN, cursor is hidden, displayed constantly
	LCD_I2C_Cmd(0x06);//shift
	LCD_I2C_Cmd(0x01);//clear
	_delay_ms(2);	
}
void LCD_I2C_String(uint8_t *str){
	int i;
	for(i=0;str[i]!=0;i++)
	{
		LCD_I2C_Char (str[i]);
	}	
}
void LCD_I2C_String_xy(uint8_t row, uint8_t pos, uint8_t *str){
	if (row == 0 && pos<16)
	LCD_I2C_Cmd((pos & 0x0F)|0x80);
	else if (row == 1 && pos<16)
	LCD_I2C_Cmd((pos & 0x0F)|0xC0);
	LCD_I2C_String(str);	
}
void LCD_I2C_Clear(void){
	 LCD_I2C_Cmd (0x01);
	 _delay_ms(2);
	 LCD_I2C_Cmd (0x80);
}
