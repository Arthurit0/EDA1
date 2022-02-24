#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include "tasks.h"

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
    @Param: Um array de char com o nome da tarefa, um inteiro de valor de prioridade, e dois ponteiros
            de "Tempo" relacionados à data limite e a duração da tarefa, respectivamente.

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
            da tarefa, e um inteiro que será usado como o ID da tarefa.

    @Return: A mesma lista de "task" passada como parâmetro, mas com a nova tarefa encadeada como último elemento

    Cria e aloca uma nova tarefa, atribuindo os "DadosTask" como parâmetro, e a insere no final da lista de Tarefas
*/
task * adiciona_nova_Tarefa(task *l, reg *dads, int ident){
    task *novo, *p;

    novo = (task *)malloc(sizeof(task)); //Aloca a nova tarefa e atribui os dados do parâmetro da função
    novo->done = 0;
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
    @Param: Um ponteiro para o início de uma lista de "task", e uma nova tarefa ainda não encadeada nesta lista.

    @Return: A lista de "task" passada como parâmetro, mas com a tarefa passada como segundo parâmetro encadeada como último elemento.

    Adiciona a tarefa passada no segundo parâmetro para a lista de task do primeiro parâmetro, encadeando-a no final desta lista.
*/
task * adiciona_Tarefa(task *l, task *t){
    task *p;

    if(l == NULL) return t; //Se a lista de tarefas for vazia, devolve a nova tarefa com os dados como cabeça da lista

    p = l;

    while(p->prox != NULL){ //Vai até o último elemento da lista
        p = p->prox;
    }

    p->prox = t; //Faz o próximo do último da lista ser o novo elemento

    return l;
}
/*
    @Param: Um ponteiro para o início de uma lista de "task", e um inteiro que é o ID de uma tarefa

    @Return: A lista de "task" sem a tarefa com o ID passado como parâmetro

    Exclui da lista de tarefas a tarefa que possui o ID passado como parâmetro
*/
task * excluir_Tarefa(task *l, int ident){
    task *p, *ant;

    if(l == NULL){ //Se não há nenhuma tarefa, retorna a própria lista
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
            // //Desalocando ponteiros das estruturas internas dos dados, os dados, e por fim o ponteiro de tarefa
            // free(p->dados->duracao);
            // free(p->dados->deadline);
            // free(p->dados);
            // free(p);
    }

    return l;
}
/*
    @Param: Um ponteiro para o início de uma lista de "task", e um inteiro que é o ID de uma tarefa

    @Return: Um ponteiro para a tarefa com o ID passado como parâmetro

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
    @Param: Um ponteiro para uma tarefa, um array de char, que será o novo nome da tarefa, e um valor inteiro, que será o
            indicador de prioridade da tarefa.
    
    @Return: O ponteiro da tarefa passado como parâmetro, mas com os dados de nome e prioridade alterados.

    Recebe uma tarefa e altera seus dados de nome e prioridade para os que foram passados como parâmetros da função
*/
task * edita_Dados(task * t, char editaNome[80], int prior, int done){
    strcpy((t->dados->nome), editaNome);
    t->dados->prioridade = prior;

    return t;
}
/*
    @Param: Um ponteiro para uma tarefa, e 5 valores inteiros, relacionados ao dia, mês, ano, hora e minuto da Deadline da tarefa,
            respectivamente.

    @Return: O ponteiro da tarefa passado como parâmetro, mas com a Deadline alterada

    Recebe uma tarefa e altera os dados da estrutura da Deadline para os que foram passados como parâmetros da função
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
    @Param: Um ponteiro para uma tarefa, e 5 valores inteiros, relacionados ao dia, mês, ano, hora e minuto da duração da tarefa,
            respectivamente.

    @Return: O ponteiro da tarefa passado como parâmetro, mas com a duração alterada

    Recebe uma tarefa e altera os dados da estrutura da Duração para os que foram passados como parâmetros da função
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
/*
    @Param: Um ponteiro para uma tarefa

    @Return: O mesmo ponteiro para a tarefa, mas com o inteiro done da tarefa setado para 1

    Recebe uma tarefa (de preferência, que tenha valor done == 0) e seta seu valor done para 1, marcando a tarefa como concluída
*/
task * compl_task(task *t){
    t->done = 1;
    return t;
}
/*
    @Param: Um ponteiro para o início de uma lista de tarefas

    @Return: Uma lista de tarefas, todas com o parâmetro done igual a 0

    Serve para retornar uma lista em que não haja tarefas já concluidas
*/
task * clear_compl_pass_tasks(task *l){
    time_t t;
    struct tm atual;
    int dia_hoje, mes_hoje, ano_hoje, hora_hoje, minuto_hoje;

    task *p, *subst;
    reg *dados_p;
    tmp *deadline_p, *duracao_p, *tempo_agora;

    p = l;

    while(p != NULL){

        if(p->done != 1){
            deadline_p = cria_Tempo(
                            p->dados->deadline->dia,
                            p->dados->deadline->mes, 
                            p->dados->deadline->ano, 
                            p->dados->deadline->hora, 
                            p->dados->deadline->minuto);
            
            t = time(NULL);
            atual = *localtime(&t);
            dia_hoje = atual.tm_mday;
            mes_hoje = atual.tm_mon + 1;
            ano_hoje = atual.tm_year + 1900;
            hora_hoje = atual.tm_hour;
            minuto_hoje = atual.tm_min;

            tempo_agora = cria_Tempo(dia_hoje, mes_hoje, ano_hoje, hora_hoje, minuto_hoje);

            if(data_anterior_a(tempo_agora, deadline_p)){
                duracao_p = cria_Tempo(
                                p->dados->duracao->dia, 
                                p->dados->duracao->mes, 
                                p->dados->duracao->ano, 
                                p->dados->duracao->hora, 
                                p->dados->duracao->minuto);
                

                dados_p = cria_Dados(p->dados->nome, p->dados->prioridade, deadline_p, duracao_p);

                subst = adiciona_nova_Tarefa(subst, dados_p, p->ID);
            }
        }

        p = p->prox;
    }

    return subst;
}
/*
    @Param: Um ponteiro para o início de uma lista encadeada de tarefas que não estão ordenadas

    @Return: O ponteiro para o início da mesma lista de tarefas, agora ordenadas

    Ordenação Mergesort para a lista de tarefas, baseado na data de início de cada tarefa
*/
task * mg_sort_tasks(task *l){
    task *e, *d, *mid;

    if(l == NULL || l->prox == NULL){
        return l;
    }

    mid = split(l);
    e = mg_sort_tasks(l);
    d = mg_sort_tasks(mid);
    l = merge(e,d);

    return l;
}

task * split(task *l){
    task *x, *y, *p, *t;

    x=y=l;

    if(l == NULL || l->prox == NULL) return l;
    
    while(y->prox != NULL){
        y = y->prox;

        if(y->prox != NULL){
            x = x->prox;
            y = y->prox;
        }
    }

    p = x->prox;
    x->prox = NULL;

    return (p);
}

task * merge(task *e, task *d){
    task *l, *aux;
    tmp *esq, *dir;
    l = NULL;

    while((e != NULL) && (d != NULL)){
        esq = e->dados->deadline;
        dir = d->dados->deadline;

        if(data_anterior_a(esq, dir) == 1){ //(e->dado) < (d->dado)
            aux = e;
            e = e->prox;
            aux->prox = NULL;
            l = adiciona_Tarefa(l, aux);
        }else{
            aux = d;
            d = d->prox;
            aux->prox = NULL;
            l = adiciona_Tarefa(l, aux);
        }
    }

        while(d != NULL){
            aux = d;
            d = d->prox;
            aux->prox = NULL;
            l = adiciona_Tarefa(l, aux);
        }

        while(e != NULL){
            aux = e;
            e = e->prox;
            aux->prox = NULL;
            l = adiciona_Tarefa(l, aux);
        }

        return l;
}

/*
    @Param: Dois valores inteiros representando um mês e ano

    @Return: Um valor inteiro que representa a quantidade de dias do mês

    Apenas uma função para retornar o número de dias de um mês baseado no número do mês e também do ano, que afeta o mês de fevereiro em anos bissextos
*/
int verif_calendario(int mes, int ano){
    switch (mes){
        case 1:
            return 31;

        case 2:
            if((ano % 400 == 0) || (((ano % 4 == 0) && (ano % 100 != 0)))){
                return 29;
            }
            return 28;
        
        case 3:
            return 31;

        case 4:
            return 30;

        case 5:
            return 31;

        case 6:
            return 30;

        case 7:
            return 31;

        case 8:
            return 31;

        case 9:
            return 30;

        case 10:
            return 31;

        case 11:
            return 30;

        case 12:
            return 31; 

        default:
            return -1;
    }
}
/*
    @Param: Dois ponteiros de tarefas

    @Return: Inteiros 1 ou 0, representando true e false

    Compara as deadlines
*/
int data_anterior_a(tmp *esq, tmp *dir){

    if(esq->ano < dir->ano){
        return 1;
    }else if(esq->ano > dir->ano){
        return 0;
    }

    //Se chegou aqui, ambas são no mesmo ano

    if(esq->mes < dir->mes){
        return 1;
    }else if(esq->mes > dir->mes){
        return 0;
    }

    //Se chegou aqui, mesmo mês

    if(esq->dia < dir->dia){
        return 1;
    }else if(esq->dia > dir->dia){
        return 0;
    }

    //Mesmo dia

    if(esq->hora < dir->hora){
        return 1;
    }else if(esq->hora > dir->hora){
        return 0;
    }

    //Mesma hora

    if(esq->minuto < dir->minuto){
        return 1;
    }else if(esq->minuto > dir->minuto){
        return 0;
    }

    //Mesmo minuto, deadline exatamente igual, então retornamos verdadeiro

    return 1;
}
/*
    @Param: Dois ponteiros para estruturas "Tempo", a primeira sendo a data de início de uma tarefa, e a outra a duração

    @Return: Uma estrutura "Tempo", sendo a data final, somando data inicial + duração.

    Função para retornar a data de conclusão de uma tarefa baseada em sua data inicial e duração. Serve para o encadeamento da lista de tarefas
    recomendadas da opção 5 do menu, para que nenhuma tarefa sobreponha a data de início da outra desta lista.
*/
tmp * data_final (tmp *deadline, tmp *duracao){
    tmp * tmpfinal;
    int d, m, a, h, min, qtde_dias_mes;

    tmpfinal = (tmp *)malloc(sizeof(tmp));

    min = (deadline->minuto + duracao->minuto) % 60;
    h = ((deadline->hora + duracao->hora) % 24) + ((deadline->minuto + duracao->minuto) / 60);
    d = (deadline->dia + duracao->dia)+((deadline->minuto + duracao->minuto) / 60);
    m = deadline->mes + duracao->mes;
    a = deadline->ano + duracao->ano;

    do{ 
        if(m > 12){
            m = m - 12;
            a++;   
        }
    } while (m > 12);

    do{
        if(min >= 60){
            min = min - 60;
            h++;
        }

    } while (min >= 60);

    do{
        if(h >= 24){
            h = h - 24;
            d++;
        }
    } while (h >= 24);

    qtde_dias_mes = verif_calendario(m, a);

    do{
        if(d > qtde_dias_mes){
            d = d - qtde_dias_mes;
            m++;
        }

        if(m > 12){
            m = m - 12;
            a++;
        }

        qtde_dias_mes = verif_calendario(m, a);

    } while (d > qtde_dias_mes);

    tmpfinal->minuto = min;
    tmpfinal->hora = h;
    tmpfinal->dia = d;
    tmpfinal->mes = m;
    tmpfinal->ano = a;

    return tmpfinal;
}
/*
    @Params: Um ponteiro apontando para uma lista de tarefas, e uma outra lista com a task mais prioritária adicionada (começando em null em main.c)

    @Return: Uma lista de tarefas com as tarefas prioritárias

    No momento, verifica a de maior prioridade com mais tasks disponiveis a se encaixar, e adiciona esta na lista opt, removendo as que conflitam com ela,
    e fazendo mais uma chamada desta com as restantes. Se a lista for vazia, irá retornar a lista opt
*/
task * filter_optm(task *l, task *opt){
    task *p, *otima_atual;
    int peso, max_peso = 0;
    p = l; 

    if(l == NULL){
        return opt;
    }else{
        while(p != NULL){
            peso = p->dados->prioridade;

            if(peso + num_de_ant_DF(l, p) > max_peso){
                otima_atual = p;
                max_peso = peso + num_de_ant_DF(l, p);
            }
            
            p = p->prox;
        }

        l = rmv_overlapping(l, otima_atual);
        opt = adiciona_Tarefa(opt, otima_atual);
        l = excluir_Tarefa(l, otima_atual->ID);

        filter_optm(l, opt);
    }
}
/*
    @Param: Um ponteiro para uma lista de tarefas, e um ponteiro para uma task

    @Return: A mesma lista, sem nenhuma task que tenha conflito de horário com a que foi passada como parâmetro

    Função que serve para remover as tarefas da lista que são conflitantes com a task passada como parâmetro
*/
task * rmv_overlapping(task* l, task *t){
    task *p;
    tmp *data_inicio_t = t->dados->deadline, 
        *data_final_t = data_final(t->dados->deadline, t->dados->duracao),
        *data_inicio_p,
        *data_final_p;

    p = l;

    while (p != NULL){

        if(p->ID != t->ID){
            data_inicio_p = p->dados->deadline;
            data_final_p = data_final(p->dados->deadline, p->dados->duracao);

            if(!(data_anterior_a(data_inicio_p, data_inicio_t) && data_anterior_a(data_final_p, data_inicio_t) ||
                data_anterior_a(data_final_t, data_inicio_p))){
                l = excluir_Tarefa(l, p->ID);
            }
        }

        p = p->prox;
    }

    return l;
}
/*
    @Param: Um ponteiro para uma lista de tarefas, e um ponteiro para uma task

    @Return: O número de tasks anteriores a passada como parâmetro que não conflitam com o horário

    Retorna o número de tasks na lista anteriores a passada como parâmetro, e que não conflitem com o horário desta 
*/
int num_de_ant_DF(task *l, task *t){
    task *p;
    tmp *data_inicio_t = t->dados->deadline, *data_final_p;
    int cont = 0;

    p = l;

    while (p != NULL && (p->ID != t->ID)){
        data_final_p = data_final(p->dados->deadline, p->dados->duracao);
        if(data_anterior_a(data_final_p, data_inicio_t)){
            cont++;
        }
        

        p = p->prox;
    }

    return cont;
}

task * mg_sort_tasks_DF(task *l){
    task *e, *d, *mid;

    if(l == NULL || l->prox == NULL){
        return l;
    }

    mid = split(l);
    e = mg_sort_tasks(l);
    d = mg_sort_tasks(mid);
    l = merge_DF(e,d);

    return l;
}

task * merge_DF(task *e, task *d){
    task *l, *aux;
    tmp *esq, *dir;
    l = NULL;

    while((e != NULL) && (d != NULL)){
        esq = data_final(e->dados->deadline, e->dados->duracao);
        dir = data_final(d->dados->deadline, d->dados->duracao);

        if(data_anterior_a(esq, dir) == 1){ //(e->dado) < (d->dado)
            aux = e;
            e = e->prox;
            aux->prox = NULL;
            l = adiciona_Tarefa(l, aux);
        }else{
            aux = d;
            d = d->prox;
            aux->prox = NULL;
            l = adiciona_Tarefa(l, aux);
        }
    }

        while(d != NULL){
            aux = d;
            d = d->prox;
            aux->prox = NULL;
            l = adiciona_Tarefa(l, aux);
        }

        while(e != NULL){
            aux = e;
            e = e->prox;
            aux->prox = NULL;
            l = adiciona_Tarefa(l, aux);
        }

        return l;
}