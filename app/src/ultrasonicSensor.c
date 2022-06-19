#include "ultrasonicSensor.h"

void tim3Init(void)
{
    TIM3_TimeBaseInit(TIM3_PRESCALER_4, 39999);
    TIM3_Cmd(ENABLE);
}

void tim3Reset(void)
{
    TIM3_ClearFlag(TIM3_FLAG_UPDATE);
    TIM3_SetCounter(0);
}

void sendTrig(void)
{
    msDelay(100);
    GPIO_WriteHigh(GPIOD, GPIO_PIN_5);
    msDelay(10);
    GPIO_WriteLow(GPIOD, GPIO_PIN_5);
}

float tim3DistanceCalculation(uint16_t tim3Value)
{
    uint16_t echoTime = tim3Value / 4; // in us (microseconds)
    return ((echoTime*0.034)/2);
}

float sendDistanceToPutty(uint16_t tim3Value)
{   
    float distance = tim3DistanceCalculation(tim3Value);
    uint16_t strD = distance;
    sendStr(intToStrConvert(strD)); 
    sendStr("\n\r");
    return distance;
}