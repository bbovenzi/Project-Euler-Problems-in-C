#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int length = 0;

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
        str[len++]=ch;
        if(len==size){
            str = realloc(str, sizeof(char)*(size+=16));
            if(!str)return str;
        }
    }
    str[len++]='\0';

    return realloc(str, sizeof(char)*len);
}

int main(void){
    char *m;

    FILE* fp = fopen ("names.txt", "r");
    printf("input string : ");
    m = inputString(fp, 10);
    char *names[length];
    int i;
    for(i = 0; i < strlen(m); i++){

    }
    printf("%s\n", m);
    free(m);
    return 0;
}