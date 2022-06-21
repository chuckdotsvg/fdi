#include <stdio.h>
#include <stdlib.h>

#define MAXS 20
#define INF 8
#define SUP 15
#define MUST "$#%&"

int valido(char[], int, int, char[]);

int main(){
	char str[MAXS+1];
	
	scanf("%s", str);

	printf("%d\n", valido(str, INF, SUP, MUST));

	return 0;
}

int valido(char username[], int min, int max, char speciali[]){
	int isok, flag, i, j;
	
	isok = 0;
	flag = 0;

	for(i = 0; username[i] != '\0'; i++)
		for(j = 0; !flag && j < speciali[j]; j++)
			if(username[i] == speciali[j])
				flag = 1;

	if(flag && i >= min && i <= max)
		isok = 1;

	return isok;
}
