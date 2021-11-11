struct pos{
    float x;
    float y;
}

struct player{
    char nome[80];
    float quantVida;
    struct pos;
};

typedef struct player rnr;

rnr criar_player(char[80] nome);
rnr alterar_HP (rnr player);
rnr alterar_pos (rnr player);