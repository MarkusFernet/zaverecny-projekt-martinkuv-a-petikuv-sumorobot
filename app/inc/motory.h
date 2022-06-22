#ifndef INC_MOTORY_H
#define INC_MOTORY_H

#include "stm8s.h"
//#include "uart.h"
//#include "intToStrConvert.h"
//#include "delay.h"
// void tim3Init(void);
// void tim3Reset(void);
// void sendTrig(void);
// float tim3DistanceCalculation(uint16_t tim3Value);
// float sendDistanceToPutty(uint16_t tim3Value);

void tim2Init(void);
void PWMInit(void);
void forward100(void);
void backwards100(void);
void stop(void);
void forward25(void);
void L100(void);
void R100(void);

#endif