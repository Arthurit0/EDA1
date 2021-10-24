#include "ponto.h"
#include <stdlib.h>

ponto * cria(float x, float y){
    ponto *p = (ponto *)malloc(sizeof(ponto));
    p->x = x;
    p->y = y;
    return(p);
}

void acessa(ponto *p, float *x, float *y){
    *x = p->x;
    *y = p->y;
}

void libera(ponto *p){
    free(p);
}