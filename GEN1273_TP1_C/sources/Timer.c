/*
 * Timer.c
 *
 * Created: 2015-09-26 12:30:04
 *  Author: remy mourard
 */ 
//#include "headers/Timer.h"
#ifndef DBG
#define DBG 0
#endif

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>

static int milliCount = 0;

void setPrescaler()
{
    // Prescaler a 8 + mode CTC
    TCCR1B &= ~(0 << WGM13);
    TCCR1B |= (1 << WGM12);
	TCCR1B &= ~(0 << CS12);
    TCCR1B |= (1 << CS11);
    TCCR1B &= ~(0 << CS10);
    
#if DBG
    printf("TCCR1B content : %#x\n", TCCR1B);
#endif
}

void setOCR(int highVal, int lowVal)
{
	OCR1AH = highVal;
	OCR1AL = lowVal;
    
#if DBG
    printf("OCR1A content : %#x %#x\n", OCR1AH, OCR1AL);
#endif    
}

void enableInteruptOnMatchA()
{
	TIMSK1 |= (1 << OCIE1A);

#if DBG
    printf("TIMSK1 content : %#x\n", TIMSK1);
#endif
}

ISR(TIMER1_COMPA_vect)
{
	++milliCount;
}

int getMilliCount()
{
	return milliCount;
}

void resetMilliCount()
{
    milliCount = 0;
}
