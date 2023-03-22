#include<stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cartas card;
 
 struct cartas{
    char nome[100];           
    char cardgame_name[50];   // Nome do jogo de cartas
    char raridade[20];        // Raridade da carta (comum, raro, super raro, ex, full art)
};

void quicksort(card vetor[], int inicio, int fim) {
    int i, j;
    struct card pivo, temp;
    i = inicio;
    j = fim - 1;
    pivot = vetor[(inicio + fim) / 2];

    while (i <= j) {
        while (strcmp(vetor[i].raridade, pivot.raridade) > 0) {
            i++;
        }
        while (strcmp(vetor[j].raridade, pivot.raridade) < 0) {
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

    if (inicio < j) {
        quicksort(vetor, inicio, j+1);
    }
    if (i < fim) {
        quicksort(vetor, i, fim);
    }
}

