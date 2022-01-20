typedef struct nodo nodo;

struct nodo{
    int chave;
    nodo *esq;
    nodo *dir;
};

typedef nodo *arvore;


//novo é um ponteiro para um nó já alocado
nodo * cria_no(int chave);
arvore insere(arvore a, nodo *novo);
nodo * busca(arvore a, int chave);