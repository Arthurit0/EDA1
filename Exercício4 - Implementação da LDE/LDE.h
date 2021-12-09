typedef struct node no;

struct node{
    int dado;
    int chave;
    no * prox;
    no * ant;
};


no * cria_no();
no * insere_inicio(no *l);
no * insere_ordenado(no *l);
no * insere_fim(no *l);
no * busca(no *l, int c);
no * atualiza(no *l, int c, int novodado);
no * remove_no(no *l, int c);

