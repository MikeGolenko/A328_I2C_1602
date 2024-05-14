
#ifndef MAIN_H_
#define MAIN_H_

#define  F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "lcd1602.h"
#include "i2c.h"
#include "i2c1602.h"

volatile uint8_t cnt1;
volatile uint8_t aaa;




#endif /* MAIN_H_ */