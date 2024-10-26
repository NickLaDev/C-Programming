#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tamanho_vetor 25
#define posicao_inicial 9
#define limite_de_tentativas 3
#define limite_de_deslisamentos 4
#define vermelho "\x1b[31m"
#define verde "\x1b[32m"
#define centralizar "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t"
#define reset "\x1b[0m"
#define linha_barra "-----------------------------------------------------"
#define linha_inicio " -----------------------------------------------------------------------------------------"
#define t_nome 15
#define direita "\t\t"

int main() {

    setlocale(LC_ALL,"portuguese");

    const int barra[tamanho_vetor] = {1,2,2,5,8,7,1,8,7,2,5,7,7,1,8,2,1,5,7,1,5,5,8,7,2};
    const int senha[5] = {4,3,4,8,2};
    const int digitos[5] = {1, 2, 5, 7, 8};
    char nome[t_nome];

    printf(centralizar "Para come�ar, digite seu nome: ");
    fflush(stdin);
    gets(nome);
    system("cls");

    printf("\n\n\n\n\n\n\n\n\n\n\t Seja Bem Vindo, %s, para utiliza��o correta do cofre, seguem as intru��es:\n\n",nome);
    printf("\t 1. O Cofre � uma barra deslizante de 25 posi��es que, ao ser girado, gera a senha.\n");
    printf("\t 2. O Cofre possui um limite de 4 deslisamentos da barra que gera a senha.\n");
    printf("\t 3. O Cofre possui um limite de 3 tentativas de senha, caso esse limite seja execedido, o cofre � trancado.\n");
    printf("\t 4. As posi��es da barra do cofre variam de 1 a 25, o padr�o inicial � no n�mero 11.\n");
    printf("\t 5. Para parar a verifica��o da senha, digite 0 ou um valor negativo.\n");
    printf("\t 6. Caso um n�mero n�o permetido for digitado, uma mensagem ser� exebida e a tentativa n�o ser� contabilizada.\n");
    printf("\t 7. Uma barra que representa a barra deslizante ser� exebida ao lado do programa, indicando sua posi��o atual na cor vermelha.\n\n");
    printf("\t Todos os avisos e recomenda��es foram dados, por favor %s digite qualaquer tecla para come�ar.\n",nome);
    fflush(stdin);
    getchar();


    for (int numero_de_tentativas = 0; numero_de_tentativas < limite_de_tentativas; numero_de_tentativas++) {
        int senha_digitada[5] = {0};
        int numero_deslisamentos = 0;
        int posicao_atual = posicao_inicial;

        system("cls");
        int proxima_posicao = posicao_inicial;

        while (numero_deslisamentos < limite_de_deslisamentos) {

                  printf("\n %s, digite a pr�xima posi��o do controle\n\t\t",nome);

            printf("\t\t\t\t" linha_barra "\n\t\t\t\t\t\t|");
            for(int i = 0; i < tamanho_vetor; i++) {
                if(i == proxima_posicao) {
                    printf(vermelho"|%d|"reset"|", barra[i]);
                } else {
                    printf("%d|", barra[i]);
                }
            }
            printf("\n\t\t\t\t\t\t" linha_barra "\n\t\t");

            scanf("%d", &proxima_posicao);
            proxima_posicao--;
            numero_deslisamentos++;

            if(proxima_posicao<0){
                break;
            }else if (posicao_atual > proxima_posicao && proxima_posicao < tamanho_vetor) {
                for (int i = posicao_atual; i >= proxima_posicao; i--) {
                    for (int j = 0; j < 5; j++) {
                        if (barra[i] == digitos[j]) {
                            senha_digitada[j]++;
                            break;
                        }
                    }
                }
                posicao_atual = proxima_posicao + 1 ;
            } else if (posicao_atual < proxima_posicao && proxima_posicao < tamanho_vetor) {
                for (int i = posicao_atual; i <= proxima_posicao; i++) {
                    for (int j = 0; j < 5; j++) {
                        if (barra[i] == digitos[j]) {
                            senha_digitada[j]++;
                            break;
                        }
                    }
                posicao_atual = proxima_posicao - 1;
                }
            }else {
                 printf(vermelho"Opera��o inv�lida\n"reset);
                numero_deslisamentos--;
                    }
        }

system("cls");

        int senha_correta = 1;

        for (int i = 0; i < 5; i++) {
            if (senha_digitada[i] != senha[i]) {
                senha_correta = 0;
                break;
            }
        }

        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("@@@                                              @@@\n");
printf("@@     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@     @@\n");
printf("@@  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  @@\n");
printf("@@  @@                                        @@  @@\n");
printf("@@  @@                                        @@  @@\n");
printf("@@  @@                                      @@@@@@@@\n");
printf("@@  @@                                      @@ @@@@@\n");
printf("@@  @@                     @@@@@@@          @@ @@@@@\n");
printf("@@  @@    @@@@@@@       @@@@@@@@@@@@@@      @@ @@@@@\n");
    printf("@@  @@   @@ @@@ @@    @@@@@@  @@  @@@@@@    @@@@@@@@\n");
    printf("@@  @@  @@@@@ @@@@   @@@@ @@@@@@@@@ @@@@@     @@  @@\n");
    printf("@@  @@   @@@@ @@@   @@@@@@@@@@  @@@ @@@@@@    @@  @@ \n");
    printf("@@  @@    @@@ @@   @@@@  @@@      @@  @@@@    @@  @@\n");
    printf("@@  @@     @@ @@   @@@@@@@@        @ @@@@@    @@  @@\n");
    printf("@@  @@     @@ @@   @@@@  @@       @@   @@@    @@  @@");
    printf(direita"A senha digitada foi:");
   for(int i=0;i<5;i++){
    printf(" %d",senha_digitada[i]);
   }
        if (senha_correta) {
            printf("\n@@  @@     @@ @@    @@@@@@@@@    @@ @@@@@@    @@  @@");
            printf("\n@@  @@     @@ @@     @@@@ @@@@@@@ @  @@@@     @@  @@");
            printf(direita verde "Ela est� correta e o cofre foi aberto!"reset);
    printf("\n@@  @@     @@ @@      @@@@@@  @@  @@@@@@    @@@@@@@@\n");
    printf("@@  @@     @@@@         @@@@@@@@@@@@@@      @@ @@@@@\n");
    printf("@@  @@                     @@@@@@@@         @@ @@@@@\n");
    printf("@@  @@                                      @@ @@@@@\n");
    printf("@@  @@                                      @@@@@@@@\n");
    printf("@@  @@                                        @@  @@\n");
    printf("@@  @@                                        @@  @@\n");
    printf("@@   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   @@\n");
    printf("@@                                                @@\n");
    printf("@@                                                @@\n");
    printf("@@     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@     @@\n");
    printf("@@     @@@                                 @@     @@\n");
     printf("@@@@@@@@                                  @@@@@@@@     \n");
            return 0;
        } else {
printf("\n@@  @@     @@ @@    @@@@@@@@@    @@ @@@@@@    @@  @@");
 printf("\n@@  @@     @@ @@     @@@@ @@@@@@@ @  @@@@     @@  @@");
            printf(direita vermelho"A senha est� incorreta, tente novamente." reset);
            printf("\n@@  @@     @@ @@      @@@@@@  @@  @@@@@@    @@@@@@@@");
            printf("\n@@  @@     @@@@         @@@@@@@@@@@@@@      @@ @@@@@");
            printf(direita "Voc� possui mais %d tentativas", limite_de_tentativas - numero_de_tentativas - 1);
            printf("\n@@  @@                     @@@@@@@@         @@ @@@@@");
            printf(direita "Digite qualquer tecla para recome�ar");
    printf("\n@@  @@                                      @@ @@@@@\n");
    printf("@@  @@                                      @@@@@@@@\n");
    printf("@@  @@                                        @@  @@\n");
    printf("@@  @@                                        @@  @@\n");
    printf("@@   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   @@\n");
    printf("@@                                                @@\n");
    printf("@@                                                @@\n");
    printf("@@     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@     @@\n");
    printf("@@     @@@                                 @@     @@\n");
     printf("@@@@@@@@                                  @@@@@@@@     \n");

            fflush(stdin);
            getchar();
        }
    }
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tVoc� atingiu o limite de tentativas, o cofre n�o foi aberto.\n\t\t\t\t\t\t\t A �ltima senha est� incorreta\n\n\n\n\n\n\n\n\n\n\n\n");
    return 0;
}
