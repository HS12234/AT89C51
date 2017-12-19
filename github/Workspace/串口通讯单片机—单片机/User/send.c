#include<reg51.h>

u8  receiveData=0;

sbit led=P1^4;
sbit key=P1^0;
sbit key1=P1^3;
void Init() 
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

void main()    
{
int i;
      u8 keyvalue;
            Init();
            while(1)
            {
                        if(key==1)
                        {
                                    if(key1==0)
                                    {
                                                for(i=0;i<1000;i++);
                                                if(key1==0)
                                                {
                                                            keyvalue=P1;
                                                            while(key1==0);
                                                            SBUF = keyvalue;
                                                            if(!T1);
                                                            T1=0;
                                                }

                                    }
                        }
            }
}

void Usart() interrupt 4
{
            
            receiveData =SBUF;
            if(receiveData==0xf7)
            {
                        if(key==0)
                        {led=~led;}
            }
            RI=0; 
            
}



