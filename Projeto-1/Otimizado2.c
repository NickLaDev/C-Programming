#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_VETOR 25
#define POSICAO_INICIAL 10
#define LIMITE_TENTATIVAS 3
#define LIMITE_DESLIZAMENTOS 4

int main() {
    int barra[TAMANHO_VETOR] = {1, 2, 5, 7, 8, 1, 2, 5, 7, 8, 1, 2, 5, 7, 8, 1, 2, 5, 7, 8, 1, 2, 5, 7, 8};
    int senha_correta[5] = {2, 2, 2, 2, 2};
    int digitos_validos[5] = {1, 2, 5, 7, 8};

    for (int tentativa = 0; tentativa < LIMITE_TENTATIVAS; tentativa++) {
        int senha_digitada[5] = {0};
        int posicao_atual = POSICAO_INICIAL;
        int numero_deslisamentos = 0;

        system("cls");

        printf("Comece a tentar abrir o cofre, digite a cada passo a próxima posição para gerar a senha\n\n");

        int proxima_posicao;
        printf("Digite a próxima posição do controle\n\t\t");
        scanf("%d", &proxima_posicao);
        numero_deslisamentos++;

        while (numero_deslisamentos < LIMITE_DESLIZAMENTOS && proxima_posicao >= 0) {
            int passo = proxima_posicao - posicao_atual;
            int direcao = passo > 0 ? 1 : (passo < 0 ? -1 : 0);

            for (int i = 0; i <= abs(passo); i++) {
                int posicao = posicao_atual + i * direcao;
                for (int j = 0; j < 5; j++) {
                    if (barra[posicao] == digitos_validos[j]) {
                        senha_digitada[j]++;
                        break;
                    }
                }
            }

            printf("Digite a próxima posição do controle\n\t\t");
            scanf("%d", &proxima_posicao);
            numero_deslisamentos++;
        }

        printf("A senha obtida foi:");
        for (int i = 0; i < 5; i++) {
            printf(" %d", senha_digitada[i]);
        }

        int senha_correta_flag = 1;

        for (int i = 0; i < 5; i++) {
            if (senha_digitada[i] != senha_correta[i]) {
                senha_correta_flag = 0;
                break;
            }
        }

        if (senha_correta_flag) {
            printf("\n\nA senha está correta e o cofre foi aberto!");
            break;
        } else {
            if (tentativa == LIMITE_TENTATIVAS - 1) {
                printf("\n\nVocê atingiu o limite de tentativas, o cofre não foi aberto e a última senha está incorreta\n\t\t");
                break;
            }

            printf("\n\nA senha está incorreta, tente novamente.\nVocê possui mais %d tentativas\n\n", LIMITE_TENTATIVAS - tentativa - 1);
            printf("Digite qualquer tecla para recomeçar\n\n");
            fflush(stdin);
            scanf("%*c");
        }
    }

    return 0;
}
