#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preenche (int *vet, int tam);
void preenche2 (int *vet, int tam);
void mm(int vet[], int tam, int *min, int *max);
void imprime (int *vet, int tam);

int main(){
    int i, tam, min, max, *vet;

    printf("Digite o tamanho do vetor: \n");
    scanf("%d", &tam);

    vet = (int *)malloc(tam*sizeof(int));

    preenche2(vet, tam);
    mm(vet, tam, &min, &max);
    imprime(vet, tam);
    printf("\n\nMin: %d\nMax: %d\n", min, max);

    return 0;
}

void preenche (int *vet, int tam){
    int i;

    //Utilizando aritmética de ponteiros para preencher
    for (i=0; i<tam; i++){
        *(vet + i) = i;
    }
}

void mm(int vet[], int tam, int *min, int *max){
    int i;

    for (i=0; i<tam; i++){
        if (i == 0) *min = *max = vet[i];
        if (vet[i] < *min) *min = vet[i];
        if (vet[i] > *max) *max = vet[i];
        
    }

}

void preenche2 (int *vet, int tam){
    int i;
    time_t t;
    srand((unsigned) time(&t));

    for (i=0; i<tam; i++){
        vet[i] = rand()%100;
    }
}

void imprime (int *vet, int tam){
    int i;

    printf("Vetor: [ ");
    for (i=0; i<tam; i++){
        printf("%d ", vet[i]);
    }
    printf("]");
}