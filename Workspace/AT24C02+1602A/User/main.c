#include <reg51.h>
#include <stdio.h>
#include "bsp_I2C.h"
#include "bsp_LED_1602A.h"
#include "bsp_AT24C02.h"

int main()    
{           
            int num=0;
            char NUM[10];
            init_lcd();

            AT24C02_Write (1,100);
            Delay_1ms(1);
            num=AT24C02_Read(1);
            sprintf(NUM,"%d",num);
            
            led_Show(0,0,"AT24C02 NUM =");
            led_Show(1,3,NUM);
            while(1);
}

