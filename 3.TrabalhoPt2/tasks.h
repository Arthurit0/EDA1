struct Tempo{
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
};

typedef struct Tempo tmp;

struct dados{
    char nome[80];
    tmp *duracao;
    tmp *deadline;
    int prioridade;
};

typedef struct dados reg;
typedef struct Tarefa task;

struct Tarefa{
    int ID;
    int done;
    reg *dados;
    task *prox;
};

//Criar estruturas do tipo tempo e dados
tmp * cria_Tempo(int d, int m, int a, int h, int min);
reg * cria_Dados(char nm[], int prior, tmp* temp, tmp *durac);

//Manipular estruturas do tipo task
task * adiciona_nova_Tarefa(task *l, reg *dads, int ident);
task * excluir_Tarefa(task *l, int ident);
task * busca_Tarefa(task *l, int ident);

//Editar estruturas(criar e substituir)
task * edita_Dados(task * t, char editaNome[80], int prior, int done);
task * edita_Deadline(task *t, int d, int m, int a, int h, int min);
task * edita_Duracao(task *t, int d, int m, int a, int h, int min);

//Verificar data final
int verif_calendario(int mes, int ano);
tmp * data_final (tmp *deadline, tmp *duracao);

//Ordenar lista de tarefas por data inicial
task * mg_sort_tasks(task *l);
task * split(task *l);
task * merge(task *e, task *d);
int data_anterior_a(tmp *a, tmp *d);

// Tarefas do momento
task * compl_task(task *t);
task * clear_compl_tasks(task *l);

task * mg_sort_tasks_DF(task *l);
task * merge_DF(task *e, task *d);

task * filter_optm(task *l, task *opt);
task * rmv_overlapping(task* l, task *t);
int num_de_ant_DF(task *l, task *t);