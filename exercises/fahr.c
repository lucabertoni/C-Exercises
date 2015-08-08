/*
	Cosa fa			:			Calcola i gradi celsius partendo dai fahreneit
*/	

#include <stdio.h>		/* Inclusione della libreria per lo standard input e output*/

#define	LIMITE	300		/* Limite al quale deve fermarsi il calcolo*/
#define PASSO	20		/* Passo con il quale deve incrementare il calcolo */
#define START	0		/* Punto dal quale iniziare a calcolare */

/* Definizione della funzione main senza un tipo*/
main(){
	float fahr = START;

	for (fahr;fahr <= LIMITE; fahr += PASSO)
		printf("%6.2f\t%6.2f\n", fahr,5*(fahr-32)/9);
}