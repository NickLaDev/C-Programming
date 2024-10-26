#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tamanho_vetor 25
#define posicao_inicial 10
#define limite_de_tentativas 3
#define limite_de_deslisamentos 4

#define RESET   "\033[0m"
#define BLACK   "\033[1;30m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define WHITE   "\033[1;37m"

int main() {
    system("chcp 65001");
    system("cls");
    setlocale(LC_ALL,"portuguese");

    const int barra[tamanho_vetor] = {1, 2, 5, 7, 8, 1, 2, 5, 7, 8, 1, 2, 5, 7, 8, 1, 2, 5, 7, 8, 1, 2, 5, 7, 8};
    const int senha[5] = {2, 2, 2, 2, 2};
    const int digitos[5] = {1, 2, 5, 7, 8};


    for (int numero_de_tentativas = 0;numero_de_tentativas<=limite_de_tentativas;numero_de_tentativas++) {
        int senha_digitada[5] = {0};
        int numero_deslisamentos = 0;
        int posicao_atual = posicao_inicial;

        system("cls");

        printf("%sComece a tentar abrir o cofre, digite a cada passo a próxima posição para gerar a senha\n\n%s", GREEN, RESET);
        printf("%sDigite a próxima posição do controle\n\t\t%s", YELLOW, RESET);

        int proxima_posicao;
        scanf("%d", &proxima_posicao);

        proxima_posicao--;
        numero_deslisamentos++;

        while (numero_deslisamentos < limite_de_deslisamentos && proxima_posicao >= 0 ) {
            if (posicao_atual > proxima_posicao && proxima_posicao < tamanho_vetor) {
                for ( posicao_atual; posicao_atual > proxima_posicao; posicao_atual--) {
                    for (int j = 0; j < 5; j++) {
                        if (barra[posicao_atual] == digitos[j]) {
                            senha_digitada[j]++;
                            break;
                        }
                    }
                }
            } else if (posicao_atual < proxima_posicao && proxima_posicao < tamanho_vetor) {
                for ( posicao_atual; posicao_atual < proxima_posicao; posicao_atual++) {
                    for (int j = 0; j < 5; j++) {
                        if (barra[posicao_atual] == digitos[j]) {
                            senha_digitada[j]++;
                            break;
                        }
                    }
                }
            } else {
                printf("%sOperação inválida%s\n", RED, RESET);
                numero_deslisamentos--;
            }

            printf("%sDigite a próxima posiçãodo controle\n\t\t%s", YELLOW, RESET);
            scanf("%d", &proxima_posicao);
            numero_deslisamentos++;
        }

        printf("%sA senha obtida foi:",BLUE);

        for (int i = 0; i < 5; i++) {
            printf(" %d", senha_digitada[i]);
        }

        int senha_correta = 1;

        for (int i = 0; i < 5; i++) {
            if (senha_digitada[i] != senha[i]) {
                senha_correta = 0;
                break;
            }
        }

        if (senha_correta) {
            printf("\n\n%sA senha está correta e o cofre foi aberto!%s", GREEN, RESET);
            break;
        } else {

            if (numero_de_tentativas+1 == limite_de_tentativas) {
                printf("\n\n%sVocê atingiu o limite de tentativas, o cofre não foi aberto e a última senha está incorreta%s\n\t\t", RED, RESET);
                break;
            }

            printf("\n\n%sA senha está incorreta, tente novamente.\nVocê possui mais %d tentativas%s\n\n", RED, limite_de_tentativas - numero_de_tentativas - 1, RESET);
            printf("Digite qualquer tecla para recomeçar\n\n");
            fflush(stdin);
            getchar();
        }
    }

    return 0;
}
