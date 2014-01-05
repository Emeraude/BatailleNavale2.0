#include <iostream>
#include <cmath>
#include <vector>

#include "constantes.hpp"
#include "structures.hpp"
#include "fonctions.hpp"

#include "joueur.hpp"

using namespace std;

Joueur::Joueur(){}
Joueur::Joueur(Case map[][LARGEUR],int pos_port_x, int pos_port_y, int type, int numero_joueur)
{
    m_port.pos.x=pos_port_x;
    m_port.pos.y=pos_port_y;
    map[m_port.pos.x][m_port.pos.y].type=PORT;
    m_type=type;
    m_numero_joueur=numero_joueur;
    m_port.vie=20;
    m_argent=100000;
    m_petrole=5;
    m_nombre_plateformes=0;
    m_nombre_bateaux=0;
    m_score=0;
}
Joueur::Joueur(Case map[][LARGEUR],int pos_port_x, int pos_port_y, int type, int numero_joueur, int vie, int argent, int petrole)
{
    m_port.pos.x=pos_port_x;
    m_port.pos.y=pos_port_y;
    map[m_port.pos.x][m_port.pos.y].type=PORT;
    m_type=type;
    m_numero_joueur=numero_joueur;
    m_port.vie=vie;
    m_argent=argent;
    m_petrole=petrole;
    m_nombre_plateformes=0;
    m_nombre_bateaux=0;
    m_score=0;
}
Joueur::~Joueur()
{
    m_plateformes.~vector();
    m_bateaux.~vector();
}

/** ACCESSEURS **/

int Joueur::getArgent()
{
    return m_argent;
}
int Joueur::getPetrole()
{
    return m_petrole;
}
int Joueur::getVie()
{
    return m_port.vie;
}
Bateau Joueur::getBateau(int x)
{
    if(bateauExiste(m_bateaux[x])) return m_bateaux[x];
}
int Joueur::getNombreBateaux()
{
    return m_nombre_bateaux;
}

/** MÉTHODES **/

