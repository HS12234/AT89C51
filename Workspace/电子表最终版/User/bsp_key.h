#ifndef __BSP_KEY_H
#define __BSP_KEY_H

#include "reg51.h"

extern char flag;

int key_press(void);

void key_control(char key);

void delay(int t) ;

#endif /*__BSP_KEY_H*/


