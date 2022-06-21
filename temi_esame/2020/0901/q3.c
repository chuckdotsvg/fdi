#include <stdio.h>
#include <stdlib.h>

#define BASE 10

void trovanarcisisti(int[], int[], int, int);

int main(int argc, char* argv[]){
	return 0;
}

void trovanarcisisti(int numero[], int tipo[], int dim, int x){
	int i, tmp, sum, exp, cifra, flag, narc;

	for(i = 0; i < dim; i++){
		narc = 0;
		flag = 0;

		for(tmp = numero[i]; tmp; tmp /= BASE){
			cifra = tmp % BASE;

			for(exp = x, sum = 1; exp; exp--)
				sum *= cifra;
			
			narc += sum;
		}

		if(narc == numero[i])
			flag = 1;

		tipo[i] = flag;
	}
}
