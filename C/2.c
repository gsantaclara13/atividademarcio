#include <stdio.h>
#include <string.h>

#define MAX_LIVROS 5
#define MAX_TAM 100

typedef struct {
    char titulo[MAX_TAM];
    char autor[MAX_TAM];
    char editora[MAX_TAM];
    int anoPublicacao;
    int qtdPaginas;
} Livro;

// Função para preencher o vetor de livros
void preencherVetor(Livro livros[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nLivro %d\n", i + 1);
        
        printf("Título: ");
        fgets(livros[i].titulo, MAX_TAM, stdin);
        livros[i].titulo[strcspn(livros[i].titulo, "\n")] = '\0';

        printf("Autor: ");
        fgets(livros[i].autor, MAX_TAM, stdin);
        livros[i].autor[strcspn(livros[i].autor, "\n")] = '\0';

        printf("Editora: ");
        fgets(livros[i].editora, MAX_TAM, stdin);
        livros[i].editora[strcspn(livros[i].editora, "\n")] = '\0';

        printf("Ano de Publicação: ");
        scanf("%d", &livros[i].anoPublicacao);

        printf("Quantidade de Páginas: ");
        scanf("%d", &livros[i].qtdPaginas);

        getchar(); // limpar o buffer do teclado
    }
}

// Função para imprimir vetor de livros
void imprimirVetor(Livro livros[], int n) {
    printf("\nLista de Livros:\n");
    for (int i = 0; i < n; i++) {
        printf("%d - %s | %s | %s | %d | %d páginas\n", 
            i, livros[i].titulo, livros[i].autor, livros[i].editora, livros[i].anoPublicacao, livros[i].qtdPaginas);
    }
}

// Busca linear pelo título, retorna índice ou -1
int buscarPorTitulo(Livro livros[], int n, char titulo[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(livros[i].titulo, titulo) == 0) {
            return i;
        }
    }
    return -1;
}

// Bubble sort para ordenar pelo título
void ordenarPorTitulo(Livro livros[], int n) {
    Livro temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (strcmp(livros[j].titulo, livros[j + 1].titulo) > 0) {
                temp = livros[j];
                livros[j] = livros[j + 1];
                livros[j + 1] = temp;
            }
        }
    }
}

// Busca binária pelo título, vetor deve estar ordenado
int buscaBinariaPorTitulo(Livro livros[], int n, char titulo[]) {
    int inicio = 0, fim = n - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        int cmp = strcmp(livros[meio].titulo, titulo);
        if (cmp == 0) {
            return meio;
        } else if (cmp < 0) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

int main() {
    Livro biblioteca[MAX_LIVROS];
    int n = MAX_LIVROS;

    preencherVetor(biblioteca, n);

    printf("\nAntes da ordenação:\n");
    imprimirVetor(biblioteca, n);

    ordenarPorTitulo(biblioteca, n);

    printf("\nDepois da ordenação:\n");
    imprimirVetor(biblioteca, n);

    char tituloBusca[MAX_TAM];
    printf("\nDigite o título do livro para busca linear: ");
    fgets(tituloBusca, MAX_TAM, stdin);
    tituloBusca[strcspn(tituloBusca, "\n")] = '\0';

    int pos = buscarPorTitulo(biblioteca, n, tituloBusca);
    if (pos == -1) {
        printf("Livro não encontrado na busca linear.\n");
    } else {
        printf("Livro encontrado na posição %d (busca linear).\n", pos);
    }

    printf("\nDigite o título do livro para busca binária: ");
    fgets(tituloBusca, MAX_TAM, stdin);
    tituloBusca[strcspn(tituloBusca, "\n")] = '\0';

    pos = buscaBinariaPorTitulo(biblioteca, n, tituloBusca);
    if (pos == -1) {
        printf("Livro não encontrado na busca binária.\n");
    } else {
        printf("Livro encontrado na posição %d (busca binária).\n", pos);
    }

    return 0;
}
