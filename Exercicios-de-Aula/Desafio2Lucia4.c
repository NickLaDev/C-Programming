#include "biblioteca.h"



int main(){

printf("Digite ate que numero da sequencia deseja vereficar a soma da sequencia\n");
scanf("%d",entrada1);
sequencia = 1;
antesequencia = sequencia;
anteantesequencia = antesequencia;

do{
    sequencia = anteantesequencia + antesequencia;
soma = soma + sequencia ;
anteantesequencia = antesequencia;
antesequencia = sequencia;
entrada1--;
printf("%d",entrada1);
} while(entrada1!=0);
printf("A soma da sequencia ate a posicacao desejada eh %d",soma); 
return 0; 
}