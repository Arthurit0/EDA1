#include "a).c"
#include <stdio.h>

void alunos_maior_menor_mediana(n* l){
    n *p, *alunomenor = NULL, *alunomaior = NULL;
    float med;

    med = calcula_mediana(n* l);

    p = l;

    while(p->notas != med){
        p = p->prox;
    }

    if(p->ant != NULL){
        alunomenor = p->ant;
    }

    if(p->prox != NULL){
        alunomaior = p->prox;
    }

    if (alunomenor != NULL){
        printf("Aluno com media abaixo da mediana:\n");
        printf("Matricula: %d\n", alunomenor->matrícula);
        printf("Nome: %s\n", alunomenor->nome);
        printf("Media: %d\n", alunomenor->notas);      
    }

    if(alunomaior != NULL){
        printf("Aluno com media acima da mediana:\n");
        printf("Matricula: %d\n", alunomaior->matrícula);
        printf("Nome: %s\n", alunomaior->nome);
        printf("Media: %d\n", alunomaior->notas);  
    }
    


}