/*
 * File:   timer.c
 * Author: 20185147
 *
 * Created on 16 de Junho de 2021, 16:41
 */


#include <xc.h>
#include "config.h"
#include "dispLCD4vias.h"
#include "delay.h"

unsigned int contador;
unsigned int t2seg;
unsigned int contador2;

void timer2_init (void)
{
    INTCONbits.GIE = 0;
    T2CONbits.T2CKPS = 0; //prescaler
    T2CONbits.TOUTPS = 0; //podscaler
    TMR2 = 0;
    PR2 = 100;
    contador = 0;
    t2seg = 1;
    contador2 = 0;
    T2CONbits.TMR2ON = 1; // Liga o timer2
    INTCONbits.PEIE = 1; // liga perifericos 
    PIE1bits.TMR2IE = 1; // interrompe o PR2
    INTCONbits.GIE = 1; // liga todos os bits          
}


void __interrupt() ossada (void)
{
   
    INTCONbits.GIE = 0;
    if (PIR1bits.TMR2IF)
    {
        PIR1bits.TMR2IF=0;
        t2seg++;
    if(!t2seg)
    {
        contador++;
        t2seg = 10000;
    }
        {
            if(contador ==11)
            {
                contador2++;
                contador = 0; 
            }    
            }
   } 
    INTCONbits.GIE= 1;
}
