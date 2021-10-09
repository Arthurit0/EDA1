#include <stdio.h>
#include <math.h>

int main(){
    int N, X, i, j, Primo;

    scanf ("%d", &N);

    for (i=0; i<N; i++){
        Primo = 0;
        scanf("%d", &X);

        if((X == 0) || (X==1)){
            printf("Not Prime");
        }
        else if (X == 2){
            printf ("Prime\n");
        }
        else if ((X%2) == 0){
            printf ("Not Prime\n"); 
        }else{
        for (j=3; j<(sqrt(X)+1); j=j+2){
            if ((X%j) == 0){
                printf ("Not Prime\n"); 
                Primo = 1;
                break;
            }
        }
            if(Primo == 0){
            printf ("Prime\n");
            }
        }

}
    return 0;
}