void Joueur::recupererPetrole(Case map[][LARGEUR],int quantite)
{
    int i,prix(0);
    Position position;

    if(quantite>m_nombre_plateformes+1) cout << "Vous n'avez pas suffisamment de plateformes petrolieres." << endl;
    else
    {
        position=trouverPetrole(map,m_port.pos.x,m_port.pos.y);
        prix+=500*distance(position.x,position.y,m_port.pos.x,m_port.pos.y);

        for(i=0;i<quantite;i++)
        {
            position=trouverPetrole(map,m_plateformes[i].pos.x,m_plateformes[i].pos.y);
            prix+=distance(position.x,position.y,m_plateformes[i].pos.x,m_plateformes[i].pos.y);
        }
        if(prix>=m_argent)
        {
            m_argent-=prix;
            m_petrole+=1+i;
        }
        else
        {
            cout << "Vous n'avez pas suffisamment d'argent" << endl;
        }
    }
}
void Joueur::vendrePetrole(int quantite)
{
    if(quantite>m_petrole)
    {
        cout << "Vous n'avez que " << m_petrole << " barils de pétrole et ne pouvez en vendre " << quantite << "." << endl;
    }
    else
    {
        m_petrole-=quantite;
        m_argent+=quantite*5000;
        cout << "Vous avez vendu " << quantite << " barils de pétrole pour la somme de " << quantite*5000 << " $." << endl << "Il vous reste " << m_petrole << " Barils." <<endl;
    }
}
void Joueur::acheterNavire(Case map[][LARGEUR], int taille, int pos_x, int pos_y, int direction)
{
    int i;
    bool e(false);

    if(map[pos_x][pos_y].type!=CASE_LIBRE)
    {
        cout << "La case aux coordonnées " << pos_x << "|" << pos_y << " n'est pas libre." << endl;
        e=true;
    }
    else
    {
        for(i=1;i<taille;i++)
        {
            if(direction==HAUT&&pos_x-i>=0)
            {
                if(map[pos_x-i][pos_y].type!=CASE_LIBRE)
                {
                    cout << "La case aux coordonnees " << pos_x-i << "|" << pos_y << " n'est pas libre." << endl;
                    e=true;
                }
            }
            else if(direction==BAS&&pos_x+i<HAUTEUR)
            {
                if(map[pos_x+i][pos_y].type!=CASE_LIBRE)
                {
                    cout << "La case aux coordonnees " << pos_x+i << "|" << pos_y << " n'est pas libre." << endl;
                    e=true;
                }
            }
            else if(direction==GAUCHE&&pos_y-i>=0)
            {
                if(map[pos_x][pos_y-i].type!=CASE_LIBRE)
                {
                    cout << "La case aux coordonnees " << pos_x << "|" << pos_y-1 << " n'est pas libre." << endl;
                    e=true;
                }
            }
            else if(direction==DROITE&&pos_y+i<LARGEUR)
            {
                if(map[pos_x][pos_y+i].type!=CASE_LIBRE)
                {
                    cout << "La case aux coordonnees " << pos_x << "|" << pos_y+i << " n'est pas libre." << endl;
                    e=true;
                }
            }
        }
        if(m_petrole<coutPetrole(m_port,pos_x,pos_y))
        {
            cout << "Vous n'avez pas assez de petrole pour placer un bateau ici." << endl;
            e=true;
        }
        if(e==false)
        {
            if(m_argent>=1000*pow(2,taille-1))
            {
                m_argent-=1000*pow(2,taille-1);
                m_petrole-=coutPetrole(m_port,pos_x,pos_y);
                m_bateaux.push_back(Bateau());
                m_bateaux.back().bonus_portee=false;
                m_bateaux.back().bonus_puissance=false;
                m_bateaux.back().taille=taille;
                m_bateaux.back().pos.x=pos_x;
                m_bateaux.back().pos.y=pos_y;
                m_bateaux.back().direction=direction;
                m_bateaux.back().vie=taille;
                m_nombre_bateaux++;
                for(i=0;i<taille;i++)
                {
                    if(direction==HAUT)
                    {
                        map[pos_x-i][pos_y].type=BATEAU;
                        map[pos_x-i][pos_y].joueur=m_numero_joueur;
                    }
                    else if(direction==BAS)
                    {
                        map[pos_x+i][pos_y].type=BATEAU;
                        map[pos_x+i][pos_y].joueur=m_numero_joueur;
                    }
                    else if(direction==GAUCHE)
                    {
                        map[pos_x][pos_y-i].type=BATEAU;
                        map[pos_x][pos_y-i].joueur=m_numero_joueur;
                    }
                    else if(direction==DROITE)
                    {
                        map[pos_x][pos_y+i].type=BATEAU;
                        map[pos_x][pos_y+i].joueur=m_numero_joueur;
                    }
                }
            }
            else
            {
                cout << "Ce bateau coute " << pow(2,taille-1) << "$ et vous ne disposez que de " << m_argent << "$." << endl;
            }
        }
    }
}
void Joueur::acheterPlateforme(Case map[][LARGEUR], int pos_x, int pos_y)
{
    bool e=false;
    if(map[pos_x][pos_y].type!=CASE_LIBRE)
    {
        cout << "La case aux coordonnées " << pos_x << "|" << pos_y << " n'est pas libre." << endl;
        e=true;
    }
    if(m_petrole<coutPetrole(m_port,pos_x,pos_y))
    {
        cout << "Vous n'avez pas assez de petrole pour placer un bateau ici." << endl;
        e=true;
    }
    if(m_argent<5000)
    {
        cout << "Une plateforme petroliere coute 5000$ et vous ne disposez que de " << m_argent << "$." << endl;
        e=true;
    }
    if(e==false)
    {
        m_argent-=5000;
        m_petrole-=coutPetrole(m_port,pos_x,pos_y);
        map[pos_x][pos_y].type=PLATEFORME;
        map[pos_x][pos_y].joueur=m_numero_joueur;
        m_plateformes.push_back(Plateforme());
        m_plateformes.back().pos.x=pos_x;
        m_plateformes.back().pos.y=pos_y;
        m_nombre_plateformes++;
    }
}
void Joueur::taperPort(Case map[][LARGEUR], int degats)
{
    map[m_port.pos.x][m_port.pos.y].type=CASE_DETRUITE;
    map[m_port.pos.x][m_port.pos.y].joueur=PERSONNE;
    m_port.vie-=degats;
}
void Joueur::taperPlateforme(Case map[][LARGEUR], int x)
{
    m_plateformes[x].~Plateforme();
    map[m_plateformes[x].pos.x][m_plateformes[x].pos.y].type=CASE_DETRUITE;
    map[m_plateformes[x].pos.x][m_plateformes[x].pos.y].joueur=PERSONNE;
    m_nombre_plateformes--;
}
void Joueur::taperBateau(Case map[][LARGEUR],int degats, int x)
{
    int i;
    m_bateaux[x].vie-=1;
    if(m_bateaux[x].vie<=0)
    {
        for(i=0;i<m_bateaux[x].taille;i++)
        {
            if(m_bateaux[x].direction==HAUT)
            {
                map[m_bateaux[x].pos.x-i][m_bateaux[x].pos.y].type=CASE_DETRUITE;
                map[m_bateaux[x].pos.x-i][m_bateaux[x].pos.y].joueur=PERSONNE;
            }
            else if(m_bateaux[x].direction==BAS)
            {
                map[m_bateaux[x].pos.x+i][m_bateaux[x].pos.y].type=CASE_DETRUITE;
                map[m_bateaux[x].pos.x+i][m_bateaux[x].pos.y].joueur=PERSONNE;
            }
            else if(m_bateaux[x].direction==GAUCHE)
            {
                map[m_bateaux[x].pos.x][m_bateaux[x].pos.y-i].type=CASE_DETRUITE;
                map[m_bateaux[x].pos.x][m_bateaux[x].pos.y-i].joueur=PERSONNE;
            }
            else if(m_bateaux[x].direction==DROITE)
            {
                map[m_bateaux[x].pos.x][m_bateaux[x].pos.y+i].type=CASE_DETRUITE;
                map[m_bateaux[x].pos.x][m_bateaux[x].pos.y+i].joueur=PERSONNE;
            }
        }
        m_bateaux[x].~Bateau();
        m_nombre_bateaux--;
    }
}
