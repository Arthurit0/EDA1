#include "Func.h"
#include <stdlib.h>
#include <stdio.h>

void mostraMenu(){
printf("\n\n================================================\n");
    printf("|      CADASTRO DE FUNCIONARIOS      |\n");
    printf("|____________________________________|\n");
    printf("|           MENU DE OPCOES           |\n");
    printf("|------------------------------------|\n");
    printf("| 1 - INSERIR n VALORES NO VETOR     |\n");
    printf("| 2 - IMPRIMIR TODOS OS FUNCIONARIOS |\n");
    printf("| 3 - IMPRIMIR FUNCIONARIO DA POSICÃO|\n");
    printf("| 4 - RETORNAR POS. DO MAIOR SALARIO |\n");
    printf("| 5 - RETORNAR POS. DO MENOR SALARIO |\n");
    printf("| 6 - RETORNAR A MEDIA DOS SALARIOS  |\n");
    printf("| 7 - INCLUIR FUNCIONARIO            |\n");
    printf("| 8 - REMOVER UM FUNCIONARIO         |\n");
    printf("| 0 - SAIR                           |\n");
    printf("|------------------------------------|\n");
    printf("\n");
}

fnc * alocaVetor (int tam){
    fnc *v;
    v = (fnc *)malloc(tam*sizeof(fnc));
    return(v);
}

void inserirNoVetor (fnc *vet, int tam){
    int i;
    
    for(i=0; i<tam; i++){
        printf("Digite o codigo do funcionario nº%d\n", (i+1));
        scanf("%d", &vet[i].codigo);
        printf("Digite o nome do funcionario nº%d\n",(i+1));
        scanf("%s", &vet[i].nome);
        printf("Digite o salario do funcionario nº%d\n", (i+1));
        scanf("%f", &vet[i].salario);
    }
}

void imprimirFunc (fnc *vet, int tam){
    int i;
    for(i = 0; i<tam; i++){
        printf("Funcionario º%d\n", (i+1));
        printf("Codigo: %d\n", vet[i].codigo);
        printf("Nome: %s\n", vet[i].nome);
        printf("Salario: %.2f\n", vet[i].salario);
    }
}

void encontraFunc (fnc *vet, int pos){
    printf("Funcionario da pos nº%i\n", pos);
    printf("Codigo: %d\n", vet[pos].codigo);
    printf("Nome: %s\n", vet[pos].nome);
    printf("Salario: %.2f\n", vet[pos].salario);
}

int maior (fnc *vet, int tam){
    int maior = vet[0].salario, posmaior=0, i;

    for (i=1; i<tam; i++){
        if(vet[i].salario > maior){
            maior = vet[i].salario;
            posmaior = i;
        }
    }

    return (posmaior);
}

int menor (fnc *vet, int tam){
    int menor = vet[0].salario, posmenor=0, i;

        for (i=1; i<tam; i++){
        if(vet[i].salario <= menor){
            menor = vet[i].salario;
            posmenor = i;
        }
    }

    return (posmenor);
}

float media (fnc *vet, int tam){
    float salarioTotal=0, media;
    int i;

    for (i=0; i<tam; i++){
        salarioTotal += vet[i].salario;
    }

    media = (salarioTotal/tam);

    return (media);
}

fnc * incluirFunc (fnc *vet, int tam){
    vet = (fnc *)realloc(vet, (tam+1)*sizeof(fnc));

    printf("Digite o codigo do novo funcionario\n");
    scanf("%d", &vet[tam].codigo);
    printf("Digite o nome do novo funcionario\n");
    scanf("%s", &vet[tam].nome);
    printf("Digite o salario do novo funcionario\n");
    scanf("%f", &vet[tam].salario);

    return (vet);
}

fnc * removeFunc (fnc * vet, int tam){
    int pos;
    printf ("Qual posicao a excluir?\n");
    scanf("%d", &pos);
    if ((pos >= 0)&&(pos < tam)){
        vet[pos] = vet[tam-1];
        vet = (fnc *)realloc(vet, (tam-1)*sizeof(fnc));
    }

    return vet;
}