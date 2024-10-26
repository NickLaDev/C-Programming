#include "biblioteca.h"



int main(){

printf("Digite os numeros que deseja vereficar seus divisores por 4\n");
scanf("%d",&entrada1);

while(entrada1!=0){
    entrada1--;
    if(entrada1 % 4 == 0 && entrada1 !=0) printf("O Numero %d eh divisivel por 4\n",entrada1);
}
    return 0;
}
