#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(){
	// - - - preliminary pythagorean theorem math - - - 
	// a = m^2 - n^2
	// b = 2*m*n
	// c = m^2 + n^2
	// m > n
	//1000 = 2*m*(m+n) = 2*m*m + 2*m*n

	//n = (1000 - 2*m*m)/(2*m)

	int m = sqrt(500);
	int product = 1;
	int n;
	bool found = false;

	while(found == false){
		if((1000 - 2*m*m) % (2*m) == 0){
			n = (1000 - 2*m*m) / (2*m);
			if(n < m){
				found = true;
				continue;
			}
		}
		m--;
	}

	product = (m*m - n*n)*(2*m*n)*(m*m + n*n);
	printf("%d\n", product);

	return 0;
}