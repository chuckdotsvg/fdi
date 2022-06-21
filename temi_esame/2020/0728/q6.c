#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct lista_{
	int num;

	struct lista_ *next;
}lista_t;

lista_t* index(int[], int, int);
lista_t* append(lista_t*, int);
void libera(lista_t**);
void visualizza(lista_t*);

int main(int argc, char *argv[]){
	int arr[MAX], s;
	lista_t* l;

	for(s = 0; s < MAX; s++){
		printf("elem %d: ", s+1);
		scanf("%d", arr+s);
	}

	printf("Soglia: ");
	scanf("%d", &s);

	l = index(arr, MAX, s);

	visualizza(l);
	libera(&l);

	return 0;
}

lista_t* append(lista_t* l, int n){
	lista_t* tmp, *scorr;

	tmp = malloc(sizeof(lista_t));
	if(tmp){
		tmp->num = n;
		tmp->next = NULL;

		if(l){
			for(scorr = l; scorr->next; scorr = scorr->next);
			scorr->next = tmp;
		}else
			l = tmp;
	}else
		printf("ERR\n");
	
	return l;
}

lista_t* index(int seq[], int dim, int soglia){
	lista_t* h;
	int i;

	for(i = 0, h = NULL; i < dim; i++)
		if(seq[i] > soglia*soglia)
			h = append(h, i);

	return h;
}

void libera(lista_t **h){
	lista_t* tmp;

	while(*h){
		tmp = *h;
		*h = (*h)->next;
		free(tmp);
	}
}

void visualizza(lista_t* h){
	while(h){
		printf("%d ", h->num);
		h = h->next;
	}

	printf("\n");
}
