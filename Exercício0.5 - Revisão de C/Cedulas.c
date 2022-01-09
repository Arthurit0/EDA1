#include <stdio.h>

int main(int argc, char const *argv[])
{
    int N,V100,V50,V20,V10,V5,V2,V1;

    scanf ("%d", &N);

    printf ("%d\n", N);
    if(0<N<1000000){
    V100 = N/100;
    N = N%100;
    V50 = N/50;
    N = N%50;
    V20 = N/20;
    N = N%20;
    V10 = N/10;
    N = N%10;
    V5 = N/5;
    N = N%5;
    V2 = N/2;
    N = N%2;

    printf ("%d nota(s) de R$ 100,00\n", V100);
    printf ("%d nota(s) de R$ 50,00\n", V50);
    printf ("%d nota(s) de R$ 20,00\n", V20);
    printf ("%d nota(s) de R$ 10,00\n", V10);
    printf ("%d nota(s) de R$ 5,00\n", V5);
    printf ("%d nota(s) de R$ 2,00\n", V2);
    printf ("%d nota(s) de R$ 1,00\n", N);

    }

    return 0;
}

