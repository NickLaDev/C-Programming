#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){

setlocale(LC_ALL,"portuguese");

char entrada[6]="",invertido[6]="";

printf("Digite a string que deseja inverter\n");
gets(entrada);
for(int i=0;i<5;i++){
invertido[4-i]=entrada[i];
}
    invertido[5]= '\0';
printf("A string digitada foi: %s, e ela invertida é: %s)",entrada,invertido);

}