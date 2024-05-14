#include "i2c.h"

void I2C_Init(void){
	TWBR=0x20; //transmission rate (at 8 MHz, 100 kHz )
}
void I2C_Start(void){
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while(!(TWCR&(1<<TWINT)));//wait until TWIN is installed
}
void I2C_Stop(void){
	TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}
void I2C_SendByte(uint8_t c){
	TWDR = c;//write a byte to the data register
	TWCR = (1<<TWINT)|(1<<TWEN);//turn on the byte transfer
	 while (!(TWCR & (1<<TWINT)));//wait until TWIN is installed
}