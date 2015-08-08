#include <stdio.h>

main(){
	long nCount = 0;
	int carattere;

	while((carattere = getchar()) != EOF)
		if(carattere == '\n')
			++nCount;
	printf("%d\n", nCount);
}