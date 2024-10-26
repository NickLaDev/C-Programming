#include <stdio.h>

#define t_vetor 5

int main(){

int vetor1[t_vetor],vetor2[t_vetor],vetor_soma[t_vetor];

printf("Digite os valores que deseja para o primeiro vetor\n");
for(int i=0;i<t_vetor;i++){
    scanf("%d",&vetor1[i]);
}
printf("Digite os valores que deseja para o segundo vetor\n");
for(int i=0;i<t_vetor;i++){
    scanf("%d",&vetor2[i]);
}

printf("Os valores dos 2 vetores somados, em sequencia, sao:\n");

for(int i=0;i<t_vetor;i++){
    vetor_soma[i] = vetor1[i] + vetor2[i];
    printf("%d\n",vetor_soma[i]);
}


}
