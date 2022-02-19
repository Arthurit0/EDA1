typedef struct nos nodo;

struct nos{
    int chave;
    nodo *esq;
    nodo *dir;
};

typedef nodo * arvore;

nodo * profundidade(arvore r){
    nodo *alvo;
    int mais_alt = 0;

    buscar(r, alvo, 0, mais_alt);
    return alvo
}

void buscar(nodo *r, nodo *alvo, int alt, int mais_alt){
    if(r != NULL) {
        alt++; //Desceu um nivel
        buscar(r->esq, alvo, alt, mais_alt); //Desce na esquerda
        
        if(alt > mais_alt){ //Chegou num lugar mais profundo? Na primeira vez sempre será verdade
            alvo = r;       //pois mais_alt começa em 0
            mais_alt = alt;
        }
        buscar(r->dir, alvo, alt, mais_alt); //Desce na direita
    }
}