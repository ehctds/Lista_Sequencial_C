#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *dados;
    int tamanho;
    int capacidade;
} lista;

void criaLista(lista *lst, int capacidade) {
    lst->dados = (int*) malloc(capacidade * sizeof(int));
    lst->tamanho = 0;
    lst->capacidade = capacidade;
}

int listaVazia(lista lst) {
    return lst.tamanho == 0;
}

int listaCheia(lista lst) {
    return lst.tamanho == lst.capacidade;
}

int tamanhoLista(lista lst) {
    return lst.tamanho;
}

int obterElemento(lista lst, int posicao) {
    return lst.dados[posicao-1];
}

void modificarElemento(lista *lst, int posicao, int novoValor) {
    lst->dados[posicao-1] = novoValor;
}

int inserirElemento(lista *lst, int posicao, int valor) {
    if (listaCheia(*lst) || posicao > lst->tamanho+1 || posicao < 1) {
        return 0;
    }

    for (int i = lst->tamanho; i >= posicao; i--) {
        lst->dados[i] = lst->dados[i-1];
    }
    lst->dados[posicao-1] = valor;
    lst->tamanho++;

    return 1;
}

int removerElemento(lista *lst, int posicao) {
    if (listaVazia(*lst) || posicao > lst->tamanho || posicao < 1) {
        return 0;
    }

    for (int i = posicao-1; i < lst->tamanho-1; i++) {
        lst->dados[i] = lst->dados[i+1];
    }
    lst->tamanho--;

    return 1;
}

void imprimirLista(lista lst) {
    if (listaVazia(lst)) {
        printf("A lista está vazia\n");
    } else {
        printf("Lista: ");
        for (int i = 0; i < lst.tamanho; i++) {
            printf("%d ", lst.dados[i]);
        }
        printf("\n");
    }
}

int main() {
    int capacidade;
    printf("Digite o tamanho máximo da lista: ");
    scanf("%d", &capacidade);

    lista lista;
    criaLista(&lista, capacidade);

    inserirElemento(&lista, 1, 1);
    inserirElemento(&lista, 2, 2);
    inserirElemento(&lista, 1, 3);
    modificarElemento(&lista, 2, 4);
    removerElemento(&lista, 1);
    printf("O elemento na posição 1 é: %d\n", obterElemento(lista, 1));
    printf("O tamanho da lista é: %d\n", tamanhoLista(lista));
    imprimirLista(lista);

    free(lista.dados);

    return 0;
}