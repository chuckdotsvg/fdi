#include <stdio.h>
#include <stdlib.h>

typedef struct lista_{
	int num;

	struct lista_ *next;
}lista_t;

int isprime(int);
void noprimi(lista_t**);
int abs(int);
lista_t* append(lista_t*, int);
void visualizza(lista_t*);
lista_t* delete(lista_t*, int);
lista_t* pop(lista_t*);
void cancellatutto(lista_t**);

int main(int argc, char *argv[]){
	lista_t* h;
	int n;
	
	h = NULL;

	printf("Inserici numeri: termina con 0\n");
	
	scanf("%d", &n);
	while(n){
		h = append(h, n);
		scanf("%d", &n);
	}
	printf("\n");

	noprimi(&h);
	
	visualizza(h);
	cancellatutto(&h);

	return 0;
}

int isprime(int n){
	int i, flag;
	
	if(!n)
		flag = 0;
	else
		for(i = 2, flag = 1; flag && i*i <= n; i++)
			if(!(n % i))
				flag = 0;

	return flag;
}

int abs(int n){
	if(n < 0)
		n = -n;

	return n;
}

void noprimi(lista_t** l){
	lista_t *tmp, *prec, *curr;

	while(isprime(abs((*l)->num))){
		tmp = *l;
		*l = (*l)->next;
		free(tmp);
	}		

	for(prec = *l, curr = prec->next; curr; prec = curr, curr = curr->next)
		if(isprime(abs(curr->num))){
			tmp = curr;
			curr = curr->next;
			prec->next = curr;
			free(tmp);
		}
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
		printf("ERRORE\n");

	return l;
}

void visualizza(lista_t* h){
	while(h){
		printf("%d ", h->num);
		h = h->next;
	}
	printf("\n");
}

lista_t* delete(lista_t* h, int n){
	lista_t *prec, *curr, *tmp;

	while(h->num == n)
		h = pop(h);

	for(prec = h, curr = prec->next; curr; prec = curr, curr = curr->next)
		if(curr->num == n){
			prec->next = curr->next;
			tmp = curr;
			curr = curr->next;
			free(tmp);
		}

}

lista_t* pop(lista_t* h){
	lista_t	*tmp;

	if(h){
		tmp = h;
		h = h->next;
		free(tmp);
	}

	return h;
}

void cancellatutto(lista_t** h){
	while(*h)
		*h = pop(*h);
}
