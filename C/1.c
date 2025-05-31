#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Função para contar vogais
int contarVogais(char frase[]) {
    int contador = 0;
    for (int i = 0; frase[i] != '\0'; i++) {
        char c = tolower(frase[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            contador++;
        }
    }
    return contador;
}

// Função para deixar a primeira letra de cada palavra em maiúscula
void capitalizarFrase(char frase[]) {
    int i = 0;
    int novaPalavra = 1; // Indica se o próximo caractere é o início de uma nova palavra

    while (frase[i] != '\0') {
        if (frase[i] == ' ') {
            novaPalavra = 1;
        } else if (novaPalavra && frase[i] >= 'a' && frase[i] <= 'z') {
            frase[i] = frase[i] - 32; // Subtrai 32 para transformar em maiúscula
            novaPalavra = 0;
        } else {
            novaPalavra = 0;
        }
        i++;
    }
}

int main() {
    char frase[200];

    // Leitura da frase
    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);

    // Remover o \n do final, se existir
    frase[strcspn(frase, "\n")] = '\0';

    // Imprime a frase digitada
    printf("Frase digitada: %s\n", frase);

    // Conta vogais
    int totalVogais = contarVogais(frase);
    printf("Número de vogais: %d\n", totalVogais);

    // Capitaliza a frase
    capitalizarFrase(frase);
    printf("Frase com palavras iniciadas em maiúsculas: %s\n", frase);

    return 0;
}
