#include "lse.h"
#include <stdio.h>
#include <stdlib.h>

nodo * insere_fim(nodo *l, int valor){
    nodo *p, *novo;
    p=l;

    novo = (nodo *)malloc(sizeof(nodo));
    novo->dado = valor;
    novo->prox = NULL;

    if(p == NULL){
        l = novo;
    }else{
        while(p->prox != NULL){
            p = p->prox;
        }
        p->prox = novo;
    }

    return l;
}

int profundidade(nodo *l, int valor){
    int cont = 0;
    nodo *p = l;

    while((p != NULL)&&(p->dado != valor)){
        cont++;
        p = p->prox;
    }

    if(p != NULL){
        return cont+1;
    }else{
        return -1;
    }
}

void imprime_lista(nodo *l){
    nodo *p = l;
    int cont = 1;

    if (p == NULL){
        printf("Lista Vazia...\n");
    }

    while(p != NULL){
        printf("Nodo %i: %d\n", cont, p->dado);
        p = p->prox;
        cont++;
    }
}

nodo * inicializa(){
    return NULL;
}

int conta_nos(nodo *l){
    nodo *p = l;
    int cont = 0;

    while(p != NULL){
        p = p->prox;
        cont++;
    }

    return cont;
}

nodo * libera_lst(nodo *l){
    nodo *ant = NULL, *p = l;

    while(p != NULL){
        ant = p;
        p = p->prox;
        free(ant);
    }
    free(p);

    l = inicializa();

    return l;
}

nodo * busca_rmv(nodo *l, int valor){
    nodo *ant = NULL, *p = l;

    while((p != NULL)&&(p->dado != valor)){
        ant = p;
        p = p->prox;
    }

    if(p != NULL){
        printf("\nValor encontrado!\n");
        if(ant == NULL){
            l = p->prox;
        }
        else{
            ant->prox = p->prox;
        }
    }else{
        printf("\nValor nao encontrado!\n");
    }
    free(p);
    return l;
}
