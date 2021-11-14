

struct Duracao{
    int horas;
    int minutos;
};

struct Tempo{
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
};

typedef struct Duracao dur;
typedef struct Tempo tmp;

struct DadosTask{
    char nome[80];
    dur *duracao;
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

tmp * cria_Tempo(int d, int m, int a, int h, int min);
dur * cria_Duracao(int hrs, int mins);
reg * cria_Dados(char nm[], int prior, tmp* temp, dur *durac);
task * adiciona_Tarefa(task *l, reg *dads);
int cria_Id_Novo(task *l);

task * excluir_Tarefa(task *l, int ident);
task * busca_Tarefa(task *l, int ident);

