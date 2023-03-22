#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
} Pessoa;

void quicksort(Pessoa *vetor, int esquerda, int direita) {
    int i, j;
    Pessoa pivo, temp;

    i = esquerda;
    j = direita;
    pivo = vetor[(esquerda + direita) / 2];

    while (i <= j) {
        while (vetor[i].idade < pivo.idade) {
            i++;
        }
        while (vetor[j].idade > pivo.idade) {
            j--;
        }
        if (i <= j) {
            temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
            i++;
            j--;
        }
    }

    if (j > esquerda) {
        quicksort(vetor, esquerda, j);
    }
    if (i < direita) {
        quicksort(vetor, i, direita);
    }
}

int main() {
    Pessoa pessoas[] = {
        {"Alice", 25},
        {"Bruno", 18},
        {"Carlos", 35},
        {"Daniel", 30},
        {"Eduarda", 22}
    };

    int tamanho = sizeof(pessoas) / sizeof(Pessoa);
    quicksort(pessoas, 0, tamanho - 1);

    printf("Nomes em ordem crescente de idade:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%s\n", pessoas[i].nome);
    }

    return 0;
}

