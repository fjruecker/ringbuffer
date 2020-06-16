#ifndef UART_H
#define UART_H

void RingbufferInit(void);
char SendSerialData(char * pSerialData, unsigned char len);

#endif /* UART_H */