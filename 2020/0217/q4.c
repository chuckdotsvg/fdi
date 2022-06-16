#include <stdio.h>

#define MAXS 40
#define MAXLINE 50

void analizzariga(char[], int*, int*, int*);

int main(int argc, char* argv[]){
	char filename[MAXS+1], row[MAXLINE+1];
	int max, min, nline, nphrase;
	FILE *fp;

	scanf("%s", filename);
	fp = fopen(filename, "r");
	if(fp){
		nphrase = nline = max = 0;
		min = MAXLINE;

		do{
			fscanf(fp, "%[^\n]\n", row);
			analizzariga(row, &max, &min, &nphrase);
			nline++;
		}while(!feof(fp));

		printf("max: %d\n", max);
		printf("min: %d\n", min);
		printf("righe: %d\n", nline);
		printf("frasi: %d\n", nphrase);

		fclose(fp);
	}else
		printf("ERRORE\n");

	return 0;
}

void analizzariga(char str[], int* max, int* min, int* frasi){
	int count, i;
	char curr;
	
	for(i = 0, count = 0; str[i] != '\0'; i++){
		if(str[i] != ' ')
			count++;

		if(str[i] == '.')
			(*frasi)++;
	}
		if(count > *max)
			*max = count;
		if(count < *min)
			*min = count;
}

/*
int main(int argc, char* argv[]){
	char filename[MAXS+1], curr;
	int max, min, nline, nphrase, count;
	FILE *fp;

	scanf("%s", filename);
	fp = fopen(filename, "r");
	if(fp){
		count = nphrase = nline = max = 0;
		min = MAXLINE;

		fscanf(fp, "%c", &curr);
		while(!feof(fp)){
			if(curr != ' ' && curr != '\n')
				count++;

			if(curr == '.'){
				nphrase++;
			}else if(curr == '\n'){
				nline++;
				if(count > max)
					max = count;
				else if(count < min)
					min = count;

				count = 0;
			}

			fscanf(fp, "%c", &curr);
		}
		printf("max: %d\n", max);
		printf("min: %d\n", min);
		printf("righe: %d\n", nline);
		printf("frasi: %d\n", nphrase);

		fclose(fp);
	}else
		printf("ERRORE\n");

	return 0;
}
*/
