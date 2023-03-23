#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int dado;
  struct no *ant;
  struct no *prox;
} No;

void trocar(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

No *particionar(No *inicio, No *fim) {
  int pivo = fim->dado;
  No *i = inicio->ant;

  for (No *j = inicio; j != fim; j = j->prox) {
    if (j->dado < pivo) {
      i = (i == NULL) ? inicio : i->prox;
      trocar(&(i->dado), &(j->dado));
    }
  }

  i = (i == NULL) ? inicio : i->prox;
  trocar(&(i->dado), &(fim->dado));

  return i;
}

void quicksort(No *inicio, No *fim) {
  if (fim != NULL && inicio != fim && inicio != fim->prox) {
    No *p = particionar(inicio, fim);
    quicksort(inicio, p->ant);
    quicksort(p->prox, fim);
  }
}

void imprimirLista(No *no) {
  while (no != NULL) {
    printf("%d ", no->dado);
    no = no->prox;
  }
  printf("\n");
}

int main() {
  No *inicio = NULL, *fim = NULL;
  int n, x;

  printf("Digite o tamanho da lista: ");
  scanf("%d", &n);

  printf("Digite os elementos da lista:\n");

  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    No *novo_no = (No*) malloc(sizeof(No));
    novo_no->dado = x;
    novo_no->ant = fim;
    novo_no->prox = NULL;

    if (fim != NULL)
      fim->prox = novo_no;
    fim = novo_no;
    if (inicio == NULL)
      inicio = fim;
  }

  printf("Lista original: ");
  imprimirLista(inicio);

  quicksort(inicio, fim);

  printf("Lista ordenada: ");
  imprimirLista(inicio);

  return 0;
}
