#include <stdio.h>
#include <stdlib.h>


int main(){

int entrada1[20],entrada2[20],produto[20],entrada3=0;
printf("Digite o tamanho do vetor que deseja, com o maximo de 20\n");
scanf("%d",&entrada3);
for(int i=0;i<entrada3;i++){
    printf("Digite o valor da posicao %d do vetor 1\n",i+1);
    scanf("%d",&entrada1[i]);
    printf("Digite o valor da posicao %d do vetor 2\n",i+1);
    scanf("%d",&entrada2[i]);
    produto[i] = entrada1[i] * entrada2[i];
}
printf("O vetor 1 digitado foi:");
for(int i=0;i<entrada3;i++){
    printf("%d\t",entrada1[i]);
}printf("\nO vetor 2 digitado foi:");
for(int i=0;i<entrada3;i++){
    printf("%d\t",entrada2[i]);
}printf("\nO vetor produto de 1 por 2 eh :");
for(int i=0;i<entrada3;i++){
    printf("%d\t",produto[i]);
}

}
