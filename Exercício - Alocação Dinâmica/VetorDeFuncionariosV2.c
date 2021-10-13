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
struct fnc * incluirFunc (struct fnc *vet, int tam);
struct fnc * removeFunc (struct fnc * vet, int tam);

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

        printf("\nFuncionários cadastrados com sucesso!\n");
        break;
    
    case 2:
        system("cls");
        imprimirFunc(vet, tam);
        break;

    case 3:
        system("cls");
        printf("Deseja encontrar o funcionário de qual posição? (0 até %d)\n", (tam-1));
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
        tam++;
        vet = incluirFunc(vet, tam);
        break;

    case 8:
        system("cls");
        vet = removeFunc(vet, tam);
        tam--;
        break;

    case 0:
        return 0;

    default:
        printf("\nOpção não encontrada, tente novamente!\n");
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
    printf("|      CADASTRO DE FUNCIONÁRIOS      |\n");
    printf("|____________________________________|\n");
    printf("|           MENU DE OPÇÕES           |\n");
    printf("|------------------------------------|\n");
    printf("| 1 - INSERIR n VALORES NO VETOR     |\n");
    printf("| 2 - IMPRIMIR TODOS OS FUNCIONÁRIOS |\n");
    printf("| 3 - IMPRIMIR FUNCIONÁRIO DA POSIÇÃO|\n");
    printf("| 4 - RETORNAR POS. DO MAIOR SALÁRIO |\n");
    printf("| 5 - RETORNAR POS. DO MENOR SALÁRIO |\n");
    printf("| 6 - RETORNAR A MÉDIA DOS SALÁRIOS  |\n");
    printf("| 7 - INCLUIR FUNCIONÁRIO            |\n");
    printf("| 8 - REMOVER UM FUNCIONÁRIO         |\n");
    printf("| 0 - SAIR                           |\n");
    printf("|------------------------------------|\n");
    printf("\n");
    printf("Selecione uma opção: ");
}

struct fnc registraFunc (int i){
    struct fnc vet;

    int tempCod;
    char tempString[80];
    float tempFloat;

    printf("Digite o código do funcionário da pos[%d]:\n", i);
    scanf("%d", &tempCod);
    vet.codigo = tempCod;
    printf("Digite o nome do funcionário da pos[%d]:\n",i);
    scanf("%s", &tempString);
    strncpy(vet.nome, tempString, 80);
    printf("Digite o salário do(a) %s:\n", vet.nome);
    scanf("%f", &tempFloat);
    vet.salario = tempFloat;  

    return vet;
}

void imprimirFunc (struct fnc *vet, int tam){
    int i;
    
    for (i=0; i<tam; i++){
        printf("------------------------------------|");
        printf("\n Código: %d\n Nome: %s\n Salário: R$ %.2f\n", vet[i].codigo, vet[i].nome, vet[i].salario);
    }
    printf("------------------------------------|");
}

void encontraFunc (struct fnc *vet, int op2, int tam){
    int i;
    bool encontrado = false;
    for (i=0; i<tam; i++){
        if (i==op2){
            printf("\nCódigo: %d\nNome: %s\nSalário: R$ %.2f\n", vet[i].codigo, vet[i].nome, vet[i].salario);
            encontrado = true;
        }
    }

    if (encontrado == false){
        printf("\nPosição inválida, tente novamente!\n");
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

    printf("\nO funcionário que possui maior salário de R$ %.2f é o da posição [%d]: %s\n", vet[posmaior].salario, posmaior, vet[posmaior].nome);
}

void menor(struct fnc *vet, int tam){
    int menor = vet[0].salario, posmenor=0, i;

        for (i=1; i<tam; i++){
        if(vet[i].salario <= menor){
            menor = vet[i].salario;
            posmenor = i;
        }
    }

    printf("\nO funcionário que possui menor salário de R$ %.2f é o da posição [%d]: %s\n", vet[posmenor].salario, posmenor, vet[posmenor].nome);
}

void media(struct fnc *vet, int tam){
    float salarioTotal=0, media;
    int i;

    for (i=0; i<tam; i++){
        salarioTotal += vet[i].salario;
    }

    media = (salarioTotal/tam);

    printf ("\nA média dos salários de todos os funcionários é R$ %.2f\n", media);
}

struct fnc * incluirFunc (struct fnc *vet, int novotam){
    struct fnc novoFunc;
    struct fnc *temp = realloc(vet, novotam*sizeof(struct fnc));
    
    novoFunc = registraFunc(novotam);

    if (temp == NULL){
        return vet;
    }else{
        vet = temp;
    }

    vet[novotam-1].codigo = novoFunc.codigo;
    strncpy(vet[novotam-1].nome, novoFunc.nome, 80);
    vet[novotam-1].salario = novoFunc.salario;

    printf("\nNovo funcionário cadastrado com sucesso!\n");

    return vet;
}

struct fnc * removeFunc (struct fnc * vet, int tam){
    int i, op;
    struct fnc *temp;

    printf("Deseja remover o funcionário de qual posição? (0 até %d)\n", (tam-1));
    scanf("%d",&op);

    if((op>0)&&(op<(tam))){
    for(i=op; i<tam; i++){
        vet[i].codigo = vet[i+1].codigo;
        strncpy(vet[i].nome, vet[i+1].nome, 80);
        vet[i].salario = vet[i+1].salario;
    }

    temp = realloc(vet, (tam-1)*sizeof(struct fnc));
    
    if (temp == NULL){
        return vet;
    }else{
        vet = temp;
        printf("\nFuncionário da posição %d removido!\n", op);
    }

    return vet;
    }else{
        printf("\nPosição inválida, tente novamente!\n");
        return vet;
    }
}