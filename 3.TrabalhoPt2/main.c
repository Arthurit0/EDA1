#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>
#include "tasks.c"

void mostra_Menu();
void mostra_Tarefas(task* l);
void imprime_Unica_Tarefa(task *t);
void system_pause();
task * adiciona_Tarefa_Main(task *l);
task * edita_Dados_Main(task * t);
task * edita_Deadline_Main(task * t);
task * edita_Duracao_Main(task * t);

int ID;

int main(){
    setlocale(LC_ALL,"Portuguese");
    task *l = NULL, *edTarefa;
    int op = 0, op2, rmvID, edID;
    ID = 1;

    do{
        system("clear");
        
        mostra_Menu();
        scanf("%d", &op);

        switch (op){

            case 1:
                system("clear");
                l = adiciona_Tarefa_Main(l);
                break;

            case 2:
                system("clear");
                if(l == NULL){
                    printf("-> Sem Tarefas! :)\n\n");
                }else{
                    printf("-> Todas as Tarefas:\n");
                    mostra_Tarefas(l);
                }
                break;

            case 3:
                system("clear");
                if(l != NULL){
                    mostra_Tarefas(l);
                    printf("Digite o ID da tarefa que deseja excluir: ");
                    scanf("%d", &rmvID);

                    l = excluir_Tarefa(l, rmvID);

                    printf("\nTarefa excluída da lista de tarefas! ");

                }else{
                    printf("Não há tarefas! ");
                }

                break;

            case 4:
                system("clear");
                
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

                        switch (op2){

                            case 1:
                                edTarefa = edita_Dados_Main(edTarefa);
                                printf("\nDados da tarefa alterados! ");

                                break;
                            
                            case 2:
                                edTarefa = edita_Deadline_Main(edTarefa);
                                printf("\nDeadline da tarefa alterado! ");
                                break;
                            
                            case 3:
                                edTarefa = edita_Duracao_Main(edTarefa);
                                printf("\nDuração da tarefa alterada! ");
                                break;
                            
                            case 0:
                                break;

                            default:
                                printf("\nOpção inválida, tente novamente! ");
                                break;
                        }
                    }else{
                        printf("\nTarefa não encontrada! ");
                    }
                }else{
                    printf("Nao há tarefas! ");
                }

                break;

            case 0:
                break;
            
            default:
                printf("\nOpção inválida, tente novamente! ");
                break;
        }
        printf("\n\n");
        system_pause();
        system("clear");
    }while(op != 0);

    return 0;
}
/*
    @Param: Um ponteiro para uma lista de tasks.
    
    @Return: O mesmo ponteiro para a lista de tasks, mas com uma nova tarefa adicionada.
    
    Aqui é onde todas os dados da nova tarefa são criados com o conteúdo digitado pelo usuário, para então ser enviada
    para a função "adiciona_nova_Tarefa", onde a tarefa será encadeada na lista de tasks.
*/
task * adiciona_Tarefa_Main(task *l){
    tmp * tempofinal;

    //Para atribuir em dados:
    char nome[80]; int prior;
    //Para atribuir em tempo:
    int dia, mes, ano, hora, min, dias_do_mes;
    //Para atribuir em duracao:
    int  dur_min, dur_hora, dur_dia = 0, dur_mes = 0, dur_ano = 0; char tarefa_longa;
    //Para associar na task:
    reg *dados; tmp *tempo; tmp *duracao;

    printf("- Digite o nome da tarefa: ");
    // fflush(stdin);
    getchar();
    fgets(nome, 80, stdin);

    do{
        printf("- Digite a prioridade da tarefa (1 a 5): ");
        scanf("%d", &prior);

        if(prior < 1 || prior > 5){
            printf("\nValor de prioridade inválido! ");
            system_pause();
            printf("\n");
        }
    }while (prior < 1 || prior > 5);

    printf("\n==> DATA DE INÍCIO:\n\n");

    do{
        printf("- Digite o dia de início da tarefa: ");
        scanf("%d", &dia);

        if(dia < 1 || dia > 31){
            printf("\nValor de dia inválido! ");
            system_pause();
            printf("\n");
            continue;
        }

        printf("- Digite o mês de início da tarefa: ");
        scanf("%d", &mes);

        if(mes < 1 || mes > 12){
            printf("\nValor de mês inválido! ");
            system_pause();
            printf("\n");
            continue;
        }

        dias_do_mes = verif_calendario(mes, 2000);
        
        if(dia > dias_do_mes){
            printf("\nO mês %d possui %d dias, logo, o dia %d é inválido! ", mes, dias_do_mes, dia);
            system_pause();
            printf("\n");
        }

    } while ((dia < 1 || dia > 31) || (mes < 1 || mes > 12) || (dia > dias_do_mes));

    do
    {
        printf("- Digite o ano de início da tarefa: ");
        scanf("%d", &ano);

        if(ano < 1990 ){
            printf("\nValor de ano inválido! ");
            system_pause();
            printf("\n");
        }
    } while (ano < 1990);
    
    do{
        printf("--> Digite a hora de início da tarefa: ");
        scanf("%d", &hora);

        if(hora < 0 || hora > 23){
            printf("\nValor de hora inválido! ");
            system_pause();
            printf("\n");
        }

    } while (hora < 0 || hora > 23);

    do
    {
        printf("--> Digite o minuto de início da tarefa: ");
        scanf("%d", &min);

        if(min < 0 || min > 59){
            printf("\nValor de minuto inválido! ");
            system_pause();
            printf("\n");
        }
    } while (min < 0 || min > 59);

    printf("\nDURAÇÃO DA TAREFA:\n");

    printf("\n- Digite a quantidade estimada da duração da tarefa em:\n");
    
    do{
        printf("-> Horas: ");
        scanf("%d", &dur_hora);

        if(dur_hora < 0){
            printf("\nValor de duração em horas inválida! ");
            system_pause();
            printf("\n");
        }

    } while (dur_hora < 0);

    do{
        printf("-> Minutos: ");
        scanf("%d", &dur_min);

        if(dur_min < 0){
            printf("\nValor de duração em minutos inválida! ");
            system_pause();
            printf("\n");
        }

    } while (dur_min < 0);

    do{
        printf("\n- Esta é uma tarefa longa (que pode demorar dias, meses e/ou anos)? S/N: ");
        getchar();
        tarefa_longa = getchar();

        if(tarefa_longa != 's' && tarefa_longa != 'S' && tarefa_longa != 'n' && tarefa_longa != 'N'){
            printf("\nOpção inválida, tente novamente! ");
            system_pause();
            printf("\n");
        }

    } while ((tarefa_longa != 's') && (tarefa_longa != 'S') && (tarefa_longa != 'n') && (tarefa_longa != 'N'));
    
    if(tarefa_longa == 's' || tarefa_longa == 'S'){

        do{
            printf("-> Dias: ");
            scanf("%d", &dur_dia);
        
            if(dur_dia < 0){
                printf("\nValor de duração em dias inválido! ");
                system_pause();
                printf("\n");
            }
        } while (dur_dia < 0);

        do{
            printf("-> Meses: ");
            scanf("%d", &dur_mes);
        
            if(dur_mes < 0){
                printf("\nValor de duração em meses inválido! ");
                system_pause();
                printf("\n");
            }
        } while (dur_mes < 0);

        do{
            printf("-> Anos: ");
            scanf("%d", &dur_ano);
        
            if(dur_ano < 0){
                printf("\nValor de duração em anos inválido! ");
                system_pause();
                printf("\n");
            }
        } while (dur_ano < 0);

    }

    tempo = cria_Tempo(dia, mes, ano, hora, min);
    duracao = cria_Tempo(dur_dia, dur_mes, dur_ano, dur_hora, dur_min);
    dados = cria_Dados(nome, prior, tempo, duracao);
    l = adiciona_nova_Tarefa(l, dados, ID);
    ID++;

    tempofinal = data_final(tempo, duracao);

    printf("\nTarefa adicionada na sua lista de tarefas! ");

    return l;
}
/*
    @Param: Um ponteiro para uma lista de tasks.
    
    @Return: O mesmo ponteiro para a lista de tasks, com uma tarefa tendo o nome e prioridade alterados.
    
    Aqui é onde o novo nome e prioridade são digitados pelo usuário, para então serem enviados para a função "edita_Dados" em
    tasks.c, que é onde a substituição dos dados desta task acontecem.
*/
task * edita_Dados_Main(task * t){
    char editaNome[80];
    int prior;

    printf("\nDigite o novo nome da tarefa: ");
    fflush(stdin);
    fgets(editaNome, 80, stdin);
    printf("Digite a nova prioridade da tarefa: ");
    scanf("%d", &prior);

    return edita_Dados(t, editaNome, prior);
}
/*
    @Param: Um ponteiro para uma lista de tasks.
    
    @Return: O mesmo ponteiro para a lista de tasks, com uma tarefa tendo a estrutura de "Tempo" Deadline alterada.
    
    Aqui é onde os novos valores da deadline são digitados pelo usuário, para então serem enviados para a função "edita_Deadline" em
    "tasks.c", que é onde a substituição dos dados desta task acontecem.
*/
task * edita_Deadline_Main(task * t){
    int d, m, a, hor, min;

    printf("\nDigite o novo dia de início da tarefa: ");
    scanf("%d", &d);
    printf("Digite o novo mês de início da tarefa: ");
    scanf("%d", &m);
    printf("Digite o novo ano de início da tarefa: ");
    scanf("%d", &a);
    printf("Digite a nova hora de início da tarefa: ");
    scanf("%d", &hor);
    printf("Digite o novo minuto de início da tarefa: ");
    scanf("%d", &min);

    return edita_Deadline(t, d, m, a, hor, min);
}
/*
    @Param: Um ponteiro para uma lista de tasks.
    
    @Return: O mesmo ponteiro para a lista de tasks, com uma tarefa tendo a estrutura de "Tempo" Duracao alterada.
    
    Aqui é onde os novos valores da duração são digitados pelo usuário, para então serem enviados para a função "edita_Duracao" em
    "tasks.c", que é onde a substituição dos dados desta task acontecem.
*/
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

    l = mg_sort_tasks(l);

    if(l != NULL){
        p = l;
        
        while(p != NULL){
            ddline = p->dados->deadline; //Crio ponteiros de "Tempo" e "Duracao" para facilitar na impressão
            durac = p->dados->duracao;
            printf("\n==================================================================\n");
            printf("Tarefa de ID %d:\n", p->ID);
            printf("-> Tarefa: %s\n", p->dados->nome);
            printf("-> Prioridade: %d\n", p->dados->prioridade);
            printf("-> Duração: %d hora(s) e %d minuto(s)", durac->hora, durac->minuto);
            
            if(durac->dia > 0){
                printf(", %d dia(s)", durac->dia);
            }

            if(durac->mes > 0){
                printf(", %d mes(es)", durac->mes);
            }

            if(durac->ano > 0){
                printf(", %d ano(s)", durac->ano);
            }

            printf("\n-> Deadline: %d/%d/%d, às %d:%d", ddline->dia, ddline->mes, ddline->ano, ddline->hora, ddline->minuto);
            printf("\n===================================================================\n");
            p = p->prox;
        }
    }
}
/*
    @Param: Um ponteiro para uma task.

    Função para imprimir todos os dados de uma task.
*/
void imprime_Unica_Tarefa(task *t){
    tmp *ddline; tmp *durac;

    ddline = t->dados->deadline; //Crio ponteiros de "Tempo" e "Duracao" para facilitar na impressão
    durac = t->dados->duracao;
    printf("\n==================================================================\n");
    printf("Tarefa de ID %d:\n", t->ID);
    printf("-> Tarefa: %s\n", t->dados->nome);
    printf("-> Prioridade: %d\n", t->dados->prioridade);
    printf("-> Duração: %d hora(s) e %d minuto(s)\n", durac->hora, durac->minuto);
            
    if(durac->dia > 0){
        printf(", %d dia(s)", durac->dia);
    }

    if(durac->mes > 0){
        printf(", %d mes(es)", durac->mes);
    }

    if(durac->ano > 0){
        printf(", %d ano(s)", durac->ano);
    }

    printf("\n-> Deadline: %d/%d/%d, às %d:%d", ddline->dia, ddline->mes, ddline->ano, ddline->hora, ddline->minuto);
    printf("\n===================================================================\n");
}

