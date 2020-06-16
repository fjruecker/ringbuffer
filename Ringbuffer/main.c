/*
 * Ringbuffer.c
 *
 * Created: 28.04.2020 13:42:22
 * Author : Florian Rücker
 */ 
#define F_CPU 16000000
#include "ringbuffer.h"
#include "uart.h"

#include <avr/io.h>
#include <util/delay.h>int main(void)
{
    UARTInit(103); // baud 9600
	RingbufferInit();
    while (1) 
    {
		SendSerialData("Hello World!", 12);
		_delay_ms(100);
    }
}

