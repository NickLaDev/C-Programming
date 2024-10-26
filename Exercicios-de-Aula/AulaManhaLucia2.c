#include "biblioteca.h"


int main()
{
    printf("Digite o Numero Desejado\n");
    scanf("%d",&entrada1);
    while(entrada1!=0){
        if(entrada1%2==0){
            soma = soma + entrada1;
        }
        entrada1--;
    }
    printf("A Soma dos pares eh %d\nw",soma);

}
