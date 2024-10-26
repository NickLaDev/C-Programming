#include <stdio.h>



void main(){

//Faça um algoritmo que leia e some 2 matrizes 10 X 20.

int matriz1[3][3]={0},matriz2[3][3]={0},soma={0};

printf("Digite a primeira matriz\n");
for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
    scanf("%d",&matriz1[i][j])
    }
}
printf("Digite a segunda matriz\n");
for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
    scanf("%d",&matriz2[i][j])
    }
}
for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
    soma[i][j] = matriz1[i][j] + matriz2[i][j];
    }
}
printf("A matriz soma eh:\n");

for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
    printf("%d",soma[i][j]);
    }
}

}