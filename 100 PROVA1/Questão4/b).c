#include "a).c"

float calcula_mediana(n* l){
    n *p; 
    int cont = 0, pos=1;

    l = ordenarlista(l); //Função hipotética que ordena a lista baseado nas notas;

    p = l;

    while(p != NULL){
        p = p->prox;
        cont++;
    }

    p = l;

    if((cont % 2) != 0) cont = cont+1;
    while(pos != (cont/2)){
            p = p->prox;
            pos++;
    }

}