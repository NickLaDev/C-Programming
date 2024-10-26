#include <stdio.h>
#include <locale.h>

int main() {
    if (setlocale(LC_ALL, "Portuguese_Brazil.1252") == NULL) {
        fprintf(stderr, "Erro ao configurar o locale.\n");
        return 1;
    }

    // Exemplo de uso de locale
    printf("Número formatado: %'d\n", 1234567);
    return 0;
}
