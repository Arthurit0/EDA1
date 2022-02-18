typedef struct no nodo;

struct no{
    int chave;
    nodo *esq;
    nodo *dir;
};

typedef nodo * arvore;


//novo é um ponteiro para um nó já alocado
nodo * cria_no(int chave);
arvore insere(arvore a, nodo * novo);
arvore remove_nodo(nodo * q);
int altura(arvore a);
int fator_balanceamento(arvore a);
arvore balanceamento(arvore a);
arvore rotDir(nodo *p);
arvore rotEsq(nodo * p);
arvore busca_r(arvore a, int k);
arvore busca_i(arvore a, int k); //Sem balanceamento
arvore busca_remove_r(arvore a, int k);
arvore busca_remove_i(arvore a, int k);