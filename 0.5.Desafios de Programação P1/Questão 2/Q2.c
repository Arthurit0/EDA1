#include <stdio.h>
#include <stdlib.h>

typedef struct sobrenome sn;

struct sobrenome{
    char letra;
    char v_ou_c;
    sn * prox;
};

sn * adicionaLetra(sn *n, char l);
char verifica_V_ou_C(char l);

int main(){
    sn *nome, *p;
    char letraAtual;
    int hardNome=0;

    nome = (sn *)malloc(sizeof(sn));
    nome->letra = '_';

    printf("Digite o nome, letra por vez. Pare com 0:\n");
    do{
        scanf("%s", &letraAtual);
        if(letraAtual == '0'){ 
            break;
        }
        nome = adicionaLetra(nome, letraAtual);

    }while(letraAtual != '0');

    p = nome;

    while(p->prox != NULL){
        if((p->v_ou_c == 'v' && p->prox->v_ou_c == 'v')||(p->v_ou_c == 'c' && p->prox->v_ou_c == 'c')){
            hardNome++;
        }

        p = p->prox;
    }

    if(hardNome <= 0){
        printf("Nome Facil!");
    }else{
        printf("Nome Dificil");
    }

    return 0;
}

sn * adicionaLetra(sn *n, char l){
    sn *p=n, *novo;
    
    if(p->letra == '_'){
        p->letra = l;
        p->v_ou_c = verifica_V_ou_C(l);
        p->prox = NULL;

        return n;
    }
   

    novo = (sn *)malloc(sizeof(sn));
    novo->letra = l;
    novo->v_ou_c = verifica_V_ou_C(l);
    novo->prox = NULL;
    
    while (p->prox != NULL){
        p=p->prox;
    }

    p->prox = novo;

    return n;
}

char verifica_V_ou_C(char l){
        if((l == 'a')||(l == 'e')||(l == 'i')||(l == 'o')||(l == 'u')){
            return 'v';
        }
        else{
            return 'c';
        }
}