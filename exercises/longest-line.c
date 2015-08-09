/*
	Cosa fa			:			Prende una riga alla volta in input fino a quando viene interrotto.
								Poi stampa a schermo la lunghezza della riga più lunga, e la riga più lunga(con più caratteri)
*/

#include <stdio.h>	/* Libreria per òp std input/output */

#define MAXLEN	1000	/* Definisco la lunghezza massima che può avere una stringa */

int getLine(char sLine[],int nLimite);	/* Vedi descrizione sotto */
void copy(char sFrom[],char sTo[]);	/* Vedi descrizione sotto */

main(){
	char sLine[MAXLEN];	/* Riga di testo presa da input */
	char sLongestLine[MAXLEN]; /* Riga di testo più lunga */
	int nLen = 0; /* Lungezza della riga corrente */
	int nMaxLen = 0; /* Lunghezza della riga con il maggior numero di caratteri*/

	/* Ciclo fino a quando la funzione getLine mi ritorna una lunghezza valida */
	while((nLen = getLine(sLine,MAXLEN)) > 0){
		if(nLen > nMaxLen){		/* Se la lunghezzza della nuova riga è maggiore di quella precedente, aggiorno*/
			nMaxLen = nLen;

			copy(sLine,sLongestLine); /* Faccio una copia della riga corrente all'interno della variabile che contioene la riga più lunga */
		}
	} /* End while */

	printf("La riga più lunga è di %d caratteri, ed è: %s\n", nMaxLen, sLongestLine); /* Stampo la lunghezza e la riga più lunga */

}


/*
	Cosa fa			:			Prende da input una serie di caratteri fino a quando non incontra il carattere EOF  o \n(quest'ultimo viene comunque salvato)
								o fino a quando raggiunge il limite di lunghezza
	sLine			:			char, variabile in cui salvare i caratteri estratti
	nLimite			:			intero, lunghezza massima che può assumere la stringa
	Ritorna			:			nLen -> intero, lunghezza (numero di caratteri) della riga estratta
*/
int getLine(char sLine[],int nLimite){
	int nLen = 0;
	int cCarattere,i;

	/* Ciclo fino a quando le condizioni sono vere (vedi sopra)*/
	for(i = 0; i < nLimite-1 && (cCarattere = getchar()) != EOF && (cCarattere = getchar()) != '\n'; i++){
		sLine[i] = cCarattere;	/* Inserisco il carattere alla fine della stringa */
		++nLen;	/* Incremento il valore di lugnhezza della stringa */
	}

	/* Se il carattere inserito prima di uscire dal ciclo è un \n lo salvo comunque*/
	if(cCarattere == '\n'){
		sLine[i++] = cCarattere;
	}

	sLine[i] = 0;	/* Aggiungo il carattere terminatore */
	return nLen;	/* Ritorno la lunghezza della stringa presa da input */
}

/*
	Cosa fa			:			Esegue una copia di una stringa in un'altra
	sFrom			:			stringa, stringa da copiare
	sTo				:			stringa, stringa in cui copiare
*/
void copy(char sFrom[],char sTo[]){
	int i = 0;

	/* Ciclo fino a quando incontro il carattere terminatore 0 */
	while(sFrom[i] != 0){
		sTo[i] = sFrom[i++];
	}
}