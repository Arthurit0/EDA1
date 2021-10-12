#include <stdio.h>

void magicFunction(int *a, int *b);

int main(){
    int a,b;
    a=5; b=1;
    magicFunction(&a,&b);
    printf("Valor de a: %d, valor de b: %d\n", a,b);
    return 0;
}

void magicFunction (int *a, int *b){
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}