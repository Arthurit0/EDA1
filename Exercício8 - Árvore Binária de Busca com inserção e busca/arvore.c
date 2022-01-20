#include <stdlib.h>
#include <stdio.h>
#include "arvore.h"

nodo * cria_no(int chave){
    nodo *n;

    n = (nodo *)malloc(sizeof(nodo));
    n->esq = n->dir = NULL;
    n->chave = chave;

    return n;
}

arvore insere(arvore a, nodo *novo){
    if(a == NULL) return novo;

    if(novo->chave < a->chave){
        a->esq = insere(a->esq, novo);
    }
    else{
        a->dir = insere(a->dir, novo);
    }

    return a;
}

nodo * busca(arvore a, int chave){
    if(a == NULL){
        // printf("\nNão achei!");
        return NULL;
    } //Nulo

    if(a->chave == chave){
        // printf("\nAchei!");
        return a;
    } //Retorna nodo com chave

    if(chave < a->chave){
        // printf("\nDesci para a esquerda");
        return busca(a->esq, chave); //Galho esquerdo
    }else{
        // printf("\nDesci para a direita");
        return busca(a->dir, chave); //Galho direito
    }

}