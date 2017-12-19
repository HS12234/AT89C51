#ifndef _BSP_LED_1602A_H
#define _BSP_LED_1602A_H

#include "reg51.h"

void LED_Write(void);
void led_Show(int y,int x,char *show);
void init_lcd(void);
void send_command(char tybe);
void Send_tybe(char tybe);
void delay1ms(char t);
      
      
#endif /*_BSP_LED_1602A_H*/