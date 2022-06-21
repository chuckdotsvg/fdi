#include <stdio.h>
#include <stdlib.h>

int diff(FILE*, FILE*);

int main(int argc, char *argv[]){
	return 0;
}

int diff(FILE* f1, FILE* f2){
	int flag;
	char c1, c2;

	flag = 0;

	fread(&c1, sizeof(char), 1, f1);
	fread(&c2, sizeof(char), 1, f2);

	while(!flag && !(feof(f1) || feof(f2))){
		if(c1 != c2)
			flag = 1;

		fread(&c1, sizeof(char), 1, f1);
		fread(&c2, sizeof(char), 1, f2);
	}

	return flag && feof(f1) && feof(f2);
}
