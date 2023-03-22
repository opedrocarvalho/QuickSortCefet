#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int chave;
    // outros campos que você queira ordenar
} Registro;

void quicksort(Registro *vetor, int esquerda, int direita) {
    int i, j;
    Registro pivo, temp;

    i = esquerda;
    j = direita;
    pivo = vetor[(esquerda + direita) / 2];

    while (i <= j) {
        while (vetor[i].chave < pivo.chave && i < direita) {
            i++;
        }
        while (vetor[j].chave > pivo.chave && j > esquerda) {
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
    Registro vetor[] = { {5}, {3}, {9}, {1}, {4}, {8}, {2}, {7}, {6} };
    int tamanho = sizeof(vetor) / sizeof(Registro);

    quicksort(vetor, 0, tamanho - 1);

    printf("Vetor ordenado: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i].chave);
    }
    printf("\n");

    return 0;
}

