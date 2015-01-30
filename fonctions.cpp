#include <iostream>
#include <vector>
#include <cmath>

#include "battleship.hpp"
#include "joueur.hpp"

int distance(int x_a, int y_a, int x_b, int y_b)
{
    return fabs(y_a-y_b)+fabs(x_a-x_b)-1;
}

int coutPetrole(Port port, int x, int y)
{
    return ceil(distance(port.pos.x,port.pos.y,x,y)/3);
}

Position trouverPetroleLePlusProche(Case map[][LARGEUR], int x, int y)
{
    int i,j,c(0),m,n;
    Position z;
    for(i=0;i<HAUTEUR;i++)
    {
        for(j=0;j<LARGEUR;j++)
        {
            if(map[i][j]==PETROLE&&distance(i,j,x,y)<distance(m,n,x,y))
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

Position trouverPetrole(Case map[][LARGEUR], int x, int y)
{
    return trouverPetroleLePlusProche(map, x, y);
}
