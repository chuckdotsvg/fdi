#include <stdio.h>
#include <stdlib.h>

void meanvarstd(int[], int, float*, float*, float*);

int main(int argc, char* argv[]){
	return 0;
}

void meanvarstd(int seq[], int dim, float* media, float* var, float* dev){
	int i;

	*media = 0;
	*var = 0;
	*dev = 0;

	for(i = 0; i < dim; i++)
		*media += seq[i];
	*media /= dim;

	for(i = 0; i < dim; i++)
		*var += (seq[i] - *media)*(seq[i] - media);
	*var /= dim;
}
