
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int numero_digitado=0,numero_invertido=0,digito=0;

int inverternumero(numero_digitado){

while(numero_digitado!=0){
digito = numero_digitado % 10 ;
numero_invertido = digito + numero_invertido*10;
numero_digitado = numero_digitado - digito ;
numero_digitado = numero_digitado / 10;
}
}
//232 - 2 -  20 -

int main(){

printf("Digite o numero que deseja inverter\n");
scanf("%d",&numero_digitado);

inverternumero(numero_digitado);

printf("O Numero invertido eh:%d",numero_invertido);
}
