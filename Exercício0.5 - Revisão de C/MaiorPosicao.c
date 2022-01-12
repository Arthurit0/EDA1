#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num[100], i, maior=0, posmaior=0;

    for (i=0; i<100; i++){
        scanf("%d", &num[i]);
        if (num[i]>maior){
            maior = num[i];
            posmaior = i+1;
        }
    }

    printf ("%d\n%d\n", maior, posmaior);

    return 0;
}
