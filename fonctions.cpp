#include <iostream>
#include <vector>
#include <cmath>

#include "constantes.hpp"
#include "structures.hpp"
#include "fonctions.hpp"
#include "joueur.hpp"

using namespace std;

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
            if(map[i][j].type==PETROLE&&distance(i,j,x,y)<distance(m,n,x,y))
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
bool listeCases(Case map[][LARGEUR], std::vector<Position> a, Bateau bateau)
{
    int i;

    if(bateauExiste(bateau))
    {
        for(i=0;i<bateau.taille;i++)
        {
            a.push_back(Position());
            if(bateau.direction==HAUT)
            {
                a.back().x=bateau.pos.x-i;
                a.back().y=bateau.pos.y;
            }
            if(bateau.direction==BAS)
            {
                a.back().x=bateau.pos.x+i;
                a.back().y=bateau.pos.y;
            }
            if(bateau.direction==GAUCHE)
            {
                a.back().x=bateau.pos.x;
                a.back().y=bateau.pos.y-i;
            }
            if(bateau.direction==DROITE)
            {
                a.back().x=bateau.pos.x;
                a.back().y=bateau.pos.y+i;
            }
        }
        return true;
    }
    else return false;
}
Bateau infoBateau(Case map[][LARGEUR], int x, int y, Joueur &joueur)
{
    unsigned int nb_bateaux,i,j;
    Bateau tmp_bateau;
    vector<Position> positions;

    nb_bateaux=joueur.getNombreBateaux();

    for(i=0;i!=nb_bateaux;i++)
    {
        if(bateauExiste(joueur.getBateau(i)))
        {
            tmp_bateau=joueur.getBateau(i);
            listeCases(map, positions, joueur.getBateau(i));
            for(j=0;j<positions.size();j++)
            {
                if(positions[j].x==x&&positions[j].y==y)
                {
                    return tmp_bateau;
                }
            }
        }
    }
}
bool bateauExiste(Bateau bateau)
{
    bool e=true;
    if(bateau.vie<=0)
    {
        e=false;
    }
    if(bateau.taille<bateau.vie||bateau.taille<0)
    {
        e=false;
    }
    if(bateau.pos.x>HAUTEUR||bateau.pos.x<0)
    {
        e=false;
    }
    if(bateau.pos.y>LARGEUR||bateau.pos.y<0)
    {
        e=false;
    }
    if(bateau.direction!=HAUT&&bateau.direction!=BAS&&bateau.direction!=GAUCHE&&bateau.direction!=DROITE)
    {
        e=false;
    }
    return e;
}
