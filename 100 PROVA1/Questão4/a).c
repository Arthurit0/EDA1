typedef struct notas n;

struct notas{
    int matrícula;
    char nome[80];
    float notas;
    n* ant;
    n* prox;
};