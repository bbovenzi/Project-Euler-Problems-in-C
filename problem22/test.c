#include <stdio.h>
#include <string.h>

int main(){
	char *c = "COLIN";
	int i, total;
	int sum = 0;
	int place = 938;
	for(i = 0; i < strlen(c); i++){
		sum += (int) c[i] - 64;
	}
	total = sum * place;
	printf("%d\n", total);
}