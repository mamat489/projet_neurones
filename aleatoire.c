#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Ne pas oublier d'inclure le fichier time.h

void main(void){
	printf("int poidsX[64]={");
	for(int i=0;i<64;i++)
	if((float)rand() / (float)RAND_MAX>0.5)
		printf("1,");
	else
		printf("-1,");
	printf("}; \n");
}
