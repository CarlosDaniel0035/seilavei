#ifndef TIMER_H
#define TIMER_H

unsigned int contador;
unsigned int t2seg;

void timer2_init (void);

void __interrupt() ossada(void);


#endif