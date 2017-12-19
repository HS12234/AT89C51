/************************** I2C 通信头文件 **************************/
#ifndef _BSP_I2C_H
#define _BSP_I2C_H

#include "reg51.h"

void I2C_Start( void );
void I2C_Stop( void );
char I2C_SendByte (char dat);
void delay_10us(void);    // 延时10us
char I2C_ReciverByte (void);

sbit SCL=P1^0;
sbit SDA=P1^1;

#endif /*__BSP_MESSAGE_H*/