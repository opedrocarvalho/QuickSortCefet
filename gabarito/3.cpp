#include<stdio.h>

typedef struct cartas card;
 
 struct cartas{
    char nome[100];           
    char cardgame_name[50];   // Nome do jogo de cartas
    char raridade[20];        // Raridade da carta (comum, raro, super raro, ex, full art)
};

