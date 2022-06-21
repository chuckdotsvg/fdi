#include <stdio.h>
#include <stdlib.h>

float *distanzalineare(float, float, int, int);

int main(int argc, char* argv[]){
	float *linea, inizio, fine;
	int bound, dim;

	scanf("%f", &inizio);
	scanf("%f", &fine);
	scanf("%d", &dim);
	scanf("%d", &bound);

	linea = distanzalineare(inizio, fine, dim, bound);

	for(bound = 0; bound < dim; bound++)
		printf("%f ", linea[bound]);

	printf("\n");
	return 0;
}

float *distanzalineare(float start, float stop, int numero, int escludistop){
	int i;
	float step;
	float *arr;
	
	i = numero - 1 + escludistop;
	step = (stop - start)/i;

	arr = malloc(sizeof(float)*numero);
	if(arr){
		for(i = 0; i < (numero + escludistop); i++){
			arr[i] = start;
			start += step;
		}
	}else
		printf("Errore memoria\n");

	return arr;
}
