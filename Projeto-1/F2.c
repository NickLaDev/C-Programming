#include <stdio.h>
#include <locale.h>

float calculo(float entrada_1, float entrada_2,float entrada_3){
    float calculo = (entrada_1*entrada_1)+entrada_2+entrada_3;
    return calculo;
}

void calculo2(float entrada_1, float entrada_2, float entrada_3, float *r){

   float calculo = (entrada_1*entrada_1)+entrada_2+entrada_3;
   *r = calculo;
}

int main(){
    float entrada_1=0,entrada_2,entrada_3=0;
    float r = 0;
    printf("Digite os valores que deseja utilizar no cálculo\n");
    scanf("%f %f %f", &entrada_1,&entrada_2,&entrada_3);
    r = calculo(entrada_1,entrada_2,entrada_3);
    printf("O valor calculado foi: %f",r);
    return 0;
}