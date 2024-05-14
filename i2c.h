
#ifndef I2C_H_
#define I2C_H_

#include "main.h"

 void I2C_Init(void);
 void I2C_Start(void);
 void I2C_Stop(void);
 void I2C_SendByte(uint8_t c);


#endif /* I2C_H_ */