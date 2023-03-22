#include <stdio.h>
#include <iostream>
typedef struct no No;
struct no {
    int num;
    No*prox,*ant;
}*inicio = NULL,*fim=NULL;

void Inicio(int x) {
    No*novo;
    novo = new No();
    
    if(inicio==NULL){
    novo -> num = x;
    novo->prox = NULL;
	novo->ant = NULL;
	inicio = novo;
	fim = novo;
	}
	else{
	novo -> num = x;
    novo->prox = inicio;
	inicio-> ant= novo;
	inicio= novo;
	inicio ->ant=NULL;
	}
}
 	

void Imprimir() {
    No*aux = inicio;
    printf("Lista Impressa: \n");
    while (aux != NULL) {
        printf("%d ", aux->num);
        aux = aux->prox;
    }
}


No *centro (No *li){
	No *start = inicio, *end = fim;
	if (inicio != NULL){
		while (end -> ant != start || end == start){
			start = start -> prox;
			end = end -> ant;
		}
	return start;	
	}
}

void Quicksort(No *n, No *l, No *r) {
	if (l == NULL || r == NULL || l == r) {
        return;
    }
    No *pivot = centro (n);
    No *left = l, *right = r;
    
    while (left != right->ant) {
        while (left->num < pivot->num) {
		left = left->prox;
		}
        while (right->num > pivot->num){
        right = right -> ant;
		}
        if (left != right->ant) {
            No *temp = left->num;
            left->num = right->num;
            right->num = temp->num;
            left = left -> prox;
            right= right -> ant;
        }
    }
    
    if (l < right) Quicksort(n, l, right);
    if (left < r) Quicksort(n, left, r);
}

int main(){
No *lista = NULL;
   lista = Inicio(6);
   lista =Inicio (2);
   lista = Inicio (1);
   lista = Inicio (10);
   lista = Inicio (11);
   
   Imprimir();
   
   Quicksort (lista, inicio, fim);
   
   Imprimir ();

}

