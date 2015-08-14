#include <stdio.h>

int main(){
	int tri_num = 1;
	int j,i = 2;
	int divisors;
	int limit = 500;

	while(divisors <= limit){
		tri_num+=i;
		i++;
		printf("%d\n", tri_num);
		divisors = 1;
		for(j = 1; j < (tri_num/2); j++){
			if(tri_num % j == 0){
				divisors+=2;
			}
		}
	}
	printf("%d\n", tri_num);
	return 0;

}