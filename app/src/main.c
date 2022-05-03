#include "stm8s.h"

void main(void)
{
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1); // FREQ MCU 16MHz
    GPIO_Init(GPIOC, GPIO_PIN_5, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(GPIOB, GPIO_PIN_5, GPIO_MODE_IN_FL_NO_IT);

    while (1)
    {
        if (GPIO_ReadInputPin(GPIOB, GPIO_PIN_5)==1)
        {
            GPIO_WriteLow(GPIOC, GPIO_PIN_5);
            for (uint32_t i = 0; i < 1000000; i++)
            ;
        }

        else if (GPIO_ReadInputPin(GPIOB, GPIO_PIN_5)==0)
        {
            GPIO_WriteHigh(GPIOC, GPIO_PIN_5);
            for (uint32_t i = 0; i < 1000000; i++)
            ;
        }    


        //while (GPIO_ReadInputPin(GPIOB, GPIO_PIN_5)==0){}
        //if (GPIO_ReadInputPin(GPIOB, GPIO_PIN_5)==0)
        //{
        //    GPIO_WriteLow(GPIOC, GPIO_PIN_5);
        //}
        //if (GPIO_ReadInputPin(GPIOB, GPIO_PIN_5)==1)
        //{
        //    GPIO_WriteHigh(GPIOC, GPIO_PIN_5);
        //}
        
        //GPIO_WriteReverse(GPIOC, GPIO_PIN_5);
        //for (uint32_t i = 0; i < 100000; i++)
        //    ;
    }
}

