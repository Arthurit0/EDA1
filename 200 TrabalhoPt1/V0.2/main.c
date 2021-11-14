#include <stdio.h>
#include <stdlib.h>
#include "tasks.c"

task * adiciona_Tarefa_Main(task *l);
task * edita_Dados(task * t);
task * edita_Tempo(task * t);
task * edita_Duracao(task * t);
void imprime_Tarefa_a_Editar(task * t);

int main(){
    task *l = NULL, *edTarefa;
    int op = 0, op2, rmvID, edID;

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
                printf("=> Sem Tarefas!\n\n");
            }else{
                printf("=> Todas as Tarefas:\n");
                mostra_Tarefas(l);
            }
            system("pause");
            break;

        case 3:
            system("cls");
            if(l != NULL){
                printf("Digite o ID da tarefa que deseja excluir: ");
                scanf("%d", &rmvID);

                l = excluir_Tarefa(l, rmvID);
            }else{
                printf("Nao ha tarefas! ");
            }
            system("pause");

            break;

        case 4:
            system("cls");
            
            if(l != NULL){
                printf("Digite o ID da tarefa: ");
                scanf("%d", &edID);

                edTarefa = busca_Tarefa(l, edID);
                imprime_Tarefa_a_Editar(edTarefa);

                if(edTarefa != NULL){
                    printf("\n1 - EDITAR DADOS (NOME E PRIORIDADE)");
                    printf("\n2 - EDITAR DATA DE INICIO");
                    printf("\n3 - EDITAR DURACAO");
                    printf("\n0 - CANCELAR\n");
                    printf("\nSelecione uma opcao para editar: ");
                    scanf("%d", &op2);

                    switch (op2)
                    {
                    case 1:
                        edTarefa = edita_Dados(edTarefa);
                        break;
                    
                    case 2:
                        edTarefa = edita_Tempo(edTarefa);
                        break;
                    
                    case 3:
                        edTarefa = edita_Duracao(edTarefa);
                        break;
                    
                    case 0:
                        break;

                    default:
                        printf("\nOpcao invalida, tente novamente! ");
                        break;
                    }
                }else{
                    printf("\nTarefa nao encontrada! ");
                }
            }else{
                printf("Nao ha tarefas! ");
            }
            system("pause");

            break;

        case 0:
            break;
        
        default:
            printf("\nOpcao invalida, tente novamente! ");
            system("pause");
            break;
        }
    }while(op != 0);

    return 0;
}

//Recebe do usuário todos os atributos das tarefas, atribui "Tempo", "Duracao", depois atribui esses dois a "DadosTask", para então
//atribuir tudo na nova task, que através da função adiciona_Tarefa, já o encadeia na lista de tarefas
task * adiciona_Tarefa_Main(task *l){
    //Para atribuir em dados:
    char n[80]; int prior;
    //Para atribuir em tempo:
    int d, m, a, h, min;
    //Para atribuir em duração:
    int DurH, DurM;
    //Para associar na task:
    reg *dados; tmp *tempo; dur *duracao;

    printf("Digite o nome da tarefa: ");
    scanf("%s", &n);
    printf("Digite a prioridade da tarefa: ");
    scanf("%d", &prior);
    printf("Digite o dia de inicio da tarefa: ");
    scanf("%d", &d);
    printf("Digite o mes de inicio da tarefa: ");
    scanf("%d", &m);
    printf("Digite o ano de inicio da tarefa: ");
    scanf("%d", &a);
    printf("Digite a hora de inicio da tarefa: ");
    scanf("%d", &h);
    printf("Digite o minuto de inicio da tarefa: ");
    scanf("%d", &min);
    printf("Digite a quantidade de horas, e depois de minutos, da duracao da tarefa:");
    printf("\n-> Horas: ");
    scanf("%d", &DurH);
    printf("-> Minutos: ");
    scanf("%d", &DurM);
    
    tempo = cria_Tempo(d, m, a, h, min);
    duracao = cria_Duracao(DurH, DurM);
    dados = cria_Dados(n, prior, tempo, duracao);

    l = adiciona_Tarefa(l, dados);

    printf("\nTarefa adicionada na sua lista de tarefas!\n\n");
    return l;
}

task * edita_Dados(task * t){
    char editaNome[80];
    int prior;

    printf("\nDigite o novo nome da tarefa: ");
    scanf("%s", &editaNome);
    printf("Digite a nova prioridade da tarefa: ");
    scanf("%d", &prior);

    strcpy((t->dados->nome), editaNome);
    t->dados->prioridade = prior;

    return t;
}

task * edita_Tempo(task * t){
    int d, m, a, hor, min;
    tmp *ddLine;

    printf("\nDigite o novo dia de inicio da tarefa: ");
    scanf("%d", &d);
    printf("Digite o novo mes de inicio da tarefa: ");
    scanf("%d", &m);
    printf("Digite o novo ano de inicio da tarefa: ");
    scanf("%d", &a);
    printf("Digite a nova hora de inicio da tarefa: ");
    scanf("%d", &hor);
    printf("Digite o novo minuto de inicio da tarefa: ");
    scanf("%d", &min);

    ddLine = t->dados->deadline;

    ddLine->dia = d;
    ddLine->mes = m;
    ddLine->ano = a;
    ddLine->hora = hor;
    ddLine->minuto = min;

    return t;
}

task * edita_Duracao(task * t){
    int mins, hors;
    dur *durc;

    printf("\nDigite a nova duracao em minutos da tarefa: ");
    scanf("%d", &mins);
    printf("Digite a nova duracao em horas da tarefa: ");
    scanf("%d", &hors);

    durc = t->dados->duracao;

    durc->minutos = mins;
    durc->horas = hors;

    return t;
}

void imprime_Tarefa_a_Editar(task * t){
    tmp *ddline; dur *durac;

    ddline = t->dados->deadline;
    durac = t->dados->duracao;
    printf("\n=================================\n");
    printf("Tarefa de ID %d:\n", t->ID);
    printf("-> Tarefa: %s\n", t->dados->nome);
    printf("-> Prioridade: %d\n", t->dados->prioridade);
    printf("-> Duracao: %d hora(s) e %d minuto(s)\n", durac->horas, durac->minutos);
    printf("-> Deadline: %d/%d/%d, as %d:%d", ddline->dia, ddline->mes, ddline->ano, ddline->hora, ddline->minuto);
    printf("\n==================================\n");
}