#ifndef STRUCT
#define STRUCT

typedef struct Position Position;
struct Position
{
    int x;
    int y;
};

typedef struct Port Port;
struct Port
{
    Position pos;
    int vie;
};

typedef struct Bateau Bateau;
struct Bateau
{
    bool bonus_portee;
    bool bonus_puissance;
    int taille;
    Position pos;
    int direction;
    int vie;
};

typedef struct Plateforme Plateforme;
struct Plateforme
{
    Position pos;
};

typedef struct Case Case;
struct Case
{
    int type;
    int joueur;
};

#endif
