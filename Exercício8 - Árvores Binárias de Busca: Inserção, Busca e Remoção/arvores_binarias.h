typedef struct reg nodo;

struct reg{
    int chave;
    int conteudo;
    nodo *esq;
    nodo *dir;
};

typedef nodo *arvore;

arvore insere(arvore r, nodo *novo);    // "novo" é um ponteiro para um nó já alocado
nodo * busca(arvore r, int k);
nodo * cria_nodo(int chave, int conteudo);
nodo *busca_remove(arvore r, int chave);
nodo *remove_nodo(nodo *q);