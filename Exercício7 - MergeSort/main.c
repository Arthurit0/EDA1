#include <stdio.h>
#include "merge_sort.c"

void imprime_lista(no *l);

int main(){
    no *lista;

    lista = adiciona_final(lista, 6);
    lista = adiciona_final(lista, 4);
    lista = adiciona_final(lista, 1);
    lista = adiciona_final(lista, 4);
    lista = adiciona_final(lista, 3);
    lista = adiciona_final(lista, 2);

    printf("Lista desordenada:\n\n");
    imprime_lista(lista);

    lista = mergeSort(lista);

    printf("\n\nLista Ordenada:\n\n");
    imprime_lista(lista);

    return 0;
}

void imprime_lista(no *l){
    no *p = l;

    printf("[");
    while(p->prox != NULL){
        printf("%d, ", p->dado);
        p = p->prox;
    }

    printf("%d]",p->dado);
}