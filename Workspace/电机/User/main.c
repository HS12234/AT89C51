#include<reg51.h> 
#define u8 unsigned char

void Init(void);
void key_control(void);
void delay_ms(int i);
void limit(void);
u8 time=0;
u8 SegCode[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
u8 key[2]={0xfe,0xfd};
char show[2]={5,0}; 

sbit KEY=P2^5;
sbit key1=P2^1;
sbit key2=P2^2;
sbit key3=P2^3;
sbit key4=P2^4;
sbit MA=P2^0;
sbit MB=P2^7;

void Init(void)
{
            IT0=1;
            IE=0x9f;
            TMOD=0x20;
            TH0=0xFe;
            TL0=0xFe;
            TR0=1;
}

void main()
{
            u8 i;
            u8 dutyCycle=0;
            Init();                  
            while(1)
            {

                        dutyCycle=show[0]*10+show[1];
                        for(i=0;i<2;i++)
                        {
                                    P1=key[i];
                                    P0=SegCode[show[i]];
                                    delay_ms(1);
                        }
                        if(time==100)
                        {
                                    time=0;
                        }
                        if(dutyCycle>time)
                        {
                                    KEY=1;
                        }
                        else KEY=0;
                        }
}

void INT0_Handler() interrupt 0
{
            key_control();
}

void TIM0_Handler() interrupt 1
{
            time=time+1;
}

void key_control(void)         
{
             if(key1==0)
            {
                        delay_ms(1);
                        if(key1==0)
                        { 
                                    while(key1==0);
                                    MA=~MA;
                               
                        }
            }
            if(key2==0)
            {
                        delay_ms(1);
                        if(key2==0)
                        {
                                    while (key2==0);
                                    if(MA!=MB)
                                    {
                                                MA=~MA;
                                                MB=~MB;
                                    }
                        }
            }
            if(key3==0)
            {
                        delay_ms(1);
                        if(key3==0)
                        {
                                    while(key3==0);
                                    if(show[1]<7||show[0]<9)
                                    {
                                                show[1]=show[1]+3;
                                    }
                                    limit();
                        }
            }
            
            if(key4==0)
            {
                        delay_ms(1);
                        if(key4==0)
                        {
                              while(key4==0);
                              if( show[1]>=5|| show[0]>0)
                              {
                                          show[1]=show[1]-5;
                              }
                              limit();
                        }
            }
}

void limit()
{           
            if(show[1]>=10)
            {
                        show[1]=show[1]-10;
                        show[0]=show[0]+1;
            }

            if(show[1]<0)
            {
                        show[1]=show[1]+10;
                        show[0]=show[0]-1;
            }
}



void delay_ms (int t)
{
            int i,j;
            for(i=t;i>0;i--)
            {
                        for(j=1000;j>0;j--);
            }
}