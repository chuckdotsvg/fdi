#include <stdio.h>
#include <stdlib.h>

#define NEAR 3
#define MINS 8

int verifica(char[]);
char lower(char);

int main(int argc, char* argv[]){
	if(argc == 2)
		printf("%d\n", verifica(argv[1]));
	else
		printf("ERRORE arg\n");

	return 0;
}

char lower(char c){
	if(c >= 'A' && c <= 'Z')
		c += 'a' - 'A';

	return c;
}

int verifica(char str[]){
	int i, numb, count, noalph;

	for(i = 0, numb = 0, count = 0, noalph = 0; count < 3 && str[i] != '\0'; i++){
		if(str[i] >= '0' && str[i] <= '9')
			numb++;
		else if(!(lower(str[i]) >= 'a' && lower(str[i]) <= 'z'))
			noalph++;

		if(count && str[i] == str[i-1])
			count++;
		else
			count = 1;
	}

	return (i >= 8) && (count < 3) && numb && noalph;
}
