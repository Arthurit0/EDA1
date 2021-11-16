struct Tempo{
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
};

typedef struct Tempo tmp;

struct DadosTask{
    char nome[80];
    tmp *duracao;
    tmp *deadline;
    int prioridade;
};

typedef struct DadosTask reg;
typedef struct Tarefa task;

struct Tarefa{
    int ID;
    reg *dados;
    task *prox;
};

void mostra_Menu();
void mostra_Tarefas(task* l);
void imprime_Unica_Tarefa(task * t);

tmp * cria_Tempo(int d, int m, int a, int h, int min);
reg * cria_Dados(char nm[], int prior, tmp* temp, tmp *durac);

task * adiciona_Tarefa(task *l, reg *dads, int ident);

task * excluir_Tarefa(task *l, int ident);
task * busca_Tarefa(task *l, int ident);

task * edita_Dados(task * t, char editaNome[80], int prior);
task * edita_Deadline(task *t, int d, int m, int a, int h, int min);
task * edita_Duracao(task *t, int d, int m, int a, int h, int min);


