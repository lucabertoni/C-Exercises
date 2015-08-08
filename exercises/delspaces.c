/*
	Cosa fa			:			Prende dei carattere in input e stampa una stringa con un solo spazio
								che separa le parole
*/

#include <stdio.h>

main(){
	int c,bSpazio,i;	/* Inizializzo le variabili che contengono il carattere, il "spazio trovato" e il counter*/
	bSpazio = i = 0;
	char sResult[1024];

	while ((c = getchar()) != EOF){
		if (c == ' '){			/* Controllo se il caratte inserito è uno spazio*/
			if(bSpazio == 0){	/* Se precedentemente non è stato inserito alcuno spazio, lo inserisco */
				sResult[i++] = c;
				bSpazio = 1;	/* Imposto che è stato inserito uno spazio*/
			}
		}else{	/* End if, start else*/	/* Se il carattere inserito non è uno spazio... */
			if (bSpazio = 1)			/* Se ho in pancia il fatto che sia stato inserito uno spazio, azzero tutto */
				bSpazio = 0;	
		} /* End else*/

		if (bSpazio == 0){				/* Se non è stato inserito uno spazio, ma un altro carattere... */
			sResult[i++] = c;			/* ...salvo il carattere */
		} /* End if */
	} /* End while */

	sResult[i++] = 0;	/* Aggiungo il carattere terminatore */
	printf("\n%s\n", &sResult);	/* Stampo la stringa estratta con un solo spazio che separa ogni parola*/
}