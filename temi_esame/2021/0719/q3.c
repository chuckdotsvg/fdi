#include <stdio.h>
#include <stdlib.h>

#define NC 10

void ***vulcano(int*[][NC], int, int, int, int);
void visualizzamappa(int[][NC], int, int);

int main(){
	return 0;
}

void ***vulcano(int *arr[][NC], int x, int y, int nr, int nc){
	int i, j, h, k, flag;

	for(i = 0; !flag && i < nr; i++)
		for(j = 0; !flag && j < nc; j++)
			if(i == x && j == y)
				flag = 1;

	for(h = i-1; h <= i+1 && h < nr; h++)
		for(k = j-1; k <= j+1 && j < nc; j++)
			if(*arr[x][y] > *arr[h][k])
				*arr[h][k]++;

	*arr[x][y] += 2;
}

void visualizzamappa(int arr[][NC], int nr, int nc){
	int i, j;

	for(i = 0; i < nr; i++){
		for(j = 0; j < nc; j++)
			printf("%d", arr[i][j]);

		printf("\n");
	}
}
