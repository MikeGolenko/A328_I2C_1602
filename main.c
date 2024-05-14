#include "main.h"

//system timer for 10ms
void timer2_init(void){
	//TCCR2A |=(1<<COM2A1);
	TCCR2A |=(1<<WGM21);
	TCCR2B |=(1<<CS20)|(1<<CS21)|(1<<CS22);
	TIMSK2 |=(1<<OCIE2A);
	OCR2A = 77;//2*1024*(1+38)/8000000=0.01
}

ISR (TIMER2_COMPA_vect){
	if(cnt1) cnt1--;
	//flagEnc=1;
	//flagKey = 1;
}
uint8_t e,d,s;

int main(void)
{		cli();
	I2C_Init();
    LCD_I2C_Init();
	//LCD_String("Hello World");
	//LCD_Command(0xC0);
	LCD_I2C_Char(0x35);
	DDRC|=(1<<5);
	//PORTC&=~(1<<5);
	timer2_init();
	aaa = 0;
	uint8_t a0,a1,a2,a3,a4,a5,a6,a7,h0,h1,h0_,h1_;
	sei();

    while (1) 
    {
		LCD_I2C_Cmd(0x80|0x00);//cursor is in position 0, (0 - F)
		//increasing the number by one
		if(cnt1==0){
			aaa++;
			e=0;d=0;s=0;
			if(aaa>250) aaa=0;//count up to 250
			e=(aaa%100)%10;// select  single digit
			d=(aaa/10)%10;//select  decimal digit
			s=aaa/100;//select  hundred digit
			a7=(aaa&128)>>7;a6=(aaa&64)>>6;a5=(aaa&32)>>5;a4=(aaa&16)>>4;a3=(aaa&8)>>3;a2=(aaa&4)>>2;a1=(aaa&2)>>1;a0=(aaa&1)>>0;
			h1=aaa/16;h0=aaa%16;
			(h1<10) ? (h1_=0x30|h1) : (h1_=0x40|(h1-9));
			(h0<10) ? (h0_=0x30|h0) : (h0_=0x40|(h0-9));
			LCD_I2C_Clear();
			LCD_I2C_Char(0x30|a7);LCD_I2C_Char(0x30|a6);LCD_I2C_Char(0x30|a5);LCD_I2C_Char(0x30|a4);LCD_I2C_Char(0x30|a3);LCD_I2C_Char(0x30|a2);LCD_I2C_Char(0x30|a1);LCD_I2C_Char(0x30|a0);
			LCD_I2C_Cmd((9 & 0x0F)|0x80);
			LCD_I2C_Char(0x30|s);LCD_I2C_Char(0x30|d);LCD_I2C_Char(0x30|e);
			LCD_I2C_Cmd((13 & 0x0F)|0x80);
			LCD_I2C_Char(h1_);LCD_I2C_Char(h0_);
			cnt1=100;//wait 1s
		}
    }
}

