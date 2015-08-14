#include <stdio.h>

int main(){
	int fb1 = 1;
	int fb2 = 2;
	int tmp;
	int limit = 4000000;
	int sum = 0;
	while(fb2 < limit){
		tmp = fb2;
		fb2 = fb2 + fb1;
		fb1 = tmp;
		if(fb1 % 2 == 0){
			sum+=fb1;
		}

	}
	printf("%d\n", sum);
	return 0;
}