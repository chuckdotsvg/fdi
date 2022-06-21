#include <stdio.h>
#include <stdlib.h>

#define ALPH 26

int pangramma(char[]);
char lower(char);

int main(int argc, char* argv[]){
	if(argc == 2){
		printf("%d\n", pangramma(argv[1]));
	}else
		printf("ERR\n");

	return 0;
}

char lower(char c){
	if(c >= 'A' && c <= 'Z')
		c += 'a' - 'A';
}

int pangramma(char str[]){
	int flag, i, count[ALPH];

	for(i = 0; i < ALPH; i++)
		count[i] = 0;
	
	for(i = 0; str[i] != '\0'; i++)
		count[lower(str[i]) - 'a']++;

	for(i = 0, flag = 1; flag && i < ALPH; i++)
		if(!count[i])
			flag = 0;

	return flag;
}
