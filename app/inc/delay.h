#ifndef INC_DELAY_H
#define INC_DELAY_H

#include "stm8s.h"
void tim4Init(void);
void tim4Reset(void);
void msDelay(uint32_t time_ms);
#endif