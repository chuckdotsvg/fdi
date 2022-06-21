#include <stdio.h>
#include <stdlib.h>

#define MAX 200

int compattaarray(int[], int);

int main(int argc, char *argv[]){
	int dim, i, *arr;

	do{
		printf("Quantità dati(%d <): ", MAX);
		scanf("%d", &dim);
	}while(dim <= 0 && dim > MAX);
	
	arr = malloc(sizeof(int)*dim);
	if(arr){
		for(i = 0; i < dim; i++){
			printf("Elem %d: ", i+1);
			scanf("%d", arr+i);
		}

		printf("%d\n", compattaarray(arr, dim));

		free(arr);
	}else
		printf("ERR\n");

	return 0;
}

int compattaarray(int arr[], int dim){
	int i, j;

	for(i = 0; i < dim; i++)
		if(!(isprime(arr[i]))){
			for(j = dim-1; j-1 >= i; j--)
				arr[j-1] = arr[j];
			
			dim--;
		}

	return dim;
}

int isprime(int num){
	int flag, i;
	
	for(i = 2, flag = 1; flag && i*i <= num; i++)
		if(!(num % i))
			flag = 0;

	return flag;
}
