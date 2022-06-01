#include "stm8s.h"
#include "uart.h"
#include "ultrasonicSensor.h"
#include "intToStrConvert.h"
#include "delay.h"

//float distance;
int riseOrFall = 1;
//uint16_t integer;

INTERRUPT_HANDLER(EXTI_PORTD_IRQHandler, 6)
{
    if (riseOrFall) // spusti se jen pri nastupni hrane
    {
        tim3Reset();
        riseOrFall = 0;
        GPIO_WriteHigh(GPIOC, GPIO_PIN_5);
    }
    else if (!(riseOrFall)) // spusti se jen pri sestupni hrane
    {
        if (TIM3_GetFlagStatus(TIM3_FLAG_UPDATE) != SET) // citac nepretekl
        {
            sendDistanceToPutty(TIM3_GetCounter());
            //float distance = tim3DistanceCalculation(TIM3_GetCounter());
            //sendDistanceToPutty(distance);
        }
        else if (TIM3_GetFlagStatus(TIM3_FLAG_UPDATE) == SET) // cistac pretekl
        {
            sendStr("Vzdál\n\r");
        }
        riseOrFall = 1;
        GPIO_WriteLow(GPIOC, GPIO_PIN_5);
    }
    
}

//void sendTrig(void)
//{
//    GPIO_WriteHigh(GPIOD, GPIO_PIN_1);
//    //GPIO_WriteHigh(GPIOC, GPIO_PIN_5);
//    msDelay(10);
//    GPIO_WriteLow(GPIOD, GPIO_PIN_1);
//    //GPIO_WriteLow(GPIOC, GPIO_PIN_5);
//    msDelay(10);
//}

void main(void)
{
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1); // FREQ MCU 16MHz
    GPIO_Init(GPIOC, GPIO_PIN_5, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(GPIOC, GPIO_PIN_4, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(GPIOE, GPIO_PIN_1, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(GPIOE, GPIO_PIN_2, GPIO_MODE_OUT_PP_HIGH_SLOW);
    GPIO_Init(GPIOD, GPIO_PIN_6, GPIO_MODE_IN_FL_IT);
    
    uart1Init();
    tim4Init();
    tim3Init();

    // ultrasonic sensor interrupts 
    EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOD, EXTI_SENSITIVITY_RISE_FALL); // interrupts settup for port E
    ITC_SetSoftwarePriority(ITC_IRQ_PORTD, ITC_PRIORITYLEVEL_1);
    enableInterrupts();
    
    while (1)
    {
        //sendTrig();
        msDelay(200);
        GPIO_WriteHigh(GPIOC, GPIO_PIN_4);
        GPIO_WriteHigh(GPIOE, GPIO_PIN_2);
        msDelay(10);
        GPIO_WriteLow(GPIOC, GPIO_PIN_4);
        GPIO_WriteLow(GPIOE, GPIO_PIN_2);
        
    }
}