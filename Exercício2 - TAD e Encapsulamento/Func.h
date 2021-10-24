struct funcionario{
    int codigo;
    char nome[80];
    float salario;
};

typedef struct funcionario fnc;

void mostraMenu();
fnc * alocaVetor (int tam);


void inserirNoVetor (fnc *vet, int tam);
void imprimirFunc (fnc *vet, int tam);
void encontraFunc (fnc *vet, int pos);
int maior(fnc *vet, int tam);
int menor(fnc *vet, int tam);
float media(fnc *vet, int tam);
fnc * incluirFunc (fnc *vet, int tam);
fnc * removeFunc (fnc * vet, int tam);