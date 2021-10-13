#include <stdio.h>

int main(){
    int a=5;
    float b=7;
    char c[6]="test";
    int *p = &a;
    printf ("Conteudo de a: %d\n", a);
    printf ("Endereco de a: %d\n", &a);
    printf ("Tamanho de a: %d\n", sizeof(a));
    printf ("Conteudo de b: %f\n", b);
    printf ("Endereco de b: %d\n", &b);
    printf ("Tamanho de b: %d\n", sizeof(b));
    printf ("Conteudo de c: %s\n", c);
    printf ("Endereco de c: %d\n", &c);
    printf ("Tamanho de c: %d\n", sizeof(c));
    printf ("Conteudo de p: %d\n", p);
    printf ("Endereco de p: %d\n", &p);
    printf ("Tamanho de p: %d\n", sizeof(p));
}