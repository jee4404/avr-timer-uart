/*
    * GEN1273_TP1_C.c
    *
    * Created: 2015-09-26 13:22:49
    *  Author: remy mourard
    */ 
#define DBG 1

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "headers/Timer.h"
#include "headers/Usart.h"

int main(void)
{
    // init du USART 0 pour les communicatins serie
    USART0Init();
    
    // redirection stdin/out
    stdout = &usartIO;
    stdin  = &usartIO;

	// active les interruptions globales
	sei();
	
	// set le prescaler a 8
	setPrescaler();
	
	// set OCR a 2000 pour avoir une interruption
	// toutes les millisecondes (F = 16 MHz et prescaler a 8)
	setOCR(0x07, 0xD0);
	
	// active interrupt sur match A
    enableInteruptOnMatchA();
	
	char input;
	
    while(1)
    {
		printf("Utilisation du timer 1 dans ATMega 2560\n");
        printf("Menu\n");
        printf("1. Afficher\n");
        printf("2. Re-initialiser\n");
        
		input = getchar();

        if(input == '1')
        {
            printf("\nLa valeur du timer est de %d\n\n", getMilliCount());
        }
        else if(input == '2')
        {
            printf("\nCompteur re-initialise\n");
            resetMilliCount();
        }
    }
	return 0;
}