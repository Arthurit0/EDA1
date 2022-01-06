#include <stdlib.h>
#include <time.h>
#include <string.h>
//#include <locale.h>
#include "tasks.h"

void mostra_Menu(){
    //setlocale(LC_ALL, "pt-BR");
    system("cls");
    printf("|------------------------------------|\n");
    printf("|         CADASTRO DE TAREFAS        |\n");
    printf("|____________________________________|\n");
    printf("|           MENU DE OPCOES           |\n");
    printf("|------------------------------------|\n");
    printf("| 1 - INSERIR NOVA TAREFA            |\n");
    printf("| 2 - VISUALIZAR TAREFAS CADASTRADAS |\n");
    printf("| 3 - EXCLUIR TAREFA                 |\n");
    printf("| 4 - EDITAR TAREFA                  |\n");
    //printf("| 5 - INDICAR A TAREFA DO MOMENTO    |\n");
    printf("| 0 - SAIR                           |\n");
    printf("|------------------------------------|\n");
    printf("\n");
    printf("Selecione uma opcao: ");
}

//Cria um ponteiro para a estrutura "Tempo" e o aloca, atribui os dados e devolve o ponteiro.
tmp * cria_Tempo(int d, int m, int a, int h, int min){ 
    tmp *novo;

    novo = (tmp *)malloc(sizeof(tmp));

    novo->dia = d;
    novo->mes = m;
    novo->ano = a;
    novo->hora = h;
    novo->minuto = min;

    return novo;
}

//Cria um ponteiro para a estrutura "DadosTask" e o aloca, atribui os ponteiros de "Tempo" e "Duracao"
reg * cria_Dados(char nm[], int prior, tmp* temp, tmp *durac){
    reg *novo;

    novo = (reg *)malloc(sizeof(reg));

    strcpy((novo->nome), nm);
    novo->prioridade = prior;
    novo->deadline = temp;
    novo->duracao = durac;

    return novo;
}

//Cria e aloca uma nova tarefa, atribuindo os "DadosTask" como parâmetro, e a insere no final da lista de Tarefas
task * adiciona_Tarefa(task *l, reg *dads, int ident){
    task *novo, *p;

    novo = (task *)malloc(sizeof(task)); //Aloca a nova tarefa e atribui os dados do parâmetro da função
    novo->ID = ident;
    novo->dados = dads;
    novo->prox = NULL;

    if(l == NULL) return novo; //Se a lista de tarefas for vazia, devolve a nova tarefa com os dados como cabeça da lista

    p = l;

    while(p->prox != NULL){ //Vai até o último elemento da lista
        p = p->prox;
    }

    p->prox = novo; //Faz o próximo do último da lista ser o novo elemento

    return l;
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

void imprime_Unica_Tarefa(task * t){
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

//Exclui a tarefa que possui o ID passado como parâmetro
task * excluir_Tarefa(task *l, int ident){
    task *p, *ant;

    if(l == NULL){ //Se não há nenhuma tarefa, retorna a própria lista
        printf("Não há nenhuma tarefa! ");    
        return l;
    }

    p = l;
    ant = NULL;

    while ((p != NULL) && (p->ID != ident)){//Percorre a lista até achar a tarefa com ID igual ao parâmetro, ou até p apontar para o próximo do último elemento (ou seja, apontar para NULL)
        ant = p;
        p = p->prox;
    }

    if(p == NULL){ //Foi até o final da lista
        printf("\nNenhuma task com esse ID foi encontrada! ");
    }else{ //Encontrou na lista:
        if (ant == NULL){ //É o primero da lista, logo, lista aponta para o próximo
            l = p->prox;
        }else{ //Está no meio da lista. O anterior a este ponteiro apontará para o próximo deste ponteiro
            ant->prox = p->prox;
        }
            //Desalocando ponteiros das estruturas internas dos dados, depois os dados, e por fim o ponteiro de tarefa
            free(p->dados->duracao);
            free(p->dados->deadline);
            free(p->dados);
            free(p);
    }

    return l;
}

//Busca uma tarefa com o ID passado como parâmetro, e devolve um ponteiro para esta tarefa
task * busca_Tarefa(task *l, int ident){
    task *p;

    if(l == NULL) return NULL; //Se a lista for vazia, devolve NULL (será tratado em main)
    p = l;
    
    while(p != NULL && p->ID != ident){ //Percorre a lista até achar a tarefa com ID igual ao parâmetro, ou até p apontar para o próximo do último elemento (ou seja, apontar para NULL)
        p = p->prox;
    }

    if(p == NULL){ //Foi até o final da lista e não encontrou uma tarefa com mesmo ID, logo, retorna NULL (será tratado em main)
        return NULL;
    }else{ //Se p não é NULL, a tarefa com este ID foi encontrada, então retorna esta tarefa
        return p;
    }
}

task * edita_Dados(task * t, char editaNome[80], int prior){
    strcpy((t->dados->nome), editaNome);
    t->dados->prioridade = prior;

    return t;
}

task * edita_Deadline(task *t, int d, int m, int a, int h, int min){
    tmp * edit_temp;
    edit_temp = t->dados->deadline;

    edit_temp->dia = d;
    edit_temp->mes = m;
    edit_temp->ano = a;
    edit_temp->hora = h;
    edit_temp->minuto = min;

    return t;
}

task * edita_Duracao(task *t, int d, int m, int a, int h, int min){
    tmp * edit_temp;
    edit_temp = t->dados->duracao;

    edit_temp->dia = d;
    edit_temp->mes = m;
    edit_temp->ano = a;
    edit_temp->hora = h;
    edit_temp->minuto = min;

    return t;
}