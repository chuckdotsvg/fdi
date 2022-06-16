#include <stdio.h>
#include <stdlib.h>

#define DIM 8
#define BASE 2
#define MAXS 20

char* char2ascii(char);

int main(int argc, char* argv[]){
	char str[MAXS+1], *tmp;
	int i;
	
	scanf("%s", str);

	for(i = 0; str[i] != '\0'; i++){
		tmp = char2ascii(str[i]);
		printf("%s", tmp);
		free(tmp);
	}
	printf("\n");

	return 0;
}

char* char2ascii(char c){
	char *bin, tmp;
	int n, i;

	bin = malloc(sizeof(char)*(DIM+1));
	if(bin){
		bin[DIM] = '\0';
		n = c;

		for(i = DIM-1; i >= 0; i--){
			tmp = n % BASE;
			bin[i] = tmp + '0';
			n /= BASE;
		}
	}else
		printf("errore\n");

	return bin;
}
