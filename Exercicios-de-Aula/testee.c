#include <stdio.h>

int main() {
    printf("Contagem regressiva: ");

    // Loop de 10 a 1
    for (int i = 10; i >= 1; i--) {
        printf("%d\b", i); // Imprime o n�mero atual e retrocede um caractere
        fflush(stdout); // For�a a sa�da do buffer para que o caractere retrocedido seja exibido imediatamente

        // Espera um pouco para simular a contagem regressiva
        getchar();
    }

    printf("BOOM!\n"); // Indica o final da contagem regressiva

    return 0;
}
