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

/** Créer une fonction qui renvoie un tableau contenant chaque case du bateau **/

Bateau infoBateau(Case map[][LARGEUR], int x, int y, Joueur &joueur)
{
    /***********************************/
    /**  /!\  FONCTION À FINIR   /!\  **/
    /**  /!\  FONCTION À FINIR   /!\  **/
    /**  /!\  FONCTION À FINIR   /!\  **/
    /**  /!\  FONCTION À FINIR   /!\  **/
    /**  /!\  FONCTION À FINIR   /!\  **/
    /**  /!\  FONCTION À FINIR   /!\  **/
    /**  /!\  FONCTION À FINIR   /!\  **/
    /***********************************/

    int nb_bateaux,i,j;
    Bateau tmp_bateau;
    vector<Position> positions;

    nb_bateaux=joueur.getNombreBateaux();

    for(i=0;i!=nb_bateaux;i++)
    {
        if(bateauExiste(joueur.getBateau(i)))
        {
            tmp_bateau=joueur.getBateau(i);
            positions.push_back(Position());
            for(j=0;j<tmp_bateau.taille;j++)
            {
                if(tmp_bateau.direction==HAUT)
                {
                    positions.back().x=tmp_bateau.pos.x-j;
                    positions.back().y=tmp_bateau.pos.y;
                }
                if(tmp_bateau.direction==BAS)
                {
                    positions.back().x=tmp_bateau.pos.x+j;
                    positions.back().y=tmp_bateau.pos.y;
                }
                if(tmp_bateau.direction==GAUCHE)
                {
                    positions.back().x=tmp_bateau.pos.x;
                    positions.back().y=tmp_bateau.pos.y-j;
                }
                if(tmp_bateau.direction==DROITE)
                {
                    positions.back().x=tmp_bateau.pos.x;
                    positions.back().y=tmp_bateau.pos.y+j;
                }
            }
        }
    }
    return tmp_bateau;
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
