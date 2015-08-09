/**/

#include <stdio.h>

#define SPACETAB		4
#define MAXBUFFERLEN	10000

void makeSpaces(char sSpaces[],int nSpaces);
void copy(char sFrom[],char sTo[]);	/* Vedi descrizione sotto */
void replaceChrWithString(char sBuffer[],char sRet[],int cCarattere,char sReplace[],int nStart,int nTimes);

main(){
	int cCarattere,nCount,nSpaceCount,nPosition;
	char sBuffer[MAXBUFFERLEN];
	char sTemp[MAXBUFFERLEN];
	char sSpaces[SPACETAB];
	nCount = nSpaceCount = 0;

	makeSpaces(sSpaces,SPACETAB);

	while((cCarattere=getchar()) != EOF){
		if (nCount == MAXBUFFERLEN-1)
			break;

		sBuffer[nCount] = cCarattere;

		if (cCarattere == '\t'){
			replaceChrWithString(sBuffer,sTemp,cCarattere,sSpaces,nCount,1);
			copy(sTemp,sBuffer);
		}
	}
	printf("\nsBuffer:%s\n", sBuffer);
}

void makeSpaces(char sSpaces[],int nSpaces){
	int i;
	for(i=0;i<nSpaces;i++)
		sSpaces[i] = ' ';
	sSpaces[i] = '\0';
}

/*
	Cosa fa			:			Esegue una copia di una stringa in un'altra
	sFrom			:			stringa, stringa da copiare
	sTo				:			stringa, stringa in cui copiare
*/
void copy(char sFrom[],char sTo[]){
	int i = 0;

	/* Ciclo fino a quando incontro il carattere terminatore 0 */
	while(sFrom[i]){
		sTo[i] = sFrom[i++];
	}
}

void replaceChrWithString(char sBuffer[],char sRet[],int cCarattere,char sReplace[],int nStart,int nTimes){
	int i,i2,i21,bReplaced;
	i = i2 = bReplaced = 0;

	while(sBuffer[i]){
		if (nTimes == 0)
			break;

		if(i >= nStart){
			if(sBuffer[i] == cCarattere){
				for(i21 = 0;sReplace[i21] != '\0';i21++){
					sRet[i2++] = sReplace[i21];
					bReplaced = 1;
				}
				--nTimes;
			}
		}

		if(bReplaced == 0){
			sRet[i2] = sBuffer[i];
			++i2;
		}

		bReplaced = 0;
		i++;
	}
}