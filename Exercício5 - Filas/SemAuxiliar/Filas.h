typedef struct nodo no;

struct nodo{
    int dado;
    no * prox;
};

no * retira_inicio(no * l, int * valor);
no * insere_fim(no * l, int valor);
