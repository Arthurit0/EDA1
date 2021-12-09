typedef struct lista no;

struct lista{
    int dado;
    no * prox;
};

no * cria_no(int d);
no * adiciona_final(no * l, int num);
no * mergeSort(no *l);
no * split(no *l);
no * merge(no *e, no *d);
void free_nos(no *l);