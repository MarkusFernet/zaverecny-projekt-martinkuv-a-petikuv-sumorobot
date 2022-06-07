#include "delay.h"

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
    for(int ms = 0; ms < time_ms; ms++) // jeden cyklus = 1ms
    {
        while(TIM4_GetFlagStatus(TIM4_FLAG_UPDATE) != SET);
        TIM4_ClearFlag(TIM4_FLAG_UPDATE);
    }
}