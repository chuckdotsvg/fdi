#include <stdio.h>
#include <stdlib.h>

typedef struct lista_{
	struct lista_ *next;
}lista_t;

int lunghezza(lista_t*);
lista_t* find(lista_t*, int);

int main(int argc, char* argv[]){
	return 0;
}

lista_t* find(lista_t* h, int k){
	int i, flag, len;
	lista_t* elem;

	len = lunghezza(h);
	if(k > len)
		elem = NULL;
	else
		for(i = len, flag = 0; !flag && h; h = h->next, i--)
			if(i == k){
				flag = 1;
				elem = h;
			}

	return elem;
}

int lunghezza(lista_t* h){
	int count;

	for(count = 0; h; h = h->next);

	return count;
}
