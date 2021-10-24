#include "ponto.h"
#include <stdio.h>

int main()
{
    ponto *p1;
    float x, y;
    p1 = cria(0.5,1.4);
    acessa(p1, &x, &y);
    printf("P1: %.1f, %.1f", x, y);
    libera(p1);

    return 0;
}

//Quando compilar: gcc main.c ponto.c -o main
