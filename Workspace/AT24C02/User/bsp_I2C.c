#include "bsp_I2C.h"

void delay_10us(void)    // 延时10us
{
    unsigned char a;
    for(a=3;a>0;a--);
}

/************************** 起始信号 **************************/
void I2C_Start(void)
{
            SCL=1;
            delay_10us();
            SDA=1;
            delay_10us();
            SDA=0;
            delay_10us();
            SCL=0;
            delay_10us();
}   

/************************** 结束信号 **************************/
void I2C_Stop(void)
{
            SDA=0;
            delay_10us();
            SCL=1;
            delay_10us();
            SDA=1;
            delay_10us();
            SDA=0;
            delay_10us();
}
/************************** 发送字节 **************************/
char I2C_SendByte (char dat)
{
            u8 a,b;
            for(a=0;a<8;a++)
            {
                        if((dat<<a)&0x80) SDA=1; 
                        else SDA=0;                   //从最高位开始传输
                        delay_10us();
                        SCL=1;
                        delay_10us();           //等待接收
                        SCL=0;    
                        delay_10us();
            }
            /* 八位数据发送完成 */
            SDA=1;
            SCL=1;
            while(SDA)
            {
                        b++;
                        if(b>200)
                        {
                                    SCL=0;
                                    delay_10us();
                                    return 0;  //返回0表示通信失败
                        }
            }
            SCL=0;
            delay_10us();
            return 1;//通信成功
}

/************************** 接收字节 **************************/
char I2C_ReciverByte (void)
{
            u8 a=0,dat=0;
            for(a=0;a<8;a++)
            {
                        SCL=1;
                        delay_10us();
                        dat=dat<<1;
                        dat=SDA|dat;
                        delay_10us();
                        SCL=0;
                        delay_10us();
            }
            return dat;
}
