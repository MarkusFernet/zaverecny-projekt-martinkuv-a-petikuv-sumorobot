#include "motory.h"

void tim2Init(void)
{
    TIM2_TimeBaseInit(TIM2_PRESCALER_8, 39999);
    TIM2_Cmd(ENABLE);
}

void PWMInit(void)
{
    TIM2_OC1Init(TIM2_OCMODE_PWM1, TIM2_OUTPUTSTATE_ENABLE, 4000, TIM2_OCPOLARITY_HIGH); // PD4
    TIM2_OC2Init(TIM2_OCMODE_PWM1, TIM2_OUTPUTSTATE_ENABLE, 4000, TIM2_OCPOLARITY_HIGH); // PD3
    TIM2_OC1PreloadConfig(ENABLE);
    TIM2_OC2PreloadConfig(ENABLE);
}

void forward100(void)
{
    TIM2_SetCompare1(39999);
    GPIO_WriteLow(GPIOB, GPIO_PIN_4); // M1-2
    TIM2_SetCompare2(39999);
    GPIO_WriteLow(GPIOB, GPIO_PIN_2); // M2-2
}

void backwards100(void)
{
    TIM2_SetCompare1(0);
    GPIO_WriteHigh(GPIOB, GPIO_PIN_4); // M1-2
    TIM2_SetCompare2(0);
    GPIO_WriteHigh(GPIOB, GPIO_PIN_2); // M2-2
}

void stop(void)
{
    TIM2_SetCompare1(0);
    GPIO_WriteLow(GPIOB, GPIO_PIN_4); // M1-2
    TIM2_SetCompare2(0);
    GPIO_WriteLow(GPIOB, GPIO_PIN_2); // M2-2
}

void forward25(void)
{
    TIM2_SetCompare1(10000);
    GPIO_WriteLow(GPIOB, GPIO_PIN_4); // M1-2
    TIM2_SetCompare2(10000);
    GPIO_WriteLow(GPIOB, GPIO_PIN_2); // M2-2
}