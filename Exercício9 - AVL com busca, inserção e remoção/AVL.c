#include <stdlib.h>
#include <stdio.h>
#include "AVL.h"

nodo * cria_no(int chave){
    nodo *n;

    n = (nodo *)malloc(sizeof(nodo));
    n->esq = n->dir = NULL;
    n->chave = chave;

    return n;
}

int altura(arvore a){
    int esq, dir;
    if(a==NULL) return -1;
    esq=altura(a->esq);
    dir=altura(a->dir);
    if(esq>dir) return(1+esq);
    else return (1+dir);
}

arvore rotDir(nodo *p){
    nodo *f = p->esq;
    p->esq=f->dir;
    f->dir=p;
    return f;
}

arvore rotEsq(nodo * p){
    nodo *f = p->dir;
    p->dir = f->esq;
    f->dir = p;
    return f;
}

int fator_balanceamento(arvore a){
    int bal = altura(a->esq)-altura(a->dir);
    return bal;
}

arvore balanceamento(arvore a){
    if(fator_balanceamento(a) >=2 ){
        if (fator_balanceamento(a->esq) < 0) a->esq = rotEsq(a->esq);
        a = rotDir(a);
    }else{
        if(fator_balanceamento(a) <= -2){
            if(fator_balanceamento(a->dir) > 0) a->dir = rotDir(a->dir);
            a= rotEsq (a);
        }
    }
}

arvore insere(arvore a, nodo * novo){
    if(a == NULL) return novo;
    if(a->chave > novo->chave){
        a->esq = insere(a->esq, novo);
        a->esq = balanceamento(a->esq);
    }else{
        a->dir = insere(a->dir, novo);
        a->dir = balanceamento(a->dir);
    }
    a = balanceamento(a);
    return a;
}

arvore remove_nodo(nodo * q){
    nodo *p, *f;
    if(q->dir == NULL){//só um dos filhos (esquerdo)
        f = q->esq;
        free(q);
        return f;
    }
    p = q;
    f = q->dir;
    while (f->esq != NULL){//procurando o sucessor
        p=f;
        f=f->esq;
    }
    //p está apontando para o pai do sucessor
    //f está apontando para o sucessor
    if(p!=q){
        p->esq = f->dir;//sucessor tem filho
        f->dir = q->dir;
    }//agora filho assumiu o lugar do pai
    f->esq = q->esq;
    free(q);
}

arvore busca_r(arvore a, int k){
    if(a == NULL) return NULL;
    if(a->chave == k) return a;
    if(k < a->chave) return busca(a->esq, k);
    else return busca(a->dir, k);
}

//Sem balanceamento
arvore busca_i(arvore a, int k){
    arvore p;
    p = a;
    while(p != NULL && p->chave != k){
        if(p->chave < k) p=p->dir;
        else p = p->esq;
    }
    if(p == NULL) return NULL;
    else return p;
}

arvore busca_remove_r(arvore a, int k){
    if(a==NULL) return NULL;
    if(a->chave == k) a=remove(a);
    else if(a->chave < k) a->dir = busca_remove_r(a->dir, k);
    else a->esq = busca_remove_r(a->esq, k);
    a = balanceamento(a);
    return a;

}

arvore busca_remove_i(arvore a, int k){
    arvore p, q;
    while(q!= NULL && q->chave != k){
        p=q;
        if(q->chave < k) q = q->dir;
        else q = q->esq;
    }
    if(q == NULL) return a;
    if(p == q) a = remove_nodo(q);
    else if(p->esq == q) p->esq = remove_nodo(q);
    else p->dir = remove_nodo(q);
    a = balanceamento(a);
    return a;
}