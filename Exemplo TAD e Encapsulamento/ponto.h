struct Ponto{
    float x;
    float y;
};

typedef struct Ponto ponto;

ponto * cria(float x, float y);
void libera(ponto *p);
void acessa(ponto *p, float *x, float *y);
void atribui(ponto * p, float x, float y);
float distancia(ponto *p1, ponto *p2);

