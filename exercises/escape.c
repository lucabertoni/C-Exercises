/*
	Cosa fa			:			Prende dei caratteri in input
								Esegue l'escape dei caratteri tab,backslash,backspace
								Stampa la stringa con l'escape
*/

#include <stdio.h>	/* Libreria per lo std input e output*/

main(){
	int c;	/* Variabile che conterrà il carattere */
	int i = 0; /* Variabile di count */
	char sResult[1024]; /* Array di caratteri che contiene la stringa con escape */

	while((c = getchar()) != EOF){		/* Ciclo fino a quando il carattere è EOF */
		if (c == '\t'){					/* Se il carattere è una tabulazione faccio l'escape */
			sResult[i++] = '\\';
			sResult[i++] = 't';
		}else if(c == '\b'){			/* 	// 	// 	//	// */
			sResult[i++] = '\\';
			sResult[i++] = 'b';
		}else if(c == '\\'){
			sResult[i++] = '\\';
			sResult[i++] = '\\';
		}else{
			sResult[i++] = c;
		}
	} /* End while */

	sResult[i++] = 0;	/* Aggiungo il carattere terminatore */
	printf("\n%s\n", &sResult);	/* Stampo la stringa con l'escape */
}