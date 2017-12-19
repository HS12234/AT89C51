#include "bsp_key.h "

int key_press(void)                     //捕获按键函数
{
       char key=0xff;
       int i=0;
       if(P2!=0xff)
       {
              delay(1);
              if(P2!=0xff)
              {
                     key=P2;
                     while((i<20)&&(P2!=0xff))
                     {
                            i++;
                            delay(1);
                     }
              }
       }
       return key;
}

void key_control(char key)                      //控制按键不同状态对应的不同情况
{
        switch (key)
        {
                case (0xfe):                                    //移位
                {
                        yiwei();
                };
                break;
                
                case (0xfd):                                    //闪烁
                {
                flag=~flag;
                if(flag!=0)                                     //关闭定时器中断
                {
                        TR1=0;
                }
                if (flag==0)                                    //开启定时器中断
                {
                        TR1=1;
                }
                }
                break;
                
                case (0xfb):                                    //加
                if(flag !=0)
                {
                        jia();
                };break;
                
                case (0xf7):                            //减
                if(flag !=0)
                {
                        jian();
                };break;
        }
}

void delay(int t)               //延迟函数
{
       int i,j;
       for(i=t;i>0;i--)
       for(j=1000;j>0;j--);
}




