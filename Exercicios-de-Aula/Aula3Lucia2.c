#include "biblioteca.h"


int main(){
setlocale(LC_ALL,"portuguese");
printf("Digite o c�digo do produto\n");
scanf("%d",&entrada1);

if(entrada1==1) printf("Alimento n�o perecivel\n");
else if(entrada1 == 2 || entrada1 == 3 || entrada1 ==4) printf("Alimento perecivel\n");
else if(entrada1 == 5 || entrada1 == 6) printf("Vestuario\n");
else if(entrada1 == 7) printf("Higiene pessoal\n");
else if(entrada1>=8 || entrada1 <=15) printf("Limpeza e Utens�lios Dom�sticos\n");
else printf("C�digo Inv�lido\n");
}
