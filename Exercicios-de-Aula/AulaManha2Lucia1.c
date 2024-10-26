#include <stdio.h>
#include <stdlib.h>


int main(){

int entrada[10],maior=0,posicao=0;
for(int i=0;i<10;i++){
    printf("Digite os valores de entrada da posicao %d\n",i+1);
    scanf("%d",&entrada[i]);
if(entrada[i]>=maior){
    maior=entrada[i];
    posicao=i;
}


}
printf("O Maior Valor eh:%d e ele esta na posicao: %d\n",maior,posicao+1);
}
