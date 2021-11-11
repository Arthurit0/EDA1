#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct fibonacci fib;

struct fibonacci{
    int num;
    fib * prox;
};

void calculaFibonacci(int N);
int verificaPrimo(int num);

int main(){
    int N;
    scanf("%d", &N);
    calculaFibonacci(N);

    return 0;
}

void calculaFibonacci(int N){
    fib *init, *p, *del;
    int t1, t2, proxterm, i, cont=0;

    init = (fib *)malloc(sizeof(fib));
    p = init;

    t1 = 0;
    t2 = 1;
    proxterm = 0;
    
    while(cont<N){
        t1 = t2;
        t2 = proxterm;
        proxterm = t1 + t2;

        if(verificaPrimo(proxterm) == 0){
            p->prox = (fib *)malloc(sizeof(fib));
            p->num = proxterm;
            p = p->prox;
            cont++;
        }
    }

    p->prox = NULL;
    p = init;
    
    while(p->prox != NULL){
        printf("%d ", p->num);
        del = p;
        p = p->prox;
        free(del);
    }
    free(p);
}

int verificaPrimo(int num){
    int i, cont=0;

    if((num == 1)||(num == 2)){
        return 0;
    }else if((num % 2) == 0){
        return 1;
    }
    else{
        for(i = 3; i < (sqrt(num)); i = i+2){
            if((num % i) == 0){
                cont++;
            }
        }
        return cont;
    }
}