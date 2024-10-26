#include "biblioteca.h"



int main(){

while(1){
        int fatorial=1;
    printf("Digite o valor que deseja calcular o fatorial\n");
    scanf("%d",&entrada1);
    if(entrada1<0){
        break;
    }
    while(entrada1!=0){
        fatorial = fatorial*entrada1;
        entrada1--;
    }
    printf("O fatorial do valor eh %d\n",fatorial);
}


}
