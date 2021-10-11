#include <stdio.h>

struct fnc{
    int codigo;
    char nome[20];
    float salario;
};

void maior(int op, struct fnc vetor[6]);

void menor (int op, struct fnc vetor[6]);

int main(){
   struct fnc funcionarios[6];
    int i, op;
    
    for (i=0; i<6;i++){
        printf("Digite o codigo do funcionario da pos[%d]:\n", i);
        scanf("%d", &funcionarios[i].codigo);
        printf("Digite o nome do funcionario da pos[%d]:\n",i);
        scanf("%s", &funcionarios[i].nome);
        printf("Digite o salario do(a) %s:\n", funcionarios[i].nome);
        scanf("%f", &funcionarios[i].salario);
    }

    do{
    printf("================================================\n");
    printf("Selecione uma opcao:\n");
    printf("1 - Funcionario de Maior Salario\n");
    printf("2 - Funcionario de Menor Salario\n");
    printf("3 - Imprimir todos os funcionarios (e suas posicoes)\n");
    printf("4 - Media dos salarios dos funcionarios\n");
    printf("5 - Imprimir os dados de todos os funcionarios\n");

    scanf("%d",&op);
    
    }while(op != 0);

    return 0;
}

void maior(int op, struct fnc vetor[6]){

}

void menor (int op, struct fnc vetor[6]){

}