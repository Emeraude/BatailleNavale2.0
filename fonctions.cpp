#include <iostream>
#include <vector>
#include <cmath>

#include "battleship.hpp"

int distance(int x_a, int y_a, int x_b, int y_b) {
    return fabs(y_a-y_b)+fabs(x_a-x_b)-1;
}

int coutPetrole(Harbor harbor, int x, int y) {
  return ceil(distance(harbor.getX(), harbor.getY(), x, y) / 3);
}

Position trouverPetroleLePlusProche(Case **map, int x, int y)
{
    int i,j,c(0),m,n;
    Position z;
    for(i=0;map[i];i++)
    {
        for(j=0;map[i][j] != BORDER;j++)
        {
            if(map[i][j]==OIL&&distance(i,j,x,y)<distance(m,n,x,y))
            {
                if(c==0)
                {
                    m=i;
                    n=j;
                }
                m=i;
                n=j;
                c++;
            }
        }
    }
    z.x=m;
    z.y=n;
    return z;
}
