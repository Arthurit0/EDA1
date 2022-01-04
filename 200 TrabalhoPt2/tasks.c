#include <stdlib.h>
#include <time.h>
#include <string.h>
//#include <locale.h>
#include "tasks.h"

// Formato de documentação
// http://www.linhadecodigo.com.br/artigo/1089/phpdoc-documentando-bem-seu-codigo.aspx

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
    printf("| 5 - INDICAR A TAREFA DO MOMENTO    |\n");
    printf("| 0 - SAIR                           |\n");
    printf("|------------------------------------|\n");
    printf("\n");
    printf("Selecione uma opcao: ");
}

/*
    @Param: Valores inteiros referentes a dia, mês, ano, hora e minuto, respectivamente
    
    @Return: Um ponteiro para a estrutura "Tempo".

    Cria um ponteiro para a estrutura "Tempo" e o aloca, 
    atribui os valores de dia e horário, e devolve o ponteiro "Tempo".
*/
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

/*
    @Param: Um array de char com o nome da Task, um inteiro de valor de prioridade, e dois ponteiros
            de "Tempo" relacionados à data limite e a duração da task, respectivamente.

    @Return: Um ponteiro para a estrutura "DadosTask"

    Cria um ponteiro para a estrutura "DadosTask" e o aloca, atribui a ele os parâmetros de nome,
    prioridade, deadline e duração, e retorna este ponteiro.
*/
reg * cria_Dados(char nm[], int prior, tmp* temp, tmp *durac){
    reg *novo;

    novo = (reg *)malloc(sizeof(reg));

    strcpy((novo->nome), nm);
    novo->prioridade = prior;
    novo->deadline = temp;
    novo->duracao = durac;

    return novo;
}
/*
    @Param: Um ponteiro para o início de uma lista de "task", um ponteiro para "reg" com os dados
            da task, e um inteiro que será usado como o ID da task.

    @Return: A mesma lista de "task" passada como parâmetro, mas com a nova task encadeada como último elemento

    Cria e aloca uma nova tarefa, atribuindo os "DadosTask" como parâmetro, e a insere no final da lista de Tarefas
*/
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

/*
    @Param: Um ponteiro para o início de uma lista de "task", e um inteiro que é o ID de uma "task"

    @Return: A lista de "task" sem a "task" com o ID passado como parâmetro

    Exclui da lista de tarefas a tarefa que possui o ID passado como parâmetro
*/
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
        return l;
    }else{ //Encontrou na lista:
        if (ant == NULL){ //É o primero da lista, logo, lista aponta para o próximo
            l = p->prox;
        }else{ //Está no meio da lista. O anterior a este ponteiro apontará para o próximo deste ponteiro
            ant->prox = p->prox;
        }
            //Desalocando ponteiros das estruturas internas dos dados, os dados, e por fim o ponteiro de tarefa
            free(p->dados->duracao);
            free(p->dados->deadline);
            free(p->dados);
            free(p);
    }

    return l;
}

/*
    @Param: Um ponteiro para o início de uma lista de "task", e um inteiro que é o ID de uma task

    @Return: Um ponteiro para a task com o ID passado como parâmetro

    Busca uma tarefa com o ID passado como parâmetro, e devolve um ponteiro para esta tarefa
*/
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

/*
    @Param: Um ponteiro para uma task, um array de char, que será o novo nome da tarefa, e um valor inteiro, que será o
            indicador de prioridade da tarefa.
    
    @Return: O ponteiro da task passado como parâmetro, mas com os atributos de nome e prioridade alterados.

    Recebe uma task e altera seus dados de nome e prioridade para os que foram passados como parâmetros da função
*/

task * edita_Dados(task * t, char editaNome[80], int prior){
    strcpy((t->dados->nome), editaNome);
    t->dados->prioridade = prior;

    return t;
}

/*
    @Param: Um ponteiro para uma task, e 5 valores inteiros, relacionados ao dia, mês, ano, hora e minuto da Deadline da task,
            respectivamente.

    @Return: O ponteiro da task passado como parâmetro, mas com a Deadline alterada

    Recebe uma task e altera os dados da estrutura da Deadline para os que foram passados como parâmetros da função
*/
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

/*
    @Param: Um ponteiro para uma task, e 5 valores inteiros, relacionados ao dia, mês, ano, hora e minuto da duração da task,
            respectivamente.

    @Return: O ponteiro da task passado como parâmetro, mas com a duração alterada

    Recebe uma task e altera os dados da estrutura da Duração para os que foram passados como parâmetros da função
*/
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

tmp * data_final (tmp *deadline, tmp *duracao){
    tmp * tmpfinal;
    int d, m, a, h, min;


    tmpfinal = (tmp *)malloc(sizeof(tmp));

    min = ((deadline->minuto) + (duracao->minuto));

    do
    {
        if(min >= 60){
            min = min - 60;
            h++;
        }
    } while (min >= 60);

    h = (deadline->hora) + (duracao->hora);

    do
    {
        if(h >= 24){
            h = h - 24;
            d++;
        }
    } while (h >= 24);

    d = (deadline->dia) + (duracao->dia);
    
    do
    {
        if(d >= 30){
            d = d - 29;
            m++;
        }
    } while (d >= 30);

    m = (deadline->mes) + (duracao->mes);

    do
    {
        if(m >= 12){

        }
    } while ();
    

}