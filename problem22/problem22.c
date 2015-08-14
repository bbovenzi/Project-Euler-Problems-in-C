#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int compare (const void * a, const void * b ) {
  return strcmp(*(char **)a, *(char **)b);
}

int main()
{
	int totalsum = 0;
	int charsum = 0;
   char namelist[47000];
   FILE * fp;
   int i = 0;
   int j = 0;
   int size = 5163;
   char *names[size];


   fp = fopen ("names.txt", "r");
   fscanf(fp, "%s", namelist);
   
   char* buffer;
   buffer = strtok (namelist, "\",\"");
   while (buffer) {
   		if( i >= size)
   			break;
		names[i] = buffer;
		i++;
	    buffer = strtok (NULL, "\",\"");
	    while (buffer && *buffer == '\040')
	        buffer++;
   }
   fclose(fp);

   size_t strings_len = sizeof(names) / sizeof(char *);
   qsort(names, strings_len, sizeof(char *), &compare);

   for(i = 0; i < size; i++){
   		charsum = 0;
   		for( j = 0; j < strlen(names[i]); j++){
   			charsum+= (int) names[i][j] - 64;
   		}
   		totalsum+= charsum * (i+1);
   }

   printf("%d\n", totalsum);
   return(0);
}
