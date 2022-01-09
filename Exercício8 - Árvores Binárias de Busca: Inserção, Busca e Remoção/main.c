#include <stdio.h>
#include <stdlib.h>
#include "arvores_binarias.h"

//e = esquerda, d = direita, r = root

void inorder_erd (arvore r);
void preorder_red(arvore r);
void postorder_edr(arvore r);

int main(){
    nodo *l = NULL, *buscado;
    int chave;

    l = insere(l, cria_nodo(8, 10));
    l = insere(l, cria_nodo(3, 11));
    l = insere(l, cria_nodo(1, 12));
    l = insere(l, cria_nodo(6, 13));
    l = insere(l, cria_nodo(4, 14));
    l = insere(l, cria_nodo(7, 15));
    l = insere(l, cria_nodo(10, 16));
    l = insere(l, cria_nodo(14, 17));
    l = insere(l, cria_nodo(13, 18));

    printf("Inorder: ");
    inorder_erd(l);
    printf("\nPreorder: ");
    preorder_red(l);
    printf("\nPostorder: ");
    postorder_edr(l);

    printf("\n\nBusque por um nodo: ");
    scanf("%d", &chave);

    buscado = busca(l, chave);

    if(buscado != NULL){
        printf("\nChave %d encontrada com conteudo %d!", buscado->chave, buscado->conteudo);
    }else{
        printf("\nChave %d nao encontrada!", chave);
    }

    printf("\n\nRemova um nodo: ");
    scanf("%d", &chave);

    l = busca_remove(l, chave);

    printf("\nNovo Inorder: ");
    inorder_erd(l);

    printf("\n");
    return 0;
}

void inorder_erd (arvore r){
    if(r != NULL){
        inorder_erd(r->esq);
        printf("%d ", r->chave);
        inorder_erd(r->dir);
    }
}

void preorder_red(arvore r){
    if(r != NULL){
        printf("%d ", r->chave);
        preorder_red(r->esq);
        preorder_red(r->dir);        
    }
}

void postorder_edr(arvore r){
    if(r != NULL){
        postorder_edr(r->esq);
        postorder_edr(r->dir);
        printf("%d ", r->chave);
    }
}

