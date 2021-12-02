#include <stdlib.h>
#include "Pilhas.h"

plh * cria_pilha(){
    plh * pilha;

    pilha = (plh *)malloc(sizeof(plh));
    pilha->topo = NULL;

    return pilha;
}

//@param: char é controlado em main para ser '(' ou ')'
void push(plh *p, char parent){
    no * novo;

    novo = (no *)malloc(sizeof(no));
    novo->dado = parent;
    novo->prox = NULL;

    novo->prox = p->topo;
    p->topo = novo;

}


char pop(plh *p, int *status){
    if(p->topo == NULL){
        *status = 0;
        return '0';
    }

    char parent; no *temp;

    temp = p->topo;
    parent = temp->dado;
    p->topo = temp->prox;
    *status = 1;
    free(temp);
    
    return parent;
}