#include <stdlib.h>
#include <stdio.h>
#include "quick_sort.h"

no * cria_no(int d){
    no * init;

    init = (no *) malloc(sizeof(no));
    init->dado = d;
    init->prox = NULL;

    return init;
}

no * adiciona_final(no *l, int num){
    no *n, *p;

    n = cria_no(num);

    if(l == NULL) return n;

    p = l;

    while (p->prox != NULL){
        p = p->prox;
    }

    p->prox = n;
    
    return l;
}

no * particao(no *l){
    no *pivo, *p, *smlr = NULL;
    int aux;

    p = l;

    while(p->prox != NULL){
        p = p->prox;
    }

    pivo = p;
    p = l;

    while(p->prox != NULL){
        if(p->dado < pivo->dado){
            if(smlr == NULL) smlr = l;
            else{
                smlr = smlr->prox;
            }

            aux = smlr->dado;
            smlr->dado = p->dado;
            p->dado = aux;
        }

        p = p->prox;
    }

    smlr = smlr->prox;

    aux = smlr->dado;
    smlr->dado = pivo->dado;
    pivo->dado = aux;

    p = l;

    while(p->prox->dado != pivo->dado){
        p = p->prox;
    }

    p->prox = NULL;

    return pivo;
}

no * concatena(no *l, no *pivo){
    no *p;

    p = l;
    while (p->prox != NULL){
        p = p->prox;
    }
    p->prox = pivo;

    return l;
    
}

no * quick_sort(no *l){
    no *pivo;

    if(l != NULL && l->prox != NULL){
        pivo = particao(l);
        l = quick_sort(l);
        pivo = quick_sort(pivo);
        l = concatena(l, pivo);
    }
    
    return l;
}