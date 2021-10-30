#include <stdio.h>
#include <stdlib.h>
#include "lse.h"

int main(){
    nodo *lista;
    int op, valor;

    lista = inicializa();

    do{
        system("cls");
        printf("Menu:\n");
        printf("1 - Inserir elemento no fim da lista\n");
        printf("2 - Profundidade do elemento\n");
        printf("3 - Imprimir lista\n");
        printf("4 - Numero de nos\n");
        printf("5 - Liberar lista (resetar)\n");
        printf("6 - Remover elemento\n");
        printf("0 - Sair\n");
        printf("\nSelecione uma opcao: ");

        scanf("%d", &op);
        system("cls");
        
        switch (op){

        case 1:
            printf("Selecione o valor do novo nodo: ");
            scanf("%d", &valor);
            lista = insere_fim(lista, valor);
            break;
        
        case 2:
            printf("Selecione o valor do nodo: ");
            scanf("%d", &valor);

            if(profundidade(lista, valor) == -1){
                printf("\nValor nao encontrado!\n");
                break;
            }

            printf("\nProfundidade: %d\n", profundidade(lista, valor));
            break;

        case 3:
            imprime_lista(lista);
            break;

        case 4:
            printf("Numero de nos: %d\n", conta_nos(lista));
            break;

        case 5:
            lista = libera_lst(lista);
            printf("Lista liberada!\n");
            break;

        case 6:
            printf("Digite o elemento a ser removido: ");
            scanf("%d", &valor);
            lista = busca_rmv(lista, valor);
            break;

        case 0:
            return 0;

        default:
            printf("\nOpcao invalida\n");
            break;
        }

        printf("\n");
        system("pause");
    }while(op != 0);

    return 0;
}