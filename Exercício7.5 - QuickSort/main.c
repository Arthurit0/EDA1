#include <stdio.h>
#include "quick_sort.h"

void imprime_lista(no *l);

int main(){
    no * lista;

    lista = adiciona_final(lista, 7);
    lista = adiciona_final(lista, 2);
    lista = adiciona_final(lista, 9);
    lista = adiciona_final(lista, 5);
    lista = adiciona_final(lista, 6);

    printf("Lista desordenada:\n\n");
    imprime_lista(lista);

    lista = quick_sort(lista);

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