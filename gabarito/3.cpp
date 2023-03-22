#include<stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cartas card;
 struct cartas{
    char nome[50];           
    char cardgame_name[50];   // Nome do jogo de cartas
    char raridade[50];        // Raridade da carta (comum, raro, super raro, ex, full art)
};


int raridade_value(char* raridade) {
    if (strcmp(raridade, "comum") == 0) {
        return 1;
    } else if (strcmp(raridade, "raro") == 0) {
        return 2;
    } else if (strcmp(raridade, "super raro") == 0) {
        return 3;
    } else if (strcmp(raridade, "ex") == 0) {
        return 4;
    } else if (strcmp(raridade, "full art") == 0) {
        return 5;
    } else {
        printf("Raridade não consta na base!\n");
        return -1;   
    }
}

void quicksort(card* vetor, int esq, int dir) {
    if (esq < dir) {
        int i = esq, j = dir;
        int pivot = raridade_value(vetor[(esq+dir)/2].raridade);
        
        while (i <= j) {
            while (raridade_value(vetor[i].raridade) > pivot) {
                i++;
            }
            while (raridade_value(vetor[j].raridade) < pivot) {
                j--;
            }
            if (i <= j) {
                card temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
                i++;
                j--;
            }
        }
        
        if (i < dir)quicksort(vetor, esq, j);
        if (esq < j)quicksort(vetor, i, dir);
    }
}

int main() {
    
    struct estoque cartas[5] = {
        {"Carta 1", "TCG 1", "raro"},
        {"Carta 2", "TCG 1", "ex"},
        {"Carta 3", "TCG 2", "full art"},
        {"Carta 4", "TCG 2", "comum"},
        {"Carta 5", "TCG 1", "super raro"}
    };
    
    quicksort(cartas, 0, 4);
    
    for (int i = 0; i < 5; i++) {
        printf("%s, %s, %s\n", cartas[i].nome, cartas[i].cardgame_name, cartas[i].raridade);
    }
    
    return 0;
}

