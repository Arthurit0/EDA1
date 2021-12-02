#include <stdio.h>
#include <stdlib.h>
#include "Pilhas.h"

int main(){
    plh *pilha;
    int status = 1, verif_prnts=0;
    char prnts, imprime_prnts;

    pilha = cria_pilha();

    printf("Digite '(' ou ')', ou qualquer outra coisa para parar e verificar os parenteses: ");

    do{
        scanf("%s", &prnts);

        if(prnts == '(' || prnts == ')'){
            push(pilha, prnts);
        }

    } while (prnts == '(' || prnts == ')');

    do
    {
        imprime_prnts = pop(pilha, &status);

        switch (imprime_prnts)
        {
            case ')':
                verif_prnts++;
                break;
            
            case '(':
                if(verif_prnts>0){
                    verif_prnts--;
                }else{
                    verif_prnts--;
                    status = 0;
                }

                break;

            default:
                break;
        }
        
    } while (status != 0);
    
    if(verif_prnts == 0){
        printf("\nCorreto!\n");
    }else{
        printf("\nIncorreto!\n");
    }

    printf("\n");
    system("pause");

}