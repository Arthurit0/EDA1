#include <stdlib.h>
#include <stdio.h>
#include "arvores_binarias.h"

nodo * cria_nodo(int key, int content){
    nodo *novo;

    novo = (nodo *)malloc(sizeof(nodo));
    novo->chave = key;
    novo->conteudo = content;

    printf("%d\n\n",novo->chave);

    return novo;
}

arvore insere(arvore r, nodo *novo){
    if(r==NULL) return novo;
        if(r->chave > novo->chave)
            r->esq = insere(r->esq,novo);
        else 
            r->dir = insere(r->dir,novo);
    
    return r;
}

nodo * busca(arvore r, int k){
    if(r==NULL || r->chave == k)
        return r;
    if(r->chave > k)
        return busca(r->esq,k);
    else
        return busca(r->dir,k);
}

