#include <stdio.h>
#include <stdlib.h>

typedef struct lista_{
	float num;

	struct lista_ *next;
}lista_t;

lista_t* append(lista_t*, float);
void cancellalista(lista_t**);
void analizzabassi(float [], int);
lista_t* cercabassi(float[], int);

int main(){
	lista_t* l;
	int n;
	float *a;

	do
		scanf("%d", &n);
	while(n <= 0);

	a = malloc(sizeof(float)*n);
	if(a){
		cercabassi(a, n);
		analizzabassi(a, n);
		cancellalista(&l);
		free(a);
	}else
		printf("Errore\n");

	return 0;
}

lista_t* cercabassi(float arr[], int dim){
	lista_t* new;
	int i;
	
	new=NULL;
	for(i = 1; i < dim-1; i++){
		if(arr[i] < arr[i-1] && arr[i] < arr[i+1])
			new = append(new, arr[i]);
	}

	return new;
}

lista_t* append(lista_t* h, float basso){
	lista_t* node;

	node = malloc(sizeof(lista_t));
	if(node){
		node->num = basso;
		node->next = NULL;

		if(h){
			while(h->next)
				h = h->next;

			h -> next = node;
		} else
			h = node;
	}

	return h;
}

void analizzabassi(float arr[], int dim){
	return;
}

void cancellalista(lista_t** h){
	lista_t* tmp;

	while(*h){
		tmp = (*h)->next;
		free(*h);
		*h = tmp;
	}
}
