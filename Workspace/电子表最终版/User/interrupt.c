#include "interrupt.h"
#include "bsp_key.h"
void INT0_Handler() interrupt 0         //外部中断
{
       key_control(key_press());
}

void TIM0_Handler() interrupt 3         //定时器中断
{
        TR1=0;
        TH1 = 0x0b;
        TL1 = 0xdc;                     //装载初值
        TR1=1;
        a++;
        if(a >= 16)                     //满一秒钟
        {
                a = 0;
                num=5;
                jia();
        }
}