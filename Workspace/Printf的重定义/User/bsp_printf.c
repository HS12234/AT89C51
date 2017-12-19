#include "bsp_printf.h"

void _printf(char *str,int num) 
{           
            char *a;//用来保存终止时str的地址
            char NUM[10];//定义一个10位的字符串数组，用来保存num的值
            int i;
      
/***********利用指针，只要字符串不为空，就 while 循环下去就利用指针指向数组的性质，***********/
/************（str+1）指向字符串数组的下一位，一位一位向下发送指针指向字符的ASCII码***********/
            Init();//初始化
            for(i=0;i<1000;i++);
            while(*str) 
            {
                        if(*str=='%'&&*(str+1)=='d')//用来判定“%d”如果字符串中出现
                        {
                                    a=str+2;
                                    sprintf(NUM,"%d",num);// 把num写入NUM中
                                    _printf(NUM,0);//输出字符串NUM
                                    str=a;//将a保存的地址赋给str，使得循环继续下去
                        }
                        else  
                        {
                                    SBUF=*str++;  //发送当前位的字符的ASCII码并让指针指向下一位
                                    while(TI==0);//判断是否发送完成，发送完成后硬件置1
                                    TI=0;//置0，等待下次发送
                                    delay_ms(100);//延时一段时间
                        }
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
void Init(void)
{
            /*          串口初始化            */
            TMOD=0x20;        //使用定时工作方式2
/******************波特率为9600***********************/      
            TL1 = 0xFD;       //设定定时初值
            TH1 = 0xFD;       //设定定时器重装值
            PCON=0x00;        //波特率不倍速

            SCON=0x50;        //设置串口通信方式1
      
            EA=1;
            ES=1;
            TR1=1;            //打开定时器中断
}

//void Usart() interrupt 4  //串口收发中断
//{
//}