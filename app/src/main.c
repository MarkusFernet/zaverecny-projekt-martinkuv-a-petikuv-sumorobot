#include "stm8s.h"
void tim4Init(void)
{
    TIM4_TimeBaseInit(TIM4_PRESCALER_64, 249);
    TIM4_Cmd(ENABLE);
}

void tim4Reset(void)
{
    TIM4_SetCounter(0);
}

void msDelay(uint32_t time_ms)
{
    
    tim4Reset();
    for(int ms = 0; ms < time_ms; ms++)
    {
        while(TIM4_GetFlagStatus(TIM4_FLAG_UPDATE) != SET);
        TIM4_ClearFlag(TIM4_FLAG_UPDATE);
    }
}

void main(void)
{
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1); // FREQ MCU 16MHz
    GPIO_Init(GPIOC, GPIO_PIN_5, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(GPIOD, GPIO_PIN_1, GPIO_MODE_OUT_PP_LOW_SLOW);
    tim4Init();
    while (1)
    {
        msDelay(100);
        GPIO_WriteHigh(GPIOC, GPIO_PIN_5);
        GPIO_WriteHigh(GPIOD, GPIO_PIN_1);
        msDelay(100);
        GPIO_WriteLow(GPIOC, GPIO_PIN_5);
        GPIO_WriteLow(GPIOD, GPIO_PIN_1);
    }
}