void mostra_Menu(){
    time_t t = time(NULL);
    struct tm atual = *localtime(&t);
    int dia_hoje = atual.tm_mday, 
        mes_hoje = atual.tm_mon + 1, 
        ano_hoje = atual.tm_year + 1900,
        hora_hoje = atual.tm_hour,
        minuto_hoje = atual.tm_min;
    

    system("clear");
    printf("|------------------------------------|\n");
    printf("|         CADASTRO DE TAREFAS        |\n");
    printf("|------------------------------------|\n");

    // printf("|            ");
    // if(dia_hoje < 10){
    //     printf(" ");
    // }

    // printf("(%d/%d/%d)            ", dia_hoje, mes_hoje, ano_hoje);

    // if(mes_hoje < 10){
    //     printf(" ");
    // }

    
    printf("|            (");
    
    if(dia_hoje < 10){
        printf("0");
    }

    printf("%d/", dia_hoje);

    if(mes_hoje < 10){
        printf("0");
    }

    printf("%d/%d)            ", mes_hoje, ano_hoje);
    printf("|\n");


    // printf("|               %d:%d                |\n", hora_hoje, minuto_hoje);

    printf("|               ");

    if(hora_hoje < 10){
        printf("0");
    }

    printf("%d:", hora_hoje);

    if(minuto_hoje < 10){
        printf("0");
    }

    printf("%d                |\n", minuto_hoje);

    printf("|____________________________________|\n");
    printf("|           MENU DE OPÇÕES           |\n");
    printf("|------------------------------------|\n");
    printf("| 1 - INSERIR NOVA TAREFA            |\n");
    printf("| 2 - VISUALIZAR TAREFAS CADASTRADAS |\n");
    printf("| 3 - EXCLUIR TAREFA                 |\n");
    printf("| 4 - EDITAR TAREFA                  |\n");
    printf("| 5 - INDICAR A TAREFA DO MOMENTO    |\n");
    printf("| 0 - SAIR                           |\n");
    printf("|------------------------------------|\n");
    printf("\n");
    printf("Selecione uma das opções: ");
}

void system_pause(){
    char continuar;
    printf("Pressione Enter para continuar...");
    getchar();
    scanf("%c", &continuar);
}