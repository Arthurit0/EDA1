#include <stdio.h>

int main(){
    int count=10;
    int *pt;
    pt=&count;
    printf("Este eh o endereco de Count: %i\n", &count);
    printf("Este eh o conteudo de Count: %i\n", count);
    printf("Este eh o endereco de Count por pt: %i\n", pt);
    printf("Este eh o conteudo de Count por pt: %i\n", *pt);
}