#include "motory.h"

void tim2Init(void)
{
    TIM2_TimeBaseInit(TIM2_PRESCALER_8, 39999);
    TIM2_Cmd(ENABLE);
}

void PWMInit(void)
{
    TIM2_OC1Init(TIM2_OCMODE_PWM1, TIM2_OUTPUTSTATE_ENABLE, 0, TIM2_OCPOLARITY_HIGH); // PD4
    TIM2_OC2Init(TIM2_OCMODE_PWM1, TIM2_OUTPUTSTATE_ENABLE, 0, TIM2_OCPOLARITY_HIGH); // PD3
    TIM2_OC1PreloadConfig(ENABLE);
    TIM2_OC2PreloadConfig(ENABLE);
}

void forward100(void)
{
    TIM2_SetCompare1(39999); //MR-1
    GPIO_WriteLow(GPIOB, GPIO_PIN_4); // MR-2
    TIM2_SetCompare2(39999); // ML-1
    GPIO_WriteLow(GPIOB, GPIO_PIN_2); // ML-2
}

void backwards100(void)
{
    TIM2_SetCompare1(0); //MR-1
    GPIO_WriteHigh(GPIOB, GPIO_PIN_4); // MR-2
    TIM2_SetCompare2(0); // ML-1
    GPIO_WriteHigh(GPIOB, GPIO_PIN_2); // ML-2
}

void stop(void)
{
    TIM2_SetCompare1(0); //MR-1
    GPIO_WriteLow(GPIOB, GPIO_PIN_4); // MR-2
    TIM2_SetCompare2(0); // ML-1
    GPIO_WriteLow(GPIOB, GPIO_PIN_2); // ML-2
}

void forward25(void)
{
    TIM2_SetCompare1(10000); //MR-1
    GPIO_WriteLow(GPIOB, GPIO_PIN_4); // MR-2
    TIM2_SetCompare2(10000); // ML-1
    GPIO_WriteLow(GPIOB, GPIO_PIN_2); // ML-2
}

void L100(void)
{
    TIM2_SetCompare1(0); //MR-1
    GPIO_WriteLow(GPIOB, GPIO_PIN_4); // MR-2
    TIM2_SetCompare2(39999); // ML-1
    GPIO_WriteLow(GPIOB, GPIO_PIN_2); // ML-2
}

void R100(void)
{
    TIM2_SetCompare1(39999); //MR-1
    GPIO_WriteLow(GPIOB, GPIO_PIN_4); // MR-2
    TIM2_SetCompare2(0); // ML-1
    GPIO_WriteLow(GPIOB, GPIO_PIN_2); // ML-2
}