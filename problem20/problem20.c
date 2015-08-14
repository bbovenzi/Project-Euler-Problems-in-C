#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <inttypes.h>

unsigned __int128 factorial(x){
	if(x == 0){
		return 1;
	}
	return (x * factorial(x - 1));
}

int main(){
	unsigned __int128 fact = factorial(100);
	//printf("%" PRIu64 "\n", fact);
	uint64_t sum = 0;
	unsigned __int128 tmp;
	unsigned __int128 tens = 10;
	while(fact > 10){
		while(fact / tens > 10){
			tens *= 10;
		}
		tmp = fact / tens;
		sum += tmp;
		fact -= tmp * tens;
		tens /= 10;
	}
	sum += fact;

	printf("%" PRIu64 "\n", sum);
	return 0;
}