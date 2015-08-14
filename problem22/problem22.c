#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int length = 1;

int compare (const void * a, const void * b ) {
  return strcmp(*(char **)a, *(char **)b);
}

char *inputString(FILE* fp, size_t size){
//The size is extended by the input with the value of the provisional
    char *str;
    int ch;
    size_t len = 0;
    str = realloc(NULL, sizeof(char)*size);//size is start size
    if(!str)return str;
    while(EOF!=(ch=fgetc(fp)) && ch != '\n'){
        if(ch == ','){
            length++;
        }
        if(ch != '\"'){
            str[len++]=ch;
        }
        if(len==size){
            str = realloc(str, sizeof(char)*(size+=16));
            if(!str)return str;
        }
    }
    str[len++]='\0';

    return realloc(str, sizeof(char)*len);
}

int main(void){

    char *namelist;
    int totalsum = 0;
    int charsum = 0;
    int i = 0;
    int j;
    char* buffer;

    FILE* fp = fopen ("names.txt", "r");
    namelist = inputString(fp, 10);

    char *names[length];

    buffer = strtok (namelist, ",");
    while (buffer) {
        if( i >= length)
            break;
        names[i] = buffer;
        i++;
        buffer = strtok (NULL, ",");
    }

    size_t strings_len = sizeof(names) / sizeof(char *);
    qsort(names, strings_len, sizeof(char *), &compare);



    for(i = 0; i < length; i++){
        charsum = 0;
        for( j = 0; j < strlen(names[i]); j++){
            charsum+= (int) names[i][j] - 64;
        }
        totalsum+= charsum * (i+1);
    }
    printf("%d\n", totalsum);
    return 0;
}