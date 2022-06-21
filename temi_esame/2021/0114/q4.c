#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cercacerniera(char[], char[]);
char* cerniera(char[], char[], int);

int cercacerniera(char s1[], char s2[]){
	int pos, i, j;

	pos = -1;

	for(i = 1; pos == -1 && s2[i] != '\0'; i++){
		if(s1[0] == s2[i]){
			pos = i;
			j = 0;

			while(s1[j] == s2[i+j] && s2[i] != '\0')
				j++;

			if (s2[i+j] != '\0')
				pos = -1;
		}
	}

	return pos;
}

char* cerniera(char s1[], char s2[], int inizio){
	int i, j, dim, len2;
	char *nuova;

	len2 = strlen(s2);
	dim = strlen(s1) - len2 + 2*inizio;

	nuova = malloc(sizeof(char)*(dim + 1));
	if(nuova){
		for(i = (len2 - inizio), j = 0; s1[i] != '\0'; i++, j ++)
			nuova[j] = s1[i];

		for(i = 0; i != inizio ; i++, j ++)
			nuova[j] = s2[i];

		nuova[j] = '\0';
	}else
		printf("Errore!");

	return nuova;
}

int main(int argc, char* argv[]){
	int pos;
	char *cern;
	if(argc == 3){
		pos = cercacerniera(argv[1], argv[2]);

		if(pos > 0){
			cern = cerniera(argv[1], argv[2], pos);
			printf("%s\n", cern);
		}
	}else
		printf("N. argomenti sbagliato\n");

    return 0;
}
