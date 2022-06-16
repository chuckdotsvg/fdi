#include <stdio.h>
#include <stdlib.h>

#define FILENAME "parole.txt"
#define MAXS 30

void analizza(char[], char*, int*);

int main(int argc, char *argv[]){
	FILE *fp;
	char parola[MAXS+1], lettera;
	int contatore, max;
	
	fp = fopen(FILENAME, "r");
	if(fp){
		max = 1;
		fscanf(fp, "%s", parola);

		while(!feof(fp)){
			analizza(parola, &lettera, &contatore);
			printf("%c %d\n", lettera, contatore);

			if(contatore > max)
				max = contatore;

			fscanf(fp, "%s", parola);
		}

		printf("%d\n", max);

		fclose(fp);
	}else
		printf("Errore\n");

	return 0;
}

void analizza(char str[], char* let, int* count){
	int c, i;
	char alph;

	alph = str[0];
	c = 1;
	
	for(i = 1; str[i] != '\0'; i++){
		if(str[i] < alph){
			alph = str[i];
			c = 1;
		}else if(str[i] == alph)
			c++;
	}

	*let = alph;
	*count = c;
}
