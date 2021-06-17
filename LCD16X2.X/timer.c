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
    INTCONbits.GIE = 0; // desliga todos para poder mexer nos bits de interrupcão 
    T2CONbits.T2CKPS = 0; //prescaler
    T2CONbits.TOUTPS = 0; //podscaler
    TMR2 = 0;  //comparador 
    PR2 = 100; //comparador 
    contador = 0; 
    t2seg = 1;
    contador2 = 0;
    T2CONbits.TMR2ON = 1; // Liga o timer2
    INTCONbits.PEIE = 1; // liga perifericos 
    PIE1bits.TMR2IE = 1; // interrompe o PR2
    INTCONbits.GIE = 1; // liga todos os bits de interrupção          
}


void __interrupt() ossada (void)
{
   
    INTCONbits.GIE = 0; // desabilita todos para poder usar os bits
    if (PIR1bits.TMR2IF) //se o comparador for ligado ele acrescenta t2seg  
    {
        PIR1bits.TMR2IF=0; // desliga comparador
        t2seg++;
    if(!t2seg) // se t2seg for chamado contador acrescenta 
    {
        contador++;
        t2seg = 10000;
    }
        {
            if(contador ==11) // se o contador chegar em 11 conta 1 e por ai vai
            {
                contador2++;
                contador = 0; 
            }    
            }
   } 
    INTCONbits.GIE= 1; // liga os bits de interrupção 
}
