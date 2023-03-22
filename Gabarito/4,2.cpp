typedef struct no No;

struct no {
    int num;
    no*prox;
}*inicio = NULL;

void Inserir(int x) {
    No* novo;
    novo = new No();
    novo -> num = x;
    novo -> prox = inicio;
    inicio = novo;
}

void QuickSort(No* esquerda, No* direita) {
    if (esquerda == NULL || direita == NULL || esquerda == direita) {
        return;
    }
    
    No* pivo = esquerda;
    No* atual = esquerda->prox;
    while (atual != NULL && atual != direita->prox) {
        if (atual->num > pivo->num) {
            No* temp = atual->prox;
            atual->prox = inicio;
            inicio = atual;
            atual = temp;
        } else {
            pivo->prox = atual;
            pivo = atual;
            atual = atual->prox;
        }
    }
    QuickSort(esquerda, pivo);
    QuickSort(pivo->prox, direita);
}



void Imprimir() {
    No*aux = inicio;
    if (inicio != NULL){
    	while (aux != NULL) {
        	printf("%d ", aux->num);
        	aux = aux->prox;
    	}
    }
    else{
    	printf ("Lista vazia");
	}
}


int main (){
	Inicio(1);
	Inicio(7);
	Inicio(10);
	Inicio(4);
	
	QuickSort(1, 4);
	
	Imprimir();
	
	return 0;
}

