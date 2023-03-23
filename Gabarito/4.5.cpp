#include <stdio.h>
#include <stdlib.h>

typedef struct no No;
 struct no{
  int dado;
  No *ant;
  No *prox;
} *inicio = NULL, *fim = NULL;

void quicksort(No *inicio, No *fim) {
  if (fim != NULL && inicio != fim && inicio != fim->prox) {
    int pivo = fim->dado;
    No *i = inicio->ant;

    for (No *j = inicio; j != fim; j = j->prox) {
      if (j->dado < pivo) {
        i = (i == NULL) ? inicio : i->prox;
        int temp = i->dado;
        i->dado = j->dado;
        j->dado = temp;
      }
    }

	if (i == NULL){
    	i = inicio;
    }
    else{
   	 	i = i -> prox;	
	}
	
    int temp = i->dado;
    i->dado = fim->dado;
    fim->dado = temp;

    quicksort(inicio, i->ant);
    quicksort(i->prox, fim);
  }
}


void imprimirLista() {
	No *aux = inicio;
  while (aux != NULL) {
    printf("%d ", aux->dado);
    aux = aux->prox;
  }
  printf("\n");
}

int main() {
  int n, x;	

  printf("Digite o tamanho da lista: ");
  scanf("%d", &n);

  printf("Digite os elementos da lista:\n");

  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    No *novo_no = new No();
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
  imprimirLista();

  quicksort(inicio, fim);

  printf("Lista ordenada: ");
  imprimirLista();

  return 0;
}
