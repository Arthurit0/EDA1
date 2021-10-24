#include <stdio.h>
#include <stdlib.h>
#include "Func.h"

int main(){
    fnc *vet;
    int op,op2, tam;

        printf("Digite o tamanho desejado para o vetor de funcionarios: ");
        scanf("%d", &tam);
        vet = alocaVetor(tam);

        system("cls");

    do{
        mostraMenu();
        printf("Digite a opcao desejada: ");
        scanf ("%d", &op);

        switch (op)
        {
        case 1:
            system("cls");
            inserirNoVetor(vet, tam);
            break;

        case 2:
            system("cls");
            imprimirFunc(vet, tam);
            system("pause");
            break;

        case 3:
            system("cls");
            printf("Deseja imprimir o funcionario de qual posicao?\n");
            scanf("%d", &op2);
            encontraFunc(vet, op2);
            system("pause");
            break;

        case 4:
            system("cls");
            printf("A posicao do maior salario eh %d\n", maior(vet, tam));
            system("pause");
            break;

        case 5:
            system("cls");
            printf("A posicao do menor salario eh %d\n", menor(vet, tam));
            system("pause");
            break;

        case 6:
            system("cls");
            printf("A media dos salarios eh %.2f\n", media(vet, tam));
            system("pause");
            break;

        case 7:
            system("cls");
            vet = incluirFunc(vet, tam);
            tam++;
            break;

        case 8:
            system("cls");
            vet = removeFunc(vet, tam);
            tam--;
            break;

        case 0:
            printf("Finalizando programa\n");
            system("pause");
            return 0;

        default:
            printf("Opcao invalida!\n");
            break;
        }
    }while(op =! 0);

    return 0;

}