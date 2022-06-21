#include <stdio.h>
#include <stdlib.h>
/*ctype.h*/

#define MAXS 1000
int alfanumerico(char[]);

int main(int argc, char *argv[]){
	char string[MAXS+1];
	scanf("%s", string);
	printf("%d\n", alfanumerico(string));
	return 0;
}

int alfanumerico(char str[]){
	int count, i;

	/*isalpha*/
	for(i = 0, count = 0; str[i] != '\0'; i++)
		if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'Z'))
			count++;

	return count;
}
