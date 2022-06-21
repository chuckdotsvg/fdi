#include <stdio.h>
#include <stdlib.h>

void minmaxstr(char[], char*, char*);
void maiusc(char[], char*, char*);
char lower(char);

int main(int argc, char* argv[]){
	char least, most;

	if(argc == 2){
		maiusc(argv[1], &least, &most);
		printf("%c %c\n", least, most);
	}else
		printf("Errore argomenti\n");

	return 0;
}

void minmaxstr(char str[], char* min, char* max){
	char high, low;
	int i;
	
	high = low = str[0];
	for(i = 1; str[i] != '\0'; i++){
		if(str[i] > high)
			high = str[i];
		else if (str[i] < low)
			low = str[i];
	}

	*min = low;
	*max = high;
}

void maiusc(char str[], char* min, char* max){
	char high, low;
	int i;
	
	high = low = lower(str[0]);
	for(i = 1; str[i] != '\0'; i++){
		str[i] = lower(str[i]);
		if(str[i] > high)
			high = str[i];
		else if (str[i] < low)
			low = str[i];
	}
	*min = low;
	*max = high;
}

char lower(char c){
	if(c < 'a')
		c += 'a' - 'A' ;

	return c;
}
