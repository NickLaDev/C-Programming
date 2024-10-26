#include "biblioteca.h"



int main(){

int maiores[2];
maiores[0]=0,maiores[1]=0;


printf("Digite 10 numeros\n");
for(int i=0;i<10;i++){
scanf("%d",&entradav[i]);
if(entradav[i]>maiores[0]){
    maiores[1]=maiores[0];
    maiores[0]=entradav[i];
}
}
printf("Os 2 maiores valores sao: %d %d\n",maiores[1],maiores[0]);
}
