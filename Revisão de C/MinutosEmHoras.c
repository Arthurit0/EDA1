#include <stdio.h>

struct hm{
    int horas;
    int minutos;
};

int main(){
    int m;
    struct hm minParaHoras;

    printf("Digite o tempo em minutos\n");
    scanf("%d",&m);

    minParaHoras.horas = m/60;
    minParaHoras.minutos = m%60;

    printf("Sao %d horas e %d minutos", minParaHoras.horas, minParaHoras.minutos);

    return 0;
}