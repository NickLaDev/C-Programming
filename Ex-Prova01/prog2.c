#include <stdio.h>



int main(){

int entrada=0;
do{
    printf("Digite um valor\n");
    scanf("%d",&entrada);
}while(entrada<10);
printf("Os %d primeiros multiplos de 5 sao\n",entrada);
for(int i = 1; i<entrada;i++ ){
printf("%d\n",i*5);
}

}