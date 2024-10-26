#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define tamanho_vetor 25
#define posicao_inicial 10
#define limite_de_tentativas 3
#define limite_de_deslisamentos 4

//Codigo que leia, dentro de um vetor, e dando, as posiçoes desejadas, leia quantas vezes os numeros da barra se
//repetem. A quantidade de vezes que eles se repetem deve ser armazenada e ela formara uma senha.
//Os numeros que constituem a barra sao: 1,2,5,7 e 8


int main(void){

system("chcp 65001");
system("cls");

setlocale(LC_ALL,"portuguese");

//Declara��o das constantes
const int barra[tamanho_vetor]={1,2,5,7,8,1,2,5,7,8,1,2,5,7,8,1,2,5,7,8,1,2,5,7,8};
const int senha[5]={2,2,2,2,2};
const int digitos[5]={1,2,5,7,8};
//Declara��o das variaveis que n�o necessitam ser zeradas a cada nova tentativa de senha
int numero_deslisamentos = 0;

//In�cio do programa
for(int tentativa=0;tentativa<limite_de_tentativas;tentativa++){

//Declara��o de vari�veis que necessitam ser zeradas a cada nova tentativa de senha
int senha_digitada[5]={0,0,0,0,0};
int posicao_atual = posicao_inicial;
int proxima_posicao = 0;
system("cls");//Comando para limpar console a cada nova senha

//Interface inicial com o us�rio
printf("Come�e a tentar abrir o cofre, digite a cada passo � proxima posi��o para gerar a senha\n\n");
printf("Digite a proxima posi��o do controle\n\t\t");
scanf("%d",&proxima_posicao);

numero_deslisamentos++;//Variavel que conta o numero m�ximo de deslisamentos

while(numero_deslisamentos<limite_de_deslisamentos && proxima_posicao>=0){
//loop que mant�m o programa at� o usu�rio parar de realizar deslisamentos

if(posicao_atual > proxima_posicao){
//Verefica se o deslisamento foi feito para DIREITA ou para esquerda

for(posicao_atual;posicao_atual>=proxima_posicao;posicao_atual--){
for(int i=0;i<5;i++){
//Verefica qual número está inserido na quela posição da barra e coloca na senha

if( barra[posicao_atual] == digitos[i] ){
    senha_digitada[i]++;
    break;
}
}
}

}else if(posicao_atual < proxima_posicao){
//Verifica se o deslisamento foi feito para ESQUERDA ou para direita

 for(posicao_atual;posicao_atual<=proxima_posicao;posicao_atual++){
  for(int i=0;i<5;i++){
//Verifica qual número está inserido na barra na quela posição e coloca na senha

   if( barra[posicao_atual] == digitos[i]){
    senha_digitada[i]++;
    break;
}
}
}

}else{
    //Verefica se a operação inserida foi válida, como colocar a mesma posição duas vezes
    printf("Opera��o inv�lida\n");
    numero_deslisamentos--;
}

printf("Digite a pr�xima posi��o do controle\n\t\t");
scanf("%d",&proxima_posicao);
numero_deslisamentos++;
}
//Diz ao usuário a senha que foi inserida
printf("A senha obtida foi :");
for(int i=0;i<5;i++){
printf(" %d",senha_digitada[i]);
}

for(int i=0;i<5;i++){
    if(senha_digitada[i]!=senha[i]){
        //Verefica se a senha digitada está correta ou ERADA
        if(tentativa==limite_de_tentativas-1){
            //Diz ao usuário que o limite de tentativas foi exedido
         printf("\n\nVoc� atingiu o limite de tentativas, o cofre n�o foi aberto e a �ltima senha est� incorreta\n\t\t");
         break;
        }
        //Interface com usuário para continuar tentando novas senhas
        printf("\n\nA senha est� incoreta, tente novamente.\nVoc� possui mais %d tentativas\n\n",limite_de_tentativas-tentativa-1);
        printf("Digite qualquer tecla para recome�ar\n\n");
        fflush(stdin);
        scanf("%*c");
        posicao_atual = posicao_inicial;
        numero_deslisamentos = 0;
        break;

    } else {
        //Interface com usuário caso a senha inserida estiver CORRETA
        printf("\t\t\n\nA senha est� correta e o cofre foi aberto!");
        tentativa = limite_de_tentativas;
        numero_deslisamentos = limite_de_deslisamentos;
        break;
    }
}
}
return 0;
}//Fim do programa
