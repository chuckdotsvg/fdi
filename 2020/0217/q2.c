#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* conta(char[], char[]);

int main(int argc, char* argv[]){
	int *ris, i;

	if(argc == 3){
		ris = conta(argv[1], argv[2]);
		
		for(i = 0; argv[2][i] != '\0'; i++)
			printf("%c %d\n", argv[2][i], ris[i]);

		free(ris);
	}else
		printf("Errore argomenti\n");

	return 0;
}

int* conta(char info[], char cars[]){
	int *count, i, j, dim;
	
	dim = strlen(cars);
	count = malloc(sizeof(int)*dim);
	if(count){
		for(i = 0; i < dim; i++)
			count[i] = 0;

		for(i = 0; cars[i] != '\0'; i++)
			for(j = 0; info[j] != '\0'; j++)
				if(cars[i] == info[j])
					count[i]++;
	}

	return count;
}
