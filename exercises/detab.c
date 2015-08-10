/*
	Cosa fa			:			Sostituisce i tab presenti in una stringa presa da input
								con un numero definito di spazi
*/

#include <stdio.h>	/* Libreria per lo std input e output */

#define SPACETAB		4	/* Numero di spazi con cui sostituire i tab */
#define MAXBUFFERLEN	1000	/* Massima lunghezza che può assumere la stringa */

void makeSpaces(char sSpaces[],int nSpaces); /* Vedi la descrizione sotto */
void append(char sWhat[], char sTo[]);	/* Vedi la descrizione sotto */

main(){
	char cCarattere[1];	/* 	Inizializzo un array di caratteri di un solo elemento, questo perhcè la funzione
							append si aspetta sempre un array di caratteri 
						*/
	char sBuffer[MAXBUFFERLEN];	/* Definisco la variabile che conterrà l'intero buffer */
	char sSpaces[SPACETAB];	/* Definisco la variabile che conterrà il numero variabile di spazi */

	makeSpaces(sSpaces,SPACETAB); /* Creo l'array di spazi */

	/* Ciclo fino a quando il carattere inserito non è uno EOF */
	while((cCarattere[0]=getchar()) != EOF){

		/*	Controllo che carattere è stato inserito
			Se è un tab, al buffer aggiungo gli spazi,
			altrimenti aggiungo il carattere inserito
		*/
		if (cCarattere[0] == '\t'){
			append(sSpaces,sBuffer);
		}else{
			append(cCarattere,sBuffer);
		}
	}

	/* Stampo il buffer generato */
	printf("\nsBuffer:%s\n", sBuffer);
}

/*
	Cosa fa			:			Riempie un array di caratteri con un numero n di spazi
	sSpaces			:			char, array di caratteri da riempire con gli spazi
	nSpaces			:			intero, numero di spazi da inserire nell'array di caratteri
*/
void makeSpaces(char sSpaces[],int nSpaces){
	int i;
	for(i=0;i<nSpaces;i++)
		sSpaces[i] = ' ';

	/* Aggiungo il carattere terminatore */
	sSpaces[i] = '\0';
}

/*
	Cosa fa			:			Aggiunge una stringa in coda ad un'altra
	sWhat			:			char, array di caratteri da aggiungere in coda alla stringa
	sTo				:			char, arrray di caratteri al quale aggiungere altro testo
*/
void append(char sWhat[], char sTo[]){
	int i = 0;
	int i18;

	/* Incremento la variabile i18 in modo da stabilire qual è la posizione dell'utlimo carattere */
	for(i18 = 0;sTo[i18];i18++);

	/* Eseguo l'append dei caratteri */
	while(sWhat[i]){
		sTo[i18] = sWhat[i];
		++i18;
		++i;
	}
}