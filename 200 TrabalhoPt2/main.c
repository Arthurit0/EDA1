#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <windows.h>
#include "tasks.c"

task * adiciona_Tarefa_Main(task *l);
task * edita_Dados_Main(task * t);
task * edita_Deadline_Main(task * t);
task * edita_Duracao_Main(task * t);

int ID;

int main(){
    setlocale(LC_ALL,"");
    task *l = NULL, *edTarefa;
    int op = 0, op2, rmvID, edID;
    ID = 1;

    do{
        mostra_Menu();
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            system("cls");
            l = adiciona_Tarefa_Main(l);
            system("pause");
            break;

        case 2:
            system("cls");
            if(l == NULL){
                printf("-> Sem Tarefas! :)\n\n");
            }else{
                printf("-> Todas as Tarefas:\n");
                mostra_Tarefas(l);
            }
            system("pause");
            break;

        case 3:
            system("cls");
            if(l != NULL){
                mostra_Tarefas(l);
                printf("Digite o ID da tarefa que deseja excluir: ");
                scanf("%d", &rmvID);

                l = excluir_Tarefa(l, rmvID);
            }else{
                printf("Nao há tarefas! ");
            }
            system("pause");

            break;

        case 4:
            system("cls");
            
            if(l != NULL){
                printf("Digite o ID da tarefa: ");
                scanf("%d", &edID);

                edTarefa = busca_Tarefa(l, edID);
                imprime_Unica_Tarefa(edTarefa);

                if(edTarefa != NULL){
                    printf("\n1 - EDITAR DADOS (NOME E PRIORIDADE)");
                    printf("\n2 - EDITAR DATA DE INÍCIO");
                    printf("\n3 - EDITAR DURAÇÃO");
                    printf("\n0 - CANCELAR\n");
                    printf("\nSelecione uma opção para editar: ");
                    scanf("%d", &op2);

                    switch (op2)
                    {
                    case 1:
                        edTarefa = edita_Dados_Main(edTarefa);
                        break;
                    
                    case 2:
                        edTarefa = edita_Deadline_Main(edTarefa);
                        break;
                    
                    case 3:
                        edTarefa = edita_Duracao_Main(edTarefa);
                        break;
                    
                    case 0:
                        break;

                    default:
                        printf("\nOpção invalida, tente novamente! ");
                        break;
                    }
                }else{
                    printf("\nTarefa nao encontrada! ");
                }
            }else{
                printf("Nao há tarefas! ");
            }
            system("pause");

            break;

        case 0:
            break;
        
        default:
            printf("\nOpção invalida, tente novamente! ");
            system("pause");
            break;
        }
    }while(op != 0);

    return 0;
}

task * adiciona_Tarefa_Main(task *l){
    time_t t = time(NULL);
    struct tm atual = *localtime(&t);

    //Para atribuir em dados:
    char nome[80]; int prior;
    //Para atribuir em tempo:
    int dia, mes, ano, hora, min;
    //Para atribuir em duração:
    int  DurMin, DurHor, DurDIA, DurMES, DurANO;
    //Para associar na task:
    reg *dados; tmp *tempo; tmp *duracao;

    printf("Digite o nome da tarefa: ");
    fflush(stdin);
    fgets(nome, 80, stdin);
    printf("Digite a prioridade da tarefa (1 a 5): ");
    scanf("%d", &prior);
    printf("Digite o dia de início da tarefa (1 a 31): ");
    scanf("%d", &dia);
    printf("Digite o mes de início da tarefa: ");
    scanf("%d", &mes);
    printf("Digite o ano de início da tarefa: ");
    scanf("%d", &ano);
    printf("Digite a hora de início da tarefa: ");
    scanf("%d", &hora);
    printf("Digite o minuto de início da tarefa: ");
    scanf("%d", &min);
    printf("\nDigite a quantidade de horas, e depois de minutos, da duracao da tarefa:");
    printf("\n-> Horas: ");
    scanf("%d", &DurHor);
    printf("-> Minutos: ");
    scanf("%d", &DurMin);
    printf("-> Dias: ");
    scanf("%d", &DurDIA);
    printf("-> Meses: ");
    scanf("%d", &DurMES);
    printf("-> Anos: ");
    scanf("%d", &DurANO);

    tempo = cria_Tempo(dia, mes, ano, hora, min);
    duracao = cria_Tempo(DurDIA, DurMES, DurANO, DurHor, DurMin);
    dados = cria_Dados(nome, prior, tempo, duracao);
    l = adiciona_Tarefa(l, dados, ID);
    ID++;

    printf("\nTarefa adicionada na sua lista de tarefas!\n\n");
    return l;
}

