#include "biblioteca.h"



int main(){
int intervalo1=0,intervalo2=0,intervalo3=0,intervalo4=0;
while(entrada1>=0){
printf("Digite o valor que deseja\n");
scanf("%d",&entrada1);
if(entrada1>=0 && entrada1<=25) intervalo1 ++;
if(entrada1>=26 && entrada1 <=50) intervalo2++;
if(entrada1 >=51 && entrada1 <=75) intervalo3++;
if(entrada1 >=76 && entrada1 <= 100) intervalo4++;
printf("Ate o momento foram digitados:\n%d numeros no primeiro intervalo\n %d no segundo\n %d no terceiro\n e %d no quarto\n",intervalo1,intervalo2,intervalo3,intervalo4);
}
printf("Programa encerrado\n\t");
return 0;
}
