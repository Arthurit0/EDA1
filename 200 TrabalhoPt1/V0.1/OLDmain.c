#include <stdio.h>
#include <stdlib.h>
#include "tasks.c"

int main(){
    tk *l = NULL;
    int op = 0;
    //Para atribuir em reg:
    char n[80]; int prior;
    //Para atribuir em tempo:
    int d, m, a, h, min;
    //Para atribuir em duração:
    int DurH, DurM;
    //Para associar na Task:
    data reg; temp tempo; dur duracao;

    do{
        mostra_Menu();
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            system("cls");
            printf("Digite o nome da tarefa: ");
            scanf("%s", &n);
            printf("Digite a prioridade da tarefa: ");
            scanf("%d", &prior);
            printf("Digite o dia de inicio da tarefa: ");
            scanf("%d", &d);
            printf("Digite o mes de inicio da tarefa: ");
            scanf("%d", &m);
            printf("Digite o ano de inicio da tarefa: ");
            scanf("%d", &a);
            printf("Digite a hora de inicio da tarefa: ");
            scanf("%d", &h);
            printf("Digite o minuto de inicio da tarefa: ");
            scanf("%d", &min);
            printf("Digite a quantidade de horas, e depois de minutos, da duracao da tarefa:");
            printf("\nHoras: ");
            scanf("%d", &DurH);
            printf("\nMinutos: ");
            scanf("%d", &DurM);
            
            tempo = cria_Temp(d, m, a, h, m);
            duracao = cria_Durac(DurH, DurM);
            reg = cria_Reg(n, prior, duracao, tempo);
            l = add_Task(l, reg);

            break;

            case 2:
                mostra_Tarefas(l);
                system("pause");
                break;
        
        default:
            break;
        }
    }while(op != 0);

    return 0;
}