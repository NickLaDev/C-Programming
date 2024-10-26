#include <stdio.h>
#define tamanho_vetor = 100


int main(){
int quantidade_jogos,inicio,fim,quantidade=0;
int ano[tamanho_vetor]={0};
int codigo[tamanho_vetor]={0};

printf("Digite quantos jogos deseja inserir\n");
scanf("%d",quantidade_jogos);
for(int i =0;i<quantidade_jogos;i++){
printf("Digite o codigo do %d jogo e o seu ano de lancamento\n",i+1);
scnaf("%d %d",&codigo[i],&ano[i]);
}
printf("Digite o intervalo de tempo\n");
scanf("%d %d",&inicio,&fim);
for(int i=0;i<quantidade;i++){
    if(ano[i]>inicio && ano[i]<fim){
        printf("O jogo com codigo %d e ano de lancamento %d esta no intervalo\n");
quantidade++;
    }
}
printf("Existem %d jogos no intervalo",quantidade);
}