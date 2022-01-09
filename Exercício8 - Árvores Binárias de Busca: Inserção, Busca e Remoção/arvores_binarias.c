#include <stdlib.h>
#include <stdio.h>
#include "arvores_binarias.h"

nodo * cria_nodo(int key, int content){
    nodo *novo;

    novo = (nodo *)malloc(sizeof(nodo));
    novo->chave = key;
    novo->conteudo = content;

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

nodo *busca_remove(arvore r, int k){
    nodo *p, *q;

    p = q = r;

    while (q->chave != k && q != NULL){
        p = q;

        if(k > q->chave) q = q->dir;
        else q = q->esq;
    }

    if (q == NULL) return r; //Nada a remover
    if(p == q) r = remove_nodo(q); //O alvo é a raiz;
    else if (p->esq == q) p->esq = remove_nodo(q); //remover filho esquerdo
    else p->dir = remove_nodo(q); //remover filho direito

    return r;
}

nodo *remove_nodo(nodo *q){
    nodo *p, *f;

    if(q->dir == NULL){ //Só tem um dos filhos (esquerdo)
        f = q->esq;
        free(q);
        return f;
    }

    if(q->esq == NULL){ //Só tem um dos filhos (direito)
        f = q->dir;
        free(q);
        return f;
    }

    p = q;
    f = q->dir;
    
    while(f->esq != NULL){ //Procurando o sucessor
        p = f;
        f = f->esq;
    }

    //f está apontando para o sucesso e p para o pai do sucessor

    p->esq = f->dir; //Sucessor tem filho(s)

    // Agora o filho assume o lugar do pai
    f->dir = q->dir;
    f->esq = q->esq;

    /*Alternativamente, começando da linha 78:

    if(p != q){
        p->esq = f->dir;
        f->dir = q;
    }

    //Agora o filho assume o lugar do pai

    f->esq = q->esq;
    */

    free(q);
    return(f);

}