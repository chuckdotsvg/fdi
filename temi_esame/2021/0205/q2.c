#include <stdio.h>
#include <stdlib.h>

int baricentro(int[], int);

int main(int argc, char *argv[]){
	return 0;
}

int baricentro(int arr[], int dim){
	int bar, dx, sx;
	int i, j;

	for(bar = -1, i = 0, dx = 0; i < dim && bar == -1; i++){
		dx += arr[i];

		for(j = i+1, sx = 0; j < dim; j++);

		if(dx == sx)
			bar = i;
	}

	return bar;
}
