#include "biblioteca.h"

int main(){


printf("Digite o número que deseja e o valor a se elevar\n");
scanf("%d %d",&entrada1,&entrada2);
while(entrada2!=1){

entrada1 = (int)(entrada1*entrada1) ;

entrada2--;

}
printf("O Valor eh %d",entrada1);
}
