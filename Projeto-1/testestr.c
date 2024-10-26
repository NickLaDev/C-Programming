#include <stdio.h>
#include <string.h>
#define t 11

int main(){
    char str[t];
    gets(str);
    printf("%d\n",strlen(str));
    puts(str);
}