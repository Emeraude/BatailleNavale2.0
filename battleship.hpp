#ifndef BATTLESHIP_HPP_
# define BATTLESHIP_HPP_

# define HAUTEUR         15
# define LARGEUR         20

# define PROBA_TSUNAMI   36
# define DEGATS_TSUNAMI  1

# define PETROLE_MIN     15
# define PETROLE_MAX     20

# define NOMBRE_JOUEUR   2

enum Case {PORT, OIL, PLATFORM, BOAT, EMPTY, DESTROYED};
enum Direction {HORIZONTAL, VERTICAL};
enum Type {AI, HUMAN};

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

int		distance(int x_a, int y_a, int x_b, int y_b);
int		coutPetrole(Port port, int x, int y);
Position	trouverPetroleLePlusProche(Case map[][LARGEUR], int x, int y);
void		jeu();

#endif
