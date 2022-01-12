#include <stdio.h>
#include <stdlib.h>

typedef struct floatV2 f2;

struct floatV2{
    char num;
    f2 * prox;
};

int main(){
    f2 *n1, *n2, *p;

    n1 = (f2 *)malloc(sizeof(f2));
    n2 = (f2 *)malloc(sizeof(f2));

    char numero1[50], numero2[50];
    int cont=0;

    printf("Digite o primeiro numero: ");
    scanf("%s", &numero1);

    alocarNumeros(n1, numero1);

}

f2 