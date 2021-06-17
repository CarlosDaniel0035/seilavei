#ifndef TIMER_H
#define TIMER_H

unsigned int contador2;
unsigned int contador;
unsigned int t2seg;

void timer2_init (void);

void __interrupt() ossada(void);

void xuaua_init (int qtdmaxima, int t);


#endif