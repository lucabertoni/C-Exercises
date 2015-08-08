/*
	Cosa fa			:			Conta il numero di caratteri,righe e parole inserite
*/

#include <stdio.h>	/* Libreria standard */

#define	INWORD	1	/* Valore booleano che indica che mi trovo all'interno di una parola */
#define OUTWORD	0	/* Valore booleano che indica che mi trovo fuori da una parola */

main(){
	int c,nCaratteri,nLinee,nParole,nState;	/* Dichiaro le variabili carattere, counter e stato*/

	nState = OUTWORD;	/* Imposto che mi trovo fuori da una parola */
	nLinee = 1;	/* Imposto che mi trovo sulla prima linea */
	nCaratteri = nParole = 0; /* Azzero i contatori */

	while((c = getchar()) != EOF){	/* Ciclo fino a quando non trovo il carattere EOF */
		++nCaratteri;	/* Incremento il counter dei caratteri */
		if (c == '\n')	/* Se il carattere inserito è un a capo, incremento il numero delle righe*/
			++nLinee;

		if (c == ' ' || c == '\n' || c == '\t'){ /*Se il carattere è uno spazio, un a capo o un tab imposto che mi trovo fuori da una parola*/
			nState = OUTWORD;
		}else if(nState == OUTWORD){	/*Se il carattere non è uno di quelli citati sopra incremento il count delle parole e imposto che mi trovo dentro ad una parola */
			nState = INWORD;
			++nParole;
		}
	} /* End while */

	printf("\nCaratteri\t\tLinee\t\tParole\n");
	printf("%10d\t%10d\t%10d\n", nCaratteri,nLinee,nParole);	/* Stampo i counter */
}