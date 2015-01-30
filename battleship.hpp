#ifndef BATTLESHIP_HPP_
# define BATTLESHIP_HPP_

enum Case {PORT, OIL, PLATFORM, BOAT, EMPTY, DESTROYED, BORDER};
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
Position	trouverPetroleLePlusProche(Case **map, int x, int y);
void		jeu();

#endif
