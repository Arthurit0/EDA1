#include <stdlib.h>
#include "merge_sort.h"

no * cria_no(int d){
    no *n;

    n = (no *)malloc(sizeof(no));
    n->dado = d;
    n->prox = NULL;

    return n;
}

no * adiciona_final(no * l, int num){
    no *n, *p;
    
    n = cria_no(num);

    if (l == NULL) return n;
    
    p = l;
    while(p->prox != NULL){
        p = p->prox;
    }
    p->prox = n;

    return l;

}

no * mergeSort(no *l){
    no *e, *d, *mid;

    if(l == NULL || l->prox == NULL){
        return l;
    }

    mid = split(l);
    e = mergeSort(l);
    d = mergeSort(mid);
    l = merge(e,d);

    return l;
}

no * split(no *l){
    no *x, *y, *p;

    x=y=l;

    if(l == NULL || l->prox == NULL) return l;
    
    while(y->prox != NULL){
        y = y->prox;

        if(y->prox != NULL){
            x = x->prox;
            y = y->prox;
        }
    }

    p = x->prox;
    x->prox = NULL;

    return (p);

}

no * merge(no *e, no *d){
    no *l, *p;
    l = NULL;

    while((e != NULL) && (d != NULL)){
        if((e->dado) < (d->dado)){
            l = adiciona_final(l,(e->dado));
            p = e;
            e = e->prox;
            free(p);
        }else{
            l = adiciona_final(l,(d->dado));
            p = d;
            d = d->prox;
            free(p);
        }
    }

        while(d != NULL){
            l = adiciona_final(l, d->dado);
            p = d;
            d = d->prox;
            free(p);
        }

        while(e != NULL){
            l = adiciona_final(l, e->dado);
            p = e;
            e = e->prox;
            free(p);
        }

        return l;

}