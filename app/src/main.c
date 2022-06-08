#include "stm8s.h"
#include "uart.h"
#include "ultrasonicSensor.h"
#include "intToStrConvert.h"
#include "delay.h"

int riseFall = 1;
uint8_t distance;

INTERRUPT_HANDLER(EXTI_PORTD_IRQHandler, 6)
{
    if (riseFall) // spusti se jen pri nastupni hrane
    {
        tim3Reset();
        riseFall = 0;
        //GPIO_WriteHigh(GPIOC, GPIO_PIN_5);
    }
    else if (!(riseFall)) // spusti se jen pri sestupni hrane
    {
        if (TIM3_GetFlagStatus(TIM3_FLAG_UPDATE) != SET) // citac nepretekl
        {
            distance = sendDistanceToPutty(TIM3_GetCounter());
            if (distance<10)
            {
                GPIO_WriteHigh(GPIOB, GPIO_PIN_5); // M1-1
                GPIO_WriteHigh(GPIOB, GPIO_PIN_3); // M2-1
                GPIO_WriteLow(GPIOB, GPIO_PIN_2); // M2-2

                //GPIO_WriteHigh(GPIOC, GPIO_PIN_5);
            }
            else
            {
                GPIO_WriteLow(GPIOB, GPIO_PIN_5); // M1-1
                GPIO_WriteLow(GPIOB, GPIO_PIN_3); // M2-1

                //GPIO_WriteHigh(GPIOB, GPIO_PIN_5); // M1-1
                //GPIO_WriteLow(GPIOB, GPIO_PIN_3); // M2-1
                //GPIO_WriteHigh(GPIOB, GPIO_PIN_2); // M2-2

                //GPIO_WriteLow(GPIOC, GPIO_PIN_5);
            }
            
            
        }
        else if (TIM3_GetFlagStatus(TIM3_FLAG_UPDATE) == SET) // cistac pretekl
        {
            sendStr("Too far\n\r");
        }
        riseFall = 1;
        //GPIO_WriteLow(GPIOC, GPIO_PIN_5);
    }
    
}

INTERRUPT_HANDLER(EXTI_PORTC_IRQHandler, 6)
{
    if (GPIO_ReadInputPin(GPIOC, GPIO_PIN_6)) // Infra-červený senzor nedetekuje
    {
       GPIO_WriteLow(GPIOC, GPIO_PIN_5);
       //GPIO_WriteLow(GPIOB, GPIO_PIN_5); // M1-1
       //GPIO_WriteLow(GPIOB, GPIO_PIN_4); // M1-2
       //GPIO_WriteLow(GPIOB, GPIO_PIN_3); // M2-1
       //GPIO_WriteLow(GPIOB, GPIO_PIN_2); // M2-2
    }

    else if (!GPIO_ReadInputPin(GPIOC, GPIO_PIN_6))  // Infra-červený senzor detekuje bilou
    {
        GPIO_WriteHigh(GPIOC, GPIO_PIN_5);
        GPIO_WriteLow(GPIOB, GPIO_PIN_5); // M1-1
        GPIO_WriteLow(GPIOB, GPIO_PIN_4); // M1-2
        GPIO_WriteLow(GPIOB, GPIO_PIN_3); // M2-1
        GPIO_WriteLow(GPIOB, GPIO_PIN_2); // M2-2
        msDelay(1000);
    }    
}

void main(void)
{
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1); // FREQ MCU 16MHz
    GPIO_Init(GPIOC, GPIO_PIN_5, GPIO_MODE_OUT_PP_LOW_SLOW); // test-led
    GPIO_Init(GPIOD, GPIO_PIN_5, GPIO_MODE_OUT_PP_LOW_SLOW); // UZ-trig
    GPIO_Init(GPIOD, GPIO_PIN_6, GPIO_MODE_IN_FL_IT); // UZ-echo
    GPIO_Init(GPIOC, GPIO_PIN_1, GPIO_MODE_OUT_PP_HIGH_SLOW); // UZ-ucc
    GPIO_Init(GPIOB, GPIO_PIN_5, GPIO_MODE_OUT_PP_LOW_SLOW); // M1-1
    GPIO_Init(GPIOB, GPIO_PIN_4, GPIO_MODE_OUT_PP_LOW_SLOW); // M1-2
    GPIO_Init(GPIOB, GPIO_PIN_3, GPIO_MODE_OUT_PP_LOW_SLOW); // M2-1
    GPIO_Init(GPIOB, GPIO_PIN_2, GPIO_MODE_OUT_PP_LOW_SLOW); // M2-2
    GPIO_Init(GPIOC, GPIO_PIN_6, GPIO_MODE_IN_FL_IT); // IR-D0
    
    uart1Init();
    tim4Init();
    tim3Init();

    // ultrasonic sensor interrupts 
    EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOD, EXTI_SENSITIVITY_RISE_FALL); // interrupts settup for port D
    ITC_SetSoftwarePriority(ITC_IRQ_PORTD, ITC_PRIORITYLEVEL_0);

    EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOC, EXTI_SENSITIVITY_RISE_ONLY); // interrupts settup for port C
    ITC_SetSoftwarePriority(ITC_IRQ_PORTC, ITC_PRIORITYLEVEL_1);
    enableInterrupts();
    
    while (1)
    {
        sendTrig();
    }
}