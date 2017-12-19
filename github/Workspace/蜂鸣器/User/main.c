#include<reg51.h>
void Init(void);
u8 time=0;
sbit key=P1^5;
int main()    
{
            Init();
            while(1)
            {

            }
}

void Init (void)
{
            IE=0xff;
            TMOD=0x20;
            TL0=0x38;
            TH0=0x38;
            TR0=1;
}

void TIM0_Handler() interrupt 1
{
            time=time+1;
                              if(time>5)
                        {
                              time=0;
                        }
                                    if(time<=3)
                                    {
                                                key=1;
                                    }
                                    else key=0;
}
