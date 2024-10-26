#include "biblioteca.h"

int main(){

printf("Digite a quantide de valores\n");
scanf("%d",&entrada1);
while(entrada1!=0){
    printf("Digite os valores\n");
    scanf("%d",&entrada2);
    if(entrada2%2==0){
        soma = soma + entrada2;
    }else{
    impares++;
    }
    entrada1--;
}
printf("A soma dos pares eh %d e tiveram %d numeros impares",soma,impares);

}
