#include <stdio.h>
#include <stdlib.h>

typedef struct elem_{
	int num;

	struct elem_ *next;
}elem_t;

elem_t* missing(elem_t*);
elem_t* push(elem_t*, int);
elem_t* exists(elem_t*, int);
void visualizza(elem_t*);
void libera(elem_t**);

int main(int argc, char *argv[]){
	elem_t* lista, *mancanti;
	int n;
	
	lista = NULL;
	mancanti = NULL;

	printf("Inserisci elementi, termina con 69\n");
	scanf("%d", &n);
	
	while(n != 69){
		lista = push(lista, n);
		scanf("%d", &n);
	}
	
	mancanti = missing(lista);

	visualizza(mancanti);
	libera(&mancanti);
	libera(&lista);

	return 0;
}

elem_t* missing(elem_t* codici){
	elem_t* mancanti, *tmp;
	int min, max, i;
	
	mancanti = NULL;
	min = max = codici->num;

	for(tmp = codici->next; tmp; tmp = tmp->next){
		if(tmp->num > max)
			max = tmp->num;
		else if(tmp->num < min)
			min = tmp->num;
	}

	for(i = min+1; i < max; i++)
		if(!exists(codici, i))
			mancanti = push(mancanti, i);

	return mancanti;
}

elem_t* push(elem_t* l, int n){
	elem_t *tmp;

	tmp = malloc(sizeof(elem_t));
	if(tmp){
		tmp->num = n;
		tmp->next = l;
		l = tmp;
	}else
		printf("ERR\n");

	return l;
}

elem_t* exists(elem_t* h, int n){
	int flag;
	
	flag = 0;

	while(h && !flag){
		if(h->num == n)
			flag = 1;

		h = h->next;
	}

	return h;
}

void libera(elem_t** h){
	elem_t* tmp;

	while(*h){
		tmp = *h;
		*h = (*h)->next;
		free(tmp);
	}
}

void visualizza(elem_t* h){
	while(h){
		printf("%d ", h->num);
		h = h->next;
	}

	printf("\n");
}
