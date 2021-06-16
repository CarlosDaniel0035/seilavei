/*
 * File:   timer.c
 * Author: 20185147
 *
 * Created on 16 de Junho de 2021, 16:41
 */


#include <xc.h>
#include "config.h"
#include "dispLCD4vias.h"

unsigned int contador;
unsigned int t2seg;

void timer2_init (void)
{
    INTCONbits.GIE = 0;
    T2CONbits.T2CKPS = 00;
    T2CONbits.TOUTPS = 0000;
    TMR2 = 256-156;
    contador = 0;
    t2seg = 10000;
    INTCONbits.PEIE = 1;
    INTCONbits.GIE = 1;           
}
void __interrupt() ossada(void)
{
    INTCONbits.GIE = 0;
    if(INTCONbits.PEIE)
    {
        INTCONbits.PEIE = 0;
        TMR2 = 256-156;
        --t2seg;
        if ( !t2seg)
        {
            t2seg = 10000;
            ++contador;
        } 
    }
    INTCONbits.GIE = 1;
}
