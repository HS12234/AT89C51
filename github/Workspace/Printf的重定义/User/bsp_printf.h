#ifndef _BSP_PRINTF_H
#define _BSP_PRINTF_H

#include <reg51.h>
#include <stdio.h>

void Init(void);
void _printf(char *str,int num);
void delay_ms (int t);

#endif // _BSP_PRINTF_H
