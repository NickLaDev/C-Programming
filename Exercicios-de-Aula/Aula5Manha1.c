#include <stdio.h>


int main(){

char normal[5];
char invertido[5];
int posicao=4;

printf("Digite os valores da sting que deseja inverter\n");

fflush(stdin);
gets(normal);

for(int i=0;i<5;i++){
    posicao = posicao - i;
    invertido[posicao]=normal[i];
}
printf("A string normal eh: %s\n",normal);
printf("String invertida %s\n",invertido);



return 0;
}
