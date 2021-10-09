#include <stdio.h>

int main(){
    double X, N[100];
    int i;

    scanf("%lf", &X);
    N[0] = X;
    printf ("N[0] = %.4lf\n", X);

    for (i=1;i<100;i++){
        N[i]=((N[i-1])/2);
        printf("N[%d] = %.4lf\n", i, N[i]);
    }

    return 0;
}