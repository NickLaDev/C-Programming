#include <stdio.h>
#include <string.h>
#define s_str 8
#define s_strg 15

int main(){

    char str[s_str],str_g[s_strg];
    printf("Digite a palavra que deseja transformar em gaga\n");
    gets(str);

    for(int i=0;i<strlen(str);i++){
        str_g[i*2] = str[i];
        str_g[i*2 + 1] = str[i];
    }

    
}