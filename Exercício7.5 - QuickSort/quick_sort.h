typedef struct lista no;

struct lista{
    int dado;
    no * prox;
};
no * cria_no(int d);
no * adiciona_final(no * l, int num);
no * quick_sort(no * l);
no * particao(no *l);
no * concatena(no * l, no * pivo);
void imprime_lista(no *l);