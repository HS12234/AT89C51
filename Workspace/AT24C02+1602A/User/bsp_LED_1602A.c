#include "bsp_LED_1602A.h"

/******************四位总线 1206A***********/

extern void I2C_Start( void );
extern void I2C_Stop( void );
extern char I2C_SendByte (char dat);

      
/************************** 输入字符 **************************/
void led_Show(int y,int x,char *show)//先输入行再输入列
{
            char addr;
            addr=0x80+0x40*y+x;
            send_command(addr);
            while(*show)
            {
                        Send_tybe(*show++);
            }
}

/************************** LED初始化 **************************/
void init_lcd(void)
{
            send_command(0x32);
            send_command(0x28);
            send_command(0x0C);
            send_command(0x06);
            send_command(0x01);
}

/************************** 发送命令 **************************/
void send_command(char tybe)
{
            char tmp;
            I2C_Start();
            I2C_SendByte(0x7e);
/************************** 发送前四位 **************************/
            tmp = tybe & 0xF0;
            tmp |= 0x0C;	//RS = 0, RW = 0, EN = 1
            I2C_SendByte(tmp);
            Delay_1ms(1);
            tmp &= 0xFB;	//Make EN = 0
            I2C_SendByte(tmp); 
/************************** 发送后四位 **************************/
            tmp = (tybe & 0x0F) << 4	 ;
            tmp |= 0x0C; 	 //RS = 0, RW = 0, EN = 1
            I2C_SendByte(tmp); 
            Delay_1ms(1);
            tmp &= 0xFB;	// Make EN = 0
            I2C_SendByte(tmp); 
            I2C_Stop();
}

/************************** 发送数据 **************************/
void Send_tybe(char tybe)
{
            char tmp;
            I2C_Start();
            I2C_SendByte(0x7e);
/************************** 发送前四位 **************************/
            tmp = tybe & 0xF0;
            tmp |= 0x0D;	//RS =1, RW = 0, EN = 1
            I2C_SendByte(tmp);
            Delay_1ms(1);
            tmp &= 0xFB;	//Make EN = 0
            I2C_SendByte(tmp); 
/************************** 发送后四位 **************************/
            tmp = (tybe & 0x0F) << 4	 ;
            tmp |= 0x0D; 	 //RS =1, RW = 0, EN = 1
            I2C_SendByte(tmp); 
            Delay_1ms(1);
            tmp &= 0xFB;	// Make EN = 0
            I2C_SendByte(tmp); 
            I2C_Stop();
}

void Delay_1ms(char t)   //误差 -0.651041666667us
{
            unsigned char a,b,i;
            for(i=0;t>i;i++)
            {
            for(b=102;b>0;b--)
            for(a=3;a>0;a--);
            }
}