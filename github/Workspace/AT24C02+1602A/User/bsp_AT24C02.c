#include "bsp_AT24C02.h"

void AT24C02_Write(char addr,char date)
{
            I2C_Start();
            I2C_SendByte (0xa0);
            I2C_SendByte (addr);
            I2C_SendByte (date);
            I2C_Stop();
}

char AT24C02_Read(char addr)
{
            char dat;
            I2C_Start();
            I2C_SendByte (0xa0);
            I2C_SendByte (addr);
            I2C_Start();
            I2C_SendByte (0xa1);
            dat=I2C_ReciverByte ();
            I2C_Stop();
            return dat;
}


      