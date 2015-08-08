/*
	Programma che implementa l'algoritmo quick-find per risolvere il problema della connettività

	Problema: data una serie di coppie in ingresso, p-q, stampare a schermo le nuove coppie.
	Una nuova coppia si presenta quando i valori p-q della coppia inserita non sono collegati tra di loro.
	Se p è collegato a q, e q è collegato a r, allora p sarà collegato a r:
	p-q
	q-r
	p-r = true, perchè p-q-r => p-r

	Tabella 1:
	p q		 	0 1 2 3 4 5 6 7 8 9 .... 10000

	3 4			0 1 2 4 4 5 6 7 8 9
	4 9			0 1 2 9 9 5 6 7 8 9
	8 0			0 1 2 9 9 5 6 7 0 9
	2 3			0 1 3 9 9 5 6 7 0 9
	5 6			0 1 3 9 9 6 6 7 0 9
	2 9			0 1 9 9 9 6 6 7 0 9
	5 9			0 1 9 9 9 9 9 7 0 9
	7 3			0 1 9 9 9 9 9 9 0 9
	4 8			0 1 0 0 0 0 0 0 0 0
	5 6			0 1 0 0 0 0 0 0 0 0
	0 2			0 1 0 0 0 0 0 0 0 0
	6 1			1 1 1 1 1 1 1 1 1 1
*/

#include <stdio.h>	/* Libreria per lo std input e output*/
#define	LIMITE	10000	/* Imposto il valore massimo che può essere assunto dai valori della coppia*/

main(){
	int aNumeri[LIMITE];	/* Dichiaro un array di interi che rappresenta l'intestazione numerica della tabella 1*/
	int p,q,i;	/* Dichiaro le variabili p,q e i che fa da contatore */

	for(i = 0;i<=LIMITE;i++) aNumeri[i] = i; /* Inizializzo gli elementi dell'array assciando all'indice come valore il valore dell'indice
												aNumeri[0] = 0
												aNumeri[1] = 1
												...
											*/

	while(1){	/* Ciclo infinito per inserire infinite coppie */
		printf("Inserire il primo valore della coppia p-q: ");	/* Prendo i valori delle coppie da input */
		scanf("%d",&p);
		printf("Inserire il secondo valore della coppia p-q: ");
		scanf("%d",&q);

		if(aNumeri[p] == aNumeri[q]){	/* 	Controllo se la coppia inserita è già connessa.
											Per farlo controllo se il valore associato all'elemento p-esimo
											corrisponde al valore associato all'elemento q-esimo
										*/
			printf("La coppia %d-%d è connessa\n",p,q);
			continue;
		}

		printf("La coppia p-q è una nuova coppia: %d-%d\n",p,q);

		for(i = 0;i < LIMITE;i++)	/* 	Nel caso la coppia p-q sia una nuova coppia, aggiorno i collegamenti
										assegnando ad ogni elemento dell'array aNumeri che ha come valore quello di p
										il valore di q, in modo che ora p sia collegato a q e a tutte le sue "referenze"
									*/
			if(aNumeri[i] == aNumeri[p])
				aNumeri[i] = aNumeri[q];
	}
}