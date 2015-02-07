#ifndef BATTLESHIP_HPP_
# define BATTLESHIP_HPP_

# include "harbor.hpp"

enum Case {PORT, OIL, PLATFORM, BOAT, EMPTY, DESTROYED, BORDER};
enum Direction {HORIZONTAL, VERTICAL};
enum Type {AI, HUMAN};

typedef struct Position Position;
struct Position
{
    int x;
    int y;
};

int		distance(int x_a, int y_a, int x_b, int y_b);
int		coutPetrole(Harbor harbor, int x, int y);
Position	trouverPetroleLePlusProche(Case **map, int x, int y);

#endif
