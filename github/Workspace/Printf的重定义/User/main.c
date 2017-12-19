#include <reg51.h>      //51单片机头文件
#include <stdio.h>      //c库头文件
#include "bsp_printf.h" //printf头文件


int main()
{
            _printf("%d",10000);
//            _printf("hello!! world!!%d&&",10000);
            while(1);
}