//#include "biblioteca.h"
#include <stdio.h>
#include <stdlib.h>
int main(){

int entrada1=0,entrada2=0;
printf("Digite seu sálario e seu plano de trabalho\n");
scanf("%d %d",&entrada1, &entrada2);

switch (entrada2){

case 1:
    printf("Seu novo salario eh %d \n",(int)(entrada1* 1.1 ));
    break;

case 2:
    printf("Seu novo salario eh'%d'\n",(int)(entrada1*1.15));
    break;

case 3 :
    printf("Seu novo salario eh '%d'\n",(int)(entrada1*1.2));
    break;

defaut :
    printf("Entrada Invalida\n");

}

}
