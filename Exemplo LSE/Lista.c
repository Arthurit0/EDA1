#include <stdio.h>
#include <stdlib.h>

typedef struct lista lst;

struct lista{
    int elem;
    lst *prox;
};

lst * criaElem_InsereFim(lst * lista, int num){
    lst *novo, *p;
    p = lista;

    novo = (lst *)malloc(sizeof(lst));
    novo->elem = num;
    novo->prox = NULL;

    if(lista == NULL){
        lista = novo;
    }else{
        while (p->prox != NULL){
            p = p->prox;
        }
        p->prox = novo;
    }

    return lista;
}

void imprimeLista(lst * lista){
    lst *p;
    p = lista;

    if(p != NULL){
        printf("\n-> Lista:\n\n");  
        while(p != NULL){
            printf("Elemento %d\n", p->elem);
            p = p->prox;
        }
    }
}

int numCelulas (lst * lista){
    int contador = 0;
    lst *p;
    p = lista;

    while (p != NULL){
        p = p->prox;
        contador++;
    }

    return contador;
}

int profundidade (lst * lista, int num){
    int contador = 0;
    lst *p;
    p = lista;

    while ((p->elem != num)&&(p != NULL)){
        p = p->prox;
        contador++;
    }
    
    return contador+1;
}

lst * insereCabeca (lst * lista, int num){
    lst * cabeca;

    cabeca = (lst *)malloc(sizeof(lst));

    cabeca->elem = num;
    cabeca->prox = lista;

    return cabeca;
}

lst * insere_ordenado(lst * lista, int num){
    lst *p, *ant, *n;
    p = lista;
    ant = NULL;
    n = malloc(sizeof(lst));

    n->elem = num;
    n->prox = NULL;

    while(p != NULL && p->elem <= num){
        ant = p;
        p = p->prox;
    }
    n->prox = p;
    if(ant == NULL){
        return (n);
    }

    ant->prox = n;
    return(lista);
}

int main(){
    lst *lista;
    int num, op;
    lista = NULL;

    do{
    system("cls");
    printf("Digite uma opcao:\n");
    printf("1 - Insere Elemento\n");
    printf("2 - Imprime Lista\n");
    printf("3 - Numero de celulas\n");
    printf("4 - Profundidade\n");
    printf("5 - Insere Cabeca\n");
    printf("6 - Insere Ordenado\n");
    printf("0 - Sair\n");
    printf("\nDigite a opcao selecionada: ");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
        system("cls");
        printf("Digite o numero inteiro que deseja adicionar na lista: ");
        scanf("%d", &num);
        lista = criaElem_InsereFim(lista,num);
        break;
    
    case 2:
        system("cls");
        imprimeLista(lista);
        break;

    case 3:
        system("cls");
        printf("Numero de Celulas: %d", numCelulas(lista));
        break;

    case 4:
        system("cls");
        printf("Digite o numero inteiro que deseja descobrir a profundidade: ");
        scanf("%d", &num);
        printf("Profundidade do elemento: %d\n", profundidade(lista, num));
        break;
    
    case 5:
        system("cls");
        printf("Digite o numero inteiro que sera a cabeca da lista: ");
        scanf("%d", &num);
        lista = insereCabeca(lista, num);
        break;

    case 6:
        system("cls");
        printf("Digite o numero inteiro a ser inserido na ordem: ");
        scanf("%d", &num);
        lista = insere_ordenado(lista,num);
        break;

    case 0:
        return 0;

    default:
        break;
    }

    printf("\n");
    system("pause");
    }while(op != 0);
    
    return 0;
}