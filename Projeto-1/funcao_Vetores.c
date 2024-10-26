#include <stdio.h>
#include <locale.h>
#define t_vetor 2

void func1(int entrada[], int* pares, int* m5){

for(int i=0;i<t_vetor;i++){
    if(entrada[i]%2==0){
        *pares = *pares + 1;
    }if(entrada[i]%5==0){
        *m5 = *m5 + 1;
    }
}
}
void func2(int entrada[], int* media, int* maiores){

int soma =0;

    for(int i=0;i<t_vetor;i++){
    soma += entrada[i];
    }
    *media = soma/t_vetor;
    for(int i=0;i<t_vetor;i++){
        if(entrada[i]>*media){
            *maiores = *maiores + 1;
        }
    }
}

int main(){

setlocale(LC_ALL,"portuguese");

int entrada[t_vetor],maiores=0,media=0,pares=0,m5=0;
printf("Digite os valores do vetor:\n");

for(int i=0;i<t_vetor;i++){
    printf("Na posição %d:",i+1);
scanf("%d",&entrada[i]);
}
func1(entrada,&pares,&m5);
func2(entrada,&media,&maiores);

printf("Existem %d pares, %d divisores de 5, a media eh:%d e existem %d numeros maiores que a media no vetor",pares,m5,media,maiores);

}
