#include <stdio.h>
#include <locale.h>
#define t_pop 2

typedef struct{

    int idade,filhos;
    float salario;
    int sexo;

}dados;

void recebe_Info(float *salario_Minimo, dados pop[t_pop]){


    printf("Começe digitando os dados da população\n");
    for(int i=0;i<t_pop;i++){
        printf("Digite a IDADE da pessoa %d\n",i+1);
        scanf("%d",&pop[i].idade);
        printf("Digite o número de FILHOS dessa pessoa\n");
        scanf("%d",&pop[i].filhos);
        printf("Digite o SALÁRIO dessa pessoa\n");
        scanf("%f",&pop[i].salario);
        printf("Digite o SEXO dessa pessoa:\n");
        printf("OBS: 0 para MASCULINO e 1 para FEMININO\n");
        scanf("%d",&pop[i].sexo);
    }
    printf("Para finalizar digite o salário mínimo dessa população:\n");
    scanf("%f",&*salario_Minimo);
}

float mf_Im(dados pop[],int salario_Minimo){

    float media=0;
    float count=0;

for(int i=0;i<t_pop;i++){
    if(salario_Minimo>pop[i].salario && pop[i].sexo == 1){
        media += pop[i].idade ;
        count++;
    }
    media = media/count;
}
return media;
}

float m_Salarial(dados pop[]){
    float media=0;

    for(int i=0;i<t_pop;i++){
        media += pop[i].salario;
    }
    media = media/t_pop;
return media;
}

float m_Filhos(dados pop[]){
    float media=0;

    for(int i=0;i<t_pop;i++){
        media += pop[i].filhos;
    }
    media = media/t_pop;
    return media;
}

int menor_If(dados pop[]){
    int m_Idade = 100;
    for(int i=0;i<t_pop;i++){
        if(pop[i].sexo == 1 && m_Idade > pop[i].idade){
            m_Idade = pop[i].idade;
        }
    }
    return m_Idade;
}

int main(void){

    setlocale(LC_ALL,"portuguese");

    dados pop[t_pop];
    float salario_Minimo,mif_Im,media_Spop,media_Filhos;
    int menor_Idadef;

//Media das idades das mulheres com salario inferior ao mínimo
//A Media do salário da população
//A Media do número de filhos
//A Menor idade do sexo feminino

    recebe_Info(&salario_Minimo,pop);
    mif_Im = mf_Im(pop, salario_Minimo);
    media_Spop = m_Salarial(pop);
    media_Filhos = m_Filhos(pop);
    menor_Idadef = menor_If(pop);

    printf("A média das idades das mulheres com salário inferior ao mínimo é: %f\n",mif_Im);
    printf("A média salarial da população é: %f\n",media_Spop);
    printf("A média de filhos da população é: %f\n",media_Filhos);
    printf("A menor idade do sexo feminino é: %d\n",menor_Idadef);

}
