#include <stdio.h>

struct hm {
    int horas;
    int minutos;
};

struct hm converteHoras (int m, struct hm hs){
    hs.horas = m/60;
    hs.minutos = m%60;

    return(struct hm hs.horas);
}

int main (){
    struct hm hs;
    int m;

    scanf ("%d", &m);

    struct hm hs = converteHoras(m, hs);

    printf("%d horas e %d minutos\n", hs.horas, hs.minutos);

}



