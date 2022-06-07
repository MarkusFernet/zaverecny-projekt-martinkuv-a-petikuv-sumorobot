#include "uart.h"

void uart1Init(void)
{
    UART1_Init(
        9600, // rychlost
        UART1_WORDLENGTH_8D, // počet datových bitů
        UART1_STOPBITS_1, // stop bity
        UART1_PARITY_NO, // typ parity
        UART1_SYNCMODE_CLOCK_DISABLE, // synchonozační typ hodin
        UART1_MODE_TXRX_ENABLE // UART mode
    );

    UART1_Cmd(ENABLE);
}

void sendChar(char c)
{
    while (!UART1_GetFlagStatus(UART1_FLAG_TXE));
        UART1_SendData8(c);
}

void sendStr(char str[])
{
    for (uint32_t i=0; str[i]; i++)
        sendChar(str[i]);
}

char getChar(void)
{
    while (!UART1_GetFlagStatus(UART1_FLAG_RXNE));
    return UART1_ReceiveData8();
}