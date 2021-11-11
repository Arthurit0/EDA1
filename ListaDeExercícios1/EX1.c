#include <stdio.h>
#include <stdlib.h>

typedef struct nodo n;

struct nodo{
    int dado;
    n * prox;
};

n * Troca(n * l, int alvo);

int main(){
    n * lista, *p;
    int i, op, verf=0;

    lista = (n *)malloc(sizeof(n));
    p = lista;
    
    printf("Digite valores para a lista: \n");

    for(i = 0; i<5; i++){
        scanf("%d", &(p->dado));
        p->prox = (n *)malloc(sizeof(n));
        p = p->prox;
    }

    p->prox = NULL;
    p = lista;


    while (p->prox != NULL)
    {
        printf("%d ", p->dado);
        p = p->prox;
    }
    
    printf("\n\nDigite um dado que deseja aplicar a funcao troca: ");
    scanf("%d", &op);

    lista = Troca(lista, op);

    p = lista;

    while (p->prox != NULL)
    {
        printf("%d ", p->dado);
        p = p->prox;
    }
    
}

n * Troca(n * l, int alvo){
    n *p, *a, *temp;
    a = NULL;
    p = l;

    while(p != NULL && p->dado != alvo){
        a = p;
        p = p->prox;
    }

    if (p == NULL){
        printf("\nValor nao encontrado!\n");
        return l;
    }else{
        if(p->prox->prox == NULL){
            printf("\nO proximo item da lista eh nulo!\n");
            return l;
        }else{
            if(a == NULL){
                temp = p->prox;
                p->prox = p->prox->prox;
                temp->prox = p;
                l = temp;
            }else{
                a->prox = p->prox;
                temp = p->prox;
                p->prox = p->prox->prox;
                temp->prox = p;
            }
        }
    }

    return l;

}