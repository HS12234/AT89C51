#include<reg51.h>
#include <intrins.h>
#include "bsp_I2C.h"
#include "bsp_LED_1602A.h"


int main()    
{
            init_lcd();
            led_Show(0,0,"LYX is SB!!");
            led_Show(1,3,"Thank you!!!");
            while(1);
}