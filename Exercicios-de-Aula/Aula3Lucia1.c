 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
int main(){

setlocale(LC_ALL,"portuguese");
int numero_1,numero_2,opr;

printf("Digite os 2 números desejados\n\t");
scanf("%d %d",&numero_1,&numero_2);
printf("Digite a Operação desejada,'1 para média, 2 a diferença, 3 o produto e 4 a divisão'\n\t");
scanf("%d",&opr);

switch(opr){

case 1 :
printf("A média dos nmeros eh:'%d'\n\t",(numero_1+numero_2)/2);
break ;

case 2 :
printf("A diferenca entre os numero eh:'%d'",abs(numero_1-numero_2));
break;

case 3 :
printf("O produto dos numeros eh '%d'",numero_1*numero_2);
break;
 
 case 4 :
 printf("A divisao deles eh'%d'",numero_1/numero_2);
break;

default : 
printf("Nenhuma das opcoes");

}

}