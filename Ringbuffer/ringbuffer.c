#include "ringbuffer.h"
#include <avr/io.h>

#define RINGBUFFERSIZE 17

unsigned char ringbuffer[RINGBUFFERSIZE];
unsigned char writeIndex, readIndex;

void RingbufferInit(void)
{
	writeIndex = 0;
	readIndex = 0;
}

char SendSerialData(char * pSerialData,
					unsigned char len)
{
	int freeSize;
	if(writeIndex >= readIndex) {
		freeSize = RINGBUFFERSIZE - (writeIndex - readIndex) - 1;
	}
	else {
		freeSize = readIndex - writeIndex - 1;
	}
	
	if(freeSize < len) {
		return 0;
	}
	
	for(int i=0; i<len; i++) {
		ringbuffer[writeIndex] = pSerialData[i];
		writeIndex ++;
		if(writeIndex >= RINGBUFFERSIZE) {
			writeIndex = 0;
		}
	}
	
	UCSR0B |= (1 << UDRIE0);
	return 1;
}

ISR (USART0_UDRE_vect)
{
	if(readIndex == writeIndex) {
		UCSR0B &= ~(1 << UDRIE0);
		return;
	}
	UDR0 = ringbuffer[readIndex];
	readIndex++;
	if(readIndex >= RINGBUFFERSIZE) {
		readIndex = 0;
	}
}
