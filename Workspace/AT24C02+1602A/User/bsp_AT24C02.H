#ifndef _BSP_AT24C02_H
#define _BSP_AT24C02_H

#include "reg51.h"
#include "bsp_I2C.h"

void AT24C02_Write (char addr,char date);
char AT24C02_Read  (char addr);

#endif /*_BSP_AT24C02_H*/