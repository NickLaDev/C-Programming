#include <stdio.h>
#include <locale.h>

void pares_Intervalo(int entrada_1, int entrada_2){

if(entrada_1 > entrada_2){ 
    int temp = entrada_1;
    entrada_2 = entrada_1;
    entrada_1 = temp ;
}
while(entrada_2 + 1 != entrada_1){

    if(entrada_1 %2 == 0){
        printf("%d\n",entrada_1); 
    }
    entrada_1 ++;
}
}

int main(){

int entrada_1=0,entrada_2=0;
setlocale(LC_ALL,"portuguese");

puts("Digite os 2 valores que deseja saber quantos pares há no intervalo\n");
scanf("%d %d",&entrada_1,&entrada_2);

pares_Intervalo(entrada_1,entrada_2);
    
}