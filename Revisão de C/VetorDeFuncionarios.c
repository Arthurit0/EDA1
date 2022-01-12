#include <stdio.h>

int N=3;

struct fnc{
    int codigo;
    char nome[20];
    float salario;
};

void maior(struct fnc vetor[N]);
void menor(struct fnc vetor[N]);
void imprimir(struct fnc func);
void media(struct fnc vetor[N]);
void imprimirDados(struct fnc vetor[N]);



int main(){
   struct fnc funcionarios[N];
    int i, op;
    
    for (i=0; i<N;i++){
        printf("Digite o codigo do funcionario da pos[%d]:\n", i);
        scanf("%d", &funcionarios[i].codigo);
        printf("Digite o nome do funcionario da pos[%d]:\n",i);
        scanf("%s", &funcionarios[i].nome);
        printf("Digite o salario do(a) %s:\n", funcionarios[i].nome);
        scanf("%f", &funcionarios[i].salario);
    }

    do{
    printf("\n\n================================================\n");
    printf("Selecione uma opcao:\n");
    printf("1 - Funcionario de Maior Salario\n");
    printf("2 - Funcionario de Menor Salario\n");
    printf("3 - Imprimir os dados de um funcionario\n");
    printf("4 - Media dos salarios dos funcionarios\n");
    printf("5 - Imprimir os dados de todos os funcionarios\n");
    printf("0 - Sair do programa\n");


    int op2;
    scanf("%d",&op);
    switch (op)
    {
    case 1:
        maior(funcionarios);
        break;
    
    case 2:
        menor(funcionarios);
        break;

    case 3:
        printf("Deseja imprimir o funcionario de qual posicao? (posicao 0 a %d)\n", N-1);
        scanf("%d", &op2);

        if ((op2>=0)&&(op2<(N-1))){
        imprimir(funcionarios[op2]);
        }else{
            printf("\nOpcao invalida, tente novamente!\n");
        }
        break;

    case 4:
        media(funcionarios);
        break;

    case 5:
        imprimirDados(funcionarios);
        break;

    case 0:
        return 0;

    default:
        printf("\nOpcao nao encontrada, tente novamente!\n");
        break;
    }

    printf("\n");
    system("pause");

    }while(op != 0);

    return 0;
}

void maior(struct fnc vetor[N]){
    int maior = vetor[0].salario, posmaior=0, i;

    for (i=1; i<N; i++){
        if(vetor[i].salario > maior){
            maior = vetor[i].salario;
            posmaior = i;
        }
    }

    printf("\nO funcionario que possui maior salario: R$ %.2f eh o da posicao [%d]: %s\n", vetor[posmaior].salario, posmaior, vetor[posmaior].nome);

}

void menor(struct fnc vetor[N]){
    int menor = vetor[0].salario, posmenor=0, i;

        for (i=1; i<N; i++){
        if(vetor[i].salario <= menor){
            menor = vetor[i].salario;
            posmenor = i;
        }
    }

    printf("\nO funcionario que possui menor salario: R$ %.2f eh o da posicao [%d]: %s\n", vetor[posmenor].salario, posmenor, vetor[posmenor].nome);

}

void imprimir(struct fnc func){
    printf("\nCodigo: %d\nNome: %s\nSalario: R$ %.2f\n", func.codigo, func.nome, func.salario);

}

void media(struct fnc vetor[N]){
    float salarioTotal=0, media;
    int i;
    for (i=0; i<N; i++){
        salarioTotal += vetor[i].salario;
    }
    media = (salarioTotal/N);

    printf ("\nA media dos salarios de todos os funcionarios eh R$ %.2f\n", media);
}

void imprimirDados(struct fnc vetor[N]){
    int i;
    printf("-----------------------------------------------------------");
    for (i=0; i<N; i++){
        printf("\nCodigo: %d\nNome: %s\nSalario: R$%.2f\n", vetor[i].codigo, vetor[i].nome, vetor[i].salario);
        printf("-----------------------------------------------------------");
    }
    printf("\n");

}