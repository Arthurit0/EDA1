typedef struct polinomio poli;

struct polinomio{
    float coef; //Aqui fica o coeficiente, que pode ser um número real
    int potencia; //Quando for implementar o polinomio, peço o número n da maior potência, e vou decrescendo e atribuindo neste inteiro.
    p* prox;
}

void mostrar(poli* x);
float calcular(poli* p, float x);