task * edita_Dados_Main(task * t){
    char editaNome[80];
    int prior;

    printf("\nDigite o novo nome da tarefa: ");
    scanf("%s", &editaNome);
    printf("Digite a nova prioridade da tarefa: ");
    scanf("%d", &prior);

    return edita_Dados(t, editaNome, prior);
}

task * edita_Deadline_Main(task * t){
    int d, m, a, hor, min;

    printf("\nDigite o novo dia de início da tarefa: ");
    scanf("%d", &d);
    printf("Digite o novo mes de início da tarefa: ");
    scanf("%d", &m);
    printf("Digite o novo ano de início da tarefa: ");
    scanf("%d", &a);
    printf("Digite a nova hora de início da tarefa: ");
    scanf("%d", &hor);
    printf("Digite o novo minuto de início da tarefa: ");
    scanf("%d", &min);

    return edita_Deadline(t, d, m, a, hor, min);

}

task * edita_Duracao_Main(task * t){
    int d, m, a, hor, min;

    printf("Digite o novo tempo em horas da duração da tarefa: ");
    scanf("%d", &hor);
    printf("Digite o novo tempo em minutos da duração da tarefa: ");
    scanf("%d", &min);
    printf("\nDigite o novo tempo em dias da duração da tarefa: ");
    scanf("%d", &d);
    printf("Digite o novo tempo em meses da duração da tarefa: ");
    scanf("%d", &m);
    printf("Digite o novo tempo em anos da duração da tarefa: ");
    scanf("%d", &a);

    return edita_Duracao(t, d, m, a, hor, min);

}

//Função para imprimir todas as tarefas
void mostra_Tarefas(task* l){
    task *p; tmp *ddline; tmp *durac;

    if(l != NULL){
        p = l;
        
        while(p != NULL){
            ddline = p->dados->deadline; //Crio ponteiros de "Tempo" e "Duracao" para facilitar na impressão
            durac = p->dados->duracao;
            printf("\n=================================\n");
            printf("Tarefa de ID %d:\n", p->ID);
            printf("-> Tarefa: %s\n", p->dados->nome);
            printf("-> Prioridade: %d\n", p->dados->prioridade);
            printf("-> Duracao: %d hora(s) e %d minuto(s), %d dias, %d meses e %d anos\n", durac->hora, durac->minuto, durac->dia, durac->mes, durac->ano);
            printf("-> Deadline: %d/%d/%d, as %d:%d", ddline->dia, ddline->mes, ddline->ano, ddline->hora, ddline->minuto);
            printf("\n==================================\n");
            p = p->prox;
        }
        printf("\n");
    }
}

void imprime_Unica_Tarefa(task *t){
    tmp *ddline; tmp *durac;

    ddline = t->dados->deadline; //Crio ponteiros de "Tempo" e "Duracao" para facilitar na impressão
    durac = t->dados->duracao;
    printf("\n=================================\n");
    printf("Tarefa de ID %d:\n", t->ID);
    printf("-> Tarefa: %s\n", t->dados->nome);
    printf("-> Prioridade: %d\n", t->dados->prioridade);
    printf("-> Duracao: %d hora(s) e %d minuto(s), %d dias, %d meses e %d anos\n", durac->hora, durac->minuto, durac->dia, durac->mes, durac->ano);
    printf("-> Deadline: %d/%d/%d, as %d:%d", ddline->dia, ddline->mes, ddline->ano, ddline->hora, ddline->minuto);
    printf("\n==================================\n");
}