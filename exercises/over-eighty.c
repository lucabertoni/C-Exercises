/*
	Cosa fa			:			Stampa a schermo la riga presa da input se la sua lunghezza supera gli 80 caratteri
*/
#include <stdio.h>

#define MAXLEN	1000	/* Definisco la lunghezza massima che può assumere la riga presa da input */

int getLine(char sLinea[], int nLimite); /* Creo il prototipo della funzione getLine */

main(){
	char sLine[MAXLEN];	/* Dichiaro la variabile che conterrà la riga presa da input */
	int nLen;	/* Dichiaro la variabile che conterrà la lunghezza della riga presa da input */

	/* Ciclo fino a quando la riga presa da input ha una lunghezza maggiore di 0 */
	while((nLen=getLine(sLine,MAXLEN))>0)
		if (nLen > 80)	/* Se la lunghezza della riga supera gli 80 caratteri di lunghezza, stampo a schermo il messaggio */
			printf("Questa linea supera gli 80 caratteri: %s\n", sLine);
}

/*
	Cosa fa			:			Prende da input una serie di caratteri fino a quando non incontra il carattere EOF  o \n(quest'ultimo viene comunque salvato)
								o fino a quando raggiunge il limite di lunghezza
	sLinea			:			char, variabile in cui salvare i caratteri estratti
	nLimite			:			intero, lunghezza massima che può assumere la stringa
	Ritorna			:			nLen -> intero, lunghezza (numero di caratteri) della riga estratta
*/
int getLine(char sLinea[], int nLimite){
	int i,nLen,c;
	nLen = 0;

	for(i = 0; i<nLimite-1 && (c=getchar()) != '\n' && c != EOF ;i++){
		sLinea[i] = c;
		++nLen;
	}

	if (c == '\n')
		sLinea[i++] = c;

	sLinea[i] = '\0';

	return nLen;
}