#include <stdlib.h>
#include "Filas.h"

no * insere_fim(no * l, int valor){
    no *p, *novo;

    if(l == NULL) return l;

    novo = (no *)malloc(sizeof(novo));
    novo->dado = valor;
    novo->prox = NULL;

    p = l;

    while (p->prox != NULL){
        p = p->prox;
    }
    
    p->prox = novo;

    return l;
}

no * retira_inicio(no * l, int * valor){
    no *p;

    if(l == NULL) return NULL;

    else{
        p = l;
        l = l->prox;
        *valor = p->dado;
        free(p);
        return l;
    }

}

