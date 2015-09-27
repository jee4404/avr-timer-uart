/*
 * Timer.h
 *
 * Created: 2015-09-26 12:29:51
 *  Author: remy mourard
 */ 
#ifndef TIMER_H_
#define TIMER_H_

#include <avr/interrupt.h>

/**
 * set le prescaler du timer
 **/
void setPrescaler();

/**
 * set l'output compare register (16 bits)
 **/
void setOCR(int highVal, int lowVal);

/**
 * active les interruptions sur 
 * un "Match A"
 **/
void enableInteruptOnMatchA();

/**
 * procedure pour traiter l'interruption
 **/
ISR(TIMER1_COMPA_vect);

/**
 * retourne le nombre de ms echues
 **/
int getMilliCount();

void resetMilliCount();

#endif /* TIMER_H_ */