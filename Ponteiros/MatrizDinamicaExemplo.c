#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preenchematriz(int **mat, int lin, int col);
void imprimematriz(int **mat, int lin, int col);

int main(){
    int lin, col, i;
    printf ("Digite o numero de linhas da matriz:\n");
    scanf("%d", &lin);
    int **mat = (int **)malloc(lin*sizeof(int *));

    printf("Digite o numero de colunas da matriz:\n");
    scanf ("%d", &col);

    for (i=0; i<lin; i++){
        mat[i] = (int *)malloc(col*sizeof(int));
    }

    preenchematriz(mat, lin, col);
    imprimematriz(mat, lin, col);

    return 0;
}

void preenchematriz(int **mat, int lin, int col){
    int i, j;
    time_t t;
    srand((unsigned) time(&t));

    for (i=0; i<lin; i++){
        for (j=0; j<col; j++){
            mat[i][j] = rand()%10;
        }
    }
}

void imprimematriz(int **mat, int lin, int col){
    int i, j;

    for (i=-3; i<(2*lin); i++){
        printf("-");
    }

    printf("\n");

    for (i=0; i<lin; i++){
        printf("| ");
        for (j=0; j<col; j++){
            printf("%d ", mat[i][j]);
        }
        printf("|\n");
    }

    for (i=-3; i<(2*lin); i++){
        printf("-");
    }

    printf("\n");

}