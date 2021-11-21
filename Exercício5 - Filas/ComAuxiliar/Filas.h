typedef struct nodo no;

struct nodo{
    int dado;
    no * prox;
};

typedef struct fila fl;

struct fl{
    no * init;
    no * fim;
    int num;
};

fl * inicializa_fila();
no * insere_fim(fl* f, int valor);
no * retira_inicio(fl* f);