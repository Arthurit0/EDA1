typedef struct veiculo car;
typedef struct saidaVagas est;

struct veiculo{
    char placa[7];
    car *frente;
};

struct saidaVagas{
    car *frente;
};

car * popUntilFind(est *estac, car *listaDeManobra, char placa[7], int *status){
    if(estac->frente == NULL){
        *status = 0;
        return NULL;
    }
    
    car *retirado;
    int isAlvo;

    while (estac->frente != NULL && isAlvo != 1){
        retirado = estac->frente;
        isAlvo = carroEhAlvo(retirado, placa);

        if(isAlvo == 0){
            if(listaDeManobra == NULL) listaDeManobra = retirado;
            else listaDeManobra->frente = retirado;
        }

        estac->frente = estac->frente->frente;
    }

    return retirado;
}

int carroEhAlvo(car *p, char placa[7]){
    int isAlvo = 1, i;

    for (int i = 0; i < 7; i++)
    {
        if(p->placa[i] != placa[i]){
            isAlvo = 0;
        }
    }
    
    return isAlvo;
}