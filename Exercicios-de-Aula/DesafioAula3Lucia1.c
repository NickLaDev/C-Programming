#include "biblioteca.h"


int main(){

int fatorial=1;

printf("Digite o valor que deseja saber o fatorial\n");
scanf("%d",&entrada1);

while(entrada1!=0){
    fatorial = fatorial * entrada1;
    entrada1--;
}
printf("%d",fatorial);
}
