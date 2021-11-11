#include <stdio.h>
#include "LDE.c"

int main(){
    no *lista, *temp;
    int op, op2, op3;

    system("cls");
    do
    {
        printf("Menu:\n");
        printf("1 - Inserir no\n");
        printf("2 - Buscar no\n");
        printf("3 - Atualizar no\n");
        printf("4 - Remover no\n");
        printf("5 - Exibir nos\n");
        printf("0 - Sair\n");
        printf("\nSelecione uma opcao: ");

        scanf("%d", &op);

        switch (op)
        {
        case 1:
            system("cls");
            printf("1 - Inserir no inicio\n");
            printf("2 - Inserir no final\n");
            printf("\nSelecione onde deseja inserir o novo no: ");
            scanf("%d", &op2);

            printf("\n");

            if (op2 == 1)
            {
                lista = insere_inicio(lista);
            }else if(op2 == 2){
                lista = insere_fim(lista);
            }else if(op2 == 3){
                lista = insere_ordenado(lista);
            }else{
                printf("");
            }

            break;

        case 2:
            system("cls");
            printf("Digite a chave do no desejado: ");
            scanf("%d", &op2);
            
            temp = busca(lista, op2);

            if(temp == NULL){
                printf("Nodo nao encontrado! ");
            }else{
                printf("O nodo de chave %d e dado %d foi encontrado na lista! ", temp->chave, temp->dado);
            }
            
            free(temp);
            
            break;
        
        case 3:
            system("cls");
            printf("Digite a chave do nodo: ");
            scanf("%d", &op2);
            printf("Digite o novo dado: ");
            scanf("%d", &op3);

            lista = atualiza(lista, op2, op3);
            break;

        case 4:
            printf("Digite a chave do no que deseja remover: ");
            scanf("%d", &op2);

           lista = remove_no(lista, op2);

           break;

        case 5:
            system("cls");
            no *p;
            p = lista;
            int cont = 0;

            printf("\n");
            while(p != NULL){
                printf("%d: Chave %d, dado %d\n", cont, p->chave, p->dado);
                p = p->prox;
                cont++;
            }
        break;

        default:
            printf("\nOpcao invalida! ");
            break;
        }

        printf("\n");
        system("pause");
        system("cls");

    
    } while (op != 0);
    
}