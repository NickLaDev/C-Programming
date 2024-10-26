#include <stdio.h>

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

        printf("Comece a tentar abrir o cofre, digite a cada passo a pr�xima posi��o para gerar a senha\n\n");

        for (int i = 0; i < LIMITE_DESLIZAMENTOS; i++) {
            int proxima_posicao;
            printf("Digite a pr�xima posi��o do controle\n\t\t");
            scanf("%d", &proxima_posicao);

            if (proxima_posicao < 0) break;

            int direcao = proxima_posicao - posicao_atual;

            for (int j = posicao_atual; j != proxima_posicao + direcao; j += direcao) {
                for (int k = 0; k < 5; k++) {
                    if (barra[j] == digitos_validos[k]) {
                        senha_digitada[k]++;
                        break;
                    }
                }
            }

            posicao_atual = proxima_posicao;
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
            printf("\n\nA senha est� correta e o cofre foi aberto!");
            return 0;
        }

        printf("\n\nA senha est� incorreta, tente novamente.\nVoc� possui mais %d tentativas\n\n", LIMITE_TENTATIVAS - tentativa - 1);
        printf("Digite qualquer tecla para recome�ar\n\n");
        fflush(stdin);
        scanf("%*c");
    }

    printf("\n\nVoc� atingiu o limite de tentativas, o cofre n�o foi aberto e a �ltima senha est� incorreta\n\t\t");
    return 0;
}
