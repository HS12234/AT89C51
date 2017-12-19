#include <reg51.h>
#include "bsp_Init.h"

/***********************************************************************/

u8 receiveData;

int main()   
{
            Init();  //初始化
            while(1)
            {
                        P1 = receiveData;//将receiveData的值赋给P1；
            }

}

void Usart() interrupt 4  //串口收发中断
{
            /*          接收中断        */
            RI=0;           //置0，便于下一次的接收
            receiveData = SBUF;//将接收到的数据保存在 receiveData 中
            SBUF = receiveData;
            while(!TI);
            TI=0;
}