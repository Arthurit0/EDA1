#include <stdio.h>
#include "AVL.h"

int main(){
    arvore a;
    nodo *found;
    int key;

    a = insere(a, cria_no(8));
    a = insere(a, cria_no(3));
    a = insere(a, cria_no(1));
    a = insere(a, cria_no(6));
    a = insere(a, cria_no(4));
    a = insere(a, cria_no(7));
    a = insere(a, cria_no(10));
    a = insere(a, cria_no(14));
    a = insere(a, cria_no(13));


    while(key != 0){
        printf("\nBusque uma chave na árvore, ou 0 para sair: ");
        scanf ("%d", &key);

        if(key == 0) return 0;

        found = busca(a, key);

        if(found != NULL){
            printf("\nAchei o %d!", found->chave);
        }else{
            printf("\nNao achei nenhuma chave %d", found->chave);
        }
    }

}