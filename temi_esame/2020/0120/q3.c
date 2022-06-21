#include <stdio.h>
#include <stdlib.h>

int bound(int[], int, int, int);

int main(int argc, char* argv[]){
	int ub, lb, i, num, *arr;

	printf("Dim arr: ");
	scanf("%d", &num);
	printf("da, a: ");
	scanf("%d %d", &lb, &ub);

	arr = malloc(sizeof(int)*num);
	if(arr){
		for(i = 0; i < num; i++){
			printf("Elem %d: ", i+1);
			scanf("%d", arr+i);
		}

		printf("%d\n", bound(arr, num, lb, ub));

		free(arr);
	}else
		printf("Errore\n");

	return 0;
}

int bound(int v[], int dim, int da, int a){
	int ok, *cont, i, n;

	n = a - da + 1;

	if(n == dim){
		cont = malloc(sizeof(int)*n);
		if(cont){
			for(i = 0; i < n; i++)
				cont[i] = 0;
			
			for(i = 0, ok = 1; ok && i < dim; i++){
				if(v[i] < da || v[i] > a || cont[v[i] - da] > 1)
					ok = 0;
				else
					cont[v[i] - da]++;
			}
			
			for(i = 0; cont[i] && i < n; i++);

			if(i != n)
				ok = 0;

			free(cont);
		}else{
			printf("errore\n");
			ok = 0;
		}
	}else
		ok = 0;


	return ok;
}
