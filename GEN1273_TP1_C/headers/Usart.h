/*
 * IncFile1.h
 *
 * Created: 2015-09-26 12:28:04
 *  Author: remy mourard
 */ 
#ifndef USART0_H
#define USART0_H

#include <stdio.h>

/**
 * initiation du USART0 pour lire
 * les donnees utilisateurs et ecrire sur le terminal
 */
void USART0Init();

/*
 * Transmettre sur le USART
 */
void USART0PutChar(char c, FILE* stream);

/*
 * Recevoir sur le USART
 */
char USART0ReadChar(FILE* stream);

/*
 * flux pour E/S avec le terminal
 */
FILE usartIO = FDEV_SETUP_STREAM(USART0PutChar, USART0ReadChar, _FDEV_SETUP_RW);

#endif /* USART0_H */