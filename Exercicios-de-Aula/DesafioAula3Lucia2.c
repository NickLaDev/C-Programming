#include "biblioteca.h"


int main(){

printf("Digite a quantidade de números (no minimo 10) e os valores\n");
scanf("%d",&entrada1);

bool m1=true;


if(entrada1<10){
    entrada1=10;
}
while(entrada1!=0){
    scanf("%d",&entrada2);
    if(m1==true){
        menor = entrada2;
        m1=false;
    }
    if(maior<=entrada2){
        maior = entrada2;
    }else if(menor>=entrada2){
        menor = entrada2;
    }
    entrada1--;
}
printf("O menor valor inserido foi:%.f e o maior foi %.f\n",menor,maior);

}
