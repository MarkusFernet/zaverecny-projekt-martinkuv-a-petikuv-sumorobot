#ifndef INC_UART_H
#define INC_UART_H

#include "stm8s.h"
void uart1Init(void);
void sendChar(char c);
void sendStr(char str[]);
char getChar(void);
#endif