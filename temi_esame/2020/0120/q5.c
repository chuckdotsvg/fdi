#include <stdio.h>
#include <stdlib.h>

typedef struct elem_{
	int num;

	struct elem_ *next;
}elem_t;

elem_t* rotate(elem_t*, int);
elem_t* push(elem_t*, int);
elem_t* append(elem_t*, int);
elem_t* pop(elem_t*);

int main(int argc, char *argv[]){
	return 0;
}

elem_t* rotate(elem_t* h, int dir){
	elem_t* tmp;

	if(dir){
		for(tmp = h; tmp->next->next; tmp = tmp->next);
		h = push(h, tmp->next->num);
		free(tmp->next);
		tmp->next = NULL;
	}else{
		h = append(h, h->num);
		h = pop(h);
	}

	return h;
}
