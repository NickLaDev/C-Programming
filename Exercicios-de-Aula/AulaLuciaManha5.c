#include "biblioteca.h"



int main(){
printf("Digite o numero que deseja calcular a tabuada\n");
    scanf("%d",&entrada1);
    for(int i=1;i<=10;i++){
        printf("%d x %d = %d \n",entrada1,i,entrada1*i);
    }
return 0;
}
