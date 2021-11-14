#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "tasks.h"

tk* add_Task(tk* l, data d){
    tk *n, *p;

    n = (tk *)malloc(sizeof(tk));
    n->ID = cria_Id_Novo(l);
    n->dados = d;
    n->prox = NULL;

    if(l == NULL) return n;

    while(p->prox != NULL){
        p = p->prox;
    }

    p->prox = n;

    return l;

}

temp cria_Temp(int d, int m, int a, int h, int min){
    temp t;

    //t = (temp *)malloc(sizeof(temp)); Necessário?

    t.dia = d;
    t.mes = m;
    t.ano = a;
    t.hora = h;
    t.minuto = min;

    return t;
}

dur cria_Durac(int h, int m){
    dur drc;

    drc.minutos = m%60;
    drc.horas = h + m/60;

    return drc;
}

data cria_Reg(char n[80], int prior, dur *durac, temp *dL){
    data d;
    return d;
}



void mostra_Menu(){
    printf("|------------------------------------|\n");
    printf("|      CADASTRO DE TAREFAS           |\n");
    printf("|____________________________________|\n");
    printf("|           MENU DE OPCOES           |\n");
    printf("|------------------------------------|\n");
    printf("| 1 - INSERIR NOVA TAREFA            |\n");
    printf("| 2 - VISUALIZAR TAREFAS CADASTRADAS |\n");
    printf("| 3 - EXCLUIR TAREFA                 |\n");
    printf("| 4 - EDITAR TAREFA                  |\n");
    printf("| 5 - INDICAR A TAREFA DO MOMENTO    |\n");
    printf("| 0 - SAIR                           |\n");
    printf("|------------------------------------|\n");
    printf("\n");
    printf("Selecione uma opcao: ");
}

int cria_Id_Novo(tk* l){
    tk *p;
    time_t t; srand((unsigned) time(&t));
    int cont, ID;

    if(l == NULL) return 1000+(rand()% 9999);

    p = l;

    do{
        cont = 0;
        ID = 1000+(rand()% 9999);

        while(p != NULL){
            if(ID == p->ID){
                cont++;
                break;
            }
            p = p->prox;
        }

    }while(cont != 0);

    return ID;
}

void mostra_Tarefas(tk* l){
    tk *p;
    temp *ddline = p->dados.deadline;

    p = l;
    printf("\n");
    while(p != NULL){
        printf("Task de ID %d:\n", p->ID);
        printf("Nome da Tarefa: %s\n", p->dados.nome);
        printf("Prioridade: %d\n", p->dados.prioridade);
        printf("Duracao: %d horas e %d minutos\n", p->dados.duracao.horas, p->dados.duracao.minutos);
        printf("Deadline: %d/%d/%d, as %d:%d", dd);
        printf("\n");
        p = p->prox;
    }
}