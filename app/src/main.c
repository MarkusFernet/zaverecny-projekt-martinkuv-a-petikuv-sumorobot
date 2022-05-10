#include "stm8s.h"

void usDelay(uint32_t uSec)
{
}

void main(void)
{
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1); // FREQ MCU 16MHz
    GPIO_Init(GPIOC, GPIO_PIN_5, GPIO_MODE_OUT_PP_LOW_SLOW);

    while (1)
    {
        usDelay(10);
        while (1)
        {
        TIM3_TimeBaseInit(TIM3_PRESCALER_256, 62499);
        TIM3_Cmd(ENABLE);
        while (TIM3_GetFlagStatus(TIM3_FLAG_UPDATE) != SET);
        TIM3_ClearFlag(TIM3_FLAG_UPDATE);
        GPIO_WriteReverse(GPIOC, GPIO_PIN_5);
        }
    }
}
