#include <stdio.h>

int main(){
    float M[12][12], X, Opr=0;
    int i,j, cont=0;
    char O;

    scanf ("%c", &O);
    for (i=0; i<12; i++){
        for (j=0; j<12; j++){
            scanf("%f", &X);
            M[i][j] = X;
        }
    }

    if (O == 'S'){
    
    for (i=0; i<12; i++){
        for (j=0; j<12; j++){
            if (j>i){
                Opr += M[i][j];
            }
        }
    }

    }else if (O == 'M'){

    for (i=0; i<12; i++){
        for (j=0; j<12; j++){
            if (j>i){
                Opr += M[i][j];
                cont++;
            }
        }
    }

    Opr = (Opr/cont);
    }

    printf("%.1f\n", Opr);

    return 0;

}