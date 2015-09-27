/*
 * Usart.c
 *
 * Created: 2015-09-26 12:29:13
 *  Author: remy mourard
 */

#ifndef BAUD
#define BAUD 9600
#endif

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <util/setbaud.h>
#include <avr/io.h>
#include <stdio.h>

void USART0Init()
{
	// vitesse du usart
	UBRR0H = UBRRH_VALUE;
	UBRR0L = UBRRL_VALUE;
	
	// double speed operation en mode async
	#if USE_2X
		UCSR0A |= _BV(U2X0);
	#else
		UCSR0A &= ~(_BV(U2X0));
	#endif
	
	//enable Tx et Rx
	UCSR0B |= (1 << TXEN0) | (1 << RXEN0);
	
	// taille des donnees, un octet
	UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);
}


void USART0PutChar(char c, FILE* stream)
{
	// attendre que le USART soit pres a transmettre
	// bit UDRE0 du registre UCSR0A doit etre egal a 1
	// la macro loop_until est definie dans avr/sfr_defs.h
	loop_until_bit_is_set(UCSR0A, UDRE0);
	
	// transmitter pret, on peut initialiser le registre
	UDR0 = c;
}


char USART0ReadChar(FILE* stream)
{
	// atendre que le byte soit complement recu
	// pour cela, le bit RXC0 doit etre a 1 dans le registre UCSR0A
	loop_until_bit_is_set(UCSR0A, RXC0);
	
	return UDR0;
}