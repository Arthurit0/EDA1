#include <stdio.h>
#include <stdlib.h>

void preenche (int *vet, int tam);
void imprime (int *vet, int tam);

int main(){
    int tam, *vet, i;

    printf("Digite o tamanho do vetor: \n");
    scanf("%d", &tam);

    vet = (int *)malloc(tam*sizeof(int));
    preenche(vet,tam);
    imprime(vet,tam);

}

void preenche (int *vet, int tam){
    int i;

    //Utilizando aritmética de ponteiros para preencher
    for (i=0; i<tam; i++){
        if (i%2 == 0) *(vet+i) = 0;
        else *(vet+i) = 1;
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