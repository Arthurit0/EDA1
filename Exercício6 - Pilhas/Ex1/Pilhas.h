typedef struct Pilha plh;
typedef struct Parenteses no;

struct Parenteses{
    char dado;
    no * prox;
};

struct Pilha{
    no * topo;
};

plh * cria_pilha();
void push(plh * p, char parent);
char pop(plh *p, int *status);