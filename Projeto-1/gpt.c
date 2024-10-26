#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define tamanho_vetor 25
#define posicao_inicial 10
#define limite_de_tentativas 3
#define limite_de_deslisamentos 4

int main() {
    system("chcp 65001");
    system("cls");
    setlocale(LC_ALL,"portuguese");

    const int barra[tamanho_vetor] = {1, 2, 5, 7, 8, 1, 2, 5, 7, 8, 1, 2, 5, 7, 8, 1, 2, 5, 7, 8, 1, 2, 5, 7, 8};
    const int senha[5] = {2, 2, 2, 2, 2};
    const int digitos[5] = {1, 2, 5, 7, 8};

    int posicao_atual = posicao_inicial;

    for (int numero_de_tentativas = 0;numero_de_tentativas<limite_de_tentativas;numero_de_tentativas++) {
        int senha_digitada[5] = {0};
        int numero_deslisamentos = 0;

        system("cls");

        printf("Comece a tentar abrir o cofre, digite a cada passo a próxima posição para gerar a senha\n\n");
        printf("Digite a próxima posição do controle\n\t\t");

        int proxima_posicao;
        scanf("%d", &proxima_posicao);

        numero_deslisamentos++;

        while (numero_deslisamentos < limite_de_deslisamentos && proxima_posicao >= 0) {
            if (posicao_atual > proxima_posicao) {
                for ( posicao_atual; posicao_atual >= proxima_posicao; posicao_atual--) {
                    for (int j = 0; j < 5; j++) {
                        if (barra[posicao_atual] == digitos[j]) {
                            senha_digitada[j]++;
                            break;
                        }
                    }
                }
            } else if (posicao_atual < proxima_posicao) {
                for ( posicao_atual; posicao_atual <= proxima_posicao; posicao_atual++) {
                    for (int j = 0; j < 5; j++) {
                        if (barra[posicao_atual] == digitos[j]) {
                            senha_digitada[j]++;
                            break;
                        }
                    }
                }
            } else {
                printf("Operação inválida\n");
                numero_deslisamentos--;
            }

            printf("Digite a próxima posição do controle\n\t\t");
            scanf("%d", &proxima_posicao);
            numero_deslisamentos++;
        }

        printf("A senha obtida foi:");

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
            printf("\n\nA senha está correta e o cofre foi aberto!");
            break;
        } else {
            numero_de_tentativas++;

            if (numero_de_tentativas == limite_de_tentativas) {
                printf("\n\nVocê atingiu o limite de tentativas, o cofre não foi aberto e a última senha está incorreta\n\t\t");
                break;
            }

            printf("\n\nA senha está incorreta, tente novamente.\nVocê possui mais %d tentativas\n\n", limite_de_tentativas - numero_de_tentativas);
            printf("Digite qualquer tecla para recomeçar\n\n");
            fflush(stdin);
            scanf("%*c");
        }
    }

    return 0;
}
