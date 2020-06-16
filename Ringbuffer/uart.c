#include "uart.h"

#include <avr/io.h>
#include <avr/interrupt.h>

void UARTInit(unsigned int baud)
{
	UBRR0 = (unsigned char) baud;
	UCSR0B = (1 << RXEN0) | (1 << TXEN0);
	UCSR0C = (3 << UCSZ00);
	sei();
}
