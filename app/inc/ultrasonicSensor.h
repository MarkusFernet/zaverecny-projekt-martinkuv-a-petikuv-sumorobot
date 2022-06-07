#ifndef INC_ULTRASONICSENSOR_H
#define INC_ULTRASONICSENSOR_H

#include "stm8s.h"
#include "uart.h"
#include "intToStrConvert.h"
#include "delay.h"
void tim3Init(void);
void tim3Reset(void);
void sendTrig(void);
float tim3DistanceCalculation(uint16_t tim3Value);
float sendDistanceToPutty(uint16_t tim3Value);
#endif