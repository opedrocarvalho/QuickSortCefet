#include <stdio.h>
#include <stdlib.h>

// Definicao da estrutura de no da lista encadeada
typedef struct no {
    int valor;
    struct no* proximo;
} No;

// Funcao que insere um novo no no inicio da lista
void inserir_inicio(No lista, int valor) {
    // Aloca um novo no na memoria
    No novo_no = new No();

    // Atribui o valor e o ponteiro para o proximo no
    novo_no->valor = valor;
    novo_no->proximo = lista;

    // Atualiza o ponteiro para o inicio da lista
    lista = novo_no;
}

// Funcao principal do quicksort
void quicksort(No lista, int tamanho) {
    if (tamanho < 2) {
        return;
    }

    // Seleciona um elemento aleatorio como pivo
    int pivo_index = rand() % tamanho;
    No* pivo = lista;
    for (int i = 0; i < pivo_index; i++) {
        pivo = pivo->proximo;
    }

    // Particiona a lista em duas partes, menores e maiores que o pivo
    No* menores = NULL;
    No* maiores = NULL;
    No* atual = *lista;
    while (atual != NULL) {
        No* proximo = atual->proximo;
        if (atual != pivo) {
            if (atual->valor < pivo->valor) {
                atual->proximo = menores;
                menores = atual;
            } else {
                atual->proximo = maiores;
                maiores = atual;
            }
        }
        atual = proximo;
    }

    // Ordena as duas sublistas recursivamente
    quicksort(&menores, tamanho - 1);
    quicksort(&maiores, tamanho - 1);

    // Concatena as sublistas na ordem correta e atualiza o ponteiro para o inicio da lista
    No* nova_lista = menores;
    while (nova_lista != NULL && nova_lista->proximo != NULL) {
        nova_lista = nova_lista->proximo;
    }
    if (nova_lista != NULL) {
        nova_lista->proximo = pivo;
        pivo->proximo = maiores;
        *lista = menores;
    } else {
        pivo->proximo = maiores;
        *lista = pivo;
    }
}

// Funcao que imprime a lista
void imprimir_lista(No* lista) {
    printf("[ ");
    while (lista != NULL) {
        printf("%d ", lista->valor);
        lista = lista->proximo;
    }
    printf("]\n");
}

// Funcao principal do programa
int main() {
    // Cria a lista vazia
    No* lista = NULL;

    // Insere alguns elementos no inicio da lista
    inserir_inicio(&lista, 5);
    inserir_inicio(&lista, 2);
    inserir_inicio(&lista, 10);
    inserir_inicio(&lista, 7);

    // Imprime a lista antes da ordenacao
    printf("Lista antes da ordenacao: ");
    imprimir_lista(lista);

    // Ordena a lista em ordem decrescente com o quicksort
    quicksort(&lista, 4);
}
   

