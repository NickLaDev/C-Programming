#include "biblioteca.h"



int main(){

do{
printf("Digite um numero\n");
scanf("%d",&entrada1);
soma = soma + entrada1;
if(entrada1 %2 == 0){
    pares++;
    somap += entrada1;
} else{
    impares++;
}
media = soma/(pares+impares);
mediap = somap/pares;
}while(entrada1!=0);
printf("Foram digitados %d valores pares, %d impares, sendo %.2f a media dos pares e %.2f a media geral\n",pares,impares,mpares,media);
return 0;
}
