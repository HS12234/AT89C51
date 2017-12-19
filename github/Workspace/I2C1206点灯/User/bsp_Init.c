#include "bsp_Init.h"

extern char SendByte (char dat);
extern void Start( void );
extern void Stop ( void );
extern void delay_10us ( void );


void Init(void)
{
            /*          串口初始化            */
            TMOD=0x20;  
            TL1 = 0xFD;       //设定定时初值
            TH1 = 0xFD;       //设定定时器重装值
            PCON=0x00;
            TR1=1;
            SCON=0x50;
            EA=1;
            ES=1;
}




