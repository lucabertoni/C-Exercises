/*
	Cosa fa			:			Prende un carattere da input e lo stampa in output
								fino a quando non arriva il carattere EOF
								
	E' possibile assegnare ad una variabile di tipo intero un carattere perchè se a monitor
	viene mostrato come carattere in realtà è sempre un numero
*/

#include <stdio.h>			/* Libreria standard per input/output*/

/* Definizione della funzione main*/
main(){
	int c;				/* Dichiarazione di una variabile di tipo intero */

	while((c = getchar()) != EOF)	/* Ciclo fino a quando il carattere inserito è un EOF (end of file) */
		putchar(c);					/* Stampa del carattere estratto nello stdout */
}