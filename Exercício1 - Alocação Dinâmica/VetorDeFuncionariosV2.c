#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>

struct fnc{
    int codigo;
    char nome[80];
    float salario;
};

void mostraMenu();
struct fnc registraFunc (int i);
void imprimirFunc (struct fnc *vet, int tam);
void encontraFunc (struct fnc *vet, int op2, int tam);
void maior(struct fnc *vet, int tam);
void menor(struct fnc *vet, int tam);
void media(struct fnc *vet, int tam);
struct fnc * incluirFunc (struct fnc *vet, int *tam);
struct fnc * removeFunc (struct fnc * vet, int *tam);

int main(){
   setlocale(LC_ALL, "");

   struct fnc *vet=NULL;
    int i, op;

    do{
    mostraMenu();

    int op2, tam, tempCod;
    char tempString[80];
    float tempFloat;
    int novotam;

    scanf("%d",&op);
    if ((vet==NULL)&&(op>1)){
        system("cls");
        printf("\nNenhum vetor cadastrado!\n");
        system("pause");
        continue;
    }
    switch (op)
    {
    case 1:
        system("cls");
        vet = NULL;
        printf("Qual o tamanho do vetor?\n");
        scanf("%d", &tam);
        vet = malloc(tam*sizeof(struct fnc));
        
        for (i=0; i<tam;i++){
            vet[i] = registraFunc(i);
    }

        printf("\nFuncionarios cadastrados com sucesso!\n");
        break;
    
    case 2:
        system("cls");
        imprimirFunc(vet, tam);
        break;

    case 3:
        system("cls");
        printf("Deseja encontrar o funcionario de qual posicao? (0 ate %d)\n", (tam-1));
        scanf("%d", &op2);
        encontraFunc(vet, op2, tam);
        break;

    case 4:
        system("cls");
        maior(vet, tam);
        break;

    case 5:
        system("cls");
        menor(vet, tam);
        break;

    case 6:
        system("cls");
        media(vet, tam);
        break;

    case 7:
        system("cls");
        vet = incluirFunc(vet, &tam);
        break;

    case 8:
        system("cls");
        vet = removeFunc(vet, &tam);
        break;

    case 0:
        return 0;

    default:
        printf("\nOpcao nao encontrada, tente novamente!\n");
        break;
    }

    printf("\n");
    system("pause");
    system("cls");

    }while(op != 0);

    return 0;
}

void mostraMenu(){
printf("\n\n================================================\n");
    printf("|      CADASTRO DE FUNCIONARIOS      |\n");
    printf("|____________________________________|\n");
    printf("|           MENU DE OPCOES           |\n");
    printf("|------------------------------------|\n");
    printf("| 1 - INSERIR N VALORES NO VETOR     |\n");
    printf("| 2 - IMPRIMIR TODOS OS FUNCIONaRIOS |\n");
    printf("| 3 - IMPRIMIR FUNCIONaRIO DA POSICAO|\n");
    printf("| 4 - RETORNAR POS. DO MAIOR SALaRIO |\n");
    printf("| 5 - RETORNAR POS. DO MENOR SALaRIO |\n");
    printf("| 6 - RETORNAR A MEDIA DOS SALARIOS  |\n");
    printf("| 7 - INCLUIR FUNCIONARIO            |\n");
    printf("| 8 - REMOVER UM FUNCIONARIO         |\n");
    printf("| 0 - SAIR                           |\n");
    printf("|------------------------------------|\n");
    printf("\n");
    printf("Selecione uma opcao: ");
}

struct fnc registraFunc (int i){
    struct fnc vet;

    int tempCod;
    char tempString[80];
    float tempFloat;

    printf("Digite o codigo do funcionario da pos[%d]:\n", i);
    scanf("%d", &tempCod);
    vet.codigo = tempCod;
    printf("Digite o nome do funcionario da pos[%d]:\n",i);
    scanf("%s", &tempString);
    strncpy(vet.nome, tempString, 80);
    printf("Digite o salario do(a) %s:\n", vet.nome);
    scanf("%f", &tempFloat);
    vet.salario = tempFloat;  

    return vet;
}

void imprimirFunc (struct fnc *vet, int tam){
    int i;
    
    for (i=0; i<tam; i++){
        printf("------------------------------------|");
        printf("\n Codigo: %d\n Nome: %s\n Salario: R$ %.2f\n", vet[i].codigo, vet[i].nome, vet[i].salario);
    }
    printf("------------------------------------|");
}

void encontraFunc (struct fnc *vet, int op2, int tam){
    int i;
    bool encontrado = false;
    for (i=0; i<tam; i++){
        if (i==op2){
            printf("\nCodigo: %d\nNome: %s\nSalario: R$ %.2f\n", vet[i].codigo, vet[i].nome, vet[i].salario);
            encontrado = true;
        }
    }

    if (encontrado == false){
        printf("\nPosicao invalida, tente novamente!\n");
    }
}
void maior(struct fnc *vet, int tam){
     int maior = vet[0].salario, posmaior=0, i;

    for (i=1; i<tam; i++){
        if(vet[i].salario > maior){
            maior = vet[i].salario;
            posmaior = i;
        }
    }

    printf("\nO funcionario que possui maior salario de R$ %.2f e o da posicao [%d]: %s\n", vet[posmaior].salario, posmaior, vet[posmaior].nome);
}

void menor(struct fnc *vet, int tam){
    int menor = vet[0].salario, posmenor=0, i;

        for (i=1; i<tam; i++){
        if(vet[i].salario <= menor){
            menor = vet[i].salario;
            posmenor = i;
        }
    }

    printf("\nO funcionario que possui menor salario de R$ %.2f e o da posicao [%d]: %s\n", vet[posmenor].salario, posmenor, vet[posmenor].nome);
}

void media(struct fnc *vet, int tam){
    float salarioTotal=0, media;
    int i;

    for (i=0; i<tam; i++){
        salarioTotal += vet[i].salario;
    }

    media = (salarioTotal/tam);

    printf ("\nA media dos salarios de todos os funcionarios e R$ %.2f\n", media);
}

struct fnc * incluirFunc (struct fnc *vet, int *tam){
    struct fnc novoFunc;
    struct fnc *temp = realloc(vet, (*tam+1)*sizeof(struct fnc));
    
    novoFunc = registraFunc((*tam+1));

    if (temp == NULL){
        return vet;
    }else{
        vet = temp;
    }

    vet[*tam].codigo = novoFunc.codigo;
    strncpy(vet[*tam].nome, novoFunc.nome, 80);
    vet[*tam].salario = novoFunc.salario;

    *tam = *tam+1;
    printf("\nNovo funcionario cadastrado com sucesso!\n");

    return vet;
}

struct fnc * removeFunc (struct fnc * vet, int *tam){
    int i, op;
    struct fnc *temp;

    printf("Deseja remover o funcionario de qual posicao? (0 ate %d)\n", (*tam-1));
    scanf("%d",&op);

    if((op>=0)&&(op<(*tam))){
    for(i=op; i<*tam; i++){
        vet[i].codigo = vet[i+1].codigo;
        strncpy(vet[i].nome, vet[i+1].nome, 80);
        vet[i].salario = vet[i+1].salario;
    }

    temp = realloc(vet, (*tam-1)*sizeof(struct fnc));
    
    if (temp == NULL){
        return vet;
    }else{
        vet = temp;
        printf("\nFuncionario da posicao %d removido!\n", op);
    }

    *tam = *tam-1;

    return vet;
    }else{
        printf("\nPosicao invalida, tente novamente!\n");
        return vet;
    }
}