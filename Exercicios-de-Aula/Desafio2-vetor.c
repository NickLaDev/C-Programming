#include <stdio.h>

#define t_vetor 50

int numero_digitado[t_vetor];

int inverter_numero(numero_digitado){
    int numero_invertido_vetor[t_vetor],numero_invertido;

    for(int i=0;i<t_vetor;i++){
        numero_invertido_vetor[i] = numero_digitado[t_vetor];

    numero_invertido = numero_invertido*10 + numero_invtertido_vetor[i];
    }



    return numero_invertido;
}


int main(){

printf("Digite o numero que deseja inverter\n");
scnaf("%d",&numero_digitado);
inverter_numero(numero_digitado);
printf("%d",inverter_numero);

}
