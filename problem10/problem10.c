#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

struct node{
	uint32_t prime;
	struct node *next;
};

int main(){
	uint64_t limit = 2000000;
	uint64_t sum = 2;
	uint32_t i,j; 
	struct node *root, *conductor;

	root = malloc( sizeof(struct node) );  
    root->next = 0;   
    root->prime = 2;

    for(i = 3; i < limit; i++){
    	conductor = root;
    	while(conductor != 0){
			if(i % conductor->prime == 0){
				break;
		    }
		    if(conductor->next == 0){
		    	printf("%d is prime\n", i);
		    	//printf("%d\n", sum);
		    	sum+=i;
		    	conductor->next = malloc( sizeof(struct node) );  
    			conductor = conductor->next;
    			conductor->prime = i;
    			conductor->next = 0;
    			break;
		    }
		    conductor = conductor->next;
		}
	}
	/*
	for(i = 3; i < limit; i++){
		for(j = 2; j < i; j++){
			if(i % j == 0){
				printf("%d is not prime\n", i);
				break;
			}else if(j == i-1){
				printf("%d is prime\n", i);
				sum+=i;
			}
		}
	}*/
	printf("%" PRIu64 "\n", sum);
	return 0;
}