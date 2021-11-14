
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

struct Registros{
    char nome[80];
    dur *duracao;
    temp *deadline;
    int prioridade;
};

struct Tarefa{
    int ID;
    data *dados;
    tk *prox;
};

typedef struct Tarefa tk;
typedef struct Registros data;
typedef struct Tempo temp;
typedef struct Duracao dur;

void mostra_Menu();
void mostra_Tarefas(tk* l);
temp * cria_Temp(int d, int m, int a, int h, int min);
data * cria_Reg(char n[80], int prior, dur durac, temp dL);
dur * cria_Durac(int h, int m);
tk* add_Task(tk* l, data d);
int cria_Id_Novo(tk* l);



