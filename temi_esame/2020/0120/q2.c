#include <stdio.h>
#include <stdlib.h>

#define NR 10
#define NC 10

int dominante(int [][NC], int, int);

int main(int argc, char* argv[]){
	return 0;
}

int dominante(int mat[][NC], int nr, int nc){
	int count, i, j, h, k, flag;
	
	for(i = 0, count = 0; i < nr -1; i++)
		for(j = 0; j < nc -1; j++)
			for(h = i + 1, flag = 1; flag && h < nr; h++){
				for(k = j + 1; flag && k < nr; k++)
					if(mat[i][j] <= mat[h][k])
						flag = 0;

				if(flag)
					count++;
			}

	return count;
}
