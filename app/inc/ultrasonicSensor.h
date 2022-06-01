#ifndef INC_ULTRASONICSENSOR_H
#define INC_ULTRASONICSENSOR_H

#include "stm8s.h"
#include "uart.h"
#include "intToStrConvert.h"
void tim3Init(void);
void tim3Reset(void);
float tim3DistanceCalculation(uint16_t tim3Value);
void sendDistanceToPutty(uint16_t tim3Value);
#endif