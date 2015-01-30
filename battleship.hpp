#ifndef BATTLESHIP_HPP_
# define BATTLESHIP_HPP_

# include <vector>

#define HAUTEUR         15
#define LARGEUR         20

#define PROBA_TSUNAMI   36
#define DEGATS_TSUNAMI  1

#define PETROLE_MIN     15
#define PETROLE_MAX     20

#define NOMBRE_JOUEUR   2

enum Cases {PORT, PETROLE, PLATEFORME, BATEAU, CASE_LIBRE, CASE_DETRUITE};
enum Directions {HAUT, BAS, DROITE, GAUCHE};

#define IA              301
#define HUMAIN          302

#define PERSONNE        401

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

class Joueur;
class Boat;

int		distance(int x_a, int y_a, int x_b, int y_b); // retourne la distance entre les points de coordonnées x_a|y_a et x_b|y_b
int		coutPetrole(Port port, int x, int y); // retourne le coût en pétrole d'une case de coordonnées x|y en fonction de sa distance avec le port
Position	trouverPetroleLePlusProche(Case map[][LARGEUR], int x, int y); // retourne la case de petrole la plus proche de la case de coordonnées x|y
Position	trouverPetrole(Case map[][LARGEUR], int x, int y); // alias de trouverPetroleLePlusProche
void		jeu();

#endif
