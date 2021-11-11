#include <stdio.h>
#include <stdlib.h>
#include "LDE.h"

no * cria_no(){
    no *n;

    n = (no *)malloc(sizeof(no));    
    n->ant = NULL;
    n->prox = NULL;
    printf("Digite o dado do no: ");
    scanf("%d", &n->dado);
    printf("Digite a chave do no: ");
    scanf("%d", &n->chave);

    return n;
}

no * insere_inicio(no *l){
    no *n;

    n = cria_no();

    if (l != NULL) l->ant = n;

    n->prox = l;

    return n;
}

no * insere_ordenado(no *l){
    no *n, *a, *p;
    a = NULL; p = l;

    n = cria_no();

    if (p == NULL){
        return n;
    }

    while(p != NULL && (n->dado > p->dado)){
        a = p;
        p = p->prox;
    }

    n->ant = a;

    if(p == NULL){
        a->prox = n;
    }
    else{ 
        n->prox = p;
        p->ant = n;
    
        if(a == NULL){
            l = n;
        }
        else{
            a->prox = n;
        }
    }

    return l;
}
//Não tá funcionando apesar de ser igual o da aula;

no * insere_fim(no *l){
    no *n, *a, *p;
    a = NULL; p = l;

    n = cria_no();

    if(p == NULL) return n;

    while(p->prox != NULL){
        p = p->prox;
    }

    p->prox = n;
    n->ant = p;

    return l;
}

no * busca(no *l, int c){
    no *n, *p;
    p = l;

    while (p != NULL && p->chave != c){
        p = p->prox;
    }

    if (p == NULL) return NULL;

    return p;
}

no * atualiza(no *l, int c, int novodado){
    no *n;

    n = busca (l, c);

    if(n == NULL) return l;
    else{
        n->dado = novodado;
        return l;
    }

}

no * remove_no(no *l, int c){
    no *p;
    p = l;

    while (p != NULL && p->chave != c){
        p = p->prox;
    }
    
    if(p == NULL){
        printf("\nValor nao encontrado!\n");
        return l;    
    }
    else{ 
        if(p->ant == NULL){
            l = p->prox;
        }
        else{
            p->ant->prox = p->prox;
            p->prox->ant = p->ant;
        }
        
    }
    return l;
}
