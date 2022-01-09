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
    reg *dados;
    task *prox;
};

//Criar estruturas do tipo tempo e dados
tmp * cria_Tempo(int d, int m, int a, int h, int min);
reg * cria_Dados(char nm[], int prior, tmp* temp, tmp *durac);

//Manipular estruturas do tipo task
task * adiciona_Tarefa(task *l, reg *dads, int ident);
task * excluir_Tarefa(task *l, int ident);
task * busca_Tarefa(task *l, int ident);

//Editar estruturas(criar e substituir)
task * edita_Dados(task * t, char editaNome[80], int prior);
task * edita_Deadline(task *t, int d, int m, int a, int h, int min);
task * edita_Duracao(task *t, int d, int m, int a, int h, int min);

int verif_calendario(int mes, int ano);
tmp * data_final (tmp *deadline, tmp *duracao);
