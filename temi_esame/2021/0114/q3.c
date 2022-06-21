#include <stdio.h>
#include <stdlib.h>

typedef struct lista_{
	int n;

	struct lista_ *next;
}lista_t;

lista_t *compatta(lista_t*);

int main(int argc, char* argv[]){
	return 0;
}

lista_t *compatta(lista_t* l){
	lista_t *tmp;

	for(tmp = l; tmp->next; tmp = tmp->next)
		if(exists(tmp->next, tmp->n))
			delete(tmp->next, tmp->n);

	return tmp;
}
