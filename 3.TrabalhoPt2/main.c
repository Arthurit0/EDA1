#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "tasks.h"

void mostra_Tarefas(task* l);
void imprime_Unica_Tarefa(task *t);
void mostra_Menu();
void tarefas_do_Momento_Main(task *l);
task * concluir_tarefa(task *l);
task * adiciona_Tarefa_Main(task *l);
task * edita_Dados_Main(task * t);
task * edita_Deadline_Main(task * t);
task * edita_Duracao_Main(task * t);
int ID; //Variável global para cada tarefa ter um número inteiro "ID" única.

int main(){
    setlocale(LC_ALL,"pt-br");
    task *l = NULL, *edTarefa, *p;
    int op = 0, op2, rmvID, edID, conclID;
    ID = 1;

    do{
        system("cls");
        
        mostra_Menu();
        scanf("%d", &op);

        switch (op){

            case 1:
                system("cls");
                l = adiciona_Tarefa_Main(l);
                break;

            case 2:
                system("cls");
                if(l != NULL){
                    printf("-> Todas as Tarefas:\n");
                    mostra_Tarefas(l);
                }else{
                    printf("-> Sem Tarefas! :)\n\n");
                }
                break;

            case 3:
                system("cls");
                if(l != NULL){
                    mostra_Tarefas(l);
                    printf("Digite o ID da tarefa que deseja excluir, ou 0 para cancelar a operacao: ");
                    scanf("%d", &rmvID);

                    if(rmvID == 0) break;

                    if(busca_Tarefa(l, rmvID) == NULL){
                        printf("\nNenhuma tarefa com esse ID foi encontrada! ");
                        break;
                    }

                    l = excluir_Tarefa(l, rmvID);

                    printf("\nTarefa excluida da lista de tarefas! ");
                }else{
                    printf("Nao ha tarefas! \n\n");
                }

                break;

            case 4:
                system("cls");
                
                if(l != NULL){
                    mostra_Tarefas(l);
                    printf("Digite o ID da tarefa a editar, ou 0 para cancelar a operacao: ");
                    scanf("%d", &edID);

                    if(edID == 0) break;

                    if(busca_Tarefa(l, edID) == NULL){
                        printf("\nNenhuma tarefa com esse ID foi encontrada! ");
                        break;
                    }

                    system("cls");
                    edTarefa = busca_Tarefa(l, edID);
                    imprime_Unica_Tarefa(edTarefa);

                    if(edTarefa != NULL){
                        printf("\n1 - EDITAR DADOS (NOME, PRIORIDADE E STATUS)");
                        printf("\n2 - EDITAR DEADLINE");
                        printf("\n3 - EDITAR DURACAO");
                        printf("\n0 - CANCELAR\n");
                        printf("\nSelecione uma opcao para editar: ");
                        scanf("%d", &op2);

                        system("cls");

                        switch (op2){
                            

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
                                printf("\nOpcao invalida, tente novamente! ");
                                break;
                        }
                    }else{
                        printf("\nTarefa nao encontrada! ");
                    }
                }else{
                    printf("Nao ha tarefas! ");
                }

                break;

            case 5:
                system("cls");
                if(l != NULL){
                    tarefas_do_Momento_Main(l);
                }else{
                    printf("Nao ha tarefas! ");
                }

                break;

            case 6:
                system("cls");
                if(l != NULL){
                    mostra_Tarefas(l);
                    printf("Selecione o ID da tarefa a concluir, ou 0 para cancelar a operacao: ");
                    scanf("%d", &conclID);

                    if(conclID == 0) break;

                    p = busca_Tarefa(l, conclID);

                    if(p == NULL){
                        printf("\nNenhuma tarefa com esse ID foi encontrada! ");
                        break;
                    }

                    p = compl_task(p);

                    printf("\nTarefa marcada como concluida! ");
                }else{
                    printf("Nao ha tarefas! ");
                }
                break;

            case 0:
                return 0;
            
            default:
                printf("\nOpcao invalida, tente novamente! ");
                break;
        }
        system("pause");
    }while(op != 0);

}
/*
    @Param: Um ponteiro para uma lista de tasks.
    
    @Return: O mesmo ponteiro para a lista de tasks, mas com uma nova tarefa adicionada.
    
    Aqui é onde todas os dados da nova tarefa são criados com o conteúdo digitado pelo usuário, para então ser enviada
    para a função "adiciona_nova_Tarefa", onde a tarefa será encadeada na lista de tasks.
*/
task * adiciona_Tarefa_Main(task *l){
    // tmp * tempofinal;

    //Para atribuir em dados:
    char nome[80]; int prior;
    //Para atribuir em tempo:
    int dia, mes, ano, hora, min, dias_do_mes;
    //Para atribuir em duracao:
    int  dur_min, dur_hora, dur_dia = 0, dur_mes = 0, dur_ano = 0; char tarefa_longa;
    //Para associar na task:
    reg *dados; tmp *tempo; tmp *duracao;


    printf("==> DADOS DA TAREFA:\n\n");
    printf("- Digite o nome da tarefa: ");
    // fflush(stdin);
    getchar();
    fgets(nome, 80, stdin);

    do{
        printf("- Digite a prioridade da tarefa (1 a 5): ");
        scanf("%d", &prior);

        if(prior < 1 || prior > 5){
            printf("\nValor de prioridade invalido! ");
            system("pause");
            printf("\n");
        }
    }while (prior < 1 || prior > 5);

    printf("\n==> DEADLINE:\n\n");

    printf("Digite a data do deadline da tarefa:\n\n");

    do{
        printf("- Dia: ");
        scanf("%d", &dia);

        if(dia < 1 || dia > 31){
            printf("\nValor de dia invalido! ");
            system("pause");
            printf("\n");
            continue;
        }

        printf("- Mes: ");
        scanf("%d", &mes);

        if(mes < 1 || mes > 12){
            printf("\nValor de mes invalido! ");
            system("pause");
            printf("\n");
            continue;
        }

        dias_do_mes = verif_calendario(mes, 2000);
        
        if(dia > dias_do_mes){
            printf("\nO mes %d possui %d dias, logo, o dia %d e invalido! ", mes, dias_do_mes, dia);
            system("pause");
            printf("\n");
        }

    } while ((dia < 1 || dia > 31) || (mes < 1 || mes > 12) || (dia > dias_do_mes));

    do
    {
        printf("- Ano: ");
        scanf("%d", &ano);

        if(ano < 1990 ){
            printf("\nValor de ano invalido! ");
            system("pause");
            printf("\n");
        }
    } while (ano < 1990);
    
    do{
        printf("- Hora: ");
        scanf("%d", &hora);

        if(hora < 0 || hora > 23){
            printf("\nValor de hora invalido! ");
            system("pause");
            printf("\n");
        }

    } while (hora < 0 || hora > 23);

    do
    {
        printf("- Minuto: ");
        scanf("%d", &min);

        if(min < 0 || min > 59){
            printf("\nValor de minuto invalido! ");
            system("pause");
            printf("\n");
        }
    } while (min < 0 || min > 59);

    printf("\n==> DURACAO DA TAREFA:\n");

    printf("\nDigite a quantidade estimada da duracao da tarefa em:\n\n");
    
    do{
        printf("- Horas: ");
        scanf("%d", &dur_hora);

        if(dur_hora < 0){
            printf("\nValor de duracao em horas invalida! ");
            system("pause");
            printf("\n");
        }

    } while (dur_hora < 0);

    do{
        printf("- Minutos: ");
        scanf("%d", &dur_min);

        if(dur_min < 0){
            printf("\nValor de duracao em minutos invalida! ");
            system("pause");
            printf("\n");
        }

    } while (dur_min < 0);

    printf("\n==> TAREFA LONGA?\n");

    do{
        printf("\nEsta e uma tarefa longa (que pode demorar dias, meses e/ou anos)? S/N: ");
        getchar();
        tarefa_longa = getchar();

        if(tarefa_longa != 's' && tarefa_longa != 'S' && tarefa_longa != 'n' && tarefa_longa != 'N'){
            printf("\nOpcao invalida, tente novamente! ");
            system("pause");
            printf("\n");
        }

    } while ((tarefa_longa != 's') && (tarefa_longa != 'S') && (tarefa_longa != 'n') && (tarefa_longa != 'N'));
    
    if(tarefa_longa == 's' || tarefa_longa == 'S'){

        do{
            printf("- Dias: ");
            scanf("%d", &dur_dia);
        
            if(dur_dia < 0){
                printf("\nValor de duracao em dias invalido! ");
                system("pause");
                printf("\n");
            }
        } while (dur_dia < 0);

        do{
            printf("- Meses: ");
            scanf("%d", &dur_mes);
        
            if(dur_mes < 0){
                printf("\nValor de duracao em meses invalido! ");
                system("pause");
                printf("\n");
            }
        } while (dur_mes < 0);

        do{
            printf("- Anos: ");
            scanf("%d", &dur_ano);
        
            if(dur_ano < 0){
                printf("\nValor de duracao em anos invalido! ");
                system("pause");
                printf("\n");
            }
        } while (dur_ano < 0);
    }

    tempo = cria_Tempo(dia, mes, ano, hora, min);
    duracao = cria_Tempo(dur_dia, dur_mes, dur_ano, dur_hora, dur_min);
    dados = cria_Dados(nome, prior, tempo, duracao);
    l = adiciona_nova_Tarefa(l, dados, ID);
    l = mg_sort_tasks(l);
    ID++;

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
    int prior, done;

    printf("==> NOVOS DADOS DA TAREFA:\n\n");

    printf("\n- Digite o novo nome da tarefa: ");
    fflush(stdin);
    fgets(editaNome, 80, stdin);
    printf("- Digite a nova prioridade da tarefa: ");
    scanf("%d", &prior);

    do{
        printf("- Status: Digite 1 para marcar como concluida, ou 0 como para fazer: ");
        scanf("%d", &done);

        if(done != 0 && done != 1){
            printf("\nOpcao invalida!");
            system("pause");
            printf("\n");
        }

    }while(done != 0 && done != 1);

    printf("\nDados editados! ");

    return edita_Dados(t, editaNome, prior, done);
}
/*
    @Param: Um ponteiro para uma lista de tasks.
    
    @Return: O mesmo ponteiro para a lista de tasks, com uma tarefa tendo a estrutura de "Tempo" Deadline alterada.
    
    Aqui é onde os novos valores da deadline são digitados pelo usuário, para então serem enviados para a função "edita_Deadline" em
    "tasks.c", que é onde a substituição dos dados desta task acontecem.
*/
task * edita_Deadline_Main(task * t){
    int d, m, a, hor, min, dias_do_mes;

    printf("\n==> NOVA DEADLINE:\n\n");

    printf("\nDigite a nova data de deadline da tarefa:\n\n");

    do{
        printf("- Dia: ");
        scanf("%d", &d);

        if(d < 1 || d > 31){
            printf("\nValor de dia invalido! ");
            system("pause");
            printf("\n");
            continue;
        }

        printf("- Mes: ");
        scanf("%d", &m);

        if(m < 1 || m > 12){
            printf("\nValor de mes invalido! ");
            system("pause");
            printf("\n");
            continue;
        }

        dias_do_mes = verif_calendario(m, 2000);
        
        if(d > dias_do_mes){
            printf("\nO mes %d possui %d dias, logo, o dia %d e invalido! ", m, dias_do_mes, d);
            system("pause");
            printf("\n");
        }

    } while ((d < 1 || d > 31) || (m < 1 || m > 12) || (d > dias_do_mes));

    do
    {
        printf("- Ano: ");
        scanf("%d", &a);

        if(a < 1990 ){
            printf("\nValor de ano invalido! ");
            system("pause");
            printf("\n");
        }
    } while (a < 1990);
    
    do{
        printf("- Hora: ");
        scanf("%d", &hor);

        if(hor < 0 || hor > 23){
            printf("\nValor de hora invalido! ");
            system("pause");
            printf("\n");
        }

    } while (hor < 0 || hor > 23);

    do
    {
        printf("- Minuto: ");
        scanf("%d", &min);

        if(min < 0 || min > 59){
            printf("\nValor de minuto invalido! ");
            system("pause");
            printf("\n");
        }
    } while (min < 0 || min > 59);

    printf("\nDeadline alterada! ");

    return edita_Deadline(t, d, m, a, hor, min);
}
/*
    @Param: Um ponteiro para uma lista de tasks.
    
    @Return: O mesmo ponteiro para a lista de tasks, com uma tarefa tendo a estrutura de "Tempo" Duracao alterada.
    
    Aqui é onde os novos valores da duração são digitados pelo usuário, para então serem enviados para a função "edita_Duracao" em
    "tasks.c", que é onde a substituição dos dados desta task acontecem.
*/
task * edita_Duracao_Main(task * t){
    int d = t->dados->duracao->dia,
        m = t->dados->duracao->mes, 
        a = t->dados->duracao->ano,
        hor, min;
    tmp *dur = t->dados->deadline;
    char tarefa_longa;


    printf("\n==> NOVA DURACAO DA TAREFA:\n");

    printf("\nDigite a nova quantidade estimada da duracao da tarefa em:\n\n");

    printf("- Horas: ");
    scanf("%d", &hor);
    printf("- Minutos: ");
    scanf("%d", &min);
    
    do{
        printf("\nDeseja adicionar/alterar dados de duraçao de tarefa longa(dias, meses e/ou anos)? S/N: ");
        getchar();
        tarefa_longa = getchar();

        if(tarefa_longa != 's' && tarefa_longa != 'S' && tarefa_longa != 'n' && tarefa_longa != 'N'){
            printf("\nOpcao invalida, tente novamente! ");
            system("pause");
            printf("\n");
        }

    } while ((tarefa_longa != 's') && (tarefa_longa != 'S') && (tarefa_longa != 'n') && (tarefa_longa != 'N'));
    
    if(tarefa_longa == 's' || tarefa_longa == 'S'){

        do{
            printf("\n- Dias: ");
            scanf("%d", &d);
        
            if(d < 0){
                printf("\nValor de duracao em dias invalido! ");
                system("pause");
            }
        } while (d < 0);

        do{
            printf("- Meses: ");
            scanf("%d", &m);
        
            if(m < 0){
                printf("\nValor de duracao em meses invalido! ");
                system("pause");
                printf("\n");
            }
        } while (m < 0);

        do{
            printf("- Anos: ");
            scanf("%d", &a);
        
            if(a < 0){
                printf("\nValor de duracao em anos invalido! ");
                system("pause");
                printf("\n");
            }
        } while (a < 0);
    }

    printf("\nDuracao alterada! ");

    return edita_Duracao(t, d, m, a, hor, min);
}
/*
    @Param: Um ponteiro para o início de uma LSE de tasks.

    Função para imprimir todos os dados de cada task de uma lista de tasks.
*/
void mostra_Tarefas(task* l){
    task *p; tmp *ddline; tmp *durac;

    if(l != NULL){
        p = l;
        
        while(p != NULL){
            ddline = p->dados->deadline; //Crio ponteiros de "Tempo" e "Duracao" para facilitar na impressão.
            durac = p->dados->duracao;
            printf("\n==================================================================\n");
            printf("Tarefa de ID %d:\n", p->ID);
            printf("-> Tarefa: %s\n", p->dados->nome);
            printf("-> Prioridade: %d\n", p->dados->prioridade);
            printf("-> Duracao: %.2d hora(s) e %.2d minuto(s)", durac->hora, durac->minuto);
            
            if(durac->dia > 0){
                printf(", %d dia(s)", durac->dia);
            }

            if(durac->mes > 0){
                printf(", %d mes(es)", durac->mes);
            }

            if(durac->ano > 0){
                printf(", %d ano(s)", durac->ano);
            }

            printf("\n-> Deadline: %.2d/%.2d/%d, as %.2d:%.2d", ddline->dia, ddline->mes, ddline->ano, ddline->hora, ddline->minuto);
                printf("\n-> Status: ");
            if(p->done == 0){
                printf("Para Fazer");
            }else{
                printf("Feito ;)");
            }
            printf("\n===================================================================\n");
            p = p->prox;
        }
        printf("\n");
    }
}
/*
    @Param: Um ponteiro para uma task.

    Função para imprimir todos os dados de uma task.
*/
void imprime_Unica_Tarefa(task *t){
    tmp *ddline; tmp *durac;

    ddline = t->dados->deadline; //Crio ponteiros de "Tempo" e "Duracao" para facilitar na impressão.
    durac = t->dados->duracao;
    printf("\n==================================================================\n");
    printf("Tarefa de ID %d:\n", t->ID);
    printf("-> Tarefa: %s\n", t->dados->nome);
    printf("-> Prioridade: %d\n", t->dados->prioridade);
    printf("-> Duracao: %.2d hora(s) e %.2d minuto(s)\n", durac->hora, durac->minuto);

    if(durac->dia > 0){
        printf(", %d dia(s)", durac->dia);
    }

    if(durac->mes > 0){
        printf(", %d mes(es)", durac->mes);
    }

    if(durac->ano > 0){
        printf(", %d ano(s)", durac->ano);
    }

    printf("\n-> Deadline: %.2d/%.2d/%d, as %.2d:%.2d", ddline->dia, ddline->mes, ddline->ano, ddline->hora, ddline->minuto);
    printf("\n-> Status: ");
    if(t->done == 0){
        printf("Para Fazer");
    }else{
        printf("Feito ;)");
    }
    printf("\n===================================================================\n");
}
/*
    Menu de opções para o usuário, impresso em "int Main()"
*/
void mostra_Menu(){
    time_t t = time(NULL);
    struct tm atual = *localtime(&t);
    int dia_hoje = atual.tm_mday, 
        mes_hoje = atual.tm_mon + 1, 
        ano_hoje = atual.tm_year + 1900,
        hora_hoje = atual.tm_hour,
        minuto_hoje = atual.tm_min;
    
    system("cls");
    printf("|------------------------------------|\n");
    printf("|         CADASTRO DE TAREFAS        |\n");
    printf("|------------------------------------|\n");
   
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
    printf("|           MENU DE OPCOES           |\n");
    printf("|------------------------------------|\n");
    printf("| 1 - INSERIR NOVA TAREFA            |\n");
    printf("| 2 - VISUALIZAR TAREFAS CADASTRADAS |\n");
    printf("| 3 - EXCLUIR TAREFA                 |\n");
    printf("| 4 - EDITAR TAREFA                  |\n");
    printf("| 5 - INDICAR AS TAREFAS DO MOMENTO  |\n");
    printf("| 6 - CONCLUIR TAREFA                |\n");
    printf("| 0 - SAIR                           |\n");
    printf("|------------------------------------|\n");
    printf("\n");
    printf("Selecione uma das opcoes: ");
}
/*
    @Param: Um ponteiro para o início de uma lista de tarefas

    Exibe as tarefas recomendadas para o usuário fazer no momento, baseadas em prioridade, deadline e duração
*/
void tarefas_do_Momento_Main(task *l){
    task * subst;

    subst = clear_compl_tasks(l);

    if(subst == NULL){
        printf("-> Nao ha tarefas para fazer :B\n\n");
    }else{
        subst = mg_sort_tasks_DF(subst);
        subst = filter_optm(subst, NULL);
        subst = mg_sort_tasks(subst);

        mostra_Tarefas(subst);
    }
}
