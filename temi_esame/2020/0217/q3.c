#include <stdio.h>
#include <stdlib.h>

#define NR 10
#define NC 10

void filtro(int[][NC], int*[][NC], int, int);

int main(int argc, char* argv[]){
	return 0;
}

void filtro(int image[][NC], int *filtered[][NC], int nr, int nc){
	int i, j, h, k;
	float tmp;

	for(i = 0; i < nr; i++)
		for(j = 0; j < nc; j++){
			for(h = i - 1, tmp = 0; h <= i + 1; h++)
				for(k = j - 1; k <= i + 1; k++)
					if((h >= 0 && h < nr) && (k >= 0 || k < nr))
						tmp += image[h][k];
			tmp /= 9;
			*filtered[i][j] = tmp;
		}
}

