#include <stdio.h>
#include <stdlib.h>

#define NC 10

float **centra(int[][NC], int, int);

int main(int argc, char* argv[]){
	return 0;
}

float **centra(int m[][NC], int nr, int nc){
	float **new, media;
	int i, j;
	
	new = malloc(sizeof(float*)*nr);
	if(new){
		for(i = 0; i < nr; i++)
			new[i] = malloc(sizeof(int)*nc);

		for(j = 0; j < nc; j++){
			for(i = 0, media = 0; i < nr; i++)
				media += m[i][j];
			
			for(i = 0; i < nr; i++)
				new[i][j] = m[i][j] - media;
		}		
	}else
		printf("ERRORE 1\n");

	return new;
}
