#include "stm8s.h"

void main(void)
{
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1); // FREQ MCU 16MHz
    GPIO_Init(GPIOC, GPIO_PIN_5, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(GPIOE, GPIO_PIN_4, GPIO_MODE_IN_PU_NO_IT);

    while (1)
    {
        if (GPIO_ReadInputPin(GPIOE, GPIO_PIN_4)) // Infra-červený senzor nedetekuje objekt
        {
            GPIO_WriteLow(GPIOC, GPIO_PIN_5);
        }

        else if (!GPIO_ReadInputPin(GPIOE, GPIO_PIN_4))  // Infra-červený senzor detekuje objekt
        {
            GPIO_WriteHigh(GPIOC, GPIO_PIN_5);
        }    
    }
}

