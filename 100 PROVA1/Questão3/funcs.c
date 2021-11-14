#include "TAD.h"
#include <stdio.h>
#include <math.h>

void mostrar(poli* x){
    poli *p;

    if (x == NULL) return x;
    p = x;

    while(p != NULL){
        if(p->prox != NULL){
            printf("%fx^%d + ", p->coef, p->potencia);
        }else{
            printf("%fx^%d", p->coef, p->potencia);
        }
        p = p->prox;
    }  
}

float calcular(poli* p, float x){
    poli *pont;
    float result = 0, C=0; 
    int POT=0;

    if(p == NULL) return 0;

    pont = p;

    while(pont != NULL){
        C = pont->coef;
        POT = pont->potencia;

        result += pow((C*x), POT);
        pont = pont->prox;
    }

    return result;
}