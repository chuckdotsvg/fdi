#include <stdio.h>
#include <stdlib.h>

#define BASE 10

int cifra(int);
int pari(int);

int main(int argc, char* argv[]){
	int num;

	scanf("%d", &num);
	printf("%d\n", cifra(num));
	printf("%d\n", pari(num));

	return 0;
}

int cifra(int n){
	int max, i, count[BASE];
	
	for(i = 0; i < BASE; i++)
		count[i] = 0;

	while(n){
		count[n%BASE]++;
		n /= BASE;
	}

	for(max = 1, i = max + 2; i < BASE; i += 2)
		if(count[i] >= count[max])
			max = i;

	return max;
}

int pari(int n){
	int max, i, count[BASE];
	
	for(i = 0; i < BASE; i++)
		count[i] = 0;

	while(n){
		count[n%BASE]++;
		n /= BASE;
	}
	
	for(i = 6, max = i+2; i >= 0; i -= 2)
		if(count[i] >= count[max])
			max = i;

	if(!count[max])
		for(max = 1, i = max + 2; i < BASE; i += 2)
			if(count[i] >= count[max])
				max = i;

	return max;
}
