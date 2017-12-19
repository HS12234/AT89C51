/*接收程序*/
#include<reg51.h>

typedef unsigned char u8;
u8 pf;

void Init() 
{
            IE=0xff;
            /*          串口初始化            */
            TMOD=0x20;  
            TH1=0xf3;
            TL1=0xf3;
            PCON=0x80;
            TR1=1;
            SCON=0x50;

            /*          外部中断0初始化          */
            IT0=1;
}


void main()    
{
            Init();
            while(1)
}

void usart() interrupt 4
{
            u8 receiveDate;
            receiveDate=SBUF;
            RI=0;
            SBUF=receiveDate;
            while (!TI);
            TI=0;
}

u8 scan(void)
{
}