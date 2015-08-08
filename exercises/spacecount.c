/*
	Cosa fa			:			Conta gli spazi, i tab e gli a capo
								Infine stampa i loro valori
*/

#include <stdio.h>

main(){
	int nSpazi,nTab,nACapo,c;		/* Dichiarazione dei counter */ 
	nSpazi = nTab = nACapo = 0;		/* Inizializzazione dei counter a 0 */

	while((c = getchar()) != EOF)	/* Ciclo che termina all'inserimento del carattere EOF */

		/* Controllo del carattere inserito */
		if (c == ' ') ++nSpazi;		/* Se è uno spazio incremento il counter dello spazio */
		else if(c == '\t') ++nTab;	/* Se è un tab incremento il counter del tab */
		else if(c == '\n') ++nACapo;/* Se è un a capo incremento il counter dell' a capo */

	printf("\nSpazi\tTab\tA capo\n");	/* Stampo un'intestazione */
	printf("%d\t%d\t%d\n", nSpazi,nTab,nACapo);	/* Stampo i counter */
}