#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXS 30
#define FILENAME "dizionario.txt"

typedef struct slista_{
	char parola[MAXS+1];

	struct slista_ *next;
}slista_t;

slista_t* push(slista_t *, char[]);
void visualizzaalternative(slista_t**);
slista_t* calcolaalternative(char[], FILE*);
void clean(slista_t **);

int main(int argc, char *argv[]){
	slista_t *alt;
	int num;
	FILE *fp;
	
	if(argc == 2){
		fp = fopen(FILENAME, "r");
		if(fp){
			alt = calcolaalternative(argv[1], fp);
			visualizzaalternative(&alt);
			fclose(fp);
		}else
			printf("Errore\n");
	}else
		printf("N. elementi errato\n");

	return 0;
}

slista_t* calcolaalternative(char cerca[], FILE* fp){
	int i, flag;
	char comp[MAXS+1];

	slista_t *list;

	list = NULL;

	fscanf(fp, "%s", comp);
	while(!feof(fp)){
		if(cerca[0] != comp[0]){
			for(i = 1; cerca[i] == comp[i] && cerca[i] != '\0'; i++);
	
			if(comp[i] == '\0' && cerca[i] == comp[i])
				push(list, comp);
	
			fscanf(fp, "%s", comp);
		}
	}
	
	return list;
}

slista_t* push(slista_t *h, char s[]){
	slista_t *tmp;

	tmp = malloc(sizeof(slista_t));
	if(tmp){
		if(tmp->parola){
			strcpy(tmp->parola, s);
			tmp->next = h;
			h = tmp;
		}else
			printf("Errore\n");
	}else
		printf("Errore mem\n");

	return h;
}


void visualizzaalternative(slista_t** l){
	int c;

	c = 0;
	while(*l){
		printf("%s\n", (*l)->parola);
		*l = (*l)->next;
		c++;
	}

	printf("%d alternative\n", c);
}
