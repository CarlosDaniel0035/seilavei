/*
 * File:   main.c
 * Author: 20185147
 *
 * Created on 30 de Abril de 2021, 13:19
 */


#include <xc.h>
#include "config.h"
#include "delay.h"
#include "dispLCD4vias.h"
#include "timer.h"

void main(void)
{    
    dispLCD_init();
    timer2_init();
    
    dispLCD(0,0,"Contador:        ");
    while( 1 )
    {
        dispLCD_num(0,9, contador, 5);
        dispLCD_num(1,9,contador2,5);
    }
    
        
}
