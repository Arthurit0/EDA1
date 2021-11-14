#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "tasks.h"

void mostra_Menu(){
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

//Cria um ponteiro para a estrutura "Duracao" e o aloca, atribui os dados e devolve o ponteiro.
dur * cria_Duracao(int hrs, int mins){
    dur *novo;

    novo = (dur *)malloc(sizeof(dur));

    novo->horas = hrs + mins/60;
    novo->minutos = mins%60;

    return novo;
}

//Cria um ponteiro para a estrutura "DadosTask" e o aloca, atribui os ponteiros de "Tempo" e "Duracao"
reg * cria_Dados(char nm[], int prior, tmp* temp, dur *durac){
    reg *novo;

    novo = (reg *)malloc(sizeof(reg));

    strcpy((novo->nome), nm);
    novo->prioridade = prior;
    novo->deadline = temp;
    novo->duracao = durac;

    return novo;
}

//Cria e aloca uma nova tarefa, atribuindo os "DadosTask" como parâmetro, e a insere no final da lista de Tarefas
task * adiciona_Tarefa(task *l, reg *dads){
    task *novo, *p;

    novo = (task *)malloc(sizeof(task)); //Aloca a nova tarefa e atribui os dados do parâmetro da função
    novo->ID = cria_Id_Novo(l);
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

//Cria um ID para uma tarefa, e quando o ID é criado, verifica se não existe um ID igual a este na lista
int cria_Id_Novo(task* l){
    task *p;
    time_t t; srand((unsigned) time(&t)); //Dando seed para o rand()
    int cont, ID;

    if(l == NULL) return 1000+(rand()%8999); //Farei tasks com IDs entre 1000 e 9999

    p = l;

    do{
        cont = 0;
        ID = 1000+(rand()% 9999); //Crio um ID

        while(p != NULL){ //Dentro deste while, verifico em toda a lista se há um ID igual a este...
            if(ID == p->ID){
                cont++;
                break;
            }
            p = p->prox;
        }

    }while(cont != 0); //... se houver um ID igual, o contador será maior que 1 e a recursão recomeça, criando um novo ID, até que um inédito seja criado

    return ID;
}

//Função para imprimir todas as tarefas
void mostra_Tarefas(task* l){
    task *p; tmp *ddline; dur *durac;

    if(l != NULL){
        p = l;
        
        while(p != NULL){
            ddline = p->dados->deadline; //Crio ponteiros de "Tempo" e "Duracao" para facilitar na impressão
            durac = p->dados->duracao;
            printf("\n=================================\n");
            printf("Tarefa de ID %d:\n", p->ID);
            printf("-> Tarefa: %s\n", p->dados->nome);
            printf("-> Prioridade: %d\n", p->dados->prioridade);
            printf("-> Duracao: %d hora(s) e %d minuto(s)\n", durac->horas, durac->minutos);
            printf("-> Deadline: %d/%d/%d, as %d:%d", ddline->dia, ddline->mes, ddline->ano, ddline->hora, ddline->minuto);
            printf("\n==================================\n");
            p = p->prox;
        }
        printf("\n");
    }
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