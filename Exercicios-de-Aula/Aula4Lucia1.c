#include "biblioteca.h"



int main(){
int intervalo1=0,intervalo2=0,intervalo3=0,intervalo4=0;
while(1){
prinf("Digite o valor que deseja\n");
scanf("%d",&entrada1);
if(entrada1>=0 && entrada1<=25) intervalo1 ++;
else if(entrada1>=26 && entrada1 <=50) intervalo2++;
else if(entrada1 >=51 && entrada1 <=75) intervalo3++;
else (entrada1 >=76 && entrada1 <= 100) intervalo4++;
printf("Ate o momento foram digitados %d numeros no primeiro intervalo %d, no segundo %d, no terceiro e %d no quarto");
}
}